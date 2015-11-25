/* IStream interface
 * Paul Wightmore 2015
 */
#ifndef _ISTREAM_h
#define _ISTREAM_h

using namespace std;

namespace Animator {

class INode;

class IStream
{
public:
  //! A list of animation nodes
  typedef INode* (*NodeList)[];
  
public:
  //! A unique name for the stream
  virtual const char* name();
  
  //! Add a new node to the animation
  //virtual void addNode(time_t time, INode*> node);
  
  //! Remove a node from the animation
  //virtual void removeNode(time_t time, const INode* node);
  
  //! Get all nodes in the animation
  virtual NodeList getNodes(size_t& count);
  
  //! Get all nodes within \p range
  //virtual NodeList getNodes(range_t range, size_t& count);
};

} // namespace Animator

#endif // _ISTREAM_h