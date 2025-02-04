// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interval_analysis_interfaces:msg/Tube.idl
// generated code does not contain a copyright notice

#ifndef INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__TUBE__STRUCT_HPP_
#define INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__TUBE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'boxes'
#include "interval_analysis_interfaces/msg/detail/box__struct.hpp"
// Member 't_domain'
#include "interval_analysis_interfaces/msg/detail/interval__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__interval_analysis_interfaces__msg__Tube __attribute__((deprecated))
#else
# define DEPRECATED__interval_analysis_interfaces__msg__Tube __declspec(deprecated)
#endif

namespace interval_analysis_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Tube_
{
  using Type = Tube_<ContainerAllocator>;

  explicit Tube_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : t_domain(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->dt = 0.0;
    }
  }

  explicit Tube_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    t_domain(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->dt = 0.0;
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _boxes_type =
    std::vector<interval_analysis_interfaces::msg::Box_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<interval_analysis_interfaces::msg::Box_<ContainerAllocator>>>;
  _boxes_type boxes;
  using _t_domain_type =
    interval_analysis_interfaces::msg::Interval_<ContainerAllocator>;
  _t_domain_type t_domain;
  using _dt_type =
    double;
  _dt_type dt;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__boxes(
    const std::vector<interval_analysis_interfaces::msg::Box_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<interval_analysis_interfaces::msg::Box_<ContainerAllocator>>> & _arg)
  {
    this->boxes = _arg;
    return *this;
  }
  Type & set__t_domain(
    const interval_analysis_interfaces::msg::Interval_<ContainerAllocator> & _arg)
  {
    this->t_domain = _arg;
    return *this;
  }
  Type & set__dt(
    const double & _arg)
  {
    this->dt = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interval_analysis_interfaces::msg::Tube_<ContainerAllocator> *;
  using ConstRawPtr =
    const interval_analysis_interfaces::msg::Tube_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interval_analysis_interfaces::msg::Tube_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interval_analysis_interfaces::msg::Tube_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interval_analysis_interfaces::msg::Tube_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interval_analysis_interfaces::msg::Tube_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interval_analysis_interfaces::msg::Tube_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interval_analysis_interfaces::msg::Tube_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interval_analysis_interfaces::msg::Tube_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interval_analysis_interfaces::msg::Tube_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interval_analysis_interfaces__msg__Tube
    std::shared_ptr<interval_analysis_interfaces::msg::Tube_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interval_analysis_interfaces__msg__Tube
    std::shared_ptr<interval_analysis_interfaces::msg::Tube_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Tube_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->boxes != other.boxes) {
      return false;
    }
    if (this->t_domain != other.t_domain) {
      return false;
    }
    if (this->dt != other.dt) {
      return false;
    }
    return true;
  }
  bool operator!=(const Tube_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Tube_

// alias to use template instance with default allocator
using Tube =
  interval_analysis_interfaces::msg::Tube_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interval_analysis_interfaces

#endif  // INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__TUBE__STRUCT_HPP_
