/**
 * Hello World Example
 * Created With Genesis-Code extension for Visual Studio Code
 * Use "Genesis Code: Compile" command to compile this program.
 **/
#include <genesis.h>
//#define BUTTON_START 0X0080
#define PSG_NOISE_FREQ_TONE3 3
#define 	PSG_NOISE_TYPE_WHITE   1
void handleInput();

int main(bool hard)
{
 ///////////////+++++++++++++++++(MAIN)++++++++++++++++++++++++++++//////////   

SYS_disableInts();
VDP_init();
VDP_setScreenWidth320();
VDP_setScreenHeight224();

VDP_setBackgroundColor(0);

SYS_enableInts();
   

///////////////+++++++++++++++++++++++++++++++++++++++++++++++++++++++//////////
    while(1)
    {

        VDP_drawText("Hello Sega!!", 10,13);
     handleInput();
        //For versions prior to SGDK 1.60 use VDP_waitVSync instead.
        SYS_doVBlankProcess();
    }
    return (0);
}
void handleInput(){
  
    VDP_clearText(1,2,3);
    u16 value = JOY_readJoypad(JOY_1 );
   
     if (value & BUTTON_LEFT)
    { VDP_clearPlane(BG_A,FALSE);  VDP_drawText("Left",0,16);  VDP_drawText("Hello Sega!!", 10,13);  }
    if (value & BUTTON_RIGHT) {  VDP_drawText("Right",0,16);  }
 //VDP_clearPlane(BG_A,FALSE);

    if(value & BUTTON_A)  {  PAL_setColors(0, palette_blue, 64, DMA);} 
    
    if (value & BUTTON_B) { PAL_setColors(1,palette_green ,32,DMA); }
    
    if(value & BUTTON_MODE) {VDP_resetScreen();  BMP_drawText("PAUSE", 1, 4); PSG_getTone(PSG_NOISE_TYPE_WHITE,PSG_NOISE_FREQ_TONE3);}


}
