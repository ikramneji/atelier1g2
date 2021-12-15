


typedef struct {
char nom[20];
char prenom[20];
char id[20];
char classe [10];
char refch[10];
int payement;
date date_entree;
}eheb;

typedef struct {
char refch[10];
int etat;
}chambre;


void ajouter_heb(eheb e);
void afficher_heb();
void modifier_heb(eheb e);
void supprimer_heb(char id[]);
int chercher_heb(char id[]);
void nombre_heb_par_etage(int t[],int n,char f);
int pourcentage_heb_classe (char classe[],char f);
int nbres(char refch[]);
void affiche_heb(GtkWidget *liste);
void affich(GtkWidget *liste);
