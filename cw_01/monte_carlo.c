#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int number=100000000;

int main()
{
    srand(time(NULL));
    int inside=0;
    double x, y;

    for(int i=0; i<number; i++){
        x=((double)rand()/RAND_MAX)-(.5);
        y=((double)rand()/RAND_MAX)-(.5);
        if((x*x+y*y)<=.25){
            inside++;
        }
    }
    double pi=(4.0*inside)/number ;
    printf("%lf", pi);
    
    printf("\n----------\n");
    system("pause");
    return 0;
}

