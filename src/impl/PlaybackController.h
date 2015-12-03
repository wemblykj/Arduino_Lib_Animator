/* IController interface
 * Paul Wightmore 2015
 */
#ifndef _ANIMATOR_PLAYBACKCONTROLLER_h
#define _ANIMATOR_PLAYBACKCONTROLLER_h

#include "../animator/IPlaybackController.h"
#include "../animator/IStream.h"

#include "../animator/Common.h"

namespace Animator {

class PlaybackController : public Controller, virtual public IPlaybackController {
public:
  
  PlaybackController(IAnimation* animation, PlaybackFlags pf = Forward)
  : Controller(animation, pf)
  , mState(Stopped)
  {}
  
  void play() override { 
    mState = Playing; 
  }
  
  void play(PlaybackFlags pf) override {
    setPlaybackFlags(pf);
    play();
  }
  
  void pause() override {
    if (mState == Playing) mState = Paused;
  }
  
  void stop() override { 
    reset(); 
  }
    
  void seek(time_t time) override {
    setPlaybackPosition(time); 
  }
  
  void update(time_t deltaTime) {
    if (mState == Playing)
      Controller::update(deltaTime);
  }
  
  void reset() {
    mState = Stopped;
    Controller::reset();
  }
private:
  enum State {
    Playing,
    Paused,
    Stopped
  };
  
  State mState;
};

} // namespace Animator

#endif // _ANIMATOR_PLAYBACKCONTROLLER_h