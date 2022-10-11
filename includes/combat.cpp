#include <iostream>
#include "header.cpp"
//COMBAT LOOP

bool playerIsDead = false;
bool monsterIsDead = false;
bool combatOver = false;

void Combat_Menu()
{
    bool playerIsDead = false;
    bool monsterIsDead = false;
    bool combatOver = false;

    do {
        system("clear");
        //Print_playerImage();
                //Print_MonsterImage

        // PLAYER ATTACKS
            // CHECK IF DEAD
        // MONSTER ATTACKS
            // CHECK IF DEAD

        Check_IfDead();
    } while (combatOver != true);

    // IF PLAYER HP <= 0, "Player has been slain!"
    // IF MONSTER HP <= 0, "Monster has been slain!"
    // DISPLAY RESULTS
}

void Player_Attack()
{
    // Check Damage stat
    // Get modifier
    // roll dice and add modifier
    // deal damage to monster
}

void Monster_Attack()
{
    // Check Damage stat
    // Get modifier
    // roll dice and add modifier
    // deal damage to monster
}

void Check_IfDead()
{
    if (playerIsDead == true || monsterIsDead == true)
        combatOver = true;
}

int Damage_Modifier(int damageStat)
{
    int damageMod = (damageStat / 4) - 1;
    return damageMod;
}