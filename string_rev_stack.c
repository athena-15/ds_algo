#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct stack
{
  int capacity;
  int top;
  char *array;
  
}stack;

stack *createStack(int size)
{
  stack *myStack = (stack *)malloc(sizeof(myStack));
  myStack->capacity = size;
  myStack->array = (char*)malloc(size * (sizeof(char)));
  myStack->top = -1;
  
  return myStack;
}

int isFull(stack *myStack)
{
  if(myStack->top == myStack->capacity)
    return 1;
  
  return 0;  
}

int isEmpty(stack *myStack)
{
  if(myStack->top == -1)
    return 1;
    
  return 0;
}

void stackPush(stack *myStack, char item)
{
  if (isFull(myStack))
    return;
  myStack->array[++myStack->top] = item;
  
}

char stackPop(stack *myStack)
{
  if (isEmpty(myStack))
    return '\0';
  return myStack->array[myStack->top--];
}

void reverseStr(char str[])
{
  stack *s;
  
  int len = strlen(str);
  s = createStack(len);
  
  for(int i=0; i<len; i++)
  {
    stackPush(s, str[i]);
  }
  
  for(int i=0; i<len; i++)
  {
    str[i] = stackPop(s);
  }
  
  
  
  
}

void main()
{
  char str[] = "abcd";
  
  reverseStr(str);
  printf("\n %s", str);
}

