

namespace ngn {

// For use in the pool manager. Gives us a simple 32 bit identifier for any
// elmeent handled by the pool manager. The type defines what type of data
// it is (in what array it exists). The counter optionally helps define
// how many other entities may be referring to this object and can be used
// for memory management purposes.
union Handle {
	struct {
		unsigned int id;
	};
	struct {
		short int idx;
		char count;
		char type;
	};
};

} // namespace ngn