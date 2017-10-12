#define TYPE_LINE 0
#define TYPE_BOX 1

GsOT	*ot;

typedef struct {
	int r;
	int g;
	int b;
} Color;

typedef struct {
	LINE_F2 line;
	int type;
} Line;

typedef struct {
	Line line[4];
	int type;
} Box;

Color createColor(int r, int g, int b) 
{
	Color color = {.r = r, .g = g, .b = b};
	return color;
}

Line createLine(Color color, int x1, int y1, int x2, int y2) 
{
	Line line;
	line.type = TYPE_LINE;
	SetLineF2(&line.line);
	setRGB0(&line.line, color.r, color.g, color.b);
	setXY2(&line.line, x1, y1, x2, y2);
	return line;
}

void drawBox(Box box) 
{
	int i;
	for(i = 0; i < 4; i++)
	{
		DrawPrim(&box.line[i].line);
	}
}

Box createBox(Color color, int x1, int y1, int x2, int y2) 
{
	Line top    = createLine(color, x1, y1, x2, y1);
	Line bottom = createLine(color, x1, y2, x2, y2);
	Line left   = createLine(color, x1, y1, x1, y2);
	Line right  = createLine(color, x2, y1, x2, y2);
	Box box;
	box.type = TYPE_BOX;
	box.line[0] = top;
	box.line[1] = bottom;
	box.line[2] = left;
	box.line[3] = right;
	return box;
}

void drawLine(Line line) 
{
	DrawPrim(&line.line);
}

void setDebugFont(int x, int y) 
{
   FntLoad(960, 0);
   FntOpen(x, y, 320, 240, 0, 512);
}

void display()
{
	FntFlush(-1);
	System_DrawFrame(ot, NULL, NULL);
}

void createFrame()
{
	ot = System_InitFrame();
}