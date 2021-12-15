//
// Created by Thibault on 01/11/2021.
//

#ifndef TESTE_FONCTION_H
#define TESTE_FONCTION_H
#include<stdio.h>
#include <string.h>
#include "structure.h"

#include<stdio.h>
#include <string.h>
#include "structure.h"

#include<stdio.h>
#include <string.h>
#include "structure.h"

BOOL est_vide (seau s);

seau ajout_queue (seau s, char a[NbChiffre]);

int taille(seau s);

seau ajoute_manquant(seau s);

int correspondence (char a);

void tri_seau(seau s, int B, seau T[]);

void afficher (seau s);

#endif //TESTE_FONCTION_H
