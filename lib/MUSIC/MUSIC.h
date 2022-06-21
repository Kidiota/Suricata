#include <Arduino.h>
#include <iostream>
#include <esp32-hal-ledc.h>
uint16_t freq = 440;    //设置频率
uint8_t channel = 0;    //通道号,取值0~15 
uint8_t resolution = 8;    //计数位数，2的8次幂=256
uint8_t longOfVoics;

uint16_t C_4  = 523;
uint16_t D_4  = 587;
uint16_t E_4  = 659;
uint16_t F_4  = 698;
uint16_t G_4  = 784;
uint16_t A_4  = 880;
uint16_t B_4  = 988;
uint16_t C_5  = 1046;
uint16_t D_5  = 1175;
uint16_t E_5  = 1318;
uint16_t F_5  = 1397;
uint16_t G_5  = 1568;
uint16_t A_5  = 1760;
uint16_t B_5  = 1976;


void setBPM(uint8_t BPM){
    longOfVoics = 15000 / BPM -20; //一个十六分音符所占时长
}
void BuzzTone(uint16_t tone,uint8_t time){
    ledcWriteTone(channel,tone);
    delay(longOfVoics*time);
    ledcWriteTone(channel,0);
    delay(20);
}