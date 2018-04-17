#ifndef SEAPATCHROOT_H
#define SEAPATCHROOT_H

#include "pandabase.h"
#include "typedObject.h"

class SeaPatchRoot : public TypedObject {

PUBLISHED:

	SeaPatchRoot();

	INLINE void enable();
	INLINE void disable();
	INLINE bool is_enabled() const;

private:
	bool _enabled;

public:
	static TypeHandle get_class_type() {
		return _type_handle;
	}
	static void init_type() {
		TypedObject::init_type();
		register_type(_type_handle, "SeaPatchRoot",
			TypedObject::get_class_type());
	}
	virtual TypeHandle get_type() const {
		return get_class_type();
	}
	virtual TypeHandle force_init_type() { init_type(); return get_class_type(); }

private:
	static TypeHandle _type_handle;
};

#include "seaPatchRoot.I"

#endif