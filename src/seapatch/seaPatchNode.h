#ifndef SEAPATCHNODE_H
#define SEAPATCHNODE_H

#include "config_libpirates.h"

#include <pandabase.h>
#include <pandaNode.h>

class EXPCL_LIBPIRATES SeaPatchNode {

PUBLISHED:
	SeaPatchNode();

private:
	bool _enabled;
};

#endif