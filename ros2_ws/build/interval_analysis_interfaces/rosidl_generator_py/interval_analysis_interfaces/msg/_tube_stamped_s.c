// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from interval_analysis_interfaces:msg/TubeStamped.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "interval_analysis_interfaces/msg/detail/tube_stamped__struct.h"
#include "interval_analysis_interfaces/msg/detail/tube_stamped__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "interval_analysis_interfaces/msg/detail/box__functions.h"
// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
bool interval_analysis_interfaces__msg__box__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * interval_analysis_interfaces__msg__box__convert_to_py(void * raw_ros_message);
bool interval_analysis_interfaces__msg__interval__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * interval_analysis_interfaces__msg__interval__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool interval_analysis_interfaces__msg__tube_stamped__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[59];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("interval_analysis_interfaces.msg._tube_stamped.TubeStamped", full_classname_dest, 58) == 0);
  }
  interval_analysis_interfaces__msg__TubeStamped * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // name
    PyObject * field = PyObject_GetAttrString(_pymsg, "name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // boxes
    PyObject * field = PyObject_GetAttrString(_pymsg, "boxes");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'boxes'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!interval_analysis_interfaces__msg__Box__Sequence__init(&(ros_message->boxes), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create interval_analysis_interfaces__msg__Box__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    interval_analysis_interfaces__msg__Box * dest = ros_message->boxes.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!interval_analysis_interfaces__msg__box__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // t_domain
    PyObject * field = PyObject_GetAttrString(_pymsg, "t_domain");
    if (!field) {
      return false;
    }
    if (!interval_analysis_interfaces__msg__interval__convert_from_py(field, &ros_message->t_domain)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // dt
    PyObject * field = PyObject_GetAttrString(_pymsg, "dt");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->dt = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * interval_analysis_interfaces__msg__tube_stamped__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of TubeStamped */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("interval_analysis_interfaces.msg._tube_stamped");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "TubeStamped");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  interval_analysis_interfaces__msg__TubeStamped * ros_message = (interval_analysis_interfaces__msg__TubeStamped *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->name.data,
      strlen(ros_message->name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // boxes
    PyObject * field = NULL;
    size_t size = ros_message->boxes.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    interval_analysis_interfaces__msg__Box * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->boxes.data[i]);
      PyObject * pyitem = interval_analysis_interfaces__msg__box__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "boxes", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // t_domain
    PyObject * field = NULL;
    field = interval_analysis_interfaces__msg__interval__convert_to_py(&ros_message->t_domain);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "t_domain", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dt
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->dt);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dt", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
