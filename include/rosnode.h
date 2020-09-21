#include <human_walking_detection/Pose.h>
#include <human_walking_detection/PoseVel.h>
#include <visualization_msgs/MarkerArray.h>
#include <ros/ros.h>
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/Pose.h"
#include <tf2/LinearMath/Quaternion.h>
#include <camera_detector/detection.h>
#include <camera_detector/detections.h>
#include <human_walking_detection/line.h>
#include <human_walking_detection/lines.h>
#include <human_walking_detection/tube.h>
#include <human_walking_detection/singleTube.h>
#include <human_walking_detection/tubes.h>

using namespace std;

class rosNode {
    public:

        // matrix A(4,vector<double>(4));

        vector<double> measurement;

        // double[2] measurement;
        double p1,p2,p3,p4;

        // Start ROS listener
        ros::Publisher semantic_map;
        ros::Publisher measuredHuman;
        ros::Publisher humanState;
        ros::Publisher humanPV;
        ros::Publisher tubeTop;

        ros::NodeHandle n;

        ros::Subscriber subHuman;

        human_walking_detection::PoseVel humanPosVel;

        visualization_msgs::Marker deleteAllMarker;
        visualization_msgs::MarkerArray markerArrayWalls;
        visualization_msgs::MarkerArray markerArrayAoI;
        visualization_msgs::MarkerArray markerArrayStatic;
        visualization_msgs::Marker markerA;
        human_walking_detection::tubes globalTube;

        int a=4;

        // rosparam
        int iMax;
        bool real;
        double xCamera,yCamera;
  
        //functions
        void createLine(int i, double xL, double yL, double zL, double xR, double yR, double zR, double r, double g, double b, double radius, visualization_msgs::Marker &marker);

        void processMap();

        void publishMap();

        void publishHumanPV();

        void visualizeHuman();

        void publishAoI();

        void publishTube();

        void visualizeMeasuredHuman();

        void initialize();

        void updateFakeMeasurement(const human_walking_detection::Pose& poseHuman);

        void updateRealMeasurement(const camera_detector::detections& poseHuman);

        // void getMeasurement(vector<double> &z);

        // void setHumanPosVel(human_walking_detection::PoseVel humanPosVel_);

        // void getHumanPosVel(human_walking_detection::PoseVel &humanPosVel_);

        void setMap(visualization_msgs::MarkerArray staticMap);

        void publishTube(human_walking_detection::tubes tube);

};