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
    int count=0;
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
    if(listDest == NULL || isEmpty(listDest)) return -1;
    if(listSource == NULL || isEmpty(listSource)) return -2;

    Node *last = NULL;
    for(last = listSource->first; last->next != NULL; last=last->next);
    if(pos ==0){
        last->next = listDest->first;
    } else{
        Node *aux = getNodeByPos(listDest, (pos -1));
        if(aux == NULL) return -3;
        last->next = aux->next;
        aux->next = listSource->first;
    }
    listDest->size +=listSource->size;

    return listSource->size;
}

int indexOf(LinkedList *list, void *data, compare equal){
    int count = 0;
    if(isEmpty(list)) return -1;
    Node *aux = list->first;

    while(aux != NULL && !equal (aux->data, data)) {
        aux = aux->next;
        count++;
    }
    return(aux == NULL) ?- 1 :count;
}
Node* getNodeByPos(LinkedList *list, int pos){
    if(isEmpty(list) || pos>=list->size) return NULL;

    Node *aux = list->first;

    for(int count = 0;(aux!=NULL && count<pos);count++,aux=aux->next);

    return aux;
}
void * removePos (LinkedList *list, int pos) {
    if ( isEmpty (list) || pos>=list-> size ) return  NULL ;
    
    Node *nodeRemove = NULL ;
    Node *aux = NULL ;
       
    if (pos<= 0 )
        return dequeue(list);
    else
        aux = getNodeByPos (list, pos- 1 );

    nodeRemove = aux-> next ;
    aux-> next = nodeRemove-> next ;
    
    void * dataRemove = nodeRemove-> data ;
    free(nodeRemove);
    list-> size --;
      
    return dataRemove;
}

bool  removeData (LinkedList *list, void *data, compare equal) {
    if ( isEmpty (list)) return - 1 ;

    Node *nodeRemove = NULL ;
    if ( equal (list-> first -> data ,data)) {
        nodeRemove = list-> first ;
        list-> first = list-> first -> next ;
        free (nodeRemove-> data );
        free (nodeRemove);
        list-> size --;
    
        return true;
    } else {
        Node *aux = list-> first ;
        while (aux-> next != NULL && ! equal (aux-> next -> data ,data))
            aux=aux-> next;
    
        if (aux->next != NULL ) {
            Node *nodeRemove = aux-> next ;
            aux-> next = nodeRemove-> next ;
            free (nodeRemove-> data );
            free (nodeRemove);
            list-> size --;
            return true;
        } else {
           return false;
        }
    }
}
