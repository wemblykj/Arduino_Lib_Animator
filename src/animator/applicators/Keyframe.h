#include "../IKeyframeApplicator.h"

namespace Animator {
namespace Applicator {

template<typename T_Payload>
class Keyframe : virtual public IKeyframeApplicator
{
public:
  Keyframe(T_Payload& target)
    : mTarget(target)
  {}

  void apply(time_t t, const INode* n)
  {
    // we make an assumption that node is the default implementation provided by this library
    assert(dynamic_cast<Node<T_Payload>*>(n);
    auto node = static_cast<Node<T_Payload>*>(n);
    mTarget = node->value();
  }

private:
  T_Payload& mTarget;
};

} // namespace Applicator
} // namespace Animator
