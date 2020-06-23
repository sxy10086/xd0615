int n=0;
int pinInterrupt = 9; //接中断信号的脚
void onChange()
{
  n=0;
  digitalWrite(8,LOW);
  n=n-'0';
  digitalWrite(2,n&0x1);
  digitalWrite(3,(n>>1)&0x1);
  digitalWrite(4,(n>>2)&0x1);
  digitalWrite(5,(n>>3)&0x1);
  digitalWrite(8,HIGH);
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
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  pinMode( pinInterrupt, INPUT);//设置管脚为输入
   
   //Enable中断管脚, 中断服务程序为onChange(), 监视引脚变化
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), onChange, CHANGE);
}
 
void loop()
{
  n=1;
  digitalWrite(8,LOW);
  n=n-'0';
  digitalWrite(2,n&0x1);
  digitalWrite(3,(n>>1)&0x1);
  digitalWrite(4,(n>>2)&0x1);
  digitalWrite(5,(n>>3)&0x1);
  digitalWrite(8,HIGH);
  delay(1000);
  if (n==9)
  {
    n=0;
  }
  else
  {
    n=n+1;
  }
 
}