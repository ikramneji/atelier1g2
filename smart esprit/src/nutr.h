#include <gtk/gtk.h>

typedef struct
{
int j;
int m;
int a;
} calander;

typedef struct 
{
char cafe[50];
char viennoiserie[50];
char jus[50];
char date[100];
} pdej;

typedef struct 
{
char dj_entree[50];
char dj_plat_p[50];
char dj_dessert[50];
char date[100];
} dej;

typedef struct 
{
char dn_entree[50];
char dn_plat_p[50];
char dn_dessert[50];
char date[100];
} din;


void ajouter_pdej (char fname[],pdej p);
void ajouter_dej (char fname[],dej dj);
void ajouter_din (char fname[],din dn);

