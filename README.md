# PROTOCOL_adc_mqtt_azure-iot
esp32 code to read adc data and send data to Azure iot hub


In this code, you need to replace the following placeholders with your actual credentials:

<device_id>: The ID of your IoT device.

<iothub_hostname>: The hostname of your IoT Hub.

<device_key>: The primary key of your IoT device.

<sas_token>: The shared access signature (SAS) token of your IoT device.

<wifi_ssid>: The SSID of your WiFi network.

<wifi_password>: The password of your WiFi network.


The code starts by connecting to WiFi using the WiFi.begin() function. It then connects to the IoT Hub using the AzureIoTHub class from the AzureIoTHub library and the PubSubClient library. The AzureIoTHub class provides a simple API for sending data to an Azure IoT Hub using the MQTT protocol. The PubSubClient library provides the MQTT client implementation.

In the loop() function, the code reads the ADC value using the analogRead() function, builds a JSON payload containing the ADC value, and sends the payload to the IoT Hub using the AzureIoTHub::sendEvent() function. The code then waits for one second before repeating the loop.

Note that you need to set up an Azure IoT Hub and register a device with the hub before you can use this code. You can find more information on how to do this in the Azure documentation.





