// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from interval_analysis_interfaces:msg/BoxStamped.idl
// generated code does not contain a copyright notice

#ifndef INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX_STAMPED__FUNCTIONS_H_
#define INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX_STAMPED__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "interval_analysis_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "interval_analysis_interfaces/msg/detail/box_stamped__struct.h"

/// Initialize msg/BoxStamped message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * interval_analysis_interfaces__msg__BoxStamped
 * )) before or use
 * interval_analysis_interfaces__msg__BoxStamped__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
bool
interval_analysis_interfaces__msg__BoxStamped__init(interval_analysis_interfaces__msg__BoxStamped * msg);

/// Finalize msg/BoxStamped message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
void
interval_analysis_interfaces__msg__BoxStamped__fini(interval_analysis_interfaces__msg__BoxStamped * msg);

/// Create msg/BoxStamped message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * interval_analysis_interfaces__msg__BoxStamped__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
interval_analysis_interfaces__msg__BoxStamped *
interval_analysis_interfaces__msg__BoxStamped__create();

/// Destroy msg/BoxStamped message.
/**
 * It calls
 * interval_analysis_interfaces__msg__BoxStamped__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
void
interval_analysis_interfaces__msg__BoxStamped__destroy(interval_analysis_interfaces__msg__BoxStamped * msg);

/// Check for msg/BoxStamped message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
bool
interval_analysis_interfaces__msg__BoxStamped__are_equal(const interval_analysis_interfaces__msg__BoxStamped * lhs, const interval_analysis_interfaces__msg__BoxStamped * rhs);

/// Copy a msg/BoxStamped message.
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
interval_analysis_interfaces__msg__BoxStamped__copy(
  const interval_analysis_interfaces__msg__BoxStamped * input,
  interval_analysis_interfaces__msg__BoxStamped * output);

/// Initialize array of msg/BoxStamped messages.
/**
 * It allocates the memory for the number of elements and calls
 * interval_analysis_interfaces__msg__BoxStamped__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
bool
interval_analysis_interfaces__msg__BoxStamped__Sequence__init(interval_analysis_interfaces__msg__BoxStamped__Sequence * array, size_t size);

/// Finalize array of msg/BoxStamped messages.
/**
 * It calls
 * interval_analysis_interfaces__msg__BoxStamped__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
void
interval_analysis_interfaces__msg__BoxStamped__Sequence__fini(interval_analysis_interfaces__msg__BoxStamped__Sequence * array);

/// Create array of msg/BoxStamped messages.
/**
 * It allocates the memory for the array and calls
 * interval_analysis_interfaces__msg__BoxStamped__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
interval_analysis_interfaces__msg__BoxStamped__Sequence *
interval_analysis_interfaces__msg__BoxStamped__Sequence__create(size_t size);

/// Destroy array of msg/BoxStamped messages.
/**
 * It calls
 * interval_analysis_interfaces__msg__BoxStamped__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
void
interval_analysis_interfaces__msg__BoxStamped__Sequence__destroy(interval_analysis_interfaces__msg__BoxStamped__Sequence * array);

/// Check for msg/BoxStamped message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interval_analysis_interfaces
bool
interval_analysis_interfaces__msg__BoxStamped__Sequence__are_equal(const interval_analysis_interfaces__msg__BoxStamped__Sequence * lhs, const interval_analysis_interfaces__msg__BoxStamped__Sequence * rhs);

/// Copy an array of msg/BoxStamped messages.
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
interval_analysis_interfaces__msg__BoxStamped__Sequence__copy(
  const interval_analysis_interfaces__msg__BoxStamped__Sequence * input,
  interval_analysis_interfaces__msg__BoxStamped__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__BOX_STAMPED__FUNCTIONS_H_
