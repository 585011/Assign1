//#include "Car.cpp"
// Assign1.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Assign1.h"
#include "drawLights.h"
#include "Car.h"
class Car
{
public:
    int n;
    int x, y;
    Car(int _n, int _x, int _y) : n(_n), x(_x), y(_y)
    {
    }
    void Draw(HDC hdc)
    {
        //HBRUSH hBrush = CreateSolidBrush(RGB(255,0,0));
        //HGDIOBJ hOrg = SelectObject(hdc, hBrush);
        Rectangle(hdc, x, y - 5, x + 5, y);

        //SelectObject(hdc, hOrg);
        //DeleteObject(hBrush);
    }
};

class CarList
{
public:
    Car* c[100];
    int i;
    CarList()
    {
        i = 0;
    }
    void push(Car* aCar)
    {
        c[i++] = aCar;
    }
    void Draw(HDC hdc)
    {
        for (int j = 0; j < i; j++)
            c[j]->Draw(hdc);
    }
    // Bruker denne for både x og y
    void MoveX(int dx)
    {
        for (int j = 0; j < i; j++)
            c[j]->x += dx;
    }
    void MoveY(int dy)
    {
        for (int j = 0; j < i; j++)
            c[j]->y += dy;
    }
    void Clear()
    {
        for (int j = 0; j < i; j++)
            delete c[j];
        i = 0;
    }
};

//void drawNorth() 
//{
//    for(int i = 0; i < )
//}

static CarList carListW;
static CarList carListN;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_ASSIGN1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ASSIGN1));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ASSIGN1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_ASSIGN1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//

int pw;
int pn;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static int state = 1;
    static int state2 = 3;
    static bool bTimer = false;
    static int n = 0;


    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_RBUTTONDOWN:
    {
        //Car* car = new Car(n++, 200, 285);
        int rnd1 = rand() % 10;
        carListW.push(new Car(n++, 200, rnd1 + 280));
        InvalidateRect(hWnd, 0, true);
    }
        break;
    case WM_LBUTTONDOWN:
    {
        if (!bTimer)
            SetTimer(hWnd, 0, 1500, 0);
        else
            KillTimer(hWnd, 0);
        bTimer = !bTimer;
        break;
    }
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            trafficLights(hdc, 100, 100,state);
            trafficLights(hdc, 600, 300, state2);
            drawRoad(hdc);
            HBRUSH hb = CreateSolidBrush(RGB(255, 0, 0));
            HGDIOBJ hOrg = SelectObject(hdc, hb);
            carListW.Draw(hdc);
            carListN.Draw(hdc);
            
            SelectObject(hdc, hOrg);
            DeleteObject(hb);
            
            //// TODO: Add any drawing code that uses hdc here...
            //HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
            //HGDIOBJ hOrg = SelectObject(hdc, hBrush);
            //Rectangle(hdc, 100, 100, 190, 330);

            //SelectObject(hdc, hOrg);
            //DeleteObject(hBrush);

            //hBrush = CreateSolidBrush(RGB(255, 0, 0));
            //hOrg = SelectObject(hdc, hBrush);
            //Ellipse(hdc, 110, 105, 180, 170);

            //SelectObject(hdc, hOrg);
            //DeleteObject(hBrush);

            //// (hdc, right, top, left, bottom) --> right samme, top = forrige top + 10, left samme
            //// bottom = top + 65
            //hBrush = CreateSolidBrush(RGB(255, 255, 0));
            //hOrg = SelectObject(hdc, hBrush);
            //Ellipse(hdc, 110, 180, 180, 245);

            //SelectObject(hdc, hOrg);
            //DeleteObject(hBrush);

            //hBrush = CreateSolidBrush(RGB(128, 128, 128));
            //hOrg = SelectObject(hdc, hBrush);
            //Ellipse(hdc, 110, 255, 180, 325);

            /*SelectObject(hdc, hOrg);
            DeleteObject(hBrush);*/

            
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_TIMER:
        //int rnd = rand() % 100; // 0-99
        //carListW.MoveX(30);
        //carListN.MoveY(30);
        state += 1;
        state2 += 1;

        if (state > 4)
        {
            state = 1;
        }
        if (state2 > 4)
        {
            state2 = 1;
        }
        if (state != 4)
        {
            carListW.MoveX(0);
        }
        else if (state == 4) {
            carListW.MoveX(30);
        }
        InvalidateRect(hWnd, 0, true);
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
            case VK_LEFT:
                pw -= 10;
                break;
            case VK_RIGHT:
                pw += 10;
                break;
            case VK_DOWN:
                pn -= 10;
                break;
            case VK_UP:
                pn += 10;
                break;
        }
    break;
    case WM_DESTROY:
        KillTimer(hWnd, 0);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
