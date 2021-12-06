/////////////////////Datos GPS
String str = "";
const char separator = ',';
const int dataLength = 3;
long data[dataLength];

int distanceToTarget;


float targetLat = 3329204;
float targetLong = -782174011;

#define WAYPOINT_DIST_TOLERANE  3
/////////////////////////////////////

int PinIN1 = 7;
int PinIN2 = 6;
int PinIN3 = 8;
int PinIN4 = 9;
int ENA1=10;
int ENA2=5;
int vel=215;
int vel2=153;
int action;
///////////////////////////////////////////
int contador=0;
////////////////////////////////////////////
const int trigPin1 = A7;
const int echoPin1 = A6;

long duration1;
int distance1;
///////////////////////////////////////////
void setup() {
  Serial.begin(115200);
  // ///////////////////////////////////MOTORES
  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);
  pinMode(PinIN3, OUTPUT);
  pinMode(PinIN4, OUTPUT);
  pinMode (ENA1, OUTPUT);
  pinMode (ENA2, OUTPUT);

//////////////////////////////////////////HALL
  pinMode(A1, INPUT);

  pinMode(trigPin1, OUTPUT); 
  pinMode(echoPin1, INPUT); 
}

void loop() {

//datosGPS();
distanceToWaypoint();
//Serial.println(distanceToTarget);

          
if (Serial.available() > 0) {
 action = Serial.parseInt(); 
}

 if(action==8){
  Adelante();
  }
if(action==2){
  Atras();
  }
if(action==4){
  Izquierda();
  }
if(action==6){
  Derecha();
  }
if(action==0){
  MotorStop();
  }

  /////////////////////////////////////////////////HALL

  
////Serial.println(action);
//
//int val = digitalRead(A1);
//  if(val == LOW)
//  {
//    contador++;
//    delay(200);
//    Serial.println(contador);
//  }
///////////////////////////////////////////////////ULTRASONICOS


//// Clears the trigPin
//digitalWrite(trigPin1, LOW);
//delayMicroseconds(2);
//// Sets the trigPin on HIGH state for 10 micro seconds
//digitalWrite(trigPin1, HIGH);
//delayMicroseconds(10);
//digitalWrite(trigPin1, LOW);
//// Reads the echoPin, returns the sound wave travel time in microseconds
//duration1 = pulseIn(echoPin1, HIGH);
//// Calculating the distance
//distance1= duration1*0.034/2;
//// Prints the distance on the Serial Monitor
//Serial.print("Distance1: ");
//Serial.println(distance1);





  
}



void Adelante()
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, HIGH);
  analogWrite(ENA1,vel2);
  analogWrite(ENA2,vel);
  //Serial.println("Adelante");
}
void Atras()
{

  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);
  digitalWrite (PinIN3, HIGH);
  digitalWrite (PinIN4, LOW);
  analogWrite(ENA1,vel2);
  analogWrite(ENA2,vel);
  //Serial.println("Atras");
}
void Izquierda()
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
  digitalWrite (PinIN3, HIGH);
  digitalWrite (PinIN4, LOW);
  analogWrite(ENA1,vel2);
  analogWrite(ENA2,vel);
  //Serial.println("Izquierda");
}
void Derecha()
{
  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, HIGH);
  analogWrite(ENA1,vel2);
  analogWrite(ENA2,vel);
  //Serial.println("Derecha");
}

void MotorStop()
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, LOW);
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, LOW);
  //Serial.println("Stop");
}

///////////////////////////////////////
void distanceToWaypoint()
{
  float delta = radians(data[1] - targetLong);
  float sdlong = sin(delta);
  float cdlong = cos(delta);
  float lat1 = radians(data[0]);
  float lat2 = radians(targetLat);
  float slat1 = sin(lat1);
  float clat1 = cos(lat1);
  float slat2 = sin(lat2);
  float clat2 = cos(lat2);
  delta = (clat1 * slat2) - (slat1 * clat2 * cdlong);
  delta = sq(delta);
  delta += sq(clat2 * sdlong);
  delta = sqrt(delta);
  float denom = (slat1 * slat2) + (clat1 * clat2 * cdlong);
  delta = atan2(delta, denom);
  distanceToTarget =  delta * 6372795;
  //Serial.println(distanceToTarget);

  // check to see if we have reached the current waypoint
//  if (distanceToTarget <= WAYPOINT_DIST_TOLERANE-1)
//  {
// //   berhenti();
//    //delay(stopwaypoint*1000);
//  //  nextWaypoint();
//  }
}
/////////////////////////////// Separar datos GPS
void datosGPS(){
  if (Serial.available())
   {
      str = Serial.readStringUntil('\n');
      for (int i = 0; i < dataLength ; i++)
      {
         int index = str.indexOf(separator);
         data[i] = str.substring(0, index).toInt();
         str = str.substring(index + 1);
        // delay(15);
      }
      
     Serial.print("Latitud: ");
     Serial.println(data[0]);
     Serial.print("Longitud: ");
     Serial.println(data[1]);
   //  Serial.print("Distancia: ");
//Serial.println(distanceToTarget);

   }
  }
