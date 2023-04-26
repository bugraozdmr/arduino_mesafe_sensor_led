int echo=10;
int trig=9;
long sure;
int uzaklik;
void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  //daha onceden trig_pin dolu ise low ile sifiladik
  digitalWrite(trig,LOW);
  delayMicroseconds(2); 
  digitalWrite(trig,HIGH);
  //sinyal hedefe ulassin diye bekledik
  delayMicroseconds(10); 
  //echopin su anda low aktiflecene kadar gecen sure hesaplancak(HIGH olana kadar)
  sure = pulseIn(echo,HIGH);
  uzaklik=sure/2/29.154;//29.154 bir birim sure
  Serial.print("mesafe:");
  Serial.println(uzaklik);
  Serial.print("sure:");
  Serial.println(sure);

  //lambalara donelim

  if(uzaklik>0 && uzaklik<7){
    digitalWrite(2,1);
    digitalWrite(3,0);
    digitalWrite(4,0);
    digitalWrite(5,0);
  }else if(uzaklik>7 && uzaklik<14){
    digitalWrite(2,0);
    digitalWrite(3,1);
    digitalWrite(4,0);
    digitalWrite(5,0);
  }else if(uzaklik>14 && uzaklik<21){
    digitalWrite(2,0);
    digitalWrite(3,0);
    digitalWrite(4,1);
    digitalWrite(5,0);
  }else{
    digitalWrite(2,0);
    digitalWrite(3,0);
    digitalWrite(4,0);
    digitalWrite(5,1);
  }
  delay(500);
}
