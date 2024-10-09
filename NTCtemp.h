#ifndef NTCtemp_H
#define NTCtemp_H
#include "Arduino.h"
class NTCtemp {
public:
NTCtemp(float dientro,float A, float B, float C);
float gettemp(int analogPin);// hàm đọc nhiêt độ( C)

private:
float tinhtoandientro(int analogValue); //hàm tính điện trở NTC
float dientro; // điện trở nối tiếp với NTC
float A,B,C; // hệ số steinhart-Hart

};
#endif
// ở đây ta định nghĩa tên các hàm cần thiết