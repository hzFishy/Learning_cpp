#include <iostream>
#include <thread> // For sleep
#include <chrono> // For sleep
#include <random>
#include "../default_functions.h" //Located in Apps Folder
#include <vector>

//Global vars
std::vector<int> Colorids = {9,10,11,12,13,15};
std::string allChars = "²&é\"'(-è_çà)=~#{[|`\\^@]}azertyuiop^$qsdfghjklmù*<wxcvbn,;:!AZERTYUIOP¨£µ%MLKJHGFDSQWXCVBN?./§¤>0147852369";

//Defaults:
double defaultSpeed = 0.001;
int defaultColor = 15;



//Logic
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
    return allChars[genRNG(0,allChars.size())];
}

void rngColor(){
    setColor(Colorids[genRNG(0,Colorids.size())]);
}

void doColorID(int ColorID){
    switch (ColorID){
    case -1:
        rngColor();
        break;
    case -2:
        rngColor();
        break;
    
    default:
        setColor(ColorID);
        break;
    }
}

void Continuous(double delay_seconds, int ColorID){
    if (ColorID == -2){
         doColorID(ColorID);
    }
    std::cout << genVoid() << genChar() << genVoid() << genChar();

    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(std::round(delay_seconds*1000))));
    Continuous(delay_seconds, ColorID);

}

void pre_Continuous(double delay_seconds, int ColorID){
    if (ColorID != -2){
        doColorID(ColorID);
    }

    Continuous(delay_seconds,ColorID);
}

double editSpeed(){
    std::cout << "Custom (0)" << std::endl;
    std::cout << "Known cases: \t Matrix Wall: 0.001 (1) \t Storm: 0.00001 (2)" << std::endl;
    std::cout << "> ";
    int SpeedPreset;
    std::cin >> SpeedPreset;
    
    double newSpeed = defaultSpeed;
    
    switch (SpeedPreset){
        case 0:
            std::cout << "Delay \t (seconds) \t (default value: " << defaultSpeed << ")";
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
    return newSpeed;
}

int editColor(){
    std::cout << "Custom (0)" << std::endl;
    std::cout << "Known cases: \t RandomSingle (1) \t RandomMultiple (2)" << std::endl;
    std::cout << "> ";
    int ColorPreset;
    std::cin >> ColorPreset;
    
    int newColorID = defaultColor;
    
    switch (ColorPreset){
        case 0:
            int tpans0;
            std::cout << "Color \t (default: White (15))" << std::endl;
            std::cout << "Color choices: \t Blue(9) \t Green (10) \t Cyan (11) \t Red (112) \t Purple (13) \t Yellow (14) \t White (15)" << std::endl;
            std::cout << "> ";
            if (std::cin >> tpans0){
                newColorID = tpans0;
            } else {
                newColorID = defaultColor;
            }
            break;
        case 1:
            newColorID = -1;
            break;
        case 2:
            newColorID = -2;
            break;
        default:
            break;
    }
    return newColorID;
}

void config(){
    double Speed = defaultSpeed;
    int ColorID = defaultColor;

    setColor(14);
    std::cout << "Edit default config ? (y/n):" << std::endl;
    std::cout << "> ";
    char ans;
    std::cin >> ans;
    switch (ans){
        case 'y':
            
            char ansSpeed;
            std::cout << "Edit speed ? (y/n)" << std::endl;
            std::cout << "> ";
            std::cin >> ansSpeed;
            if (ansSpeed == 'y'){
                Speed = editSpeed();
            }

            char ansColor;
            std::cout << "Edit color ? (y/n)" << std::endl;
            std::cout << "> ";
            std::cin >> ansColor;
            if (ansColor == 'y'){
                ColorID = editColor();
            }

            break;
        
        default:
            break;
    }
    pre_Continuous(Speed,ColorID);
    
}

void WallOfIllusions(){
    config();
}