#include <DX3D/Window/Window.h>
#include <Windows.h>
#include<stdexcept>

dx3d::Window::Window():Base()
{
	WNDCLASSEX wc{};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpszClassName = L"DX3DWindow";
	wc.lpfnWndProc = DefWindowProc;
	auto winowClassId = RegisterClassEx(&wc);


	if (!winowClassId)
	
		throw std::runtime_error("RegisterClassEx failed.");

	
	RECT rc{ 0,0,1280,720 };
	AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);

    auto WindowClassId=	RegisterClassEx(&wc);
	m_handle= CreateWindowEx(NULL, MAKEINTATOM(WindowClassId), L"PardCode | C++ 3D Game Tutorial Series",
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT,
		rc.right - rc.left, rc.bottom - rc.top,
		NULL, NULL, NULL, NULL);
	if (!m_handle)
	
		throw std::runtime_error("CreateWindowEx failed.");
	ShowWindow(static_cast<HWND>(m_handle), SW_SHOW);
}

dx3d::Window::~Window()
{
	int ok=199;
}
