/* Keyframe applicator
 * Paul Wightmore 2015
 */
 
#ifndef _ANIMATOR_APPLICATOR_h
#define _ANIMATOR_APPLICATOR_h

#include "animator/IApplicator.h"

namespace Animator {

template<
    typename T_Payload,
    template <typename> class DerivativePolicy,
    template <typename> class ApplicationPolicy
  >
class Applicator : public DerivativePolicy<T_Payload>, public ApplicationPolicy<T_Payload>, virtual public IApplicator
{
public:
  typedef typename ApplicationPolicy<T_Payload>::target_t target_t;
  
  Applicator(target_t target)
    : ApplicationPolicy<T_Payload>(target)
  {}

  void apply(time_t t, const typename IStream::NodeList::node_t& n) override
  {
    
    //assert(dynamic_cast<const Node<T_Payload>&>(n));
    //auto node = reinterpret_cast<const Node<const T_Payload>&>(n);
    const auto payload = DerivativePolicy<T_Payload>::derive(t, n);
    ApplicationPolicy<T_Payload>::apply(payload);
  }
};

} // namespace Animator

#endif // _ANIMATOR_APPLICATOR_h