int PinIN1 = 7;
int PinIN2 = 6;
int PinIN3 = 8;
int PinIN4 = 9;
int ENA1=10;
int ENA2=5;
int vel=180;
int vel2=130;
int action;

void setup() {
  // Inicializacion de pines de motor
  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);
  pinMode(PinIN3, OUTPUT);
  pinMode(PinIN4, OUTPUT);

  pinMode (ENA1, OUTPUT);
  pinMode (ENA2, OUTPUT);
  
}

void loop() {
  // funcion a ejecutarse para calibracion
Adelante();


}

///FUNCIONES DE MOVIMIENTO
void Adelante()
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, HIGH);
  analogWrite(ENA1,vel2);
  analogWrite(ENA2,vel);
}
void Atras()
{
  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);
  digitalWrite (PinIN3, HIGH);
  digitalWrite (PinIN4, LOW);
  analogWrite(ENA1,vel2);
  analogWrite(ENA2,vel);
}
void Izquierda()
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
  digitalWrite (PinIN3, HIGH);
  digitalWrite (PinIN4, LOW);
  analogWrite(ENA1,vel2);
  analogWrite(ENA2,vel);
}
void Derecha()
{
  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, HIGH);
  analogWrite(ENA1,vel2);
  analogWrite(ENA2,vel);
}

void MotorStop()
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, LOW);
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, LOW);
}
