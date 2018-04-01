#define analogPin A0 // аналоговый выход MQ135 подключен к пину A0 Arduino
#define digitalPin 3 // цифровой выход подключен к пину 3
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

float analogValue; // для аналогового значения
byte digitalValue; // для цифрового значения, можно, кстати и boolean, но не суть

void setup() {

  Serial.begin(9600); // инициализация последовательного порта
  pinMode(analogPin, INPUT); // режим работы аналогового пина
  pinMode(digitalPin, INPUT); // режим работы цифрового пина
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
  delay(1000); // устаканимся
  }

void loop() {

  /*sudo chown maxim  /dev/ttyACM0
  sudo ln -s /dev/ttyACM0 /dev/ttyUSB0*/
  analogValue = analogRead(analogPin); // чтение аналогового значения
  digitalValue = digitalRead(3); // чтение цифрового значения
  // вывод аналогового значения в последовательный порт
  
  Serial.print("sid:007,");
  Serial.print("val:"+String(analogValue,0) + ",");

  if (analogValue>150){
     setColor(255, 0, 0, 300); // красный
  } else{
  delay(300); // задержка, чтобы не мельтешило перед глазами
  }
}

void setColor(int red, int green, int blue, int del)
{
    #ifdef COMMON_ANODE
    red = 255 - red
    green = 255 - green;
    blue = 255 - blue;
    #endif
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
    delay(del);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    
}
