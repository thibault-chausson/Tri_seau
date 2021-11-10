#include "structure.h"
#include "fonction.h"
#include <stdlib.h>

int main(void)
{
    int B;
    char nb[NbChiffre];
    seau Tab_aux=NULL;
    int total;
    int k=0;
    BOOL base=TRUE;
    int longueur;
    int lo=0;

    printf("Dans quelle base travaille-t-on ? \n");
    scanf("%d", &B);

    printf("Combien de nombre a trier ?\n");
    scanf("%d",&total);

    while (k<total){
        printf("Quelle est la valeur ? \n");
        scanf("%s", nb);
        longueur= strlen(nb);
        while( base && lo<longueur){
            if (correspondence(nb[lo])>B-1){
                base=FALSE;
            }
            lo=lo+1;
        }
        if (base) {
            Tab_aux = ajout_tete(Tab_aux, nb);
            k=k+1;
        }
        else {
            base=TRUE;
            printf("Le nombre saisie n'est pas de la bonne base !! \n");
        }
    }

    Tab_aux=ajoute_manquant(Tab_aux);

    seau p[B];
    int i;
    tri_seau(Tab_aux,B, p);

    for ( i = 0; i < B; i++ ) {
        afficher (p[i] );
    }

    return 0;
}