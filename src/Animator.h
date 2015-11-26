/* Animator
 * Paul Wightmore 2015
 */
#ifndef _ANIMATOR_h
#define _ANIMATOR_h

using namespace std;

namespace Animator {

class IAnimation;
class IPlaybackController;
class IStream;

//! Create an animation stream
/**
  * Note the same stream can be used by one or more animations as long as the name remains unique in all animations
  *
  * \param name A unique name for the stream
  */
IStream* createStream(const char* name);

//! Create an animation
/**
  * Note the same animation can be used by one or more animation controllers
  */
IAnimation* createAnimation(IStream*[]);

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