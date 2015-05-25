@0x82accfe8fc35fa20;

struct World {
	name @0 :Text;

	width @1 :UInt64;
	height @2 :UInt64;

	tiles @3 :List(List(UInt16));
}

