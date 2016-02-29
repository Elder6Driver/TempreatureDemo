
int LM35 = A0;
int led = 13;

//从串口读取的内容放入cmd变量中，下面判断是否有写入，如果有写入则返回温度值
String cmd = "";

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);     

}

void loop() 
{
  // put your main code here, to run repeatedly:
  
  //如果串口获取了指令，那么使用cmd记录这个指令
  while ( Serial.available()) 
  {
    cmd += char(Serial.read());
    delay(2);
  }

  //如果指令正确，那么测试温度并串口返回
  if ( cmd == "+tempreature")
  {
    // 读取传感器模拟值，并计算出当前温度
    float temp = (5.0 * analogRead(LM35) * 100.0) / 1024;
    // 将温度输出至串口显示
    Serial.print("Arduino UNO,Tempreature,");
    Serial.println(temp);
    //亮灯提醒串口返回消息
    digitalWrite(led, HIGH);  
    delay(200);
    digitalWrite(led, LOW);   
    delay(200);
    cmd = "";
  }

}
