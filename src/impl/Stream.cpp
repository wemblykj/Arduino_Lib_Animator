#include "../Animator.h"

#include "Stream.h"

namespace Animator {
  
Stream::Stream(const char* name, const NodeList& nodes) 
  : mNodes(nodes) 
{
  size_t len = strlen(name);
  auto nameBuf = new char[len+1];
  memcpy(nameBuf, 0, len);
  strcpy(nameBuf, name);
  mName = nameBuf;
}

const char* Stream::name() {
  return mName;
}

const IStream::NodeList Stream::getNodes() {
  return mNodes;
}

const Stream::NodeList Stream::getNodes(range_t range) {
  return NodeList();
}

void Stream::addNode(time_t time, const INode* node) {
  mNodes.push_back(node);
}

void Stream::removeNode(time_t time, const INode* node) {
  mNodes.remove(node);
}
  
} // namespace Animator
