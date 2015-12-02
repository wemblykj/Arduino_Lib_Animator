/* INode interface
 * Paul Wightmore 2015
 */
#ifndef _ANIMATOR_INODE_h
#define _ANIMATOR_INODE_h

#include "Common.h"

namespace Animator {

class INode
{
public:
  virtual ~INode() {};
  
  //! The node's time of execution
  virtual time_t time() const = 0;
};

} // namespace Animator

#endif // _ANIMATOR_INODE_h
