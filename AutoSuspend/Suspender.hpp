#pragma once
#include <Windows.h>
#include <debugapi.h>

class Suspender
{
public:
	static bool pause_pid();
	static bool resume_pid();
	static bool toggle();
	
private:
	Suspender() {};
	static void get_active_window_pid();
	static bool debug_started;
	static DWORD pid;
};

