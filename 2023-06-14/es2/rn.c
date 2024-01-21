#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define MAX 15
#define N 50
typedef struct{
    char name[MAX];
    int s;
    int pu;
    int po;
    float punteggioaggregato;

}hotel_t;

hotel_t * incubo(FILE * fpin);

float voto_hotel(FILE *fpin,hotel_t * hotel);

int main (){

    FILE * fpin;
    fpin = fopen("hotel.txt","r");
    if(fpin == NULL){
        printf("File not found");
        return -1;
    }
    
    hotel_t * temp=incubo(fpin);

    printf("%s : %.1f",temp->name,temp->punteggioaggregato);

    

    










    return 0;
}

float voto_hotel(FILE * fpin,hotel_t * hotel){
    

    fscanf(fpin,"%s",(*hotel).name);
    int hold=0;
    (*hotel).po=0;
    (*hotel).pu=0;
    (*hotel).s=0;
    
    while(fscanf(fpin,"%d",&hold)!= EOF){
        (*hotel).s=hold+(*hotel).s;
        fscanf(fpin,"%d",&hold);
        hotel->pu=hold+hotel->pu;
        fscanf(fpin,"%d",&hold);
        hotel->po=hotel->po+hold;
        
        
        


    }
    //printf("Punteggio po:%f\n",hotel.po/3.0);
    //printf("Punteggio pu:%f\n",hotel.pu/3.0);
    //printf("Punteggio s:%f\n",hotel.s/3.0);
    return (hotel->po/3.0)+(hotel->pu/3.0)+(hotel->s/3.0);


   









}

hotel_t * incubo(FILE * fpin){
    int counter=0;
    float punteggiominimo = __FLT_MAX__;
    hotel_t * hotelminimo;
    hotel_t * arrayhotel = (hotel_t *) malloc(sizeof(hotel_t)*N);
    if(arrayhotel==NULL){

        exit(1);
    }
    char hold [MAX];
    while(fscanf(fpin,"%s",hold)!=EOF){
        
        
        //printf("%s", hold);
        FILE *temp = fopen(hold, "r");
        if (temp == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
        arrayhotel[counter].punteggioaggregato = voto_hotel(temp,&arrayhotel[counter]);
        if(punteggiominimo>arrayhotel[counter].punteggioaggregato){
            punteggiominimo=arrayhotel[counter].punteggioaggregato;
            hotelminimo = &arrayhotel[counter];

        }

        counter++;

    }
    return hotelminimo;

}