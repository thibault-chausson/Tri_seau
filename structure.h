//
// Created by Thibault on 01/11/2021.
//

#ifndef TEST_STRUCTURE_H
#define TEST_STRUCTURE_H

//Quantité de chiffres maximale  par nombre
#define NbChiffre 11 //Ici 11 car, il met un "\0" à la fin

#define TRUE 1
#define FALSE 0

typedef int BOOL;

//Déclaration de la structure seau

typedef struct elem {
    char nombre[NbChiffre];
    struct elem *suivant;} element;

typedef element *seau;

#endif //TEST_STRUCTURE_H
