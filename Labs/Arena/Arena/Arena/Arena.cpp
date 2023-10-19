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








struct Entity {
    string name;
    int8_t health = 0;
    int8_t minattack = 0;
    int8_t attack = 0;
    int Gold = 0;

    void CreateDataEntry(string _n, int _h, int _a, int _ma , int _g) {
        name = _n;
        health = _h;
        attack = _a;
        minattack = _ma;
        Gold = _g;
    }


    int take_damage(short dmg) {
        srand((unsigned) time(0));


        int Attacked = minattack + (rand() % attack);
        health -= Attacked;  //dmg;
        
        return Attacked;
    }
};

struct Enemies : Entity
{
    

};


string EnemyArray[1][5] = {
    {"Goblin","10","1","5","10"}
};

struct Enemies AllEnemies[5];
int Choice;
int8_t Result;

struct PlayerStruct : Entity
{
    
};

PlayerStruct Player;



void Create_Enemies() {

    for (int i = 0; i < 1; i++) {
        Enemies Current;
        Current.CreateDataEntry(EnemyArray[i][0] , stoi(EnemyArray[i][1]) , stoi(EnemyArray[i][3]), stoi(EnemyArray[i][2]), stoi(EnemyArray[i][4]));
        AllEnemies[i] = Current;
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
            cout << " ----------------------------------------\n " << CurrentEnemyData.name << " attacked for " << Player.take_damage(CurrentEnemyData.attack) << " Damage!\n";
            Sleep(1000);
            cout << " ----------------------------------------\n " << Player.name << " attacked for " << CurrentEnemyData.take_damage(Player.attack) << " Damage!";
            Sleep(1000);
            

            break;
        default:
            break;
        }
    } while ((Player.health > 0) && (CurrentEnemyData.health > 0));

    return BattleEnd(CurrentEnemyData);
}

int MainMenu() {

    system("cls");
    //DisplayLogo();
    cout << MainLogoText;
    cout << "Main Menu: \nSelect Decision \n 1)Arena \n";
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
    Player.CreateDataEntry("Temp", 100, 5 , 3, 0);
    Create_Enemies();

    MainMenu();
    return 0;
}
