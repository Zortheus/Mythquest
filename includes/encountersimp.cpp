#include "header.cpp"

void Generate_Adventure()
{
    int randomEncNum = (rand() % 3) + 1;

    cout << endl;
    if (randomEncNum == 1)
        cout << playerColor << playerName << RESET << " walked around. Then, out of nowhere..." << endl;
    
    if (randomEncNum == 2)
        cout << playerColor << playerName << RESET << " explored a cave. Suddenly..." << endl;
    
    if (randomEncNum == 3)
        cout << playerColor << playerName << RESET << " got lost in the woods." << endl;

    cout << endl;
    sleep(1);
}

void Generate_Encounter1()
{
    int randomEncNum = (rand() % 5) + 1;

    switch(randomEncNum)
    {
        // Rat Encounter
        case 1:
            DrawArt(drawRat);
            sleep(1);
            cout << "Attacked by RAT!" << endl;
            sleep(1);

            if (playerStr >= 10 || playerAgi >= 10)
            {
                cout << "\nRat slain." << endl;
                cout << "Gained 2 XP" << endl;
                playerXP = playerXP + 2;
                sleep(1);
            }

            cout << "Lost 1 hp." << endl;
            sleep(3);
            playerHP--;
            cout << "\nCurrent HP : " << playerHP << " / " << playerHPTotal << endl;
            break;

        // Goblin Encounter
        case 2:
            DrawArt(drawGoblin);
            sleep(1);
            cout << "Attacked by GOBLIN!" << endl;
            sleep(1);

            if (playerStr >= 10 || playerAgi >= 10)
            {
                cout << "\nGoblin slain." << endl;
                cout << "Gained 5 XP" << endl;
                playerXP = playerXP + 5;
            }

            sleep(1);
            cout << "Lost 3 hp." << endl;
            sleep(1);
            playerHP = playerHP - 3;
            cout << "\nCurrent HP : " << playerHP << " / " << playerHPTotal << endl;
            break;

        // Demon Encounter
        case 3:
            DrawArt(drawDemon);
            sleep(1);
            cout << "Attacked by DEMON!" << endl;
            sleep(1);

            if (playerStr >= 12 || playerAgi >= 12)
            {
                cout << "\nDemon slain." << endl;
                cout << "Gained 10 XP" << endl;
                playerXP = playerXP + 10;
            }

            cout << "Lost 5 hp." << endl;
            sleep(1);
            playerHP = playerHP - 5;
            cout << "\nCurrent HP : " << playerHP << " / " << playerHPTotal << endl;
            break;

        // Puzzle Encounter
        case 4:
            DrawArt(drawPuzzlePiece);
            sleep(1);
            cout << "Found a puzzle! Can you solve it?" << endl;
            if (playerMnd > 8){
                cout << "\nSolved! Found 10 gold and gained 5 XP.";
                playerGold = playerGold + 10;
                playerXP = playerXP + 5;
            } else {
                cout << "\nNot solved! " << endl;
            }
            sleep(1);
            cout << "\nCurrent Gold: " << BOLDYELLOW << playerGold << RESET << endl;
            break;

        // Campsite Encounter
        case 5:
            DrawArt(drawCampsite);
            sleep(1);
            cout << "Rested at CAMPSITE. HP and MP are full!" << endl;
            sleep(2);
            playerHP = playerHPTotal;
            playerMP = playerMPTotal;
            break;
        default:
            break;
    }
    
    sleep(3);
}

//int randTreasure = rand() % 10;
//cout << "Found " << randTreasure << " gold!" << endl;
//playerGold = playerGold + randTreasure;