// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from interval_analysis_interfaces:msg/TubeStamped.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "interval_analysis_interfaces/msg/detail/tube_stamped__struct.hpp"
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

void TubeStamped_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) interval_analysis_interfaces::msg::TubeStamped(_init);
}

void TubeStamped_fini_function(void * message_memory)
{
  auto typed_message = static_cast<interval_analysis_interfaces::msg::TubeStamped *>(message_memory);
  typed_message->~TubeStamped();
}

size_t size_function__TubeStamped__boxes(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<interval_analysis_interfaces::msg::Box> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TubeStamped__boxes(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<interval_analysis_interfaces::msg::Box> *>(untyped_member);
  return &member[index];
}

void * get_function__TubeStamped__boxes(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<interval_analysis_interfaces::msg::Box> *>(untyped_member);
  return &member[index];
}

void fetch_function__TubeStamped__boxes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const interval_analysis_interfaces::msg::Box *>(
    get_const_function__TubeStamped__boxes(untyped_member, index));
  auto & value = *reinterpret_cast<interval_analysis_interfaces::msg::Box *>(untyped_value);
  value = item;
}

void assign_function__TubeStamped__boxes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<interval_analysis_interfaces::msg::Box *>(
    get_function__TubeStamped__boxes(untyped_member, index));
  const auto & value = *reinterpret_cast<const interval_analysis_interfaces::msg::Box *>(untyped_value);
  item = value;
}

void resize_function__TubeStamped__boxes(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<interval_analysis_interfaces::msg::Box> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TubeStamped_message_member_array[5] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interval_analysis_interfaces::msg::TubeStamped, header),  // bytes offset in struct
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
    offsetof(interval_analysis_interfaces::msg::TubeStamped, name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "boxes",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<interval_analysis_interfaces::msg::Box>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interval_analysis_interfaces::msg::TubeStamped, boxes),  // bytes offset in struct
    nullptr,  // default value
    size_function__TubeStamped__boxes,  // size() function pointer
    get_const_function__TubeStamped__boxes,  // get_const(index) function pointer
    get_function__TubeStamped__boxes,  // get(index) function pointer
    fetch_function__TubeStamped__boxes,  // fetch(index, &value) function pointer
    assign_function__TubeStamped__boxes,  // assign(index, value) function pointer
    resize_function__TubeStamped__boxes  // resize(index) function pointer
  },
  {
    "t_domain",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<interval_analysis_interfaces::msg::Interval>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interval_analysis_interfaces::msg::TubeStamped, t_domain),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "dt",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interval_analysis_interfaces::msg::TubeStamped, dt),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TubeStamped_message_members = {
  "interval_analysis_interfaces::msg",  // message namespace
  "TubeStamped",  // message name
  5,  // number of fields
  sizeof(interval_analysis_interfaces::msg::TubeStamped),
  TubeStamped_message_member_array,  // message members
  TubeStamped_init_function,  // function to initialize message memory (memory has to be allocated)
  TubeStamped_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TubeStamped_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TubeStamped_message_members,
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
get_message_type_support_handle<interval_analysis_interfaces::msg::TubeStamped>()
{
  return &::interval_analysis_interfaces::msg::rosidl_typesupport_introspection_cpp::TubeStamped_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interval_analysis_interfaces, msg, TubeStamped)() {
  return &::interval_analysis_interfaces::msg::rosidl_typesupport_introspection_cpp::TubeStamped_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
