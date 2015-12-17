#include "Controller.h"

#include "animator/Common.h"
#include "animator/IAnimation.h"
#include "animator/IApplicator.h"

#include <Arduino.h>

namespace Animator {

  Controller::Controller(IAnimation* animation, PlaybackFlags pf)
    : mTime(0)
    , mAnimation(animation)
    , mFlags(pf)
  {
    assert(mAnimation);
  }
  
  IAnimation& Controller::animation()
  {
	  return *mAnimation;
  }
  
  time_t Controller::length() const
  {
    time_t length = 0;
    auto n = mAnimation->getStreams().head();
    while (n != nullptr)
      length = max(length, n->payload->length());
      
    return length;
  }
  
  void Controller::addStreamApplicator(const String& streamName, IApplicator* applicator)
  {
    auto context = getStreamContext(streamName);
    context->applicators.push_back(applicator);
  }
  
  void Controller::setStreamApplicators(const String& streamName, const ApplicatorList& applicators)
  {
    auto context = getStreamContext(streamName);
    context->applicators = applicators;
  }
  
  String Controller::removeStreamApplicator(IApplicator* applicator)
  {
    auto n = mStreamContextList.head();
    while (n != nullptr)
    {
      if (n->payload->applicators.remove(applicator))
        return n->payload->name;
    }
    
    return String();
  }
  
  IController::ApplicatorList Controller::removeStreamApplicators(const String& streamName)
  {
    auto context = getStreamContext(streamName);
    auto applicators = context->applicators;
    context->applicators = ApplicatorList();
    return applicators;
  }
  
  void Controller::update(time_t deltaTime)
  {
	mTime += deltaTime;
	
	auto n = mStreamContextList.head();
	while (n != nullptr)
	{
		auto context = n->payload;
		
		if (! context->currentNode) {
			auto stream = mAnimation->getStreams().head();
			while (stream != nullptr)
			{
				if (stream->payload->name() == context->name) {
					context->currentNode = stream->payload->getNodes().head();
					break;
				}
				stream =stream->next;
			}
		}
			
		if (context->currentNode && mTime >= context->currentNode->payload->time()) {
			if (context->currentNode->next && mTime >= context->currentNode->next->payload->time())
				context->currentNode = context->currentNode->next;
				
			// Update applicators
			auto a = context->applicators.head();
			while (a != nullptr)
			{
				a->payload->apply(mTime, *(context->currentNode));
				a = a->next;
			}
		}
		
		n = n->next;
	}
  }
  
  void Controller::reset()
  {
    mTime = 0;
	
	auto n = mStreamContextList.head();
	while (n != nullptr)
	{
		auto context = n->payload;
		context->currentNode = nullptr;
	}
  }

  struct Controller::StreamContext* Controller::getStreamContext(const String& streamName)
  {
    assert(streamName);
    
    auto n = mStreamContextList.head();
    while (n != nullptr)
    {
      if (n->payload->name == streamName)
        return n->payload;
    }
    
    auto sc = new StreamContext(streamName);
    mStreamContextList.push_back(sc);
    return sc;
  }
  
} // namespace Animator