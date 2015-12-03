#include "../Animator.h"

#include "Animation.h"

namespace Animator {
  
Animation::Animation(const StreamList& streams) 
  : mStreams(streams) 
{}

const IAnimation::StreamList Animation::getStreams() {
  return mStreams;
}

void Animation::addStream(const IStream* stream) {
  mStreams.push_back(stream);
}

void Animation::setStreams(const StreamList& streams) {
  mStreams = streams;
}

void Animation::removeStream(const IStream* stream) {
  mStreams.remove(stream);
}

} // namespace Animator
