/* INode interface
 * Paul Wightmore 2015
 */
#ifndef _INODE_h
#define _INODE_h

namespace Animator {

class INode
{
public:
  //! The node's time of execution
  virtual time_t time() = 0;
};

} // namespace Animator

#endif // _INODE_h