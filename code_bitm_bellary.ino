#define BLYNK_TEMPLATE_ID "TMPL3qFPntV1Q"
#define BLYNK_TEMPLATE_NAME "spy robot"
#define BLYNK_AUTH_TOKEN "7nFWfAG6KnEUGtSWuIMGukLiJlyxUaiC"
 
// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
 
 
char auth[] = BLYNK_AUTH_TOKEN; 
 
// Your WiFi credentials.
// Set password to "" for open networks.

char ssid[] = "moto";
char pass[] = "12345678";

BlynkTimer timer;

 
int fw1=33;
int bw1=32;
int fw2=5;
int bw2=2;
 
int metalsensor = 4;
 
int metalval;
 
 
void metalprox()
{
  metalval=digitalRead(metalsensor);
  if(metalval==1)
  {
    Blynk.virtualWrite(V6,"Metal detected");
      
    }
   else
   {
    Blynk.virtualWrite(V6,"No Metal detected");
    } 
  }    
void setup() 
{
  // put your setup code here, to run once:
Serial.begin(9600);

   WiFi.begin(ssid, pass);
   
  int wifi_ctr = 0;
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }
  Serial.println("WiFi connected");
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

pinMode(fw1,OUTPUT);
pinMode(bw1,OUTPUT);
pinMode(fw2,OUTPUT);
pinMode(bw2,OUTPUT);
 
pinMode(metalsensor,INPUT);
timer.setInterval(2000L, metalprox); 
 
 }
 

void loop() {
  // put your main code here, to run repeatedly:
Blynk.run();
timer.run();
}

BLYNK_WRITE(V1)
{
  int pinstate1=param.asInt();
  if(pinstate1==1)
  {
    digitalWrite(fw1,HIGH);
    digitalWrite(fw2,HIGH);
    digitalWrite(bw1,LOW);
  digitalWrite(bw2,LOW);
  }
  else
   
 {
    digitalWrite(fw1,LOW);
    digitalWrite(fw2,LOW);
    digitalWrite(bw1,LOW);
  digitalWrite(bw2,LOW);
  }
}

 BLYNK_WRITE(V2)
{
  int pinstate2=param.asInt();
  if(pinstate2==1)
  {
    digitalWrite(fw1,LOW);
    digitalWrite(fw2,LOW);
    digitalWrite(bw1,HIGH);
  digitalWrite(bw2,HIGH);
  }
  else
  { 
    digitalWrite(fw1,LOW);
    digitalWrite(fw2,LOW);
    digitalWrite(bw1,LOW);
    digitalWrite(bw2,LOW);
  }
}

 BLYNK_WRITE(V3)
{
  int pinstate3=param.asInt();
  if(pinstate3==1)
  {
    digitalWrite(fw1,HIGH);
    digitalWrite(fw2,LOW);
    digitalWrite(bw1,LOW);
  digitalWrite(bw2,HIGH);
  }
  else
  { 
    digitalWrite(fw1,LOW);
    digitalWrite(fw2,LOW);
    digitalWrite(bw1,LOW);
    digitalWrite(bw2,LOW);
  }
}

 
BLYNK_WRITE(V4)
{
  int pinstate9=param.asInt();
  if(pinstate9==1)
  {
    digitalWrite(fw1,LOW);
    digitalWrite(fw2,HIGH);
    digitalWrite(bw1,HIGH);
  digitalWrite(bw2,LOW);
  }
  else
   
 {
    digitalWrite(fw1,LOW);
    digitalWrite(fw2,LOW);
    digitalWrite(bw1,LOW);
  digitalWrite(bw2,LOW);
  }
}

 
