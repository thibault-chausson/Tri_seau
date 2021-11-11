//
// Created by Thibault on 01/11/2021.
//

#ifndef TESTE_STRUCTURE_H
#define TESTE_STRUCTURE_H

//Nombre de chiffres maximale  par nombre
#define NbChiffre 11 //Ici que 11 car met un "\0" à la fin

#define TRUE 1
#define FALSE 0

typedef int BOOL;

//Déclaration de la structure seau

typedef struct elem {
    char nombre[NbChiffre];
    struct elem *suivant;} element;

typedef element *seau;

#endif //TESTE_STRUCTURE_H
