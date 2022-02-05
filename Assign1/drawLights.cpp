#include <wtypes.h>

const COLORREF red = RGB(255, 0, 0);
const COLORREF yellow = RGB(255, 255, 0);
const COLORREF green = RGB(0, 255, 0);
const COLORREF gray = RGB(128, 128, 128);
const COLORREF black = RGB(0, 0, 0);

void ellipseHelp(HDC hdc, int left, int top, int right, int bottom, COLORREF colr) {
	HBRUSH hBrush = CreateSolidBrush(colr);
	HGDIOBJ hOrg = SelectObject(hdc, hBrush);

	Ellipse(hdc, left, top, right, bottom);

	SelectObject(hdc, hOrg);
	DeleteObject(hBrush);
}

void rectangleHelp(HDC hdc, int left, int top, int right, int bottom, COLORREF colr) {
	HBRUSH hBrush = CreateSolidBrush(colr);
	HGDIOBJ hOrg = SelectObject(hdc, hBrush);

	Rectangle(hdc, left, top, right, bottom);

	SelectObject(hdc, hOrg);
	DeleteObject(hBrush);
}

void drawRoad(HDC hdc) {
	HBRUSH hBrush = CreateSolidBrush(gray);
	HGDIOBJ hOrg = SelectObject(hdc, hBrush);

	//Horisontal vei
	Rectangle(hdc, 200, 290, 700, 280);
	Rectangle(hdc, 200, 280, 700, 270);

	//Vertikal vei
	Rectangle(hdc, 450, 100, 460, 500);
	Rectangle(hdc, 440, 100, 450, 500);

	Rectangle(hdc, 440, 270, 460, 290);

	SelectObject(hdc, hOrg);
	DeleteObject(hBrush);
}

// Sett state som int forel�pig. Usikker p� ka som e best � bruke
void trafficLights(HDC hdc, int left, int top, int state) {
	
	//Treng left, top, right, bottom

	/*int redTop = top + 5;
	int yellowTop = top + 80;
	int greenTop = top + 155;

	int redBot = redTop + 65;
	int yellowBot = yellowTop + 65;
	int greenBot = greenTop + 65;

	int right = left + 80;*/

	int redTop = top + 5;
	int yellowTop = top + 45;
	int greenTop = top + 85;

	int redBot = redTop + 35;
	int yellowBot = yellowTop + 35;
	int greenBot = greenTop + 35;

	int right = left + 40;

	//rectangleHelp(hdc, left, top, (left + 90), (top + 230), black);
	rectangleHelp(hdc, left, top, (left + 45), (top + 125), black);

	// Left va left + 10 f�r.
	switch (state) {
	case 1: 
		ellipseHelp(hdc, (left + 5), redTop, right, redBot, red);
		ellipseHelp(hdc, (left + 5), yellowTop, right, yellowBot, gray);
		ellipseHelp(hdc, (left + 5), greenTop, right, greenBot, gray);
		break;
	case 2:
		ellipseHelp(hdc, (left + 5), redTop, right, redBot, red);
		ellipseHelp(hdc, (left + 5), yellowTop, right, yellowBot, yellow);
		ellipseHelp(hdc, (left + 5), greenTop, right, greenBot, gray);
		break;
	case 3:
		ellipseHelp(hdc, (left + 5), redTop, right, redBot, gray);
		ellipseHelp(hdc, (left + 5), yellowTop, right, yellowBot, gray);
		ellipseHelp(hdc, (left + 5), greenTop, right, greenBot, green);
		break;
	case 4:
		ellipseHelp(hdc, (left + 5), redTop, right, redBot, gray);
		ellipseHelp(hdc, (left + 5), yellowTop, right, yellowBot, yellow);
		ellipseHelp(hdc, (left + 5), greenTop, right, greenBot, gray);
		break;
	}

	/*	ellipseHelp(hdc, (left + 10), redTop, right, redBot, red);
		ellipseHelp(hdc,(left+10), yellowTop, right,yellowBot, gray);
		ellipseHelp(hdc, (left+10), greenTop, right, greenBot, gray);*/
}
