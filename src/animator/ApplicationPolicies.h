/* Applicator application policices
 * Paul Wightmore 2015
 */
 
#ifndef _ANIMATOR_APPLICATIONPOLICIES_h
#define _ANIMATOR_APPLICATIONPOLICIES_h

namespace Animator {

//! A base policy for storing the target
/**
  * \tparam T_Payload the type of the payload that will be applied to the target
  */
template <typename T_Payload>
struct ApplicationPolicy {
  typedef T_Payload& target_t;
  
  ApplicationPolicy(target_t _target)
    : target(_target) {}
  
protected:
  target_t target;
};
  
//! A policy for assigning a payload to a reference of the target
/**
  * \tparam T_Payload the type of the target
  */
template <typename T_Payload>
struct AssignmentPolicy : protected ApplicationPolicy<T_Payload> {
  typedef T_Payload& target_t;
  
  AssignmentPolicy(target_t _target)
    : ApplicationPolicy<T_Payload>(_target) {}
    
  void apply(const T_Payload& payload) {
    this->target = payload;
  }
};

//! A policy for calling a callback function with the payload as a parameter
/**
  * \tparam T_Payload the type of the target
  */
template <typename T_Payload>
struct CallbackPolicy : protected ApplicationPolicy<T_Payload> {
  typedef void (*target_t)(const T_Payload&);

  CallbackPolicy(target_t _target)
    : ApplicationPolicy<T_Payload>(_target) {}
    
  void apply(const T_Payload& payload) {
    this->target(payload);
  }
};

} // namespace Animator

#endif // _ANIMATOR_APPLICATIONPOLICIES_h