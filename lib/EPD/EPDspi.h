/*
 *  Author: LoBo (loboris@gmail.com, loboris.github),
 *          AtomDrug 
 *
 *  Module supporting SPI ePaper displays
 *
*/

#ifndef _EPDSPI_H_
#define _EPDSPI_H_

#include <Arduino.h>
#include <SPI.h>
#include "EPD.h"

//////////////////////////////////////////////
//Adjust
//////////////////////////////////////////////

//1.54 Inch EPD
#define EPD_DISPLAY_WIDTH	200
#define EPD_DISPLAY_HEIGHT	200

//pin defintions
#define DC_Pin		17
#define BUSY_Pin	26
#define RST_Pin		27
#define CS_Pin		05

///////////////////////////////////////////////

#define DC_VAL (1 << DC_Pin)

#define EPD_CS_0	digitalWrite(CS_Pin, 0)
#define EPD_CS_1	digitalWrite(CS_Pin, 1)
#define isEPD_CS	digitalRead(CS_Pin)

#define EPD_RST_0	digitalWrite(RST_Pin, 0)
#define EPD_RST_1	digitalWrite(RST_Pin, 1)
#define isEPD_RST	digitalRead(RST_Pin)

#define EPD_DC_0	digitalWrite(DC_Pin, 0)
#define EPD_DC_1	digitalWrite(DC_Pin, 1)

#define isEPD_BUSY  digitalRead(BUSY_Pin)

#define EPD_BUSY_LEVEL 0

extern uint8_t *gs_disp_buffer;
extern uint8_t *disp_buffer;
extern uint8_t *gs_drawBuff;
extern uint8_t *drawBuff;
extern int _width;
extern int _height;
extern uint16_t gs_used_shades;
extern uint8_t _gs;
extern uint8_t *LUT_part;
extern uint8_t LUTDefault_fastest[31];
extern uint8_t LUTDefault_part[31];
extern uint8_t LUT_gs[31];
extern uint8_t LUTDefault_full[31];
extern uint8_t lvl_buf[16];
extern uint8_t lvl_buf_jpg[16];

extern void EPD_wait(uint32_t ms);
extern void EPD_DisplaySetFull(uint8_t val);
extern void EPD_DisplaySetPart(int xStart, int xEnd, uint8_t yStart, uint8_t yEnd, uint8_t val);
extern void EPD_DisplayClearFull();
extern void EPD_DisplayClearPart();
extern void EPD_DisplayFull(uint8_t *DisBuffer);
extern void EPD_DisplayPart(int xStart, int xEnd, uint8_t yStart, uint8_t yEnd, uint8_t *DisBuffer);
extern void EPD_gsUpdate(int xStart, int xEnd, uint8_t yStart, uint8_t yEnd, uint8_t gs);
extern void EPD_Update(int xStart, int xEnd, uint8_t yStart, uint8_t yEnd);
extern void EPD_UpdateScreen();
extern void EPD_Cls();
extern void EPD_init_Part(void);
extern void initEPD();

#endif
