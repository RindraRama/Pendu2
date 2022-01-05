#include "SauvegardePendu.h"

GAME *creerPartie (char PlayerName [40],char motatrouver [30],char lettersFounded [30],int erreurs,float debutPartie,float finPartie,float TempsTotalPartieEnSec)
{
    GAME * test=malloc(sizeof(GAME));
    test->debutPartie=debutPartie;//tmier
    test->erreurs=erreurs;
    test->finPartie=finPartie;// timer
    strcpy(test->lettersFounded,lettersFounded);
    strcpy(test->motatrouver,motatrouver);
    strcpy(test->PlayerName,PlayerName);
    test->TempsTotalPartieEnSec=TempsTotalPartieEnSec; //timer
    test->ID=FindID(test);
    return test;

}
// il faudra set ces données en fonction du type de partie (nouveau ou ancien) pour créer une partie, il faut qu'elles soient extérieures à la fonction ou que la fonction de création soit initiée au debut pour prendre les infos dès le debut



void ResumeGame()
{
    FILE * fichier=NULL;
    fichier=fopen("save.txt","r");
    rewind(fichier);
    char temp[100]={0};
    while(fgets(temp,100,fichier))
    {

    }
}

//permet de visualiser les différentes parties et de choisir laquelle on reprend

//trouver comment écrire dans un fichier et aller rechercher dedans et passer du fichier à la stucture et inversement pour le bon traitement
//+chercher comment on peut créer une nouvelle partie ou supprimmer des parties etc

void SaveGame(GAME * partie)
{
    FILE * save=NULL;
    save=fopen("save.txt","r+");
    rewind(save);
    char a[100]={0};
    for(int i=0;i<partie->ID;i++)
    {
        fgets(a,100,save);
    }
    fprintf(save,"\n");
    fprintf(save,"%i %s %s %s %d %f %f %f\n",partie->ID, partie->PlayerName, partie->motatrouver,partie->lettersFounded, partie->erreurs, partie->debutPartie,partie->finPartie, partie->TempsTotalPartieEnSec);
    fclose(save);

}

int FindID(GAME * game)
{
    FILE * fichier=NULL;
    fichier=fopen("save.txt","r");
    rewind(fichier);
    int ID;
    int idp='1';
    char temp[100]={0};
    while(fgets(temp,100,fichier))
    {
        ID=temp[0];
        if(ID!=idp)
        {
            break;
        }
        idp++;
    }
    fclose(fichier);
    return idp-'0';
}


























