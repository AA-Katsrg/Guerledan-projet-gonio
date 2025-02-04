// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from interval_analysis_interfaces:msg/BoxListStamped.idl
// generated code does not contain a copyright notice

#ifndef INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX_LIST_STAMPED__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX_LIST_STAMPED__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "interval_analysis_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "interval_analysis_interfaces/msg/detail/box_list_stamped__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace interval_analysis_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interval_analysis_interfaces
cdr_serialize(
  const interval_analysis_interfaces::msg::BoxListStamped & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interval_analysis_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  interval_analysis_interfaces::msg::BoxListStamped & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interval_analysis_interfaces
get_serialized_size(
  const interval_analysis_interfaces::msg::BoxListStamped & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interval_analysis_interfaces
max_serialized_size_BoxListStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace interval_analysis_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interval_analysis_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interval_analysis_interfaces, msg, BoxListStamped)();

#ifdef __cplusplus
}
#endif

#endif  // INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX_LIST_STAMPED__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
