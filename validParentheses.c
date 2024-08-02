#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define NODEBUG

#ifndef NODEBUG
#define printf(fmt, ...) (0)
#endif
void push(char );
struct node{
    char ch;
    struct node *pre_node;
};

struct node *stack = NULL;

void push(char ch)
{
    struct node *newNode=NULL;
    if(stack == NULL)
    {
        stack = malloc(sizeof(struct node)*1);
        stack->ch = ch;
        stack->pre_node=NULL;
	return;
    }
    newNode = malloc(sizeof(struct node)*1);
    newNode->ch = ch;
    newNode->pre_node = stack;
    stack = newNode;
    return;
}

char pop(void)
{
    char ch;
    struct node *temp = NULL;
    if(stack == NULL)
        return '\0';
    temp =  stack->pre_node;
    ch = stack->ch;
    free(stack);
    stack = temp;
    return ch;
}

char top(void)
{
    if(stack == NULL)
        return '\0';
    return stack->ch;
}
void freeupStack()
{
    char ch;
    while(top() != '\0')
        ch = pop();
}

bool isValid(char *str)
{
    stack = NULL;
    if(strlen(str)%2 !=0 ) 
    {
        printf("Invalid string\n");
        return false;
    }
    for(int i=0; i< strlen(str); i++)
    {
        //check if stack is empty or any opening char
        if(str[i] == '{' || str[i] == '(' || str[i] == '[' )
        {
            push(str[i]);
            continue;
        }
        //Now only closing char
        if((str[i] == '}' && top() != '{' ) ||
            (str[i] == ')' && top() != '(' ) ||
            (str[i] == ']' && top() != '[' ))
        {
            printf("Invalid string.\n");
            freeupStack();
            return false;
        }
	else
	{
	    char ch = pop();
	}
    }
    if(top() != '\0')
    {
            printf("Invalid string.\n");
	    return false;
    }
    printf("Yoo!! It is Valid string.\n");
    return true;
}
int main(int argc, char *argv[])
{
    if(argc < 2){
	    printf("Kindly provide string input\n");
	    return 1;
    }
    if(isValid(argv[1]))
    	return 0;
    else
	return 1;
}
