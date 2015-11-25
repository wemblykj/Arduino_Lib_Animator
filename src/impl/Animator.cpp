#include "..\Animator.h"

namespace Animator {

IStream* createStream(const char* name)
{
  return nullptr;
}

//! Create an animation
/**
  * Note the same animation can be used by one or more animation controllers
  */
IAnimation* createAnimation(IStream*[])
{
  return nullptr;
}

//! Create an animation controller with a predefined update resolution
/**
 * A custom update resolution can be defined by specifying Resolution::Custom and defining CUSTOM_RESOLUTION
 * in your sketch before including the Animator header file.
 *
 * \param applicator The animation resolution to use for the controller
 * \return An IController instance
 */
IPlaybackController* createPlaybackController(IAnimation* animation)
{
  return nullptr;
}

} // namespace Animator
