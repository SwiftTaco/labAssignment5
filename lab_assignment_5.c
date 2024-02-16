//AUTHOR: DIEGO MENDOZA
//DATE: 1/27/2024
//Name of assignment: programming_assignment_1
//Class: COP3502C Section 3

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char letter;
  struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
  int count = 0;
  while (head != NULL)
    {
      count++;
      head = head->next;
    }
  return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
  int len = length(head);
  char* str = (char*)malloc(sizeof(char) * (len + 1));
  int i = 0;
  while (head != NULL)
    {
      str[i] = head->letter;
      head = head->next;
      i++;
    }
  str[i] = '\0';
  return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
  node* newNode = (node*)malloc(sizeof(node));
  newNode->letter = c;
  newNode->next = NULL;
  if(*pHead == NULL)
  {
    *pHead = newNode;
  }
  else
  {
    node* current = *pHead;
    while(current->next != NULL)
      {
        current = current->next;
      }
    current->next = newNode;
  }
    

}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
  while(*pHead != NULL)
    {
      node* temp = *pHead;
      *pHead = (*pHead)->next;
      free(temp);
    }
}

int main(void)
{
  int i, strLen, numInputs;
  node* head = NULL;
  char* str;
  char c;
  FILE* inFile = fopen("input.txt","r");

  fscanf(inFile, " %d\n", &numInputs);

  while (numInputs-- > 0)
  {
    fscanf(inFile, " %d\n", &strLen);
    for (i = 0; i < strLen; i++)
    {
      fscanf(inFile," %c", &c);
      insertChar(&head, c);
    }

    str = toCString(head);
    printf("String is : %s\n", str);

    free(str);
    deleteList(&head);

    if (head != NULL)
    {
      printf("deleteList is not correct!");
      break;
    }
  }

  fclose(inFile);
}