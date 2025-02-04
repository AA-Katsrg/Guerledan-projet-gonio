// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interval_analysis_interfaces:msg/TubeStamped.idl
// generated code does not contain a copyright notice

#ifndef INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__TUBE_STAMPED__STRUCT_H_
#define INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__TUBE_STAMPED__STRUCT_H_

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
// Member 't_domain'
#include "interval_analysis_interfaces/msg/detail/interval__struct.h"

/// Struct defined in msg/TubeStamped in the package interval_analysis_interfaces.
/**
  * TubeStamped.msg
  * ROS2 message definition for a collection of boxes with temporal metadata, with a header for timestamp and frame reference
 */
typedef struct interval_analysis_interfaces__msg__TubeStamped
{
  /// Standard header for timestamps and frame reference
  std_msgs__msg__Header header;
  /// Optionnal
  rosidl_runtime_c__String name;
  /// List of boxes
  interval_analysis_interfaces__msg__Box__Sequence boxes;
  /// Time domain start and end (e.g., for time-series or interval analysis)
  interval_analysis_interfaces__msg__Interval t_domain;
  /// Time step or interval duration
  double dt;
} interval_analysis_interfaces__msg__TubeStamped;

// Struct for a sequence of interval_analysis_interfaces__msg__TubeStamped.
typedef struct interval_analysis_interfaces__msg__TubeStamped__Sequence
{
  interval_analysis_interfaces__msg__TubeStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interval_analysis_interfaces__msg__TubeStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__TUBE_STAMPED__STRUCT_H_
