#include "SauvegardePendu.h"

GAME *creerPartie (char PlayerName [40],char motatrouver [30],char lettersFounded [30],int erreurs,float debutPartie,float finPartie,float TempsTotalPartieEnSec,int diff)
{
    GAME * test=malloc(sizeof(GAME));
    test->debutPartie=debutPartie;//tmier
    test->erreurs=erreurs;
    test->finPartie=finPartie;// timer
    strcpy(test->lettersFounded,lettersFounded);
    strcpy(test->motatrouver,motatrouver);
    strcpy(test->PlayerName,PlayerName);
    test->TempsTotalPartieEnSec=TempsTotalPartieEnSec; //timer
    return test;

}
// il faudra set ces données en fonction du type de partie (nouveau ou ancien) pour créer une partie, il faut qu'elles soient extérieures à la fonction ou que la fonction de création soit initiée au debut pour prendre les infos dès le debut



void ResumeGame(char *PlayerName,char *motatrouver,char *lettersFounded,int *erreurs,float *debutPartie,float *finPartie,float *TempsTotalPartieEnSec,int *diff)
{
    char *Nom=malloc(sizeof(char)*20);
    printf("Entrez votre nom\n");
    scanf("%s",Nom);
    int ex=fexists(Nom);
    while (ex==1)
    {
        printf("%s ------\n",Nom);
        printf("Partie inexistante, veillez reessayer\n");
        scanf("%s",Nom);
        ex=fexists(Nom);
    }
    FILE* fichier =NULL;
    fichier=fopen(Nom,"r");
    rewind(fichier);
    fscanf(fichier,"%s ",PlayerName);
    fscanf(fichier,"%s ",motatrouver);
    fscanf(fichier,"%s ",lettersFounded);
    fscanf(fichier,"%d ",erreurs);
    fscanf(fichier,"%f ",debutPartie);
    fscanf(fichier,"%f ",finPartie);
    fscanf(fichier,"%f ",TempsTotalPartieEnSec);
    fscanf(fichier,"%d ",diff);

}


void SaveGame(GAME * partie)
{
    FILE * save=NULL;
    char  *Nom=malloc(sizeof(char)*50);
    printf("Entrez votre nom\n");
    scanf("%s",Nom);
    int ex=fexists(Nom);
    printf("%d\n",ex);
    {
        printf("Nom pris, veillez changer\n\n");
        printf("Entrez votre nom\n");
        scanf("%s",Nom);
        ex=fexists(Nom);
    }
    save=fopen(Nom,"w");
    rewind(save);
    fprintf(save,"%s %s %s %d %f %f %f %d",partie->PlayerName, partie->motatrouver,partie->lettersFounded, partie->erreurs, partie->debutPartie,partie->finPartie, partie->TempsTotalPartieEnSec,partie->diff);
    fclose(save);
}
int fexists(char * fichier)
{
    FILE* f=NULL;
    f=fopen(fichier,"r");
    if (f==NULL)
    {
        fclose(f);
        return 1;
    }
    else
    {
        fclose(f);
        return 0;
    }
}

























