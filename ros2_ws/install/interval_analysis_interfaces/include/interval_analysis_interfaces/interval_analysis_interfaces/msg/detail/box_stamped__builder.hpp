// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interval_analysis_interfaces:msg/BoxStamped.idl
// generated code does not contain a copyright notice

#ifndef INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX_STAMPED__BUILDER_HPP_
#define INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interval_analysis_interfaces/msg/detail/box_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interval_analysis_interfaces
{

namespace msg
{

namespace builder
{

class Init_BoxStamped_intervals
{
public:
  explicit Init_BoxStamped_intervals(::interval_analysis_interfaces::msg::BoxStamped & msg)
  : msg_(msg)
  {}
  ::interval_analysis_interfaces::msg::BoxStamped intervals(::interval_analysis_interfaces::msg::BoxStamped::_intervals_type arg)
  {
    msg_.intervals = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::BoxStamped msg_;
};

class Init_BoxStamped_name
{
public:
  explicit Init_BoxStamped_name(::interval_analysis_interfaces::msg::BoxStamped & msg)
  : msg_(msg)
  {}
  Init_BoxStamped_intervals name(::interval_analysis_interfaces::msg::BoxStamped::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_BoxStamped_intervals(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::BoxStamped msg_;
};

class Init_BoxStamped_header
{
public:
  Init_BoxStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoxStamped_name header(::interval_analysis_interfaces::msg::BoxStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_BoxStamped_name(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::BoxStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interval_analysis_interfaces::msg::BoxStamped>()
{
  return interval_analysis_interfaces::msg::builder::Init_BoxStamped_header();
}

}  // namespace interval_analysis_interfaces

#endif  // INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX_STAMPED__BUILDER_HPP_
