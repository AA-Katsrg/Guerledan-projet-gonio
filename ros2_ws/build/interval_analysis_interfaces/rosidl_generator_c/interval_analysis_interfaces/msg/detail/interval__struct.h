// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interval_analysis_interfaces:msg/Interval.idl
// generated code does not contain a copyright notice

#ifndef INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__INTERVAL__STRUCT_H_
#define INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__INTERVAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Interval in the package interval_analysis_interfaces.
/**
  * Interval.msg
  * ROS2 message definition for interval analysis without a header for timestamp and frame reference
 */
typedef struct interval_analysis_interfaces__msg__Interval
{
  /// Optionnal
  rosidl_runtime_c__String name;
  /// Start of the interval (e.g., time, range lower bound)
  double start;
  /// End of the interval (e.g., time, range upper bound)
  double end;
} interval_analysis_interfaces__msg__Interval;

// Struct for a sequence of interval_analysis_interfaces__msg__Interval.
typedef struct interval_analysis_interfaces__msg__Interval__Sequence
{
  interval_analysis_interfaces__msg__Interval * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interval_analysis_interfaces__msg__Interval__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__INTERVAL__STRUCT_H_
