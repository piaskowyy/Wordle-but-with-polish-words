#include <iostream>
#include <Windows.h>
#include <time.h>
#include <random>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int text_color = 7;

string randomize()
{
    const string words[] = {
        "kubek","rower","telefon","dym","krzyk","ojciec","klucz","zegarek","centrum","list",
        "cisza","zimno","mistrz","kraj","wolny","czarny","niebieski","zielony","mama","widelec",
        "zachwyt","palec","stopa","noga","strach","obcy","kosmos","kosmita","rak","kot","pies",
        "krab","motyl","zamek","portfel","kultura","zeszyt","tygrys","lew","foka","testosteron",
        "nerw","uczucie","reszta","gra","jasno","ciemno","schody","winda","lewo","duch","zjawa","moc",
        "fakt","rok","okno","laptop","mysz","kawa","herbata","kabel","ekran","godzina","tekst","emotikon",
        "czekolada","cukier","dywan","liczba","chmura","spodnie","leszcz","jeden","woda","morze","jezioro",
        "rzeka","ucho","oko","nos","sklep","miecz","pistolet","buty","sweter","pisak","jajko","piorun",
        "cztery","motocykl","korek","system","kakao","linijka","smok","peleryna","horror","tarcza"
    };
    mt19937 seed(time(NULL));
    uniform_int_distribution<int> gen(0, sizeof(words) / sizeof(words[0]));
    int rng = gen(seed);
    string word = words[rng];
    return word;
}
string xword = randomize();
char guess[15];
void draw(string word, char guess[15])
{
    size_t length = word.length();
    for (int i = 0; i < length; i++)
    {
        text_color = 7;
        SetConsoleTextAttribute(hConsole, text_color);
        cout << "| ";
        if (word[i] == guess[i]) text_color = 2;
        else if (word.find(guess[i]) != string::npos) text_color = 6;
        SetConsoleTextAttribute(hConsole, text_color);
        cout << guess[i] << " ";
    }
    text_color = 7;
    SetConsoleTextAttribute(hConsole, text_color);
    cout << "|" << " --- word length: " << length << endl;
}
void rules()
{
    system("CLS");
    cout << "In wordle game your goal is to guess some random word" << endl << endl;
    cout << "|   |   |   |   |" << " <-- This is table that contains your guess" << endl << endl;
    cout << "| s | t | a |";
    text_color = 6;
    SetConsoleTextAttribute(hConsole, text_color);
    cout << " r";
    text_color = 7;
    SetConsoleTextAttribute(hConsole, text_color);
    cout << " |" << " <-- when letter is colored yellow it means that this letter is in word but not on this position" << endl << endl;
    cout << "| f | ";
    text_color = 2;
    SetConsoleTextAttribute(hConsole, text_color); 
    cout << "o ";
    text_color = 7;
    SetConsoleTextAttribute(hConsole, text_color); 
    cout << "| ";
    text_color = 2;
    SetConsoleTextAttribute(hConsole, text_color);
    cout << "r ";
    text_color = 7;
    SetConsoleTextAttribute(hConsole, text_color);
    cout << "| k |" << " <-- when letter is colored green it means that it is on the right position" << endl << endl;
    system("pause");
}
void game(string word, char guess[15])
{
    system("CLS");
    int turn = 0, lose = 1;
    for (int i = 0; i < word.length(); i++)
    {
        guess[i] = ' ';
    }
    draw(word, guess);
    while (turn != 5)
    {
        cin >> guess;
        draw(word, guess);
        if (word == guess)
        {
            lose = 0;
            text_color = 2;
            SetConsoleTextAttribute(hConsole, text_color);
            cout << "congratulations";
            text_color = 7;
            SetConsoleTextAttribute(hConsole, text_color);
            cout << ", you guessed the word!" << endl;
            break;
        }
        turn++;
    }
    if (lose == 1)
    {
        cout << "the word was: ";
        text_color = 2;
        SetConsoleTextAttribute(hConsole, text_color);
        cout << word;
        text_color = 7;
        SetConsoleTextAttribute(hConsole, text_color);
        cout << " better luck next time!" << endl;
    }
    int choice;
    cout << "[1] play again            [2] exit" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        game(randomize(), guess);
        break;
    case 2:
        exit(1);
    default:
        break;
    }
}
void start()
{   
    system("CLS");
    int choice;
    cout << "Welcome to polish wordle!" << endl;
    cout << "[1] Start" << endl;
    cout << "[2] Rules" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        break;
    case 2:
        rules();
        start();
        break;
    }
}
int main()
{
    start();
    game(randomize(), guess);
}
