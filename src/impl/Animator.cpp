#include "../Animator.h"

#include "Controller.h"

#include "../animator/IStream.h"
#include "../animator/IAnimation.h"

namespace Animator {

IStream* createStream(const char* name, const IStream::NodeList&)
{
  return nullptr;
}

IStream* createStream(const char* name, const INode* (*nodes), size_t count)
{
  IStream::NodeList nl;
  for (int i = 0; i < count; ++i)
    nl.push_back(nodes[i]);
    
  return createStream(name, nl);
}

IAnimation* createAnimation(const IAnimation::StreamList&)
{
  return nullptr;
}

IAnimation* createAnimation(const IStream* (*streams), size_t count)
{
  IAnimation::StreamList sl;
  for (int i = 0; i < count; ++i)
    sl.push_back(streams[i]);
    
  return createAnimation(sl);
}

IPlaybackController* createPlaybackController(IAnimation* animation, PlaybackFlags pf)
{
  return new Controller(animation, pf);
}

} // namespace Animator
