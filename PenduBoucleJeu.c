#include "PenduBoucleJeu.h"




int TestLettre(char * mot, char prop)
/// Tester si une lettre est dans le mot
{
    int i = 0;
    while (mot[i] != '\0')
    /// teste toutes les lettre du mot si la proposition est dans le mot arrete la fonction et renvoie TRUE
    {
        if (mot[i]== prop)
        {
            return 0;
        }
        i++;
    }
    return 1;
    ///la proposition n'est pas dans le mot, renvoie FALSE
}
char * replacerlettre(char * mot , char * progress, char a)
///place la lettre trouvée a sa place
{
    int i =0;
    while(mot[i] != '\0')
    {
        if (mot[i]==a)
            progress[i]=a;
        i++;
    }
    return progress;
}







