#include <Arduino.h>
#include <NTCtemp.h>  // Nhúng thư viện bạn vừa tạo
// put function declarations here:
const float A = 1.009249522e-03;  // Hằng số Steinhart-Hart, xem datasheet ntc
const float B = 2.378405444e-04;
const float C = 2.019202697e-07;
const float dientro = 10000;  // Điện trở nối tiếp với NTC: 10kΩ,có thể chọn dien tro khác

NTCtemp ntc(dientro,A,B,C);
// code này khi dùng hệ số beta
/*const float nominalResistance = 10000;  // 10kΩ tại 25°C
const float nominalTemperature = 25;    // 25°C là nhiệt độ tham chiếu
const float beta = 3950;                // Hệ số Beta từ datasheet
const float dientro = 10000;     // Điện trở nối tiếp 10kΩ
NTCtemp ntc(dientro, nominalResistance, nominalTemperature, beta);
*/

// biến thời gian để chạy 1 giây 1 lần
unsigned long previousMillis1 = 0;
const long interval1 = 1000; //1s
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
 Serial.begin(9600); // mở port ở mức 9600
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis1 >= interval1) {
    previousMillis1 = currentMillis;
  float temperature = ntc.gettemp(A0);  // ví dụ đọc nhiệt độ từ chân A0
   Serial.print("Nhiet do: ");
   Serial.println(temperature);
  }

}

// put function definitions here:
