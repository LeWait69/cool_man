#include <Servo.h>

Servo myServo;  // Создаём объект для серво

int servoPin = 2; // Пин, к которому подключён сигнальный провод

void setup() {
  myServo.attach(servoPin); // Привязываем серво к пину
  myServo.write(0);         // Устанавливаем начальное положение в 0 градусов
  delay(1000);              // Ждём, пока серво встанет в позицию
}

void loop() {
  // Плавно поворачиваем от 0 до 180 градусов
  for (int angle = 0; angle <= 180; angle++) {
    myServo.write(angle);
    delay(15); // Небольшая задержка для плавности (для MG996R можно 10-15 мс)
  }
  
  delay(1000); // Пауза перед движением назад

  // Плавно возвращаем от 180 до 0 градусов
  for (int angle = 180; angle >= 0; angle--) {
    myServo.write(angle);
    delay(15);
  }
  
  delay(1000);
}
