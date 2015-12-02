/* Default IStream implemenation
 * Paul Wightmore 2015
 */
#ifndef _ANIMATOR_STREAM_h
#define _ANIMATOR_STREAM_h

#include "../animator/IStream.h"

#include "../animator/Common.h"

namespace Animator {

class INode;

class Stream : virtual public IStream {
public:
  Stream(const char* name, const NodeList& nodes);

  // Implement IStream interface
  const char* name() override;
  const NodeList getNodes() override;
  const NodeList getNodes(range_t range) override;
  void addNode(time_t time, const INode* node) override;
  void removeNode(time_t time, const INode* node) override;
  
private:
  const char* mName;
  IStream::NodeList mNodes;
};

} // namespace Animator

#endif // _ANIMATOR_STREAM_h