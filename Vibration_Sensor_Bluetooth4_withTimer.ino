const int LED=13;
int rsvData = 0;
int sensorVal = 0;
unsigned long time;

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  time = millis();
  
  // 受信処理
if(Serial.available() > 0){
  rsvData = Serial.read();
  if(rsvData == 1){ 
    digitalWrite(LED, HIGH);
  }else if(rsvData == 0){
    digitalWrite(LED, LOW);
  } 
} 
//センサー読み取り～送信
sensorVal = analogRead(0);
sensorVal = sensorVal>>2; //10bit->8bit値

String stringVal = String(sensorVal);
String stringTime = String(time);
//Serial.write(sensorVal);
Serial.println(stringVal + "," + stringTime);

//ウェイト

delay(100);
}
