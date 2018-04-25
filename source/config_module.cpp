#include "config_module.h"

// Nametags.
#include "nametagGlobals.h"

// SeaPatch.
#include "seaPatchRoot.h"
#include "seaPatchNode.h"

#include "dconfig.h"

Configure(config_libpirates);
NotifyCategoryDef(libpirates, "");

ConfigureFn(config_libpirates) {
  init_libpirates();
}

void init_libpirates() {
  static bool initialized = false;

  if (initialized) {
    return;
  }

  initialized = true;

  // Init Nametag types.
  NametagGlobals::init_type();

  // Init SeaPatch types.
  SeaPatchRoot::init_type();
  SeaPatchNode::init_type();

  return;
}

