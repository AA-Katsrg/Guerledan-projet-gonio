// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interval_analysis_interfaces:msg/BoxStamped.idl
// generated code does not contain a copyright notice

#ifndef INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX_STAMPED__STRUCT_H_
#define INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX_STAMPED__STRUCT_H_

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
// Member 'intervals'
#include "interval_analysis_interfaces/msg/detail/interval__struct.h"

/// Struct defined in msg/BoxStamped in the package interval_analysis_interfaces.
/**
  * Box.msg
  * ROS2 message definition for a box (Interval vector) represented by a list of intervals with a header for timestamp and frame reference
 */
typedef struct interval_analysis_interfaces__msg__BoxStamped
{
  /// Standard header for timestamps and frame reference
  std_msgs__msg__Header header;
  /// Optionnal
  rosidl_runtime_c__String name;
  /// List of intervals defining the box (e.g., spatial bounds, time intervals)
  interval_analysis_interfaces__msg__Interval__Sequence intervals;
} interval_analysis_interfaces__msg__BoxStamped;

// Struct for a sequence of interval_analysis_interfaces__msg__BoxStamped.
typedef struct interval_analysis_interfaces__msg__BoxStamped__Sequence
{
  interval_analysis_interfaces__msg__BoxStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interval_analysis_interfaces__msg__BoxStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX_STAMPED__STRUCT_H_
