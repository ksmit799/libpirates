INLINE void SeaPatchRoot::enable(){
  _enabled = true;
}

INLINE void SeaPatchRoot::disable(){
  _enabled = false;
}

INLINE bool SeaPatchRoot::is_enabled() const {
  return _enabled;
}

INLINE void SeaPatchRoot::set_center(NodePath center) {
	// Cast the geometry of the NodePath into a GeometricBoundingVolume.
	PT(GeometricBoundingVolume) gbv = center.get_bounds()->as_geometric_bounding_volume();

	// Make sure we have geometry to work with.
	nassertv(gbv != NULL);
	nassertv(!gbv->is_infinite() && !gbv->is_empty());

	// Calculate and set our center.
	_center = gbv->get_approx_center();
}

INLINE LPoint3f SeaPatchRoot::get_center() const {
  return _center;
}

INLINE void SeaPatchRoot::set_anchor(NodePath anchor) {
	_anchor = anchor;
}

INLINE NodePath SeaPatchRoot::get_anchor() const {
	return _anchor;
}

INLINE void SeaPatchRoot::set_sea_level(float level) {
	_seaLevel = level;
}

INLINE float SeaPatchRoot::get_sea_level() const {
	return _seaLevel;
}

INLINE void SeaPatchRoot::set_high_color(LColorf color) {
	_colorHigh = color;
}

INLINE LColorf SeaPatchRoot::get_high_color() const {
	return _colorHigh;
}

INLINE void SeaPatchRoot::set_low_color(LColorf color) {
	_colorLow = color;
}

INLINE LColorf SeaPatchRoot::get_low_color() const {
	return _colorLow;
}

INLINE void SeaPatchRoot::set_overall_speed(float speed) {
	_overallSpeed = speed;
}

INLINE float SeaPatchRoot::get_overall_speed() const {
	return _overallSpeed;
}

INLINE void SeaPatchRoot::set_uv_speed(LVecBase2f speed) {
	_uvSpeed = speed;
}

INLINE LVecBase2f SeaPatchRoot::get_uv_speed() const {
	return _uvSpeed;
}

INLINE void SeaPatchRoot::set_uv_scale(LVecBase2f scale) {
	_uvScale = scale;
}

INLINE LVecBase2f SeaPatchRoot::get_uv_scale() const {
	return _uvScale;
}

INLINE void SeaPatchRoot::set_threshold(float threshold) {
	_threshold = threshold;
}

INLINE float SeaPatchRoot::get_threshold() const {
	return _threshold;
}

INLINE void SeaPatchRoot::set_radius(float radius) {
	_radius = radius;
}

INLINE float SeaPatchRoot::get_radius() const {
	return _radius;
}

INLINE void SeaPatchRoot::enable_wave(int waveId) {
	return;
}