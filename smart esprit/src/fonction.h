#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include "fonction.h"






typedef struct
{
    int jour;
    int mois;
    int annee;
 char nom[20];
char prenom[20];
char Cin[20];
char Email[20];
char Modps[20];

char Role[20];
char sexe[20];

   
}holybody;

typedef struct
{
    char jour[20];
    char mois[20];
    char annee[20];
 char nom[20];
char prenom[20];
char Cin[20];
char Email[20];
char Modps[20];
char Role[20];
char sexe[20];

   
}userty;


void ajouter_1(holybody r);
void ajouter_2(char e[20]);
void affich(GtkWidget *liste);
void chercher(char n[20] ,char p[20],GtkWidget *liste);
void NiveauEtud(GtkWidget *liste);
void supprimer_reclam(userty p);
void modifier_reclam( userty p ,holybody r);
int Login( char id[20] ,char psw[20]);
int verification(holybody z);

void sendmail(char body[]);

#endif // FONCTION_H_INCLUDED
