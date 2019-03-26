// demo: CAN-BUS Shield, send data
#include <mcp_can.h>
#include <SPI.h>

static const int spiClk = 1000000; // 1 MHz
SPIClass vspi(VSPI);

MCP_CAN CAN0(5, vspi);                           // Set CS to pin 5

void setup()
{
  Serial.begin(115200);
  Serial.print("Initializing SPI...");
  vspi.begin();
  ///hspi.beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
  // init can bus, baudrate: 500k
  Serial.print("Initializing CAN...");
  if(CAN0.begin(CAN_500KBPS) == CAN_OK) Serial.print("can init ok!!\r\n");
  else Serial.print("Can init fail!!\r\n");
  pinMode(4, INPUT);
}

unsigned char stmp[8] = {0, 1, 2, 3, 4, 5, 6, 7};
void loop()
{
  // send data:  id = 0x00, standrad flame, data len = 8, stmp: data buf
  CAN0.sendMsgBuf(0x00, 0, 8, stmp);  
  delay(1000);                       // send data per 100ms
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
