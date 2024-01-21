#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typedef struct nodo {
    char nome[MAX];
    char cognome[MAX];
    int occ;
    struct nodo *nextelem;
} nodo_t;
nodo_t * ordinalista(nodo_t * testa);
void swap (nodo_t * prec, nodo_t * nodo);
nodo_t *ordine1(FILE *);
nodo_t * ordine (FILE * fp);
void print(nodo_t *testa) {
    while (testa != NULL) {
        printf("(%s, %s, %d) -> ", testa->nome, testa->cognome, testa->occ);
        testa = testa->nextelem;
    }
    printf("NULL\n");
}


nodo_t *statistica(nodo_t *, int *);

int main(int argc, char *argv[]) {
    if (argc  <0) {
        printf("Usage");
        return -1;
    }

    FILE *fp = fopen("stud.txt", "r");
    if (fp == NULL) {
        printf("Error while opening the file");
        return -1;
    }
    nodo_t * testa = ordine(fp);


    print(testa);
    int numstudenti =0;
    nodo_t * cognome = statistica(testa,&numstudenti);
    printf("%s",cognome->cognome);

    fclose(fp);
    while(testa != NULL){
        nodo_t * last = testa;
        testa = testa->nextelem;
        free(last);
    }

    
}
nodo_t * ordine1 (FILE * fp){
    char nome[MAX];
    char cognome[MAX];
    nodo_t * testa = NULL;
    while(fscanf(fp,"%s",nome) != EOF){
        fscanf(fp,"%s",cognome);
        nodo_t * newnode = (nodo_t *) malloc(sizeof(nodo_t));
        newnode->nextelem=NULL;
        strcpy(newnode->nome,nome);
        strcpy(newnode->cognome,cognome);

        if(testa == NULL){
            testa = newnode;
        }else{

            int flag1 = 0;
            nodo_t * temp = testa;
            nodo_t * last1;
            while(temp!=NULL && flag1==0){
                if(flag1==0 && strcmp(cognome,temp->cognome)==0 && strcmp(nome,temp->nome)==0){
                    flag1=1; //Se i due nomi sono uguali ho il flag ad 1
                    printf("1\n");
                }
                if(flag1==0 && strcmp(cognome,temp->cognome)<0 && temp == testa){
                    flag1=2; //Se 
                     printf("2\n");
                }
                if(flag1==0 && strcmp(cognome,temp->cognome)<0 ){
                    flag1=3; //Se 
                     printf("3\n");
                }
                if(flag1==0 && strcmp(cognome,temp->cognome)==0){
                    flag1=4;
                    printf("4\n");
                }
                last1 = temp;
                temp = temp->nextelem;
            }
            


            if(flag1==1){
                newnode->nextelem=last1->nextelem;
                last1->nextelem=newnode;
            }
            if(flag1==2){
                newnode->nextelem=testa;
                testa=newnode;
            }
            if(flag1==3){
                newnode->nextelem=last1->nextelem;
                last1->nextelem=newnode;
            }
            if(flag1==4){
                printf("Ok");
                int flag2=0;
                nodo_t * temp2 = temp;
                nodo_t * last2;
                while (temp2 != NULL && flag2 == 0) {
                    printf("Ok");
                    if (strcmp(cognome, temp2->cognome) != 0) {
                        flag2 = 1;
                        printf("Porcodio");
                    } else if (flag2 == 0 && strcmp(nome, temp2->nome) <= 0) {
                        flag2 = 2;
                        
                        printf("Porcodio");
                    }
                    last2 = temp2;
                    temp2 = temp2->nextelem;
                }

                if (flag2 == 1) {
                    newnode->nextelem = last2->nextelem;
                    last2->nextelem = newnode;
                } else if (flag2 == 2) {
                    newnode->nextelem = testa;
                    testa = newnode;
                } else {
                    newnode->nextelem = last1->nextelem;
                    last1->nextelem = newnode;
                }
                
            }
            if(flag1==0){
                newnode->nextelem=last1->nextelem;
                last1->nextelem=newnode;
            }


        }



        print(testa);
        puts("");
    }
    return testa;
}
nodo_t * ordine (FILE * fp){

    nodo_t * testa = NULL;
    char nome[MAX];
    char cognome [MAX];

    while(fscanf(fp,"%s %s",nome,cognome)!=EOF){
        nodo_t * newnode = (nodo_t *)malloc(sizeof(nodo_t));
        newnode->nextelem=NULL;
        strcpy(newnode->nome,nome);
        strcpy(newnode->cognome,cognome);


        
        newnode->nextelem=testa;
        testa = newnode;

            
        
    }

    testa = ordinalista(testa);

    return testa;






}

nodo_t * ordinalista(nodo_t * testa){

    int scambia = 1;

    while(scambia){
        scambia = 0;
        nodo_t * temp = testa;
        nodo_t * last = NULL;
        while(temp != NULL && temp-> nextelem != NULL ){
            
            int cmp = strcmp(temp->cognome,temp->nextelem->cognome);
            if(cmp >0 || ( cmp ==0 && strcmp(temp->nome,temp->nextelem->nome)>0)){
                scambia = 1;
                if(temp == testa){
                    
                    testa = temp->nextelem;
                    temp->nextelem=temp->nextelem->nextelem;
                    testa->nextelem=temp;

                }else{

                    swap(last,temp);

                    

                }
            }
            last = temp;
            temp = temp->nextelem;

        }



    }
    return testa;

}

void swap (nodo_t * prec, nodo_t * nodo){
    
    nodo_t * nodo2 = nodo->nextelem;
    nodo_t * hold = nodo2->nextelem;

    prec->nextelem=nodo2;
    nodo2->nextelem = nodo;
    nodo->nextelem=hold;
    


}

nodo_t * statistica(nodo_t * testa,int * studenti){

    nodo_t * temp = testa;
    int max=0;
    nodo_t * cognomefreq;
    while ( temp != NULL){
        (*studenti)++;

        nodo_t * temp2 = testa;
        
        int counter =0;
        while(temp2!=NULL){
           int  cmp = strcmp(temp->cognome,temp2->cognome);
           if(cmp==0){
            counter++;
           }
           temp2=temp2->nextelem;

        }
        if(counter>max){
            cognomefreq->occ=counter;
            cognomefreq=temp;
        }


        temp = temp->nextelem;

    }

    if(max==1){
        testa->occ=1;
        return testa;
    }else{
        return cognomefreq;
    }





}