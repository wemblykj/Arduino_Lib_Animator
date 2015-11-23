/* IStream interface
 * Paul Wightmore 2015
 */
#ifndef _ISTREAM_h
#define _ISTREAM_h

#include <list>
#include <memory>

using namespace std;

namespace Animator {

class INode;

class IStream
{
public:
  //! A list of animation nodes
  typedef std::list<shared_ptr<INode>> NodeList
  
public:
  //! A unique name for the stream
  virtual string name();
  
  //! Add a new node to the animation
  virtual void addNode(time_t time, const shared_ptr<INode> node);
  
  //! Remove a node from the animation
  virtual void removeNode(time_t time, const shared_ptr<INode> node);
  
  //! Get all nodes in the animation
  virtual NodeList getNodes();
  
  //! Get all nodes within \p range
  virtual void getNodes(range_t range);
};

} // namespace Animator

#endif // _ISTREAM_h