#include <Arduino.h>
#include <NTCtemp.h>  // Nhúng thư viện bạn vừa tạo
// put function declarations here:
const float A = 1.009249522e-03;  // Hằng số Steinhart-Hart, xem datasheet ntc
const float B = 2.378405444e-04;
const float C = 2.019202697e-07;
const float dientro = 10000;  // Điện trở nối tiếp 10kΩ,có thể chọn cái khác

NTCtemp ntc(dientro,A,B,C);



void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature = ntc.gettemp(A0);  // ví dụ đọc nhiệt độ từ chân A0
}

// put function definitions here:
