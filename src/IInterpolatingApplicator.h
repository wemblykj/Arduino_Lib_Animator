/* InterpolatingApplicator interface
 * Paul Wightmore 2015
 */
#ifndef _IINTERPOLATINGAPPLICATOR_h
#define _IINTERPOLATINGAPPLICATOR_h


#include "IApplicator.h"

namespace Animator {

class IInterpolatingApplicator : virtual public IApplicator
{
public:
  //! Apply an animation to a component by interpolating between two nodes
  /**
   * \param The elapsed milliseconds since the last update 
   */
  virtual void apply(time_t t, shared_ptr<INode> n0, shared_ptr<INode> n1) = 0;
};

} // namespace Animator

#endif // _IINTERPOLATINGAPPLICATOR_h