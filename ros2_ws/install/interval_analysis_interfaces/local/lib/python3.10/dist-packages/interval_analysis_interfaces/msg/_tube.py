# generated from rosidl_generator_py/resource/_idl.py.em
# with input from interval_analysis_interfaces:msg/Tube.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Tube(type):
    """Metaclass of message 'Tube'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('interval_analysis_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'interval_analysis_interfaces.msg.Tube')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__tube
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__tube
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__tube
            cls._TYPE_SUPPORT = module.type_support_msg__msg__tube
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__tube

            from interval_analysis_interfaces.msg import Box
            if Box.__class__._TYPE_SUPPORT is None:
                Box.__class__.__import_type_support__()

            from interval_analysis_interfaces.msg import Interval
            if Interval.__class__._TYPE_SUPPORT is None:
                Interval.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Tube(metaclass=Metaclass_Tube):
    """Message class 'Tube'."""

    __slots__ = [
        '_name',
        '_boxes',
        '_t_domain',
        '_dt',
    ]

    _fields_and_field_types = {
        'name': 'string',
        'boxes': 'sequence<interval_analysis_interfaces/Box>',
        't_domain': 'interval_analysis_interfaces/Interval',
        'dt': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['interval_analysis_interfaces', 'msg'], 'Box')),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['interval_analysis_interfaces', 'msg'], 'Interval'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.name = kwargs.get('name', str())
        self.boxes = kwargs.get('boxes', [])
        from interval_analysis_interfaces.msg import Interval
        self.t_domain = kwargs.get('t_domain', Interval())
        self.dt = kwargs.get('dt', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.name != other.name:
            return False
        if self.boxes != other.boxes:
            return False
        if self.t_domain != other.t_domain:
            return False
        if self.dt != other.dt:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def name(self):
        """Message field 'name'."""
        return self._name

    @name.setter
    def name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'name' field must be of type 'str'"
        self._name = value

    @builtins.property
    def boxes(self):
        """Message field 'boxes'."""
        return self._boxes

    @boxes.setter
    def boxes(self, value):
        if __debug__:
            from interval_analysis_interfaces.msg import Box
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Box) for v in value) and
                 True), \
                "The 'boxes' field must be a set or sequence and each value of type 'Box'"
        self._boxes = value

    @builtins.property
    def t_domain(self):
        """Message field 't_domain'."""
        return self._t_domain

    @t_domain.setter
    def t_domain(self, value):
        if __debug__:
            from interval_analysis_interfaces.msg import Interval
            assert \
                isinstance(value, Interval), \
                "The 't_domain' field must be a sub message of type 'Interval'"
        self._t_domain = value

    @builtins.property
    def dt(self):
        """Message field 'dt'."""
        return self._dt

    @dt.setter
    def dt(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'dt' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'dt' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._dt = value
