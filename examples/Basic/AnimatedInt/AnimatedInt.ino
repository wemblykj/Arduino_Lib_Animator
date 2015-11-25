#include <Animator.h>
#include <IAnimation.h>
#include <IPlaybackController.h>
#include <IStream.h>
#include <Common.h>

using namespace std;
using namespace Animator;

IStream* intStream;
IAnimation* animation;

struct _CONTROLLER {
  _CONTROLLER() 
  : reset(true)
  , interval(200)
  , controller(nullptr)
  , lastTime(0) 
  {}
  
  bool reset;
  time_t interval;
  IController* controller;
  time_t lastTime;
} controllers[2];

static const int numControllers = sizeof(controllers)/sizeof(struct _CONTROLLER);

void updateController(struct _CONTROLLER c)
{
  const time_t time = millis();
  if (!c.reset)
  {
    const time_t delta_time = time - c.lastTime;
  
    if (delta_time >= c.interval)
    {
      c.controller->update(delta_time);
      c.lastTime = time;
    }
  }
  else
  {
    c.controller->update(0);
    c.lastTime = time;
  }
}

void setup() {
  intStream = createStream("int");
  IStream* streams[] = {intStream};
  
  // Create an animations
  animation = createAnimation(streams);
  
  auto c1 = createPlaybackController(animation);
  auto c2 = createPlaybackController(animation);
  
  // Create multiple controllers that share the same animation
  controllers[0].controller = c1;
  controllers[0].interval = 250;
  
  // Seek halfway trhough the animation for 2nd controller and update at half the speed
  controllers[1].controller = c2;
  controllers[1].interval = 500;
  
  c1->play();
  c2->seek(c2->length()/2);
  c2->play();
}

void loop() {
  // update all controllers
  for (int i = 0; i < numControllers; ++i)
    updateController(controllers[i]);
}
