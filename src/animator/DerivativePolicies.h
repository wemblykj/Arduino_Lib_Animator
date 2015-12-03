/* Applicator derivative policices
 * Paul Wightmore 2015
 */
 
#ifndef _ANIMATOR_DERIVATIVEPOLICIES_h
#define _ANIMATOR_DERIVATIVEPOLICIES_h

namespace Animator {

//! A policy to derive a keyframe value from the current node
/**
  * \tparam T_Payload the type of the target
  */
template<typename T_Payload>
struct KeyframePolicy
{
  T_Payload derive(time_t t, const typename IStream::NodeList::node_t& n)
  {
    // we make an assumption that node is the default implementation provided by this library
    //assert(dynamic_cast<const Node<const T_Payload>&>(n));
    auto node = reinterpret_cast<const Node<const T_Payload>*>(n.payload);
    return node->value();
  }
};

//! A policy to derive an interpolated value from the current and proceeding nodes
/**
  * The target must implement basic overloading operators for + - and *(float)
  * \tparam T_Payload the type of the target
  */
template<typename T_Payload>
struct LinearInterpolatorPolicy
{
  T_Payload derive(time_t t, const typename IStream::NodeList::node_t& n0)
  {
    // we make an assumption that node is the default implementation provided by this library
    //assert(dynamic_cast<const Node<const T_Payload>&>(n0));
    //assert(dynamic_cast<const Node<const T_Payload>&>(n1));
    auto node0 = reinterpret_cast<const Node<const T_Payload>*>(n0.payload);
    auto node1 = reinterpret_cast<const Node<const T_Payload>*>(n0.next->payload);
    
    const auto v0 = node0->value();
    const time_t t0 = node0->time();
    const auto v1 = node1->value();
    const time_t t1 = node1->time();
    const float dt = (float)(t-t0)/(float)(t1-t0);
    return v0 + ((v1-v0)*dt);
  }
};

} // namespace Animator

#endif // _ANIMATOR_DERIVATIVEPOLICIES_h