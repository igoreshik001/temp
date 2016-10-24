#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char word[46];
    struct Node* next;
}Node;
Node* first=NULL;

//void findFunc(char* word);

void showFunc();

void addFunc(char* word);

void loadFunc();

int main()
{
    addFunc("opa");
    addFunc("jopa");
    loadFunc();
    printf("\nshow\n");
    showFunc();
}

void addFunc(char* word)
{
    Node* new=(Node*)malloc(sizeof(Node));
    strcpy(new->word, word);//new->word=word;
    if (first == NULL)
    {
        printf("\nif %s\n",word);
        new->next=first;
        first=new;
        return;
    }
    Node* tmp=first;
    while (tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    new->next=tmp->next;
    tmp->next=new;
}

void showFunc()
{
    if (first==NULL)
    {
        printf("empty");
        return;
    }
    Node* tmp=first;
    while (tmp != NULL)
    {
        printf("%s\n",tmp->word);
        tmp=tmp->next;
    }
}

void loadFunc()
{
    FILE* file = fopen("small","r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", "small.txt");
        return;
    }
    char word[46];
    int index=0;
    for (int c = fgetc(file); c != EOF; c = fgetc(file))
    {
        printf("{%c}",c);
        word[index]=c;
        index++;
        if (c=='\n')
        {
            word[index-1]='\0';
            printf("\n%s-word\n",word);
            addFunc(word);
            index=0;
        }
    }
    return;
}
