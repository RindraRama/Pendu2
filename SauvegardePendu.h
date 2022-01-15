#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct statsgame
    {
        char PlayerName [40];
        char motatrouver [30];
        char lettersFounded [30];
        int erreurs; // sert à afficher le pendu en fonction du nombre d'erreurs réalisées
        long debutPartie; // recupere temps debut et fin de partie pour stat de temps eventuellement le temps passe dessus ATTENTON penser a importer bibliotheque de temps
        long finPartie;
        double TempsTotalPartieEnSec;
        int diff;
    } GAME;

int fexists(char * fichier);
GAME *creerPartie (char PlayerName [40],char motatrouver [30],char lettersFounded [30],int erreurs,long debutPartie,long finPartie,double TempsTotalPartieEnSec,int diff);
void ResumeGame(char *PlayerName,char *motatrouver,char *lettersFounded,int *erreurs,long *debutPartie,long *finPartie,double *TempsTotalPartieEnSec,int *diff);
void SaveGame(GAME * partie);
void SaveGame2(GAME * partie);
