#include <stdlib.h>
#include <stdio.h>
#include"BinarySearchTree.h"

int add(TreeNode **root, void *element, TreeComparator f){
    if((*root) == NULL){
         TreeNode *NewNode = (TreeNode*) malloc(sizeof(TreeNode));
         if(NewNode == NULL)
            return 0;
        NewNode->element = element;
        NewNode->left = NewNode->right = NULL;
        *root = NewNode;
        return 1;
    }

    int compvalue = f(element, (*root)->element);
    if(compvalue > 0){
        return add(&(*root)->right, element, f);
    }else if(comvalue < 0){
        return add(&(*root)->left, element, f);
    }else{
        return -1;
    }
}

/*
- Localiza um elemento na árvore
*
- Argumentos: 
- - root: A raiz da árvore/subárvore
- - key: o elemento a ser localizado
- - f: a função para comparação dos elementos
- - element: um parâmetro de saída
*
- Retorna: 
- - 1 em caso de sucesso
- - 0 caso não encontre
*/
int find(TreeNode *root, void *key, TreeComparator f, void **element){
    if(root == NULL)
        return 0;
    int compavalue = f(key, root->element);
    if(compvalue == 0){
        *element = root->element;
        return 1;
    }else if(compvalue > 0)
        return find(root->right, key, f, element);
    return find(root->left, key, f, element);
}

/*
- Imprime os elementos na ordem Esquerda Raiz Direita
*/
void in_order(TreeNode *root, printNode print){
    if(root != NULL){
        in_order(root->left, print);
        print(root->element);
        in_order(root->right, print);
    }
}

/*
- Imprime os elementos Raiz Esquerda Direita
*/
void pre_order(TreeNode *root, printNode print){
    if(root != NULL){
        print(root->element);
        pre_order(root->left, print);
        pre_order(root->right, print);
    }
}

/*
- Imprime os elementos Esquerda Direita Raiz
*/
void post_order(TreeNode *root, printNode print){
    if(root != NULL){
        post_order(root->left, print);
        post_order(root->right, print);
        print(root->element);
    }
}

TreeNode greaterRight(TreeNode **no){
    if((*no)->right != NULL)
        return greaterRight((*no)->right);
    else{
        TreeNode *aux = *no;

        if((*no)->left != NULL)
            *no = (*no)->left;
        else
            *no = NULL;
        return aux; 
    }
}

TreeNode SmallerLeft(TreeNode **Node){
    if((*no)->left != NULL)
        return SmallerLeft((*no)->left)
    else{
        TreeNode *aux = *no;
        if((*no)->right != NULL)
            *no = (*no)->right;
        else    
            *no = NULL;
        return aux;
    }
}

/*
- Remove um elemento na árvore
*
- Argumentos: 
- - root: A raiz da árvore/subárvore
- - key: o elemento a ser localizado e removido
- - f: a função para comparação dos elementos
*
- Retorna: 
- - 1 em caso de sucesso
- - 0 caso não encontre
*/
int removeTreeNode(TreeNode **root, void *key, TreeComparator f){
    if(*root == NULL){
        return 0;
    }
    int compvalue = f(key, (*root)->element);
}

/*
- Calcula a altura da árvore/subárvore
*
- Argumentos: 
- - root: A raiz da árvore/subárvore
*
- Retorna: 
- - inteiro que representa a altura da árvore
- - árvore com apenas um nó tem altura 0
*/
int height (TreeNode *root){

}

/*
- Destrói a árvore/subárvore
*
- Argumentos: 
- - root: A raiz da árvore/subárvore
*/
void destroy (TreeNode **root){

}

#endif