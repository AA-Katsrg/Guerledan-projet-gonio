// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interval_analysis_interfaces:msg/IntervalStamped.idl
// generated code does not contain a copyright notice

#ifndef INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__INTERVAL_STAMPED__TRAITS_HPP_
#define INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__INTERVAL_STAMPED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interval_analysis_interfaces/msg/detail/interval_stamped__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace interval_analysis_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const IntervalStamped & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: start
  {
    out << "start: ";
    rosidl_generator_traits::value_to_yaml(msg.start, out);
    out << ", ";
  }

  // member: end
  {
    out << "end: ";
    rosidl_generator_traits::value_to_yaml(msg.end, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const IntervalStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start: ";
    rosidl_generator_traits::value_to_yaml(msg.start, out);
    out << "\n";
  }

  // member: end
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "end: ";
    rosidl_generator_traits::value_to_yaml(msg.end, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const IntervalStamped & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace interval_analysis_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interval_analysis_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interval_analysis_interfaces::msg::IntervalStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  interval_analysis_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interval_analysis_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const interval_analysis_interfaces::msg::IntervalStamped & msg)
{
  return interval_analysis_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<interval_analysis_interfaces::msg::IntervalStamped>()
{
  return "interval_analysis_interfaces::msg::IntervalStamped";
}

template<>
inline const char * name<interval_analysis_interfaces::msg::IntervalStamped>()
{
  return "interval_analysis_interfaces/msg/IntervalStamped";
}

template<>
struct has_fixed_size<interval_analysis_interfaces::msg::IntervalStamped>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interval_analysis_interfaces::msg::IntervalStamped>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interval_analysis_interfaces::msg::IntervalStamped>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__INTERVAL_STAMPED__TRAITS_HPP_
