//
// Created by Thibault on 31/10/2021.
//

#include "fonction.h"
#include "structure.h"
#include <stdlib.h>

seau ajout_queue (seau s, char a[NbChiffre]){
    seau nouveau_element;
    seau t;
    nouveau_element=(element *) malloc(sizeof(element));
    snprintf(nouveau_element->nombre, sizeof a, "%s", a);
    nouveau_element->suivant=NULL;
    if(s == NULL) {
        s=nouveau_element;
    }
    else {
        t = s;
        while (t->suivant !=NULL) {
            t=t->suivant;
        }
        t->suivant=nouveau_element;
    }
    return (s);
}

seau ajout_tete (seau s, char e[NbChiffre]) {
    seau new_element;
    new_element=(element *) malloc(sizeof(element));
    snprintf(new_element->nombre, sizeof e, "%s", e);
    new_element->suivant=s;
    return new_element;
}

BOOL est_vide(seau s){
    if (s==NULL) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

void afficher (seau s) {
    if (est_vide(s)==TRUE){
        printf("Est vide seau\n");
    }
    else {
        seau p = s;
        printf("[ ");
        while (p->suivant != NULL) {
            printf("%s\t; ", p->nombre);
            p = p->suivant;
        }
        printf(" %s ]\n", p->nombre);
    }
}

int taille (seau s){
    int t=0;
    if (est_vide(s)==TRUE){
        t=0;
    }
    else {
        seau p = s;
        while (p->suivant != NULL) {
            if (strlen(p->nombre) > t)  {
                t=strlen(p->nombre);
            }
            p = p->suivant;
        }
        if (strlen(p->nombre) > t)  {
            t=strlen(p->nombre);
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
        while (p->suivant != NULL) {
            tBis=strlen(p->nombre);
            if (tBis!=t){
                for (k=0;k<(t-tBis);k++){
                    char aux[NbChiffre]="0";
                    strcat(aux,p->nombre);
                    snprintf(p->nombre, sizeof p->nombre, "%s", aux);
                }
            }
            p=p->suivant;
        }
        tBis=strlen(p->nombre);
        if (tBis!=t){
            for (k=0;k<(t-tBis);k++){
                char aux[NbChiffre]="0";
                strcat(aux,p->nombre);
                snprintf(p->nombre, sizeof p->nombre, "%s", aux);
            }
        }
    }
    return(s);
}


int correspondence (char a){
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
    else if (a=='a'){
        b=10;
    }
    else if (a=='b'){
        b=11;
    }
    else if (a=='c'){
        b=12;
    }
    else if (a=='d'){
        b=13;
    }
    else if (a=='e'){
        b=14;
    }
    else if (a=='f'){
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
    for (y=0;y<B;y++){
        T[y]=(element *) malloc(sizeof(element));
        T[y]=NULL;
    }

    if (est_vide(s)==FALSE){
        //Initialisation
        seau p=s;
        while (p->suivant!=NULL){
            i=correspondence((p->nombre)[t-1]);
            T[i]=ajout_queue(T[i],p->nombre);
            p=p->suivant;
        }
        i=correspondence((p->nombre)[t-1]);
        T[i]=ajout_queue(T[i],p->nombre); //Fin initialisation

        //On trie
        for (k=0;k<t-1;k++){
            seau T_aux[B];
            for (y=0;y<B;y++){
                T_aux[y]=(element *) malloc(sizeof(element));
                T_aux[y]=NULL;
            }
            for (j=0;j<B;j++){
                if (est_vide(T[j])==FALSE){
                    seau q=T[j];
                    while (q->suivant!=NULL){
                        i=correspondence((q->nombre)[t-k-2]);
                        T_aux[i]=ajout_queue(T_aux[i],q->nombre);
                        q=q->suivant;
                    }
                    i=correspondence((q->nombre)[t-k-2]);
                    T_aux[i]=ajout_queue(T_aux[i],q->nombre);
                }
            }
            int x;
            for (x=0;x<B;x++){
                T[x]=T_aux[x];
            }
        }
    }
}
