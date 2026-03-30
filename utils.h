#pragma once
#include <iostream>
using namespace std;

#ifdef _WIN32
    #include <windows.h>
    void sleep_ms(int milliseconds) {
        Sleep(milliseconds);
    }
#else
    #include <thread>
    #include <chrono>
    void sleep_ms(int milliseconds) {
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    }
#endif


// Функция для принудительного обновления терминала на Mac
void flushTerminal() {
    cout << flush;
}

// Кроссплатформенная очистка экрана
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
