// demo: CAN-BUS Shield, send data
#include <mcp_can.h>
#include <SPI.h>

static const int spiClk = 10000000; // 10 MHz
SPIClass hspi(HSPI);

MCP_CAN CAN0(15, &hspi);                           // Set CS to pin 15

void setup()
{
  Serial.begin(115200);
  Serial.println("Initializing SPI...");
  hspi.begin(spiClk);
  ///hspi.beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
  // init can bus, baudrate: 500k
  Serial.println("Initializing CAN...");
  if(CAN0.begin(CAN_500KBPS) == CAN_OK) Serial.println("can init ok!!\r\n");
  else Serial.println("Can init fail!!\r\n");
  pinMode(4, INPUT);
}

unsigned char stmp[8] = {0, 1, 2, 3, 4, 5, 6, 7};
void loop()
{
  // send data:  id = 0x00, standrad flame, data len = 8, stmp: data buf
  Serial.println("Sending...");
  CAN0.sendMsgBuf(0x00, 0, 8, stmp);  
  delay(1000);                       // send data per 100ms
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
