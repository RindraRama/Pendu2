#include <stdio.h>
#include "affichagependu.h"
#include"Menu_Pendu.h"
#include"PenduBoucleJeu.h"
#include <stdlib.h>
#include <time.h>
#include "SauvegardePendu.h"


int main()
{
    // On introduit les constantes qui vont servir dans le reste du jeu (pj
    int Jouer;
    int typePartie;
    int compteurErreurs=0;
    Jouer=menuPenduJouerQuitter();
    int erreurs;
    char *mot=malloc(sizeof(char)*20);
    getchar(); //pour faire une pause et pouvoir executer menuPenduTypePartie
    while (Jouer !=2)
    {
        typePartie=menuPenduTypePartie();
        if (typePartie=='N' || typePartie=='n')
        {
            printf("Nouvelle Partie\n");
            int diff=menuPenduDifficulte();
            if (diff==1)
            {
                printf("Difficulte facile\n");
                erreurs=10;
                Selection("Mot_1.txt",mot);
            }
            if (diff==2)
            {
                printf("Difficulte facile\n");
                erreurs=10;
                Selection("Mot_2.txt",mot);
            }
            if (diff==3)
            {
                printf("Difficulte facile\n");
                erreurs=15;
                Selection("Mot_3.txt",mot);
            }

            printf("%s\n",mot);
            int t = strlen(mot);
            mot[t]='\0';
            char *avance=malloc(sizeof(char)*t); /// alloue une case mémoire à avance
            memset(avance,'_',t);///rempli avance de _
            avance[t]='\0';
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("Le mot est compos%c de %d lettres\n",130,t);
            char *stop=strdup("stop");
            while ((compteurErreurs<erreurs) && (Jouer!=2))
            ///Boucle de test de lettre
            {
                if (strcmp(mot,avance)==0)
                {
                    Jouer=2;
                }
                char prop;
                printf("Proposer une lettre : \n");
                scanf("%s", &prop);
                if (prop == *stop)
                {
                    compteurErreurs--;
                    Jouer=2;
                    ///si on veut arreter le jeu on entre stop
                }
                int res = TestLettre(mot, prop);
                if (res==0) ///bonne lettre
                {
                    avance=replacerlettre(mot,avance,prop);
                    printf("Bonne proposition\n");
                    printf ("il reste %d tentatives\n", erreurs-compteurErreurs-1);
                    printf("%s\n\n",avance);
                }
                if (res==1) ///mauvaise lettre
                {
                    afficherPendu(compteurErreurs);
                    printf("Mauvaise proposition\n");
                    printf ("il reste %d tentatives\n\n", erreurs-compteurErreurs-1);
                    printf("%s\n\n",avance);
                }
                compteurErreurs++;
            }
        }

        if (typePartie=='R' || typePartie=='r' )
        {
            ResumeGame();
            //printf("%s %s %s %d %f %f %f\n",partie->PlayerName, partie->motatrouver,partie->lettersFounded, partie->erreurs, partie->debutPartie,partie->finPartie, partie->TempsTotalPartieEnSec);
        }
        if (typePartie=='Q' || typePartie=='q')
        {
            Jouer=2;
        }
    getchar();
    }
    return 0;
}
