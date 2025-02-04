// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from interval_analysis_interfaces:msg/Tube.idl
// generated code does not contain a copyright notice
#include "interval_analysis_interfaces/msg/detail/tube__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "interval_analysis_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "interval_analysis_interfaces/msg/detail/tube__struct.h"
#include "interval_analysis_interfaces/msg/detail/tube__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "interval_analysis_interfaces/msg/detail/box__functions.h"  // boxes
#include "interval_analysis_interfaces/msg/detail/interval__functions.h"  // t_domain
#include "rosidl_runtime_c/string.h"  // name
#include "rosidl_runtime_c/string_functions.h"  // name

// forward declare type support functions
size_t get_serialized_size_interval_analysis_interfaces__msg__Box(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_interval_analysis_interfaces__msg__Box(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interval_analysis_interfaces, msg, Box)();
size_t get_serialized_size_interval_analysis_interfaces__msg__Interval(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_interval_analysis_interfaces__msg__Interval(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interval_analysis_interfaces, msg, Interval)();


using _Tube__ros_msg_type = interval_analysis_interfaces__msg__Tube;

static bool _Tube__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Tube__ros_msg_type * ros_message = static_cast<const _Tube__ros_msg_type *>(untyped_ros_message);
  // Field name: name
  {
    const rosidl_runtime_c__String * str = &ros_message->name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: boxes
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, interval_analysis_interfaces, msg, Box
      )()->data);
    size_t size = ros_message->boxes.size;
    auto array_ptr = ros_message->boxes.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: t_domain
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, interval_analysis_interfaces, msg, Interval
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->t_domain, cdr))
    {
      return false;
    }
  }

  // Field name: dt
  {
    cdr << ros_message->dt;
  }

  return true;
}

static bool _Tube__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Tube__ros_msg_type * ros_message = static_cast<_Tube__ros_msg_type *>(untyped_ros_message);
  // Field name: name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->name.data) {
      rosidl_runtime_c__String__init(&ros_message->name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'name'\n");
      return false;
    }
  }

  // Field name: boxes
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, interval_analysis_interfaces, msg, Box
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->boxes.data) {
      interval_analysis_interfaces__msg__Box__Sequence__fini(&ros_message->boxes);
    }
    if (!interval_analysis_interfaces__msg__Box__Sequence__init(&ros_message->boxes, size)) {
      fprintf(stderr, "failed to create array for field 'boxes'");
      return false;
    }
    auto array_ptr = ros_message->boxes.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: t_domain
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, interval_analysis_interfaces, msg, Interval
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->t_domain))
    {
      return false;
    }
  }

  // Field name: dt
  {
    cdr >> ros_message->dt;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interval_analysis_interfaces
size_t get_serialized_size_interval_analysis_interfaces__msg__Tube(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Tube__ros_msg_type * ros_message = static_cast<const _Tube__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name.size + 1);
  // field.name boxes
  {
    size_t array_size = ros_message->boxes.size;
    auto array_ptr = ros_message->boxes.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_interval_analysis_interfaces__msg__Box(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name t_domain

  current_alignment += get_serialized_size_interval_analysis_interfaces__msg__Interval(
    &(ros_message->t_domain), current_alignment);
  // field.name dt
  {
    size_t item_size = sizeof(ros_message->dt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Tube__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_interval_analysis_interfaces__msg__Tube(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interval_analysis_interfaces
size_t max_serialized_size_interval_analysis_interfaces__msg__Tube(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: boxes
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_interval_analysis_interfaces__msg__Box(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: t_domain
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_interval_analysis_interfaces__msg__Interval(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: dt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = interval_analysis_interfaces__msg__Tube;
    is_plain =
      (
      offsetof(DataType, dt) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Tube__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_interval_analysis_interfaces__msg__Tube(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Tube = {
  "interval_analysis_interfaces::msg",
  "Tube",
  _Tube__cdr_serialize,
  _Tube__cdr_deserialize,
  _Tube__get_serialized_size,
  _Tube__max_serialized_size
};

static rosidl_message_type_support_t _Tube__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Tube,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interval_analysis_interfaces, msg, Tube)() {
  return &_Tube__type_support;
}

#if defined(__cplusplus)
}
#endif
