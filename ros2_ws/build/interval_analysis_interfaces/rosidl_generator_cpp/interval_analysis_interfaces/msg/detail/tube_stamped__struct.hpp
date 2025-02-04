// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interval_analysis_interfaces:msg/TubeStamped.idl
// generated code does not contain a copyright notice

#ifndef INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__TUBE_STAMPED__STRUCT_HPP_
#define INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__TUBE_STAMPED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'boxes'
#include "interval_analysis_interfaces/msg/detail/box__struct.hpp"
// Member 't_domain'
#include "interval_analysis_interfaces/msg/detail/interval__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__interval_analysis_interfaces__msg__TubeStamped __attribute__((deprecated))
#else
# define DEPRECATED__interval_analysis_interfaces__msg__TubeStamped __declspec(deprecated)
#endif

namespace interval_analysis_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TubeStamped_
{
  using Type = TubeStamped_<ContainerAllocator>;

  explicit TubeStamped_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    t_domain(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->dt = 0.0;
    }
  }

  explicit TubeStamped_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    name(_alloc),
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
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
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
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
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
    interval_analysis_interfaces::msg::TubeStamped_<ContainerAllocator> *;
  using ConstRawPtr =
    const interval_analysis_interfaces::msg::TubeStamped_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interval_analysis_interfaces::msg::TubeStamped_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interval_analysis_interfaces::msg::TubeStamped_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interval_analysis_interfaces::msg::TubeStamped_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interval_analysis_interfaces::msg::TubeStamped_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interval_analysis_interfaces::msg::TubeStamped_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interval_analysis_interfaces::msg::TubeStamped_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interval_analysis_interfaces::msg::TubeStamped_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interval_analysis_interfaces::msg::TubeStamped_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interval_analysis_interfaces__msg__TubeStamped
    std::shared_ptr<interval_analysis_interfaces::msg::TubeStamped_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interval_analysis_interfaces__msg__TubeStamped
    std::shared_ptr<interval_analysis_interfaces::msg::TubeStamped_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TubeStamped_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
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
  bool operator!=(const TubeStamped_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TubeStamped_

// alias to use template instance with default allocator
using TubeStamped =
  interval_analysis_interfaces::msg::TubeStamped_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interval_analysis_interfaces

#endif  // INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__TUBE_STAMPED__STRUCT_HPP_
