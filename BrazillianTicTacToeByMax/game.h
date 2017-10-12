DataManager_Files game_datas[] =
{
	{"TITLE.TIM", 0},
	{"BRA1.TIM", 0},
	{"BRA2.TIM", 0},
	{"TICO25.TIM", 0},
	{"TICX25.TIM", 0},
	{"DEUCE.TIM", 0},
	{"P1WINS.TIM", 0},
	{"P2WINS.TIM", 0},
	{"BOARD.TIM", 0},
	{"CHECK.VAG", 0},
	{"MOVE.VAG", 0},
	{NULL, 0}
};

enum
{
	TITLE,
	BRA1,
	BRA2,
	TICO25,
	TICX25,
	DEUCE,
	P1WINS,
	P2WINS,
	BOARD,
	CHECK,
	MOVE
};

typedef struct Position
{
	int x;
	int y;
	int pos;
	int status;
} Position;

int i = 0;

int gameOffsetX = 100;

int gameOffsetY = 50;

int currentPlayer = 1;

Position boardPositions[9];

Position playerPosition;

int winner;

GsIMAGE	TIMtitle, TIMbg1, TIMbg2, TIMtico, TIMticx, TIMdeuce, TIMp1wins, TIMp2wins, TIMboard;
GsSPRITE title, bg1, bg2, tico, ticx, deuce, p1wins, p2wins, board;

char strBuf[100];

void initialize();
void update();
void display();
void draw();
int checkForDeuce();
void drawBoard();
void drawGame(Position p);
void initializeBoard();
void drawPlayer();
int readPads();
int checkForWin(int player);
void loadGameData();
void drawTitle();
void drawBackground();
int checkWinner();
void drawWinner();
void drawDeuce();
void drawPlayer1(int x, int y);
void drawPlayer2(int x, int y);
Position getNextFreePosition();

void loadGameData()
{
	DataManager_Init();
	DataManager_LoadDatas("DATA", game_datas);
	
	Tim_Load(&TIMboard, game_datas[BOARD].address);	
	Sprite_Init(&board, &TIMboard, SPRITE_NORMAL, 0, 0, 100, 105);
	
	Tim_Load(&TIMtitle, game_datas[TITLE].address);	
	Sprite_Init(&title, &TIMtitle, SPRITE_NORMAL, 0, 0, 200, 37);

	Tim_Load(&TIMbg1, game_datas[BRA1].address);	
	Sprite_Init(&bg1, &TIMbg1, SPRITE_NORMAL, 0, 0, 256, 240);

	Tim_Load(&TIMbg2, game_datas[BRA2].address);	
	Sprite_Init(&bg2, &TIMbg2, SPRITE_NORMAL, 0, 0, 64, 240);
	
	Tim_Load(&TIMticx, game_datas[TICX25].address);	
	Sprite_Init(&ticx, &TIMticx, SPRITE_NORMAL, 0, 0, 25, 25);
	
	Tim_Load(&TIMtico, game_datas[TICO25].address);	
	Sprite_Init(&tico, &TIMtico, SPRITE_NORMAL, 0, 0, 25, 25);
	
	Tim_Load(&TIMdeuce, game_datas[DEUCE].address);	
	Sprite_Init(&deuce, &TIMdeuce, SPRITE_NORMAL, 0, 0, 100, 34);
	
	Tim_Load(&TIMp1wins, game_datas[P1WINS].address);	
	Sprite_Init(&p1wins, &TIMp1wins, SPRITE_NORMAL, 0, 0, 200, 30);
	
	Tim_Load(&TIMp2wins, game_datas[P2WINS].address);	
	Sprite_Init(&p2wins, &TIMp2wins, SPRITE_NORMAL, 0, 0, 200, 30);
	
	Sound_Init();
	Sound_Load(0, game_datas[CHECK].address);
	Sound_Load(1, game_datas[MOVE].address);
}

void resetGame()
{
	initializeBoard();

	currentPlayer = 1;
	
	winner = 0;
	
	playerPosition = getNextFreePosition();
}