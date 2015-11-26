/* IController interface
 * Paul Wightmore 2015
 */
#ifndef _CONTROLLER_h
#define _CONTROLLER_h

namespace Animator {

template<typename T_Payload>
class ForwardLinkedList {
public:
  struct Node {
      Node(T_Payload _p, Node* _next)
        : p(_p_)
        , next(_next)
      {}
      
      T_Payload operator->() { return p; }
      struct Node* next;
      T_Payload p;
  };
  
  ForwardLinkedList()
    : mHead(nullptr)
    , mTail(nullptr)
  {}
  
  Node* head()
  { return mHead; }
  
  T_Payload pop()
  {
    if (!mHead)
      return nullptr;
      
    T_Payload p = mHead.p;
    auto n = mHead;
    mHead = mHead->next; 
    delete n;
    
    if (!mHead)
      mTail = nullptr;
      
    return p;
  }
  
  void push(T_Payload p)
  { 
    auto n = new Node(p, mHead);
    if(!mHead) mTail = n;
    mHead = n; 
  }
  
  size_t size() 
  {
    size_t count = 0;
    auto n = mHead;
    while(n) ++count;
    
    return count;
  }
  
  void push_back(T_Payload p)
  {
    auto n = new Node(p, nullptr);
    mTail->next = n;
    mTail = n;
  }
  
protected:
  Node* mHead;
  Node* mTail;
};

} // namespace Animator