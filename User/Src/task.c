#include "task.h"


void Task_25Hz(__Key_Data key_data,__Rocker_Data rocker_data)
{
    printf("Key status:%d, %d, %d, %d, %d, %d.\r\n",key_data.key_0,key_data.key_1,key_data.key_2,key_data.key_3,key_data.key_4,key_data.key_5);
    printf("Pitch:%f.\r\n",rocker_data.pitch);
    printf("Roll:%f.\r\n",rocker_data.roll);
    printf("Throttle:%f.\r\n",rocker_data.throttle);
    printf("Yaw:%f.\r\n",rocker_data.yaw);
}