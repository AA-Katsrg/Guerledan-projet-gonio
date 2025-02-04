// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interval_analysis_interfaces:msg/TubeStamped.idl
// generated code does not contain a copyright notice

#ifndef INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__TUBE_STAMPED__TRAITS_HPP_
#define INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__TUBE_STAMPED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interval_analysis_interfaces/msg/detail/tube_stamped__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'boxes'
#include "interval_analysis_interfaces/msg/detail/box__traits.hpp"
// Member 't_domain'
#include "interval_analysis_interfaces/msg/detail/interval__traits.hpp"

namespace interval_analysis_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TubeStamped & msg,
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

  // member: boxes
  {
    if (msg.boxes.size() == 0) {
      out << "boxes: []";
    } else {
      out << "boxes: [";
      size_t pending_items = msg.boxes.size();
      for (auto item : msg.boxes) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: t_domain
  {
    out << "t_domain: ";
    to_flow_style_yaml(msg.t_domain, out);
    out << ", ";
  }

  // member: dt
  {
    out << "dt: ";
    rosidl_generator_traits::value_to_yaml(msg.dt, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TubeStamped & msg,
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

  // member: boxes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.boxes.size() == 0) {
      out << "boxes: []\n";
    } else {
      out << "boxes:\n";
      for (auto item : msg.boxes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: t_domain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "t_domain:\n";
    to_block_style_yaml(msg.t_domain, out, indentation + 2);
  }

  // member: dt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dt: ";
    rosidl_generator_traits::value_to_yaml(msg.dt, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TubeStamped & msg, bool use_flow_style = false)
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
  const interval_analysis_interfaces::msg::TubeStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  interval_analysis_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interval_analysis_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const interval_analysis_interfaces::msg::TubeStamped & msg)
{
  return interval_analysis_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<interval_analysis_interfaces::msg::TubeStamped>()
{
  return "interval_analysis_interfaces::msg::TubeStamped";
}

template<>
inline const char * name<interval_analysis_interfaces::msg::TubeStamped>()
{
  return "interval_analysis_interfaces/msg/TubeStamped";
}

template<>
struct has_fixed_size<interval_analysis_interfaces::msg::TubeStamped>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interval_analysis_interfaces::msg::TubeStamped>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interval_analysis_interfaces::msg::TubeStamped>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERVAL_ANALYSIS_INTERFACES__MSG__DETAIL__TUBE_STAMPED__TRAITS_HPP_
