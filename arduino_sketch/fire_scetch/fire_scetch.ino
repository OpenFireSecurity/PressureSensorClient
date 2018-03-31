#define analogPin A0 // аналоговый выход MQ135 подключен к пину A0 Arduino
#define digitalPin 3 // цифровой выход подключен к пину 3

float analogValue; // для аналогового значения
byte digitalValue; // для цифрового значения, можно, кстати и boolean, но не суть

void setup() {

Serial.begin(9600); // инициализация последовательного порта
pinMode(analogPin, INPUT); // режим работы аналогового пина
pinMode(digitalPin, INPUT); // режим работы цифрового пина
delay(1000); // устаканимся
}

void loop() {

  analogValue = analogRead(analogPin); // чтение аналогового значения
  digitalValue = digitalRead(3); // чтение цифрового значения
  // вывод аналогового значения в последовательный порт
  Serial.print(String(analogValue,0) + ",");
  delay(300); // задержка, чтобы не мельтешило перед глазами

}
