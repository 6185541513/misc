#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <Windows.h>
using namespace std;

//functions
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
HMENU CreateLabMenu();
void movePlayer(HWND hwnd, int x_value, int y_value);
void drawLab(int color_bk, int color_txt, LPCTSTR letter, int j_value, int i_value);

//WM_COMMANDs
const int ID_START = 1;
const int ID_QUIT = 2;

const int BUT_NORTH = 101;
const int BUT_SOUTH = 102;
const int BUT_WEST = 103;
const int BUT_EAST = 104;

//buttons for moving player
HWND hwnd;
HWND buttonNorth;
HWND buttonSouth;
HWND buttonWest;
HWND buttonEast;

//handle to display DC
HDC hdc = { 0 };
PAINTSTRUCT ps = { 0 };

//x & y pos
int x = 14;
int y = 16;

RECT rect = { x, y, x + 14, y + 16 };

//counter - no. of moves to goal
int moves = 0;

//player 
char cross[256] = { "X" };

//buffer for making x & y printable LPCTSTR
char buffer_x[10], buffer_y[10];

//level matrix
char** level = new char*[20];

//positions of wall
bool ones[330][450] = { false };

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
//load level into matrix
	ifstream file("level1.txt");
	for (UINT i = 0; i < 20; i++){
		level[i] = new char[20];
		for (UINT j = 0; j < 20; j++){
			file >> level[i][j];
		}
	}

//create window
	//preparations
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hIcon = (HICON)LoadIcon(0, IDI_APPLICATION);
	wc.hIconSm = 0;
	wc.hCursor = (HCURSOR)LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = 0;
	wc.lpszClassName = "MyWindowClass";
	wc.style = CS_DBLCLKS;

	RegisterClassEx(&wc);

	//create window
	hwnd = CreateWindow(
		"MyWindowClass",
		"MyWindow",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		330, 450,
		0,
		CreateLabMenu(),
		hInstance,
		0);

	//create buttons for moving player
	buttonNorth = CreateWindow(
		"BUTTON",
		"North",
		WS_CHILD | WS_VISIBLE,
		0, 320,
		75, 25,
		hwnd,
		(HMENU)BUT_NORTH,
		hInstance,
		0);

	buttonSouth = CreateWindow(
		"BUTTON",
		"South",
		WS_CHILD | WS_VISIBLE,
		75, 320,
		75, 25,
		hwnd,
		(HMENU)BUT_SOUTH,
		hInstance,
		0);

	buttonWest = CreateWindow(
		"BUTTON",
		"West",
		WS_CHILD | WS_VISIBLE,
		150, 320,
		75, 25,
		hwnd,
		(HMENU)BUT_WEST,
		hInstance,
		0);

	buttonEast = CreateWindow(
		"BUTTON",
		"East",
		WS_CHILD | WS_VISIBLE,
		225, 320,
		75, 25,
		hwnd,
		(HMENU)BUT_EAST,
		hInstance,
		0);

	//disable buttons before game has started
	EnableWindow(buttonNorth, false);
	EnableWindow(buttonSouth, false);
	EnableWindow(buttonWest, false);
	EnableWindow(buttonEast, false);

	//set font for buttons
	HFONT font = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	SendMessage(buttonNorth, WM_SETFONT, (WPARAM)font, 0);
	SendMessage(buttonSouth, WM_SETFONT, (WPARAM)font, 0);
	SendMessage(buttonWest, WM_SETFONT, (WPARAM)font, 0);
	SendMessage(buttonEast, WM_SETFONT, (WPARAM)font, 0);

	//make window visible
	ShowWindow(hwnd, nCmdShow);

//sending messages
	MSG msg = { 0 };
	BOOL isRunning = true;
	while (isRunning)
	{
		while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)){
			if (msg.message == WM_QUIT){
				isRunning = false;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		Sleep(10);
	}
	return 0;
}

//create menu
HMENU CreateLabMenu(){
	HMENU main = CreateMenu();
	HMENU menu = CreateMenu();

	AppendMenu(menu, MFT_STRING, ID_START, "&Start game");
	AppendMenu(menu, MF_SEPARATOR, 0, 0);
	AppendMenu(menu, MF_STRING, ID_QUIT, "&Quit");
	AppendMenu(main, MF_POPUP, (UINT_PTR)menu, "&Menu");

	return main;
}

//handling messages
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_COMMAND:
		switch (LOWORD(wParam)){
//button events
		case BUT_NORTH:
		{
			movePlayer(hwnd, x, (y - 16));
		}
			break;

		case BUT_SOUTH:
		{
			movePlayer(hwnd, x, (y + 16));
		}
			break;

		case BUT_WEST:
		{
			movePlayer(hwnd, (x - 14), y);
		}
			break;

		case BUT_EAST:
		{
			movePlayer(hwnd, (x + 14), y);

			//when player reaches the goal
			if (x == 18 * 14 && y == 18 * 16){
				char s[256];
				sprintf_s(s, "You did it^^ And in just %d moves.", moves);
				MessageBox(0, s, "", MB_OK);
				PostQuitMessage(0);
			}
		}
			break;

//start game
		case ID_START:
		{
			hdc = GetDC(hwnd);
			//get player in game
			TextOut(hdc, x, y, cross, strlen(cross));

			//print x pos
			buffer_x[10];
			sprintf_s(buffer_x, "%d", x);
			TextOut(hdc, 25, 345, buffer_x, strlen(buffer_x));

			//print y pos
			buffer_y[10];
			sprintf_s(buffer_y, "%d", y);
			TextOut(hdc, 25, 360, buffer_y, strlen(buffer_y));

			//enable buttons
			EnableWindow(buttonNorth, true);
			EnableWindow(buttonSouth, true);
			EnableWindow(buttonWest, true);
			EnableWindow(buttonEast, true);
			UpdateWindow(hwnd);
		}
			break;

//quit
		case ID_QUIT:
			PostQuitMessage(0);
			return 0;
		}
		break;

//paint playing field
	case WM_PAINT:
	{
		hdc = BeginPaint(hwnd, &ps);
		//x pos
		TextOut(hdc, 10, 345, "x:", 2);

		//y pos
		TextOut(hdc, 10, 360, "y:", 2);

		//level
		char buffer_floor[256] = { "X" };
		for (int i = 0; i < 20; i++){
			for (int j = 0; j < 20; j++){
				if (level[i][j] == '1'){
					drawLab(0, 0, "W", j, i);
					
					//marks coordinates for the "bricks" in the wall
					ones[j * 14][i * 16] = true;
				}
				else if (level[i][j] == '0'){
					drawLab(255, 255, "X", j, i);
				}
				else if(level[i][j] == 's'){
					drawLab(0, 145, "S", j, i);
				}
				else if (level[i][j] == 'e'){
					drawLab(0, 145, "G", j, i);
				}
			}
		}
		EndPaint(hwnd, &ps);
	}
	break;

//quit
	case WM_CLOSE:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

//move player
void movePlayer(HWND hwnd, int x_value, int y_value){
//looking to see if the coordinates of the players next move are a part of the wall...
	bool ok = false;
	for (int i = 0; i < 330; i++){
		for (int j = 0; j < 450; j++){
			if (!ones[x_value][y_value]){
				ok = true;
				break;
			}
		}
		if (ok){
			break;
		}
	}

//...if not so, move the player
	if (ok){
		hdc = GetDC(hwnd);
		//update no. of moves
		moves++;

		//update rect and erase players current pos
		rect = { x, y, x + 14, y + 16 };
		InvalidateRect(hwnd, &rect, true);

		//update x & y
		x = x_value;
		y = y_value;

		//print new x & y pos
		sprintf_s(buffer_x, "%d", x);
		TextOut(hdc, 25, 345, buffer_x, strlen(buffer_x));

		sprintf_s(buffer_y, "%d", y);
		TextOut(hdc, 25, 360, buffer_y, strlen(buffer_y));

		//print player in new pos
		TextOut(hdc, x, y, cross, strlen(cross));

		UpdateWindow(hwnd);
	}
}

void drawLab(int color_txt, int color_bk, LPCTSTR letter, int j_value, int i_value){
	SetTextColor(hdc, RGB(color_txt, color_txt, color_txt));
	SetBkColor(hdc, RGB(color_bk, color_bk, color_bk));
	TextOut(hdc, (j_value * 14), (i_value * 16), letter, 1);
}



