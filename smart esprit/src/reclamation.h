#include <gtk/gtk.h>

typedef struct{
	char cin[30];
	char nom[20];
	char prenom[20];
	char text[20];
	date d;
	int etat;
}reclamation;

void ajouter_reclamation(reclamation r);
void modifier_reclamation(reclamation r,char file[20]);
void supprimer_reclamation(char cin[30],char file[20]);
int cinexiste(char cin[30],char file[20]);
void recherche_reclamation(char cin[30],char file[20]);
void afficher_reclamation(GtkWidget *liste,char file[20]);
int service_le_plus_reclame();
