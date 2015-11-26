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
  //! A list of animation nodes
  typedef IApplicator* (*ApplicatorList)[];
  
  //! Specify the playback mode of the animation
  /**  If Loop is not specified then the animation will perform one complete pass, and in the case of PingPong 1 pass in each direction
    */
  enum PlaybackFlags {
    Forward = 0,  // Play from the beginning to the end
    Reverse = 1,  // Play in reverse from the end to the beginning
    PingPong = 2, // Play once in one direction and then once in the other; can be combined with all other flags
    Loop = 3,     // Play in a loop; can be combined with all other flags
  };
public:
  //! Get the animation associated with this controller
  virtual IAnimation& animation() = 0;
  
  //! Return the active playback flags
  virtual PlaybackFlags playbackFlags() const = 0;
  
  //! The length of the animation
  /**  The length of the animation in milliseconds between the first node ande the last
    *  the length takes into consideration the playback speed and so may vary from that calculated by another controller
    *  for the same animation
    * \return The length of the animation in the context of this controller in milliseconds
    */
  virtual time_t length() const = 0;
  
  //! Return the current playback position of the animation
  /**
    *  \return The playback position in milliseconds, this will be between between 0 and length()
    */
  virtual time_t playbackPosition();
  
  //! Get a list of all applicators for a specific stream
  virtual ApplicatorList streamApplicators(const char* streamName) = 0;
  
  //! Add an applicator to the named stream
  virtual void addStreamApplicator(const char* streamName, IApplicator* applicator) = 0;
  
  //! Add a list of applicators for the named animation stream
  /**
    * this will destroy all existing applicators for the named stream
    */
  virtual void addStreamApplicators(const char* streamName, ApplicatorList) = 0;
  
  //! Remove \p applicator from the stream it is associated with
  /**
    * \return The name of the stream the applicator was associated with
    */
  virtual const char* removeStreamApplicator(IApplicator* applicator) = 0;
  
  //! Remove all applicators for the named animation stream
  virtual ApplicatorList removeStreamApplicators(const char* streamName) = 0;
  
  //! Update the controller for the specified time period \p deltaTime
  virtual void update(time_t deltaTime) const = 0;
  
  //! Reset the controller to its initial state
  /**  This will stop the animation and seek back to the beginning
    *
    */
  virtual void reset() = 0;
};

} // namespace Animator

#endif // _ICONTROLLER_h