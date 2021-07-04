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
    uint8_t front_fine_tune_Key;
    uint8_t back_fine_tune_key;
    uint8_t left_fine_tune_key;
    uint8_t right_fine_tune_key;
    uint8_t left_key;
    uint8_t right_key;
    
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
  uint8_t left_offset_finish_flag;
  uint8_t right_offset_finish_flag;

  uint8_t do_offset_counter;
  uint8_t do_left_offset_counter;
  uint8_t do_right_offset_counter;

  uint16_t unlock_counter;
  uint16_t left_offset_counter;
  uint16_t right_offset_counter;

}__Start__Flag;




#endif