#include "affichagependu.h"

void afficherPendu (int compteur)

{
    if (compteur == 0)
        // rien
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    if (compteur == 1)
        // la barre au sol
        printf("\n\n\n\n\n\n\n\n\n\n\n\n_____________");
    if (compteur == 2)
        // le mat
        printf("\n      _\n      |\n      |\n      |\n      |\n      |\n      |\n      |\n      |\n      |\n      |\n______|______");
    if (compteur == 3)
        // la barre du haut
        printf("\n      _______\n      |     |\n      |\n      |\n      |\n      |\n      |\n      |\n      |\n      |\n      |\n______|______");
    if (compteur == 4)
        // la tete
        printf("\n      _______\n      |     |\n      |     o\n      |\n      |\n      |\n      |\n      |\n      |\n      |\n      |\n______|______");
    if (compteur == 5)
        // le corps
        printf("\n      _______\n      |     |\n      |     o\n      |     |\n      |\n      |\n      |\n      |\n      |\n      |\n      |\n______|______");
    if (compteur == 6)
        // bras gauche
        printf("\n      _______\n      |     |\n      |     o \n      |    /|\n      |\n      |\n      |\n      |\n      |\n      |\n      |\n______|______");
    if (compteur == 7)
        // bras droit
        printf("\n      _______\n      |     |\n      |     o/ \n      |    /|\n      |\n      |\n      |\n      |\n      |\n      |\n      |\n______|______");
    if (compteur == 8)
        // jambe gauche
        printf("\n      _______\n      |     |\n      |     o/ \n      |    /|\n      |    / \n      |\n      |\n      |\n      |\n      |\n      |\n______|______");
    if (compteur == 9)
        {

        // jambe droite
        printf("\n      _______\n      |     |\n      |     o/ \n      |    /|\n      |    /| \n      |\n      |\n      |\n      |\n      |\n      |\n______|______");
        printf("\n\nC'est perdu");
        };
}



