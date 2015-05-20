SRC_SHARED = $(wildcard source/*.cpp)
SRC_CLIENT = $(wildcard source/client/*.cpp) $(SRC_SHARED)
OBJ_CLIENT = $(patsubst source/%.cpp, .objs/%.o, $(SRC_CLIENT))
SRC_SERVER = $(wildcard source/server/*.cpp) $(SRC_SHARED)
OBJ_SERVER = $(patsubst source/%.cpp, .objs/%.o, $(SRC_SERVER))
DEP = $(OBJ_CLIENT:.o=.d) $(OBJ_SERVER:.o=.d)
EXECNAME_CLIENT = lajerlas_client
EXECNAME_SERVER = lajerlas_server
LDFLAGS_CLIENT = -lncurses -lenet
LDFLAGS_SERVER = -lenet
CXXFLAGS = -Wall -Wextra -g -std=c++0x

default: objdir $(EXECNAME_CLIENT) $(EXECNAME_SERVER)
	./$(EXECNAME_SERVER) &
	./$(EXECNAME_CLIENT)

$(EXECNAME_CLIENT): $(OBJ_CLIENT)
	$(CXX) -o $@ $^ $(LDFLAGS_CLIENT)

$(EXECNAME_SERVER): $(OBJ_SERVER)
	$(CXX) -o $@ $^ $(LDFLAGS_SERVER)

.objs/%.o: source/%.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

objdir:
	mkdir -p .objs .objs/client .objs/server

-include $(DEP)
.objs/%.d: source/%.cpp
	$(CPP) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) > $@

.PHONY: clean
clean:
	-rm -f $(OBJ_CLIENT) $(EXECNAME_CLIENT)
	-rm -f $(OBJ_SERVER) $(EXECNAME_SERVER)
	-rm -f $(DEP)

