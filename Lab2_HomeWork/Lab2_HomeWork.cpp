// Lab2_HomeWork.cpp : Определяет точку входа для приложения.
//
#include <windows.h>
#include "framework.h"
#include "Lab2_HomeWork.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
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

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB2HOMEWORK, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB2HOMEWORK));

    MSG msg;

    // Цикл основного сообщения:
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
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB2HOMEWORK));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB2HOMEWORK);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

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

void Carcass(HDC hdc) 
{
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 0));
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0)); 
    SelectObject(hdc, hBrush);
    SelectObject(hdc, hPen);

    Rectangle(hdc, 170, 200, 1500, 600);

    DeleteObject(hBrush);
    DeleteObject(hPen);
}

void FrontWindow(HDC hdc) 
{
    HBRUSH hBrush = CreateSolidBrush(RGB(0, 191, 255));
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    SelectObject(hdc, hPen);

    Rectangle(hdc, 1470, 220, 1500, 450);

    DeleteObject(hBrush);
    DeleteObject(hPen);
}

void LargeWindow(HDC hdc, int x, int y)
{
    HBRUSH hBrush = CreateSolidBrush(RGB(0, 191, 255));
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    SelectObject(hdc, hPen);

    Rectangle(hdc, x, y, x + 240, y + 230);

    MoveToEx(hdc, x, y + 50, NULL);
    LineTo(hdc, x + 240, y + 50);
    MoveToEx(hdc, x + 120, y, NULL);
    LineTo(hdc, x + 120, y + 50);

    DeleteObject(hBrush);
    DeleteObject(hPen);
}

void SmallWindow(HDC hdc)
{
    HBRUSH hBrush = CreateSolidBrush(RGB(0, 191, 255));
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    SelectObject(hdc, hPen);

    Rectangle(hdc, 1120, 220, 1170, 450);

    DeleteObject(hBrush);
    DeleteObject(hPen);
}

void DoubleDoor(HDC hdc)
{
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 165, 0));
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    SelectObject(hdc, hPen);

    Rectangle(hdc, 930, 250, 1090, 580);

    DeleteObject(hBrush);
    DeleteObject(hPen);

    MoveToEx(hdc, 1010, 250, NULL);
    LineTo(hdc, 1010, 579);
}

void DoorWindow(HDC hdc, int x, int y)
{
    HBRUSH hBrush = CreateSolidBrush(RGB(0, 191, 255));
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    SelectObject(hdc, hPen);

    Rectangle(hdc, x, y, x + 60, y + 200);

    DeleteObject(hBrush);
    DeleteObject(hPen);
}

void VerticalDoorHandle(HDC hdc, int x, int y)
{
    HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x, y,NULL);
    LineTo(hdc, x, y + 20);

    DeleteObject(hPen);
}

void BackDoor(HDC hdc)
{
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 165, 0));
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    SelectObject(hdc, hPen);

    Rectangle(hdc, 200, 250, 360, 580);

    DeleteObject(hBrush);
    DeleteObject(hPen);
}

void RearDoorWindow(HDC hdc)
{
    HBRUSH hBrush = CreateSolidBrush(RGB(0, 191, 255));
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    SelectObject(hdc, hPen);

    Rectangle(hdc, 220, 270, 340, 390);

//    MoveToEx(hdc, 200, 410, NULL);
//    LineTo(hdc, 360, 410);

    DeleteObject(hBrush);
    DeleteObject(hPen);
}

void HorizontalDoorHandle(HDC hdc)
{
    HPEN hPen = CreatePen(PS_SOLID, 7, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 340, 420, NULL);
    LineTo(hdc, 320, 420);

    DeleteObject(hPen);
}

void Wheel(HDC hdc, int x, int y) 
{
    HBRUSH hBrush = CreateSolidBrush(RGB(128, 128, 128));
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    SelectObject(hdc, hPen);

    Ellipse(hdc, x, y, x + 110, y + 110);


    DeleteObject(hBrush);
    DeleteObject(hPen);

    HBRUSH hBrush_2 = CreateSolidBrush(RGB(192, 192, 192));
    HPEN hPen_2 = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hBrush_2);
    SelectObject(hdc, hPen_2);

    Ellipse(hdc, x + 25, y + 25, x + 85, y + 85);

    DeleteObject(hBrush_2);
    DeleteObject(hPen_2);

}

void Arch(HDC hdc, int x, int y)
{
    HBRUSH hBrush = CreateSolidBrush(RGB(25, 25, 25));
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    SelectObject(hdc, hPen);

    Chord(hdc, x - 30, y - 30, x + 140, y + 140, x + 160, y + 55, x - 50, y + 55);


    DeleteObject(hBrush);
    DeleteObject(hPen);
}

void Luke(HDC hdc)
{
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 165, 0));
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    SelectObject(hdc, hPen);

    POINT pt[4];
    pt[0].x = 1180;
    pt[0].y = 200;
    pt[1].x = 1170;
    pt[1].y = 180;
    pt[2].x = 900;
    pt[2].y = 180;
    pt[3].x = 890;
    pt[3].y = 200;
    Polygon(hdc, pt, 4);

    DeleteObject(hBrush);
    DeleteObject(hPen);
}

void Lattice(HDC hdc)
{
    HBRUSH hBrush = CreateSolidBrush(RGB(220, 220, 220));
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    SelectObject(hdc, hPen);

    Rectangle(hdc, 650, 490, 890, 570);

    DeleteObject(hBrush);
    DeleteObject(hPen);


    HPEN hPen_2 = CreatePen(PS_SOLID, 7, RGB(0, 0, 0));
    SelectObject(hdc, hPen_2);

    MoveToEx(hdc, 660, 500, NULL);
    LineTo(hdc, 660, 560);
    MoveToEx(hdc, 880, 500, NULL);
    LineTo(hdc, 880, 560);

    MoveToEx(hdc, 660, 500, NULL);
    LineTo(hdc, 880, 500);
    MoveToEx(hdc, 660, 510, NULL);
    LineTo(hdc, 880, 510);
    MoveToEx(hdc, 660, 520, NULL);
    LineTo(hdc, 880, 520);
    MoveToEx(hdc, 660, 530, NULL);
    LineTo(hdc, 880, 530);
    MoveToEx(hdc, 660, 540, NULL);
    LineTo(hdc, 880, 540);
    MoveToEx(hdc, 660, 550, NULL);
    LineTo(hdc, 880, 550);
    MoveToEx(hdc, 660, 560, NULL);
    LineTo(hdc, 880, 560);


    DeleteObject(hPen_2);
}

void Headlight(HDC hdc)
{
    HBRUSH hBrush = CreateSolidBrush(RGB(245, 222, 179));
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    SelectObject(hdc, hPen);

    Chord(hdc, 1470, 400+80, 1530, 460 + 80, 1500, 360, 1500, 500 + 80);


    DeleteObject(hBrush);
    DeleteObject(hPen);
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
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
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
         
            Carcass(hdc);
            FrontWindow(hdc);
            LargeWindow(hdc, 1200, 220);
            SmallWindow(hdc);
            DoubleDoor(hdc);
            DoorWindow(hdc, 1020, 260);
            DoorWindow(hdc, 940, 260);
            VerticalDoorHandle(hdc, 1020, 480);
            VerticalDoorHandle(hdc, 1000, 480);
            LargeWindow(hdc, 660, 220);
            LargeWindow(hdc, 390, 220);
            BackDoor(hdc);
            RearDoorWindow(hdc);
            HorizontalDoorHandle(hdc);
            Arch(hdc, 470, 545);
            Arch(hdc, 1150, 545);
            Wheel(hdc, 470, 545);
            Wheel(hdc, 1150, 545);
            Luke(hdc);
            Lattice(hdc);
            Headlight(hdc);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
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
