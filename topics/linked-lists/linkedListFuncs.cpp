#include "linkedListFuncs.h"
#include <stddef.h>
#include <climits>

using namespace std;

int recursiveSum(Node* head) {
 if (!head){
   return 0;
 }
 return head->data + recursiveSum(head->next);
}

int recursiveLargestValue(Node* head) {
 if (!head){
  return 0;
 }
 if (!head->next){
  return head->data;
 }
 int max = recursiveLargestValue(head->next);
 return(head->data>max) ? head->data : max;
}

Node* recursiveFindKthNode(Node *head, int k){
 if (!head||k<=0){
 return nullptr;
 }
 if(k==1){
  return head;
 }
 return recursiveFindKthNode(head->next,k-1);
}

Node* recursiveDeleteKthNode(Node *head, int k) {
 if (k==1){
  head = head->next;
  return head;
 }
 head->next = recursiveDeleteKthNode(head->next,k-1);
 return head;
}

Node* recursiveRemoveKFromFront(Node *head, int k) {
 if (k==0){
 return head;
 }
 return recursiveRemoveKFromFront(head->next,k-1);
}

Node* recursiveElementwiseSum(Node *head1, Node *head2) {
 if (!head1 && !head2){
  return nullptr;
 }
 int v1;
 int v2;

 if(head1){
  v1 = head1->data;
 }
 else{
  v1 = 0;
 }

 if(head2){
  v2 = head2->data;
 }
 else{
  v2 = 0;
 }

 Node* newNode = new Node;
 newNode->data = v1 + v2;
 newNode->next = recursiveElementwiseSum(head1 ? head1->next : NULL, head2 ? head2->next : NULL);
 return newNode;
}

Node* recursiveSplice(Node *head1, Node *head2) {
 if (!head1){
  return head2;
 }
 if (!head2){
  return head1;
 }
 
 Node* next1 = head1->next;
 Node* next2 = head2->next;
 
 head1->next=head2;
 head2->next=recursiveSplice(next1,next2);
 
 return head1;
}
