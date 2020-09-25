#ifndef _ROS_pr2_gripper_sensor_msgs_PR2GripperReleaseActionGoal_h
#define _ROS_pr2_gripper_sensor_msgs_PR2GripperReleaseActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "pr2_gripper_sensor_msgs/PR2GripperReleaseGoal.h"

namespace pr2_gripper_sensor_msgs
{

  class PR2GripperReleaseActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef pr2_gripper_sensor_msgs::PR2GripperReleaseGoal _goal_type;
      _goal_type goal;

    PR2GripperReleaseActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pr2_gripper_sensor_msgs/PR2GripperReleaseActionGoal"; };
    const char * getMD5(){ return "e5f06f3717f8990527330a2e0eaa0c81"; };

  };

}
#endif
