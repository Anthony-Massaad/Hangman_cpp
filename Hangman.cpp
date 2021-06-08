#include <iostream>
#include <stdlib.h> 
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Variables
int bodyCount, totalGuessedWord;
char completeBody[] = {'O', '|', '\\', '/', '\\', '/'};
bool gameover, exist = false, win, quit = false; 
vector<char> guessedWords;  
string words[] = {"Chocolate", "Basketball", "Net"};
string word, displayWord, another; 
char input; 
void stage(char body[]); 

int main(){
    do{    
        srand(time(0));
        bodyCount = 0;
        totalGuessedWord = 0;
        char body[] = {' ', ' ', ' ', ' ', ' ', ' '};
        win = false; 
        gameover = false;
        word = words[rand() % (sizeof(words)/sizeof(words[0]))];
        another = "";
        displayWord = "";
        guessedWords.clear();
        for (int i = 0; i< word.size(); i++){
            displayWord += "_"; 
        }
        while (gameover == false && win == false){
            stage(body);
            cout << "Guessed Letters: ";
            for (int i =0; i<guessedWords.size(); i++){
                cout << guessedWords[i] << " "; 
            } 
            cout << endl;
            cout << "Word: "; 
            for (int i=0; i < displayWord.size(); i++){
                cout << displayWord[i] << " "; 
            }
            cout << "For Admin -> " << word; // just to display the word
            cout << endl; 
            cout << another << endl; 
            cout << "Type a Letter: "; 
            cin >> input; 
            
            if (find(guessedWords.begin(), guessedWords.end(), input) != guessedWords.end()){
                another = "Guess another character";
            }
            else{ 
                another = "";
                for (int j = 0; j< word.size(); j++){
                    if (tolower(word[j]) == input){
                        displayWord[j] = word[j];
                        exist = true;
                        totalGuessedWord++; 
                        if (totalGuessedWord == word.size()){
                            win = true; 
                        }
                    }
                    if (exist == false && j == word.size()-1){
                        body[bodyCount] = completeBody[bodyCount];
                        bodyCount++; 
                        if (bodyCount == 6){
                            gameover = true; 
                        }
                    }
                }
                exist = false; 
                guessedWords.push_back(input);
            }
        }
        stage(body);
        if (win == true){
            cout << "YOU GOT THE WORD! -> '" << word << "'" << endl;
        }
        else if (gameover == true){
            cout << "Word was '" << word << "'" << endl; 
        }
        cout << "Would you like to play again? (any letter to continue or n to quit): ";
        cin >> input; 
        if (tolower(input) == 'n'){
            quit = true;
        }
    }while(quit == false);
    return 0;
}

void stage(char body[]){
    system("cls");
    cout << "Welcome To Hangman" << endl; 
    cout << "---------" << endl; 
    cout << "|       |" << endl; 
    cout << "|       " << body[0] << endl; 
    cout << "|      " << body[2] << body[1] << body[3] << endl;
    cout << "|       " << body[1] << endl;
    cout << "|      " << body[5] << " " << body[4] << endl; 
    cout << "-----" << endl; 

}

