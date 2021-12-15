#include "structure.h"
#include "fonction.h"

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
    char continu='o';

    printf("Dans quelle base travaille-t-on (entre 1 et 16) ? \n");
    scanf("%d", &B);

    while(B>16 || B<1)/*Si la base saisie par l'utilisateur est incorrecte*/{
        printf("Dans quelle base travaille-t-on (entre 1 et 16) ? \n");
        scanf("%d", &B);
    }

    while (continu=='o'){
        printf("Quelle est la valeur ? \n");
        scanf("%s", nb);
        longueur= strlen(nb);
        while( base && lo<longueur) /*On vérifie que le nombre donné par l'utilisateur est dans la bonne base et qu'il ne depasse pas les 10 caratères*/{
            if (correspondence(nb[lo])>B-1)/*Si un des caratère n'est pas un caractère conforme à la base*/{
                base=FALSE;
            }
            lo=lo+1;
        }
        if (base) /*S'il répond à toutes les conditions on l'ajoute dans le liste des nombres à trier*/ {
            Tab_aux = ajout_queue(Tab_aux, nb);
            printf("Avez-vous d'autre nombre à trier ? (o/n)\n");
            scanf("%s",&continu);
        }
        else /*On informe l'utilisateur que le nombre saisie ne convient pas*/ {
            base=TRUE;
            printf("Le nombre saisie n'est pas de la bonne base !! \n");
            printf("Avez-vous d'autre nombre à trier ? (o/n)\n");
            scanf("%s",&continu);
        }
    }

    Tab_aux=ajoute_manquant(Tab_aux); /*On crée un seau ou tous les nombres on le même nombre de caractères*/

    seau p[B];
    int i;
    tri_seau(Tab_aux,B, p); /*On tri le seau*/

    for ( i = 0; i < B; i++ ) /*On affiche les nombres triés*/ {
        afficher (p[i] );
    }
    return 0;
}