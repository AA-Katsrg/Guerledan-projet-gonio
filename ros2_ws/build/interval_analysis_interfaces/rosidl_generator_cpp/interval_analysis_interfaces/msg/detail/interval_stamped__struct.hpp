// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interval_analysis_interfaces:msg/IntervalStamped.idl
// generated code does not contain a copyright notice

#ifndef INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__INTERVAL_STAMPED__STRUCT_HPP_
#define INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__INTERVAL_STAMPED__STRUCT_HPP_

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

#ifndef _WIN32
# define DEPRECATED__interval_analysis_interfaces__msg__IntervalStamped __attribute__((deprecated))
#else
# define DEPRECATED__interval_analysis_interfaces__msg__IntervalStamped __declspec(deprecated)
#endif

namespace interval_analysis_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IntervalStamped_
{
  using Type = IntervalStamped_<ContainerAllocator>;

  explicit IntervalStamped_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->start = 0.0;
      this->end = 0.0;
    }
  }

  explicit IntervalStamped_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->start = 0.0;
      this->end = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _start_type =
    double;
  _start_type start;
  using _end_type =
    double;
  _end_type end;

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
  Type & set__start(
    const double & _arg)
  {
    this->start = _arg;
    return *this;
  }
  Type & set__end(
    const double & _arg)
  {
    this->end = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interval_analysis_interfaces::msg::IntervalStamped_<ContainerAllocator> *;
  using ConstRawPtr =
    const interval_analysis_interfaces::msg::IntervalStamped_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interval_analysis_interfaces::msg::IntervalStamped_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interval_analysis_interfaces::msg::IntervalStamped_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interval_analysis_interfaces::msg::IntervalStamped_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interval_analysis_interfaces::msg::IntervalStamped_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interval_analysis_interfaces::msg::IntervalStamped_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interval_analysis_interfaces::msg::IntervalStamped_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interval_analysis_interfaces::msg::IntervalStamped_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interval_analysis_interfaces::msg::IntervalStamped_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interval_analysis_interfaces__msg__IntervalStamped
    std::shared_ptr<interval_analysis_interfaces::msg::IntervalStamped_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interval_analysis_interfaces__msg__IntervalStamped
    std::shared_ptr<interval_analysis_interfaces::msg::IntervalStamped_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IntervalStamped_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    if (this->start != other.start) {
      return false;
    }
    if (this->end != other.end) {
      return false;
    }
    return true;
  }
  bool operator!=(const IntervalStamped_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IntervalStamped_

// alias to use template instance with default allocator
using IntervalStamped =
  interval_analysis_interfaces::msg::IntervalStamped_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interval_analysis_interfaces

#endif  // INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__INTERVAL_STAMPED__STRUCT_HPP_
