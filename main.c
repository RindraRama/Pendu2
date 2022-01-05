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
    int compteurErreurs;
    Jouer=menuPenduJouerQuitter();

    getchar(); //pour faire une pause et pouvoir executer menuPenduTypePartie
    while (Jouer !=2)
    {
        typePartie=menuPenduTypePartie();
        if (typePartie=='N' || typePartie=='n')
        {
            printf("Nouvelle Partie\n");
            // je dirais plus tard ce qu'il faut faire mais en gros on active la recherche de mot aléatoire dans le dico et on déroule (PJ) # nouvelle partie
            //enn fonction de la difficulté
            //1) Choix du mot par l'aléatoire et en fonction de la difficulté

            /*
            int difficulty=menuPenduDifficulte ();
            if (difficulty==1)
            {
             //FONCTIONCHOIXMOT( DANS LISTE DES MOTS FACILES)
                nomfichier="listlvl1"
                compteurErreurs=0;
                Tailleliste= ;
            //OU bien on met le compteur d'erreurs plus haut
            }
            if (difficulty==2)
            {
             FONCTIONCHOIXMOT( DANS LISTE DES MOTS MOYENS)
                nomfichier="listlvl2"
                compteurErreurs=2;
                Tailleliste= ;
            }
            if (difficulty==3)
            {
             FONCTIONCHOIXMOT( DANS LISTE DES MOTS DIFFICILES)
                nomfichier="listlvl2"
                compteurErreurs=2;
                Tailleliste= ;
            }
            */
            /*
            //On lance le chrono et on l'enregistre au moins pour les stats de fin de game
            time_t debut=time(NULL);
            //2) On lance la boucle de jeu (proposer une lettre etc) ou de quitter
            //3) Si le joueur quitte on lui propose de sauvegarder (ajouter Sauvegarde à la fin de tout endroit ou on peut quitter)
            //4) si le joueur gagne ou perd on lui propose pas de sauvegarder mais a voir si je dois refaire une liste des parties jouees pour faire des meilleures stats
            //4) et on lui montre son temps, eventuellement le pourcentage de lettres trouvees
            */


            char *mot=strdup("hola"); /// changer plus trad par une fonction qui prend un mot random
            int t = strlen(mot);
            char *avance=malloc(sizeof(char)*t); /// alloue une case mémoire à avance
            memset(avance,'_',t);///rempli avance de _
            avance[t]='\0';
            printf("Le mot est compos%c de %d lettres\n",130,t);
            compteurErreurs = 0;
            char *stop=strdup("stop");

            while (compteurErreurs<10)
            ///Boucle de test de lettre
            ///la condition du while doit etre a déterminer
            {
                if (strcmp(mot,avance)==0)
                {
                    Jouer=2;
                    break;
                }
                char prop;
                printf("Proposer une lettre : \n");
                scanf("%s", &prop);

                if (prop == *stop)
                {
                    Jouer=2;
                    break;
                    ///si on veut arreter le jeu on entre quitter
                }
                int res = TestLettre(mot, prop);
                if (res==0)
                {
                    avance=replacerlettre(mot,avance,prop);
                    printf ("il reste %d tentatives\n", 10-compteurErreurs-1);
                    printf("%s\n",avance);
                    }
                if (res==1)
                {
                    afficherPendu(compteurErreurs);
                    printf ("il reste %d tentatives\n", 10-compteurErreurs-1);
                }
                compteurErreurs++;
            }
        }

        if (typePartie=='R' || typePartie=='r' )
        {
            //On affiche les anciennes parties avec leurs stats -> Affichage à modifier et on joue si le joeur a choisi la partie qu'il veut rejouer (PJ)/
            //1) On set le mot à trouver, le temps de à zero et à la fin on l'ajoute au temps total ecoulé, etc (rajoutez si vous pensez à des trucsque j'ai oublié), le compteur, le mot et les lettres trouvées -> faut faire une liste des lettres trouvees pour la reconstruction de la partie en cours d'ailleus
                //time_t debut=time(NULL);
                //printf("Vous avez deja passe %d min sur ce mot",TempsTotal)
            //2) etapes 3 et 4 d'au dessus avec recalcul du temps
                //TempsTotal+=difftime(debut,fin)
        }
        //ajouter la selection du mot
        //la variable du mot va se nommer "mot"
        if (typePartie=='Q' || typePartie=='q')
        {
            Jouer=2;
        }
    getchar();
    }

    Selection();
    return 0;
}
