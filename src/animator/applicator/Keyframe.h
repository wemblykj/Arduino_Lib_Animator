/* Keyframe applicator
 * Paul Wightmore 2015
 */
 
#ifndef _ANIMATOR_APPLICATOR_KEYFRAME_h
#define _ANIMATOR_APPLICATOR_KEYFRAME_h

#include "animator/IKeyframeApplicator.h"

namespace Animator {
namespace Applicators {

template<
    typename T_Payload,
    template <typename> class ApplicationPolicy
  >
class Keyframe : public ApplicationPolicy<T_Payload>, virtual public IKeyframeApplicator
{
  typedef typename ApplicationPolicy<T_Payload>::applicatee_t applicatee_t;
  
public:
  Keyframe(const applicatee_t& applicatee)
    : ApplicationPolicy<T_Payload>(applicatee)
  {}

  void apply(time_t t, const INode& n) override
  {
    // we make an assumption that node is the default implementation provided by this library
    //assert(dynamic_cast<const Node<T_Payload>&>(n));
    auto node = reinterpret_cast<const Node<const T_Payload>&>(n);
    ApplicationPolicy<T_Payload>::apply(node.value());
  }
};

} // namespace Applicators
} // namespace Animator

#endif // _ANIMATOR_APPLICATOR_KEYFRAME_h