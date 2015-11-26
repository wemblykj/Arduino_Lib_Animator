#include "Controller.h"

namespace Animator {

  Controller::Controller(IAnimation* animation, PlaybackFlags pf)
    : mTime(0)
    , mAnimation(animation)
    , mFlags(pf)
  {
    assert(mAnimation);
    
    // Build a data structure of streams and their monitored nodes
    const auto count = mAnimation->getStreamCount();
    const auto& streams = mAnimation->getStreams();
    for (int i = 0; i < count; ++i) {
      streams[i]->
    }
  }
  
  IAnimation& Controller::animation()
  {}
  
  time_t Controller::length()
  {}
  
  ApplicatorList Controller::streamApplicators(const char* streamName)
  {}
  
  void Controller::addStreamApplicator(const char* streamName, IApplicator* applicator)
  {}
  
  void Controller::addStreamApplicators(const char* streamName, ApplicatorList)
  {}
  
  const char* Controller::removeStreamApplicator(IApplicator* applicator)
  {}
  
  ApplicatorList Controller::removeStreamApplicators(const char* streamName)
  {}
  
  void Controller::update(time_t deltaTime)
  {
    mTime += deltaTime;
    
    
    
  }
  
  void Controller::reset()
  {}

} // namespace Animator