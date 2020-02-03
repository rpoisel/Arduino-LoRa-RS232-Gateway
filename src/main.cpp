#include <Arduino.h>
#include <PacketSerial.h>
#include <RH_RF95.h>

static void onPacketReceived(const uint8_t* buffer, size_t size);

static PacketSerial packetSerial;
static uint32_t debugLed = LOW;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, debugLed);

  packetSerial.begin(115200);
  packetSerial.setPacketHandler(&onPacketReceived);
}

void loop()
{
  packetSerial.update();

  // Check for a receive buffer overflow (optional).
  if (packetSerial.overflow())
  {
    debugLed = (debugLed == LOW ? HIGH : LOW);
    digitalWrite(LED_BUILTIN, debugLed);
  }
}

static void onPacketReceived(const uint8_t* buffer, size_t size)
{
  (void)buffer;
  (void)size;
}
