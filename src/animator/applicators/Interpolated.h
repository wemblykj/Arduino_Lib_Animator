#include "../IKeyframeApplicator.h"

namespace Animator {
namespace Applicator {

/**
  * The target must implement basic overloading operators for - and *
  * \tparam T_Payload the type of the target
  */
template<typename T_Payload>
class Keyframe : virtual public IApplicator
{
public:
  Keyframe(T_Payload& target)
    : mTarget(target)
  {}

  virtual void apply(time_t t,const INode& n0, const INode& n1) = 0;
  {
    // we make an assumption that node is the default implementation provided by this library
    assert(dynamic_cast<Node<T_Payload>*>(n0);
    assert(dynamic_cast<Node<T_Payload>*>(n1);
    auto node0 = static_cast<Node<T_Payload>*>(n0);
    auto node1 = static_cast<Node<T_Payload>*>(n1);
    auto length = (n1->time() - n0->time())/t;
    //        ( t - n0)            ( t - n0)
    // u = v2 (-------) + v1 ( 1 - (-------)    
    //        (n1 - n0)            (n1 - n0)
    mTarget = (node1->value() - node0->value());
  }

private:
  T_Payload& mTarget;
};

} // namespace Applicator
} // namespace Animator
