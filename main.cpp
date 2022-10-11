// MYTHQUEST
// A text-based RPG for Mac Terminal
// by AJP
//
// v0.3.0

#include "includes/header.cpp" 
#include "includes/player.cpp"
#include "includes/monster.cpp"
#include "includes/encounters.cpp" 
//#include "includes/bossfight.h"
#include <iostream>

bool gameOver = false;
bool exitGame = false;
int mainMenuNum;

//bossfight

void Boss_Fight()
{
    system("clear");

    cout << BOLDWHITE;
    DrawArt(drawCastle);
    cout << BEEP;
    cout << RESET;

    sleep(3);

    if (hasKey == true)
    {
        cout << BOLDYELLOW;
        DrawArt(drawKey);
        cout << BEEP;
        cout << RESET;

        sleep(1);
        cout << "Used CASTLE KEY!" << endl;
        sleep(1);
        
        system("clear");
        
        cout << BOLDRED;
        DrawArt(drawMenuDemon);
        cout << BEEP;
        cout << RESET;

        cout << "\n\n" << BOLDWHITE << "BOSS FIGHT : DEMOTAUR" << RESET << endl;
        sleep(3);
        cout << "\n" << BOLDMAGENTA << "Are you strong enough to defeat him?" << RESET << endl;
        sleep(3);
        cout << ".";
        sleep(1);
        cout << ".";
        sleep(1);
        cout << ".";
        sleep(1);

        if (hasJewel == true)
        {
            cout << BEEP;
            cout << "JEWEL protected " << playerColor << playerName << " from DEMOTAUR's wrath!" << endl;
            sleep(2);
            cout << BEEP;
            cout << "\nDEMOTAUR HAS BEEN SLAIN!" << endl;
            sleep(3);
            cout << playerColor << playerName << " is victorious!" << RESET << endl;
            bossSlain = true;
            gameOver = true;
            sleep(3);
        } else {
            cout << BEEP;
            cout << "\nDEMOTAUR IS TOO POWERFUL! " << endl;
            sleep(3);
            cout << playerColor << playerName << " lost 10 HP!" << RESET << endl;
            playerHP = playerHP - 10;
            sleep(3);
        }
    } else {
        cout << BEEP;
        cout << "\nNeed CASTLE KEY!" << endl;
        sleep(3);
    }

    if (playerHP <= 0)
    {
        gameOver = true;
    }
}

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

void Level_Up_Menu()
{
    system("clear");
    
    DrawArt(drawLevelUpMenu);
    cout << BEEP;

    do {
        Level_Up_Stats();
    } while (playerXP >= nextLevelUp);

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

    // CHECK IF GAME OVER
    if (playerHP <= 0)
    {
        gameOver = true;
        cout << "\n" << playerColor << playerName << BOLDRED << " has been slain!" << RESET << endl;
        sleep(3);
    }

    // CHECK IF LEVEL UP
    if (playerXP >= nextLevelUp && gameOver != true)
    {
        Level_Up_Menu();
    }

    if (playerGold < 0)
        playerGold = 0;
}

void Shop_Menu()
{
    system("clear");
    
    DrawArt(drawShopMenu);
    cout << BEEP;

    int shopMenuNum;
    cout << "\nWelcome, " << playerColor << playerName << RESET << "!" << endl;
    cout << "\n\nCurrent HP   | " << BOLDRED << playerHP << RESET << " / " << BOLDRED << playerHPTotal << RESET << endl;
    cout << "\nCurrent Gold | " << BOLDYELLOW << playerGold << RESET << "\n\n\n\n";
    cout << "PRESS 1 | " << BOLDRED << "POTION" << RESET << " - " << BOLDYELLOW << "5 Gold" << RESET << endl;
    cout << "\n\n\n";
    cout << BOLDBLACK << "PRESS 0    | EXIT" << RESET << "\n\n";

    // Shop Menu Selection
    cin.clear();
    cout << "> ";
    cin >> shopMenuNum;
    cout << endl;
    if (shopMenuNum == 1 && playerGold >= 5)
    {
        system("clear");

        cout << BOLDRED;
        DrawArt(drawPotion);
        cout << BEEP;
        cout << RESET;
        sleep(1);

        playerHP = playerHPTotal;
        playerGold = playerGold - 5;
        cout << "\nDrank potion." << endl;
        cout << "\nCurrent HP : " << BOLDRED << playerHP << " / " << playerHPTotal << RESET << endl;
        cout << "Current Gold : " << BOLDYELLOW << playerGold << RESET << endl;
        cout << endl;
        sleep(4);
    } else if (shopMenuNum == 1 && playerGold < 5) {
        cout << BEEP << "\nNot enough gold!" << endl;
        sleep(2);
        Shop_Menu();
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

    int itemMenuNum;
    DrawArt(drawItemMenu);
    cout << BEEP;

    cout << "\n\n\n";

    if (hasKey == true)
        cout << "- CASTLE KEY \n\n";
    
    if (hasMap == true)
        cout << "- TREASURE MAP \n\n";

    if (hasJewel == true)
        cout << "- JEWEL \n\n";

    sleep(1);

    cout << "\n\n\n";
    cout << BOLDBLACK << "PRESS 0    | EXIT" << RESET << "\n\n";

    // Item Menu Selection
    cin.clear();
    cout << "> ";
    cin >> itemMenuNum;

    if (itemMenuNum == 0) {
    } else {
        Item_Menu();
    }
    cin.clear();
    
    system("clear");
}

void Stats_Menu()
{
    system("clear");

    DrawArt(drawStatsMenu);
    cout << BEEP;

    Print_playerImage();
    Print_playerStats();

    cin.clear();
    cout << BOLDBLACK << "ENTER 0 to EXIT" << RESET << endl;
    int exitMenu;
    cout << "> ";
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
    cout << BEEP;
    cout << RESET;

    cout << "\n ENTER 1 | " << BOLDRED << "ADVENTURE" << RESET;
    cout << "\n ENTER 2 | " << BOLDYELLOW << "SHOP" << RESET;
    cout << "\n ENTER 3 | " << BOLDGREEN << "ITEMS" << RESET;
    cout << "\n ENTER 4 | " << BOLDCYAN << "STATS" << RESET;
    cout << "\n ENTER 5 | " << BOLDMAGENTA << "ENTER CASTLE" << RESET;
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
        case 5:
            Boss_Fight();
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
    cout << BEEP;
    sleep(3);
    cout << endl;
}

void Victory_Menu()
{
    system("clear");
    DrawArt(drawVictory);
    sleep(1);
    DrawArt(drawTheEnd);
    sleep(3);
    cout << "\n\n";
    Print_playerImage();
    cout << playerColor << playerName << RESET << " found the key, slayed the boss, and become a true hero." << endl;
    sleep(3);
    cout << "\n\n\nThank you for playing MYTHQUEST!" << endl;
    sleep(5);
    cout << BEEP;
}

int main()
{
    Title_Screen();

    New_Character();

    do {
        Town_Menu();
    } while (gameOver != true);

    if (gameOver == true && bossSlain == false && mainMenuNum != 0)
        Game_Over();

    if (gameOver == true && bossSlain == true)
        Victory_Menu();

    system("clear");

    return EXIT_SUCCESS;
}