// imports
#include <iostream>
#include <fstream> //files
#include "../default_functions.h" //Located in Apps Folder
#include <nlohmann/json.hpp> //json handler


//namespaces
using json = nlohmann::json;

//declarations
void ask();
void performAction(int actionID);
void User_login();
void User_register();
void User_page(std::string username);
bool UserExist(std::string username);
bool PasswordCheck(std::string username,std::string password);
void Create_User(std::string username,std::string password, std::string DisplayName);


//functions
void start(){
    setColor(10);
    std::cout << "Welcome ! Select your choice" << std::endl;
    setColor(5);
    std::cout << ">> Login (1) << \t >> Register (2) << \t >> Leave (3) << " << std::endl;
    ask();
}

void ask(){
    setColor(10);
    int answer = 0;
    std::cout << "> ";
    if (std::cin >> answer && answer < 4 && answer > 0) {
        performAction(answer);
    } else {
        setColor(12);
        std::cout << "Invalid response" << std::endl;
        // PB: infinite loop si str
        ask();
    }
}

void performAction(int actionID){
    setColor(11);
    switch (actionID)
    {
    case 1:
        User_login();
        break;
    case 2:
        User_register();
        break;
    case 3:
        df_closing_app();
        break;
    default:
        df_closing_app();
        break;
    }   
}

json openJSON(){
    // open JSON file
    std::ifstream file("data.json");
    if (!file.is_open()) {
        system("Color O4");
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return 0;
    }

    json data;
    file >> data;
    return data;
}

void User_login(){
    setColor(11);
    std::cout << "Enter username: ";
    std::string username;
    std::cin >> username;
    std::cout << std::endl;
    if (UserExist(username)){
        setColor(3);
        std::cout << "Enter Password: ";
        std::string userPSW;
        std::cin >> userPSW;
        std::cout << std::endl;
        
        if (PasswordCheck(username, userPSW)){
            User_page(username);
        } else {
            setColor(12);
            std::cerr << "Password invalid" << std::endl;
            User_login();
        }
    } else {
        setColor(12);
        std::cout << "Username not found" << std::endl;
        User_login();
    }
}

bool registerValidateUsername(std::string username){
        std::cout << "Your username is: [" << username << "] do you confirm ? (y/n)" << std::endl;
        char answer;
        std::cin >> answer;
        switch (answer)
        {
        case 'y':
            return true;
            break;
        case 'n':
            return false;
            break;
        default:
        return false;
            break;
        }
}

bool registerValidateDisplayName(std::string DisplayName){
        std::cout << "Your DisplayName is: [" << DisplayName << "] do you confirm ? (y/n)" << std::endl;
        char answer;
        std::cin >> answer;
        switch (answer)
        {
        case 'y':
            return true;
            break;
        case 'n':
            return false;
            break;
        default:
        return false;
            break;
        }
}

std::string registerDisplayName(){
    setColor(11);
    std::cout << "Enter DisplayName: ";
    std::string DisplayName;
    std::cin >> DisplayName;
    std::cout << std::endl;
    if (registerValidateDisplayName(DisplayName)){
        return DisplayName;
    } else {
        registerDisplayName();
    }
}

bool registerValidatePassword(std::string password){
        std::cout << "Enter your password again to confirm" << std::endl;
        std::string answer;
        std::cin >> answer;
        if (password == answer){
            return true;
        } else {
            setColor(12);
            std::cout << "Passwords aren't the same" << std::endl;
            return false;
        }
}

bool registerCheckPassword(std::string password){
    if (password.length() <= 3){
        setColor(12);
        std::cout << "Password is too short" << std::endl;
        return false;
    } else {
        return true;
    }
}

std::string registerPassword(){
    setColor(3);
    std::cout << "Enter Password: ";
    std::string password;
    std::cin >> password;
    std::cout << std::endl;
    if (registerCheckPassword(password)){
        if (registerValidatePassword(password)){
            return password;
        } else {
            return "";
        }
    } else {
        return "";
    }
}

void registerLastPasswordCheck(std::string username, std::string DisplayName){
    std::string password = registerPassword();
    if (!password.empty()){
        Create_User(username, password, DisplayName);
    } else {
        registerLastPasswordCheck(username,DisplayName);
    }
}

void User_register(){
    setColor(9);
    std::cout << "==== Registration started ====" << std::endl;
    setColor(11);
    std::cout << "Enter username: ";
    std::string username;
    std::cin >> username;
    std::cout << std::endl;
    if (!UserExist(username)){
        if (registerValidateUsername(username)){
            std::string DisplayName = registerDisplayName();
            registerLastPasswordCheck(username,DisplayName);
        } else {
            setColor(12);
            std::cout << "Username already exists" << std::endl;
            User_register();
        }
    } else {
            setColor(12);
            std::cout << "Username already taken" << std::endl;
            User_register();
        }
}

void Create_User(std::string username,std::string password, std::string DisplayName){
    setColor(4);
    std::cout << "Trying to create account..." << std::endl;

    std::ifstream inputFile("data.json");
    json jsonData;
    inputFile >> jsonData;
    inputFile.close();

    jsonData[username]["DisplayName"] = DisplayName;
    jsonData[username]["password"] = password;

    std::ofstream outputFile("data.json");
    outputFile << std::setw(4) << jsonData << std::endl;
    outputFile.close();

    setColor(10);
    std::cout << "Account created !" << std::endl;
    setColor(11);
    std::cout << "\t Asked: \t USERNAME \t PASSWORD \t DISPLAYNAME" << std::endl;
    std::cout << "\t Given: " << "\t" << username << "\t" << password << "\t" << DisplayName;
    std::string aa;
    std::cin >> aa;
    User_page(username);
}

void User_page(std::string username){
    json userData = openJSON()[username];
    setColor(2);
    std::string DisplayName = userData["DisplayName"].get<std::string>();
    std::cout << "Logged as " << DisplayName << std::endl;
    df_closing_app();
}

bool UserExist(std::string username){
    json data = openJSON();
    if (data.contains(username)) {
        return true;
    } else {
        return false;
    }
}

bool PasswordCheck(std::string username,std::string password){
    json data = openJSON();
    
    json userData = data[username];
    std::string Realpassword = userData["password"].get<std::string>();
    if (Realpassword == password){
        return true;
    } else {
        return false;
    }
}

int main()
{
    start();

    return 0;
}
