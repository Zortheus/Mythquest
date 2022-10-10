#include "header.cpp"
#include "draw.cpp"

// Player Stats
string playerName;
int playerClassNum;
string playerClassName;
string playerImage;
string playerColor;
int playerLevel;
int playerXP;
int playerHP;
int playerHPTotal;
int playerMP;
int playerMPTotal;
int playerGold;
int playerStr;
int playerAgi;
int playerTou;
int playerMnd;
int playerCha;
int nextLevelUp = 1;

void Choose_Class()
{
    cout << "Choose a " << BOLDWHITE << "CLASS.\n" << RESET << endl;
    cout << " ENTER 1 | " << BOLDRED << " KNIGHT" << RESET << endl;
    cout << " ENTER 2 | " << BOLDBLUE << " WIZARD" << RESET << endl;
    cout << endl;

    cin.clear();
    cout << "> ";
    cin >> playerClassNum;
    
    sleep(1);
    system("clear");

    if (playerClassNum == 1)
    {
            playerClassName = "KNIGHT";
            playerImage = drawKnight;
            playerColor = BOLDRED;

            playerLevel = 1;        
            cout << "You have selected " << playerColor << "KNIGHT" << RESET << endl;
            
            // Set Stats
            playerHP = 10;
            playerHPTotal = 10;
            playerMP = 0;
            playerMPTotal = 0;
            playerGold = 5;
            playerStr = 10;
            playerAgi = 8;
            playerTou = 12;
            playerMnd = 4;
            playerCha = 6;
    } else if (playerClassNum == 2) {

            playerClassName = "WIZARD"; 
            playerImage = drawWizard;  
            playerColor = BOLDBLUE; 

            playerLevel = 1;  
            cout << "You have selected " << playerColor << "WIZARD" << RESET << endl;
            RESET;

            // Set Stats
            playerHP = 6;
            playerHPTotal = 6;
            playerMP = 10;
            playerMPTotal = 10;
            playerGold = 20;
            playerStr = 4;
            playerAgi = 6;
            playerTou = 8;
            playerMnd = 12;
            playerCha = 10;
    } else {
        cout << "Try again." << endl;
        Choose_Class();
    }

    sleep(1);
}

void Choose_Name()
{
    DrawArt(drawNewChar);

    cout << "\nHello, Player. Welcome to MYTHQUEST." << "\n\n";
    cout << "\nWhat is your " << BOLDWHITE << "NAME? \n" << RESET << endl;
    cout << "> ";

    cin.clear();
    cin >> playerName;
    cout << "\n\n";

    sleep(1);
}

void Print_playerImage()
{
    cout << playerColor << playerImage << RESET << "\n\n";
}

void Print_playerStats() 
{   
    cout << ">> " << BOLDWHITE << playerName << RESET << endl;
    cout << BOLDBLACK << "Level " << playerLevel << RESET << " ";
    cout << BOLDWHITE << playerColor << playerClassName << RESET << "\n" << endl;
    cout << BOLDRED << "HP        |   " << RESET << playerHP << " / " << playerHPTotal << endl;
    cout << BOLDBLUE << "MP        |   " << RESET << playerMP << " / " << playerMPTotal << endl;
    cout << BOLDYELLOW << "Gold      |   " << RESET << playerGold << "\n" << endl;
    cout << BOLDWHITE << "XP        |   " << RESET << playerXP << "\n" << endl;
    cout << BOLDCYAN << "Strength  |   " << RESET << playerStr << endl;
    cout << BOLDCYAN << "Agility   |   " << RESET << playerAgi << endl;
    cout << BOLDCYAN << "Toughness |   " << RESET <<  playerTou << endl;
    cout << BOLDCYAN << "Mind      |   " << RESET << playerMnd << endl;
    cout << BOLDCYAN << "Charm     |   " << RESET << playerCha << endl;
    cout << endl;

    sleep(1);
}

void New_Character()
{
    Choose_Name();
    Choose_Class();

    // Print the stats
    Print_playerImage();
    Print_playerStats();
    Draw_Loading();
}