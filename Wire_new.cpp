///*
//  TwoWireSpecialEdition.cpp - TWI/I2C library for Wiring & Arduino
//  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//*/
//
//extern "C" {
//  #include <stdlib.h>
//  #include <string.h>
//  #include <inttypes.h>
//  #include "twi_new.h"
//}
//
//#include "Wire_new.h"
//
//// Initialize Class Variables //////////////////////////////////////////////////
//
//static volatile uint8_t rxByte = 0;
//
//uint8_t TwoWireSpecialEdition::txAddress = 0;
//uint8_t TwoWireSpecialEdition::txBuffer[BUFFER_LENGTH];
//uint16_t TwoWireSpecialEdition::txBufferIndex = 0;
//uint16_t TwoWireSpecialEdition::txBufferLength = 0;
//
//uint8_t TwoWireSpecialEdition::transmitting = 0;
//void (*TwoWireSpecialEdition::user_onRequest)(void);
//void (*TwoWireSpecialEdition::user_onReceive)(int);
//
//// Constructors ////////////////////////////////////////////////////////////////
//
//TwoWireSpecialEdition::TwoWireSpecialEdition()
//{
//}
//
//// Public Methods //////////////////////////////////////////////////////////////
//
//void TwoWireSpecialEdition::begin(void)
//{
//  txBufferIndex = 0;
//  txBufferLength = 0;
//
//  twi_init();
//}
//
//void TwoWireSpecialEdition::begin(uint8_t address)
//{
//  twi_setAddress(address);
//  twi_attachSlaveTxEvent(onRequestService);
//  begin();
//}
//
//void TwoWireSpecialEdition::begin(int address)
//{
//  begin((uint8_t)address);
//}
//
//
//void TwoWireSpecialEdition::beginTransmission(uint8_t address)
//{
//  // indicate that we are transmitting
//  transmitting = 1;
//  // set address of targeted slave
//  txAddress = address;
//  // reset tx buffer iterator vars
//  txBufferIndex = 0;
//  txBufferLength = 0;
//}
//
//void TwoWireSpecialEdition::beginTransmission(int address)
//{
//  beginTransmission((uint8_t)address);
//}
//
//uint8_t TwoWireSpecialEdition::endTransmission(void)
//{
//  // transmit buffer (blocking)
//  int8_t ret = twi_writeTo(txAddress, txBuffer, txBufferLength, 1);
//  // reset tx buffer iterator vars
//  txBufferIndex = 0;
//  txBufferLength = 0;
//  // indicate that we are done transmitting
//  transmitting = 0;
//  return ret;
//}
//
//// must be called in:
//// slave tx event callback
//// or after beginTransmission(address)
//size_t TwoWireSpecialEdition::write(uint8_t data)
//{
//  if(transmitting){
//  // in master transmitter mode
//    // don't bother if buffer is full
//    if(txBufferLength >= BUFFER_LENGTH){
//      setWriteError();
//      return 0;
//    }
//    // put byte in tx buffer
//    txBuffer[txBufferIndex] = data;
//    ++txBufferIndex;
//    // update amount in buffer
//    txBufferLength = txBufferIndex;
//  }else{
//  // in slave send mode
//    // reply to master
//    twi_transmit(&data, 1);
//  }
//  return 1;
//}
//
//// must be called in:
//// slave tx event callback
//// or after beginTransmission(address)
//size_t TwoWireSpecialEdition::write(const uint8_t *data, uint16_t quantity)
//{
//  if(transmitting){
//  // in master transmitter mode
//    for(uint16_t i = 0; i < quantity; i++){
//      write(data[i]);
//    }
//  }else{
//  // in slave send mode
//    // reply to master
//    twi_transmit(data, quantity);
//  }
//  return quantity;
//}
//
//
//// must be called in:
//// slave rx event callback
//// or after requestFrom(address, numBytes)
//int TwoWireSpecialEdition::read(void)
//{
//  return rxByte;
//}
//
//// behind the scenes function that is called when data is requested
//void TwoWireSpecialEdition::onRequestService(void)
//{
//  // don't bother if user hasn't registered a callback
//  if(!user_onRequest){
//    return;
//  }
//  // reset tx buffer iterator vars
//  // !!! this will kill any pending pre-master sendTo() activity
//  txBufferIndex = 0;
//  txBufferLength = 0;
//  // alert user program
//  user_onRequest();
//}
//
//// sets function called on slave write
//void TwoWireSpecialEdition::onReceive( void (*function)(uint8_t) )
//{
//  twi_attachSlaveRxEvent(function);
//}
//
//// sets function called on slave read
//void TwoWireSpecialEdition::onRequest( void (*function)(void) )
//{
//  user_onRequest = function;
//}
//
//int TwoWireSpecialEdition::peek() {
//  // not implemented
//  return 0;
//}
//
//void TwoWireSpecialEdition::flush() {
//  // not implemented
//}
//// Preinstantiate Objects //////////////////////////////////////////////////////
//
//int TwoWireSpecialEdition::available() {
//    return true;
//}
//
//TwoWireSpecialEdition wire = TwoWireSpecialEdition();

