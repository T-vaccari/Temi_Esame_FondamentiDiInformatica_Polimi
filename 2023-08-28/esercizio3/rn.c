#include <stdio.h>
#include <stdlib.h>


typedef struct n_t {

    int indice1;
    int indice2;
    struct n_t * next;
}nodo_t;
void print(nodo_t * lista){
    nodo_t * temp = lista;
    while (temp != NULL){
        printf("(%d,%d)",temp->indice1,temp->indice2);
        temp = temp->next;

    }
}
nodo_t * costruiscilista (int * a, int target,int dim);
int main(){
    int a[] = {2, 8, 0, 3, 9, 6, 1, 3};
    print(costruiscilista(a,10,8));
    


}
nodo_t * costruiscilista (int * a, int target,int dim){
    nodo_t  * lista = NULL;
    nodo_t * temp = NULL;
    int somma = 0;
    int indice1 = 0;
    int indice2=0;
    for(int i=0;i<dim;i++){
        somma = somma + a[i];
        indice2=i;
        if(somma > target){
            nodo_t * newnode = (nodo_t *)malloc(sizeof(nodo_t));
            newnode->next= NULL;
            if(lista == NULL){
                lista = newnode;
                temp = newnode;

            }else{
                temp->next= newnode;
                temp = newnode;
            }
            somma = a[i];
            
            newnode->indice1=indice1;
            newnode->indice2=indice2-1;
            indice1 = i;
            
        }
        
    }
    if(somma!=0){
            nodo_t * newnode = (nodo_t *)malloc(sizeof(nodo_t));
            newnode->next= NULL;
            temp->next= newnode;
            
            newnode->indice1=indice1;
            newnode->indice2=dim-1;

        }
    return lista;
}