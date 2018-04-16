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
};

#include "seaPatchNode.I"

#endif