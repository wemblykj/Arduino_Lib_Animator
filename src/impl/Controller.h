/* IController interface
 * Paul Wightmore 2015
 */
#ifndef _CONTROLLER_h
#define _CONTROLLER_h

#include "../animator/IController.h"
#include "../animator/IStream.h"

#include "../animator/Common.h"

namespace Animator {

class Controller : virtual public IController{
public:
  Controller(IAnimation* animation, PlaybackFlags pf = Forward);
    
  ~Controller()
  {}
  
  // implement IController
  IAnimation& animation() override;
  PlaybackFlags playbackFlags() const override
  { return mFlags; }
  time_t length();
  time_t playbackPosition()
  { return mTime; }
  void addStreamApplicator(const char* streamName, const IApplicator* applicator) override;
  void setStreamApplicators(const char* streamName, const ApplicatorList&) override;
  const char* removeStreamApplicator(const IApplicator* applicator) override;
  ApplicatorList removeStreamApplicators(const char* streamName) override;
  void update(time_t deltaTime) override;
  void reset() override;
  
protected:
  struct StreamContext {
    StreamContext(const char* _name) 
      : name(_name)
      , currentNode(nullptr)
    {}
    const char* name;
    ForwardLinkedList<const INode*>::node_t* currentNode;
    ForwardLinkedList<const IApplicator*> applicators;
  };
  
  struct StreamContext* getStreamContext(const char* streamName);
  
private:
  ForwardLinkedList<struct StreamContext*> mStreamContextList;
  time_t mTime;
  IAnimation* mAnimation;
  PlaybackFlags mFlags;
};

} // namespace Animator

#endif // _CONTROLLER_h