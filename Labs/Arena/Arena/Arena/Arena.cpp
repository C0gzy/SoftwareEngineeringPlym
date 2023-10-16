// Arena.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
using namespace std;


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










struct Enemies
{
    string name;
    int8_t health = 0;
    int8_t attack = 0;
    int take_damage(short dmg) {
        health -= dmg;
        return health;
    }

};


string EnemyArray[1][3] = {
    {"Goblin","10","2"}
};

struct Enemies AllEnemies[5];
int Choice;

struct PlayerStruct
{
    string name;
    int8_t health = 100;
    int8_t attack = 5;
    int take_damage(short dmg) {
        health -= dmg;
        return health;
    }
};

PlayerStruct Player;

void Create_Enemies() {

    for (int i = 0; i < 1; i++) {
        Enemies Current;
        Current.name = EnemyArray[i][0];
        Current.health = stoi(EnemyArray[i][1]);
        Current.attack = stoi(EnemyArray[i][2]);


        AllEnemies[i] = Current;
    }

}

int CreateGameScene() {
    Enemies CurrentEnemyData = AllEnemies[0];


    do {
        printf("---------------------\n %s \n Health: %d \n ---------------------\n %s \n Health: %d \n ---------------------\n 1)Attack\n",
            CurrentEnemyData.name.c_str(), CurrentEnemyData.health, Player.name.c_str(), Player.health);

        cin >> Choice;

        switch (Choice)
        {
        case 1:



            CurrentEnemyData.take_damage(Player.attack);



            break;
        default:
            break;
        }
    } while ((Player.health > 0) && (CurrentEnemyData.health > 0));


    return 0;
}

int MainMenu() {
    cout << "Main Menu: \nSelect Decision \n 1)Arena \n";
    cin >> Choice;

    switch (Choice)
    {
    case 1:
        cout << "Arena";
        system("cls");
        CreateGameScene();
        break;
    default:
        break;
    }

    return 0;
}

int main()
{
    Create_Enemies();

    MainMenu();
    return 0;
}
