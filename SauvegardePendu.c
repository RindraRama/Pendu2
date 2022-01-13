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
    return test;

}
// il faudra set ces données en fonction du type de partie (nouveau ou ancien) pour créer une partie, il faut qu'elles soient extérieures à la fonction ou que la fonction de création soit initiée au debut pour prendre les infos dès le debut



void ResumeGame()
{
    char Nom;
    printf("Entrez votre nom\n");
    scanf("%s",&Nom);

    int ex=fexists(&Nom);
    while (ex==1)
    {
        printf("%s ------\n",&Nom);
        printf("Partie inexistante, veillez reessayer\n");
        scanf("%s",&Nom);
        ex=fexists(&Nom);
    }

    FILE* fichier =NULL;
    char *PlayerName;
    /*char motatrouver;
    char lettersFounded;
    int erreurs;
    float debutPartie;
    float finPartie;
    float TempsTotalPartieEnSec;*/
    fichier=fopen(&Nom,"r");
    rewind(fichier);
    char temp[100];
    while (fscanf(fichier,"%[^\n]",temp)!=EOF)
    {
        fscanf(fichier,"%[^\n]",&PlayerName);
        printf("az\n");
        printf("%s\n",PlayerName);
    }
}


void SaveGame(GAME * partie)
{
    FILE * save=NULL;
    char  Nom;
    printf("Entrez votre nom\n");
    scanf("%s",&Nom);
    int ex=fexists(&Nom);
    printf("%d\n",ex);
    while (ex==0)
    {
        printf("Nom pris, veillez changer\n\n");
        printf("Entrez votre nom\n");
        scanf("%s",&Nom);
        ex=fexists(&Nom);
    }

    save=fopen(&Nom,"w");
    rewind(save);
    fprintf(save,"%s %s %s %d %f %f %f",partie->PlayerName, partie->motatrouver,partie->lettersFounded, partie->erreurs, partie->debutPartie,partie->finPartie, partie->TempsTotalPartieEnSec);
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
/*
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
*/

























