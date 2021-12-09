#include "SauvegardePendu.h"

GAME *creerPartie (char motatrouver [30],char lettersFounded [30],int erreurs,float debutPartie,float finPartie,float TempsTotalPartieEnSec,int nb_erreur)
{
    GAME*partie = malloc(sizeof(GAME)); // on reserve l'espace nécesssaire à l'objet

    printf("\n\nQuel est votre nom ou pseudo, Joueur-Joueuse? :"); //on demande son nom au joueur pour quil retrouve sa partie plus tard
    scanf("%s",partie->PlayerName);




    partie->erreurs=nb_erreur;
    strcpy(partie->motatrouver,motatrouver);
    strcpy(partie->lettersFounded,lettersFounded);
    partie->debutPartie=debutPartie;
    partie->finPartie=finPartie;
    partie->TempsTotalPartieEnSec=TempsTotalPartieEnSec;
    partie->suivant=NULL;
    return partie;

}
// il faudra set ces données en fonction du type de partie (nouveau ou ancien) pour créer une partie, il faut qu'elles soient extérieures à la fonction ou que la fonction de création soit initiée au debut pour prendre les infos dès le debut



int ResumeGame(GAME*liste)
{
    return 0;
}
//permet de visualiser les différentes parties et de choisir laquelle on reprend

//trouver comment écrire dans un fichier et aller rechercher dedans et passer du fichier à la stucture et inversement pour le bon traitement
//+chercher comment on peut créer une nouvelle partie ou supprimmer des parties etc

void SaveGame(GAME * partie)
{
    FILE * save=NULL;
    save=fopen("save.txt","a");
    fprintf(save,"%i %s %s %s %d %f %f %f\n",partie->ID, partie->PlayerName, partie->motatrouver,partie->lettersFounded, partie->erreurs, partie->debutPartie,partie->finPartie, partie->TempsTotalPartieEnSec);
    fclose(save);

}

int FindID(GAME * game)
{
    FILE * fichier=NULL;
    fichier=fopen("save.txt","r");
    rewind(fichier);
    char PlayerName;
    char motatrouver;
    char lettersFounded;
    int erreurs;
    float debutPartie;
    float finPartie;
    float TempsTotalPartieEnSec;
    int ID;
    int idp=0;
    char* temp;
    fscanf(fichier,"%i %s %s %s %d %f %f %f", &ID, &PlayerName,&motatrouver,&lettersFounded,&erreurs,&debutPartie,&finPartie,&TempsTotalPartieEnSec);
    while(idp+1!=ID)
    {
        fgets(temp,100,fichier);
        ID=fgetc(fichier);
        idp++;
    }

    return idp;

}


























