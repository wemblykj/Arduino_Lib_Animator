/* IPlaybackControls interface
 * Paul Wightmore 2015
 */
#ifndef _ANIMATOR_IPLAYBACKCONTROLLER_h
#define _ANIMATOR_IPLAYBACKCONTROLLER_h

#include "IController.h"

#include "Common.h"

namespace Animator {

class IPlaybackController : virtual public IController
{
public:
  virtual void play() = 0;
  virtual void play(PlaybackFlags pf) = 0;
  virtual void pause() = 0;
  virtual void stop() = 0;
  virtual void seek(time_t time) = 0;
};

} // namespace Animator

#endif // _ANIMATOR_IPLAYBACKCONTROLLER_h