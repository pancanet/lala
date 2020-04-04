#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

void dataCallback(const sensor_msgs::LaserScan::ConstPtr& msg){
	// Get the range of the laser scanner
    std::vector<float> laser_scan_range;
    laser_scan_range = msg->ranges;

    float min_distance = 10000;

    for(int i = 0; i < laser_scan_range.size(); i++){
                        if(min_distance > laser_scan_range[i]) {
                                        min_distance = laser_scan_range[i];
                        }
                }

                        ROS_INFO_STREAM("jarak hiyahiyahiya: " + std::to_string(min_distance));
}

int main(int argc, char** argv){
	ros::init(argc, argv, "lala");

	ros::NodeHandle nodeHandle("~");

	std::string taupiq;
	int queque;

	nodeHandle.getParam("/lala/config/topic_name", taupiq);
	nodeHandle.getParam("/lala/config/queue_size", queque);

	ros::Subscriber subcriber = 
		nodeHandle.subscribe(taupiq,queque,dataCallback);
	ros::spin();
	return 0;
}
