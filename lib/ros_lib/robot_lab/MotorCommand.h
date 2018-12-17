#ifndef _ROS_robot_lab_MotorCommand_h
#define _ROS_robot_lab_MotorCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robot_lab
{

  class MotorCommand : public ros::Msg
  {
    public:
      typedef float _left_type;
      _left_type left;
      typedef float _right_type;
      _right_type right;
      typedef bool _hardStop_type;
      _hardStop_type hardStop;

    MotorCommand():
      left(0),
      right(0),
      hardStop(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_left;
      u_left.real = this->left;
      *(outbuffer + offset + 0) = (u_left.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left);
      union {
        float real;
        uint32_t base;
      } u_right;
      u_right.real = this->right;
      *(outbuffer + offset + 0) = (u_right.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right);
      union {
        bool real;
        uint8_t base;
      } u_hardStop;
      u_hardStop.real = this->hardStop;
      *(outbuffer + offset + 0) = (u_hardStop.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->hardStop);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_left;
      u_left.base = 0;
      u_left.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left = u_left.real;
      offset += sizeof(this->left);
      union {
        float real;
        uint32_t base;
      } u_right;
      u_right.base = 0;
      u_right.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right = u_right.real;
      offset += sizeof(this->right);
      union {
        bool real;
        uint8_t base;
      } u_hardStop;
      u_hardStop.base = 0;
      u_hardStop.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->hardStop = u_hardStop.real;
      offset += sizeof(this->hardStop);
     return offset;
    }

    const char * getType(){ return "robot_lab/MotorCommand"; };
    const char * getMD5(){ return "d5a729c8779fbc6e69374ccf740a06e6"; };

  };

}
#endif