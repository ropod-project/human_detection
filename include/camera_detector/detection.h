// Generated by gencpp from file camera_detector/detection.msg
// DO NOT EDIT!


#ifndef CAMERA_DETECTOR_MESSAGE_DETECTION_H
#define CAMERA_DETECTOR_MESSAGE_DETECTION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace camera_detector
{
template <class ContainerAllocator>
struct detection_
{
  typedef detection_<ContainerAllocator> Type;

  detection_()
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , p(0.0)  {
    }
  detection_(const ContainerAllocator& _alloc)
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , p(0.0)  {
  (void)_alloc;
    }



   typedef float _x_type;
  _x_type x;

   typedef float _y_type;
  _y_type y;

   typedef float _z_type;
  _z_type z;

   typedef float _p_type;
  _p_type p;





  typedef boost::shared_ptr< ::camera_detector::detection_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::camera_detector::detection_<ContainerAllocator> const> ConstPtr;

}; // struct detection_

typedef ::camera_detector::detection_<std::allocator<void> > detection;

typedef boost::shared_ptr< ::camera_detector::detection > detectionPtr;
typedef boost::shared_ptr< ::camera_detector::detection const> detectionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::camera_detector::detection_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::camera_detector::detection_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace camera_detector

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'camera_detector': ['/home/nvidia/detector_ws/src/camera_detector/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::camera_detector::detection_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::camera_detector::detection_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::camera_detector::detection_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::camera_detector::detection_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::camera_detector::detection_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::camera_detector::detection_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::camera_detector::detection_<ContainerAllocator> >
{
  static const char* value()
  {
    return "76c0035e71172ec5a99c984c5fe5a6e1";
  }

  static const char* value(const ::camera_detector::detection_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x76c0035e71172ec5ULL;
  static const uint64_t static_value2 = 0xa99c984c5fe5a6e1ULL;
};

template<class ContainerAllocator>
struct DataType< ::camera_detector::detection_<ContainerAllocator> >
{
  static const char* value()
  {
    return "camera_detector/detection";
  }

  static const char* value(const ::camera_detector::detection_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::camera_detector::detection_<ContainerAllocator> >
{
  static const char* value()
  {
    return "## interpolated coordinates (at height of the laser range finder)\n\
#float32 x\n\
#float32 y\n\
#float32 z\n\
## detection probability, radius and length\n\
#float32 p\n\
#float32 r\n\
#float32 d\n\
## coordinates of interpolated lower leg parts (from ankle(0.0) to knee(1.0) @0.0, 0.25, 0.5, 0.75, 1.0)\n\
#float32[] xArray\n\
#float32[] yArray\n\
#float32[] zArray\n\
## coordinates of measured lower leg parts (from ankle(0.0) to knee(1.0) @0.0, 0.25, 0.5, 0.75, 1.0)\n\
#float32[] xValArray\n\
#float32[] yValArray\n\
#float32[] zValArray\n\
\n\
## ankle and knee xyz points\n\
#float32 xAnkle\n\
#float32 yAnkle\n\
#float32 zAnkle\n\
#float32 xKnee\n\
#float32 yKnee\n\
#float32 zKnee\n\
## measurement labels\n\
#bool validSize\n\
##bool associated\n\
#bool validHeight\n\
#bool validUniqueness #occluded behind\n\
##int32[] associatedPoints\n\
##float32[] associationProbabilities\n\
##int32[] associatedPointsAll\n\
##float32[] associationProbabilitiesAll\n\
##bool[] associationVisitedAll\n\
##bool associationVisited\n\
#float32 distContinuous\n\
#int32 personID\n\
#bool leftLeg\n\
\n\
float32 x\n\
float32 y\n\
float32 z\n\
float32 p\n\
";
  }

  static const char* value(const ::camera_detector::detection_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::camera_detector::detection_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
      stream.next(m.p);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct detection_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::camera_detector::detection_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::camera_detector::detection_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<float>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<float>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<float>::stream(s, indent + "  ", v.z);
    s << indent << "p: ";
    Printer<float>::stream(s, indent + "  ", v.p);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CAMERA_DETECTOR_MESSAGE_DETECTION_H