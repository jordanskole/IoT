// This #include statement was automatically added by the Particle IDE.
#include "SparkFun_Photon_Weather_Shield_Library/SparkFun_Photon_Weather_Shield_Library.h"

char Org[] = "jordans_particle";
char Disp[] = "Jordans Particle";
char Locn[] = "WSU Detroit, MI";

//Create Instance of HTU21D or SI7021 temp and humidity sensor and MPL3115A2 barrometric sensor
Weather sensor;

void setup()

{

  Serial.begin(9600);

 //Initialize the I2C sensors and ping them
 sensor.begin();

 /*You can only receive acurate barrometric readings or acurate altitiude
 readings at a given time, not both at the same time. The following two lines
 tell the sensor what mode to use. You could easily write a function that
 takes a reading in one made and then switches to the other mode to grab that
 reading, resulting in data that contains both acurate altitude and barrometric
 readings. For this example, we will only be using the barometer mode. Be sure
 to only uncomment one line at a time. */

 sensor.setModeBarometer();//Set to Barometer Mode

 //baro.setModeAltimeter();//Set to altimeter Mode
 //These are additional MPL3115A2 functions the MUST be called for the sensor to work.
 sensor.setOversampleRate(7); // Set Oversample rate
 //Call with a rate from 0 to 7. See page 33 for table of ratios.
 //Sets the over sample rate. Datasheet calls for 128 but you can set it
 //from 1 to 128 samples. The higher the oversample rate the greater
 //the time between data samples.

  delay(10000);
}

void loop()

{

 // Measure Temperature from the HTU21D or Si7021
 // It is faster, therefore, to read it from previous RH
 // measurement with getTemp() instead with readTemp()

 float f = sensor.getTempF();

 char payload[255];

 snprintf(payload, sizeof(payload), "{
   \"s\":\"wthr\",
   \"u\":\"F\",
   \"l\":\"%s\",
   \"m\":\"Temperature\",
   \"o\":\"%s\",
   \"v\": %f,
   \"d\":\"%s\"
 }", Locn, Org, f, Disp);

 Serial.println(payload);
 Spark.publish("WeatherDweet", payload);

 delay(60000);

}
