/* IController interface
 * Paul Wightmore 2015
 */
#ifndef _ICONTROLLER_h
#define _ICONTROLLER_h

#include <memory.h>

namespace Animator {

class IAnimation;
class IPlaybackControls;

class IController
{
public:
  //! Get the animation associated with this controller
  virtual shared_ptr<IAnimation> animation() = 0;
  //! Get the playback controls for the controller
  virtual shared_ptr<IPlaybackControls> playbackControls() = 0;
  //! Specify an applicator for a named animation stream
  virtual setStreamApplicator(string streamName, shared_ptr<IApplicator> applicator) = 0;
  //! Reset the controller to its initial state
  virtual void reset() = 0;
};

} // namespace Animator

#endif // _ICONTROLLER_h