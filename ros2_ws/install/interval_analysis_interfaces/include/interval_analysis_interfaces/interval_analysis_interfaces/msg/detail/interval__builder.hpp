// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interval_analysis_interfaces:msg/Interval.idl
// generated code does not contain a copyright notice

#ifndef INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__INTERVAL__BUILDER_HPP_
#define INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__INTERVAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interval_analysis_interfaces/msg/detail/interval__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interval_analysis_interfaces
{

namespace msg
{

namespace builder
{

class Init_Interval_end
{
public:
  explicit Init_Interval_end(::interval_analysis_interfaces::msg::Interval & msg)
  : msg_(msg)
  {}
  ::interval_analysis_interfaces::msg::Interval end(::interval_analysis_interfaces::msg::Interval::_end_type arg)
  {
    msg_.end = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::Interval msg_;
};

class Init_Interval_start
{
public:
  explicit Init_Interval_start(::interval_analysis_interfaces::msg::Interval & msg)
  : msg_(msg)
  {}
  Init_Interval_end start(::interval_analysis_interfaces::msg::Interval::_start_type arg)
  {
    msg_.start = std::move(arg);
    return Init_Interval_end(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::Interval msg_;
};

class Init_Interval_name
{
public:
  Init_Interval_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Interval_start name(::interval_analysis_interfaces::msg::Interval::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Interval_start(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::Interval msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interval_analysis_interfaces::msg::Interval>()
{
  return interval_analysis_interfaces::msg::builder::Init_Interval_name();
}

}  // namespace interval_analysis_interfaces

#endif  // INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__INTERVAL__BUILDER_HPP_
