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
// il faudra set ces donn�es en fonction du type de partie (nouveau ou ancien) pour cr�er une partie, il faut qu'elles soient ext�rieures � la fonction ou que la fonction de cr�ation soit initi�e au debut pour prendre les infos d�s le debut



int ResumeGame() //Afficher les diff�rentes parties pour les reprendre
{
    FILE * fichier=NULL; //on cree un pointeur
    fichier=fopen("save.txt","r"); // on indique le chemin
    rewind(fichier);                //cursuer au debut
    char temp[100]={0};
    int ID=0;             //on cree de la memoire
    while(fgets(temp,100,fichier))
    {
        printf("Partie: %s",temp);
    }
    fclose(fichier);

    printf("quel est le nmero de la partie que vous voulez rejouer? :");
    int a;
    scanf("%d",&a);

    return a;
}

//permet de visualiser les diff�rentes parties et de choisir laquelle on reprend

//trouver comment �crire dans un fichier et aller rechercher dedans et passer du fichier � la stucture et inversement pour le bon traitement
//+chercher comment on peut cr�er une nouvelle partie ou supprimmer des parties etc

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


























