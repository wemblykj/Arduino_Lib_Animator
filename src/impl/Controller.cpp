#include "Controller.h"

#include "../animator/Common.h"

namespace Animator {

  Controller::Controller(IAnimation* animation, PlaybackFlags pf)
    : mTime(0)
    , mAnimation(animation)
    , mFlags(pf)
  {
    assert(mAnimation);
  }
  
  IAnimation& Controller::animation()
  {}
  
  time_t Controller::length() const
  {}
  
  void Controller::addStreamApplicator(const char* streamName, const IApplicator* applicator)
  {
    auto context = getStreamContext(streamName);
    context->applicators.push_back(applicator);
  }
  
  void Controller::setStreamApplicators(const char* streamName, const ApplicatorList& applicators)
  {
    auto context = getStreamContext(streamName);
    context->applicators = applicators;
  }
  
  const char* Controller::removeStreamApplicator(const IApplicator* applicator)
  {
    auto n = mStreamContextList.head();
    while (n != nullptr)
    {
      if (n->payload->applicators.remove(applicator))
        return n->payload->name;
    }
    
    return nullptr;
  }
  
  IController::ApplicatorList Controller::removeStreamApplicators(const char* streamName)
  {
    auto context = getStreamContext(streamName);
    auto applicators = context->applicators;
    context->applicators = ApplicatorList();
    return applicators;
  }
  
  void Controller::update(time_t deltaTime)
  {
    mTime += deltaTime;
  }
  
  void Controller::reset()
  {
    mTime = 0;
  }

  struct Controller::StreamContext* Controller::getStreamContext(const char* streamName)
  {
    assert(streamName);
    
    auto n = mStreamContextList.head();
    while (n != nullptr)
    {
      if (0 == strcmp(streamName, n->payload->name))
        return n->payload;
    }
    
    auto sc = new StreamContext(streamName);
    mStreamContextList.push_back(sc);
    return sc;
  }
  
} // namespace Animator