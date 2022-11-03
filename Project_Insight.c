int esq = A1, dir = A3, mei = A5, Ddir = 0, Desq = 0, Dmei = 0, eesq=A0, edir=A2, emei=A4;
int ledMei = 13, ledDir = 11, ledEsq = 12;

int ledOn(int ledPin)
{
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  delay(200);
  
  digitalWrite(ledPin, LOW);
}


//caso o sensor tiver apenas 3 pinos use trigger e echo como o mesmo pin
long ultraRead(int trigger, int echo)
{
  int Dcm = 0;//
  
  pinMode(trigger, OUTPUT); //limpa o trigger
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigger, HIGH);//manda o sinal por 10ms
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
  
  pinMode(echo, INPUT);//liga o echo para receber o sinal da onda
  //le o tempo ate a onda chegar no sensor em (ms), e faz o calculo do tempo em (cm)
  Dcm = pulseIn(echo, HIGH) * 0.01723;
    
  return Dcm;//retorna a distancia do objeto ate o sensor em (cm)
}
  
void setup()
{
  pinMode(dir, INPUT);
  pinMode(mei, INPUT);
  pinMode(esq, INPUT);
  
  Serial.begin(9600);

}

void loop()
{
  //para calcular a distancia em (cm) multiplique o tempo por 0.01723
  Desq = ultraRead(esq, eesq);
  Serial.print("dist esquerda: ");
  Serial.println(Desq);
  
 /* Dmei = ultraRead(mei, emei);
  Serial.print("dist meio: ");
  Serial.println(Dmei);*/
  
  Ddir = ultraRead(dir, edir);
  Serial.print("dist direita: ");
  Serial.println(Ddir);
  
  Serial.println();
  
  
  
  if(Desq < 50){
    ledOn(ledEsq);
  }
  
 /* if(Dmei < 100){
    ledOn(ledMei);
  }*/
  
  if(Ddir < 50){
    ledOn(ledDir);
  }
  
  
  
  
  delay(500);
  
  
  
  
}
