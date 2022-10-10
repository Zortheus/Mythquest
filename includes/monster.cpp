#include "header.cpp"

// Monster
string monsterName;
string monsterImage;
string monsterColor;
int monsterHP;
int monsterAttack;

// 1 Rat
// 2 Goblin
// 3 Demon
// 10 DEMOTAUR

void Choose_Monster (int randomEncNum)
{
    if (randomEncNum == 1) {
        monsterName = "Rat";
        monsterImage = drawRat;
        monsterColor = BOLDWHITE;
        monsterHP = 4;
        monsterAttack = 1;
    }
    else if (randomEncNum == 2) {
        monsterName = "Goblin";
        monsterImage = drawGoblin;
        monsterColor = BOLDGREEN;
        monsterHP = 6;
        monsterAttack = 2;
    }
    else if (randomEncNum == 3) {
        monsterName = "Demon";
        monsterImage = drawDemon;
        monsterColor = BOLDMAGENTA;
        monsterHP = 8;
        monsterAttack = 3;
    } 
    else {
        cout << endl;
    }
}

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