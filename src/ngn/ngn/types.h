#pragma once

namespace ngn {

// For use in the pool manager. Gives us a simple 32 bit identifier for any
// elmeent handled by the pool manager. The type defines what type of data
// it is (in what array it exists). The counter optionally helps define
// how many other entities may be referring to this object and can be used
// for memory management purposes.
/*union Handle {
	struct {
		unsigned int id;
	};
	struct {
		short int idx;
		char count;
		char type;
	};
};*/


class Handle {
public:
	union {
		struct {
			unsigned int id;
		};
		struct {
			short int idx;
			char count;
			char type;
		};
	};

	Handle():id(0){}
	Handle(unsigned int id) {
		this->id = id;
	}
	Handle(short int idx, char count, char type) {
		this->idx = idx;
		this->count = count;
		this->type = type;
	}
	virtual ~Handle(){}

	bool operator==(const Handle &h) {
		return id == h.id;
	};

};


/* Types ------------------------------------------------ */
static char TYPE_NOTYPE = 0; // We need this reserved since handle ids will default to zero
static char TYPE_LOCATION = 1;

static Handle nullComponent; // Should be initialized to zero. 

typedef char EntityType;
typedef char ComponentType;

} // namespace ngn