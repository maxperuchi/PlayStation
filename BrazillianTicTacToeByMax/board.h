void initializeBoard()
{
	boardPositions[0].pos = 0;
	boardPositions[0].x = 0;
	boardPositions[0].y = 0;
	boardPositions[0].status = 0;
	
	boardPositions[1].pos = 1;
	boardPositions[1].x = 35;
	boardPositions[1].y = 0;
	boardPositions[1].status = 0;
	
	boardPositions[2].pos = 2;
	boardPositions[2].x = 68;
	boardPositions[2].y = 0;
	boardPositions[2].status = 0;
	
	boardPositions[3].pos = 3;
	boardPositions[3].x = 0;
	boardPositions[3].y = 36;
	boardPositions[3].status = 0;
	
	boardPositions[4].pos = 4;
	boardPositions[4].x = 34;
	boardPositions[4].y = 36;
	boardPositions[4].status = 0;
		
	boardPositions[5].pos = 5;
	boardPositions[5].x = 68;
	boardPositions[5].y = 36;
	boardPositions[5].status = 0;
	
	boardPositions[6].pos = 6;
	boardPositions[6].x = 0;
	boardPositions[6].y = 72;
	boardPositions[6].status = 0;
	
	boardPositions[7].pos = 7;
	boardPositions[7].x = 34;
	boardPositions[7].y = 72;
	boardPositions[7].status = 0;
		
	boardPositions[8].pos = 8;
	boardPositions[8].x = 69;
	boardPositions[8].y = 72;
	boardPositions[8].status = 0;
}

int checkForDeuce()
{
	for (i = 0; i < 9; i++)
	{
		if (boardPositions[i].status == 0)
		{
			return 0;
		}
	}
	
	return 1;
}