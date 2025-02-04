// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interval_analysis_interfaces:msg/Tube.idl
// generated code does not contain a copyright notice

#ifndef INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__TUBE__BUILDER_HPP_
#define INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__TUBE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interval_analysis_interfaces/msg/detail/tube__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interval_analysis_interfaces
{

namespace msg
{

namespace builder
{

class Init_Tube_dt
{
public:
  explicit Init_Tube_dt(::interval_analysis_interfaces::msg::Tube & msg)
  : msg_(msg)
  {}
  ::interval_analysis_interfaces::msg::Tube dt(::interval_analysis_interfaces::msg::Tube::_dt_type arg)
  {
    msg_.dt = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::Tube msg_;
};

class Init_Tube_t_domain
{
public:
  explicit Init_Tube_t_domain(::interval_analysis_interfaces::msg::Tube & msg)
  : msg_(msg)
  {}
  Init_Tube_dt t_domain(::interval_analysis_interfaces::msg::Tube::_t_domain_type arg)
  {
    msg_.t_domain = std::move(arg);
    return Init_Tube_dt(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::Tube msg_;
};

class Init_Tube_boxes
{
public:
  explicit Init_Tube_boxes(::interval_analysis_interfaces::msg::Tube & msg)
  : msg_(msg)
  {}
  Init_Tube_t_domain boxes(::interval_analysis_interfaces::msg::Tube::_boxes_type arg)
  {
    msg_.boxes = std::move(arg);
    return Init_Tube_t_domain(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::Tube msg_;
};

class Init_Tube_name
{
public:
  Init_Tube_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Tube_boxes name(::interval_analysis_interfaces::msg::Tube::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Tube_boxes(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::Tube msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interval_analysis_interfaces::msg::Tube>()
{
  return interval_analysis_interfaces::msg::builder::Init_Tube_name();
}

}  // namespace interval_analysis_interfaces

#endif  // INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__TUBE__BUILDER_HPP_
