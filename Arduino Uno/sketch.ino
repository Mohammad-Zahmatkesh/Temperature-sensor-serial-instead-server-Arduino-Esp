#include <DHT.h>
#define DHTPIN 5    
#define DHTTYPE DHT22  
DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(115200);
  dht.begin();          
  Serial.println("DHT22 Sensor Simulation Started!");
}

void loop() 
{
  float temperature = dht.readTemperature();

  if (isnan(temperature))
   {
    Serial.println("Failed to read temperature from DHT sensor!");
    } 
    else
    {
    Serial.print("Sending data to server: ");
    Serial.print("Temperature = ");
    Serial.print(temperature);
    Serial.print(" °C ");
  
    Serial.println("POST /update HTTP/1.1");
    Serial.println("Host: mamad.Z.com");
    Serial.println("Content-Type: application/mamad-www-form-urlencoded");
    Serial.print("Content-Length: ");
    String postData = "temp=" + String(temperature) + " °C "; 
    Serial.println(postData.length());
    Serial.println();
    Serial.println(postData);
  }
  delay(7000); 
}

