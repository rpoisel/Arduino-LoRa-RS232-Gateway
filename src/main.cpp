#include <Arduino.h>
#include <PacketSerial.h>
#include <RH_RF95.h>

constexpr uint8_t const RFM95_CS = 8;
constexpr uint8_t const RFM95_INT = 4;

static void onPacketReceived(const uint8_t* buffer, size_t size);

static PacketSerial packetSerial;
static uint32_t debugLed = LOW;
static RH_RF95 rf95(RFM95_CS, RFM95_INT);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, debugLed);

  packetSerial.begin(115200);
  packetSerial.setPacketHandler(&onPacketReceived);

  while (!rf95.init())
  {
  }
  if (!rf95.setFrequency(868.0))
  {
  }
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

  // check whether LoRa paket has been received
  // in case: forward via packetSerial
}

static void onPacketReceived(const uint8_t* buffer, size_t size)
{
  (void)buffer;
  (void)size;

  // send via LoRa
}
