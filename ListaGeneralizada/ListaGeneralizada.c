#include<stdlib.h>
#include<stdio.h>
#include"ListaGeneralizada"

int addAtom(Node **list, int atom) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    if(newNode == NULL)  return -1;

    newNode->type = 0;
    newNode->next = NULL;
    newNode->atomList.atom = atom;

    if(*list == NULL) {
        *list = newNode;
    }
    else {
        Node *aux = NULL;
        for(aux = *list; aux->next != NULL; aux = aux->next);
        aux->next = newNode;
    }
    return 1;
}
int addList(Node **list, Node **subList) {

    Node *newNode = (Node *)malloc(sizeof(Node));

    if(newNode == NULL) return -1;
    
    newNode->type = 1;
    newNode->next = NULL;
    newNode->atomList.list = *subList;

    if(*list == NULL) {
        *list = newNode;
    }
    else {
        Node *aux = NULL;
        for(aux = *list; aux->next != NULL; aux = aux->next);
        aux->next = newNode;
    }

    return 1;
}
Node* head(Node *list) {
    
    if(list == NULL) {
        return list;
    }
    else {
        Node *headAux = NULL;
        if(list->type == 0) {
            headAux = (Node *)malloc(sizeof(Node));
            if(headAux == NULL) {   
    
                return headAux;
            }
            headAux->type = 1;
            headAux->atomList.list = list->atomList.list;
            headAux->next = NULL;
        }
        else {
            headAux = list->atomList.list;    
        }
        return headAux;
    }   
}
Node* tail(Node *list) {
    if(list == NULL) {
        return list;
    }
    else {
        return list->next;
    }   
}
void show(Node *list) {
    Node *aux = NULL;
    for(aux = list; aux != NULL; aux = aux->next) {
        if (aux->type == 0) {
            printf("%d ",aux->atomList.atom);
        } else {
            show(aux->atomList.list);
        }
    }
    printf(")");
}
bool search(Node *list, int atom) {
    bool currentBool = false;
    if(list != NULL) {
        Node *aux = NULL;
        for(aux = list; aux != NULL; aux = aux->next) {
            if (aux->type == 1) {
                bool newBool = search(aux->atomList.list, atom);
                if(newBool == true) {
                    currentBool = true;;
                    return currentBool;
                }
            }
            else {
                if(aux->atomList.atom == atom) {
                    currentBool = true;
                    return currentBool;
                }
            }
        }
    }
    return currentBool;
}
int depth(Node *list) {
    int currentDepth = 0;
    if(list == NULL) {
        return 0;
    }
    Node *aux = NULL;
    for(aux = list; aux != NULL; aux = aux->next) {
        if(aux->type == 1) {
            int newDepth = depth(aux->atomList.list);
            if(newDepth > currentDepth) {
            currentDepth = newDepth;
            }
        }
    }
    return currentDepth + 1;
}