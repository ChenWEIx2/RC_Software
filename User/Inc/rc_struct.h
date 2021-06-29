/**
  ******************************************************************************
  * @file           : rc_struct.h
  * @brief          : This is a struct,which include all rc datas.
  ******************************************************************************
*/

#ifndef __RC_STRUCT_H
#define __RC_STRUCT_H

#include <stdint.h>

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
    uint16_t meanless1;
    uint16_t meanless2;
    uint16_t pitch;
    uint16_t roll;
    uint16_t throttle;
    uint16_t yaw;
}__Rocker_Data;

typedef struct
{
  uint8_t unlock_flag;
  uint8_t offset_flag;

  uint8_t unlock_finish_flag;
  uint8_t offset_finish_flag;

  uint16_t unlock_counter;
  uint16_t offset_counter;
}__Start__Flag;




#endif