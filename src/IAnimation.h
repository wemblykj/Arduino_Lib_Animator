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
  virtual StreamList getStreams();
};

} // namespace Animator

#endif // _IANIMATION_h