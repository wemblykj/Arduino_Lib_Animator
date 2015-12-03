/* IApplicator interface
 * Paul Wightmore 2015
 */
#ifndef _ANIMATOR_IAPPLICATOR_h
#define _ANIMATOR_IAPPLICATOR_h

#include "animator/IStream.h"

namespace Animator {

//! An abstract interface for an aplicator of animation nodes to a target component
class IApplicator
{
  //! Apply an animation keyframe node to a component
  /**
   * Note that there may be a time difference between the designated time of \p n and time \p t
   *
   * \param t The current animation time in milliseconds
   * \param t The node which is to be applied after \p t has passed
   */
  virtual void apply(time_t t, const typename IStream::NodeList::node_t& n) = 0;
};

} // namespace Animator

#endif // _ANIMATOR_IAPPLICATOR_h