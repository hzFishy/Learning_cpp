#include <iostream>
#include <filesystem>
#include "../default_functions.h" //Located in Apps Folder
#include <cstdlib>

const std::string ANSI_RESET = "\033[Om";
const std::string ANSI_RED = "\033[31m";
const std::string ANSI_GREEN = "\033[32m";
const std::string ANSI_YELLOW = "\033[33m";
const std::string ANSI_TEST = "\033[34m";

// Shortcut
namespace fs = std::filesystem;

void Tree_start(){
    std::cout << ANSI_YELLOW << "====================================\n";
}

int& Tree_getFolders(){
    static int new_folders = 0;
    return new_folders;
}

std::string Tree_addSpace(int remove){
    std::string returnS = "";
    for (int i = 0; i < Tree_getFolders()-remove; i++){
        returnS += "  ";
    }
    
    return returnS;
}

void Tree_addFolder(std::string folder_name){
    Tree_getFolders()++;
    std::cout << Tree_addSpace(1) << "\\||\\" << folder_name << "\\ \n";
}

void Tree_removeFolder(){
    Tree_getFolders()--;
}

std::string Tree_addLine(){
    return "=> ";
}

void parcourirDossier(const fs::path& dossier) {
    for (const auto& entry : fs::directory_iterator(dossier)) {
        if (fs::is_regular_file(entry)) {

            std::cout << Tree_addSpace(0)+"||" << Tree_addLine() << entry.path().filename().stem().string() << entry.path().extension().string() << "\n";
        }
    }

    for (const auto& entry : fs::directory_iterator(dossier)) {
        if (fs::is_directory(entry)) {

            std::string folderName = entry.path().filename().string();
            std::cout << ANSI_TEST << Tree_addSpace(0)+"|| \n";
            Tree_addFolder(folderName);

            parcourirDossier(entry.path());
            Tree_removeFolder();
            
        }
    }
}

void ask(){
    std::string input;
    std::cout << ANSI_RED << "Give path to search: ";
    std::cin >> input;
    fs::path FoldertoCover = input;
    // enter "./" for current dir

    std::cout << ANSI_YELLOW << "FoldertoCover: [ " << FoldertoCover << " ]\n";
    Tree_start();
    parcourirDossier(FoldertoCover);
}

int main() {
    std::cout << ANSI_GREEN << "Select a choice" << "\n";
    std::cout << "\t New Tree (n) \t Leave (q)" << "\n";
    char choice;
    std::cin >> choice;

    switch (choice)
    {
    case 'n':
        system("cls");
        ask();
        main();
    case 'q':
        df_closing_app();
        break;
    
    default:
        df_closing_app();
        break;
    }

    return 0;
}
