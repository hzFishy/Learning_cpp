// imports
#include <iostream>
#include <fstream>
#include "../default_functions.h" //Located in Apps Folder
#include <nlohmann/json.hpp>

//namespaces
using json = nlohmann::json;

//declarations
void performAction(int actionID);
void User_login();
void User_register();
void User_page(json userData);
bool UserExist();
bool PasswordCheck(std::string username,std::string password);
bool Create_User(std::string username,std::string password);

//functions
void start(){
    int answer = 0;
    if (std::cin >> answer) {
            performAction(answer);
    } else {
        std::cout << "La réponse n'est pas un choix valide." << std::endl;
        start();
    }
}

void performAction(int actionID){
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
        break;
    }   
}

json openJSON(){
    // open JSON file
    std::ifstream file("data.json");
    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return 0;
    }

    json data;
    file >> data;
    return data;
}

void User_login(){
    std::cout << "Enter username: ";
    std::string username;
    std::cin >> username;
    std::cout << std::endl;

    std::cout << "Enter Password: ";
    std::string userPSW;
    std::cin >> userPSW;
    std::cout << std::endl;

    
    if (User_Exist(username)) {
        json userData = data[username];
        std::string password = userData["passwordHash"].get<std::string>();
        if (PasswordCheck(username, password)){
            User_page(userData);
        } else {
            std::cerr << "Password invalid" << std::endl;
            User_login();
        }
    } else {
        std::cout << "Username not found" << std::endl;
        User_login();
    }
}

void User_register(){
    void enter_username(){
        std::cout << "Enter username: ";
        std::string username;
        std::cin >> username;
        std::cout << std::endl;
        void enter_password(){
            if (!User_Exist(username)){
                std::cout << "Enter Password: ";
                std::string userPSW;
                std::cin >> userPSW;
                std::cout << std::endl;
                if (userPSW.length() <= 3){
                    std::cout << "password is too short" << std:endl;
                    enter_password();
                } else {
                    Create_User(username, userPSW);
                }
            } else {
                std::cout << "Username already exists" << std::endl;
                enter_username();
            }
        }
    }


}

bool Create_User(std::string username,std::string password){
    //code
}

void User_page(json userData){
    std::cout << "Loged as " << userData["DisplayName"].get<std::string>() << std::endl;
}

bool User_Exist(std::string username){
    json data = openJSON();
    if (data.contains(username)) {
        return true
    } else {
        return false
    }
}

bool PasswordCheck(std::string username,std::string password){
    return false;
}

int main()
{
    std::cout << "Bienvenue ! Que souhaitez vous faire ?" << std::endl;
    std::cout << ">> Login (1) << \t >> Register (2) << \t >> Leave (3) << " << std::endl;

    start();

    return 0;
}
