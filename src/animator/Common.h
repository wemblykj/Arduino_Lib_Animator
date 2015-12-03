/* Common
 * Paul Wightmore 2015
 */
#ifndef _ANIMATOR_COMMON_h
#define _ANIMATOR_COMMON_h

#define __ASSERT_USE_STDERR
#include <assert.h>

#include <Arduino.h>

namespace Animator {

typedef uint16_t time_t;
struct range_t {
  time_t begin;
  time_t end;
};

//! Specify the playback mode of the animation
/**  If Loop is not specified then the animation will perform one complete pass, and in the case of PingPong 1 pass in each direction
  */
enum PlaybackFlags {
  Forward = 0,  // Play from the beginning to the end
  Reverse = 1,  // Play in reverse from the end to the beginning
  PingPong = 2, // Play once in one direction and then once in the other; can be combined with all other flags
  Loop = 3,     // Play in a loop; can be combined with all other flags
};

// handle diagnostic informations given by assertion and abort program execution:
// Snippet taken from https://gist.github.com/jlesech/3089916
inline void __assert(const char *__func, const char *__file, int __lineno, const char *__sexp) {
    // transmit diagnostic informations through serial link. 
    Serial.println(__func);
    Serial.println(__file);
    Serial.println(__lineno, DEC);
    Serial.println(__sexp);
    Serial.flush();
    // abort program execution.
    abort();
}

} // namespace Animator

#endif // _ANIMATOR_COMMON_h