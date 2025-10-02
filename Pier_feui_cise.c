#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void choix_du_joueur(int choix) {
    switch (choix) {
    case 1 : printf("Pierre\n");
    break;
    case 2 : printf("Feuille\n");
    break;
    case 3 : printf("Ciseaux\n");
    break;
    }
}

void repeat(int *joueur, int *ordi) {
  while (*joueur == *ordi)
    {
        printf("Votre choix (1-3) : ");
        scanf("%d", joueur);
        *ordi = rand() % 3 + 1;

        printf("Votre choix : ");
        choix_du_joueur(*joueur);
        printf("\n");

        printf("L'ordi a choisi : ");
        choix_du_joueur(*ordi);
        printf("\n");

        if (*joueur == *ordi) {
        printf("Egalite\n");
        } else if ((*joueur == 1 && *ordi == 3) ||
                   (*joueur == 2 && *ordi == 1) ||
               (*joueur == 3 && *ordi == 2)) {
            printf("Vous gagnez\n");
        } else {
            printf("L'ordinateur gagne\n");
        }  
    }
}

int main() {
    int joueur, ordi;

    srand(time(NULL));

    printf("==>  Pierre  -  Feuille  -  Ciseaux  <==\n");
    printf("1. Pierre\n2. Feuille \n3. Ciseaux\n");
    printf("Votre choix : ");
    scanf("%d", &joueur);

    if (joueur == 0) {
        printf("Fermeture du jeu..\n");
        return(1);
    }

    if (joueur > 3) {
        printf("Choix invalide  -  Fermeture du jeu..\n");
        return(1);
    }

    ordi = rand() % 3 + 1;
    

    printf("Votre choix : ");
    choix_du_joueur(joueur);
    printf("\n");

    printf("L'ordi a choisi : ");
    choix_du_joueur(ordi);
    printf("\n");

    if (joueur == ordi) {
        printf("Egalite\n");
        repeat(&joueur, &ordi);
    } else if ((joueur == 1 && ordi == 3) ||
               (joueur == 2 && ordi == 1) ||
               (joueur == 3 && ordi == 2)) {
        printf("Vous gagnez\n");
    } else {
        printf("L'ordinateur gagne\n");
    }
    return(0);           
}