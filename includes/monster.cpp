#include "header.cpp"

// Monster
string monsterName;
string monsterImage;
string monsterColor;
int monsterHP;

void Print_monsterImage()
{
    cout << monsterColor << monsterImage << RESET << "\n\n";
}

void Print_monsterStats() 
{   
    cout << BOLDWHITE << "Name : " << RESET << monsterName << "" << endl;
    cout << BOLDRED << "HP        :   " << RESET << monsterHP << endl;
    cout << endl;
}