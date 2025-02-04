// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from interval_analysis_interfaces:msg/Tube.idl
// generated code does not contain a copyright notice

#ifndef INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__TUBE__FUNCTIONS_H_
#define INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__TUBE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "interval_analysis_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "interval_analysis_interfaces/msg/detail/tube__struct.h"

/// Initialize msg/Tube message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * interval_analysis_interfaces__msg__Tube
 * )) before or use
 * interval_analysis_interfaces__msg__Tube__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
bool
interval_analysis_interfaces__msg__Tube__init(interval_analysis_interfaces__msg__Tube * msg);

/// Finalize msg/Tube message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
void
interval_analysis_interfaces__msg__Tube__fini(interval_analysis_interfaces__msg__Tube * msg);

/// Create msg/Tube message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * interval_analysis_interfaces__msg__Tube__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
interval_analysis_interfaces__msg__Tube *
interval_analysis_interfaces__msg__Tube__create();

/// Destroy msg/Tube message.
/**
 * It calls
 * interval_analysis_interfaces__msg__Tube__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
void
interval_analysis_interfaces__msg__Tube__destroy(interval_analysis_interfaces__msg__Tube * msg);

/// Check for msg/Tube message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
bool
interval_analysis_interfaces__msg__Tube__are_equal(const interval_analysis_interfaces__msg__Tube * lhs, const interval_analysis_interfaces__msg__Tube * rhs);

/// Copy a msg/Tube message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
bool
interval_analysis_interfaces__msg__Tube__copy(
  const interval_analysis_interfaces__msg__Tube * input,
  interval_analysis_interfaces__msg__Tube * output);

/// Initialize array of msg/Tube messages.
/**
 * It allocates the memory for the number of elements and calls
 * interval_analysis_interfaces__msg__Tube__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
bool
interval_analysis_interfaces__msg__Tube__Sequence__init(interval_analysis_interfaces__msg__Tube__Sequence * array, size_t size);

/// Finalize array of msg/Tube messages.
/**
 * It calls
 * interval_analysis_interfaces__msg__Tube__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
void
interval_analysis_interfaces__msg__Tube__Sequence__fini(interval_analysis_interfaces__msg__Tube__Sequence * array);

/// Create array of msg/Tube messages.
/**
 * It allocates the memory for the array and calls
 * interval_analysis_interfaces__msg__Tube__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
interval_analysis_interfaces__msg__Tube__Sequence *
interval_analysis_interfaces__msg__Tube__Sequence__create(size_t size);

/// Destroy array of msg/Tube messages.
/**
 * It calls
 * interval_analysis_interfaces__msg__Tube__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
void
interval_analysis_interfaces__msg__Tube__Sequence__destroy(interval_analysis_interfaces__msg__Tube__Sequence * array);

/// Check for msg/Tube message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
bool
interval_analysis_interfaces__msg__Tube__Sequence__are_equal(const interval_analysis_interfaces__msg__Tube__Sequence * lhs, const interval_analysis_interfaces__msg__Tube__Sequence * rhs);

/// Copy an array of msg/Tube messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
bool
interval_analysis_interfaces__msg__Tube__Sequence__copy(
  const interval_analysis_interfaces__msg__Tube__Sequence * input,
  interval_analysis_interfaces__msg__Tube__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__TUBE__FUNCTIONS_H_
