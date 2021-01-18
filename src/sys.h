/* 
 * File:   sys.h
 * Author: igor
 *
 * Created on September 9, 2019, 2:44 AM
 */

#ifndef SYS_H
#define	SYS_H



#define u8 unsigned char
#define u16 unsigned short
#define u32 unsigned long
#define u64 unsigned long long

#define vu8 volatile unsigned char
#define vu16 volatile unsigned short
#define vu32 volatile unsigned long
#define vu64 volatile unsigned long long

#define s8 signed char
#define s16 short
#define s32 long
#define s64 long long

#include "libdragon.h"
#include "string.h"
#include "stdlib.h"


#define CIC_6101 1
#define CIC_6102 2
#define CIC_6103 3
#define CIC_5101 4
#define CIC_6105 5
#define CIC_6106 6
#define CIC_5167 7

#define REGION_PAL      0
#define REGION_NTSC     1
#define REGION_MPAL     2

#define KSEG0           0x80000000
#define KSEG1           0xA0000000

#define VI_BASE_REG     0x04400000
#define	VI_CONTROL	(VI_BASE_REG + 0x00)
#define	VI_FRAMEBUFFER	(VI_BASE_REG + 0x04)
#define	VI_WIDTH	(VI_BASE_REG + 0x08)
#define	VI_V_INT	(VI_BASE_REG + 0x0C)
#define	VI_CUR_LINE	(VI_BASE_REG + 0x10)
#define	VI_TIMING	(VI_BASE_REG + 0x14)
#define	VI_V_SYNC	(VI_BASE_REG + 0x18)
#define	VI_H_SYNC	(VI_BASE_REG + 0x1C)
#define	VI_H_SYNC2	(VI_BASE_REG + 0x20)
#define	VI_H_LIMITS	(VI_BASE_REG + 0x24)
#define	VI_COLOR_BURST	(VI_BASE_REG + 0x28)
#define	VI_H_SCALE	(VI_BASE_REG + 0x2C)
#define	VI_VSCALE	(VI_BASE_REG + 0x30)

#define PI_BSD_DOM1_LAT_REG	(PI_BASE_REG+0x14)
#define PI_BSD_DOM1_PWD_REG	(PI_BASE_REG+0x18)
#define PI_BSD_DOM1_PGS_REG	(PI_BASE_REG+0x1C)    /*   page size */
#define PI_BSD_DOM1_RLS_REG	(PI_BASE_REG+0x20)

#define PI_BSD_DOM2_LAT_REG	(PI_BASE_REG+0x24)    /* Domain 2 latency */
#define PI_BSD_DOM2_PWD_REG	(PI_BASE_REG+0x28)    /*   pulse width */
#define PI_BSD_DOM2_PGS_REG	(PI_BASE_REG+0x2C)    /*   page size */
#define PI_BSD_DOM2_RLS_REG	(PI_BASE_REG+0x30)    /*   release duration */

#define	PHYS_TO_K1(x)           ((u32)(x)|KSEG1)        /* physical to kseg1 */
#define	IO_WRITE(addr,data)	(*(vu32 *)PHYS_TO_K1(addr)=(u32)(data))
#define	IO_READ(addr)		(*(vu32 *)PHYS_TO_K1(addr))

#define PI_STATUS_REG   (PI_BASE_REG+0x10)
#define PI_BASE_REG     0x04600000

#define VI_BASE_REG     0x04400000
#define VI_STATUS_REG   (VI_BASE_REG+0x00)
#define VI_CONTROL_REG  VI_STATUS_REG
#define VI_CURRENT_REG  (VI_BASE_REG+0x10)

#define RGB(r, g, b) ((r << 11) | (g << 6) | (b << 1))

typedef struct {
    vu32 region;
    vu32 rom_type;
    vu32 base_addr;
    vu32 rst_type;
    vu32 cic_type;
    vu32 os_ver;
    vu32 ram_size;
    vu32 app_buff;
} BootStrap;

typedef struct {
    u32 w;
    u32 h;
    u32 pixel_w;
    u32 pixel_h;
    u32 char_h;
    u32 buff_len;
    u32 buff_sw;
    u16 * buff[2];
    u16 *current;
    u16 *bgr_ptr;
} Screen;

#define G_SCREEN_W      40 //screen.w
#define G_SCREEN_H      30 //screen.h


void sysInit();
void sysPI_rd(void *ram, unsigned long pi_address, unsigned long len);
void sysPI_wr(void *ram, unsigned long pi_address, unsigned long len);



#define G_SCREEN_W      40 //screen.w
#define G_SCREEN_H      30 //screen.h
#define G_BORDER_X      2
#define G_BORDER_Y      2
#define G_MAX_STR_LEN   (G_SCREEN_W - G_BORDER_X*2)

#define PAL_B1          0x1000
#define PAL_B2          0x2000
#define PAL_B3          0x3000
#define PAL_G1          0x1400
#define PAL_G2          0x2400
#define PAL_G3          0x3400

#define PAL_BR          0x5000
#define PAL_BG          0x6000
#define PAL_WG          0x1700
#define PAL_RB          0x0500

void gCleanScreen();
void gConsPrint(u8 *str);
void gSetXY(u8 x, u8 y);
void gSetPal(u16 pal);
void gAppendString(u8 *str);
void gAppendChar(u8 chr);
void gAppendHex8(u8 val);
void gAppendHex16(u16 val);
void gAppendHex32(u32 val);
void gAppendHex32(u32 val);
void gRepaint();
void gVsync();

#endif	/* SYS_H */

