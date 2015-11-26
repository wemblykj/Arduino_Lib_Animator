#include "../IInterpolatingApplicator.h"

namespace Animator {
namespace Applicator {

//! Generic linear interpolator
/**
  * The target must implement basic overloading operators for + - and *(float)
  * \tparam T_Payload the type of the target
  */
template<typename T_Payload>
class LinearInterpolator : virtual public IInterpolatingApplicator
{
public:
  Interpolator(T_Payload& target)
    : mTarget(target)
  {}

  virtual void apply(time_t t,const INode& n0, const INode& n1) = 0;
  {
    // we make an assumption that node is the default implementation provided by this library
    assert(dynamic_cast<Node<T_Payload>*>(n0);
    assert(dynamic_cast<Node<T_Payload>*>(n1);
    auto node0 = static_cast<Node<T_Payload>*>(n0);
    auto node1 = static_cast<Node<T_Payload>*>(n1);
    
    const auto v0 = node0->value();
    const time_t t0 = node0->time();
    const auto v1 = node1->value();
    const time_t t1 = node1->time();
    const float dt = (float)(t-t0)/(float)(t1-t0);
    mTarget = v0 + ((v1-v0)*dt);
  }

private:
  T_Payload& mTarget;
};

} // namespace Applicator
} // namespace Animator
