// demo: CAN-BUS Shield, receive data
#include <mcp_can.h>
#include <SPI.h>

long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[8];

SPIClass vspi(VSPI);

MCP_CAN CAN0(5, &vspi);                             // Set CS to pin 5

bool led_on = false;

bool data_available() {
  return CAN0.checkReceive() == CAN_MSGAVAIL;
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Initializing SPI...");
  vspi.begin();
  Serial.println("Initializing CAN...");
  if(CAN0.begin(CAN_500KBPS) == CAN_OK) Serial.println("can init ok!!\r\n");
  else Serial.println("Can init fail!!\r\n");
  pinMode(4, INPUT);                            // Setting pin 4 for /INT input
  Serial.println("MCP2515 Library Receive Example...");
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    //if(!digitalRead(4))                         // If pin 4 is low, read receive buffer
    if(data_available())
    {
      CAN0.readMsgBuf(&len, rxBuf);              // Read data: len = data length, buf = data byte(s)
      rxId = CAN0.getCanId();                    // Get message ID
      Serial.print("ID: ");
      Serial.print(rxId, HEX);
      Serial.print("  Data: ");
      for(int i = 0; i<len; i++)                // Print each byte of the data
      {
        if(rxBuf[i] < 0x10)                     // If data byte is less than 0x10, add a leading zero
        {
          Serial.print("0");
        }
        Serial.print(rxBuf[i], HEX);
        Serial.print(" ");
      }
      Serial.println();

      digitalWrite(LED_BUILTIN, led_on);
      led_on = !led_on;
    }
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
