namespace Animator {
namespace Applicator {
  
template <typename T_Payload>
struct AssignmentPolicy {
  typedef T_Payload& applicatee_t;
  
  AssignmentPolicy(applicatee_t _applicatee)
    : applicatee(_applicatee) {}
    
  void apply(const T_Payload& payload) {
    applicatee = payload;
  }
private:
  applicatee_t applicatee;
};

template <typename T_Payload>
struct CallbackPolicy {
  typedef void (*applicatee_t)(const T_Payload&);

  CallbackPolicy(applicatee_t _applicatee)
    : applicatee(_applicatee) {}
    
  void apply(const T_Payload& payload) {
    applicatee(payload);
  }
  
private:
  applicatee_t applicatee;
};

} // namespace Applicator
} // namespace Animator