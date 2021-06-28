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
    float meanless1;
    float meanless2;
    float pitch;
    float roll;
    float throttle;
    float yaw;
}__Rocker_Data;





#endif