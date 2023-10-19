// Arena.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"


/*
int8_t      8-bit integer
uint8_t     8-bit unsigned integer
int16_t     16-bit integer
uint16_t    16-bit unsigned integer
int32_t	    32-bit integer
uint32_t	32-bit unsigned integer
int64_t	    64-bit integer
uint64_t	64-bit unsigned integer
*/



struct Weapon {
    string name;
    int8_t maxDamage = 0;
    int8_t minDamage = 0;
    int8_t cost = 0;

    int BuyWeapon(int& CurrentGold) {
        if (CurrentGold - cost <= 0) {

            return CurrentGold -= cost;
        }

    }

    void CreateDataEntry(string _n, int _ma, int _mia, int _c) {
        name = _n;
        maxDamage = _ma;
        minDamage = _mia;
        cost = _c;
    }
};





struct Entity {
    string name;
    int8_t health = 0;
    //int8_t minattack = 0;
    //int8_t attack = 0;
    int Gold = 0;
    Weapon CurrentEquipped;

    void CreateDataEntry(string _n, int _h , int _g, Weapon _ce) {
        name = _n;
        health = _h;
        //attack = _a;
        //minattack = _ma;
        Gold = _g;
        CurrentEquipped = _ce;
    }


    int take_damage(Weapon WeaponE) {
        srand(time(0));


        int Attacked = WeaponE.minDamage + (rand() % (WeaponE.maxDamage - 1));
        health -= Attacked;  //dmg;
        
        return Attacked;
    }
};



struct Enemies : Entity
{
    

};


string EnemyArray[2][4] = {
    {"Goblin","10","10","1"},
    {"Skeleton","7","15","2"}
};

string WeaponArray[3][4] = {
    {"Fists","3","2","0"},
    {"Club","6","2","15"},
    {"Bow","7","3","10"}
};

Enemies AllEnemies[5];
Weapon AllWeapons[5];
int Choice;
int8_t Result;

struct PlayerStruct : Entity
{
    
    Weapon Inventory[10];
};

PlayerStruct Player;



void Create_Enemies() {

    for (int i = 0; i < 1; i++) {
        Enemies Current;
        Current.CreateDataEntry(EnemyArray[i][0] , stoi(EnemyArray[i][1]) , stoi(EnemyArray[i][2]), AllWeapons[stoi(EnemyArray[i][3])]);
        AllEnemies[i] = Current;
    }

}

void Create_Weapons() {
    for (int i = 0; i < 2; i++) {
        Weapon Current;
        Current.CreateDataEntry(WeaponArray[i][0], stoi(WeaponArray[i][1]), stoi(WeaponArray[i][2]), stoi(WeaponArray[i][3]));
        AllWeapons[i] = Current;
    }
}


int BattleEnd(Enemies CurrentEnemy) {

    if (CurrentEnemy.health > 0) {
        cout << "---------------------\n        " << CurrentEnemy.name << "     Won this Battle\n       Better luck next time\n" << "---------------------";
        return 0;
    }
    else
    {
        Player.Gold += CurrentEnemy.Gold;
        cout << "---------------------\n   " << Player.name << " Won this Battle\n     You won " << CurrentEnemy.Gold << " Gold \n Current Gold Amount " << Player.Gold << "\n" << "---------------------";
        return 1;
    }

    return 1;
}

int CreateGameScene() {
    Enemies CurrentEnemyData = AllEnemies[0];


    do {
        system("cls");
        printf(" ---------------------\n %s \n Health: %d \n ---------------------\n %s \n Health: %d \n ---------------------\n 1)Attack\n",
            CurrentEnemyData.name.c_str(), CurrentEnemyData.health, Player.name.c_str(), Player.health);

        cin >> Choice;

        switch (Choice)
        {
        case 1:

            
            
            system("cls");
            cout << " ----------------------------------------\n " << CurrentEnemyData.name << " attacked with " << CurrentEnemyData.CurrentEquipped.name << " for " << Player.take_damage(CurrentEnemyData.CurrentEquipped) << " Damage!\n";
            Sleep(1000);
            cout << " ----------------------------------------\n " << Player.name << " attacked with " << Player.CurrentEquipped.name << " for " << CurrentEnemyData.take_damage(Player.CurrentEquipped) << " Damage!";
            Sleep(1000);
            

            break;
        default:
            break;
        }
    } while ((Player.health > 0) && (CurrentEnemyData.health > 0));

    return BattleEnd(CurrentEnemyData);
}

void Shop() {

}



int MainMenu() {

    system("cls");
    //DisplayLogo();
    cout << MainLogoText;
    cout << "\nSelect Decision \n 1)Arena \n";
    cin >> Choice;
    
    switch (Choice)
    {
    case 1:
        
        Result = CreateGameScene();
        if (Result == 0) return 0;
        if (Result == 1) MainMenu();

        break;
    default:
        break;
    }

    return 0;
}

int main()
{

    Create_Weapons();
    Create_Enemies();
   

    Player.CreateDataEntry("Temp", 100, 1000, AllWeapons[0]);


    MainMenu();
    return 0;
}
