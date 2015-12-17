/* Default IStream implemenation
 * Paul Wightmore 2015
 */
#ifndef _ANIMATOR_STREAM_h
#define _ANIMATOR_STREAM_h

#include "../animator/Common.h"
#include "../animator/IStream.h"
#include "../animator/Node.h"


namespace Animator {

class INode;

template<
    typename T_Payload,
    template <typename> class T_NodeImpl = Node
  >
class Stream : virtual public IStream {
public:
  //! A type safe Stream specific node type
  typedef T_NodeImpl<T_Payload> node_t;
  //! A type safe list of Stream specific nodes
  typedef ForwardLinkedList<const node_t*> NodeList;
  
public:
  Stream(const String& name, const NodeList& nodes)
	: mName(name)
  {
    auto n = nodes.head();
    while (n) {
      mNodes.push_back(n->payload);
      n = n->next;
    }
  }
  
  //! Create a concrete node that is compatible with this stream
  node_t createCompatibleNode(time_t time, T_Payload payload) const {
    return new node_t(time, payload);
  }
  
  // Implement IStream interface
  String name() const override {
    return mName; }
  
  const time_t length() const override {
    if (auto tail = mNodes.tail())
      return tail->payload->time();
      
    return 0;
  }
  
  IStream::NodeList getNodes() override {
    return mNodes; }
  
  const IStream::NodeList getNodes() const override {
	return mNodes; }
  
  IStream::NodeList getNodes(range_t range) override {
    return IStream::NodeList(); }
	
  const IStream::NodeList getNodes(range_t range) const override {
	return IStream::NodeList(); }
  
  void addNode(time_t time, const INode* node) override {
    mNodes.push_back(node); }
  
  void removeNode(time_t time, const INode* node) override {
    mNodes.remove(node); }
  
private:
  String mName;
  IStream::NodeList mNodes;
};

} // namespace Animator

#endif // _ANIMATOR_STREAM_h