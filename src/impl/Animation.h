/* Default IAnimation implementation
 * Paul Wightmore 2015
 */
#ifndef _ANIMATOR_ANIMATION_h
#define _ANIMATOR_ANIMATION_h

#include "../animator/IAnimation.h"

#include "../animator/Common.h"

namespace Animator {

class IStream;

class Animation : virtual public IAnimation {
public:
  Animation(const StreamList& streams);

  // Implement IAnimation interface
  const StreamList getStreams() override;
  void addStream(const IStream* applicator) override;
  void setStreams(const StreamList&) override;
  void removeStream(const IStream* stream) override;
  
private:
  IAnimation::StreamList mStreams;
};

} // namespace Animator

#endif // _ANIMATOR_ANIMATION_h