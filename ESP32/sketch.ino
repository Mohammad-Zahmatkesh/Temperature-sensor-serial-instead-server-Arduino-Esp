#include <DHT.h>
#include <WiFi.h>
#define DHTPIN 14    
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(115200);  
  dht.begin();           
  Serial.println("ESP32 Sensor Simulation Started! :)");
}

void loop() 
{
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) 
  {
    Serial.println("Failed to read from DHT sensor! :(");
  } 
  else 
  {
    Serial.print("Sending data to server: ");
    Serial.print("Temperature = ");
    Serial.print(temperature);
    Serial.print(" °C, Humidity = ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.println("POST /update HTTP/1.1");
    Serial.println("Host: example.com");
    Serial.println("Content-Type: application/x-www-form-urlencoded");
    Serial.print("Content-Length: ");
    String postData = "Temperature= " + String(temperature) + " °C" +"\n"+ "humidity= " + String(humidity) + " %";
    Serial.println(postData.length());
    Serial.println();
    Serial.println(postData);
  }
  delay(5000);
}
