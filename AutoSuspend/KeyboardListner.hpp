#pragma once
#include <Windows.h>
#include <mmsystem.h>

class KeyboardListner
{
public:
	static void listen();
	static DWORD sleep_duration;
	static int grace_period;
private:
	KeyboardListner() {};
	static void display_keys(SHORT* keys);
	static bool check_pattern(SHORT* keys, int* pattern, int pattern_size);
};

