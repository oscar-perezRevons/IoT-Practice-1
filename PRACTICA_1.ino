int DISTANCIA = 0;
int pinEco = 18;
int pinLed=1;
int pinGatillo = 19;
class LED
{
  private:
    int numero;
  public:
    int getnumero()
    {
      return numero;
    }
    void setnumero(int n)
    {
      numero=n;
    }
    LED(int n)
    {
      numero=n;
    }
    void encender(){
      digitalWrite(numero, HIGH);
    }

    void apagar() {
      digitalWrite(numero, LOW);
    }
};
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  //Iniciamos el pin del emisor de reuido en salida
  pinMode(triggerPin, OUTPUT);
  //Apagamos el emisor de sonido
  digitalWrite(triggerPin, LOW);
  //Retrasamos la emision de sonido por 2 milesismas de segundo
  delayMicroseconds(2);
  // Comenzamos a emitir sonido
  digitalWrite(triggerPin, HIGH);
  //Retrasamos la emision de sonido por 2 milesismas de segundo
  delayMicroseconds(10);
  //Apagamos el emisor de sonido
  digitalWrite(triggerPin, LOW);
  //Comenzamos a escuchar el sonido
  pinMode(echoPin, INPUT);
  // Calculamos el tiempo que tardo en regresar el sonido
  return pulseIn(echoPin, HIGH);
}
LED L1(1);

void setup() {
  
  //Configuramos el pin del led como salida
  
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  //Calculamos la distancia en cm
  DISTANCIA = 0.01723 * readUltrasonicDistance(pinGatillo, pinEco);
  //Mostramos la disstancia
   L1.setnumero(0);
  //Si la distancia es menor a 20 encendemos el led
  while(L1.getnumero()!=3)
    {
        L1.setnumero(L1.getnumero()+1);
        if (DISTANCIA > 0 && DISTANCIA <= 10 && L1.getnumero() == 3) { continue; }
        if (DISTANCIA > 10 && DISTANCIA <= 20 && L1.getnumero() == 2) { continue; }
        if (DISTANCIA > 20 && DISTANCIA <= 30 && L1.getnumero() == 1) { continue; }
        L1.encender();
        //digitalWrite(i, HIGH);
        delay(230);
        //digitalWrite(i, LOW);
        L1.apagar();
    }
  delay(100);
}
