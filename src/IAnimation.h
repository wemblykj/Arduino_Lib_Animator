/* IAnimation interface
 * Paul Wightmore 2015
 */
#ifndef _IANIMATION_h
#define _IANIMATION_h

#include "INode.h"

#include <list>
#include <memory.h>

using namespace std;

namespace Animator {

class IStream;

class IAnimation
{
public:
  typedef list<shared_ptr<IStream>> StreamList
  
public:
  virtual void addStream(const shared_ptr<IStream>& stream) = 0;
  virtual void removeStream(const shared_ptr<IStream>& stream) = 0;
  virtual void StreamList getStreams();
};

} // namespace Animator

#endif // _IANIMATION_h