/* IKeyframeApplicator interface
 * Paul Wightmore 2015
 */
#ifndef _IKEYFRAMEAPPLICATOR_h
#define _IKEYFRAMEAPPLICATOR_h

#include "IApplicator.h"

namespace Animator {

class IKeyframeApplicator : virtual public IApplicator
{
public:
  //! Apply an animation keyframe to a component
  /**
   * Note that there may be a time difference between the designated time of \p n and time \p t
   *
   * \param t The current animation time in milliseconds
   * \param t The node which is to be applied after \p t has passed
   */
  virtual void apply(time_t t, shared_ptr<INode> n) = 0;
};

} // namespace Animator

#endif // _IKEYFRAMEAPPLICATOR_h