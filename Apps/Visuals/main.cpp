#include <iostream>
#include "../default_functions.h" //Located in Apps Folder
#include "WallOfIllusions.h"


int main(){
    setColor(11);
    std::cout << "##     ## ####  ######  ##     ##    ###    ##        ######  \n"
                "##     ##  ##  ##    ## ##     ##   ## ##   ##       ##    ## \n"
                "##     ##  ##  ##       ##     ##  ##   ##  ##       ##       \n"
                "##     ##  ##   ######  ##     ## ##     ## ##        ######  \n"
                " ##   ##   ##        ## ##     ## ######### ##             ## \n"
                "  ## ##    ##  ##    ## ##     ## ##     ## ##       ##    ## \n"
                "   ###    ####  ######   #######  ##     ## ########  ######  \n";

    int ans;
    setColor(10);
    std::cout << "What do you want? " << " \t Leave (0) \t Wall of Illusions (1)" << "\n > ";
    std::cin >> ans;
    setColor(15);
    switch (ans)
    {
    case 1:
        WallOfIllusions();
        break;
    
    default:
        break;
    }
    df_closing_app();
    
    return 0;
}