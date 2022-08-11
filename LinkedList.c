#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "log.h"

void init( LinkedList *list){
    log_info("inicializando a lista");
    log_trace("entrando em init");
    list->first = NULL;
    list->size = 0;

    log_debug("list->first: %p", list->first);
    log_debug("list->size: %p", list->size);
    log_trace("saindo de init");

}

int enqueue(LinkedList *list, void *data){
    Node *novoNo = (Node *)malloc(sizeof (Node) );
    if (novoNo == NULL) return -1;

    novoNo->data = data;
    novoNo->next = NULL;
    

    if (list->first == NULL){   //se a lista estiver vazia
        list->first = novoNo;   // Novo nó é o primeiro
    }
    else{
        Node *aux = list->first;    //aux recebe o primeiro da lista

        while(aux->next != NULL){   //enquanto não for o ultimo nó
            aux = aux->next;        //aux recebe o próximo nó
        }
         aux->next = novoNo;        //ultimo nó aponta para o novo nó
    }

    list->size++;

    return 1;
}

bool isEmpty(LinkedList *list){
        return list->first == NULL;
}
void* dequeue(LinkedList *list){
    
    if (isEmpty(list)) return NULL;

    Node *aux = list->first;    // auxiliar recebe o dado do primeiro nó da fila
    list->first = list->first->next;   //o primeiro da lista recebe o próximo
    void *auxdata = aux->data;  //
    list->size--;
    free(aux);          

    return auxdata;
}

void* first(LinkedList *list){
    if (isEmpty(list)) return NULL;

    return list->first->data;

    //return isEmpty(list)?NULL:list->first->data;
}
void* last(LinkedList *list){
    if (isEmpty(list)) return NULL;

     Node *aux = list->first;    //aux recebe o primeiro da lista

        while(aux->next != NULL){   //enquanto não for o ultimo nó
            aux = aux->next;        //aux recebe o próximo nó
        }

         return aux->next;       
}
 //operações para pilha
int push(LinkedList *list, void *data){
    Node *novoNo = (Node *)malloc(sizeof (Node) );
    if (novoNo == NULL) return -1;

    novoNo->data = data;
    novoNo->next = NULL;

    if (list->first == NULL){   //se a lista estiver vazia
        novoNo->next = NULL;
        list->first = novoNo;   // Novo nó é o primeiro

    }
    else{
        Node *aux = list->first;
        list->first = novoNo;
        list->size++;
    }
     return 1;
}
void* pop(LinkedList *list){

    dequeue(list);
        
}

void* top(LinkedList *list){
    first(list);
}

int add(LinkedList *list, int pos, void *data){
    int count = 0;
    Node *novoNo = (Node *)malloc(sizeof (Node) );
    if (novoNo == NULL) return -1;

    Node *aux = list->first;
    novoNo->data = data;
    novoNo->next = NULL;
    
    while(count != pos-1 && aux->next != NULL){
        count++;
        aux = aux->next;
    }
        novoNo->next = aux->next;
        aux->next = novoNo;
        list->size++;
        
        return 1;
}

void* getPos(LinkedList *list, int pos){
    int count = 0;
    if (novoNo == NULL) return -1;

    Node *aux = list->first;
    while(count != pos && aux->next != NULL){
        count++;
        aux = aux->next;
    }

    return aux->data;
}

int addAll(LinkedList *listDest, int pos, LinkedList *listSource){
    Node *last = NULL;
}

int indexOf(LinkedList *list, void *data, compare equal){
    int count;

    
}

