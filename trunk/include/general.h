/**
 *
 * @file
 * @brief The file contain the general defines
 *
 * @mainpage Wii Pong2 Documentation
 * @image html pong2.png
 * Welcome to the Pong2 documentation.
 *
 * @section Introduction
 * Pong2 is a 2D classic game for the Nintendo Wii.
 *
 * @section Links
 * Website: http://www.plaatsoft.nl\n
 * Code: http://code.google.com/p/pongtwo\n
 *
 * @section Credits
 * Documentation  : wplaat\n
 *
 * @section WishList
 *   - Use GRRLIB as grapical engine.
 *   - Add support for GameCube controller.
 *
 * @section ReleaseNotes
 *   <b>XX-XX-XXXX Version 1.0 (Up coming release)</b>
 *   - GUI:
 *    - Update main menu screen information.
 *   - Core:
 *    - Improve network thread.
 *   - General:
 *    - Added source code to Google Code Repository
 *    - Added source code documentation (Javadoc style).
 *    - Added Doxygen (automatic documentation generation tool) config file. 
 *    - Build game with devkitPPC r19 compiler.
 *
 *   <b>15-11-2009 Version 0.99</b>
 *   - GUI:
 *    - Update main menu screen information.
 *   - Core:
 *    - Added functionality to trace game debug events to file.
 *    - Use the asndlib (part of libogc) now as standard sound engine.
 *    - Improve network thread.
 *    - Upgrade libmxml library to 2.6.
 *    - Upgrade libfat library to 1.0.6.
 *    - Upgrade libogc library to 1.8.0.
 *   - General:
 *    - Maintenance release.
 *    - Build game with devkitPPC r19 compiler.
 *
 *   <b>17-02-2009 Version 0.98</b>
 *    - GUI:
 *     - Update main menu screen information.
 *    - Core:
 *     - It took a long time but now pong2 support multi player mode.
 *    - General:
 *     - Build game with devkitPPC r16 compiler.
 *
 *   <b>03-02-2009 Version 0.97</b>
 *   - HotFix: Set start level to zero each first game.
 *   - HotFix: Remove typo on help screen.
 *   - Release notes screen is now showing information fetch from internet.
 *   - Added up and down cursor event to scroll through release notes.
 *   - Build game with devkitPPC r16 compiler.
 * 
 *   <b>01-02-2009 Version 0.96</b>
 *   - Improve third intro screen.
 *   - Added small game menu.
 *   - Added credits screen
 *   - Improve help screen.
 *   - Added release notes screen.
 *   - Increase http receive buffer size to 8196 bytes.
 *   - Use only one unique cookie number during the game.
 *   - Split game logic, button events and screen output in source code.
 *   - Build game with devkitPPC r16 compiler.
 *
 *   <b>15-01-2009 Version 0.95</b>
 *   - Update url on intro screens to www.plaatsoft.nl (My new domain).
 *   - Improve intro screen positioning by PAL 50Hz TV mode.
 *   - Network thread status is showed on screen.
 *   - Bugfix: Highscore is now always loaded correctly.
 *   - Build game with devkitPPC r16 compiler.
 *
 *   <b>20-12-2008 Version 0.94</b>
 *   - Added SDHC card support.
 *   - Added power down button support.
 *   - Added win screen if players wins all levels.
 *   - Update ligogc library to 1.7.1
 *   - Build game with devkitPPC r16 compiler.
 *
 *   <b>02-12-2008 Version 0.93</b>
 *   - Improve http (new version check) thread.
 *   - Build game with devkitPPC r15 compiler.
 *
 *   <b>21-11-2008 Version 0.92</b>
 *   - Added threaded network check for new version.
 *   - Solved some minor reported bugs.
 *   - Added GNU GPL2 statement in source code.
 *   - Build game with devkitPPC r15 compiler.
 *
 *   <b>12-11-2008 Version 0.91</b>
 *   - Added high Score screen.
 *   - High scores are saved (.xml format) on your SD card.
 *   - Added better game sound effects.
 *   - Build game with devkitPPC r15 compiler.
 *   
 *   <b>02-11-2008 Version 0.90</b>
 *   - Added new welcome screens.
 *   - Improved game images.
 *   - Added help screen (Minus button).
 *   - Created new homebrew game logo.
 *   - Build game with devkitPPC r15 compiler.
 *
 *   <b>31-10-2008 Version 0.80</b>
 *   - Added support for Wii Classic Controller.
 *   - Added two bars on the Game board (Game Level > 2 and higher).
 *   - Added game level six.
 *   - Build game with devkitPPC r15 compiler.
 *
 *   <b>27-10-2008 Version 0.70</b>
 *   - Improved goodbye screen.
 *   - Added support for 60Hz screens.
 *   - Build game with devkitPPC r15 compiler.
 *
 *   <b>23-10-2008 Version 0.60</b>
 *   - Fixed two bugs in result screen.
 *   - Improved game images.
 *   - Replaced two music tracks.
 *   - Made source code available.
 *   - Build game with devkitPPC r15 compiler.
 *
 *   <b>22-10-2008 Version 0.50</b>
 *   - Added a game score overview screen.
 *   - Start ball position is random now.
 *   - Added (impossible) level five.
 *   - Build game with devkitPPC r15 compiler.
 *
 *   <b>21-10-2008 Version 0.40</b>
 *   - Added 4 game levels.
 *   - Improved game board layout.
 *   - Added game clock.
 *   - Added pause (+) button.
 *   - Build game with devkitPPC r15 compiler.
 *
 *   <b>20-10-2008 Version 0.30</b>
 *   - First release for public use.
 *   - Added a nice start screen.
 *   - Ball speed can now be controlled by A and B buttons.
 *   - 10 tracks of background music added.
 *   - Music track can be controlled with 1 and 2 button.
 *   - Build game with devkitPPC r15 compiler.
 *   
 *   <b>19-10-2008 Version 0.20</b>
 *   - Improved paddle control.
 *   - Improve screen layout.
 *   - Build game with devkitPPC r15 compiler.
 *
 *   <b>18-10-2008 Version 0.10</b>
 *   - Started programming.
 *   - Gameboard ready.
 *   - Basic game logic ready.
 *   - Use libogc 1.6.0 as Wii Interface library
 *   - Build game with devkitPPC r15 compiler.
 *
 * @section Licence
 * Copyright (c) 2008-2010 Plaatsoft
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

// -----------------------------------------------------------
// DEFINES
// -----------------------------------------------------------

#define LAN(X) X

#define PROGRAM_NAME	   "Pong2"
#define PROGRAM_VERSION    "0.99"
#define RELEASE_DATE       "19-11-2009" 
#define MAX_SCORE          10
#define MAX_LEVEL          5
#define MAX_LEN			   256
#define MAX_BARS		   2
#define MAX_PADDLES		   2
#define MAX_BUTTONS        10
#define MAX_BUFFER_SIZE	   8196
#define MAX_NOTE_LINES     11
#define START_DELAY        0
#define MUSIC_MULTIPLER	   5

// Check latest available version 
#define URL1                "http://www.plaatsoft.nl/service/releasenotes1.html"
#define ID1			        "UA-6887062-1"

// Fetch Release notes
#define URL2                "http://www.plaatsoft.nl/service/releasenotes1.html"
#define ID2				    "UA-6887062-1"

// Set Get Today HighScore
#define URL3                "http://www.plaatsoft.nl/service/score_set_today.php"
#define ID3				    "UA-6887062-1"

// Set Get Global HighScore
#define URL4                "http://www.plaatsoft.nl/service/score_set_global.php"
#define ID4				    "UA-6887062-1"

#define URL_TOKEN           " Version "
#define HIGHSCORE_FILENAME  "sd:/apps/pong2/highscore.xml"

// Local trace (debug) file
#define TRACE_FILENAME      "sd:/apps/pong2/pong2.trc"

#define BUTTON_ANY      (WPAD_BUTTON_A     | WPAD_BUTTON_B)
#define BUTTON_A        (WPAD_BUTTON_A     | WPAD_CLASSIC_BUTTON_A)
#define BUTTON_B        (WPAD_BUTTON_B     | WPAD_CLASSIC_BUTTON_B)
#define BUTTON_1        (WPAD_BUTTON_1     | WPAD_CLASSIC_BUTTON_X)
#define BUTTON_2        (WPAD_BUTTON_2     | WPAD_CLASSIC_BUTTON_Y)
#define BUTTON_HOME     (WPAD_BUTTON_HOME  | WPAD_CLASSIC_BUTTON_HOME)
#define BUTTON_UP       (WPAD_BUTTON_UP    | WPAD_CLASSIC_BUTTON_UP)
#define BUTTON_DOWN     (WPAD_BUTTON_DOWN  | WPAD_CLASSIC_BUTTON_DOWN)
#define BUTTON_LEFT     (WPAD_BUTTON_LEFT  | WPAD_CLASSIC_BUTTON_LEFT)
#define BUTTON_RIGHT    (WPAD_BUTTON_RIGHT | WPAD_CLASSIC_BUTTON_RIGHT)
#define BUTTON_PLUS     (WPAD_BUTTON_PLUS  | WPAD_CLASSIC_BUTTON_PLUS)
#define BUTTON_MINUS    (WPAD_BUTTON_MINUS | WPAD_CLASSIC_BUTTON_MINUS)

// -----------------------------------------------------------
// TYPEDEFS
// -----------------------------------------------------------

typedef struct
{
   time_t localTime;
   time_t levelTime; 
   int    player1Score; 
   int    player2Score;
} 
score;

score scores[MAX_LEVEL+1];
score highscores[MAX_LEVEL+1];

struct
{
   int    x;
   int    xPrev;
   bool   xMove; 
   int    y;
   int    yPrev;
   bool   yMove;    
   int    counter;
}
ball;

typedef struct 
{
   int    x;
   int    xPrev;
   int    y;
   int    yPrev;
   int    len;
}
paddle;

paddle paddles[MAX_PADDLES];

typedef struct
{
   int    x;
   int    y;
   int    len;
}
bar;

bar bars[MAX_BARS];
   
typedef struct
{
   int   x;
   int   y;
   char  label[MAX_LEN];
}
button;

button buttons[MAX_BUTTONS];

struct
{
   int    prevSecond;  
   int    delay;
   int    leftScore;
   int    rightScore;
   int    level;
   time_t startTime;
   bool   multiplayer;
}
game;
     
struct
{
   char data[MAX_BUFFER_SIZE];
   int  len;
   int  maxLines;
   int  scrollIndex;
   bool enabled;
}
releasenotes;

// -----------------------------------------------------------
// ENUMS
// -----------------------------------------------------------
 
enum
{
   stateMenu=0,
   stateGame=1,
   stateLevel=2,
   stateGameOver=3,
   stateGamePause=4,
   stateScore=5,
   stateHighScore=6,
   stateHelp=7,
   stateCredits=8,
   stateReleaseNotes=9,
   stateGoodbye=10,
   stateNone=11
};

// -----------------------------------------------------------
// The End
// -----------------------------------------------------------