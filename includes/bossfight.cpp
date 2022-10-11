#include "header.cpp"

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