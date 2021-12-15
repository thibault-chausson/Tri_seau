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

seau ajout_queue (seau s, char a[NbChiffre]);

void afficher (seau s);

BOOL est_vide (seau s);

int taille(seau s);

seau ajoute_manquant(seau s);

void tri_seau(seau s, int B, seau T[]);

int correspondence (char a);

#endif //TESTE_FONCTION_H
