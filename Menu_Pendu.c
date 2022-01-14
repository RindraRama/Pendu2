#include "Menu_Pendu.h"
#include "SauvegardePendu.h"
#define JOUER 4
#define LEAVE 2

int menuPenduJouerQuitter ()

{

    char jouer_quitter = 'q';
    printf("\n Voulez vous jouer ou quitter ? ");
    printf("\n----->Si vous desirez jouer, entrez le caractere minuscule: %c",'j');
    printf("\n----->Si vous desirez quitter, entrez le caractere minuscule: %c\n",'q');
    scanf("%c", &jouer_quitter);

    if (jouer_quitter != 'j' && jouer_quitter != 'q')
    {
        printf("\nCarractere non reconnu, veuillez recommencer ");
        menuPenduJouerQuitter();
    }

    else
    {
        if (jouer_quitter=='j')
        {
            printf("_*_Bonne Partie!!!_*_");
            return 4;
        }

        if (jouer_quitter=='q' )
        {
            printf("\nVous aller quitter la partie en cours\n\n--->Souhaitez vous sauvegarder?");
            return 2;
        }

    }
    return 0;
}

int menuPenduTypePartie ()
{

      char typ;
      //char confirmation;
      printf("\n\nSouhaitez vous jouer une ancienne partie? ou Jouer une nouvelle partie ?");
      printf("\n------> Pour jouer une ancienne partie, tapez R");
      printf("\n------> Pour jouer une nouvelle partie, tapez N");
      printf("\n(-----> Pour quitter le jeu, tapez Q)\n");
      scanf("%c",&typ);
/*
      if (typ == 'R' || typ=='r')
        {
            printf("\n\nChoisissons une ancienne partie, êtes vous d'accord ?");
            printf("\n------> Si vous confirmez votre choix, tapez C");
            scanf("%c",&confirmation);

            while (confirmation != 'C' || confirmation !='c')
                {
                printf("Choix erroné, erreur de frappe, je ne sais pas, veuillez reformuler");
                scanf("%c",&confirmation);
                }
        }
      if (typ == 'N' || typ=='n')
        {
            printf("\n\n Vous confirmez vouloir jouer une nouvelle partie ?");
            printf("\n------> Si vous confirmez votre choix, tapez C");
            scanf("%c",&confirmation);

            while (confirmation != 'C' || confirmation !='c')
                {
                    printf("\nChoix errone, erreur de frappe, je ne sais pas, veuillez reformuler\n");
                    scanf("%c",&confirmation);
                }
        }*/
        return typ;
};

int menuPenduDifficulte ()

{
    int diff;

    printf("Sélectionnez la difficulté 1 facile 2 facile 3 facile :\n");
    scanf("%d", &diff);
    while ((diff!= 2) && (diff !=1) && (diff!=3))
    {
        getc(stdin);
        printf("Erreur survenue, veuillez recommencer\n\n");
        printf("Sélectionnez la difficulté 1 facile 2 facile 3 facile :\n");
        scanf("%d", &diff);
    }

    return diff;
};

int menuPenduSauvergarder()
{
    char Save;
    printf("\n\n SI vous souhaitez sauvergarder entrez s \n");
    scanf("%c", &Save);
    if (Save == 's' )
    {
        return 0;
    }
    else
    {
        printf("Aurevoir!!!");
        return 1;
    }

}



void Selection(char * filename, char * motatrouver)
    {
    srand ( time(NULL) );
    FILE * fichier=NULL;
    int temp;
    fichier=fopen(filename,"r");
    int n=rand()%10000;
    int i=0;
        while(i<n)
    {
        temp=fscanf(fichier,"%s ",motatrouver);
        if (temp== EOF) rewind(fichier);
        i++;
    }
    fclose(fichier);
}
