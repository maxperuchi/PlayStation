#include "System.h"
#include "Sound.h"
#include "Sprite.h"
#include "DataManager.h"
#include "controller.h"
#include "common.h"
#include "game.h"
#include "drawing.h"
#include "board.h"
#include "player.h"

int main() {
	
	initialize();
	
	while(1) {
		
		update();
		
		draw();
		
		display();
	}
}

void initialize() {
	
	System_Init(MODE_NTSC, VMODE_16BITS, 320, 240, GsNONINTER, 0);
	
	loadGameData();
	
	initializePad();		
		
	initializeBoard();
}


void draw() {
		
	createFrame();
	
	drawBackground();
		
	drawTitle();
	
	if (checkWinner() == 1)
	{
		drawWinner();
		return;
	}
	
	if (checkForDeuce() == 1)
	{
		drawDeuce();
		return;
	}
	
	drawBoard();
	
	drawPlayer();
}

void update()
{
    int r = readPads();
	
	if (r == 1)
		Sound_Play(1);
	if (r == 2)
		Sound_Play(0);
}