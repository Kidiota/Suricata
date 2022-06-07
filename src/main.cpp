#include <Arduino.h>
#include <Suricata_VFD.h>
#include <iostream>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <stdlib.h>

using namespace std;

const char *ssid1 = "Kidiota_Wifi";    //首选wifi SSID
const char *password1 = "return01";    //首选wifi 密码

WiFiUDP ntpUDP;    //更新时间
NTPClient timeClient(ntpUDP, "ntp1.aliyun.com",8*60*60, 30*60*1000);    //设置时区

void setup() {
  Serial.begin(115200);    //串口设置波特率
  VFD_SETUP();    //屏幕初始化
  WiFi.begin(ssid1, password1);    //连接WiFi
  uint8_t i = 0;  
  while(WiFi.status() != WL_CONNECTED){    //如果没连上WiFi，执行下列代码
      VFD_WriteStr(i, ".");    //在屏幕上显示一个点
      i = i + 1;    //向后移一位
      Serial.print(".");
      delay(100);
    }
  VFD_WriteStr(0,"OK");
  Serial.print("WiFi ok");
  delay(1000);
  VFD_WriteStr(0,"        ");
}

void loop() {
  // put your main code here, to run repeatedly:
  timeClient.update();
  String str=timeClient.getFormattedTime();
  char *formattedTime=(char*)str.c_str();
  VFD_WriteStr(0, formattedTime);
  Serial.print(timeClient.getFormattedTime());
  Serial.print("\n");
}
