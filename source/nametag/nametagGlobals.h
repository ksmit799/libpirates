#ifndef NAMETAGGLOBALS_H
#define NAMETAGGLOBALS_H

#include "pandabase.h"
#include "ReferenceCount.h"
#include "nodepath.h"
#include "luse.h"
#include "mouseWatcher.h"

class NametagGlobals : public virtual ReferenceCount {

PUBLISHED:

	enum {
		CCNormal = 0,
		CCNoChat = 1,
		CCNonPlayer = 2,
		CCSuit = 3,
		CCToonBuilding = 4,
		CCSuitBuilding = 5,
		CCHouseBuilding = 6,
		CCSpeedChat = 7,
		CCFreeChat = 8
	};

	enum {
		WTNormal = 0,
		WTQuickTalker = 1,
		WTSystem = 2,
		WTBattleSOS = 3,
		WTEmote = 4,
		WTToontownBoardingGroup = 5
	};

	enum {
		CFSpeech = 1,
		CFThought = 2,
		CFQuicktalker = 4,
		CFTimeout = 8,
		CFPageButton = 16,
		CFQuitButton = 32,
		CFReversed = 64,
		CFSndOpenchat = 128,
		CFNoQuitButton = 256
	};

	enum {
		CName = 1,
		CSpeech = 2,
		CThought = 4
	};

	NametagGlobals();

	INLINE void set_camera(NodePath& node);
	INLINE void set_arrow_model(NodePath& node);
	INLINE void set_nametag_card(NodePath& node, VBase4 frame);
	INLINE void set_mouse_watcher(MouseWatcher& watcher);
	// ChatBalloon* sb3d for args.
	INLINE void set_speech_balloon_3d();
	INLINE void set_thought_balloon_3d();
	INLINE void set_speech_balloon_2d();
	INLINE void set_thought_balloon_2d();

};

#endif