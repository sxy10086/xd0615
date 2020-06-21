#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

#define S1 8
#define S2 9
#define S3 10
#define S4 11

#define LT 6
#define BT 7

void setup()
{
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  pinMode(S1, OUTPUT);//片选1
  pinMode(S2, OUTPUT);//片选2
  pinMode(S3, OUTPUT);//片选3
  pinMode(S4, OUTPUT);//片选4
  
  pinMode(LT,OUTPUT);//测试
  pinMode(BT,OUTPUT);//消隐

  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  digitalWrite(S1,HIGH);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  digitalWrite(S4,HIGH);
  Serial.begin(9600); 
}
void loop()
{
byte income=0;
if(Serial.available()>0)
  {
    digitalWrite(S4,LOW);
    income=Serial.read();
    income=income-'0';
    digitalWrite(IN1,income&0x1);
    digitalWrite(IN2,(income>>1)&0x1);
    digitalWrite(IN3,(income>>2)&0x1);
    digitalWrite(IN4,(income>>3)&0x1);
    digitalWrite(S1,HIGH);
    delay(10);
  }
}
	