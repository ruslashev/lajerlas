CXX = g++
SRC_SHARED = $(wildcard source/*.cc)
SRC_CLIENT = $(wildcard source/client/*.cc) $(SRC_SHARED)
OBJ_CLIENT = $(patsubst source/%.cc, .objs/%.o, $(SRC_CLIENT))
SRC_SERVER = $(wildcard source/server/*.cc) $(SRC_SHARED)
OBJ_SERVER = $(patsubst source/%.cc, .objs/%.o, $(SRC_SERVER))
DEP = $(OBJ_CLIENT:.o=.d) $(OBJ_SERVER:.o=.d)
EXECNAME_CLIENT = lajerlas_client
EXECNAME_SERVER = lajerlas_server
LDFLAGS_CLIENT = -lncurses -lenet
LDFLAGS_SERVER = -lenet
CXXFLAGS = -Wall -Wextra -g -std=c++0x -fpermissive

default: objdir $(EXECNAME_CLIENT) $(EXECNAME_SERVER)
	@true

$(EXECNAME_CLIENT): $(OBJ_CLIENT)
	$(CXX) -o $@ $^ $(LDFLAGS_CLIENT)

$(EXECNAME_SERVER): $(OBJ_SERVER)
	$(CXX) -o $@ $^ $(LDFLAGS_SERVER)

.objs/%.o: source/%.cc
	$(CXX) -c -o $@ $< $(CXXFLAGS)

objdir:
	mkdir -p .objs .objs/client .objs/server

-include $(DEP)
.objs/%.d: source/%.cc
	$(CPP) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) > $@

.PHONY: clean
clean:
	-rm -f $(OBJ_CLIENT) $(EXECNAME_CLIENT)
	-rm -f $(OBJ_SERVER) $(EXECNAME_SERVER)
	-rm -f $(DEP)

