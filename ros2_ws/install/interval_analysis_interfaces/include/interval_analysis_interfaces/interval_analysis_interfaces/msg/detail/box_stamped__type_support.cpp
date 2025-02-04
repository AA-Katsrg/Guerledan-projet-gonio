// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from interval_analysis_interfaces:msg/BoxStamped.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "interval_analysis_interfaces/msg/detail/box_stamped__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace interval_analysis_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void BoxStamped_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) interval_analysis_interfaces::msg::BoxStamped(_init);
}

void BoxStamped_fini_function(void * message_memory)
{
  auto typed_message = static_cast<interval_analysis_interfaces::msg::BoxStamped *>(message_memory);
  typed_message->~BoxStamped();
}

size_t size_function__BoxStamped__intervals(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<interval_analysis_interfaces::msg::Interval> *>(untyped_member);
  return member->size();
}

const void * get_const_function__BoxStamped__intervals(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<interval_analysis_interfaces::msg::Interval> *>(untyped_member);
  return &member[index];
}

void * get_function__BoxStamped__intervals(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<interval_analysis_interfaces::msg::Interval> *>(untyped_member);
  return &member[index];
}

void fetch_function__BoxStamped__intervals(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const interval_analysis_interfaces::msg::Interval *>(
    get_const_function__BoxStamped__intervals(untyped_member, index));
  auto & value = *reinterpret_cast<interval_analysis_interfaces::msg::Interval *>(untyped_value);
  value = item;
}

void assign_function__BoxStamped__intervals(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<interval_analysis_interfaces::msg::Interval *>(
    get_function__BoxStamped__intervals(untyped_member, index));
  const auto & value = *reinterpret_cast<const interval_analysis_interfaces::msg::Interval *>(untyped_value);
  item = value;
}

void resize_function__BoxStamped__intervals(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<interval_analysis_interfaces::msg::Interval> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember BoxStamped_message_member_array[3] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interval_analysis_interfaces::msg::BoxStamped, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interval_analysis_interfaces::msg::BoxStamped, name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "intervals",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<interval_analysis_interfaces::msg::Interval>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interval_analysis_interfaces::msg::BoxStamped, intervals),  // bytes offset in struct
    nullptr,  // default value
    size_function__BoxStamped__intervals,  // size() function pointer
    get_const_function__BoxStamped__intervals,  // get_const(index) function pointer
    get_function__BoxStamped__intervals,  // get(index) function pointer
    fetch_function__BoxStamped__intervals,  // fetch(index, &value) function pointer
    assign_function__BoxStamped__intervals,  // assign(index, value) function pointer
    resize_function__BoxStamped__intervals  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers BoxStamped_message_members = {
  "interval_analysis_interfaces::msg",  // message namespace
  "BoxStamped",  // message name
  3,  // number of fields
  sizeof(interval_analysis_interfaces::msg::BoxStamped),
  BoxStamped_message_member_array,  // message members
  BoxStamped_init_function,  // function to initialize message memory (memory has to be allocated)
  BoxStamped_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t BoxStamped_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &BoxStamped_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace interval_analysis_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interval_analysis_interfaces::msg::BoxStamped>()
{
  return &::interval_analysis_interfaces::msg::rosidl_typesupport_introspection_cpp::BoxStamped_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interval_analysis_interfaces, msg, BoxStamped)() {
  return &::interval_analysis_interfaces::msg::rosidl_typesupport_introspection_cpp::BoxStamped_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
