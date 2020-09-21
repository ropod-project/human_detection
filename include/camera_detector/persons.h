// Generated by gencpp from file camera_detector/persons.msg
// DO NOT EDIT!


#ifndef CAMERA_DETECTOR_MESSAGE_PERSONS_H
#define CAMERA_DETECTOR_MESSAGE_PERSONS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <camera_detector/person.h>

namespace camera_detector
{
template <class ContainerAllocator>
struct persons_
{
  typedef persons_<ContainerAllocator> Type;

  persons_()
    : persons()  {
    }
  persons_(const ContainerAllocator& _alloc)
    : persons(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::camera_detector::person_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::camera_detector::person_<ContainerAllocator> >::other >  _persons_type;
  _persons_type persons;





  typedef boost::shared_ptr< ::camera_detector::persons_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::camera_detector::persons_<ContainerAllocator> const> ConstPtr;

}; // struct persons_

typedef ::camera_detector::persons_<std::allocator<void> > persons;

typedef boost::shared_ptr< ::camera_detector::persons > personsPtr;
typedef boost::shared_ptr< ::camera_detector::persons const> personsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::camera_detector::persons_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::camera_detector::persons_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace camera_detector

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'camera_detector': ['/home/nvidia/detector_ws/src/camera_detector/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::camera_detector::persons_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::camera_detector::persons_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::camera_detector::persons_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::camera_detector::persons_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::camera_detector::persons_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::camera_detector::persons_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::camera_detector::persons_<ContainerAllocator> >
{
  static const char* value()
  {
    return "80d390b113cf0af963976467a54aaebb";
  }

  static const char* value(const ::camera_detector::persons_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x80d390b113cf0af9ULL;
  static const uint64_t static_value2 = 0x63976467a54aaebbULL;
};

template<class ContainerAllocator>
struct DataType< ::camera_detector::persons_<ContainerAllocator> >
{
  static const char* value()
  {
    return "camera_detector/persons";
  }

  static const char* value(const ::camera_detector::persons_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::camera_detector::persons_<ContainerAllocator> >
{
  static const char* value()
  {
    return "person[] persons\n\
\n\
================================================================================\n\
MSG: camera_detector/person\n\
personAssociation[] p\n\
int32 personID\n\
\n\
================================================================================\n\
MSG: camera_detector/personAssociation\n\
int32 leftLegObject\n\
string leftLegObjectID\n\
int32 rightLegObject\n\
string rightLegObjectID\n\
float32 associationProbability\n\
\n\
\n\
";
  }

  static const char* value(const ::camera_detector::persons_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::camera_detector::persons_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.persons);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct persons_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::camera_detector::persons_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::camera_detector::persons_<ContainerAllocator>& v)
  {
    s << indent << "persons[]" << std::endl;
    for (size_t i = 0; i < v.persons.size(); ++i)
    {
      s << indent << "  persons[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::camera_detector::person_<ContainerAllocator> >::stream(s, indent + "    ", v.persons[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // CAMERA_DETECTOR_MESSAGE_PERSONS_H
