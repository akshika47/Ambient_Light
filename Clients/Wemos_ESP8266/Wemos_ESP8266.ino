#include <ESP8266WiFi.h>
#include <Adafruit_NeoPixel.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

/************************* WiFi Access Point *********************************/

char ssid[] = "Akshika's iPhone"; //SSID of your Wi-Fi router
char pass[] = "akshika47"; //Password of your Wi-Fi router

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "akshika47"
#define AIO_KEY         "95c18e999ffc4bf79c62ef42c812fcc7"


int delayval = 50; // delay for half a second

// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

/****************************** Feeds ***************************************/

// Setup a feed called 'onoff' for subscribing to changes.
Adafruit_MQTT_Subscribe onoffbutton = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/onoff");

void MQTT_connect();

int LED = D5;
Adafruit_NeoPixel ring = Adafruit_NeoPixel(12, LED , NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(115200);
  ring.begin();
  ring.setBrightness(250); //adjust brightness here
  ring.show(); //make the neo pixels show the configuration

  // Connect to Wi-Fi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to...");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Wi-Fi connected successfully");


  // Setup MQTT subscription for onoff feed.
  mqtt.subscribe(&onoffbutton);

}


void loop () {

  /*
     Ensure the connection to the MQTT server is alive (this will make the first
     connection and automatically reconnect when disconnected). See the MQTT_connect
     function definition further below.
  */
  MQTT_connect();

  // this is our 'wait for incoming subscription packets' busy subloop
  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(5000))) {
    if (subscription == &onoffbutton) {
      String str((char *)onoffbutton.lastread);
      if (str.equals("on"))
      {
        for (int j = 0; j < 12 ; j++) {
          for (int i = 0; i < 12; i++) {
            ring.setPixelColor(i, ring.Color(0, 255, 0)); // (moderately bright green color). Adafruit_NeoPixel.Color takes RGB values, from 0,0,0 up to 255,255,255
            ring.show(); // This sends the updated pixel color to the hardware.
            delay(delayval); // Delay for a period of time (in milliseconds).
          }

        }
      }
      if (str.equals("off"))
      {
        for (int i = 0; i < 12; i++) {
          ring.setPixelColor(i, ring.Color(0, 0, 0)); // (moderately bright blue color).
          ring.show(); // This sends the updated pixel color to the hardware.
        }

        Serial.print(F("Got: "));
        Serial.println((char *)onoffbutton.lastread);
      }
    }

  }

}
// Function to connect and reconnect as necessary to the MQTT server.
// Should be called in the loop function and it will take care if connecting.
void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 5 seconds...");
    mqtt.disconnect();
    delay(5000);  // wait 5 seconds
    retries--;
    if (retries == 0) {
      // basically die and wait for WDT to reset me
      while (1);
    }
  }
  Serial.println("MQTT Connected!");
}

