INLINE void NametagGlobals::set_camera(NodePath& node){
	_camera = node;
}

INLINE void NametagGlobals::set_arrow_model(NodePath& node){
	_arrow_model = node;
}

INLINE void NametagGlobals::set_nametag_card(NodePath& node, LColorf frame){
	_nametag_card_model = node;
	_nametag_card_frame = frame;
}

INLINE void NametagGlobals::set_mouse_watcher(MouseWatcher& watcher){
	_mouse_watcher = watcher;
}

INLINE void NametagGlobals::set_page_button(int state, NodePath& model){
	// Set page button	
	return;
}

INLINE void NametagGlobals::set_page_button(NodePath& model, NodePath& model1, NodePath& model2, NodePath& model3){
	// Set page button	
	return;
}

INLINE void NametagGlobals::set_quit_button(int state, NodePath& model){
	// Set quit button
	return;
}

INLINE void NametagGlobals::set_quit_button(NodePath& model, NodePath& model1, NodePath& model2, NodePath& model3){
	// Set quit button
	return;
}

INLINE void NametagGlobals::set_rollover_sound(PT(AudioSound) sound){
	// Set rollover sound
	return;
}

INLINE void NametagGlobals::set_click_sound(PT(AudioSound) sound){
	// Set click sound
	return;
}

INLINE void NametagGlobals::set_toon(NodePath& toon){
	// Set toon
	return;
}

INLINE void NametagGlobals::set_master_nametags_active(bool isActive){
	// Set master nametags active
	return;
}

INLINE void NametagGlobals::set_master_arrows_on(bool isOn){
	// Set master arrows on
	return;
}

INLINE void NametagGlobals::set_onscreen_chat_forced(bool forced){
	// Set onscreen chat forced
	return;
}

INLINE void NametagGlobals::set_balloon_modulation_color(LColorf color){
	// Set balloon modulation color
	return;
}