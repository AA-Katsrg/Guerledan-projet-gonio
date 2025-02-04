// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interval_analysis_interfaces:msg/BoxListStamped.idl
// generated code does not contain a copyright notice

#ifndef INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX_LIST_STAMPED__BUILDER_HPP_
#define INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX_LIST_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interval_analysis_interfaces/msg/detail/box_list_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interval_analysis_interfaces
{

namespace msg
{

namespace builder
{

class Init_BoxListStamped_boxes
{
public:
  explicit Init_BoxListStamped_boxes(::interval_analysis_interfaces::msg::BoxListStamped & msg)
  : msg_(msg)
  {}
  ::interval_analysis_interfaces::msg::BoxListStamped boxes(::interval_analysis_interfaces::msg::BoxListStamped::_boxes_type arg)
  {
    msg_.boxes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::BoxListStamped msg_;
};

class Init_BoxListStamped_name
{
public:
  explicit Init_BoxListStamped_name(::interval_analysis_interfaces::msg::BoxListStamped & msg)
  : msg_(msg)
  {}
  Init_BoxListStamped_boxes name(::interval_analysis_interfaces::msg::BoxListStamped::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_BoxListStamped_boxes(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::BoxListStamped msg_;
};

class Init_BoxListStamped_header
{
public:
  Init_BoxListStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoxListStamped_name header(::interval_analysis_interfaces::msg::BoxListStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_BoxListStamped_name(msg_);
  }

private:
  ::interval_analysis_interfaces::msg::BoxListStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interval_analysis_interfaces::msg::BoxListStamped>()
{
  return interval_analysis_interfaces::msg::builder::Init_BoxListStamped_header();
}

}  // namespace interval_analysis_interfaces

#endif  // INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX_LIST_STAMPED__BUILDER_HPP_
