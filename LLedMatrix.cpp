/*
  Copyright (c) 2014 MediaTek Inc.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License..

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
   See the GNU Lesser General Public License for more details.
*/

#include "arduino.h"
#include "LLedMatrix.h"
#include "Wire.h"


unsigned char LLedMatrixClass::check_on_line()
{
	unsigned char DataBuf[4] = {0};
	unsigned char i = 0;
	Wire.begin();
	Wire.beginTransmission(LEDAddress);
    Wire.write(0);
	Wire.endTransmission();
	Wire.requestFrom(LEDAddress, 4);
	while(Wire.available())
    {
		DataBuf[i++] = Wire.read();
    }
	if(DataBuf[3] == LEDAddress)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void LLedMatrixClass::disp_string(const char uData[],unsigned char uDataLength,unsigned int uTime)
{
	unsigned char buffer[20] = {0};
	unsigned char i;
	
	if(uDataLength > 4)return;
	buffer[0] = DISP_STRING;
	buffer[1] = uDataLength;
	for(i=0;i<uDataLength;i++)buffer[i + 2] = *(uData ++);
	buffer[i+2] = uTime >> 8;
	buffer[i+3] = uTime;
	
	Wire.begin();
	Wire.beginTransmission(LEDAddress);
	Wire.write(buffer,uDataLength + 4);
	Wire.endTransmission();
}

void LLedMatrixClass::disp_char(const char uData,unsigned int uTime)
{
	unsigned char buffer[4] = {0};
	unsigned char  i;
	
	buffer[0] = DISP_CHAR_5X7;
	buffer[1] = uData;
	buffer[2] = uTime >> 8;
	buffer[3] = uTime;

	Wire.begin();
	Wire.beginTransmission(LEDAddress);
	Wire.write(buffer,4);
	Wire.endTransmission();
}

void LLedMatrixClass::set_disp_orientation(unsigned char orientation)
{
	Wire.begin();
	Wire.beginTransmission(LEDAddress);
	Wire.write(SET_DISP_ORIENTATION);
	Wire.endTransmission();
}

void LLedMatrixClass::disp_pic(unsigned char uPicNum, unsigned int uTime)
{
	unsigned char buffer[4] = {0};
	unsigned char  i;
	
	buffer[0] = DISP_PIC;
	buffer[1] = uPicNum;
	buffer[2] = uTime >> 8;
	buffer[3] = uTime;

	Wire.begin();
	Wire.beginTransmission(LEDAddress);
	Wire.write(buffer,4);
	Wire.endTransmission();
}

void LLedMatrixClass::disp_data(unsigned char *uPicData, unsigned int uTime)
{
	unsigned char buffer[8] = {0};
	
	buffer[0] = DISP_DATA;
	buffer[1] = *(uPicData);
	buffer[2] = *(uPicData + 1);
	buffer[3] = *(uPicData + 2);
	buffer[4] = *(uPicData + 3);
	buffer[5] = *(uPicData + 4);
	buffer[6] = uTime >> 8;
	buffer[7] = uTime;
	
	Wire.begin();
	Wire.beginTransmission(LEDAddress);
	Wire.write(buffer,8);
	Wire.endTransmission();
	
}

LLedMatrixClass LedMatrix;

