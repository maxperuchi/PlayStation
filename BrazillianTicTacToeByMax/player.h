Position getNextFreePosition()
{
	for (i = 0; i < 9; i++)
	{	
		if (boardPositions[i].status == 0)
		{
			return boardPositions[i];
		}
	}
	
	return playerPosition;
}

int readPads()
{		
	padUpdate();
		
	if ( (currentPlayer == 1 && padCheckPressed(Pad1Up)) || (currentPlayer == 2 && padCheckPressed(Pad2Up)) )
	{
		if (playerPosition.pos == 0 || 
			playerPosition.pos == 1 ||
			playerPosition.pos == 2)
			{
				return 0;
			}
			
		if (boardPositions[playerPosition.pos - 3].status == 0)
		{
			playerPosition = boardPositions[playerPosition.pos - 3];
			return 1;
		}
		
		if (boardPositions[playerPosition.pos - 6].status == 0)
		{
			playerPosition = boardPositions[playerPosition.pos - 6];
			return 1;
		}
		
		return 0;
	}
	
	if ( (currentPlayer == 1 && padCheckPressed(Pad1Down)) || (currentPlayer == 2 && padCheckPressed(Pad2Down)) )
	{
		if (playerPosition.pos == 6 || 
			playerPosition.pos == 7 ||
			playerPosition.pos == 8)
			{
				return 0;
			}
			
		if (boardPositions[playerPosition.pos + 3].status == 0)
		{
			playerPosition = boardPositions[playerPosition.pos + 3];
			return 1;
		}
		
		if ((playerPosition.pos != 4) && boardPositions[playerPosition.pos + 6].status == 0)
		{
			playerPosition = boardPositions[playerPosition.pos + 6];
			return 1;
		}
		
		return 0;
	}
	
	if ( (currentPlayer == 1 && padCheckPressed(Pad1Left)) || (currentPlayer == 2 && padCheckPressed(Pad2Left)) )
	{
		if (playerPosition.pos == 0 || 
			playerPosition.pos == 3 ||
			playerPosition.pos == 6)
			{
				return 0;
			}
			
		if ((playerPosition.pos - 1 >= 0) && boardPositions[playerPosition.pos - 1].status == 0)
		{
			playerPosition = boardPositions[playerPosition.pos - 1];
			return 1;
		}
		
		if ((playerPosition.pos - 1 > 0) && boardPositions[playerPosition.pos - 2].status == 0)
		{
			playerPosition = boardPositions[playerPosition.pos - 2];
			return 1;
		}
		
		return 0;
	}
	
	if ( (currentPlayer == 1 && padCheckPressed(Pad1Right)) || (currentPlayer == 2 && padCheckPressed(Pad2Right)) )
	{
		if (playerPosition.pos == 2 || 
			playerPosition.pos == 5 ||
			playerPosition.pos == 8)
			{
				return 0;
			}
			
		if (boardPositions[playerPosition.pos + 1].status == 0)
		{
			playerPosition = boardPositions[playerPosition.pos + 1];
			return 1;
		}
		
		if (boardPositions[playerPosition.pos + 2].status == 0)
		{
			playerPosition = boardPositions[playerPosition.pos + 2];
			return 1;
		}
		
		return 0;
	}
	
	if ( (currentPlayer == 1 && padCheckPressed(Pad1Cross)) || (currentPlayer == 2 && padCheckPressed(Pad2Cross)) )
	{
		if (boardPositions[playerPosition.pos].status == 0)
		{			
			boardPositions[playerPosition.pos].status = currentPlayer;
			
			playerPosition = getNextFreePosition();
			
			if (currentPlayer == 2)
			{
				currentPlayer = 1;
			}
			else
			{
				currentPlayer = 2;
			}
			
			return 2;
		}
	}
	
	if ( padCheckPressed(Pad1Triangle) || padCheckPressed(Pad2Triangle) )
	{
		resetGame();
		return 3;
	}
	
	return 0;
}

int checkForWin(int player)
{
	if (boardPositions[0].status == player &&
		boardPositions[1].status == player &&
		boardPositions[2].status == player)
	{
		return player;
	}
	
	if (boardPositions[3].status == player &&
		boardPositions[4].status == player &&
		boardPositions[5].status == player)
	{
		return player;
	}
	
	if (boardPositions[6].status == player &&
		boardPositions[7].status == player &&
		boardPositions[8].status == player)
	{
		return player;
	}
	
	if (boardPositions[0].status == player &&
		boardPositions[4].status == player &&
		boardPositions[8].status == player)
	{
		return player;
	}
	
	if (boardPositions[2].status == player &&
		boardPositions[4].status == player &&
		boardPositions[6].status == player)
	{
		return player;
	}
	
	if (boardPositions[0].status == player &&
		boardPositions[3].status == player &&
		boardPositions[6].status == player)
	{
		return player;
	}
	
	if (boardPositions[1].status == player &&
		boardPositions[4].status == player &&
		boardPositions[7].status == player)
	{
		return player;
	}
	
	if (boardPositions[2].status == player &&
		boardPositions[5].status == player &&
		boardPositions[8].status == player)
	{
		return player;
	}
	
	return 0;
}

int checkWinner()
{
	winner = checkForWin(1);
	if (winner == 0)
	{
		winner = checkForWin(2);
	}
	
	if (winner > 0)
	{
		return 1;
	}
	
	return 0;
}