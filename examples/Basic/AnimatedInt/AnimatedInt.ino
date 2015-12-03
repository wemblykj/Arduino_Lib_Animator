#include <Animator.h>
#include <animator/IAnimation.h>
#include <animator/IPlaybackController.h>
#include <animator/IStream.h>
#include <animator/DerivativePolicies.h>
#include <animator/ApplicationPolicies.h>
#include <animator/Common.h>

using namespace std;
using namespace Animator;

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

uint8_t value1 = 0;
uint8_t value2 = 0;

IAnimation* createDefaultAnimation() {
  // Animate an uint8_t from 0 -> 255 over 1 second
  time_t times[] = {0, 500, 1000};
  uint8_t payloads[] = {0, 200, 255};
  IStream* intStream = createStream<uint8_t>("int", times, payloads, sizeof(times)/sizeof(time_t));
  const IStream* streams[] = {intStream};
  
  // Create an animations
  return createAnimation(streams, sizeof(streams)/sizeof(IStream*));
}

void updateController(struct _CONTROLLER c) {
  const time_t time = millis();
  if (!c.reset) {
    const time_t delta_time = time - c.lastTime;
  
    if (delta_time >= c.interval) {
      c.controller->update(delta_time);
      c.lastTime = time;
    }
  } else {
    c.controller->update(0);
    c.lastTime = time;
  }
}

void setup() {
  IAnimation* animation = createDefaultAnimation();
  auto c1 = createPlaybackController(animation);
  auto c2 = createPlaybackController(animation);
  
  // Create multiple controllers that share the same animation but use different applicators, the controllers can therefore be driven
  // independently, e.g. playback speed and position.
  controllers[0].controller = c1;
  controllers[0].interval = 100;  // uses keyframe applicator for 3 nodes so should only require updating every half-a-second.
  
  controllers[1].controller = c2;
  controllers[1].interval = 4;    // uses interpolation of 3 nodes over one second, 4ms should allow us to drive all 256 levels
  
  c1->addStreamApplicator("intStream", createCompatibleApplicator<uint8_t, KeyframePolicy, AssignmentPolicy>(value1));
  c2->addStreamApplicator("intStream", createCompatibleApplicator<uint8_t, KeyframePolicy, AssignmentPolicy>(value2));
  
  c1->play();
  c2->play();
}

void loop() {
  // update all controllers
  for (int i = 0; i < numControllers; ++i)
    updateController(controllers[i]);
}

