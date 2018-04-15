INLINE bool SeaPatchNode::is_enabled() const {
  return _enabled;
}

INLINE void SeaPatchNode::enable(){
  _enabled=true;
}

INLINE void SeaPatchNode::disable(){
  _enabled=false;
}