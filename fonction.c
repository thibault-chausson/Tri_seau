//
// Created by Thibault on 31/10/2021.
//

#include "fonction.h"
#include "structure.h"
#include <stdlib.h>

BOOL est_vide(seau s){
    if (s==NULL) /*Si c'est vide nous le mettons à vrai*/ {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

seau ajout_queue (seau s, char a[NbChiffre]){
    seau nouvel_element;
    seau t;
    nouvel_element=(element *) malloc(sizeof(element));
    snprintf(nouvel_element->nombre, sizeof a, "%s", a); /*Nous mettons la chaine de caractère "a" dans la partie nombre du nouvel_element*/
    nouvel_element->suivant=NULL; /*Comme c'est le dernier nous le mettons à NULL*/
    if(s == NULL) {
        s=nouvel_element;
    }
    else {
        t = s;
        while (t->suivant !=NULL) /*Nous allons jusqu'à la fin*/ {
            t=t->suivant;
        }
        t->suivant=nouvel_element; /*Nous le mettons à la fin*/
    }
    return (s);
}


int taille (seau s){
    int t=0;
    if (est_vide(s)==TRUE)/*Si c'est vide la taille est nulle*/{
        t=0;
    }
    else {
        seau p = s;
        while (p != NULL) {
            if (strlen(p->nombre) > t) /*Nous regardons la taille si elle est plus grande nous la mettons dans t*/ {
                t=strlen(p->nombre);
            }
            p = p->suivant;
        }
    }
    return(t);
}

seau ajoute_manquant(seau s){
    int t=taille(s);
    int k;
    int tBis;

    if (est_vide(s)!=TRUE){
        seau p = s;
        while (p!= NULL) {
            tBis=strlen(p->nombre);
            if (tBis!=t) /*Si nous ne sommes pas à la taille maximale nous ajoutons des 0*/ {
                for (k=0;k<(t-tBis);k++)/*Nous ajoutons le bon nombre de 0*/{
                    char aux[NbChiffre]="0";
                    strcat(aux,p->nombre);
                    snprintf(p->nombre, sizeof p->nombre, "%s", aux);
                }
            }
            p=p->suivant;
        }
    }
    return(s);
}


int correspondence (char a)/*Nous faisons correspondre un caractère à un nombre de 0 à 15*/{
    int b;
    if (a=='0'){
        b=0;
    }
    else if (a=='1'){
        b=1;
    }
    else if (a=='2'){
        b=2;
    }
    else if (a=='3'){
        b=3;
    }
    else if (a=='4'){
        b=4;
    }
    else if (a=='5'){
        b=5;
    }
    else if (a=='6'){
        b=6;
    }
    else if (a=='7'){
        b=7;
    }
    else if (a=='8'){
        b=8;
    }
    else if (a=='9'){
        b=9;
    }
    else if (a=='a' || a=='A'){
        b=10;
    }
    else if (a=='b'|| a=='B'){
        b=11;
    }
    else if (a=='c'|| a=='C'){
        b=12;
    }
    else if (a=='d'|| a=='D'){
        b=13;
    }
    else if (a=='e'|| a=='E'){
        b=14;
    }
    else if (a=='f'|| a=='F'){
        b=15;
    }
    return(b);
}


void tri_seau(seau s, int B, seau T[]){

    int t=taille(s);
    int k;
    int i;
    int j;
    int y;

    //Initialisation
    for (y=0;y<B;y++) /*Nous initialisons le tableau de seau*/{
        T[y]=(element *) malloc(sizeof(element));
        T[y]=NULL;
    }

    if (est_vide(s)==FALSE){
        seau p=s;
        while (p!=NULL)/*Nous ajoutons les éléments du seau à trier dans le tableau*/{
            i=correspondence((p->nombre)[t-1]);/*Nous regardons dans quelle case du tableau nous devons reporter le nombre*/
            T[i]=ajout_queue(T[i],p->nombre);/*Nous reportons le nombre*/
            p=p->suivant;
        }
        
        /*Nous trions de la même manière que l'initialisation, mais en avançant vers les chiffres de gauche*/
        for (k=0;k<t-1;k++){
            seau T_aux[B];
            for (y=0;y<B;y++)/*Initialisation du tableau*/{
                T_aux[y]=(element *) malloc(sizeof(element));
                T_aux[y]=NULL;
            }
            for (j=0;j<B;j++){
                if (est_vide(T[j])==FALSE){
                    seau q=T[j];
                    while (q!=NULL){
                        i=correspondence((q->nombre)[t-k-2]);
                        T_aux[i]=ajout_queue(T_aux[i],q->nombre);
                        q=q->suivant;
                    }
                }
            }
            int x;
            for (x=0;x<B;x++){
                T[x]=T_aux[x];
            }
        }
    }
}

void afficher (seau s) {
    if (est_vide(s)==TRUE){
        printf("Est vide seau\n"); /*Si le seau est vide*/
    }
    else {
        seau p = s;
        printf("[ ");
        while (p->suivant != NULL) /*Nous avançons et nous affichons*/ {
            printf("%s\t; ", p->nombre);
            p = p->suivant;
        }
        printf(" %s ]\n", p->nombre); /*Nous affichons le dernier*/
    }
}