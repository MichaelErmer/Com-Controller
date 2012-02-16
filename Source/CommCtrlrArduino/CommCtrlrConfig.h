#ifndef CommCtrlrConfig_h
#define CommCtrlrConfig_h

#define __WHITESTARBALLOON__


#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif


/*
Global Configuration Information
*/
#define IRIDIUM_SERIAL_PORT Serial1
#define CUTDOWN_SERIAL_PORT Serial2

/*******************************
 *    Pin declarations         *
 *******************************/
const int sat_sa = 3;                              // Satellite Modem Satellite Available
const int PWR_EN = 6;                              // Satellite Modem Power Enable
const int sat_cts = 7;                             // Satellite Modem Clear to Send
const int sat_rts = 9;                             // Satellite Modem Request to Send
const int sda = 18;                                // I2C SDA
const int scl = 19;                                // I2C SCL


/*******************************
 *    Address declarations     *
 * These are software variable  *
 *******************************/
const byte i2cFlightComputerAddr  = 0x05;           // Flight Computer I2C Address
const byte i2cCutDownAddr         = 0x06;           // Cut Down Module I2C Address
const byte i2cGroundSupportAddr   = 0x07;           // Ground Support Board I2C Address
const byte i2cCommCtrlAddr        = 0x08;           // Communication Computer I2C Address
const byte i2cBallastCtrlAddr     = 0x09;           // Ballast Computer I2C Address
const byte i2ceePROMAddr          = 0x50;           // EEPROM I2C Address

/*******************************
 *     Constants for Sat Modem *
 *******************************/
const byte satIncomingPackLenLimit = 70;             //Used to define length of buffer arrays for packet data
const unsigned int satPowerOffMinimumTime = 2000;    //Probably 2000 millis for iridium
const unsigned int maxTelemLenConst = 1024;          //Maximum acceptable length of telemetry packet FROM EEPROM

#define LONG_MSG_QUEUE_LEN 20
const unsigned int LongMsgQueueLen = LONG_MSG_QUEUE_LEN;             // Number of messages that can be in the queue to send out sat modem

/*******************************
 *   I2C Incoming Queue
********************************/
#define I2C_MSG_QUEUE_LEN 4
const byte I2CMsgQueueLen = I2C_MSG_QUEUE_LEN;      // Number of messages that can be in the queue of received I2C msgs
const byte i2cMaxDataLen = 15;                      //I2C buffer length for cmd+data

/*******************************
 *   Constants for message payload processing (set these based on headers of sat modem provider)
********************************/
const byte packetPayloadStartIndex = 6;  // Message content starts here in a received packet from sat modem 6 for orbcomm, may be 0 for Iridium
const byte satIncomingMessageHeaderLength = 15;  //Length of inbound message headers, 15 for orbcomm, may be 0 for Iridium
const byte i2cRetryLimit = 10;


/*******************************
 *     Constants for I2C Commands to Comm Controller  *
 *******************************/
const byte i2cCmdSATTXATCRpt = 0x00;
const byte i2cCmdSATTxFrmEEPROM = 0x01;
const byte i2cCmdHFUpdtTelem = 0x02;
const byte i2cCmdHFTxShortRpt = 0x03;
const byte i2cCmdHFSetTxRate = 0x04;
const byte i2cCmdHFSnooze = 0x05;
const byte i2cCmdCDNHeartBeat = 0x06;
const byte i2cCmdCDNSetTimerAndReset = 0x07;
const byte i2cCmdUpdateCurrentEpochTime = 0x08;
const byte i2cCmdUpdateThreeNinersValue = 0x09;
const byte i2cCmdCDNCUTDOWNNOW = 0x99;
const byte i2cCmdSATPowerOn = 0xBB;
const byte i2cCmdSATPowerOff = 0xAA;

/*******************************
 *   Internal EEPROM Locations         *
 *******************************/
const int EPLOCcmdCounterArrayStart = 2; 
const int EPLENcmdCounterArray = 76;  //76 byte array to store used received command counter numbers.
const int EPLOCAtcReportPairArrayStart = 80;  // Arduino EEPROM location to store the latest ATC report pair
const int EPLOCAtcReportPairArray = 12;






#endif

