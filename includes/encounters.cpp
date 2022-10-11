#include "header.cpp"

int Damage_Modifier(int damageStat)
{
    int damageMod = (damageStat / 4) - 1;
    return damageMod;
}

void Generate_Adventure()
{
    int randomEncNum = (rand() % 10) + 1;
    
    // ADVENTURE FLAVOR TEXT
    cout << endl;
    if (randomEncNum == 1)
        cout << playerColor << playerName << RESET << " walked around. Then, out of nowhere..." << endl;
    
    if (randomEncNum == 2)
        cout << playerColor << playerName << RESET << " explored a cave. Suddenly..." << endl;
    
    if (randomEncNum == 3)
        cout << playerColor << playerName << RESET << " got lost in the woods." << endl;

    if (randomEncNum == 4)
        cout << playerColor << playerName << RESET << " walked down an old road. Heard a sound. Turned around and..." << endl;

    // #5
    if (randomEncNum == 5 && hasKey == true)
        cout << playerColor << playerName << RESET << " explored an ancient ruin. Then all of a sudden..." << endl;

    if (randomEncNum == 5 && hasKey == false)
    {
        cout << playerColor << playerName << RESET << " explored an ancient ruin. Found a key to the castle!" << endl;
        sleep(3);
        cout << "\n\tAdded " << BOLDMAGENTA << "CASTLE KEY" << RESET << " to ITEMS." << endl;
        sleep(3);
        cout << "\nThen all of a sudden..." << endl;
        sleep(1);
        hasKey = true;
    }

    if (randomEncNum == 6)
        cout << "It was a fine day in the countryside. " << playerColor << playerName << RESET << " was out for a stroll..." << endl; 

    if (randomEncNum == 7)
        cout << "After a long day of adventuring, " << playerColor << playerName << RESET << " was returning home when..." << endl; 


    // #8

    if (randomEncNum == 8 && hasMap == true)
    {
        cout << "While adventuring by the sea, " << playerColor << playerName << RESET << " witnessed a beautiful sunset. Just as it became dark...";
        sleep(3);
    }

    if (randomEncNum == 8 && hasMap == false)
    {
        cout << "While adventuring by the sea, " << playerColor << playerName << RESET << " found a " << BOLDMAGENTA << "TREASURE MAP" << RESET << " inside of a bottle." << endl;
        sleep(3);
        cout << "\n\tAdded " << BOLDMAGENTA << "TREASURE MAP" << RESET << " to ITEMS." << endl;
        sleep(3);
        cout << "\nIn that moment..." << endl;
        sleep(1);
        hasMap = true;
    }

    // #9
    if (randomEncNum == 9 && hasMap == true && hasJewel == true)
    {
        cout << playerColor << playerName << RESET << " returned to the mysterious island... but found nothing else." << endl;
        sleep(3);
        cout << "\nThen, out of nowhere..." << endl;
    }

    if (randomEncNum == 9 && hasMap == true && hasJewel == false)
    {
        cout << playerColor << playerName << RESET << " searched a mysterious island for buried treasure. Found a " << BOLDMAGENTA << "JEWEL" << RESET << "!" << endl;
        sleep(3);
        cout << "\n\tAdded " << BOLDMAGENTA << "JEWEL" << RESET << " to ITEMS." << endl;
        sleep(3);
        cout << "\nThen something unexpected happened..." << endl;
        sleep(1);
        hasJewel = true;
    }

    if (randomEncNum == 9 && hasMap == false && hasJewel == false)
    {
        cout << playerColor << playerName << RESET << " searched a mysterious island for buried treasure. Nothing was found." << endl;
    }

    if (randomEncNum == 10)
    {
        cout << "While walking through town " << playerColor << playerName << RESET << " encountered a shaman." << endl;
        sleep(3);
        cout << "\n\tThe shaman said 'the JEWEL protects against the DEMITAUR!'" << endl; 
        sleep(3);
    }

    cout << endl;
    sleep(1);
}

void Generate_Encounter1()
{
    int randomEncNum = (rand() % 10) + 1;
    int monsterAR, monsterXP, monsterGold;
    int randDamage, randXP, randGold;

    if (randomEncNum < 3) { // 20% chance
            // DRAW
            DrawArt(drawRat);
            sleep(1);
            cout << "Attacked by RAT! \n" << endl;
            sleep(3);

            if (playerStr >= 5 || playerAgi >= 7)
            {
                cout << "\tRat slain!" << endl;
                sleep(2);
                cout << "\n\nGained " << BOLDGREEN << "2 XP" << RESET << endl;
                playerXP = playerXP + 2;
                sleep(2);
            }
            
            cout << "Lost " << BOLDRED << "1 HP" << RESET << endl;
            sleep(2);
            playerHP--;
            
            cout << "\nCurrent HP : " << BOLDRED << playerHP << " / " << playerHPTotal << RESET << endl;
            sleep(2);
    }
        else if (randomEncNum == 3 || randomEncNum == 4) { // 20% chance
            DrawArt(drawGoblin);
            cout << BEEP;
            sleep(1);
            cout << "\nAttacked by GOBLIN! \n" << endl;
            sleep(3);

            if (playerStr >= 8 || playerAgi >= 8)
            {
                cout << "\tGoblin slain!" << endl;
                sleep(2);
                cout << "\n\nGained " << BOLDGREEN << "5 XP" << RESET << endl;
                sleep(1);
                cout << "Found " << BOLDYELLOW << "3 gold" << RESET << endl;
                sleep(2);
                playerXP = playerXP + 5;
                playerGold = playerGold + 3;
            }
            
            playerHP = playerHP - 3;
            cout << "Lost " << BOLDRED << "3 HP" << RESET << endl;
            sleep(3);
            
            cout << "\nCurrent HP : " << BOLDRED << playerHP << " / " << playerHPTotal << RESET << endl;
    }
        else if (randomEncNum == 5) { // 10% chance
            DrawArt(drawDemon);
            cout << BEEP;
            sleep(1);
            cout << "Attacked by DEMON! \n" << endl;
            sleep(3);

            if (playerStr >= 12 || playerAgi >= 12)
            {
                cout << "\tDemon slain!" << endl;
                sleep(2);
                cout << "\n\nGained " << BOLDGREEN << "10 XP" << RESET << endl;
                playerXP = playerXP + 10;
                sleep(2);
            }

            cout << "Lost " << BOLDRED << "5 HP" << RESET << endl;
            sleep(3);
            playerHP = playerHP - 5;
            cout << "\nCurrent HP : " << BOLDRED << playerHP << " / " << playerHPTotal << RESET << endl;
            sleep(2);
    }
        else if (randomEncNum == 6) { // 10% chance
            DrawArt(drawPuzzlePiece);
            cout << BEEP;
            sleep(1);
            cout << "Found a puzzle! Tried to solve it...\n" << endl;
            sleep(3);
            if (playerMnd >= 10){
                cout << "\tSolved!" << endl;
                sleep(1);
                cout << "\n\nFound " << BOLDYELLOW << "10 gold" << RESET << endl;
                cout << "Gained " << BOLDGREEN << "5 XP" << RESET << "\n";
                playerGold = playerGold + 10;
                playerXP = playerXP + 5;
                sleep(2);
                cout << "\nCurrent Gold : " << BOLDYELLOW << playerGold << RESET << endl;
                cout << "Current XP : " << BOLDGREEN << playerXP << RESET << endl;
                sleep(2);
            } else {
                cout << "\n\tUnable to solve! " << endl;
                sleep(2);
            }
    }
        else if (randomEncNum == 7 || randomEncNum == 8) { // 20% chance
            DrawArt(drawCampsite);
            cout << BEEP;
            sleep(1);
            cout << playerColor << playerName << RESET << " rested at a campsite." << endl;
            sleep(2);
            cout << "\n\tHP and MP are full!" << endl;
            sleep(1);
            playerHP = playerHPTotal;
            playerMP = playerMPTotal;
    }
        else if (randomEncNum == 9) { // 10% chance
            DrawArt(drawTrapDoor);
            cout << BEEP;
            sleep(1);

            if (playerAgi >= 10) {
                cout << "Trap door!" << endl;
                sleep(2);
                cout << "\tDodged at the last second!" << endl;
            } else if (playerMnd >= 10) {
                cout << "Trap door!" << endl;
                sleep(2);
                cout << "\n\tDisabled the trap!" << endl;
                sleep(2);
                cout << "\n\nGained " << BOLDGREEN << "2 XP" << RESET << endl;
                playerXP = playerXP + 2;
                sleep(1);
                cout << "\nCurrent XP : " << BOLDGREEN << playerXP << RESET << endl;
                sleep(2);
            } else {
                cout << "Trap door!" << endl;
                sleep(2);
                cout << "\n\tFell through!" << endl;
                sleep(2);

                cout << "\n\nLost " << BOLDRED << "2 HP" << RESET << endl;
                cout << "Dropped " << BOLDYELLOW << "3 gold" << RESET << endl;
                playerHP = playerHP - 2;
                playerGold = playerGold - 3;
                sleep(3);

                cout << "\nCurrent HP : " << BOLDRED << playerHP << " / " << playerHPTotal << RESET << endl;
                cout << "Current Gold : " << BOLDYELLOW << playerGold << RESET << endl;
                sleep(2);
            }
    }
        else if (randomEncNum == 10) { // 10% chance
            DrawArt(drawTraveller);
            cout << BEEP;
            sleep(1);
            cout << "\nMet a traveller on the road." << endl;
            sleep(3);

            if (playerCha >= 10)
            {
                cout << "\n\tTraveller found you charming." << endl;
                sleep(1);
                cout << "\n\tThey gave you " << BOLDYELLOW << "5 gold" << RESET << endl;
                sleep(3);
                cout << "\nGained " << BOLDGREEN << "5 XP" << RESET << endl;
                playerGold = playerGold + 5;
                playerXP = playerXP + 5;
                sleep(2);
                cout << "\nCurrent Gold : " << BOLDYELLOW << playerGold << RESET << endl;
                cout << "Current XP : " << BOLDGREEN << playerXP << RESET << endl;
            } else {
                cout << "\n\tYou both said 'hello' and went your separate ways." << endl;
                sleep(2);
            }
    } else {
        Generate_Encounter1();
    }

    sleep(3);
}

//int randTreasure = rand() % 10;
//cout << "Found " << randTreasure << " gold!" << endl;
//playerGold = playerGold + randTreasure;