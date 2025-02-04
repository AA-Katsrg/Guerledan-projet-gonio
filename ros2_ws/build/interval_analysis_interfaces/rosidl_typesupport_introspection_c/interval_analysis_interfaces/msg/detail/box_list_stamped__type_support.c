// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from interval_analysis_interfaces:msg/BoxListStamped.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "interval_analysis_interfaces/msg/detail/box_list_stamped__rosidl_typesupport_introspection_c.h"
#include "interval_analysis_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "interval_analysis_interfaces/msg/detail/box_list_stamped__functions.h"
#include "interval_analysis_interfaces/msg/detail/box_list_stamped__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `boxes`
#include "interval_analysis_interfaces/msg/box.h"
// Member `boxes`
#include "interval_analysis_interfaces/msg/detail/box__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__BoxListStamped_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  interval_analysis_interfaces__msg__BoxListStamped__init(message_memory);
}

void interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__BoxListStamped_fini_function(void * message_memory)
{
  interval_analysis_interfaces__msg__BoxListStamped__fini(message_memory);
}

size_t interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__size_function__BoxListStamped__boxes(
  const void * untyped_member)
{
  const interval_analysis_interfaces__msg__Box__Sequence * member =
    (const interval_analysis_interfaces__msg__Box__Sequence *)(untyped_member);
  return member->size;
}

const void * interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__get_const_function__BoxListStamped__boxes(
  const void * untyped_member, size_t index)
{
  const interval_analysis_interfaces__msg__Box__Sequence * member =
    (const interval_analysis_interfaces__msg__Box__Sequence *)(untyped_member);
  return &member->data[index];
}

void * interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__get_function__BoxListStamped__boxes(
  void * untyped_member, size_t index)
{
  interval_analysis_interfaces__msg__Box__Sequence * member =
    (interval_analysis_interfaces__msg__Box__Sequence *)(untyped_member);
  return &member->data[index];
}

void interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__fetch_function__BoxListStamped__boxes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const interval_analysis_interfaces__msg__Box * item =
    ((const interval_analysis_interfaces__msg__Box *)
    interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__get_const_function__BoxListStamped__boxes(untyped_member, index));
  interval_analysis_interfaces__msg__Box * value =
    (interval_analysis_interfaces__msg__Box *)(untyped_value);
  *value = *item;
}

void interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__assign_function__BoxListStamped__boxes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  interval_analysis_interfaces__msg__Box * item =
    ((interval_analysis_interfaces__msg__Box *)
    interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__get_function__BoxListStamped__boxes(untyped_member, index));
  const interval_analysis_interfaces__msg__Box * value =
    (const interval_analysis_interfaces__msg__Box *)(untyped_value);
  *item = *value;
}

bool interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__resize_function__BoxListStamped__boxes(
  void * untyped_member, size_t size)
{
  interval_analysis_interfaces__msg__Box__Sequence * member =
    (interval_analysis_interfaces__msg__Box__Sequence *)(untyped_member);
  interval_analysis_interfaces__msg__Box__Sequence__fini(member);
  return interval_analysis_interfaces__msg__Box__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__BoxListStamped_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interval_analysis_interfaces__msg__BoxListStamped, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interval_analysis_interfaces__msg__BoxListStamped, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "boxes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interval_analysis_interfaces__msg__BoxListStamped, boxes),  // bytes offset in struct
    NULL,  // default value
    interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__size_function__BoxListStamped__boxes,  // size() function pointer
    interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__get_const_function__BoxListStamped__boxes,  // get_const(index) function pointer
    interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__get_function__BoxListStamped__boxes,  // get(index) function pointer
    interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__fetch_function__BoxListStamped__boxes,  // fetch(index, &value) function pointer
    interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__assign_function__BoxListStamped__boxes,  // assign(index, value) function pointer
    interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__resize_function__BoxListStamped__boxes  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__BoxListStamped_message_members = {
  "interval_analysis_interfaces__msg",  // message namespace
  "BoxListStamped",  // message name
  3,  // number of fields
  sizeof(interval_analysis_interfaces__msg__BoxListStamped),
  interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__BoxListStamped_message_member_array,  // message members
  interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__BoxListStamped_init_function,  // function to initialize message memory (memory has to be allocated)
  interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__BoxListStamped_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__BoxListStamped_message_type_support_handle = {
  0,
  &interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__BoxListStamped_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_interval_analysis_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interval_analysis_interfaces, msg, BoxListStamped)() {
  interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__BoxListStamped_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__BoxListStamped_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interval_analysis_interfaces, msg, Box)();
  if (!interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__BoxListStamped_message_type_support_handle.typesupport_identifier) {
    interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__BoxListStamped_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &interval_analysis_interfaces__msg__BoxListStamped__rosidl_typesupport_introspection_c__BoxListStamped_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
