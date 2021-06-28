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
  float pitch;
  float roll;
  float yaw;
  float throttle;
}__RC_Data;




#endif