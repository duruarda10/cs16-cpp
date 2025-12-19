#include <cassert>
#include "linkedList.h"
#include "linkedListFuncs.h"
#include <climits>

void addIntToEndOfList(LinkedList *list, int value)
{
  assert(list != NULL);

  Node *p = new Node;
  p->data = value;
  p->next = nullptr;

  if (list->head == NULL)
  {
    list->head = p;
    list->tail = p;
  }
  else
  {
    list->tail->next = p;
    list->tail = p;
    }
}

void addIntToStartOfList(LinkedList *list, int value)
{
  assert(list != NULL);
  Node *p = new Node;
  p->data = value;
  if (list->head == NULL){
    p->next = nullptr;
    list->head = p;
    list->tail = p;
  }
  else{
    p->next = list->head;
    list->head = p;
  }
}

Node *pointerToMax(LinkedList *list)
{
  assert(list != NULL);
  assert(list->head != NULL);
  int max = INT_MIN;
  Node *maxptr;
  Node *curr = list->head;
  while (curr){
    if (curr->data>max){
      maxptr=curr;
      max=curr->data;
    }
    curr=curr->next;
  }
  return maxptr;
}

Node *pointerToMin(LinkedList *list)
{
  assert(list != NULL);
  assert(list->head != NULL);
  int min = INT_MAX;
  Node *minptr;
  Node *curr = list->head;
  while (curr){
    if (curr->data<min){
      minptr=curr;
      min=curr->data;
    }
    curr=curr->next;
  }
  return minptr;
}

int largestValue(LinkedList *list)
{
  assert(list != NULL);
  assert(list->head != NULL);
  int max = INT_MIN;
  Node *curr = list->head;
  while (curr){
    if (curr->data>max){
      max = curr->data;
    }
    curr = curr->next;
  }
  return max;
}

int smallestValue(LinkedList *list)
{
  assert(list != NULL);
  assert(list->head != NULL);
  int min = INT_MAX;
  Node *curr = list->head;
  while (curr){
    if (curr->data<min){
      min = curr->data;
    }
    curr = curr->next;
  }
  return min;
}

int sum(LinkedList *list)
{
  assert(list != NULL);
  int sum = 0;
  Node *curr = list->head;
  while (curr){
    sum += curr->data;
    curr = curr->next;
  }
  return sum;
}
