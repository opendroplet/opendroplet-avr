/*
 * 
 * Stores configuration in the EEPROM.
 * These values will stay in the EEPROM when the board is
 * turned off and may be retrieved later when booting the node.
 */

#include <EEPROM.h>

// Change these values according to your network setup:
static byte nodeID = 7; // range: 2-254
static byte uid[] = { 255, 242, 255, 255, 255, nodeID }; // choose a UID
static byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, nodeID }; // choose a unique MAC (optional, only if ethernet used)
static byte ip[] = { 192, 168, 8, nodeID }; // your subnet IP scheme (optional, only if ethernet used)
static byte gw[] = { 192, 168, 8, 1}; // your gateway (optional, only if ethernet used)


byte val[] = {nodeID, uid[0], uid[1], uid[2], uid[3], uid[4], uid[5], mac[0],mac[1],mac[2],mac[3],mac[4],mac[5],ip[0],ip[1],ip[2],ip[3],gw[0],gw[1],gw[2],gw[3]};

int addr=0;
void setup()
{
  SaveData();
}

void loop()
{
  delay(1337);
  
}

void SaveData(){
  while (addr < sizeof(val)){
  EEPROM.write(addr, val[addr]);
  // advance to the next address. 
  addr++;
    }
}
