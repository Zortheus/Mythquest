#include "header.cpp"

void Generate_Adventure()
{
    int randomEncNum = (rand() % 5) + 1;

    cout << endl;
    if (randomEncNum == 1)
        cout << playerColor << playerName << RESET << " walked around. Then, out of nowhere..." << endl;
    
    if (randomEncNum == 2)
        cout << playerColor << playerName << RESET << " explored a cave. Suddenly..." << endl;
    
    if (randomEncNum == 3)
        cout << playerColor << playerName << RESET << " got lost in the woods." << endl;

    if (randomEncNum == 4)
        cout << playerColor << playerName << RESET << " walked down an old road. Heard a sound. Turned around and..." << endl;

    if (randomEncNum == 5 && hasKey == true)
        cout << playerColor << playerName << RESET << " explored an ancient ruin. Then all of a sudden..." << endl;

    if (randomEncNum == 5 && hasKey == false)
        cout << playerColor << playerName << RESET << " explored an ancient ruin. Found " << BOLDGREEN << "CASTLE KEY" << RESET << ". Then all of a sudden..." << endl;
        hasKey = true;

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
            sleep(3);

            if (playerStr >= 10 || playerAgi >= 10)
            {
                cout << "\nRat slain." << endl;
                cout << "Gained 2 XP" << endl;
                playerXP = playerXP + 2;
            }

            sleep(1);
            cout << "\nLost 1 hp." << endl;
            sleep(3);
            playerHP--;
            cout << "\nCurrent HP : " << playerHP << " / " << playerHPTotal << endl;
            break;

        // Goblin Encounter
        case 2:
            DrawArt(drawGoblin);
            sleep(1);
            cout << "Attacked by GOBLIN!" << endl;
            sleep(3);

            if (playerStr >= 10 || playerAgi >= 10)
            {
                cout << "\nGoblin slain." << endl;
                cout << "Gained 5 XP" << endl;
                playerXP = playerXP + 5;
            }

            sleep(1);
            cout << "\nLost 3 hp." << endl;
            sleep(3);
            playerHP = playerHP - 3;
            cout << "\nCurrent HP : " << playerHP << " / " << playerHPTotal << endl;
            break;

        // Demon Encounter
        case 3:
            DrawArt(drawDemon);
            sleep(1);
            cout << "Attacked by DEMON!" << endl;
            sleep(3);

            if (playerStr >= 12 || playerAgi >= 12)
            {
                cout << "\nDemon slain." << endl;
                cout << "Gained 10 XP" << endl;
                playerXP = playerXP + 10;
            }

            sleep(1);
            cout << "\nLost 5 hp." << endl;
            sleep(3);
            playerHP = playerHP - 5;
            cout << "\nCurrent HP : " << playerHP << " / " << playerHPTotal << endl;
            break;

        // Puzzle Encounter
        case 4:
            DrawArt(drawPuzzlePiece);
            sleep(1);
            cout << "Found a puzzle! Can you solve it?" << endl;
            if (playerMnd >= 8){
                cout << "\nSolved! Found 10 gold and gained 5 XP.";
                playerGold = playerGold + 10;
                playerXP = playerXP + 5;
                sleep(3);
                cout << "\nCurrent Gold: " << BOLDYELLOW << playerGold << RESET << endl;
                sleep(2);
            } else {
                cout << "\nNot solved! " << endl;
                sleep(3);
            }
            break;

        // Campsite Encounter
        case 5:
            DrawArt(drawCampsite);
            sleep(1);
            cout << "Rested at CAMPSITE. HP and MP are full!" << endl;
            sleep(3);
            playerHP = playerHPTotal;
            playerMP = playerMPTotal;
            break;
        case 6:
            DrawArt(drawTrapDoor);
            sleep(1);
            cout << "Fell through a trap door! Lost 2 HP and dropped 3 gold." << endl;
            sleep(3);
            playerHP = playerHP - 2;
            playerGold = playerGold - 3;
            break;

        default:
            break;
    }

    sleep(3);
}

//int randTreasure = rand() % 10;
//cout << "Found " << randTreasure << " gold!" << endl;
//playerGold = playerGold + randTreasure;