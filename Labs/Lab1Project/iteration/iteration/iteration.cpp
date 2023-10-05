

#include <stdio.h>
#include <windows.h>

int main()
{

    /*
    int i = 5;

    printf("Start while loop\n");

    do
    {
        printf("i = %d\n", i);
        i--;              // Alternatively, write i++;
    } while (i > 0);            //Repeat if condition is met

    printf("Finished: i = %d\n", i);

    */


    char bouncer[10] = {'O',' ',' ',' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' };

    printf("%.10s\n", bouncer);
    do {
        for (int i = 0; i < sizeof(bouncer) - 1; i++) {
            Sleep(10);
            //puts(bouncer[i]);
            if (bouncer[i] == 'O') {
                bouncer[i + 1] = 'O';
                bouncer[i] = ' ';

            }
            printf("%.10s\n", bouncer);
        }

        for (int i = sizeof(bouncer); i > 0; i--) {
            Sleep(10);
            if (bouncer[i] == 'O') {
                bouncer[i - 1] = 'O';
                bouncer[i] = ' ';

            }
            printf("%.10s\n", bouncer);
        }
    } while (1);


}
