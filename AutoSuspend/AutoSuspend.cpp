#include <iostream>
#include "KeyboardListner.hpp"

int main()
{
    ShowWindow(GetConsoleWindow(), SW_HIDE); //hide the console window
    std::cout << "Get ready\n";
    KeyboardListner::sleep_duration = 500; //how often to check for keys in milliseconds
    KeyboardListner::grace_period = 5; //for how many loops to ignore checking for keys ( the lower you set the sleep_duration the higher grace_period should be )
    KeyboardListner::listen();
    std::cout << "all done\n";
}
