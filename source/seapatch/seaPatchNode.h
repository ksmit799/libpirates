#ifndef SEAPATCHNODE_H
#define SEAPATCHNODE_H

#include "pandabase.h"
#include "pandaNode.h"

static const int noise_table_size = 64;

class SeaPatchNode : public PandaNode {

PUBLISHED:

	enum Alpha_Type {
		AHIGH,
		ALOW,
		ATOTAL,
		ANONE,
	};

	SeaPatchNode(const string &name);

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
		PandaNode::init_type();
		register_type(_type_handle, "SeaPatchNode",
			PandaNode::get_class_type());
	}
	virtual TypeHandle get_type() const {
		return get_class_type();
	}
	virtual TypeHandle force_init_type() { init_type(); return get_class_type(); }

private:
	static TypeHandle _type_handle;
};

#include "seaPatchNode.I"

#endif