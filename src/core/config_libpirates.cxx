#include "config_libpirates.h"

#include "seaPatchNode.h"

#include <pandabase.h>
#include <dconfig.h>

// Configure the project.
Configure(config_libpirates);

// Create a new notify category for libpirates.
NotifyCategoryDef(libpirates, "");

// Init the lib.
ConfigureFn(config_libpirates) {
	init_libpirates();
};

void init_libpirates() {
	// Keep track of whether we are already initialized or not.
	static bool isInitialized = false;

	// If we have already initialized, return.
	if (isInitialized) {
		return;
	};

	isInitialized = true;

	// Setup our types.
	//SeaPatchNode::init_type();
};