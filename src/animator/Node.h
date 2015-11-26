#include "../INode.h"

#include "../Common.h"

template<T_Payload>
class Node : virtual public INode
{
public:
  Node(time_t, const T_Payload value)
    : mTime(time)
    , mValue(value)
  {}

  const T_Payload value() const;

  // implement INode
  time_t time() const override;

private:
  time_t mTime;
  const T_Payload mValue;
};
