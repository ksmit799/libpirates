#include "config_module.h"

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

  //SeaPatchNode::init_type();

  return;
}

