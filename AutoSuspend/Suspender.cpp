#include "Suspender.hpp"

bool Suspender::debug_started = false;
DWORD Suspender::pid = NULL;

bool Suspender::pause_pid() {
    get_active_window_pid();
    if (pid != NULL) {
        bool success = DebugActiveProcess(pid);
        if (success) {
            debug_started = true;
            return true;
        }
    }
    return false;
}

bool Suspender::resume_pid() {
    if (pid != NULL) {
        if (debug_started) {
            bool stop_success = DebugActiveProcessStop(pid);
            if (stop_success) {
                debug_started = false;
                return true;
            }
        }
    }
    return false;
}

bool Suspender::toggle() {
    if (debug_started) {
        /*
        DWORD current_pid = pid;
        get_active_window_pid();
        if (current_pid != pid) {
            //new window clicked, resume old window
            DebugActiveProcessStop(current_pid);
        }*/
        return resume_pid();
    }
    else {
        return pause_pid();
    }
}

void Suspender::get_active_window_pid() {
    pid = NULL;
    HWND hwnd = GetForegroundWindow();
    GetWindowThreadProcessId(hwnd, &pid);
}