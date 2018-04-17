#ifndef SEAPATCHROOT_H
#define SEAPATCHROOT_H

#include "pandabase.h"

#include "notifyCategoryProxy.h"
#include "typedObject.h"
#include "nodePath.h"
#include "luse.h"
#include "geometricBoundingVolume.h"

// Declare our notify category.
NotifyCategoryDecl(SeaPatchRoot, EXPORT_CLASS, EXPORT_TEMPL);

class SeaPatchRoot : public TypedObject {

PUBLISHED:

	SeaPatchRoot();

	INLINE void enable();
	INLINE void disable();
	INLINE bool is_enabled() const;

	INLINE void set_center(NodePath center);
	INLINE LPoint3f get_center() const;

	INLINE void set_anchor(NodePath anchor);
	INLINE NodePath get_anchor() const;

	INLINE void set_sea_level(float level);
	INLINE float get_sea_level() const;

	// LColorf -> typedef for LVecBase4f.
	INLINE void set_high_color(LColorf color);
	INLINE LColorf get_high_color() const;

	INLINE void set_low_color(LColorf color);
	INLINE LColorf get_low_color() const;

	INLINE void set_overall_speed(float speed);
	INLINE float get_overall_speed() const;

	INLINE void set_uv_speed(LVecBase2f speed);
	INLINE LVecBase2f get_uv_speed() const;

	INLINE void set_uv_scale(LVecBase2f scale);
	INLINE LVecBase2f get_uv_scale() const;

	INLINE void set_threshold(float threshold);
	INLINE float get_threshold() const;

	INLINE void set_radius(float radius);
	INLINE float get_radius() const;

	INLINE void enable_wave(int waveId);

private:
	bool _enabled;
	LPoint3f _center;
	NodePath _anchor;
	float _seaLevel;
	LColorf _colorHigh;
	LColorf _colorLow;
	float _overallSpeed;
	LVecBase2f _uvSpeed;
	LVecBase2f _uvScale;
	float _threshold;
	float _radius;

public:
	void allocate_wave(int waveId);

public:
	static TypeHandle get_class_type() {
		return _type_handle;
	}
	static void init_type() {
		TypedObject::init_type();
		register_type(_type_handle, "SeaPatchRoot",
			TypedObject::get_class_type());
	}
	virtual TypeHandle get_type() const {
		return get_class_type();
	}
	virtual TypeHandle force_init_type() { init_type(); return get_class_type(); }

private:
	static TypeHandle _type_handle;
};

#include "seaPatchRoot.I"

#endif