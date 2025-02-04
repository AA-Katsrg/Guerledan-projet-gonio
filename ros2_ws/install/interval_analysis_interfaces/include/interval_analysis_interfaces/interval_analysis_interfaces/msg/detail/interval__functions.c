// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interval_analysis_interfaces:msg/Interval.idl
// generated code does not contain a copyright notice
#include "interval_analysis_interfaces/msg/detail/interval__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

bool
interval_analysis_interfaces__msg__Interval__init(interval_analysis_interfaces__msg__Interval * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    interval_analysis_interfaces__msg__Interval__fini(msg);
    return false;
  }
  // start
  // end
  return true;
}

void
interval_analysis_interfaces__msg__Interval__fini(interval_analysis_interfaces__msg__Interval * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // start
  // end
}

bool
interval_analysis_interfaces__msg__Interval__are_equal(const interval_analysis_interfaces__msg__Interval * lhs, const interval_analysis_interfaces__msg__Interval * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // start
  if (lhs->start != rhs->start) {
    return false;
  }
  // end
  if (lhs->end != rhs->end) {
    return false;
  }
  return true;
}

bool
interval_analysis_interfaces__msg__Interval__copy(
  const interval_analysis_interfaces__msg__Interval * input,
  interval_analysis_interfaces__msg__Interval * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // start
  output->start = input->start;
  // end
  output->end = input->end;
  return true;
}

interval_analysis_interfaces__msg__Interval *
interval_analysis_interfaces__msg__Interval__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interval_analysis_interfaces__msg__Interval * msg = (interval_analysis_interfaces__msg__Interval *)allocator.allocate(sizeof(interval_analysis_interfaces__msg__Interval), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interval_analysis_interfaces__msg__Interval));
  bool success = interval_analysis_interfaces__msg__Interval__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interval_analysis_interfaces__msg__Interval__destroy(interval_analysis_interfaces__msg__Interval * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interval_analysis_interfaces__msg__Interval__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interval_analysis_interfaces__msg__Interval__Sequence__init(interval_analysis_interfaces__msg__Interval__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interval_analysis_interfaces__msg__Interval * data = NULL;

  if (size) {
    data = (interval_analysis_interfaces__msg__Interval *)allocator.zero_allocate(size, sizeof(interval_analysis_interfaces__msg__Interval), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interval_analysis_interfaces__msg__Interval__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interval_analysis_interfaces__msg__Interval__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
interval_analysis_interfaces__msg__Interval__Sequence__fini(interval_analysis_interfaces__msg__Interval__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interval_analysis_interfaces__msg__Interval__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

interval_analysis_interfaces__msg__Interval__Sequence *
interval_analysis_interfaces__msg__Interval__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interval_analysis_interfaces__msg__Interval__Sequence * array = (interval_analysis_interfaces__msg__Interval__Sequence *)allocator.allocate(sizeof(interval_analysis_interfaces__msg__Interval__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interval_analysis_interfaces__msg__Interval__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interval_analysis_interfaces__msg__Interval__Sequence__destroy(interval_analysis_interfaces__msg__Interval__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interval_analysis_interfaces__msg__Interval__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interval_analysis_interfaces__msg__Interval__Sequence__are_equal(const interval_analysis_interfaces__msg__Interval__Sequence * lhs, const interval_analysis_interfaces__msg__Interval__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interval_analysis_interfaces__msg__Interval__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interval_analysis_interfaces__msg__Interval__Sequence__copy(
  const interval_analysis_interfaces__msg__Interval__Sequence * input,
  interval_analysis_interfaces__msg__Interval__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interval_analysis_interfaces__msg__Interval);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    interval_analysis_interfaces__msg__Interval * data =
      (interval_analysis_interfaces__msg__Interval *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interval_analysis_interfaces__msg__Interval__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          interval_analysis_interfaces__msg__Interval__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interval_analysis_interfaces__msg__Interval__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
