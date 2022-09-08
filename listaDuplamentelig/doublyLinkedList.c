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
int indexOf(DoublyLinkedList *list,void *data, compare equal){
    int count = 0;
    if(isEmpty(list)) return -1;
    Node *aux = aux->first->next;

    while(aux != NULL && !equal (aux->data, data)){
        aux = aux->next;
        count++;
    }
    return(aux==list->first) ?-1: count;
}
Node* getNodeByPos(DoublyLinkedList *list,int pos){
    if(isEmpty(list) || pos>=list->size) return NULL;
    Node *aux = list->first->next;

    for(it count = 0; (aux!=NULL && count<pos);count++,aux=aux->next);

    return aux;
}
void* getPos(DoublyLinkedList *list,int pos){
    int count = 0;
    if(isEmpty(list)) return -1;

    Node *aux = list->first->next;
    while(count != pos && aux->next != list->first){
        count++;
        aux = aux->next;
    }
    aux->data;
}
int add(DoublyLinkedList *list, int pos, void *data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL) return -1;

    Node *aux = getNodeByPos(list, pos);

    newNode->data = data;

    newNode->next= aux;
    newNode->previous = aux->previous;

    aux->previus->next = newNode;
    aux->previous = newNode;

    list->size++;

    return 1;
}
int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource){
    Node *aux = getNodeByPos(list,pos);

    if(aux ==NULL) return -1;

    if(isEmpty(listSource)) return -2;

    listSource->first->previous->next = aux;
    listSource->first->next->previous = aux->previous;

    aux->previous->next = listSource->first->next;
    aux->previous-> listSource->first->previous;

    listDest->size+=listSource->size;

    return listSource->size;
}
void* removePos(DoublyLinkedList *list, int pos){
    if(isEmpty(list) || pis>= list->size) return NULL;

    Node *NodeRemove = getNodeByPos(list,pos);

    NodeRemove->previous->next = NodeRemove->next;
    NodeRemove->next->previous = NodeRemove->previous;

    void * dataRemove = NodeRemove->data;
    free(NodeRemove);
    list->size--;

    return dataRemove;
}
bool removeData(DoublyLinkedList *list, void *data, compare equal){
     if ( isEmpty (list)) return - 1 ;

    Node *nodeRemove = list->first->next;
    while(nodeRemove!= list->first && ! equal(nodeRemove->data, data))
        nodeRemove=nodeRemove->next;
    if(nodeRemove != list->first){
        nodeRemove->previous->next = nodeRemove->next;
        nodeRemove->next->previous = nodeRemove->previous;
        free(nodeRemove->data);
        free(nodeRemove);
        list->size--;
        return 1;
    } else{
        return 0;
    }
}
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
