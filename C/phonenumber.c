#include <stdio.h> 
#include <stdlib.h> 


int main() {
    char ch; 

    printf("Enter a phone number: ");

   do {
       ch = getchar();
        if (ch == 'A' ||ch ==  'B' ||ch ==  'C') { 
            printf("2"); 
        }
        else if (ch == 'D' ||ch ==  'E' ||ch ==  'F') { 
            printf("3");
        }
        else if (ch == 'G' ||ch ==  'H' ||ch ==  'I') { 
            printf("4"); 
        }
        else if (ch == 'J' ||ch ==  'K' ||ch ==  'L') { 
            printf("5"); 
        }
        else if (ch == 'M' ||ch ==  'N' ||ch ==  'O') { 
            printf("6"); 
        }
        else if (ch == 'P' ||ch ==  'R' ||ch ==  'S') { 
            printf("7"); 
        }
        else if (ch == 'T' ||ch ==  'U' ||ch ==  'V') { 
            printf("8"); 
        }
        else if (ch == 'W' ||ch ==  'X' ||ch ==  'Y') { 
            printf("9"); 
        }
        else printf("%c", ch);  
    } while(ch != '\n');

    return 0; 
}


