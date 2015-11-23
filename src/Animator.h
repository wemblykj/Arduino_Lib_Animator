/* Animator
 * Paul Wightmore 2015
 */
#ifndef _ANIMATOR_h
#define _ANIMATOR_h

#include <memory.h>

using namespace std;

namespace Animator {

class IController;

//! Create an animation stream
/**
  * Note the same stream can be used by one or more animations as long as the name remains unique in all animations
  *
  * \param name A unique name for the stream
  */
shared_ptr<IStream> createAnimationStream(string name);

//! Create an animation
/**
  * Note the same animation can be used by one or more animation controllers
  */
shared_ptr<IAnimation> createAnimation();

//! Create an animation controller with a predefined update resolution
/**
 * A custom update resolution can be defined by specifying Resolution::Custom and defining CUSTOM_RESOLUTION
 * in your sketch before including the Animator header file.
 *
 * \param applicator The animation resolution to use for the controller
 * \return An IController instance
 */
shared_ptr<IController> createAnimationController();


} // namespace Animator

#endif // _ANIMATOR_h