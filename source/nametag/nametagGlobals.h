#ifndef NAMETAGGLOBALS_H
#define NAMETAGGLOBALS_H

#include "pandabase.h"
#include "ReferenceCount.h"
#include "nodepath.h"
#include "luse.h"
#include "mouseWatcher.h"
#include "audioSound.h"

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
	~NametagGlobals();

	INLINE void set_camera(NodePath& node);
	INLINE void set_arrow_model(NodePath& node);
	INLINE void set_nametag_card(NodePath& node, LColorf frame);
	INLINE void set_mouse_watcher(MouseWatcher& watcher);
	// ChatBalloon* sb3d for args.
	INLINE void set_speech_balloon_3d();
	INLINE void set_thought_balloon_3d();
	INLINE void set_speech_balloon_2d();
	INLINE void set_thought_balloon_2d();
	INLINE void set_page_button(int state, NodePath& model);
	INLINE void set_page_button(NodePath& model, NodePath& model1, NodePath& model2, NodePath& model3);
	INLINE void set_quit_button(int state, NodePath& model);
	INLINE void set_quit_button(NodePath& model, NodePath& model1, NodePath& model2, NodePath& model3);
	INLINE void set_rollover_sound(PT(AudioSound) sound);
	INLINE void set_click_sound(PT(AudioSound) sound);
	INLINE void set_toon(NodePath& toon);
	INLINE void set_master_nametags_active(bool isActive);
	INLINE void set_master_arrows_on(bool isOn);
	INLINE void set_onscreen_chat_forced(bool forced);
	INLINE void set_balloon_modulation_color(LColorf color);

private:
	// set_camera
	NodePath _camera;

	// set_arrow_model
	NodePath _arrow_model;

	// set_nametag_card
	NodePath _nametag_card_model;
	LColorf _nametag_card_frame;

	// set_mouse_watcher
	MouseWatcher _mouse_watcher;


public:
	static TypeHandle get_class_type() {
		return _type_handle;
	}
	static void init_type() {
		ReferenceCount::init_type();
		register_type(_type_handle, "NametagGlobals",
			ReferenceCount::get_class_type());
	}
	virtual TypeHandle get_type() const {
		return get_class_type();
	}
	virtual TypeHandle force_init_type() { init_type(); return get_class_type(); }

private:
	static TypeHandle _type_handle;
};

#include "nametagGlobals.I"

#endif