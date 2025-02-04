// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interval_analysis_interfaces:msg/Box.idl
// generated code does not contain a copyright notice

#ifndef INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX__STRUCT_H_
#define INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX__STRUCT_H_

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
// Member 'intervals'
#include "interval_analysis_interfaces/msg/detail/interval__struct.h"

/// Struct defined in msg/Box in the package interval_analysis_interfaces.
/**
  * Box.msg
  * ROS2 message definition for a box (Interval vector) represented by a list of intervals without a header for timestamp and frame reference
 */
typedef struct interval_analysis_interfaces__msg__Box
{
  /// Optionnal
  rosidl_runtime_c__String name;
  /// List of intervals defining the box (e.g., spatial bounds, time intervals)
  interval_analysis_interfaces__msg__Interval__Sequence intervals;
} interval_analysis_interfaces__msg__Box;

// Struct for a sequence of interval_analysis_interfaces__msg__Box.
typedef struct interval_analysis_interfaces__msg__Box__Sequence
{
  interval_analysis_interfaces__msg__Box * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interval_analysis_interfaces__msg__Box__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX__STRUCT_H_
