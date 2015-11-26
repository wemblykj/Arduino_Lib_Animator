/* IPlaybackControls interface
 * Paul Wightmore 2015
 */
#ifndef _IPLAYBACKCONTROLLER_h
#define _IPLAYBACKCONTROLLER_h

#include "IController.h"

#include "Common.h"

namespace Animator {

class IPlaybackController : virtual public IController
{
public:
  virtual void play(PlaybackFlags pf = Forward) = 0;
  virtual void pause() = 0;
  virtual void stop() = 0;
  virtual void seek(time_t time) = 0;
  virtual void setPlaybackFlags(PlaybackFlags pf = Forward) = 0;
};

} // namespace Animator

#endif // _IPLAYBACKCONTROLLER_h