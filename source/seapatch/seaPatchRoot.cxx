#include "seaPatchRoot.h"

// Type Handle.
TypeHandle SeaPatchRoot::_type_handle;

// Setup our notify category.
NotifyCategoryDef(SeaPatchRoot, "");

SeaPatchRoot::SeaPatchRoot() {
	SeaPatchRoot_cat.warning() << "__init__()" << std::endl;
}

void SeaPatchRoot::allocate_wave(int waveId) {}