#include <iostream>
#include <stddef.h>
#include <windows.h>  // colors
#include <vector>

int df_closing_app();
void df_print();
void setColor(int colorID);


int df_closing_app(){
    setColor(12);
    std::cout << "Appuyez sur une touche pour quitter...";
    std::cin.ignore();
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}

void df_print(){
    //code
}

void setColor(int colorID){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorID);
}

bool isCharInVector(const std::vector<char>& vec, char targetChar) {
    for (char ch : vec) {
        if (ch == targetChar) {
            return true;
        }
    }
    return false;
}