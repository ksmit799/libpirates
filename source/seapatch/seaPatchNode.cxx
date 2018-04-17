#include "seaPatchNode.h"

TypeHandle SeaPatchNode::_type_handle;

// Setup our notify category.
NotifyCategoryDef(SeaPatchNode, "");

SeaPatchNode::SeaPatchNode(const string &name) : PandaNode(name) {
	SeaPatchNode_cat.warning() << "__init__(string name)" << std::endl;
}