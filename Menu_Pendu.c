#include "Menu_Pendu.h"
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
            menuPenduSauvergarder();
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

    printf("\n Sélectionnez la difficulté 1 facile 2 facile 3 facile :");
    scanf("%d", &diff);

    return diff;
};

int menuPenduSauvergarder()
{
    char Save;
    printf("\n\n SI vous souhaitez sauvergarder entrez s ");
    scanf("%c", &Save);
    if (Save == 's' )
    {
        //on sauvegarde le fichier (à refaire)
        printf("Sauvergarde en cours de developpement");
    }
    else
        printf("Aurevoir!!!");
    return 0;
}


void n_alea(int maxi, int *n)
{
    *n = rand() % maxi + 1;
}

void Selection(char nomfichier[], char motatrouver[40],int Tailleliste)
            {
                int aleatoire;
                char word[MAX_CHAR];
                FILE *fic;
                srand ( time(NULL) );

                fic = fopen(nomfichier,'r');

                n_alea(Tailleliste, &aleatoire);

                //chercher(word, fic, aleatoire);// que fait chercher?
                int n=0;
                while (n < aleatoire)
                {
                    fgets(word,MAX_CHAR,nomfichier);
                }
                printf("%d\n", aleatoire);

                //printf("%s\n", word);
                strcpy(motatrouver,word);

                return 0;
            }
