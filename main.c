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
    char *stop=strdup("stop");
    getchar(); //pour faire une pause et pouvoir executer menuPenduTypePartie
    while (Jouer !=2)
    {
        typePartie=menuPenduTypePartie();
        if (typePartie=='N' || typePartie=='n')
            ///Nouvelle partie
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
            getchar();
            int s=menuPenduSauvergarder();
            printf("%s %s %d\n",mot,avance,compteurErreurs);
            if (s==0)
            {
                GAME*partie=creerPartie("",mot,avance,compteurErreurs,1.22,2.33,3.44,diff);
                SaveGame(partie);
            }
        }

        if (typePartie=='R' || typePartie=='r' )
        {
            ///continuer une partie
            char PlayerName [40];
            char *mot = malloc(sizeof(char)*30);
            char *avance=malloc(sizeof(char)*30);
            int *erreurs=malloc(sizeof(int)); // sert à afficher le pendu en fonction du nombre d'erreurs réalisées
            float *debutPartie=malloc(sizeof(float)); // recupere temps debut et fin de partie pour stat de temps eventuellement le temps passe dessus ATTENTON penser a importer bibliotheque de temps
            float *finPartie=malloc(sizeof(float));
            float *TempsTotalPartieEnSec=malloc(sizeof(float));
            int* diff=malloc(sizeof(int));
            ResumeGame(PlayerName,mot,avance,erreurs,debutPartie,finPartie,TempsTotalPartieEnSec,diff);
            int trys;
            if(*diff==1) trys=10;
            if(*diff==2) trys=10;
            if(*diff==3) trys=15;
            printf("%d %s %s\n",compteurErreurs,mot,avance);
            while ((compteurErreurs<trys) && (Jouer!=2))
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
                    printf ("il reste %d tentatives\n", trys-compteurErreurs-1);
                    printf("%s\n\n",avance);
                }
                if (res==1) ///mauvaise lettre
                {
                    afficherPendu(compteurErreurs);
                    printf("Mauvaise proposition\n");
                    printf ("il reste %d tentatives\n\n", trys-compteurErreurs-1);
                    printf("%s\n\n",avance);
                }
                compteurErreurs++;
            }
        }
        if (typePartie=='Q' || typePartie=='q')
        {
            Jouer=2;
        }
    getchar();
    }

    return 0;
}
