#include <iostream>
#include <stddef.h>
#include <limits.h>

int df_closing_app(){
    std::cout << "Appuyez sur une touche pour quitter...";
    std::cin.ignore();
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}

void df_print(){
    //code
}