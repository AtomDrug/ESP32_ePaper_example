#include <time.h>
#include <WiFi.h>
#include "EPD.h"

static time_t time_now;
static struct tm* tm_info;

void setup()
{
    //Serial.begin(115200);
	initEPD();
}

void loop(){

	char tmp_buff[128];
	uint32_t t1 = millis();

	//get rtc time / if not set it´s the uptime
	time(&time_now);
	tm_info = localtime(&time_now);

	int prog = ((180.0/60.0)*tm_info->tm_sec+1);

	//simple progressbar for seconds/min
	EPD_drawRect(10-1,20-1,180+2,20+2, EPD_BLACK);
	EPD_fillRect(10,20,180,20, EPD_WHITE);
	EPD_fillRect(10,20,prog,20, EPD_BLACK);

	//set font
	EPD_setFont(FONT_7SEG);
	set_7seg_font_atrib(10, 2, 0, 15);

	//time
	sprintf(tmp_buff, "%02d:%02d:%02d", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
	EPD_print(tmp_buff, CENTER, CENTER);

	int y2 = LASTY + EPD_getfontheight() + 10;

	//date
	set_7seg_font_atrib(4, 1, 1, 15);
	sprintf(tmp_buff, "%02d.%02d.%04d", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year+1900);
	EPD_print(tmp_buff, CENTER, y2);

	//render
	EPD_UpdateScreen();

	//FPS calc after update, else we do not calculated time needed for rendering!
	float fps = 1000.0 / (millis()-t1);
	EPD_setFont(UBUNTU16_FONT);
	sprintf(tmp_buff, "FPS: %.2f    ", fps);

	//will be printed in n+1 (the next) frame
	EPD_print(tmp_buff, 10, EPD_DISPLAY_HEIGHT-30);
}