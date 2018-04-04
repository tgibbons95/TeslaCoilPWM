#include <iostream>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
        int x = atoi(argv[1]);
        while(1){
                printf("\nGPIO Pin %d: %d",x,digitalRead(x));
        }

}

