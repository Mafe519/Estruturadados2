#include<stdio.h>
#include<sdlib.h>
#include"DoublyLinkedList.h"
#include"log.h"

typedef bool (*compare)(void*,void*){

}
typedef void (*printNode)(void*){

}
void init(DoublyLinkedList *list){
    node *FirstNode = (Node*)malloc(sizeof(Node));
    FirstNode->data=NULL;
    FirstNode->first=FirstNode;
    FirstNode->previous=FirstNode;
    list->next=FirstNode;
    list->size=0;

}
int enqueue(DoublyLinkedList *list, void *data){
    Node *NewNode = (Node *)malloc(sizeof(Node));
    NewNode->data = data;
    NewNode->next = list->first;

    if(NewNode == NULL) return -1;

    NewNode->previous = list->first->previus;
    list->first->previous->next = NewNode;
    list->first->previous = NewNode;
    list->size++;

    return 1;
}
void* dequeue(DoublyLinkedList *list){
    if(isEmpty(list)) return NULL;

        Node *sentinela = list->first;
        Node *First = list->first->next;
        list->next->previous = sentinela;
        sentinela->prox = First->data;

        void *data = first->next;
        free(fisrt);

        list->size--; 
}
void* first(DoublyLinkedList *list){
    return list->first->next->data;
}
void* last(DoublyLinkedList *list){
    return list->first->previous->data;
}
int push(DoublyLinkedList *list, void *data){
    Node (*NewNode)malloc(sizeof(Node));
    NewNode = data;
    NewNode->prox = list->first->next;
    NewNode->previous = list->first;
    list->first->next->previous = NewNode;
    list->first->next = NewNode;
    list->size++;
    return 1;
}
void* pop(DoublyLinkedList *list){
    dequeue(list);
}
void* top(DoublyLinkedList *list){
    first(list);
}

bool isEmpty(DoublyLinkedList *list){
    return (list->size == 0);
}
int indexOf(DoublyLinkedList *list,void *data, compare equal);
Node* getNodeByPos(DoublyLinkedList *list,int pos);
void* getPos(DoublyLinkedList *list,int pos){
    int count = 0;
    if(isEmpty(list)) return -1;
}
int add(DoublyLinkedList *list, int pos, void *data);
int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource);
void* removePos(DoublyLinkedList *list, int pos);
bool removeData(DoublyLinkedList *list, void *data, compare equal);
void show(DoublyLinkedList *list, printNode print){
    Node *aux = list->first->next;
    while(aux!=list->first){
        print(aux->data);
        aux->aux->next;
    }
}
void showMem(DoublyLinkedList *list){
    printf("NewNode: %p \n",list->first);
    Node *aux = list->first->next;
    printf("Endereço do Nó: \n\n previous  -  Data  -  next\n\n")
    while(aux!=list->first){
        printf(" %p  %p  %p  %p:",aux, aux->previous, aux->data, aux->next);
        aux->aux->next;
    }
}
