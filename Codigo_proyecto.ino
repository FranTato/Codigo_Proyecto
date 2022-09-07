const int Trigger = 12;//PIN usado para trigger
const int Echo = 11;//PIN usado para echo
const int Buzzer = 10;//PIN usado para buzzer

const float sonido = 34300.0;// Velocidad del sonido en cm/s
// limites 

const int umbral1 = 100;
const int umbral2 = 90;
const int umbral3 = 80;
const int umbral4 = 70;
const int umbral5 = 60;
const int umbral6 = 50;
const int umbral7 = 40;
const int umbral8 = 30;
const int umbral9 = 20;
const int umbral10 = 10;

 
void setup() {
  
  Serial.begin(9600);//Incializamos la comunicación
 
  
  pinMode(Trigger, OUTPUT);//Declaramos a trigger de tipo Salida (emisor)
  pinMode(Buzzer, OUTPUT);//Declaramos al buzzer de tipo salida
  pinMode(Echo, INPUT);//Declaramos al Echo de tipo entrada
  
  digitalWrite(Trigger, LOW);//Inicializamos el sensor en cero (apagado)

}
 
void loop() {
   
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10); 
  digitalWrite(Trigger, LOW);
 
    unsigned long tiempo = pulseIn(Echo, HIGH);// La función pulseIn obtiene el tiempo que tarda en cambiar entre estados, en este caso a HIGH
  
  // Obtenemos la distancia en cm, hay que convertir el tiempo en segudos ya que está en microsegundos
  // por eso se multiplica por 0.000001
  float distancia = tiempo * 0.000001 * sonido / 2.0;
  Serial.print(distancia);
  Serial.println(" cm");
 
//Agregamos un IF para validar, si se detecta algo o alguien a una distancia menor a 100cm
    if (distancia < umbral1)
   {
    
    if (distancia >= umbral2)
    {
      
      tone(Buzzer, 2000, 200);
      delay(1000); 
      
    }
    else if (distancia < umbral2 && distancia > umbral3)
    {
    
      tone(Buzzer, 2000, 200);
      delay(900);
    }
    else if (distancia < umbral3 && distancia > umbral4)
    { 
       tone(Buzzer,2000,200);
       delay(800);
      
    }
      
    else if (distancia < umbral4 && distancia > umbral5)
    {
      tone(Buzzer,2000,200);
      delay(700);
    }
      
    else if (distancia < umbral5 && distancia > umbral6)
    {
      tone(Buzzer,2000,200);
      delay(600);
    }
    else if (distancia < umbral6 && distancia > umbral7)
    {
      tone(Buzzer,2000,200);
      delay(500);
    }
     else if (distancia < umbral7 && distancia > umbral8)
    {
      tone(Buzzer,2000,200);
      delay(400);
    }
     else if (distancia < umbral8 && distancia > umbral9)
    {
      tone(Buzzer,2000,200);
      delay(300);
    }
    
      else if (distancia < umbral9 && distancia > umbral10)
    {
      tone(Buzzer,2000,200);
      delay(200);
    }
    else if (distancia <= umbral10)
    {
      
      tone(Buzzer, 2000, 200);
      delay(100); 
      
    }
  }
 
}
