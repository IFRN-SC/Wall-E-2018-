#include <ros.h>
#include <std_msgs/Int16MultiArray.h>
#include "Estrategia.h"
#include <byakugan/BoolStamped.h>

byakugan::BoolStamped dataInit;
ros::Publisher pubInit("initFind", &dataInit);

ros::NodeHandle nh;

void motoresCb(const std_msgs::Int16MultiArray &motores){
  robo.acionarMotores(motores.data[0], motores.data[1]);
}
ros::Subscriber<std_msgs::Int16MultiArray> subMotores("ctrl_motores", &motoresCb);

int lastValue0 = 0;
int lastValue1 = 0;

void garraCb(const std_msgs::Int16MultiArray &garra){
  robo.acionarServoGarra1(garra.data[0]);
  robo.acionarServoGarra2(garra.data[1]);

  if ((garra.data[0] - lastValue0) > 0) {
    robo.ligarLed(1);
  } else {
    robo.desligarLed(1);
  }

  lastValue0 = garra.data[0];

  if ((garra.data[1] - lastValue1) > 0) {
    robo.ligarLed(2);
  } else {
    robo.desligarLed(2);
  }

  lastValue1 = garra.data[1];
}

ros::Subscriber<std_msgs::Int16MultiArray> subGarras("ctrl_garras", &garraCb);

Estrategia estrategia;

void setup(){
  nh.getHardware()->setBaud(115200);
  nh.initNode();

  nh.subscribe(subMotores);
  nh.subscribe(subGarras);

  nh.advertise(pubInit);
  
  Serial.begin(9600);
  robo.configurar(true);
  robo.habilitaTCS34();
  estrategia.calibrar();
  estrategia.verificar();
}

void loop(){
  if (estrategia.isSala3()) {
    dataInit.existe.data = true;  
    pubInit.publish(&dataInit);
  } else {
    dataInit.existe.data = true;  
    pubInit.publish(&dataInit);  
    estrategia.executar();
  }
  nh.spinOnce();
}                                
                                                                                                               

//angelo.reset(obr2020, true);**-123

 
