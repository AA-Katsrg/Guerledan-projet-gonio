// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interval_analysis_interfaces:msg/TubeStamped.idl
// generated code does not contain a copyright notice

#ifndef INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__TUBE_STAMPED__BUILDER_HPP_
#define INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__TUBE_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interval_analysis_interfaces/msg/detail/tube_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interval_analysis_interfaces
{

namespace msg
{

namespace builder
{

class Init_TubeStamped_dt
{
public:
  explicit Init_TubeStamped_dt(::interval_analysis_interfaces::msg::TubeStamped & msg)
  : msg_(msg)
  {}
  ::interval_analysis_interfaces::msg::TubeStamped dt(::interval_analysis_interfaces::msg::TubeStamped::_dt_type arg)
  {
    msg_.dt = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::TubeStamped msg_;
};

class Init_TubeStamped_t_domain
{
public:
  explicit Init_TubeStamped_t_domain(::interval_analysis_interfaces::msg::TubeStamped & msg)
  : msg_(msg)
  {}
  Init_TubeStamped_dt t_domain(::interval_analysis_interfaces::msg::TubeStamped::_t_domain_type arg)
  {
    msg_.t_domain = std::move(arg);
    return Init_TubeStamped_dt(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::TubeStamped msg_;
};

class Init_TubeStamped_boxes
{
public:
  explicit Init_TubeStamped_boxes(::interval_analysis_interfaces::msg::TubeStamped & msg)
  : msg_(msg)
  {}
  Init_TubeStamped_t_domain boxes(::interval_analysis_interfaces::msg::TubeStamped::_boxes_type arg)
  {
    msg_.boxes = std::move(arg);
    return Init_TubeStamped_t_domain(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::TubeStamped msg_;
};

class Init_TubeStamped_name
{
public:
  explicit Init_TubeStamped_name(::interval_analysis_interfaces::msg::TubeStamped & msg)
  : msg_(msg)
  {}
  Init_TubeStamped_boxes name(::interval_analysis_interfaces::msg::TubeStamped::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_TubeStamped_boxes(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::TubeStamped msg_;
};

class Init_TubeStamped_header
{
public:
  Init_TubeStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TubeStamped_name header(::interval_analysis_interfaces::msg::TubeStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TubeStamped_name(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::TubeStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interval_analysis_interfaces::msg::TubeStamped>()
{
  return interval_analysis_interfaces::msg::builder::Init_TubeStamped_header();
}

}  // namespace interval_analysis_interfaces

#endif  // INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__TUBE_STAMPED__BUILDER_HPP_
