#include <stdio.h> 
#include <stdlib.h> 


int main() 
{    

    int days, i, week = 0, initialize; 
    printf("Enter number of days in  month: "); 
    scanf("%d", &days); 
    printf("Enter starting day of the week: "); 
    scanf("%d", &initialize);
    initialize -= 1; 
    week = week + initialize; 

    while (initialize != 0) 
    {
        printf("\t"); 
        initialize -= 1; 
    }

    for ( i = 1; i <= days; i++)
    {
        printf("%d\t", i); 
        week += 1;
        if (week == 7) 
        {
            printf("\n\n"); 
            week = 0; 
        }
    }
    printf("\n"); 

    return 1; 
}