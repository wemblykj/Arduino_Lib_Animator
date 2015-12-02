/* IAnimation interface
 * Paul Wightmore 2015
 */
#ifndef _ANIMATOR_IANIMATION_h
#define _ANIMATOR_IANIMATION_h

#include "animator/INode.h"
#include "animator/Common.h"
#include "animator/LinkedList.h"

using namespace std;

namespace Animator {

class IStream;

class IAnimation
{
public:
  typedef ForwardLinkedList<const IStream*> StreamList;
  
public:
  //! Get a list of streams for the animation
  virtual const StreamList getStreams() = 0;
  
  //! Add a stream to the animation
  virtual void addStream(const IStream* stream) = 0;
  
  //! Add a list of streams to the animation
  /**
    * this will destroy all existing streams
    */
  virtual void setStreams(const StreamList&) = 0;
  
  //! Remove \p stream from the animation
  virtual void removeStream(const IStream* stream) = 0;
};

} // namespace Animator

#endif // _ANIMATOR_IANIMATION_h