// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interval_analysis_interfaces:msg/BoxListStamped.idl
// generated code does not contain a copyright notice

#ifndef INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX_LIST_STAMPED__STRUCT_H_
#define INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX_LIST_STAMPED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'name'
#include "rosidl_runtime_c/string.h"
// Member 'boxes'
#include "interval_analysis_interfaces/msg/detail/box__struct.h"

/// Struct defined in msg/BoxListStamped in the package interval_analysis_interfaces.
/**
  * BoxStampedList.msg
  * ROS2 message definition for a list of box (Interval vector)
 */
typedef struct interval_analysis_interfaces__msg__BoxListStamped
{
  /// Standard header for timestamps and frame reference
  std_msgs__msg__Header header;
  rosidl_runtime_c__String name;
  /// List of boxes
  interval_analysis_interfaces__msg__Box__Sequence boxes;
} interval_analysis_interfaces__msg__BoxListStamped;

// Struct for a sequence of interval_analysis_interfaces__msg__BoxListStamped.
typedef struct interval_analysis_interfaces__msg__BoxListStamped__Sequence
{
  interval_analysis_interfaces__msg__BoxListStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interval_analysis_interfaces__msg__BoxListStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX_LIST_STAMPED__STRUCT_H_
