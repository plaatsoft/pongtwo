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