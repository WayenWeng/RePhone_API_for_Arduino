
#include <LWs2812.h>

void setup() 
{
	Serial.begin(115200);
	while(!Serial.available()); 
	Serial.print("Ws2812 test.\r\n");
    
	while(1)
	{
		if(LWs2812.check_on_line())
		{
			Serial.print("Ws2812 on line.\r\n");
			break;
		}
		delay(1000);
		Serial.print("Ws2812 off line.\r\n");
	}
}

void loop()
{
	LWs2812.monochrome(5, 0xff0000, 2);
	delay(2500);
	LWs2812.marquee(5, 0xffff00, 5);
	delay(5500);
	LWs2812.rainbow(5, 5);
	delay(5500);
}
