/* Animator
 * Paul Wightmore 2015
 */
#ifndef _ANIMATOR_h
#define _ANIMATOR_h

#include "animator/IAnimation.h"
#include "animator/IStream.h"
#include "animator/Applicator.h"
#include "animator/Node.h"
#include "animator/Stream.h"

using namespace std;

namespace Animator {

class IController;
class INode;
class IPlaybackController;

template<
    typename T_Payload,
    template <typename> class T_NodeImpl = Node
  >
T_NodeImpl<T_Payload>* createCompatibleNode(time_t time, T_Payload payload) {
  return new T_NodeImpl<T_Payload>(time, payload);
}

template<
    typename T_Payload,
    template <typename> class DerivativePolicy,
    template <typename> class ApplicationPolicy,
    template <typename> class T_NodeImpl = Node
  >
Applicator<T_Payload, DerivativePolicy, ApplicationPolicy>* createCompatibleApplicator(typename Applicator<T_Payload, DerivativePolicy, ApplicationPolicy>::target_t target) {
  return new Applicator<T_Payload, DerivativePolicy, ApplicationPolicy>(target);
}
//! Create an animation stream
/**
  * Note the same stream can be used by one or more animations as long as the name remains unique in all animations
  *
  * \param name A unique name for the stream
  * \param nodes A dynamic list of nodes
  */
template<
    typename T_Payload,
    template <typename> class T_NodeImpl = Node
  >
IStream* createStream(const char* name, const typename Stream<T_Payload, T_NodeImpl>::NodeList& nodes = Stream<T_Payload, T_NodeImpl>::NodeList()) {
  return new Stream<T_Payload, T_NodeImpl>(name, nodes);
}


//! Convenience function to create an animation stream from an array of nodes
/**
  * \param name A unique name for the stream
  * \param nodes A pointer to a static array of nodes
  * \param count The number of entries in the \p nodes array
  */
template<
    typename T_Payload,
    template <typename> class T_NodeImpl = Node
  >
IStream* createStream(const char* name,  const time_t (*times), const T_Payload (*payloads), size_t count) {
  typename Stream<T_Payload, T_NodeImpl>::NodeList nl;
  for (int i = 0; i < count; ++i)
    nl.push_back(createCompatibleNode<T_Payload, T_NodeImpl>(times[i], payloads[i]));
    
  return createStream<T_Payload, T_NodeImpl>(name, nl);
}

//! Create an animation
/**
  * Note the same animation can be used by one or more animation controllers
  */
IAnimation* createAnimation(const IAnimation::StreamList& = IAnimation::StreamList());

//! Convenience function to create an animation from an array of streams
/**
  * \param nodes A pointer to a static array of streams
  * \param count The number of entries in the \p streams array
  */
IAnimation* createAnimation(const IStream* (*streams), size_t count);

//! Create an animation controller with a predefined update resolution
/**
 * A custom update resolution can be defined by specifying Resolution::Custom and defining CUSTOM_RESOLUTION
 * in your sketch before including the Animator header file.
 *
 * \param applicator The animation resolution to use for the controller
 * \return An IController instance
 */
IPlaybackController* createPlaybackController(IAnimation* animation, PlaybackFlags pf = Forward);

} // namespace Animator

#endif // _ANIMATOR_h