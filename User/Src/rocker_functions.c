


#include "rocker_functions.h"

void Rocker_Data_Mapping(__Rocker_Data* rocker_data,volatile uint16_t* adc_data)
{
    rocker_data->ch1_x = *(adc_data + 0) * 3.3 / 4095;
    rocker_data->ch1_y = *(adc_data + 1) * 3.3 / 4095;
    rocker_data->ch2_x = *(adc_data + 2) * 3.3 / 4095;
    rocker_data->ch2_y = *(adc_data + 3) * 3.3 / 4095; 
}

void Rocker_Data_Log(__Rocker_Data* rocker_data,uint8_t n)
{
    char buff1[10],buff2[10],buff3[10],buff4[10];

    float2char(rocker_data->ch1_x,buff1,n);
    float2char(rocker_data->ch1_y,buff2,n);
    float2char(rocker_data->ch2_x,buff3,n);
    float2char(rocker_data->ch2_y,buff4,n);

    LOGI("%s,%s,%s,%s",buff1,buff2,buff3,buff4);
}


void float2char(float slope,char*buffer,int n)  //浮点型数，存储的字符数组，字符数组的长度
{
    int temp,i,j;
    if(slope>=0)//判断是否大于0
        buffer[0] = '+';
    else
    {
        buffer[0] = '-';
        slope = -slope;
    }
    temp = (int)slope;//取整数部分
    for(i=0;temp!=0;i++)//计算整数部分的位数
        temp /=10;
    temp =(int)slope;
    for(j=i;j>0;j--)//将整数部分转换成字符串型
    {
        buffer[j] = temp%10+'0';
        temp /=10;
    }
    buffer[i+1] = '.';
    slope -=(int)slope;
    for(i=i+2;i<n-1;i++)//将小数部分转换成字符串型
    {
        slope*=10;
        buffer[i]=(int)slope+'0';
        slope-=(int)slope;
    }
    buffer[n-1] = '\0';
}