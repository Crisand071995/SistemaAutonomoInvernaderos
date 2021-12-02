String str = "";
const char separator = ',';
const int dataLength = 3;
float pos0[dataLength];
///////////////////////////////////////////////////////////////////////////////////////////////////////////

float waypoint1[3][2]={{0.333938, -78.125792},
                        {0.334093, -78.125809},     //WayPoints analizados
                        {0.334272, -78.125808}};
float distancias[3]={0,0,0};    //Distancias de referencia para ubicacion actual
float distanciaref=0;
float tolerancia=1;
void setup() {

Serial.begin(115200);
}

void loop() {
  //Adquisicion de datos cada 1 segundo
   datosGPS();
   medidas();
 delay(1000);

  
}

//Funcion de Calculo de distancia entre punto actual y punto destino 
float calc_dist(float flat1, float flon1, float flat2, float flon2)
{
float dist_calc=0;
float dist_calc2=0;
float diflat=0;
float diflon=0;


diflat=radians(flat2-flat1);
flat1=radians(flat1);
flat2=radians(flat2);
diflon=radians((flon2)-(flon1));

dist_calc = (sin(diflat/2.0)*sin(diflat/2.0));
dist_calc2= cos(flat1);
dist_calc2*=cos(flat2);
dist_calc2*=sin(diflon/2.0);
dist_calc2*=sin(diflon/2.0);
dist_calc +=dist_calc2;

dist_calc=(2*atan2(sqrt(dist_calc),sqrt(1.0-dist_calc)));

dist_calc*=6371000.0; //Convertir a metros
//Serial.print("Distancia al WayPoint: ");
//Serial.println(dist_calc);
distanciaref=dist_calc;
delay(200);
//return dist_calc;
}
//Funcion de calculo de pendiente para orientacion del dispositivo
void medidas(){
  for(int c=0;c<=3;c++){
    
  calc_dist(pos0[0], pos0[1], waypoint1[c][0], waypoint1[c][1]);
  distancias[c]=distanciaref;
   }
   Serial.println(distancias[0]);
   Serial.println(distancias[1]);
   Serial.println(distancias[2]);
   Serial.println("///////////////////////////////////////////");

   float pendiente=((-78.125792-(pos0[0]))/(0.333938-(pos0[1])));
    Serial.println(pendiente);
    Serial.println("///////////////////////////////////////////");
  }
//Funcion de lectura del modulo GPS
void datosGPS(){
  if (Serial.available())
   {
      str = Serial.readStringUntil('\n');
      for (int i = 0; i < dataLength ; i++)
      {
         int index = str.indexOf(separator);
         pos0[i] = str.substring(0, index).toInt();
         str = str.substring(index + 1);
        // delay(15);
      }
      pos0[0]=pos0[0]/10000000;
      pos0[1]=pos0[1]/10000000;
//     Serial.print("Latitud Actual: ");
//     Serial.println(pos0[0],7);
//     Serial.print("Longitud Actual: ");
//     Serial.println(pos0[1],7);
      }
  }
