// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from interval_analysis_interfaces:msg/Tube.idl
// generated code does not contain a copyright notice
#include "interval_analysis_interfaces/msg/detail/tube__rosidl_typesupport_fastrtps_cpp.hpp"
#include "interval_analysis_interfaces/msg/detail/tube__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace interval_analysis_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const interval_analysis_interfaces::msg::Box &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  interval_analysis_interfaces::msg::Box &);
size_t get_serialized_size(
  const interval_analysis_interfaces::msg::Box &,
  size_t current_alignment);
size_t
max_serialized_size_Box(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace interval_analysis_interfaces

namespace interval_analysis_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const interval_analysis_interfaces::msg::Interval &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  interval_analysis_interfaces::msg::Interval &);
size_t get_serialized_size(
  const interval_analysis_interfaces::msg::Interval &,
  size_t current_alignment);
size_t
max_serialized_size_Interval(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace interval_analysis_interfaces


namespace interval_analysis_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interval_analysis_interfaces
cdr_serialize(
  const interval_analysis_interfaces::msg::Tube & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: name
  cdr << ros_message.name;
  // Member: boxes
  {
    size_t size = ros_message.boxes.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      interval_analysis_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.boxes[i],
        cdr);
    }
  }
  // Member: t_domain
  interval_analysis_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.t_domain,
    cdr);
  // Member: dt
  cdr << ros_message.dt;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interval_analysis_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  interval_analysis_interfaces::msg::Tube & ros_message)
{
  // Member: name
  cdr >> ros_message.name;

  // Member: boxes
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.boxes.resize(size);
    for (size_t i = 0; i < size; i++) {
      interval_analysis_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.boxes[i]);
    }
  }

  // Member: t_domain
  interval_analysis_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.t_domain);

  // Member: dt
  cdr >> ros_message.dt;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interval_analysis_interfaces
get_serialized_size(
  const interval_analysis_interfaces::msg::Tube & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.name.size() + 1);
  // Member: boxes
  {
    size_t array_size = ros_message.boxes.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        interval_analysis_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.boxes[index], current_alignment);
    }
  }
  // Member: t_domain

  current_alignment +=
    interval_analysis_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.t_domain, current_alignment);
  // Member: dt
  {
    size_t item_size = sizeof(ros_message.dt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interval_analysis_interfaces
max_serialized_size_Tube(
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


  // Member: name
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

  // Member: boxes
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
      size_t inner_size =
        interval_analysis_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_Box(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: t_domain
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        interval_analysis_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_Interval(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: dt
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
    using DataType = interval_analysis_interfaces::msg::Tube;
    is_plain =
      (
      offsetof(DataType, dt) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Tube__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const interval_analysis_interfaces::msg::Tube *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Tube__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<interval_analysis_interfaces::msg::Tube *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Tube__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const interval_analysis_interfaces::msg::Tube *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Tube__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Tube(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Tube__callbacks = {
  "interval_analysis_interfaces::msg",
  "Tube",
  _Tube__cdr_serialize,
  _Tube__cdr_deserialize,
  _Tube__get_serialized_size,
  _Tube__max_serialized_size
};

static rosidl_message_type_support_t _Tube__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Tube__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace interval_analysis_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_interval_analysis_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<interval_analysis_interfaces::msg::Tube>()
{
  return &interval_analysis_interfaces::msg::typesupport_fastrtps_cpp::_Tube__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interval_analysis_interfaces, msg, Tube)() {
  return &interval_analysis_interfaces::msg::typesupport_fastrtps_cpp::_Tube__handle;
}

#ifdef __cplusplus
}
#endif
