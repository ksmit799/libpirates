INLINE bool SeaPatchRoot::is_enabled() const {
  return _enabled;
}

INLINE void SeaPatchRoot::enable(){
  _enabled=true;
}

INLINE void SeaPatchRoot::disable(){
  _enabled=false;
}