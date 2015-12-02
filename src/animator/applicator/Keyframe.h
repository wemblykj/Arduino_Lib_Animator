/* Keyframe applicator
 * Paul Wightmore 2015
 */
 
#ifndef _ANIMATOR_APPLICATOR_KEYFRAME_h
#define _ANIMATOR_APPLICATOR_KEYFRAME_h

#include "animator/IKeyframeApplicator.h"

namespace Animator {
namespace Applicators {

template<typename T_Payload>
class Keyframe : virtual public IKeyframeApplicator
{
public:
  Keyframe(T_Payload& target)
    : mTarget(target)
  {}

  void apply(time_t t, const INode& n) override
  {
    // we make an assumption that node is the default implementation provided by this library
    //assert(dynamic_cast<const Node<T_Payload>&>(n));
    auto node = reinterpret_cast<const Node<const T_Payload>&>(n);
    mTarget = node.value();
  }

private:
  T_Payload& mTarget;
};

} // namespace Applicators
} // namespace Animator

#endif // _ANIMATOR_APPLICATOR_KEYFRAME_h