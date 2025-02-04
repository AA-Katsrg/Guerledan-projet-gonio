// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interval_analysis_interfaces:msg/IntervalStamped.idl
// generated code does not contain a copyright notice

#ifndef INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__INTERVAL_STAMPED__STRUCT_H_
#define INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__INTERVAL_STAMPED__STRUCT_H_

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

/// Struct defined in msg/IntervalStamped in the package interval_analysis_interfaces.
/**
  * Interval.msg
  * ROS2 message definition for interval analysis with a header for timestamp and frame reference
 */
typedef struct interval_analysis_interfaces__msg__IntervalStamped
{
  /// Standard header for timestamps and frame reference
  std_msgs__msg__Header header;
  /// Optionnal
  rosidl_runtime_c__String name;
  /// Start of the interval (e.g., time, range lower bound)
  double start;
  /// End of the interval (e.g., time, range upper bound)
  double end;
} interval_analysis_interfaces__msg__IntervalStamped;

// Struct for a sequence of interval_analysis_interfaces__msg__IntervalStamped.
typedef struct interval_analysis_interfaces__msg__IntervalStamped__Sequence
{
  interval_analysis_interfaces__msg__IntervalStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interval_analysis_interfaces__msg__IntervalStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__INTERVAL_STAMPED__STRUCT_H_
