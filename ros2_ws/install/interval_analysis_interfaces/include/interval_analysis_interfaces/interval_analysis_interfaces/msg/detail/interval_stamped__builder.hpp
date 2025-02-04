// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interval_analysis_interfaces:msg/IntervalStamped.idl
// generated code does not contain a copyright notice

#ifndef INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__INTERVAL_STAMPED__BUILDER_HPP_
#define INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__INTERVAL_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interval_analysis_interfaces/msg/detail/interval_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interval_analysis_interfaces
{

namespace msg
{

namespace builder
{

class Init_IntervalStamped_end
{
public:
  explicit Init_IntervalStamped_end(::interval_analysis_interfaces::msg::IntervalStamped & msg)
  : msg_(msg)
  {}
  ::interval_analysis_interfaces::msg::IntervalStamped end(::interval_analysis_interfaces::msg::IntervalStamped::_end_type arg)
  {
    msg_.end = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::IntervalStamped msg_;
};

class Init_IntervalStamped_start
{
public:
  explicit Init_IntervalStamped_start(::interval_analysis_interfaces::msg::IntervalStamped & msg)
  : msg_(msg)
  {}
  Init_IntervalStamped_end start(::interval_analysis_interfaces::msg::IntervalStamped::_start_type arg)
  {
    msg_.start = std::move(arg);
    return Init_IntervalStamped_end(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::IntervalStamped msg_;
};

class Init_IntervalStamped_name
{
public:
  explicit Init_IntervalStamped_name(::interval_analysis_interfaces::msg::IntervalStamped & msg)
  : msg_(msg)
  {}
  Init_IntervalStamped_start name(::interval_analysis_interfaces::msg::IntervalStamped::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_IntervalStamped_start(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::IntervalStamped msg_;
};

class Init_IntervalStamped_header
{
public:
  Init_IntervalStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IntervalStamped_name header(::interval_analysis_interfaces::msg::IntervalStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_IntervalStamped_name(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::IntervalStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interval_analysis_interfaces::msg::IntervalStamped>()
{
  return interval_analysis_interfaces::msg::builder::Init_IntervalStamped_header();
}

}  // namespace interval_analysis_interfaces

#endif  // INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__INTERVAL_STAMPED__BUILDER_HPP_
