#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <ctype.h>
#define MAX_LEN 20

struct list 
{
    char word[MAX_LEN]; 
    struct list *next; 
};
struct list *words = NULL; 


int add(); 
int sort(void);
int read_line(char str[], int n);

int main(void)
{ 
    struct list *count;
    int counter = 0, sort_cap = 50; 
    printf("\n>Welcome to the Alphabetizer! Enter words one at a time to sort them.\n>When you're ready to sort, simply press enter.\n\n");
    while (add())
    {
        counter++; 
    }

    if (counter == 1) 
    {
        printf("You only entered one word!\n");
        return 0; 
    }
    else if (counter == 0) 
    {
        printf("You didn't enter anything!\n");
        return 0;
    }


    while(sort_cap > 0)
    {
        sort();
        sort_cap--;
    } 

    printf("Ordered: ");
     for (count = words->next; count != NULL; count = count->next)
    {
        printf("%s ", count->word);
    }
    
    printf("\n");   
    return 0; 
}


int sort(void)
{
    struct list *prev, *cur, *prev2;
    for (cur = words->next, prev = words, prev2 = NULL; cur != NULL && strcmp(cur->word, prev->word) > 0; prev2 = prev, prev = cur, cur = cur->next);
    if (cur == NULL)
    {
        return 0; 
    }
    else 
    {
        prev->next = cur->next;
        cur->next = prev;
        prev2->next = cur; 
    return 0;
    }
}


int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
  {
    if (i < n)
    {
      str[i++] = tolower(ch);
    }
  }
  str[i] = '\0';
  return i;
}


int add(void) 
{
    struct list *new;
    new = malloc(sizeof(struct list)); 
    if (new == NULL)
    {
        printf("No more words!"); 
        exit(EXIT_FAILURE); 
    }
   
    printf("-Enter a word: "); 
    int j = read_line(new->word, MAX_LEN); 

    new->next = words; 
    words = new; 
    return j;
}


