/**
  ******************************************************************************
  * @file           : rc_struct.h
  * @brief          : This is a struct,which include all rc datas.
  ******************************************************************************
*/

#ifndef __RC_STRUCT_H
#define __RC_STRUCT_H

typedef struct 
{
    uint8_t key_0;
    uint8_t key_1;
    uint8_t key_2;
    uint8_t key_3;
    uint8_t key_4;
    uint8_t key_5;
    
}__Key_Data;

typedef struct 
{
    double ch1_x;
    double ch1_y;
    double ch2_x;
    double ch2_y;
}__Channel_Data;

typedef struct
{
  double pithc;
  double roll;
  double yaw;

  double horizontal_speed;
  double vertical_speed;
}__Kinetic_Data;




#endif