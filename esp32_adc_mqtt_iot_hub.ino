#include <WiFi.h>
#include <PubSubClient.h>
#include <AzureIoTHub.h>

// Azure IoT Hub credentials
#define IOT_HUB_DEVICE_ID "<device_id>"
#define IOT_HUB_HOSTNAME "<iothub_hostname>"
#define IOT_HUB_DEVICE_KEY "<device_key>"
#define IOT_HUB_SAS_TOKEN "<sas_token>"

// WiFi credentials
const char* WIFI_SSID = "<wifi_ssid>";
const char* WIFI_PASSWORD = "<wifi_password>";

// ADC pin
const int ADC_PIN = 36;

// MQTT client
WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

// Azure IoT Hub client
AzureIoTHub iotHubClient(IOT_HUB_DEVICE_ID, IOT_HUB_HOSTNAME, IOT_HUB_DEVICE_KEY, IOT_HUB_SAS_TOKEN);

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Connect to Azure IoT Hub
  iotHubClient.begin(mqttClient);
  while (!iotHubClient.connect()) {
    delay(1000);
    Serial.println("Connecting to IoT Hub...");
  }
  Serial.println("Connected to IoT Hub");
}

void loop() {
  // Read ADC value
  int adcValue = analogRead(ADC_PIN);

  // Build JSON payload
  char payload[64];
  sprintf(payload, "{\"ADCValue\":%d}", adcValue);

  // Publish payload to Azure IoT Hub
  iotHubClient.sendEvent(payload);

  delay(1000);
}
