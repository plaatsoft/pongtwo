/* 
**  Created by wplaat (www.plaatsoft.nl)
**	
**  Copyright (C) 2008-2009
**  =======================
**
**  This program is free software; you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, version 2.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program; if not, write to the Free Software
**  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
**
**  Release Notes:
**  ==============
**
**   15/11/2009 Version 0.99
**   - Maintenance release
**   - Added functionality to trace game debug events to file.
**   - Use the asndlib (part of libogc) now as standard sound engine.
**   - Improve network thread
**   - Upgrade libmxml library to 2.6
**   - Upgrade libfat library to 1.0.6.
**   - Build game with libogc 1.8.0 and devkitPPC r19 compiler
**
**   17/02/2009 Version 0.98
**   - It took a long time but now pong2 support multi player mode.
**   - Build game with libogc 1.7.1 and devkitPPC r16 compiler
**
**   03/02/2009 Version 0.97
**   - HotFix: Set start level to zero each first game.
**   - HotFix: Remove typo on help screen.
**   - Release notes screen is now showing information fetch from internet.
**   - Added up and down cursor event to scroll through release notes.
**   - Build game with libogc 1.7.1 and devkitPPC r16 compiler
** 
**   01/02/2009 Version 0.96
**   - Improve third intro screen.
**   - Added small game menu.
**   - Added credits screen
**   - Improve help screen.
**   - Added release notes screen.
**   - Increase http receive buffer size to 8196 bytes.
**   - Use only one unique cookie number during the game.
**   - Split game logic, button events and screen output in source code.
**   - Build game with libogc 1.7.1 and devkitPPC r16 compiler
**
**   15/01/2009 Version 0.95
**   - Update url on intro screens to www.plaatsoft.nl (My new domain).
**   - Improve intro screen positioning by PAL 50Hz TV mode.
**   - Network thread status is showed on screen.
**   - Bugfix: Highscore is now always loaded correctly.
**   - Build game with libogc 1.7.1 and devkitPPC r16 compiler.
**
**   20/12/2008 Version 0.94
**   - Added SDHC card support.
**   - Added power down button support.
**   - Added win screen if players wins all levels.
**   - Build game with new libogc 1.7.1 and devkitPPC r16 compiler
**
**   02/12/2008 Version 0.93
**   - Improve http (new version check) thread.
**   - Build game with libogc 1.6.0 and devkitPPC r15 compiler
**
**   21/11/2008 Version 0.92
**   - Added threaded network check for new version.
**   - Solved some minor reported bugs.
**   - Added GNU GPL2 statement in source code.
**   - Build game with libogc 1.6.0 and devkitPPC r15 compiler
**
**   12/11/2008 Version 0.91
**   - Added high Score screen.
**   - High scores are saved (.xml format) on your SD card.
**   - Added better game sound effects.
**   - Build game with libogc 1.6.0 and devkitPPC r15 compiler
**   
**   02/11/2008 Version 0.90   
**   - Added new welcome screens.
**   - Improved game images.
**   - Added help screen (Minus button).
**   - Created new homebrew game logo.
**   - Build game with libogc 1.6.0 and devkitPPC r15 compiler
**
**   31/10/2008 Version 0.80
**   - Added support for Wii Classic Controller.
**   - Added two bars on the Game board (Game Level > 2 and higher).
**   - Added game level six.
**   - Build game with libogc 1.6.0 and devkitPPC r15 compiler.
**
**   27/10/2008 Version 0.70
**   - Improved goodbye screen.
**   - Added support for 60Hz screens.
**   - Build game with libogc 1.6.0 and devkitPPC r15 compiler.
**
**   23/10/2008 Version 0.60
**   - Fixed two bugs in result screen.
**   - Improved game images.
**   - Replaced two music tracks.
**   - Made source code available.
**   - Build game with libogc 1.6.0 and devkitPPC r15 compiler.
**
**   22/10/2008 Version 0.50
**   - Added a game score overview screen.
**   - Start ball position is random now.
**   - Added (impossible) level five.
**   - Build game with libogc 1.6.0 and devkitPPC r15 compiler.
**
**   21/10/2008 Version 0.40
**   - Added 4 game levels.
**   - Improved game board layout.
**   - Added game clock.
**   - Added pause (+) button.
**   - Build game with libogc 1.6.0 and devkitPPC r15 compiler.
**
**   20/10/2008 Version 0.30
**   - First release for public use.
**   - Added a nice start screen.
**   - Ball speed can now be controlled by A and B buttons.
**   - 10 tracks of background music added.
**   - Music track can be controlled with 1 and 2 button.
**   - Build game with libogc 1.6.0 and devkitPPC r15 compiler.
**   
**   19/10/2008 Version 0.20
**   - Improved paddle control.
**   - Improve screen layout.
**   - Build game with libogc 1.6.0 and devkitPPC r15 compiler.
**
**   18/10/2008 Version 0.10
**   - Started programming.
**   - Gameboard ready.
**   - Badic game logic ready.
**   - Build game with libogc 1.6.0 and devkitPPC r15 compiler.
*/

#include <stdio.h>
#include <gccore.h>
#include <ogcsys.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h> 
#include <wiiuse/wpad.h>
#include <gcmodplay.h> 
#include <jpeg/jpgogc.h>
#include <fat.h>
#include <mxml.h>
#include <asndlib.h>  

#include "music0_mod.h"
#include "music1_mod.h"
#include "music2_mod.h"
#include "music3_mod.h"
#include "music4_mod.h"
#include "music5_mod.h"
#include "music6_mod.h"
#include "music7_mod.h"
#include "music8_mod.h"
#include "music9_mod.h"
#include "effect1_wav.h"
#include "effect2_wav.h"
#include "effect3_wav.h"

#include "general.h"
#include "light.h"
#include "network.h"
#include "http.h"
#include "trace.h"

// -----------------------------------------------------------
// PROTYPES
// -----------------------------------------------------------

void initGame(void);
void button1x(int channel);
void button2y(int channel);
void buttonHome(int channel);
void musicSelect(bool show);
void initBall(boolean direction);
void initLevel(void);
void storeScore(int gameLevel);
void screenScore(int channel);
void screenHelp(int channel);
void loadHighScoreFile(char* filename);
void saveHighScoreFile(char* filename);
void movePlayer2(void);
void moveBall(void);
void detectCollision(int channel);
void exitGame(bool mode);


// -----------------------------------------------------------
// Variables
// -----------------------------------------------------------

// Screen dimisions
u32 *frameBuffer[1] = {NULL};
GXRModeObj *rmode = NULL;
int  xMin=0;
int  yMin=0;
int  xMax=0;
int  yMax=0;
int  yjpegOffset=0;
int  offset = 1;
int  scrollRange=100;
char appl_user3[MAX_LEN];

int  maxButtons=0;
int  buttonSelect=0;
int  prevNetworkState=-1;
int  prevMusicTrack=-1;

// State Machine
int  stateMachine=stateMenu;
int  prevStateMachine=stateNone;

// Music parameters
static MODPlay snd1;
int  musicVolume=5;
int  musicTrack=0;

// Poweroff flag
bool bPowerOff = false;	

// level0 image
extern char     pic0data[];
extern int      pic0length;

// level1 image
extern char     pic1data[];
extern int      pic1length;

// level2 image
extern char     pic2data[];
extern int      pic2length;

// level3 image
extern char     pic3data[];
extern int      pic3length;

// gameover image
extern char     pic4data[];
extern int      pic4length;

// goodbye image
extern char     pic5data[];
extern int      pic5length;

// game score image
extern char     pic6data[];
extern int      pic6length;

// level4 image
extern char     pic7data[];
extern int      pic7length;

// Intro1 image
extern char     pic8data[];
extern int      pic8length;

// GetReady image
extern char     pic9data[];
extern int      pic9length;

// level5 image
extern char     pic10data[];
extern int      pic10length;

// help image
extern char     pic11data[];
extern int      pic11length;

// Intro2 image
extern char     pic12data[];
extern int      pic12length;

// Intro3 image
extern char     pic13data[];
extern int      pic13length;

// high Score image
extern char     pic14data[];
extern int      pic14length;

// Win image
extern char     pic16data[];
extern int      pic16length;

// Menu image
extern char     pic17data[];
extern int      pic17length;

// Credits image
extern char     pic18data[];
extern int      pic18length;

// Release Notes image
extern char     pic19data[];
extern int      pic19length;

// -----------------------------------------------------------
// SCREEN ACTIONS
// -----------------------------------------------------------

void drawEmptyScreen(bool mode)
{
   int x;
   int y;
   int xMin1=0, xMax1=0, yMin1=0, yMax1=0;
   
   if (mode)
   { 
	   // Clear inner section
	   xMin1=xMin+offset;
	   xMax1=xMax-offset;
	   yMin1=yMin+2+offset;
	   yMax1=yMax-offset;
   }
   else
   {
	   // Clear complete screen
	   xMin1=xMin;
	   xMax1=xMax;
	   yMin1=yMin;
	   yMax1=yMax+4;
   }

   // Clear Screen
   for (x=xMin1; x<=xMax1; x++)
   {	
      for (y=yMin1; y<=yMax1; y++)
      {	
	     printf("\x1b[%d;%dH%c",y,x,255);	
      } 
   }
}

void drawTime()
{
  struct tm *local;
  time_t currentTime = time(NULL)-game.startTime;  
  local = localtime(&currentTime);
  if (local->tm_sec!=game.prevSecond)
  {   
    printf("\x1b[%d;%dH%02d:%02d", yMax + offset, 53, local->tm_min, local->tm_sec);
	game.prevSecond=local->tm_sec;
  }
}

void drawNetworkState()
{
  int state=0;
  
  LAN( state=tcp_get_state_nr(); )
  if (state!=prevNetworkState)
  {   
    printf("\x1b[%d;%dH[%X]", yMax + offset, 59, state);
	prevNetworkState=state;
  }
}

void drawScore(void)
{
   printf("\x1b[%d;%dH%03d", yMax + 1, 75, game.rightScore);
   printf("\x1b[%d;%dH%03d", yMax + 1, 2, game.leftScore); 
}

void drawLevel(void)
{
   printf("\x1b[%d;%dH%d", yMax + offset, 25, game.level);
}

void drawMusicTrack(void)
{
   if (musicTrack!=prevMusicTrack)
   {  
     if (musicTrack==10)
     {
       printf("\x1b[%d;%dH  Music Off   ", yMax + offset, xMin+34);
     }
     else
     {
       printf("\x1b[%d;%dHMusic Track %d ", yMax + offset, xMin+34, musicTrack+1);
     }  
	 prevMusicTrack=musicTrack;
   }
}

void drawPaddle(int channel)
{
   int y;
   
   for (y=paddles[channel].yPrev-paddles[channel].len; y<=(paddles[channel].yPrev+paddles[channel].len); y++)
   {	
	   printf("\x1b[%d;%dH%c",y,paddles[channel].xPrev,255);	
   }  
	  
   for (y=paddles[channel].y-paddles[channel].len; y<=(paddles[channel].y+paddles[channel].len); y++)
   {
	  printf("\x1b[%d;%dH%c",y,paddles[channel].x,219);	
   }
   
   paddles[channel].yPrev=paddles[channel].y;
   paddles[channel].xPrev=paddles[channel].x;
}

void drawBar(void)
{
   int y=0;
   
   // Top bar
   if (bars[0].len>0)
   {
     printf("\x1b[%d;%dH%c",bars[0].y,bars[0].x,203);	
     for (y=bars[0].y+1; y<bars[0].y+bars[0].len; y++)
     {
        printf("\x1b[%d;%dH%c",y,bars[0].x,186);	
     }
   }
   else
   {
      printf("\x1b[%d;%dH%c", bars[0].y, bars[0].x, 205);
   }
   
   // Bottom bar
   if (bars[1].len>0)
   {
      printf("\x1b[%d;%dH%c",bars[1].y,bars[1].x,202);	
      for (y=bars[1].y-1; y>bars[1].y-bars[1].len; y--)
      {
         printf("\x1b[%d;%dH%c",y,bars[1].x,186);	
      }
   }
   else
   {
      printf("\x1b[%d;%dH%c", bars[1].y, bars[1].x, 205);   
   }
}


void drawReleaseNotes(void)
{
	char *s_fn="drawReleaseNotes";
	traceEvent(s_fn,0,"enter");
	
   int i;
   int startpos=0;
   int lineCount=0;
   int yOffset=14;
   
   if (releasenotes.enabled)
   {
     for (i=releasenotes.scrollIndex; i<(releasenotes.scrollIndex+MAX_NOTE_LINES); i++)
     {
       while (lineCount!=i)
	   {
	     if (releasenotes.data[startpos++]==0x00) 
		 {
		   lineCount++;
		 }
	   }
	   printf("\x1b[%d;%dH                                                                        ",(i-releasenotes.scrollIndex)+yOffset,5);	
	   printf("\x1b[%d;%dH%s",(i-releasenotes.scrollIndex)+yOffset,5,releasenotes.data+startpos);	
     }
   }
   else
   {   
      int ypos=18; 
	  char tmp[MAX_LEN];
	  sprintf(tmp,"Information could not be fetch from internet");
	  printf("\x1b[%d;%dH%s", ypos, ((xMax/2)-(strlen(tmp)/2)), tmp);
   }
   
   traceEvent(s_fn,0,"leave [void]");
}

void drawBall(void)
{
   printf("\x1b[%d;%dH%c",ball.y,ball.x,48);	

   if ((ball.y!=ball.yPrev) || (ball.x!=ball.xPrev))
   {
      printf("\x1b[%d;%dH%c",ball.yPrev,ball.xPrev,255);
   }
}


void drawButtons(void)
{
   int i;
   char tmp[MAX_LEN];
   
   for (i=0; i<maxButtons; i++)
   {
      if (i==buttonSelect)
	  {	     
		 sprintf(tmp,"[ %s ]", buttons[i].label );
	  }
	  else
	  {
         sprintf(tmp,"  %s  ", buttons[i].label );	
	  }
	  printf("\x1b[%d;%dH%s",buttons[i].y,buttons[i].x,tmp);	
   }   
}

void drawGameBoard(void)
{
	char *s_fn="drawGameBoard";
	traceEvent(s_fn,0,"enter");
	
	int x;
	int y;
	
	// Clear Screen
	drawEmptyScreen(false);
	
	// The console understands VT terminal escape codes
	// This positions the cursor on row 2, column 0
	// we can use variables for this with format codes too
	// e.g. printf ("\x1b[%d;%dH", row, column );
	
	printf("\x1b[%d;%dH%c", yMin, xMin, 201);		   
	for (x=(xMin+offset); x<=(xMax-offset); x++) printf("\x1b[%d;%dH%c", yMin, x, 205);	
	printf("\x1b[%d;%dH%c", yMin, xMax, 187);
	
	printf("\x1b[%d;%dH%c", yMin+1, xMin, 186);	
	printf("\033[01;30;46m\x1b[%d;%dH%s v%s", yMin+1, 2, PROGRAM_NAME, PROGRAM_VERSION);
	printf("\033[01;30;46m\x1b[%d;%dH%s", yMin+1, 32, "www.plaatsoft.nl");
	printf("\033[01;30;46m\x1b[%d;%dH%s", yMin+1, xMax-11, RELEASE_DATE);
	printf("\x1b[%d;%dH%c", yMin+1, xMax, 186);
	   
	printf("\x1b[%d;%dH%c", yMin+2, xMin, 204);		   
	for (x=(xMin+offset); x<=(xMax-offset); x++) printf("\x1b[%d;%dH%c", yMin+2, x, 205);	
	printf("\x1b[%d;%dH%c", yMin+2, xMax, 185);
	
	for (y=(yMin+2+offset); y<=(yMax-offset); y++) printf("\x1b[%d;%dH%c", y, xMin, 186);	
	for (y=(yMin+2+offset); y<=(yMax-offset); y++) printf("\x1b[%d;%dH%c", y, xMax, 186);	
	
	printf("\x1b[%d;%dH%c", yMax, xMin, 204);	
	for (x=(xMin+offset); x<=(xMax-offset); x++) printf("\x1b[%d;%dH%c", yMax, x, 205);	
	printf("\x1b[%d;%dH%c", yMax, xMax, 185);	
		
	printf("\x1b[%d;%dH%c", yMax+offset, xMin, 186);	
    printf("\x1b[%d;%dHLevel %d ", yMax + offset, 19, game.level);
	printf("\x1b[%d;%dH00:00 [0]", yMax + offset, 53);
	    
	printf("\x1b[%d;%dH%c", yMax+2, xMin, 200);	
	for (x=(xMin+offset); x<=(xMax-offset); x++) printf("\x1b[%d;%dH%c", yMax+2, x, 205);	
	printf("\x1b[%d;%dH%c", yMax+2, xMax, 188);	
	
	printf("\x1b[%d;%dH%c", yMax, 15, 203);	
	printf("\x1b[%d;%dH%c", yMax+offset, 15, 186);	
	printf("\x1b[%d;%dH%c", yMax+2, 15, 202);
	
	printf("\x1b[%d;%dH%c", yMax, 29, 203);	
	printf("\x1b[%d;%dH%c", yMax+offset, 29, 186);	
	printf("\x1b[%d;%dH%c", yMax+2, 29, 202);
	
	printf("\x1b[%d;%dH%c", yMax, 50, 203);	
	printf("\x1b[%d;%dH%c", yMax+offset, 50, 186);	
	printf("\x1b[%d;%dH%c", yMax+2, 50, 202);
	
	printf("\x1b[%d;%dH%c", yMax, 63, 203);	
	printf("\x1b[%d;%dH%c", yMax+offset, 63, 186);	
	printf("\x1b[%d;%dH%c", yMax+2, 63, 202);
	
	printf("\x1b[%d;%dH%c", yMax+offset, xMax, 186);   
	
	traceEvent(s_fn,0,"leave [void]");
}

void drawPlayerInfo(void)
{
    if (!game.multiplayer)
	{
	  printf("\x1b[%d;%dH%03d Human   ", yMax + offset, 2, game.leftScore);
	  printf("\x1b[%d;%dHComputer %03d", yMax + offset, xMax-13, game.rightScore);
	 
	}
	else
	{
	  printf("\x1b[%d;%dH%03d Player1", yMax + offset, 2, game.leftScore);
 	  printf("\x1b[%d;%dH Player2 %03d", yMax + offset, xMax-13, game.rightScore);
	}
}
	
void drawImage(char *pictureData, int pictureLength, int x, int y )
{
	char *s_fn="drawImage";
	traceEvent(s_fn,0,"enter");
	
    JPEGIMG         jpeg;
    int             row,
                    col,
                    pix,
                    offset;
    unsigned int   *jpegout;

    memset(&jpeg, 0, sizeof(JPEGIMG));

    jpeg.inbuffer = pictureData;
    jpeg.inbufferlength = pictureLength;

    JPEG_Decompress(&jpeg);
	
    pix = 0;

    jpegout = (unsigned int *) jpeg.outbuffer;

    offset=(y+yjpegOffset)*320;
    for (row = 0; row < jpeg.height; row++)
    {
	    for (col = 0; col < (jpeg.width >> 1); col++)
		{
	       frameBuffer[0][offset + col + x] = jpegout[pix++];
		}
	    offset+=320;
    }
    free(jpeg.outbuffer);
	
	traceEvent(s_fn,0,"leave [void]");
}

void drawIntroSceen(int index)
{
	char *s_fn="drawIntroSceen";
	traceEvent(s_fn,0,"enter [index=%d]",index);
	
   boolean flag = true;
   
   switch (index)
   {
      case 0: drawImage(pic8data, pic8length, 0, 0 );
	          break;
			  
	  case 1: drawImage(pic12data, pic12length, 0, 0 );
	          break;
			  
	  case 2: drawImage(pic13data, pic13length, 0, 0 );
	          break;
   }
			  
   // Handle buttons events
   while ( flag && !bPowerOff )
   {
		WPAD_ScanPads(); 
		if (WPAD_ButtonsDown(WPAD_CHAN_0) & BUTTON_A) flag=false; 	
		if (WPAD_ButtonsDown(WPAD_CHAN_1) & BUTTON_A) flag=false; 
		
	    // Flush and Wait for the next frame
      	VIDEO_SetNextFramebuffer(frameBuffer[0]); 
		VIDEO_Flush();
		VIDEO_WaitVSync();	
   }
   
   // Handle buttons events  
   flag = true;
   while ( flag && !bPowerOff )
   {
     WPAD_ScanPads(); 	
     if (WPAD_ButtonsUp(WPAD_CHAN_0) & BUTTON_A) flag=false;
	 if (WPAD_ButtonsUp(WPAD_CHAN_1) & BUTTON_A) flag=false;
   }	
   traceEvent(s_fn,0,"leave [void]");
}

void drawWonMessage(int y)
{
   char tmp[MAX_LEN];
   
   if (game.multiplayer)
   {
      if (game.leftScore>=MAX_SCORE)
      {	 
		sprintf(tmp,"PLAYER 1 HAS WON!");
	  }
	  else
	  {
		sprintf(tmp,"PLAYER 2 HAS WON!");
	  }
	  printf("\x1b[%d;%dH%s", y, ((xMax/2)-(strlen(tmp)/2)), tmp);
   }
   else
   {
      if (game.leftScore>=MAX_SCORE)
      {	 	  
         sprintf(tmp,"PLAYER 1 (HUMAN) HAS WON!");
	  }
	  else
	  {
	     sprintf(tmp,"PLAYER 2 (COMPUTER) HAS WON!");
	  }
	  printf("\x1b[%d;%dH%s", y, ((xMax/2)-(strlen(tmp)/2)), tmp);
   }
}
		 
void drawScreen()
{
    char tmp[MAX_LEN];
    int  i;
		
    drawNetworkState();
	 	
	char *s_fn="drawScreen";
	traceEvent(s_fn,0,"enter [stateMachine=%d]",stateMachine);
			
    switch (stateMachine)
	{
	   case stateMenu:
	   {	
         char *version=NULL;	 
		 int yoffset=23;
		          
	     drawImage(pic17data, pic17length, 10, 60 );
					 
	     drawButtons();   
		 drawMusicTrack(); 

         LAN (version=tcp_get_version();)
         if ( (version!=NULL) &&  (strlen(version)>0) && (strcmp(version,PROGRAM_VERSION)!=0) )
         {          
            sprintf(tmp,"New version [%s] of Pong2 is available on", version);
            printf("\x1b[%d;%dH%s", yoffset, ((xMax/2)-(strlen(tmp)/2)), tmp );	   

            printf("\x1b[%d;%dH%s", yoffset+1, ((xMax/2)-(strlen("http://www.plaatsoft.nl")/2)), "http://www.plaatsoft.nl" );	 
         }   
	   }
	   break;
	   
	   case stateCredits:
	   {
	     drawImage(pic18data, pic18length, 10, 60 );   	   

	     int ypos=13;		 
		 sprintf(tmp,"GAME LOGIC");
		 printf("\x1b[%d;%dH%s", ypos, ((xMax/2)-(strlen(tmp)/2)), tmp);
		 ypos++;
		 sprintf(tmp,"wplaat");
		 printf("\x1b[%d;%dH%s", ypos, ((xMax/2)-(strlen(tmp)/2)), tmp);
		 ypos+=2;			 
		 
		 sprintf(tmp,"GAME GRAPHICS");
		 printf("\x1b[%d;%dH%s", ypos, ((xMax/2)-(strlen(tmp)/2)), tmp);
		 ypos++;
		 sprintf(tmp,"wplaat");
		 printf("\x1b[%d;%dH%s", ypos, ((xMax/2)-(strlen(tmp)/2)), tmp);
		 ypos+=2;

		 sprintf(tmp,"MUSIC & SOUND EFFECTS");
		 printf("\x1b[%d;%dH%s", ypos, ((xMax/2)-(strlen(tmp)/2)), tmp);
		 ypos++;
		 sprintf(tmp,"modarchive.org");
		 printf("\x1b[%d;%dH%s", ypos, ((xMax/2)-(strlen(tmp)/2)), tmp);
		 ypos++;
		 sprintf(tmp,"wplaat");
		 printf("\x1b[%d;%dH%s", ypos, ((xMax/2)-(strlen(tmp)/2)), tmp);
		 ypos+=2;
		 
		 sprintf(tmp,"TESTERS");
		 printf("\x1b[%d;%dH%s", ypos, ((xMax/2)-(strlen(tmp)/2)), tmp);
		 ypos++;
		 sprintf(tmp,"wplaat");
		 printf("\x1b[%d;%dH%s", ypos, ((xMax/2)-(strlen(tmp)/2)), tmp);		 
	   }
	   break;
	   
  	   case stateReleaseNotes:
	   {
	     drawImage(pic19data, pic19length, 10, 60 );   	   
		 		
		 drawReleaseNotes();
	   }
	   break;
	   
	   case stateGame:
	   {	 
		 // Draw ball
		 drawBall();
		    
		 // Draw Paddles
		 drawPaddle(0);
 		 drawPaddle(1);
						
		 // Update game level time
		 drawTime();
	   }
	   break;
	   
	   case stateLevel:
	   {   
          WIILIGHT_TurnOn();
          WIILIGHT_SetLevel(255);
		   		     
          switch (game.level)
          {
	         case 0: for (i=0; i<(scrollRange/2); i=i+4) 
	                 {
			           drawImage(pic9data, pic9length, 10, 70+i );
			           drawImage(pic0data, pic0length, 10, 220+i);			
			         }
			         break;

	         case 1: for (i=0; i<(scrollRange/2); i=i+4) 
	                 {
				       drawImage(pic9data, pic9length, 10, 70+i);
	                   drawImage(pic1data, pic1length, 10, 220+i );			   
			         }
			         drawWonMessage(6);			   
			         break;

	         case 2: for (i=0; i<(scrollRange/2); i=i+4) 
	                 {
			           drawImage(pic9data, pic9length, 10, 70+i );
		               drawImage(pic2data, pic2length, 10, 220+i );
			         }
			         drawWonMessage(6);
			         break;

	         case 3: for (i=0; i<(scrollRange/2); i=i+4) 
	                 {
			           drawImage(pic9data, pic9length, 10, 70+i);
		               drawImage(pic3data, pic3length, 10, 220+i );
			         }
			         drawWonMessage(6);
			         break;
			   
	         case 4: for (i=0; i<(scrollRange/2); i=i+4) 
	                 {
			           drawImage(pic9data, pic9length, 10, 70+i );
		               drawImage(pic7data, pic7length, 10, 220+i );
			         }
			         drawWonMessage(6);
			         break;
			   
	         case 5: for (i=0; i<(scrollRange/2); i=i+4) 
	                 {
			           drawImage(pic9data, pic9length, 10, 70+i );
		               drawImage(pic10data, pic10length, 10, 220+i );
			         }
			         drawWonMessage(6);
			         break;
					 
			 default:  sprintf(tmp,"Undefine Level");
			           printf("\x1b[%d;%dH%s", 6, ((xMax/2)-(strlen(tmp)/2)), tmp);
			           break;
          }	
	   }	  
	   break;
	   	   
	   case stateGameOver:
	   {       
         if (game.multiplayer)
		 {
		    for (i=0; i<scrollRange; i=i+4) drawImage(pic4data, pic4length, 10, 70+i );		 
			drawWonMessage(8);
			storeScore(game.level); 
		 }
		 else
		 {  
		    if (game.leftScore>=MAX_SCORE)
            {	  
              for (i=0; i<scrollRange; i=i+4) 
              {
                if (game.level==5)
		        {
		           drawImage(pic16data, pic16length, 10, 70+i );
	            }
		        else
		        {
		           drawImage(pic4data, pic4length, 10, 70+i );
		        }
              }   	  
              drawWonMessage(8);	  
            }	 
            else
            {
              for (i=0; i<scrollRange; i=i+4) drawImage(pic4data, pic4length, 10, 70+i );
              drawWonMessage(8);	  
            }	 
            storeScore(game.level);  
	      }
	   }
       break;
	
	   case stateGamePause:
	   {	   
           printf("\x1b[%d;%dH%s", (yMax/2)+1, xMin+38, "PAUSE");  	   
	   }
	   break;
	   
	   case stateHelp:
	   {
          drawImage(pic11data, pic11length, 10, 60 );
		  
		  int ypos=14;		 
		  sprintf(tmp,"BUTTONS     ACTION");
		  printf("\x1b[%d;%dH%s", ypos, 22, tmp);
		  ypos+=2;
		  
		  sprintf(tmp,"(cursors)   Control paddle during game");		  
		  printf("\x1b[%d;%dH%s", ypos, 22, tmp);
		  ypos+=1;			 
		  
		  sprintf(tmp,"            Scroll through release notes");		  
		  printf("\x1b[%d;%dH%s", ypos, 22, tmp);
		  ypos+=1;			 
		  
		  sprintf(tmp,"(A) or (a)  Increase ball speed");		  
		  printf("\x1b[%d;%dH%s", ypos, 22, tmp);
		  ypos+=1;	

		  sprintf(tmp,"(B) or (b)  Decrease ball speed");		  
		  printf("\x1b[%d;%dH%s", ypos, 22, tmp);
		  ypos+=1;	
		  
		  sprintf(tmp,"(1) or (x)  Next music track");		  
		  printf("\x1b[%d;%dH%s", ypos, 22, tmp);
		  ypos+=1;	

		  sprintf(tmp,"(2) or (y)  Previous music track");		  
		  printf("\x1b[%d;%dH%s", ypos, 22, tmp);
		  ypos+=1;	

		  sprintf(tmp,"(+)         Pause during game");		  
		  printf("\x1b[%d;%dH%s", ypos, 22, tmp);
		  ypos+=1;
		  
		  sprintf(tmp,"(Home)      Go to menu screen");		  
		  printf("\x1b[%d;%dH%s", ypos, 22, tmp);
	   }
       break;

	   case stateScore:
	   { 
          struct tm *local;
          struct tm *level;
          int yoffset=14;
			
          drawImage(pic6data, pic6length, 10, 60 );
   
          printf("\x1b[%d;%dH%s", yoffset, 8,    "Level");
          printf("\x1b[%d;%dH%s", yoffset+1, 8,  "=====");
          printf("\x1b[%d;%dH%s", yoffset, 18,   "Current Date");
          printf("\x1b[%d;%dH%s", yoffset+1, 18, "============");
          printf("\x1b[%d;%dH%s", yoffset, 42,   "Level Time");
          printf("\x1b[%d;%dH%s", yoffset+1, 42, "==========");
          printf("\x1b[%d;%dH%s", yoffset, 55,   "Human");
          printf("\x1b[%d;%dH%s", yoffset+1, 55, "=====");
          printf("\x1b[%d;%dH%s", yoffset, 64,   "Computer");
          printf("\x1b[%d;%dH%s", yoffset+1, 64, "========");
	   
          for (i=0; i<=game.level; i++)
          {	   
		     printf("\x1b[%d;%dH%d", yoffset+i+2, 8, i);
	   
		     local = localtime(&scores[i].localTime);
		     printf("\x1b[%d;%dH%02d-%02d-%04d %02d:%02d:%02d", yoffset+i+2, 18, 
			   local->tm_mday, local->tm_mon+1, local->tm_year+1900, local->tm_hour, local->tm_min, local->tm_sec);

		     level = localtime(&scores[i].levelTime);
		     printf("\x1b[%d;%dH%02d:%02d:%02d", yoffset+i+2, 42, level->tm_hour, level->tm_min, level->tm_sec);
		
		     printf("\x1b[%d;%dH%d", yoffset+i+2, 55, scores[i].player1Score);
		     printf("\x1b[%d;%dH%d", yoffset+i+2, 64, scores[i].player2Score);
          }
       }
       break;
	   
	   case stateHighScore:
	   {	   
         int yoffset=14;
         struct tm *local;
         struct tm *level;
   
         // Check if highscore is reached
         for (i=0; i<=MAX_LEVEL; i++)
         {
           if ( (scores[i].player1Score>scores[i].player2Score) &&
	            ( (highscores[i].levelTime==0) ||
	              (highscores[i].levelTime>scores[i].levelTime) ||
	              ((highscores[i].levelTime==scores[i].levelTime) && (highscores[i].player1Score>scores[i].player1Score))
			    ) 
		      )
	       {
	          highscores[i].localTime=scores[i].localTime;
	          highscores[i].levelTime=scores[i].levelTime;
		      highscores[i].player1Score=scores[i].player1Score;
		      highscores[i].player2Score=scores[i].player2Score;
	       }
         }
         saveHighScoreFile(HIGHSCORE_FILENAME);
   
         drawImage(pic14data, pic14length, 10, 60 );
   
         printf("\x1b[%d;%dH%s", yoffset, 8,    "Level");
         printf("\x1b[%d;%dH%s", yoffset+1, 8,  "=====");
         printf("\x1b[%d;%dH%s", yoffset, 18,   "Current Date");
         printf("\x1b[%d;%dH%s", yoffset+1, 18, "============");
         printf("\x1b[%d;%dH%s", yoffset, 42,   "Level Time");
         printf("\x1b[%d;%dH%s", yoffset+1, 42, "==========");
         printf("\x1b[%d;%dH%s", yoffset, 55,   "Human");
         printf("\x1b[%d;%dH%s", yoffset+1, 55, "=====");
         printf("\x1b[%d;%dH%s", yoffset, 64,   "Computer");
         printf("\x1b[%d;%dH%s", yoffset+1, 64, "========");
	   
         for (i=0; i<=MAX_LEVEL; i++)
         {	   
	        //if (highscores[i].levelTime!=0)
	       {
		      printf("\x1b[%d;%dH%d", yoffset+i+2, 8, i);
	   	   
		      local = localtime(&highscores[i].localTime);
		      if (local->tm_year+1900!=1970)
		      {
		         printf("\x1b[%d;%dH%02d-%02d-%04d %02d:%02d:%02d", yoffset+i+2, 18, 
			       local->tm_mday, local->tm_mon+1, local->tm_year+1900, local->tm_hour, local->tm_min, local->tm_sec);
	          }
		      else
		      {
		         printf("\x1b[%d;%dH%02d-%02d-%04d %02d:%02d:%02d", yoffset+i+2, 18, 0, 0, 0, 0, 0, 0);	
		      }

		      level = localtime(&highscores[i].levelTime);
		      printf("\x1b[%d;%dH%02d:%02d:%02d", yoffset+i+2, 42, level->tm_hour, level->tm_min, level->tm_sec);
		
		      printf("\x1b[%d;%dH%d", yoffset+i+2, 55, highscores[i].player1Score);
		      printf("\x1b[%d;%dH%d", yoffset+i+2, 64, highscores[i].player2Score);
	        }
         }
       }
       break;
    }
	
	traceEvent(s_fn,0,"leave [void]");
}

// -----------------------------------------------------------
// BUTTONS ACTIONS
// -----------------------------------------------------------

void buttonDown(int channel)
{
   boolean flag = true;
   switch (stateMachine)
   {
      case stateMenu:
	  {    
         if (buttonSelect<maxButtons-1) buttonSelect++;
	  
         // Handle buttons events  
         while ( flag && !bPowerOff )
         {
            WPAD_ScanPads(); 	
            if (WPAD_ButtonsUp(channel) & BUTTON_DOWN) flag=false;
         }
	   }
	   break;
	  
	  case stateGame:
       if (paddles[channel].y<(yMax-paddles[channel].len-offset)) 
       {
         paddles[channel].y++;	
	  	  
	     // Bar1 Collesion
	     if (paddles[channel].x==bars[1].x)
	     {
   	       if ((paddles[channel].y+paddles[channel].len)>(bars[1].y-bars[1].len))
		   {
		      paddles[channel].y--;
		   }
	     }
	   }
	   break;	 
	   
	   case stateReleaseNotes:
	   {
	     if (releasenotes.scrollIndex<(releasenotes.maxLines-(2*MAX_NOTE_LINES))) 
		 {
		    releasenotes.scrollIndex+=MAX_NOTE_LINES-1;
		 }
		 else
		 {		 
			releasenotes.scrollIndex=(releasenotes.maxLines-MAX_NOTE_LINES);
		 }
	
		 
		 // Handle buttons events  
         while ( flag && !bPowerOff )
         {
            WPAD_ScanPads(); 	
            if (WPAD_ButtonsUp(channel) & BUTTON_DOWN) flag=false;
         }
	   }
	   break;
   }
}

void buttonUp(int channel)
{
   boolean flag = true;
   
   switch (stateMachine)
   {
      case stateMenu:
	  {    
         if (buttonSelect>0) buttonSelect--;
  
         // Handle buttons events  
         while ( flag && !bPowerOff )
         {
            WPAD_ScanPads(); 	
            if (WPAD_ButtonsUp(channel) & BUTTON_UP) flag=false;
         }
	  }
	  break;
	  
	  case stateGame:
      {
	     if (paddles[channel].y>(yMin+paddles[channel].len+2+offset)) 
         {
            paddles[channel].y--;
	  
	        // Bar0 Collesion
	        if (paddles[channel].x==bars[0].x)
	        {
	           if ((paddles[channel].y-paddles[channel].len)<(bars[0].y+bars[0].len))
		       {
		          paddles[channel].y++;
			   }
	        }
	     } 
	  }
	  break;	

	  case stateReleaseNotes:
	  {
	   	 if (releasenotes.scrollIndex>MAX_NOTE_LINES) 
		 {
		    releasenotes.scrollIndex-=(MAX_NOTE_LINES+1);
		 }
		 else
		 {
		    releasenotes.scrollIndex=0;
		 }
		 
		 // Handle buttons events  
         while ( flag && !bPowerOff )
         {
            WPAD_ScanPads(); 	
            if (WPAD_ButtonsUp(channel) & BUTTON_UP) flag=false;
         }
	  }
	  break; 
   }
}

void buttonRight(int channel)
{

   if (paddles[channel].x<(xMax-offset)) 
   {
      paddles[channel].x++;	
	  
	  // Ball Collesion
	  if (ball.x==paddles[channel].x) 
	  {
	     if ((ball.y>=(paddles[channel].y-paddles[channel].len-offset)) && 
		     (ball.y<=(paddles[channel].y+paddles[channel].len+offset)) )
		 {
		    paddles[channel].x--;
		 }
	  }
	  
	  // Bar0 Collesion
	  if (paddles[channel].x==bars[0].x)
	  {
    	  if ((paddles[channel].y-paddles[channel].len)<bars[0].y+bars[0].len)
	      {
	         paddles[channel].x--;
	      }
	  }	  
	  
	  // Bar1 Collesion
	  if (paddles[channel].x==bars[1].x)
	  {
    	  if ((paddles[channel].y+paddles[channel].len)>bars[1].y-bars[1].len)
	      {
	         paddles[channel].x--;
	      }
	  }	  
   }
}

void buttonLeft(int channel)
{
   if (paddles[channel].x>(xMin+offset)) 
   {
     paddles[channel].x--;	
	 
	  // Ball Collesion
	  if (ball.x==paddles[channel].x) 
	  {
	     if ((ball.y>=(paddles[channel].y-paddles[channel].len-offset)) && 
		     (ball.y<=(paddles[channel].y+paddles[channel].len+offset)) )
		 {
		    paddles[channel].x++;
		 }
	  }
	  
	  // Bar0 Collesion
	  if (paddles[channel].x==bars[0].x)
	  {
    	  if ((paddles[channel].y-paddles[channel].len)<bars[0].y+bars[0].len)
	      {
	        paddles[channel].x++;
	      }
	  }	  
	  
	  // Bar1 Collesion
	  if (paddles[channel].x==bars[1].x)
	  {
    	  if ((paddles[channel].y+paddles[channel].len)>bars[1].y-bars[1].len)
	      {
	         paddles[channel].x++;
	      }
	  }	  
   }
}

void buttonA(int channel)
{
   boolean flag = true;
 
   switch (stateMachine)
   {
      case stateMenu:
	  {
	     switch (buttonSelect)
		 {
		     case 0: // Play (Single Player)
			         drawEmptyScreen(true);
			         stateMachine=stateLevel;
					 game.multiplayer=false;
					 drawPlayerInfo();
					 initGame();
					 initLevel();
			         break;
					 
		     case 1: // Play (Multi player)
					 drawEmptyScreen(true);
			         stateMachine=stateLevel;
					 game.multiplayer=true;
					 drawPlayerInfo();
					 initGame();
					 initLevel();
			         break;
					 
			 case 2: // HighScore
			 		 drawEmptyScreen(true); 
					 stateMachine=stateHighScore;
					 break;
			 			 
			 case 3: // Help
			         drawEmptyScreen(true);
					 stateMachine=stateHelp;
					 break;
			 
			 case 4: // credits
			         drawEmptyScreen(true);
					 stateMachine=stateCredits;
					 break;
			 
			 case 5: // Release Notes
			         drawEmptyScreen(true);
					 stateMachine=stateReleaseNotes;
					 break;
			 
			 case 6: // Exit Homebrew channel
			         drawEmptyScreen(true);
					 drawImage(pic5data, pic5length, 10, 165 );
			         exitGame(true); 
					 break;
			 
			 case 7: // Reset Wii
			         drawEmptyScreen(true);
					 drawImage(pic5data, pic5length, 10, 165 );
			 		 exitGame(false); 
					 break;			 
	      }
       }
	   break;
	   
	   case stateLevel:
	   {
	   	 WIILIGHT_SetLevel(1);
         WIILIGHT_TurnOn();
         WIILIGHT_TurnOff();
   
   		 initLevel();
		 initBall(true);	   
         game.startTime = time(NULL);   
		  
         drawEmptyScreen(true);
         drawScore();	
 		 drawBar();
		 stateMachine=stateGame;	
	   }
	   break;
	   
	   case stateGamePause:
	   {
	      drawEmptyScreen(true);
		  stateMachine=stateGame;
	   }
	   break;
	   
	   case stateGameOver:
	   {
	      drawEmptyScreen(true); 
		  stateMachine=stateScore;		  		  
	   }
	   break;
				
	   case stateCredits:
	   {
	      drawEmptyScreen(true); 
	      stateMachine=stateMenu;
	   }
	   break;
	 
	   case stateHelp:
	   {
		  drawEmptyScreen(true); 	   
	      stateMachine=stateMenu;
	   }
	   break;

	   case stateReleaseNotes:
	   {
	      drawEmptyScreen(true); 
	      stateMachine=stateMenu;
	   }
	   break;
	   
	   case stateScore:
	   {
		  if (game.multiplayer)
		  {
		     drawEmptyScreen(true); 
		     stateMachine=stateMenu;
		  }
		  else
		  { 
		     drawEmptyScreen(true); 
		     stateMachine=stateHighScore;	  
		  }
	   }
	   break;
			
	   case stateHighScore:
	   {  
		  drawEmptyScreen(true);     
          stateMachine=stateMenu;	
	   }
	   break;
    }
	
	// Handle buttons events  
    while ( flag && !bPowerOff )
    {
       WPAD_ScanPads(); 	
       if (WPAD_ButtonsUp(channel) & BUTTON_A) flag=false;
    }
}

void button1x(int channel)
{
   boolean flag = true;
 
   MODPlay_Stop(&snd1);  
   if (musicTrack<10) musicTrack++; else musicTrack=0;   
   musicSelect(true);
   drawMusicTrack();
      
   // Handle buttons events  
   while ( flag && !bPowerOff )
   {
      WPAD_ScanPads(); 	
      if (WPAD_ButtonsUp(channel) & BUTTON_1) flag=false;
   }
}

void button2y(int channel)
{
   boolean flag = true;
 
   MODPlay_Stop(&snd1);
   if (musicTrack>0) musicTrack--; else musicTrack=10;
   musicSelect(true);
   drawMusicTrack();
      
   // Handle buttons events  
   while ( flag && !bPowerOff )
   {
      WPAD_ScanPads(); 	
      if (WPAD_ButtonsUp(channel) & BUTTON_2) flag=false;
   }
}

void buttonActions(int channel)
{
    boolean flag = true;
 
    // Rumble if key is pressed
	if (WPAD_ButtonsHeld(channel) & BUTTON_ANY )  
	{
	   WPAD_Rumble(channel,1); 
	}
	else 
	{
	   WPAD_Rumble(channel,0); 		 
	}
		  
	// Handle buttons events 
    switch (stateMachine)
	{	
       case stateMenu:
	   {
	      while ( flag && !bPowerOff )
          {		
	         WPAD_ScanPads();
	         u32 wpadheld = WPAD_ButtonsHeld(channel);
			 u32 wpaddown = WPAD_ButtonsDown(channel); 
				
		     if (wpaddown & BUTTON_UP ) 
			 {
			    buttonUp(channel);				
				flag=false;
			 }
		     if (wpaddown & BUTTON_DOWN ) 
			 {
			    buttonDown(channel);				   						  
				flag=false;
			 }
			 
		     if (wpaddown & BUTTON_A ) 
			 {
			    buttonA(channel);
				flag=false;
			 }
			 
			 if (wpadheld & BUTTON_1 ) button1x(channel);				
		     if (wpadheld & BUTTON_2 ) button2y(channel);	
		  }
	   }
	   break;
	   
	   case stateCredits:
	   {	   
	      while ( flag && !bPowerOff )
          {	     
	         WPAD_ScanPads();
	         u32 wpadheld = WPAD_ButtonsHeld(channel);  
			 u32 wpaddown = WPAD_ButtonsDown(channel);  	   						  
			 
	         if (wpaddown & BUTTON_A ) 
			 {
			    buttonA(channel);
				flag=false;
		     }
			 
			 if (wpadheld & BUTTON_1 ) button1x(channel);				
		     if (wpadheld & BUTTON_2 ) button2y(channel);	
		  }
	   }
	   break;
	   
	   case stateReleaseNotes:
	   {
	      while ( flag && !bPowerOff )
          {	         
	         WPAD_ScanPads();
			 u32 wpadheld = WPAD_ButtonsHeld(channel);  
			 u32 wpaddown = WPAD_ButtonsDown(channel);
					
             if (wpadheld & BUTTON_UP ) 
			 {
			    buttonUp(channel);	
				drawReleaseNotes();
			 }
		     if (wpadheld & BUTTON_DOWN ) 
			 {
			    buttonDown(channel);
				drawReleaseNotes();
			 }
			   						  
	         if (wpaddown & BUTTON_A ) 
			 {
			    buttonA(channel);
				flag=false;
		     }
			 
			 if (wpadheld & BUTTON_1 ) button1x(channel);				
		     if (wpadheld & BUTTON_2 ) button2y(channel);	
		  }
	   }
	   break;
	   
	   case stateHelp:
	   {
	      while ( flag && !bPowerOff )
          {	         
	         WPAD_ScanPads();
			 u32 wpadheld = WPAD_ButtonsHeld(channel);  
			 u32 wpaddown = WPAD_ButtonsDown(channel);
								   						  
	         if (wpaddown & BUTTON_A ) 
			 {
			    buttonA(channel);
				flag=false;
		     }
			 
			 if (wpadheld & BUTTON_1 ) button1x(channel);				
		     if (wpadheld & BUTTON_2 ) button2y(channel);	
		  }
	   }	   
	   break;
	   
	   case stateGame:
	   {
		  WPAD_ScanPads();
		  u32 wpadheld = WPAD_ButtonsHeld(channel);
		  u32 wpaddown = WPAD_ButtonsDown(channel);
						
		  if (wpaddown & BUTTON_HOME ) 
		  {
		     drawEmptyScreen(true); 		     
		     stateMachine=stateMenu;  
			 game.multiplayer=false;
		  }			
		  
		  if (wpadheld & BUTTON_1 ) button1x(channel);				
		  if (wpadheld & BUTTON_2 ) button2y(channel);				   				

		  if (wpadheld & BUTTON_B) 
		  {
		     if (game.delay<100) game.delay+=1;
		  }
		  
		  if (wpadheld & BUTTON_A) 
		  {
		    if (game.delay>1) game.delay-=1; else game.delay=0; 
		  }		
		 
		  if (wpadheld & BUTTON_DOWN ) buttonDown(channel);	
		  if (wpadheld & BUTTON_UP ) buttonUp(channel);		
		  if (wpadheld & BUTTON_RIGHT ) buttonRight(channel);		
		  if (wpadheld & BUTTON_LEFT ) buttonLeft(channel);		
		
		  if (wpaddown & BUTTON_PLUS ) 
		  {
		     stateMachine=stateGamePause;    
		  }
	   }
	   break;
	   
	   case stateLevel:
	   {
          while ( flag && !bPowerOff )
          {
             WPAD_ScanPads(); 
			 u32 wpadheld = WPAD_ButtonsHeld(channel);
			 u32 wpaddown = WPAD_ButtonsDown(channel);
	
             if (wpaddown & BUTTON_A) 
			 {
			    buttonA(channel);	
			    flag=false; 	  
			 }

	         if (wpaddown & BUTTON_HOME )
			 {
			    drawEmptyScreen(true); 
			    stateMachine=stateMenu;  
				flag=false; 
			 }
			 
	         if (wpadheld & BUTTON_1 ) button1x(channel);	
	         if (wpadheld & BUTTON_2 ) button2y(channel);	
          }	  
	   }
	   break;
   
       case stateGameOver:
	   {	
          while ( flag && !bPowerOff )
          {
		     WPAD_ScanPads(); 
			 u32 wpadheld = WPAD_ButtonsHeld(channel);
			 u32 wpaddown = WPAD_ButtonsDown(channel);
			 
		     if (wpaddown & BUTTON_A) 
			 {
			    buttonA(channel);	 
				flag=false; 
			 }
		     if (wpaddown & BUTTON_HOME ) 
			 {
			 	drawEmptyScreen(true); 
			    stateMachine=stateMenu;  
				flag=false; 
			 }
			 
		     if (wpadheld & BUTTON_1 ) button1x(channel);	
		     if (wpadheld & BUTTON_2 ) button2y(channel);				 		
          }
	   }
	   break;
	   
	   case stateGamePause:
	   { 
          while ( flag && !bPowerOff )
          {
		     WPAD_ScanPads(); 
			 u32 wpadheld = WPAD_ButtonsHeld(channel);
			 u32 wpaddown = WPAD_ButtonsDown(channel);
	
		     if (wpaddown & BUTTON_A)
			 { 
				buttonA(channel);
			    flag=false; 		
			 }
			 
 		     if (wpaddown & BUTTON_HOME ) 
			 {
			    drawEmptyScreen(true); 
			    stateMachine=stateMenu;  
				flag=false; 	
			 }
			 
		     if (wpadheld & BUTTON_1 ) button1x(channel);		
		     if (wpadheld & BUTTON_2 ) button2y(channel);			
  	  
		     drawTime();             
		  }	   		  
	   }
	   break;
	   	   
	   case stateScore:
	   {  
         while ( flag && !bPowerOff )
         {
		    WPAD_ScanPads(); 
			u32 wpadheld = WPAD_ButtonsHeld(channel);
			u32 wpaddown = WPAD_ButtonsDown(channel);
					
		    if (wpaddown & BUTTON_A) 
			{
				buttonA(channel);
			    flag=false; 	
		    }
			
		    if (wpadheld & BUTTON_1 ) button1x(channel);	
		    if (wpadheld & BUTTON_2 ) button2y(channel);	
          }    	
	   }
	   break;
	   
	   case stateHighScore:
	   {   
  	      while ( flag && !bPowerOff )
          {
		    WPAD_ScanPads(); 
			u32 wpadheld = WPAD_ButtonsHeld(channel);
			u32 wpaddown = WPAD_ButtonsDown(channel);
			
			if (wpaddown & BUTTON_A) 
			{
			   buttonA(channel);		
			   flag=false;
			}
		    if (wpadheld & BUTTON_1 ) button1x(channel);	
		    if (wpadheld & BUTTON_2 ) button2y(channel);	
          }  
	   }
	   break;
	}
}

// -----------------------------------------------------------
// GAME LOGIC
// -----------------------------------------------------------

void saveHighScoreFile(char* filename)
{
   char *s_fn="saveHighScoreFile";
   traceEvent(s_fn,0,"enter");
   
   int i;
   mxml_node_t *xml;
   mxml_node_t *group;
   mxml_node_t *data;   
   char tmp[MAX_LEN];
      
   xml = mxmlNewXML("1.0");
   
   group = mxmlNewElement(xml, "pong2");
   
   for(i=0; i<=MAX_LEVEL; i++)
   {
      sprintf(tmp, "level%d", i);
      data = mxmlNewElement(group, tmp);
  
      //Create Some config value
	  sprintf(tmp, "%d", (int) highscores[i].localTime);
      mxmlElementSetAttr(data, "localTime", tmp);
	  
	  sprintf(tmp, "%d", (int) highscores[i].levelTime);
	  mxmlElementSetAttr(data, "levelTime", tmp);
	  
	  sprintf(tmp, "%d", highscores[i].player1Score);
      mxmlElementSetAttr(data, "player1Score", tmp);
	  
	  sprintf(tmp, "%d", highscores[i].player2Score);
	  mxmlElementSetAttr(data, "player2Score", tmp);
   }
  
   /* now lets save the xml file to a file! */
   FILE *fp;
   fp = fopen(filename, "w");

   mxmlSaveFile(xml, fp, MXML_NO_CALLBACK);
   
   /*Time to clean up!*/
   fclose(fp);
   mxmlDelete(data);
   mxmlDelete(group);
   mxmlDelete(xml);
   
   traceEvent(s_fn,0,"leave [void]");
}

void loadHighScoreFile(char* filename)
{
   char *s_fn="loadHighScoreFile";
   traceEvent(s_fn,0,"enter [%s]",filename);
   
   int i;
   FILE *fp;
   mxml_node_t *tree=NULL;
   mxml_node_t *data=NULL;
   const char *tmp;
   char temp[MAX_LEN];
   
   /*Load our xml file! */
   fp = fopen(filename, "r");
   if (fp!=NULL)
   {
     tree = mxmlLoadFile(NULL, fp, MXML_NO_CALLBACK);
     fclose(fp);

     for(i=0; i<=MAX_LEVEL; i++)
     {
	    sprintf(temp, "level%d", i);
        data = mxmlFindElement(tree, tree, temp, NULL, NULL, MXML_DESCEND);
  
        tmp=mxmlElementGetAttr(data,"localTime");   
        if (tmp!=NULL) highscores[i].localTime=atoi(tmp); else highscores[i].localTime=0;
		
		tmp=mxmlElementGetAttr(data,"levelTime"); 
		if (tmp!=NULL) highscores[i].levelTime=atoi(tmp); else highscores[i].levelTime=0;
		
		tmp=mxmlElementGetAttr(data,"player1Score"); 
		if (tmp!=NULL) highscores[i].player1Score=atoi(tmp); else highscores[i].player1Score=0;
		
		tmp=mxmlElementGetAttr(data,"player2Score"); 
		if (tmp!=NULL) highscores[i].player2Score=atoi(tmp); else highscores[i].player2Score=0;
	 } 
   }
   else
   {
     // If file not found, create empty highscore list.
     for(i=0; i<=MAX_LEVEL; i++)
     {
       	highscores[i].localTime=0;
		highscores[i].levelTime=0;
		highscores[i].player1Score=0;
		highscores[i].player2Score=0; 
	 } 
   }
   mxmlDelete(data);
   mxmlDelete(tree);
   
   traceEvent(s_fn,0,"leave [void]");
}

void exitGame(bool mode)
{
   char *s_fn="exitGame";
   traceEvent(s_fn,0,"enter");
   
   // Stop tcp thread   
   LAN(tcp_stop_thread();)
   
   // Switch dvd light   
   WIILIGHT_TurnOff();
   
   // Stop music track
   MODPlay_Stop(&snd1);
   
   if (mode)
   {
      traceEvent(s_fn, 0,"Go back to Homebrew Channel" );
   
      traceEvent(s_fn, 0,"%s %s Stopped", PROGRAM_NAME, PROGRAM_VERSION);
	  traceEvent(s_fn, 0,"leave [void]");
	  
	  traceClose();
	
      // Exit To Homebrew Channel  
      exit(0);
   }
   else
   {
      traceEvent(s_fn, 0,"Reset Wii" );
   
      traceEvent(s_fn, 0,"%s %s Stopped", PROGRAM_NAME, PROGRAM_VERSION);
	  traceEvent(s_fn, 0,"leave [void]");
	  
	  traceClose();
	
      // Reset Wii
      SYS_ResetSystem(SYS_RESTART,0,0);
   }
}

void storeScore(int gameLevel)
{
   char *s_fn="storeScore";
   traceEvent(s_fn,0,"enter [gameLevel=%d]",gameLevel);

   scores[gameLevel].localTime=time(NULL);
   scores[gameLevel].levelTime=(time(NULL)-game.startTime); 
   scores[gameLevel].player1Score=game.leftScore;
   scores[gameLevel].player2Score=game.rightScore;
   
   traceEvent(s_fn,0,"leave [void]");
}
   
void musicSelect(bool show)
{
   char *s_fn="musicSelect";
   traceEvent(s_fn,0,"enter");
   
   traceEvent(s_fn,0,"Selected music track [%d]", musicTrack);
   
   switch (musicTrack)
   {
      case 0 : MODPlay_SetVolume( &snd1, musicVolume*MUSIC_MULTIPLER,musicVolume*MUSIC_MULTIPLER); 
	           MODPlay_SetMOD(&snd1, music0_mod);
			   MODPlay_Start(&snd1);	
			   break;	
			   
      case 1 : MODPlay_SetVolume( &snd1, musicVolume*MUSIC_MULTIPLER,musicVolume*MUSIC_MULTIPLER);
	           MODPlay_SetMOD(&snd1, music1_mod);
			   MODPlay_Start(&snd1);	
			   break;
			   
      case 2 : MODPlay_SetVolume( &snd1, musicVolume*MUSIC_MULTIPLER,musicVolume*MUSIC_MULTIPLER);
	           MODPlay_SetMOD(&snd1, music2_mod);
			   MODPlay_Start(&snd1);	
			   break;
			   
      case 3 : MODPlay_SetVolume( &snd1, musicVolume*MUSIC_MULTIPLER,musicVolume*MUSIC_MULTIPLER);
	           MODPlay_SetMOD(&snd1, music3_mod);
			   MODPlay_Start(&snd1);	
			   break;
			   
      case 4 : MODPlay_SetVolume( &snd1, musicVolume*MUSIC_MULTIPLER,musicVolume*MUSIC_MULTIPLER);
	           MODPlay_SetMOD(&snd1, music4_mod);
			   MODPlay_Start(&snd1);	
			   break;
			   
      case 5 : MODPlay_SetVolume( &snd1, musicVolume*MUSIC_MULTIPLER,musicVolume*MUSIC_MULTIPLER);
	           MODPlay_SetMOD(&snd1, music5_mod);
			   MODPlay_Start(&snd1);	
			   break;	
		   
	  case 6 : MODPlay_SetVolume( &snd1, musicVolume*MUSIC_MULTIPLER,musicVolume*MUSIC_MULTIPLER);
	           MODPlay_SetMOD(&snd1, music6_mod);
			   MODPlay_Start(&snd1);	
			   break;	
			   
	  case 7 : MODPlay_SetVolume( &snd1, musicVolume*MUSIC_MULTIPLER,musicVolume*MUSIC_MULTIPLER);
	           MODPlay_SetMOD(&snd1, music7_mod);
			   MODPlay_Start(&snd1);	
			   break;	
			   
	  case 8 : MODPlay_SetVolume( &snd1, musicVolume*MUSIC_MULTIPLER,musicVolume*MUSIC_MULTIPLER);
	           MODPlay_SetMOD(&snd1, music8_mod);
			   MODPlay_Start(&snd1);	
			   break;	
			   
	  case 9 : MODPlay_SetVolume( &snd1, musicVolume*MUSIC_MULTIPLER,musicVolume*MUSIC_MULTIPLER);
	           MODPlay_SetMOD(&snd1, music9_mod);
			   MODPlay_Start(&snd1);	
			   break;
	
	  case 10: MODPlay_SetVolume( &snd1, 0,0); 
	           MODPlay_Stop(&snd1);			   
			   break;
			   
	  default: traceEvent(s_fn,0,"ERROR: Selected music track out of range!");
			    break;
   } 
   traceEvent(s_fn,0,"leave [void]");
}

void movePlayer2()
{
   int channel=1;
   if ((ball.xMove) && (ball.x>(xMax/2)))
   {
     if ((ball.y>paddles[channel].y) && (paddles[channel].y+paddles[channel].len<(yMax-offset)))
     { 
	    paddles[channel].yPrev=paddles[channel].y;
		if ((rand() % 3) == 1 )
		{
           paddles[channel].y++;
		}
     }
     if ((ball.y<paddles[channel].y) && (paddles[channel].y-paddles[channel].len>(yMin+2+offset)))
     { 
	    paddles[channel].yPrev=paddles[channel].y;
		if ((rand() % 3) == 1 )
		{
           paddles[channel].y--;
		}
     }
   }
}

void detectScore(void)
{
   // Right score detection
   if (ball.x==(xMin+1))
   {
       SND_SetVoice(SND_GetFirstUnusedVoice(), VOICE_MONO_8BIT, 16000, 0, (u8 *) effect1_wav, effect1_wav_size, 255, 0, NULL);
       game.rightScore++;   
	   drawScore();	   
	   
	   initBall(!ball.xMove);
   }
   
   if (game.rightScore>=MAX_SCORE)	
   {		
       storeScore(game.level);  

       if (game.multiplayer)
	   {	   	  
	     if (game.level<MAX_LEVEL) 
	     {					     
		    game.level++;
		    drawEmptyScreen(true); 
		    stateMachine=stateLevel;		 
	     }
	     else
	     {	
            drawEmptyScreen(true);    
	        stateMachine=stateGameOver;
	     }
	   }
	   else
	   {
	      drawEmptyScreen(true);    
	      stateMachine=stateGameOver;
	   }
	}
   
   // Left score detection
   if (ball.x==(xMax-1))
   {
       SND_SetVoice(SND_GetFirstUnusedVoice(), VOICE_MONO_8BIT, 16000, 0, (u8 *) effect2_wav, effect2_wav_size, 0, 255, NULL);
       game.leftScore++;
	   drawScore();
	   	   
	   initBall(!ball.xMove);
    }

    if (game.leftScore>=MAX_SCORE) 
    {	       
	  storeScore(game.level);

      if (game.level<MAX_LEVEL) 
	  {					     
	    game.level++;
	    drawEmptyScreen(true); 
	    stateMachine=stateLevel;		 
	  }
	  else
	  {	
        drawEmptyScreen(true);    
	    stateMachine=stateGameOver;
	  }		   
   }
}
      
void detectCollision(int channel)
{   
   // Collision with Paddle
   if (  (ball.xMove && (ball.x==(paddles[channel].x-offset))) || 		
		 (!ball.xMove && (ball.x==(paddles[channel].x+offset))) )
   {
       if ( (ball.y>=(paddles[channel].y-paddles[channel].len-offset)) &&
              (ball.y<=(paddles[channel].y+paddles[channel].len+offset)) )
       {
	       ball.xMove=!ball.xMove;		

		   switch ( channel )
		   {
			 case 0: SND_SetVoice(SND_GetFirstUnusedVoice(), VOICE_MONO_8BIT, 8000, 0, (u8 *) effect3_wav, effect3_wav_size, 255, 255, NULL);
					 break;
						
			 case 1: SND_SetVoice(SND_GetFirstUnusedVoice(), VOICE_MONO_8BIT, 8000, 0, (u8 *) effect3_wav, effect3_wav_size, 255, 255, NULL);
					 break;
		   }   
	   }
   }
   
   // Collision with Bar
   if ( 
        (ball.xMove && (ball.x==(bars[channel].x-1))) || 
        (!ball.xMove && (ball.x==(bars[channel].x+1)))  
	  ) 
   {
     if ( 
	      (bars[channel].len>0) && 
	      (ball.y>=(bars[channel].y-bars[channel].len-1)) && 
		  (ball.y<=(bars[channel].y+bars[channel].len+1)) 
		)
     {
	   SND_SetVoice(SND_GetFirstUnusedVoice(), VOICE_MONO_8BIT, 8000, 0, (u8 *) effect3_wav, effect3_wav_size, 255, 255, NULL);
       ball.xMove=!ball.xMove;	
 	 }	 
   }	
}

  
void moveBall(void)
{  
   if (ball.counter++>game.delay)
   {
     // Detection and draw current score
	 detectScore();
		
	 ball.counter=0;
   
     ball.xPrev=ball.x;
     ball.yPrev=ball.y;
        
     // Move the bal
     if (ball.xMove)
     {
        // Move from left to right
	    if (ball.x<(xMax-offset)) 
	    {
	       ball.x++; 
	    }
	    else 
	    {
		   SND_SetVoice(SND_GetFirstUnusedVoice(), VOICE_MONO_8BIT, 8000, 0, (u8 *) effect3_wav, effect3_wav_size, 255, 255, NULL);
	       ball.xMove=false;	  
		   ball.x--;
	    }
     }
     else
     {
        // Move from right to left
        if (ball.x>(xMin+offset)) 
	    {
	       ball.x--; 
	    }
 	    else 
 	    {
		   SND_SetVoice(SND_GetFirstUnusedVoice(), VOICE_MONO_8BIT, 8000, 0, (u8 *) effect3_wav, effect3_wav_size, 255, 255, NULL);
	       ball.xMove=true;	
		   ball.x++;
	    }
     }
   
     if (ball.yMove)
     {
        // Move from up to down
	    if (ball.y<(yMax-offset)) 
	    {
	       ball.y++; 
	    }
	    else 
	    {
		   SND_SetVoice(SND_GetFirstUnusedVoice(), VOICE_MONO_8BIT, 8000, 0, (u8 *) effect3_wav, effect3_wav_size, 255, 255, NULL);
	       ball.yMove=false;	  
		   ball.y--;
	    }
     }
     else
     {
        // Move from down to up
        if (ball.y>(yMin+2+offset)) 
	    {
	       ball.y--; 
	    }
	    else 
	    {
		   SND_SetVoice(SND_GetFirstUnusedVoice(), VOICE_MONO_8BIT, 8000, 0, (u8 *) effect3_wav, effect3_wav_size, 255, 255, NULL);
	       ball.yMove=true;	
		   ball.y++;
        }
	  }
   }
}

void initButtons()
{
   char *s_fn="initButtons";
   traceEvent(s_fn,0,"enter");
	
   switch( stateMachine )
   { 
      case stateMenu:
	  {
	     maxButtons=8;

	     buttons[0].x=30;
		 buttons[0].y=13;
         strcpy(buttons[0].label,"PLAY (ONE PLAYER)");

	     buttons[1].x=30;
		 buttons[1].y=14;
         strcpy(buttons[1].label,"PLAY (TWO PLAYERS)");
		 
		 buttons[2].x=30;
		 buttons[2].y=15;
         strcpy(buttons[2].label,"HIGH SCORE");
		 
	     buttons[3].x=30;
		 buttons[3].y=16;
         strcpy(buttons[3].label,"HELP");
		 
		 buttons[4].x=30;
		 buttons[4].y=17;
         strcpy(buttons[4].label,"CREDITS");
		 		 
		 buttons[5].x=30;
		 buttons[5].y=18;
         strcpy(buttons[5].label,"RELEASE NOTES");
		 
		 buttons[6].x=30;
		 buttons[6].y=20;
         strcpy(buttons[6].label,"EXIT TO HBC");

		 buttons[7].x=30;
		 buttons[7].y=21;
         strcpy(buttons[7].label,"RESET WII");
      }
	  break;	  
   }
   
   traceEvent(s_fn,0,"leave [void]");
}

// Init Game.  	
void initGame(void)
{	
	char *s_fn="initGame";
	traceEvent(s_fn,0,"enter");

    int i;
	game.level=0;
	game.delay=START_DELAY;
	game.prevSecond=0;
		
	for (i=0; i<MAX_LEVEL;i++)
	{
	   scores[i].localTime=0;
	   scores[i].levelTime=0;
       scores[i].player1Score=0;
	   scores[i].player2Score=0;
	}
	
	traceEvent(s_fn,0,"leave [void]");
}

// Init. Game Level
void initLevel(void)
{
	char *s_fn="initLevel";
	traceEvent(s_fn,0,"enter");
	
	// First Paddle (Human)
	paddles[0].x=xMin+3;
	paddles[0].xPrev=paddles[0].x;
	paddles[0].y=(yMax/2)+2;
	paddles[0].yPrev=paddles[0].y;
				
	// Second Paddle (Computer)
	paddles[1].x=xMax-3;
	paddles[1].xPrev=paddles[1].x;
	paddles[1].y=(yMax/2)+2;
	paddles[1].yPrev=paddles[1].y;
	
    // First Bar		
	bars[0].x=(xMax/2);
	bars[0].y=yMin+2;	
	
	// Second Bar
	bars[1].x=(xMax/2);
	bars[1].y=yMax;
				
	game.leftScore=0;
	game.rightScore=0;
	game.startTime = time(NULL);
	
	// Init Paddle and Bar Length
	switch (game.level)
	{	
	   case 0: 	if (game.multiplayer)
				{
	               paddles[0].len=4;
				   paddles[1].len=4;	
				}
				else
				{
	               paddles[0].len=4;
				   paddles[1].len=3;				
				}
				
				// No bars 							
				bars[0].len=0;
				bars[1].len=0;
				break;

	   case 1:  if (game.multiplayer)
				{
				  paddles[0].len=3;
				  paddles[1].len=3;
				}
				else
				{
				  paddles[0].len=3;
				  paddles[1].len=3;
				}
				
				// No bars
				bars[0].len=0;
				bars[1].len=0;
				break;
		
	   case 2:  if (game.multiplayer)
				{
				   paddles[0].len=2;
				   paddles[1].len=2;
				}
				else
				{
				   paddles[0].len=2;
				   paddles[1].len=3;
				}
				
				// Increes bar size 
				bars[0].len=4;
				bars[1].len=4;
				break;
		
	   case 3:  if (game.multiplayer)
				{
					paddles[0].len=1;	
					paddles[1].len=1;
				}
				else
				{
					paddles[0].len=1;	
					paddles[1].len=3;
				}
				
				// Increes bar size 
				bars[0].len=6;
				bars[1].len=6;
				break;
				
	   case 4:  if (game.multiplayer)
				{
					paddles[0].len=1;	
					paddles[1].len=1;
				}
				else
				{
					paddles[0].len=1;	
					paddles[1].len=3;
				}
				
				// Increes bar size 
				bars[0].len=8;
				bars[1].len=8;
				break;
				
	   case 5:  if (game.multiplayer)
				{
					paddles[0].len=0;	
					paddles[1].len=0;
				}
				else
				{
					paddles[0].len=0;	
					paddles[1].len=4;
				}
				
				// Increes bar size 
				bars[0].len=8;
				bars[1].len=8;
				break;
	}					
	drawLevel();	
	
	traceEvent(s_fn,0,"leave [void]");
}

void initReleaseNotes(void)
{
   char *s_fn="initReleaseNotes";
   traceEvent(s_fn,0,"enter");
	
	
   int i;
   char *buffer=NULL;
  
   if (!releasenotes.enabled)
   {
     LAN( buffer=tcp_get_releasenote(); )
     if ((buffer!=NULL) && (strlen(buffer)>0))
     {
	   releasenotes.maxLines=0;
       releasenotes.enabled=true;
       releasenotes.scrollIndex=0;	
	   strncpy(releasenotes.data,buffer,MAX_BUFFER_SIZE);
	   releasenotes.len=strlen(releasenotes.data);
   	   
	   for (i=0;i<releasenotes.len;i++) 
	   {
	      if (releasenotes.data[i]=='\n') 
		  {
		     releasenotes.data[i]=0x00;
		     releasenotes.maxLines++;
		  }
	   }
	 }
   }
   
   traceEvent(s_fn,0,"leave [void]");
}

// Init. Ball
void initBall(boolean direction)
{
	char *s_fn="initBall";
	traceEvent(s_fn,0,"enter");

	// Cleanup old position of ball
    if ((ball.y!=ball.yPrev) || (ball.x!=ball.xPrev))
    {
      printf("\x1b[%d;%dH%c",ball.y,ball.x,255);
    }
	
	// Reset Ball
	ball.x = (xMax/2);
	if (!direction) ball.x=ball.x+10+(rand() % 20) ; else ball.x=ball.x-10-(rand() % 20);
	ball.xPrev= ball.x;
	ball.xMove = direction;   
	 
	ball.y = yMin+2+offset;
	ball.yPrev= ball.y;    
	ball.yMove = direction;   
	
	ball.counter=0; 
	
	traceEvent(s_fn,0,"leave [void]");
}

//	PowerOff callback function.
void doPowerOff( void )
{
	char *s_fn="doPowerOff";
	traceEvent(s_fn,0,"enter");
	
	bPowerOff = true;
	
	traceEvent(s_fn,0,"leave [void]");
	return;
}

//	PowerOff callback function for the Wii Remote power button.
void doPadPowerOff( s32 chan )
{
	char *s_fn="doPadPowerOff";
	traceEvent(s_fn,0,"enter");

	if ( chan == WPAD_CHAN_0 )
	{
		bPowerOff = true;
	}
	
	traceEvent(s_fn,0,"leave [void]");
	return;
}

void initThreads(void)
{ 
   char *s_fn="initThreads";
   traceEvent(s_fn,0,"enter");
   
   char userData1[MAX_LEN];
   char userData2[MAX_LEN];

   // Set userData1   		 
   memset(userData1,0x00,sizeof(userData1));
   sprintf(userData1,"%s=%s",PROGRAM_NAME,PROGRAM_VERSION);
		
   // Get userData2 
   memset(userData2,0x00,sizeof(userData2));
   sprintf(userData2,"appl=%s",PROGRAM_NAME);
	   
   LAN( tcp_start_thread(PROGRAM_NAME, PROGRAM_VERSION, 
						ID1, URL1, 
						ID2, URL2, 
						ID3, URL3, 
						ID4, URL4, 
						URL_TOKEN, userData1, userData2); )
   
   traceEvent(s_fn,0,"leave [void]");
}

void initStateMachine(void)
{	
	if (stateMachine!=prevStateMachine) initButtons();
				 
	switch (stateMachine)
	{    
      case stateMenu:  initReleaseNotes();					  
			           break;
	    
      case stateGame:  if (!game.multiplayer) movePlayer2();
					   detectCollision(0);
					   detectCollision(1);
					   moveBall();
					   break;
	}
	
	prevStateMachine=stateMachine;
}

// -----------------------------------------------------------
// MAIN
// -----------------------------------------------------------

int main(int argc, char **argv) 
{	   	
    char *s_fn = "main";
	
	releasenotes.enabled=false;

	// Initialise the video system
	VIDEO_Init();
	
	// This function initialises the attached controllers
	WPAD_Init();
	
	// And this one gives us access to the accelerometers and infrared.
	WPAD_SetDataFormat(WPAD_CHAN_ALL, WPAD_FMT_BTNS_ACC_IR);
	
	// Wiimote is shutdown after 300 seconds of innactivity.
	WPAD_SetIdleTimeout(300); 
  
 	// Set Shutdown Callbacks.
	SYS_SetPowerCallback( doPowerOff );
	WPAD_SetPowerButtonCallback( doPadPowerOff );
	
	// Obtain the preferred video mode from the system
	// This will correspond to the settings in the Wii menu
	rmode = VIDEO_GetPreferredMode(NULL);
	
	// allocate 2 framebuffers for double buffering
	frameBuffer[0] = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
		
	// Initialise the console, required for printf
	console_init(frameBuffer[0],20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);
	
	// Set up the video registers with the chosen mode
	VIDEO_Configure(rmode);
	
	if (rmode->xfbHeight==528)
	{
	    // TV mode PAL 50Hz
	    xMin = 0;
        yMin = 0;
		xMax = 79;
        yMax = 29;
		scrollRange=100;	
        yjpegOffset = 25;   
	}
	else
	{      
	    // TV mode PAL 60Hz
	    xMin = 0;
        yMin = 1;
        xMax = 79;
        yMax = 26;
		scrollRange=80;
		yjpegOffset = 0;
	}
	
	// Tell the video hardware where our display memory is
	VIDEO_SetNextFramebuffer(frameBuffer[0]);
	
	// Make the display visible
	VIDEO_SetBlack(FALSE);

	// Flush the video register changes to the hardware
	VIDEO_Flush();

	// Wait for Video setup to complete
	VIDEO_WaitVSync();
	if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();
  
	// Init Wii DVD rom lights
	WIILIGHT_Init();	

    // Init Fat
    fatInitDefault();
	
	// Open trace module
	traceOpen(TRACE_FILENAME);
	
	traceEvent(s_fn, 0,"%s %s Started", PROGRAM_NAME, PROGRAM_VERSION);

    // Init Sound engine	
	SND_Init(INIT_RATE_48000); 
	MODPlay_Init(&snd1);
    SND_Pause(0);
		
	// Start music			
	musicSelect( false);
			
	// init threads
	initThreads();

	// Load highscore xml file (if available)
	loadHighScoreFile(HIGHSCORE_FILENAME);
		
	// Init game settings	
	initGame();
	initLevel();
	initBall(true);
	
    // show intro screens
    drawIntroSceen(0);
	drawIntroSceen(1);
	drawIntroSceen(2);
		
	// Workarround to reset this value
	yjpegOffset = 0; 
			
	// Draw gameboard
	drawGameBoard();	
	drawPlayerInfo();
						  	
	// Endless loop
	while(!bPowerOff) 
	{  
	   // Init Statemachine;
	   initStateMachine();
	
       // Draw screen 		
       drawScreen();
	   
	   // Proccess button action.
	   buttonActions(WPAD_CHAN_0);
	   if (stateMachine==stateGame && game.multiplayer) buttonActions(WPAD_CHAN_1);
	   						   
	   // Flush and Wait for the next frame
       VIDEO_SetNextFramebuffer(frameBuffer[0]); 
	   VIDEO_Flush();
	   VIDEO_WaitVSync();
	}
		
	// Shut the system down.
	if ( bPowerOff )
	{
		traceEvent(s_fn, 0,"Shut the system down");
		traceEvent(s_fn, 0,"%s %s Stopped", PROGRAM_NAME, PROGRAM_VERSION);
		traceClose();
		
		SYS_ResetSystem( SYS_POWEROFF, 0, 0 );
    }
	
	return 0;
}

