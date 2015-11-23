/* IPlaybackControls interface
 * Paul Wightmore 2015
 */
#ifndef _IPLAYBACKCONTROLLER_h
#define _IPLAYBACKCONTROLLER_h

#include "Common.h"

namespace Animator {

class IPlaybackController
{
public:
  virtual void play() = 0;
  virtual void pause() = 0;
  virtual void stop() = 0;
  virtual void seek(time_t time) = 0;
};

} // namespace Animator

#endif // _IPLAYBACKCONTROLLER_h