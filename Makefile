CXX = g++

CAPNPROTOS = $(wildcard source/*.capnp)
CAPNPROTOS_COMPILED = $(patsubst %, %.cc, $(CAPNPROTOS))

source/%.capnp.cc: source/%.capnp
	@echo capnp compile -oc++ $<
	@echo mv $<.c++ $@

SRC_SHARED = $(wildcard source/*.cc)

SRC_CLIENT = $(SRC_SHARED) $(wildcard source/client/*.cc)
SRC_SERVER = $(SRC_SHARED) $(wildcard source/server/*.cc)

OBJ_SERVER = $(patsubst source/%.cc,.objs/%.o, $(SRC_SERVER))
OBJ_CLIENT = $(patsubst source/%.cc,.objs/%.o, $(SRC_CLIENT))

EXECNAME_CLIENT = lajerlas_client
EXECNAME_SERVER = lajerlas_server
LDFLAGS_CLIENT = -lncurses -lenet
LDFLAGS_SERVER = -lenet
CXXFLAGS = -Wall -Wextra -g -std=c++0x -fpermissive

default: objdir $(CAPNPROTOS_COMPILED) $(EXECNAME_CLIENT) $(EXECNAME_SERVER)
	@true

$(EXECNAME_CLIENT): $(OBJ_CLIENT)
	$(CXX) -o $@ $^ $(LDFLAGS_CLIENT)

$(EXECNAME_SERVER): $(OBJ_SERVER)
	$(CXX) -o $@ $^ $(LDFLAGS_SERVER)

.objs/%.o: source/%.cc
	$(CXX) $< -c -o $@ $(CXXFLAGS)

objdir:
	@mkdir -p .objs .objs/client .objs/server

.PHONY: clean
clean:
	-rm -f $(OBJ_CLIENT) $(EXECNAME_CLIENT)
	-rm -f $(OBJ_SERVER) $(EXECNAME_SERVER)

