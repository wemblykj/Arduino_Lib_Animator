/* Animator
 * Paul Wightmore 2015
 */
#ifndef _ANIMATOR_h
#define _ANIMATOR_h

#include "animator/IAnimation.h"
#include "animator/IController.h"
#include "animator/IStream.h"

using namespace std;

namespace Animator {

class INode;
class IPlaybackController;

//! Create an animation stream
/**
  * Note the same stream can be used by one or more animations as long as the name remains unique in all animations
  *
  * \param name A unique name for the stream
  * \param nodes A dynamic list of nodes
  */
IStream* createStream(const char* name, const IStream::NodeList& node = IStream::NodeList());

//! Convenience function to create an animation stream from an array of nodes
/**
  * \param name A unique name for the stream
  * \param nodes A pointer to a static array of nodes
  * \param count The number of entries in the \p nodes array
  */
IStream* createStream(const char* name, const INode* (*nodes), size_t count);

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