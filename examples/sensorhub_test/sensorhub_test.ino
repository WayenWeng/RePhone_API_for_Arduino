
#include <LSensorHub.h>
#include <stdio.h>


void setup()
{
	Serial.begin(115200);
	Serial.print("Sensor Hub test.\r\n");

	while(1)
	{
		if(LSensorHub.check_on_line())
		{
			Serial.print("Sensor Hub is on line.\r\n");
			break;
		}
		delay(1000);
		Serial.print("Sensor Hub is off line.\r\n");
	}
}

void loop()
{
	long data1 = 0;
	long data2 = 0;
	long data3 = 0;
	unsigned long data4 = 0;
	long data5 = 0;
	char buffer[50] = {0,};

	LSensorHub.GetAccData(&data1, &data2, &data3);
	LSensorHub.GetLighData(&data4);
	LSensorHub.GetTempData(&data5);

	sprintf(buffer,"acc_x is %d \r\n", data1);
	Serial.print(buffer);
	sprintf(buffer,"acc_y is %d \r\n", data2);
	Serial.print(buffer);
	sprintf(buffer,"acc_z is %d \r\n", data3);
	Serial.print(buffer);
	sprintf(buffer,"light is %d \r\n", data4);
	Serial.print(buffer);
	sprintf(buffer,"temperature is %d \r\n", data5);
	Serial.print(buffer);

	delay(1000);
}
