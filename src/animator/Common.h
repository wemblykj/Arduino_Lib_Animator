/* Common
 * Paul Wightmore 2015
 */
#ifndef _COMMON_h
#define _COMMON_h

#include <Arduino.h>

namespace Animator {

typedef uint16_t time_t;
struct range_t {
  time_t begin;
  time_t end;
};

} // namespace Animator

#endif // _COMMON_h