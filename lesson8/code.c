
*/

// 定义一个数字数组去追踪
// 越大的数字将被越平滑处理，但是会减慢输出对输入的反应
// 用constant变量去决定数组索引的大小
// 
const int numReadings = 10;

int readings[numReadings];      // 模拟输入变量readings
int readIndex = 0;              // 设置索引下标
int total = 0;                  // 运行次数
int average = 0;                // 平均值
int inputPin = A0;

void setup() {
  // 初始化串口通信
  Serial.begin(9600);
  // 初始化所有的变量readings:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) //循环十次{
    readings[thisReading] = 0;
  }
}

void loop() {
  // 减去最近一次输入
  total = total - readings[readIndex];
  // 从传感器读取:
  readings[readIndex] = analogRead(inputPin);
  // 将最近一次读取添加到total计数:
  total = total + readings[readIndex];
  // 索引值加一位:
  readIndex = readIndex + 1;

  // 进行判断，如果在数组的末端则跳回到开始
  if (readIndex >= numReadings) {
    readIndex = 0;
  }

  //计算平均值:
  average = total / numReadings;
  // 转为ASCII码数字加到电脑
  Serial.println(average);
  delay(1);        //延时以稳定
}