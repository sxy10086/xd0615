int n=0;
byte n1=0;

int pinInterrupt = 13; //接中断信号的脚
void onchange()
  
{
  if ( digitalRead(pinInterrupt) == LOW )
    Serial.println("Key Down");
  	n=0;
    digitalWrite(8,LOW);
    n1=n-'0';
    digitalWrite(2,n1&0x1);
    digitalWrite(3,(n1>>1)&0x1);
    digitalWrite(4,(n1>>2)&0x1);
    digitalWrite(5,(n1>>3)&0x1);
    digitalWrite(8,HIGH);

  else
      Serial.println("Key UP");

  
}
 
void setup()
{
  Serial.begin(9600); //初始化串口

  pinMode(2, OUTPUT);//输入1
  pinMode(3, OUTPUT);//输入2
  pinMode(4, OUTPUT);//输入3
  pinMode(5, OUTPUT);//输入4
  pinMode(8, OUTPUT);//片选1
  pinMode(6, OUTPUT);//片选2
  pinMode(7, OUTPUT);//片选3
  pinMode( pinInterrupt, INPUT);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), onChange, CHANGE);
}
 
void loop()
{
  digitalWrite(8,LOW);
  n1=n-'0';
  digitalWrite(2,n1&0x1);
  digitalWrite(3,(n1>>1)&0x1);
  digitalWrite(4,(n1>>2)&0x1);
  digitalWrite(5,(n1>>3)&0x1);
  digitalWrite(8,HIGH);
  if(n==9)
    n=0;
  else
    n=n+1;
  delay(1000);
 }
