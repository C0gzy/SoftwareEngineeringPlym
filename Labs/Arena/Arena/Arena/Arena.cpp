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
    int take_damage(short dmg) {
        health -= dmg;
        return health;
    }

};


string EnemyArray[1][2] = {
    {"Goblin","10"}
};

struct Enemies AllEnemies[5];
int Choice;
short PlayerHealth = 100;




int Create_Enemies() {

    for (int i = 0; i < 1; i++) {
        Enemies Current;
        Current.name = EnemyArray[i][0];
        Current.health = stoi(EnemyArray[i][1]);


        AllEnemies[i] = Current;
    }

    return 0;
}

int CreateGameScene() {
    Enemies CurrentEnemyData = AllEnemies[0];

    printf("---------------------\n %s \n Health: %d \n ---------------------\n %d", CurrentEnemyData.name.c_str(), CurrentEnemyData.health , PlayerHealth);



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
