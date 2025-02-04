// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interval_analysis_interfaces:msg/Box.idl
// generated code does not contain a copyright notice

#ifndef INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX__BUILDER_HPP_
#define INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interval_analysis_interfaces/msg/detail/box__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interval_analysis_interfaces
{

namespace msg
{

namespace builder
{

class Init_Box_intervals
{
public:
  explicit Init_Box_intervals(::interval_analysis_interfaces::msg::Box & msg)
  : msg_(msg)
  {}
  ::interval_analysis_interfaces::msg::Box intervals(::interval_analysis_interfaces::msg::Box::_intervals_type arg)
  {
    msg_.intervals = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::Box msg_;
};

class Init_Box_name
{
public:
  Init_Box_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Box_intervals name(::interval_analysis_interfaces::msg::Box::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Box_intervals(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::Box msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interval_analysis_interfaces::msg::Box>()
{
  return interval_analysis_interfaces::msg::builder::Init_Box_name();
}

}  // namespace interval_analysis_interfaces

#endif  // INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX__BUILDER_HPP_
