#include <iostream>
#include <filesystem>

// Shortcut
namespace fs = std::filesystem;

void Tree_start(){
    std::cout << "====================================\n";
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
            std::cout << Tree_addSpace(0)+"|| \n";
            Tree_addFolder(folderName);

            parcourirDossier(entry.path());
            Tree_removeFolder();
            
        }
    }
}

int main() {

    std::string input;
    std::cout << "Give path to search: ";
    std::cin >> input;
    fs::path FoldertoCover = input;
    // enter "./" for current dir

    std::cout << "FoldertoCover: [ " << FoldertoCover << " ]\n";
    Tree_start();
    parcourirDossier(FoldertoCover);

    std::cout << "Appuyez sur une touche pour quitter...";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}
