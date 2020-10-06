//Win32 SDK

#include<windows.h>
#include<iostream>

//global function declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//variable declaration
	WNDCLASSEX wndclass;  //object of structure(mould)
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MY APPLICATION");


	//initilaising the structure elements;
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//register above class
	RegisterClassEx(&wndclass);

	//create window function for creating the window based on ( mould=> wndclass filled above 12 parameters) internally (not visible )
	hwnd = CreateWindow(szAppName,
		TEXT("Window is mine"),  //title of window
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;

}

//Defination of callback function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

	//code of message handlers
	switch (iMsg)
	{

	//only called first time before  window is created
	case WM_CREATE:
		MessageBox(hwnd, TEXT("Window created"), TEXT("Message"), MB_OK);
		break;


	case WM_KEYDOWN:
		MessageBox(hwnd, TEXT("key is pressed"), TEXT("Message"), MB_OK);
		break;

	case WM_LBUTTONDOWN:
		MessageBox(hwnd, TEXT("left button pressed"), TEXT("Message"), MB_OK);
		break;

	case WM_RBUTTONDOWN:
		MessageBox(hwnd, TEXT("right button pressed"), TEXT("Message"), MB_OK);
		break;


	case WM_DESTROY:
		PostQuitMessage(0);
		break;



	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

