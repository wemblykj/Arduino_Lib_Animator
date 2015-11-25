/* IController interface
 * Paul Wightmore 2015
 */
#ifndef _ICONTROLLER_h
#define _ICONTROLLER_h

namespace Animator {

class IAnimation;
class IPlaybackControls;

class IController
{
public:
  //! Update the controller for the specified time period \p millis
  virtual void update(time_t millis);
  //! Get the animation associated with this controller
  virtual IAnimation& animation() = 0;
  virtual time_t length();
  //! Reset the controller to its initial state
  virtual void reset() = 0;
  //! Specify an applicator for a named animation stream
  //virtual setStreamApplicator(string streamName, IApplicator> applicator) = 0;
  
};

} // namespace Animator

#endif // _ICONTROLLER_h