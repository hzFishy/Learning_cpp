#include <iostream>
#include <thread> // For sleep
#include <chrono> // For sleep
#include <random>
#include "../default_functions.h" //Located in Apps Folder
#include <vector>


int genRNG(int min, int max){
    std::random_device rd;
    std::mt19937 generator(rd());
    
    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}


std::string genVoid(){
    return std::string(genRNG(0,250), ' ');
}

char genChar(){
    std::string allChars = "²&é\"'(-è_çà)=~#{[|`\\^@]}azertyuiop^$qsdfghjklmù*<wxcvbn,;:!AZERTYUIOP¨£µ%MLKJHGFDSQWXCVBN?./§¤>0147852369";
    return allChars[genRNG(0,allChars.size())];
}

void rngColor(){
    std::vector<int> ids = {10,11,12,13,14,15};

    setColor(ids[genRNG(0,ids.size())]);
}

void Continuous(double delay_seconds){
    rngColor();
    std::cout << genVoid() << genChar() << genVoid() << genChar();

    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(std::round(delay_seconds*1000))));
    Continuous(delay_seconds);

}

void config(){
    setColor(14);
    double Speed = 0.001;
    std::cout << "Edit default config ? (y/n): \n> " << std::endl;
    char ans;
    std::cin >> ans;
    switch (ans){
        case 'y':
            std::cout << "Custom (0)" << std::endl;
            std::cout << "Known cases: \t Matrix Wall: 0.001 (1) \t Storm: 0.00001 (2)" << std::endl;
            int ans2;
            std::cin >> ans2;
            
            double newSpeed = Speed;
            /*
            switch (ans2){
                case 0:
                    std::cout << "Delay \t (seconds) \t (default value: " << Speed << ")";
                    std::cout << "> ";
                    std::cin >> newSpeed;
                    break;
                case 1:
                    newSpeed = 0.001;
                    break;
                case 2:
                    newSpeed = 0.00001;
                    break;
                default:
                    break;
            }
            */
            Continuous(newSpeed);
            break;
        
        default:
            Continuous(Speed);
            break;
    }
    
}

void WallOfIllusions(){
    config();
}