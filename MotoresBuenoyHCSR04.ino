
int PinIN1 = 7;     //pines de habilitación de motor
int PinIN2 = 6;     //pines de habilitación de motor
int PinIN3 = 8;     //pines de habilitación de motor
int PinIN4 = 9;     //pines de habilitación de motor
int ENA1=10;        //pines de habilitación de motor
int ENA2=5;         //pines de habilitación de motor
int vel=205;        //velocidad motor1
int vel2=173;       //velocidad motor2

const int trigPin = 11;//pines sensores de movimiento
const int echoPin = 12;//pines sensores de movimiento
const int trigPin2 = 4;//pines sensores de movimiento
const int echoPin2 = 2;//pines sensores de movimiento
// variables de distancia de obstaculos
long duration;
int distance;
long duration2;
int distance2;

void setup() {
  pinMode(trigPin, OUTPUT); // Entradas y salidas del sensor de movimiento 1
  pinMode(echoPin, INPUT);  
  pinMode(trigPin2, OUTPUT); // Entradas y salidas del sensor de movimiento 2
  pinMode(echoPin2, INPUT); 

  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);  // Pines de salida de los motores de potencia
  pinMode(PinIN3, OUTPUT);
  pinMode(PinIN4, OUTPUT);
  pinMode (ENA1, OUTPUT);
  pinMode (ENA2, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println('E');


}
void loop() {
///// Movimiento hasta encontrar un siguiente WayPoint
hcsr041();
hcsr042();

if(distance<=15)Derecha();
else 
if(distance2<=15)Izquierda();
else Adelante();

if (Serial.available() > 0) {
char dato = Serial.read();
if (dato=='R'){
  Adelante();
delay(1000);
MotorStop();
Serial.println('E');
  }

}

Adelante();
delay(6000);
MotorStop();
Serial.println('E');
delay(4000);



}

//FUNCIONES DE DETECCIÓN DE OBSTÁCULOS
void hcsr041(){
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
//Calculo de la distancia del obstaculo1
distance= duration*0.034/2;
//Serial.print("Distance: ");
//Serial.println(distance);
  }
  void hcsr042(){
  digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
duration2 = pulseIn(echoPin2, HIGH);
//Calculo de la distancia del obstaculo2
distance2= duration2*0.034/2;
//Serial.print("Distance-----2: ");
//Serial.println(distance2);
  }

//FUNCIONES DE MOVIMIENTO
  void Adelante()
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, HIGH);
  analogWrite(ENA1,vel);
  analogWrite(ENA2,vel2);
}
void Atras()
{
  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);
  digitalWrite (PinIN3, HIGH);
  digitalWrite (PinIN4, LOW);
  analogWrite(ENA1,vel);
  analogWrite(ENA2,vel2);
}
void Derecha()
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
  digitalWrite (PinIN3, HIGH);
  digitalWrite (PinIN4, LOW);
  analogWrite(ENA1,vel);
  analogWrite(ENA2,vel2);
}
void Izquierda()
{
  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, HIGH);
  analogWrite(ENA1,vel);
  analogWrite(ENA2,vel2);
}

void MotorStop()
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, LOW);
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, LOW);
}
