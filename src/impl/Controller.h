/* IController interface
 * Paul Wightmore 2015
 */
#ifndef _CONTROLLER_h
#define _CONTROLLER_h

#include "../animator/IController.h"

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
  ApplicatorList streamApplicators(const char* streamName) override;
  void addStreamApplicator(const char* streamName, IApplicator* applicator) override;
  void addStreamApplicators(const char* streamName, ApplicatorList) override;
  const char* removeStreamApplicator(IApplicator* applicator) override;
  ApplicatorList removeStreamApplicators(const char* streamName) override;
  void update(time_t deltaTime) override;
  void reset() override;
  
private:
  struct _STREAM {
    _STREAM(const char* _name, const NodeList& _nodes, uint8_t _nodeCount) 
      : name(_name)
      , nodes(_nodes)
      , nodeCount(_nodeCount)
      , currentNode(0)
    {}
    const char* name;
    const NodeList& nodes;
    const uint8_t nodeCount;
    uint8_t currentNode;
  }
  time_t mTime;
  IAnimation* mAnimation;
  PlaybackFlags mFlags;
};

} // namespace Animator
