// C++ codeint carroVermelho = 12;int carroVermelho = 12;

int carroVermelho = 12;
int carroAmarelo = 11;
int carroVerde = 10;
int pedVermelho = 7;
int pedVerde = 5;
int botao = 9;
int estado,estadoA;
bool piscaLed = 0;
unsigned long tempo, tSemafaro01, tempoatual;


void semafaro01();
void semafaro02();
void semafaro03();
void initBotao();


void setup (){
	pinMode(carroVermelho, OUTPUT);
	pinMode(carroAmarelo,OUTPUT);
	pinMode(carroVerde,OUTPUT);
	pinMode(pedVermelho,OUTPUT);
	pinMode(pedVerde,OUTPUT);
	pinMode(botao,INPUT_PULLUP);
	semafaro01();
}

void loop (){
  initBotao();
  if(estadoA==HIGH && ((millis() - tSemafaro01)> 5000)){
	semafaro02();
    estadoA=LOW;
  }else if (estado == HIGH){
  	estadoA = estado;
  }
}
void initBotao(){
  estado = digitalRead(botao);
  delay(10);
}
//condicao inicial do semafaro
void semafaro01(){
  tSemafaro01=millis();
  digitalWrite(carroVermelho, LOW);
  digitalWrite(carroAmarelo, LOW);
  digitalWrite(carroVerde, HIGH);
  digitalWrite(pedVermelho, HIGH);
  digitalWrite(pedVerde, LOW);
}
void semafaro02() {
  digitalWrite(carroVermelho, LOW);
  digitalWrite(carroAmarelo, HIGH);
  digitalWrite(carroVerde, LOW);
  digitalWrite(pedVermelho, HIGH);
  digitalWrite(pedVerde, LOW);
  delay(2000);
  digitalWrite(carroVermelho, HIGH);
  digitalWrite(carroAmarelo, LOW);
  delay(1000);
  digitalWrite(pedVermelho, LOW);
  digitalWrite(pedVerde, HIGH);
  delay(5000);
  semafaro03();
}

void semafaro03(){
  for (int x=0; x<10; x++) {
    digitalWrite(pedVerde, LOW);
    delay(160);
    digitalWrite(pedVerde, HIGH);
    delay(160);
  }
  digitalWrite(pedVermelho, HIGH);
  digitalWrite(pedVerde, LOW);
  delay(500);
  semafaro01();
  }
