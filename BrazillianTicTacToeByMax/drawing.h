void drawBackground()
{	
	Sprite_SetPosition(&bg1, 0, 0);
	Sprite_DrawFast(&bg1, ot);
	
	Sprite_SetPosition(&bg2, 256, 0);
	Sprite_DrawFast(&bg2, ot);
}

void drawGame(Position p)
{
	if (p.status == 1)
	{		
		drawPlayer1(gameOffsetX + p.x + 12, gameOffsetY + p.y + 35);
	}
	
	if (p.status == 2)
	{
		drawPlayer2(gameOffsetX + p.x + 12, gameOffsetY + p.y + 35);
	}
}

void drawPlayer1(int x, int y)
{
	Sprite_SetPosition(&ticx, x, y);
	Sprite_DrawFast(&ticx, ot);
}

void drawPlayer2(int x, int y)
{
	Sprite_SetPosition(&tico, x, y);
	Sprite_DrawFast(&tico, ot);
}

void drawBoard() 
{
	Sprite_SetPosition(&board, gameOffsetX + 10, gameOffsetY + 30);
	Sprite_DrawFast(&board, ot);
			
	for (i = 0; i < 9; i++)
	{
		if (boardPositions[i].status > 0)
		{
			drawGame(boardPositions[i]);
		}
	}
}

void drawPlayer() 
{
	if (currentPlayer == 1)
	{
		drawPlayer1(gameOffsetX + playerPosition.x + 12, gameOffsetY + playerPosition.y + 35);
	}
	else
	{
		drawPlayer2(gameOffsetX + playerPosition.x + 12, gameOffsetY + playerPosition.y + 35);
	}	
}

void drawTitle()
{
	Sprite_SetPosition(&title, 55, 10);
	Sprite_DrawFast(&title, ot);
}

void drawWinner()
{
	if (winner == 1)
	{
		Sprite_SetPosition(&p1wins, 60, 200);
		Sprite_DrawFast(&p1wins, ot);
	}
	else if (winner == 2)
	{
		Sprite_SetPosition(&p2wins, 60, 200);
		Sprite_DrawFast(&p2wins, ot);
	}
}

void drawDeuce()
{
	Sprite_SetPosition(&deuce, 110, 200);
	Sprite_DrawFast(&deuce, ot);
}