#include <iostream>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	

    int sec, dB, reading, count = 0;
    scanf("%d %d", &sec, &dB);

    for (int n = 0; n < sec; n++)
    {
        scanf("%d", &reading);
        if (reading > dB)
            count++;
        else
            printf("-1\n");
    }

    printf("%d\n", count);

}
