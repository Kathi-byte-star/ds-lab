#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
structNode*next;
};
struct Queue{
structNode*front;
structNode*rear;
};
struct Node*createNode(int data);
void initializeQueue(struct Queue *queue);
void enqueue(struct Queue*queue,int data);
int dequeue(struct Queue*queue);
void displayQueue(struct Queue*queue);
int main()
{
struct Queue queue;
int choice,element;
initilaizeQueue(&queue);
while(1){
printf("\nQueue Operations Menu:\n");
printf("1.Enqueue\n");

