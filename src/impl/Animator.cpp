#include "..\Animator.h"

namespace Animator {

IStream* createStream(const char* name, const IStream::NodeList&)
{
  return nullptr;
}

IStream* createStream(const char* name, const INode* (*nodes), size_t count)
{
  return nullptr;
}

IAnimation* createAnimation(const IAnimation::StreamList&)
{
  return nullptr;
}

IAnimation* createAnimation(const IStream* (*streams), size_t count)
{
  return nullptr;
}

IPlaybackController* createPlaybackController(IAnimation* animation, PlaybackFlags pf)
{
  return nullptr;
}

} // namespace Animator
