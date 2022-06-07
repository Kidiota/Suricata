#include <Arduino.h>
#include <Suricata_VFD.h>




void setup() {
  /*
  pinMode(en, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(din, OUTPUT);
  pinMode(cs, OUTPUT);
  pinMode(Reset, OUTPUT);
  digitalWrite(en, HIGH);
  delayMicroseconds(100);
  digitalWrite(Reset, LOW);
  delayMicroseconds(5);
  digitalWrite(Reset, HIGH);
  VFD_init();
  */
  VFD_SETUP();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  VFD_cmd(0xE9);// 全亮测试 屏幕
  delay(1000);
  
  VFD_WriteOneChar(0, 1);
  VFD_WriteOneChar(1, 2);
  VFD_WriteOneChar(2, 3);
  VFD_WriteOneChar(3, 4);
  VFD_WriteOneChar(4, 5);
  VFD_WriteOneChar(5, 6);
  VFD_WriteOneChar(6, 7);
  VFD_WriteOneChar(7, 8);
  delay(1000);
  
  VFD_WriteStr(0, "ABCDEFGH");
  delay(1000);

  VFD_WriteUserFont(0,0,ziku_data[0]);//0号位字符 自定义字库中字模0
  VFD_WriteUserFont(1,1,ziku_data[1]);
  VFD_WriteUserFont(2,2,ziku_data[2]);
  VFD_WriteUserFont(3,3,ziku_data[3]);
  VFD_WriteUserFont(4,4,ziku_data[4]);
  VFD_WriteUserFont(5,5,ziku_data[5]);
  VFD_WriteUserFont(6,6,ziku_data[6]);
  VFD_WriteUserFont(7,7,ziku_data[7]);
  delay(1000);
}
