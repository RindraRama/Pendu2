#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct statsgame
    {
        char PlayerName [40];
        char motatrouver [30];
        char lettersFounded [30];
        int erreurs; // sert � afficher le pendu en fonction du nombre d'erreurs r�alis�es
        float debutPartie; // recupere temps debut et fin de partie pour stat de temps eventuellement le temps passe dessus ATTENTON penser a importer bibliotheque de temps
        float finPartie;
        float TempsTotalPartieEnSec;
        int ID;
        struct statsgame*suivant;


    } GAME;



GAME *listeParties ;

GAME *creerPartie (char motatrouver [30],char lettersFounded [30],int erreurs,float debutPartie,float finPartie,float TempsTotalPartieEnSec,int nb_erreur);

//GAME *ajouterAliste(GAME*listeParties,GAME*partie);


int ResumeGame(GAME*listeParties);
//permet de visualiser les diff�rentes parties et de choisir laquelle on reprend

//trouver comment �crire dans un fichier et aller rechercher dedans et passer du fichier � la stucture et inversement pour le bon traitement
//+chercher comment on peut cr�er une nouvelle partie ou supprimmer des parties etc
void SaveGame(GAME * partie);
//pour sauvegarder une parie
int FindID(GAME * game); ///Pour cr�er l'ID d'une nouvelle partie
