#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <windows.h>

void logAccess(const std::string& username) 
{
    std::ofstream file("log.txt", std::ios::app);
    time_t now = time(nullptr);
    char dt[26];
    ctime_s(dt, sizeof(dt), &now);
    file << username << " logged in at " << dt;
    file.close();
}

int main() 
{
    std::string username;
    std::cout << "Enter your username: ";
    std::getline(std::cin, username);

    logAccess(username);

    std::cout << "Access logged.\nOpening dashboard...\n";

    ShellExecute(0, 0, L"dashboard.html", 0, 0, SW_SHOW);

    return 0;
}