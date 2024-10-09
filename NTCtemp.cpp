#include "NTCtemp.h"'
#include <math.h>


NTCtemp:: NTCtemp(float dientro,float A, float B, float C){
this-> dientro = dientro;
this->A = A;
this->B = B;
this->C = C;

}

float NTCtemp:: gettemp(int analogPin){
int analogValue= analogRead(analogPin);
float resistance = tinhtoandientro(analogValue);
// phương trình steinhart-hart tính toan nhiet do(kenvin)
float steinhart;
steinhart = log(resistance); // logarit của dien tro
steinhart = A+B*steinhart + C*pow(steinhart,3);
steinhart = 1/ steinhart;// đảo ngược để có nhiệt độ(kenvin)
float tempC = steinhart -273.15; // đổi từ kenvin sang celsius
return tempC;
}

float NTCtemp:: tinhtoandientro(int analogValue){
float volt = analogValue*(5/1023); //analog 5 volt 8 bit
float resistance =(5/volt-1)*dientro; // tinh dien tro NTC
return resistance;

}
//A,B,C là các hằng số Steinhart-Hart, được xác định thông qua đặc trưng của cảm biến.
// ở đây ta viết chức năng của các hàm