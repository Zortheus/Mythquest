// MYTHQUEST
// A text-based RPG for Mac Terminal
// by AJP
//
// v0.1.0

#include "includes/header.cpp" 
#include "includes/player.cpp"
#include "includes/monster.cpp"
#include "includes/encountersimp.cpp"
#include <iostream>

bool gameOver = false;
bool exitGame = false;
int mainMenuNum;

void Title_Screen()
{
    system("clear");
    srand(time(NULL));

    bool firstTime = true;

    if (firstTime == true){
        DrawArt(drawMenuTitle);
        cout << BOLDRED;
        DrawArt(drawMenuDemon);
        cout << RESET;
        sleep(3);
    }

    firstTime = false;

    system("clear");
}

void Level_Up_Stats()
{
    playerLevel++;
    playerStr++;
    playerAgi++;
    playerTou++;
    playerMnd++;
    playerCha++;
    playerHPTotal++;
    playerMPTotal++;
    playerHP = playerHPTotal;
    playerMP = playerMPTotal;
    playerXP = playerXP - 10;

    if (playerXP < 0)
        playerXP = 0;
}

void Level_Up_Menu()
{
    system("clear");

    DrawArt(drawLevelUpMenu);

    Level_Up_Stats();
    Print_playerImage();
    Print_playerStats();

    sleep(5);
    cout << endl;
}

void Adventure_Menu()
{
    system("clear");

    DrawArt(drawAdventureMenu);
    Draw_Loading();

    Generate_Adventure();
    Generate_Encounter1();

    if (playerXP >= 10)
        Level_Up_Menu();

    if (playerHP <= 0)
    {
        gameOver = true;
    }
}

void Shop_Menu()
{
    system("clear");
    
    DrawArt(drawShopMenu);

    int shopMenuNum;
    cout << "\nWelcome, " << playerColor << playerName << RESET << "!" << endl;
    cout << "\n\nCurrent HP   | " << BOLDRED << playerHP << RESET << " / " << BOLDRED << playerHPTotal << RESET << endl;
    cout << "\nCurrent Gold | " << BOLDYELLOW << playerGold << RESET << "\n\n\n";
    cout << ">> MENU" << endl;
    cout << "_______________________________\n" << endl;
    cout << "PRESS 1    | " << BOLDRED << "POTION" << RESET << " - " << BOLDYELLOW << "5 Gold" << RESET << endl;
    cout << "\n";
    cout << BOLDBLACK << "PRESS 0    | EXIT" << RESET << "\n\n";

    // Shop Menu Selection
    cin.clear();
    cout << "> ";
    cin >> shopMenuNum;
    cout << endl;
    if (shopMenuNum == 1 && playerGold >= 5)
    {
        playerHP = playerHPTotal;
        playerGold = playerGold - 5;
        cout << "Drank potion." << endl;
        cout << "\nCurrent HP : " << playerHP << " / " << playerHPTotal << endl;
        cout << "Current Gold : " << BOLDYELLOW << playerGold << RESET << endl;
        cout << endl;
        sleep(5);
    } else if (shopMenuNum == 0) {
    } else {
        Shop_Menu();
    }
    cin.clear();
    
    system("clear");
}

void Item_Menu()
{
    system("clear");   
    cout << "COMING SOON!" << endl;
    sleep(3);
}

void Stats_Menu()
{
    system("clear");

    DrawArt(drawStatsMenu);

    Print_playerImage();
    Print_playerStats();

    cin.clear();
    cout << BOLDBLACK << "ENTER 0 to EXIT" << RESET << endl;
    int exitMenu;
    cin >> exitMenu;

    switch(exitMenu)
    {
        case 0:
            break;
        default:
            Stats_Menu();
    }
}

void Town_Menu()
{
    system("clear");
    cin.clear();

    // DRAW TOWN MENU
    cout << BOLDWHITE;
    DrawArt(drawTown);
    cout << RESET;

    cout << "\n ENTER 1 | " << BOLDRED << "ADVENTURE" << RESET;
    cout << "\n ENTER 2 | " << BOLDYELLOW << "SHOP" << RESET;
    cout << "\n ENTER 3 | " << BOLDGREEN << "ITEMS" << RESET;
    cout << "\n ENTER 4 | " << BOLDCYAN << "STATS" << RESET;
    cout << BOLDBLACK << "\n\n ENTER 0 | EXIT" << RESET << "\n\n";

    // MENU SWITCH
    if (gameOver != true)
        cout << "> ";
        cin.clear();
        cin >> mainMenuNum;

    switch(mainMenuNum)
    {
        case 1:
            Adventure_Menu();
            break;
        case 2:
            Shop_Menu();
            break;
        case 3:
            Item_Menu();
            break;
        case 4:
            Stats_Menu();
            break;
        case 0:
            gameOver = true;
            break;
        default:
            Town_Menu();
            break;
    }
}

void Game_Over()
{
    system("clear");
    DrawArt(drawGameOver);
    sleep(3);
    cout << endl;
}

int main()
{
    Title_Screen();

    New_Character();

    do {
        Town_Menu();
    } while (gameOver != true);

    if (gameOver == true && mainMenuNum != 0)
        Game_Over();

    system("clear");

    return EXIT_SUCCESS;
}