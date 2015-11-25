/* InterpolatingApplicator interface
 * Paul Wightmore 2015
 */
#ifndef _IINTERPOLATINGAPPLICATOR_h
#define _IINTERPOLATINGAPPLICATOR_h

#include "IApplicator.h"

#include "Common.h"

namespace Animator {

class IInterpolatingApplicator : virtual public IApplicator
{
public:
  //! Apply an animation to a component by interpolating between two nodes
  /**
   * \param The elapsed milliseconds since the last update 
   */
  virtual void apply(time_t t,const INode& n0, const INode& n1) = 0;
};

} // namespace Animator

#endif // _IINTERPOLATINGAPPLICATOR_h