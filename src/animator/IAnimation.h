/* IAnimation interface
 * Paul Wightmore 2015
 */
#ifndef _IANIMATION_h
#define _IANIMATION_h

#include "INode.h"

#include "Common.h"

using namespace std;

namespace Animator {

class IStream;

class IAnimation
{
public:
  typedef IStream* (*StreamList)[];
  
public:
  virtual const StreamList& getStreams() = 0;
  virtual uint8_t getStreamCount() = 0;
};

} // namespace Animator

#endif // _IANIMATION_h