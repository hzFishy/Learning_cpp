// imports
#include <iostream>
#include "../default_functions.h" //Located in Apps Folder
#include <vector>
#include <random>
#include <algorithm>

//Tries
int& getTries(){
    static int tries = 0;
    return tries;
}

void showPendue(){
    std::vector<std::string>  data = {"_|_"," | "," | "," | "," |/","  ___"};
    
    int tries = getTries();
    setColor(14);
    std::cout << "tries: " << tries << std::endl;
    if (tries != 0){
        if (tries < 7){
            for (int i = tries; i > 0; i--){
                std::cout << data[i-1] << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

// UsedLetters (wrong)
std::vector<char>& getUsedLetters(){
    static std::vector<char> letters = {};
    return letters;
}

void showUsedLetters(){
    setColor(15);
    std::cout << "You already used the following letters: ";
    for (char l : getUsedLetters()){
        std::cout << l << ", ";
    }
    std::cout << std::endl;
}

// GuessedLetters (good)
std::vector<char>& getGuessedLetters(){
    static std::vector<char> letters = {};
    return letters;
}

void showGuessingWord(std::string word){
    setColor(10);
    std::cout << "Word: ";
    std::vector<char> GuessedLetters = getGuessedLetters();
    for (char ch : word){
        if (isCharInVector(GuessedLetters,ch)){
            std::cout << " "<< ch << " ";
        } else {
            std::cout << " _ ";
        }
    }
    std::cout << std::endl;
}

//User Prompt
bool letterIsInWord(std::string word, char l){
    for (char il : word){
       if (il == l) {
            return true;
        }
    }
    return false;
}

void askUserLetter(std::string word){
    setColor(15);
    std::cout << "Guess a letter \n> ";
    char ans;
    std::cin >> ans;
    if (letterIsInWord(word, ans)){
        setColor(10);
        std::cout << "good" << std::endl;
        getGuessedLetters().push_back(ans);
    } else {
        setColor(12);
        std::cout << "not good" << std::endl;
        getTries()++;
        getUsedLetters().push_back(ans);
    }
}

//Utility
bool isWordGuessed(std::string word){
    std::vector<char> GuessedLetters = getGuessedLetters();
    std::vector<char> charsWord;
    for (char ch : word) {
            charsWord.push_back(ch);
    }
    
    bool letterFound = false;
    for (char ch_cw : charsWord){
        auto it = std::find(GuessedLetters.begin(), GuessedLetters.end(), ch_cw);
        if (it == GuessedLetters.end()){
            return false;
        }
    }
    return true;
    
}

//Start
//declars
void newGame();

void start(){
    std::cout << "Start ? \n> ";
    char ans;
    std::cin >> ans;
    switch (ans)
    {
    case 'y':
        newGame();
        break;
    
    default:
        df_closing_app();
        break;
    }
}

std::string getRandomWord(){
    std::vector<std::string> words = {"banana"};

    std::random_device rd;
    std::mt19937 generator(rd());
    
    std::uniform_int_distribution<int> distribution(0, words.size());

    return words[distribution(generator)];
}

void newRound(std::string word){
    
    if (!isWordGuessed(word)){
        system("cls");
        showPendue();
        showUsedLetters();
        std::cout << std::endl;
        showGuessingWord(word);
        std::cout << std::endl;
        askUserLetter(word);

        newRound(word);
    }
    setColor(10);
    std::cout << "you won ! " << std::endl;
}

void newGame(){
    newRound(getRandomWord());
    df_closing_app();
}

int main(){
    start();
    return 0;
}