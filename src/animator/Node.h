/* Node
 * Paul Wightmore 2015
 */
#ifndef _NODE_h
#define _NODE_h

#include "animator/INode.h"

#include "animator/Common.h"

namespace Animator {

template<typename T_Payload>
class Node : virtual public INode
{
public:
  Node(const time_t time, const T_Payload value)
    : mTime(time)
    , mValue(value)
  {}

  const T_Payload& value() const
  { return mValue; }
  
  // implement INode
  time_t time() const override
  { return mTime; }

private:
  const time_t mTime;
  const T_Payload mValue;
};

} // namespace Animator

#endif // _NODE_h