#include <math.h>
using namespace std;
#include <vector>
#include <human_walking_detection/line.h>
#include <human_walking_detection/lines.h>
#include <human_walking_detection/tube.h>
#include <human_walking_detection/singleTube.h>
#include <human_walking_detection/tubes.h>
#include <human_walking_detection/tubesH.h>
#include <human_walking_detection/transform.h>
#include <human_walking_detection/human.h>
#include <human_walking_detection/robot.h>
#include <human_walking_detection/hypothesis.h>
#include <human_walking_detection/hypotheses.h>
#include <iostream>
#include <armadillo>
#include <visualization_msgs/MarkerArray.h>

using namespace arma;

class vectorFieldMap {
    public:
    void initializeMap();
    void updateHypotheses(double x, double y, double vx, double vy, double xRobot, double yRobot, double thetaRobot);
    void readMap(visualization_msgs::MarkerArray &staticMarkers,visualization_msgs::MarkerArray &dynamicMarkers);
    human_walking_detection::tubes globalTube;
    human_walking_detection::tubesH globalTubesH;
    human_walking_detection::hypotheses hypotheses;
    // vector<human_walking_detection::tubes> tubesH;


    struct positionVars {
        float x;
        float y;
        bool curved;
    };

    struct graph {
        vector<vector<double>> A;
        vector<vector<double>> AShort;
        vector<bool> marked;
        vector<int> ALink;
    };

    struct recursiveWalk {
        int toTube;
        double dir;
        double distance;
        int fromTube;
        double pEndStore;
        double zEndStore;
        vector<int> storeElement;
    };

    struct recursiveWalkStore {
        int index;
        double dTot;
        double pStore;
        vector<int> path;
    };
    


    private:
    human_walking_detection::human human;
    human_walking_detection::robot robot;
    visualization_msgs::MarkerArray staticMap;
    visualization_msgs::MarkerArray dynamicMap;
    visualization_msgs::MarkerArray map;
    graph G;


    struct TBCS {
        int i;
        bool border;
        bool oneSide;
    };


    void pointsToLine(human_walking_detection::lines &lines);
    double dist(double x1,double y1,double x2,double y2);
    double sign(double var);
    void intersectLines(human_walking_detection::lines lines, positionVars &result);
    void initializeTubeCurved(human_walking_detection::singleTube &tube);
    void initializeTubeStraight(human_walking_detection::singleTube &tube);
    void createGraphShort(human_walking_detection::tubes tube, graph &G);
    void zVal(human_walking_detection::singleTube &tube,double x,double y,bool rel,double &z, double &p, bool &inside);
    human_walking_detection::line createLineTemp(double x1,double x2,double y1,double y2,double th1, double th2);
    void linspace(double v1, double v2, int n, vector<double> &result);
    positionVars Fry(human_walking_detection::singleTube tube,double I1,double I2,bool rel);
    void clearTube(visualization_msgs::MarkerArray map);
    void plotTube(human_walking_detection::singleTube tube, int n1, int n2,int subID, bool rel, bool sub, double r, double g, double b, double a, string ns, visualization_msgs::MarkerArray &map);
    void linesToTube(human_walking_detection::lines &lines,human_walking_detection::tubes &tubes,double id,TBCS TBC,bool marked);
    void createGraph(human_walking_detection::tubes tube, graph &G);
    void findPointInTube(human_walking_detection::tubes tubes, double x, double y, vector<int> &index);
    void calcGradient(human_walking_detection::singleTube tube,double x, double y, double &u, double &v);
    void derivativeF(human_walking_detection::singleTube tube, double x, double y, double &dphidx, double &dphidy);
    void FuvStraight(double dphidx,double dphidy,human_walking_detection::singleTube tube,double &u, double &v);
    void FuvCurved(double dphidr,double dphidtheta,double theta,double r,double signlr,double &u, double &v);
    bool considerHuman(human_walking_detection::human person,human_walking_detection::robot robot);
    void createDynamicAsOI(human_walking_detection::tubes tube,double xPR, double yPR,graph G,vector<bool> &seenTubes,vector<bool> openTubes,double dMax,vector<recursiveWalkStore> &store);
    void distEnd(double x,double y,vector<recursiveWalkStore> &store,vector<recursiveWalk> prev,vector<recursiveWalk> &next,human_walking_detection::tubes tube,graph G,vector<bool> openTubes,double dMax);
    void nextTube(vector<int> index,graph G,vector<int> &toTube, vector<double> &direction);
    bool inAvailableTube(vector<bool> openTubes,graph G,int toTube);
    void nextTube(int index,graph G,vector<int> &toTube, vector<double> &direction);
    void recursiveWalkA(vector<recursiveWalkStore> &store,vector<recursiveWalk> next,human_walking_detection::tubes tube,graph G,vector<bool> &seenTubes,vector<bool> openTubes,double dMax);
    void validateHypotheses(double x, double y, double vx, double vy, vector<human_walking_detection::tubes> tubesH);
    void createTubeHypothesis(human_walking_detection::tubes tube,vector<recursiveWalkStore> store,graph G,human_walking_detection::robot robot, vector<human_walking_detection::tubes> &tubesH);
    void borderTransform(human_walking_detection::tubes &tube);
    void plotAOI(human_walking_detection::singleTube tube, int n, int subID, double a, string ns,double p,visualization_msgs::MarkerArray &map);
    void walkConstant(human_walking_detection::singleTube tube,double ds,double &x,double &y, double &C, double &p, double &D);
    void addObject(human_walking_detection::tubes &tube,human_walking_detection::robot object, int TBCi);
    void walkToBorder(double &x,double &y,double dMax,human_walking_detection::tubes tube,bool &endReached, double &dist, bool &border);
    void minVal(vector<double> prTemp, double &minVal, int &minInd);
    void maxVal(vector<double> prTemp, double &minVal, int &minInd);
    int findPGlobalInTube(human_walking_detection::tubes tube, double p);
    double angleBetweenVectors(human_walking_detection::line lineTemp,double v1[2]);
    double relativeGradientV2(human_walking_detection::line lineTemp,human_walking_detection::singleTube tube,int i);
    void addBorderElement(double zFixed,double zBorder,human_walking_detection::tubes tube,double p,double dfStart,human_walking_detection::lines linesB,double index,positionVars O,double theta_2);
    void splitFrontBack(double &xLoop,double &yLoop,double &df,human_walking_detection::tubes tube,bool &endReached,human_walking_detection::lines &lines,human_walking_detection::lines &linesB,double &dTot,double zVar,vector<double> CfT1,vector<double> CfT2,double zFixed,double zBorder,double dfStart);
    void newTubeSplit(human_walking_detection::tubes tube,double zFixed,double zBorder,double zVar,double zVarEnd,double pVar,double df,double v1[2],human_walking_detection::lines &lines,human_walking_detection::lines &linesB);
    void walkStraight(double x1,double y1,double x2,double y2,human_walking_detection::tubes tube,vector<int> tube_indices, vector<double> x_ind, vector<double> y_ind);
    void newTubeSplitMiddle(human_walking_detection::tubes tube,double zFixed,double x[4],double y[4],int ind1,int ind2,double v1[2],double zBorder,human_walking_detection::lines &lines,human_walking_detection::lines &linesB);
    void plotLine(double x1, double x2, double y1, double y2, int i,double r, double g, double b, double a, string ns,visualization_msgs::MarkerArray &map);
    void plotRobot(human_walking_detection::robot object);
    void validatePointInSubTube(human_walking_detection::tube tube, double x, double y, double vx, double vy,vector<double> &prop);
    void plotStandingTube(double x, double y, double radius, double r, double g, double b, double a, string ns,visualization_msgs::MarkerArray &map);
};