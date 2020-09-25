#ifndef _ROS_naoqi_bridge_msgs_JointTrajectoryActionResult_h
#define _ROS_naoqi_bridge_msgs_JointTrajectoryActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "naoqi_bridge_msgs/JointTrajectoryResult.h"

namespace naoqi_bridge_msgs
{

  class JointTrajectoryActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef naoqi_bridge_msgs::JointTrajectoryResult _result_type;
      _result_type result;

    JointTrajectoryActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "naoqi_bridge_msgs/JointTrajectoryActionResult"; };
    const char * getMD5(){ return "8863b007f420d5f94fcdaa0f865d1767"; };

  };

}
#endif