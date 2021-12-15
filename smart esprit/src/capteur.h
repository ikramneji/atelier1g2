#include <gtk/gtk.h>

int ea;
int ra ;
int rm;
int em ;
int b;
int a ;

enum { EREFF,
       EMARQUE,
	ETYPES,
	EVALEURS,
	EVALEURMIN,
	EVALEURMAX,
	EPLACE,
	EETAGE,
	EJOURS,
	EMOIS,
	EANNES,
	COLUMN };

typedef struct {
int jour ;
char mois[20] ;
int annees;
}date2 ;
typedef struct {
char place[40] ;
char bloc[4] ;
int etage;
}emp ;

typedef struct {

  char reference[50]  ;
char marque[50] ;
  char type[50];
  emp emplacement;
  date2 date_ajout ;
  date2 date_modif ;
  char valeur[50] ;
  char valeur_min[50] ;
  char valeur_max[50] ;
}capteur;


void vider(GtkWidget *liste);
void AjouterCapteur(capteur c);
void ModifierCapteur();
void SuppCapteur(capteur c);
void suppancien(char reference[50]);
void rechercheraffiche(char ref[50],char reference[50],char marque[50],char valeur[50],char valeur_min[50],char valeur_max[50],char type[50]);
int exist(char reference[50],capteur c);
int existm(char reference[50]);
void Afficher(GtkWidget *liste,char file[50]) ;
//void afficher_capteur(GtkWidget *liste,char file[50]);
//void affiche_capteurch(GtkWidget *liste);
void chercher_capteur(char ref[50]);
//void affiche_historique(GtkWidget *liste, char j [50],char m[50],char a[50]);
///////////////les pane et alarme et capteur defectueux///////////////
typedef struct{
int valeur ;
float val ;
}val ;
typedef struct{
int jour ;
int heure ;
int numcapteur;
val valeurs ;
char emp[50] ;
char type[50];
}pr;
typedef struct{
pr fume ;
pr mvt ;
pr temp;
pr debit ;
}choix;
void affiche_alarm(GtkWidget *liste);
void affiche_defect(GtkWidget *liste);
void affiche_panne(GtkWidget *liste);
//int mail();


