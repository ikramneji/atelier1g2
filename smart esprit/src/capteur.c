#include <stdio.h>
#include <stdlib.h>
#include "capteur.h"
#include <gtk/gtk.h>
#include <string.h>
#include <sys/wait.h>
#define MAX 256
 

///////////////////Ajouter////////////////////////////////////////////////////////////
void AjouterCapteur(capteur c)
{   
    FILE *F ;

    F=fopen("capteurs.txt","a+");
fprintf(F,"%s %s %s %s %s %s %s %d %d %s %d\n"
,c.reference,c.marque,c.type,c.valeur,c.valeur_min,c.valeur_max,c.emplacement.place,c.emplacement.etage,c.date_ajout.jour,c.date_ajout.mois,c.date_ajout.annees);

fclose(F);

}
//////////////////////rechercheaffichelibich n3abi beha les case////////
void rechercheraffiche(char ref[],char reference[],char marque[],char valeur[],char valeur_min[],char valeur_max[],char type[]){
 capteur c ;
FILE *f;
    f=fopen("capteurs.txt", "r");
    
    while(fscanf(f,"%s %s %s %s %s %s %s %d %d %s %d\n"
,c.reference,c.marque,c.type,c.valeur,c.valeur_min,c.valeur_max,c.emplacement.place,&c.emplacement.etage,&c.date_ajout.jour,c.date_ajout.mois,&c.date_ajout.annees)!=EOF) 
{
        if(strcmp(c.reference,ref)==0) { strcpy(reference,c.reference);
					 strcpy(marque,c.marque);
					strcpy(valeur,c.valeur);
					strcpy(valeur_min,c.valeur_min);
					strcpy(valeur_max,c.valeur_max);
					strcpy(type,c.type);

					break;

}



}
fclose(f);
}
///////////////////////////vider//////////////////////////////////////////////
void vider(GtkWidget *liste){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
store=NULL ;
FILE *F ;


store=gtk_tree_view_get_model(liste);
if (store==NULL) {
       renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("reference",renderer,"text",EREFF,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("marque",renderer,"text",EMARQUE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPES,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",EVALEURS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("valeur_min",renderer,"text",EVALEURMIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("valeur_max",renderer,"text",EVALEURMAX,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("place",renderer,"text",EPLACE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etage",renderer,"text",EETAGE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOURS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annees",renderer,"text",EANNES,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}
store=gtk_list_store_new(COLUMN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT);

gtk_list_store_append(store,&iter);
	 
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
//g_object_unref(store);
}





//////////////////////afficherbord/////////////////////////////////////////////////



void Afficher(GtkWidget *liste,char file[50]){

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
store=NULL ;
FILE *F ;

char reference[50];
char marque [50];
char type[50];
char valeur[50] ;
char valeur_min[50] ;
char valeur_max[50] ;
char place [50];
int etage;
int jour;
char mois[50];
int annees;


store=gtk_tree_view_get_model(liste);
if (store==NULL) {
       renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("reference",renderer,"text",EREFF,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("marque",renderer,"text",EMARQUE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPES,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",EVALEURS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("valeur_min",renderer,"text",EVALEURMIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("valeur_max",renderer,"text",EVALEURMAX,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("place",renderer,"text",EPLACE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etage",renderer,"text",EETAGE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOURS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annees",renderer,"text",EANNES,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}
store=gtk_list_store_new(COLUMN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT);
F=fopen(file,"r");
if (F==NULL){ return ;}
else { 
while (fscanf(F,"%s %s %s %s %s %s %s %d %d %s %d\n",reference,marque,type,valeur,valeur_min,valeur_max,place,&etage,&jour,mois,&annees)!=EOF)
{
gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,EREFF,reference,EMARQUE,marque,ETYPES,type,EVALEURS,valeur,EVALEURMIN,valeur_min,EVALEURMAX,valeur_max,EPLACE,place,EETAGE,etage,EJOURS,jour,EMOIS,mois,EANNES,annees, -1);
} fclose(F); 
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
//////////////////////supp///////////////////////////////////////

void SuppCapteur(capteur c)
{   char reference[50];
char marque [50];
char type[50];
char valeur[50] ;
char valeur_min[50] ;
char valeur_max[50] ;
char place [50];
int etage;
int jour;
char mois[50];
int annees;

        FILE*Fich=NULL ;
	FILE*F=NULL ;

    F=fopen("capteurs.txt","r");
    Fich=fopen("reservecapteur.txt","w");
    if (F==NULL || Fich==NULL) { return ;}
    else{    while(fscanf(F,"%s %s %s %s %s %s %s %d %d %s %d\n"
,reference,marque,type,valeur,valeur_min,valeur_max,place,&etage,&jour,mois,&annees)!=EOF){
       if (strcmp(c.reference,reference)!=0||strcmp(c.type,type)!=0||strcmp(c.valeur,valeur)!=0||strcmp(c.valeur_min,valeur_min)!=0||strcmp(c.valeur_max,valeur_max)!=0||strcmp(c.emplacement.place,place)!=0||(c.emplacement.etage!=etage)||(c.date_ajout.jour!=jour)||strcmp(c.date_ajout.mois,mois)!=0||(c.date_ajout.annees!=annees))
fprintf(Fich,"%s %s %s %s %s %s %s %d %d %s %d\n"
,reference,marque,type,valeur,valeur_min,valeur_max,place,etage,jour,mois,annees);}
    fclose(Fich);
    fclose(F);
    remove("capteurs.txt");
    rename("reservecapteur.txt","capteurs.txt");
}
}
//////////////////////fonction exist///////////////////////////////////////////////////
int exist(char reference[50],capteur c)
{
    FILE *F ;

    F=fopen("capteurs.txt","r");
  while(fscanf(F,"%s %s %s %s %s %s %s %d %d %s %d\n",c.reference,c.marque,c.type,c.valeur,c.valeur_min,c.valeur_max,c.emplacement.place,&c.emplacement.etage,&c.date_ajout.jour,c.date_ajout.mois,&c.date_ajout.annees)!=EOF){
if(strcmp(reference,c.reference)==0)return 1; 
}
fclose(F);
return 0;
}
//////////////////suppwahdaokhramte3lmodif//////////////////////////////////////////////
void suppancien(char reference[50]){
         FILE*f=NULL;
	FILE*f1=NULL;
	capteur c;
	f=fopen("capteurs.txt","r");
	f1=fopen("ancien.txt","w+");
	while(fscanf(f,"%s %s %s %s %s %s %s %d %d %s %d\n",c.reference,c.marque,c.type,c.valeur,c.valeur_min,c.valeur_max,c.emplacement.place,&c.emplacement.etage,&c.date_ajout.jour,c.date_ajout.mois,&c.date_ajout.annees)!=EOF){
	if(strcmp(reference,c.reference)!=0)
	fprintf(f1,"%s %s %s %s %s %s %s %d %d %s %d\n"
,c.reference,c.marque,c.type,c.valeur,c.valeur_min,c.valeur_max,c.emplacement.place,c.emplacement.etage,c.date_ajout.jour,c.date_ajout.mois,c.date_ajout.annees);

	}
	fclose(f);
	fclose(f1);
	remove("capteurs.txt");
	rename("ancien.txt","capteurs.txt");


}


//////////////////////existemte3modif///////////////////////////////////////////////////
int existm(char ref[50])
{
 
capteur c ;  

FILE *F ;

    F=fopen("capteurs.txt","r");
  while(fscanf(F,"%s %s %s %s %s %s %s %d %d %s %d\n",c.reference,c.marque,c.type,c.valeur,c.valeur_min,c.valeur_max,c.emplacement.place,&c.emplacement.etage,&c.date_ajout.jour,c.date_ajout.mois,&c.date_ajout.annees)!=EOF){
if(strcmp(c.reference,ref)==0||strcmp(c.type,ref)==0)return 1; 
}
fclose(F);
return 0;
}


/////////////////////////////Liste des alarmes//////////////////////////////////////////
enum { EJOUR,
       EHEURE,
	ENUMCAPTEUR,
	EVALEUR,
	EEMP,
	ETYPE,
	COLUMNS };



void affiche_alarm(GtkWidget *liste){
choix ch ;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


store=NULL ;
FILE *F ;

store=gtk_tree_view_get_model(liste);
if (store==NULL) {
       renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("heure",renderer,"text",EHEURE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("numcapteur",renderer,"text",ENUMCAPTEUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",EVALEUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("emplacement",renderer,"text",EEMP,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}
store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING);
F=fopen("Fumee.txt","r");
if (F==NULL){ return ;}
else { while(fscanf(F,"%d %d %d %d",&ch.fume.jour,&ch.fume.heure,&ch.fume.numcapteur,&ch.fume.valeurs.valeur)!=EOF){
	
       if(ch.fume.valeurs.valeur==1){
       strcpy(ch.fume.type,"capteur de fumee");
       if (ch.fume.numcapteur==3){
            strcpy(ch.fume.emp,"etage 3"); }
	else if (ch.fume.numcapteur==2){ strcpy(ch.fume.emp,"etage 2");}
        else strcpy(ch.fume.emp,"etage 1") ;

	gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,EJOUR,ch.fume.jour,EHEURE,ch.fume.heure,ENUMCAPTEUR,ch.fume.numcapteur,EVALEUR,ch.fume.valeurs.valeur,EEMP,ch.fume.emp,ETYPE,ch.fume.type,-1);
}} fclose(F); 
F=fopen("mouvement.txt","r");
if (F==NULL){ return ;}
else { while(fscanf(F,"%d %d %d %d",&ch.mvt.jour,&ch.mvt.heure,&ch.mvt.numcapteur,&ch.mvt.valeurs.valeur)!=EOF){
       if(ch.mvt.valeurs.valeur==1){
	strcpy(ch.mvt.type,"capteur de mouvement");
       if (ch.mvt.numcapteur==3){
            strcpy(ch.mvt.emp,"etage 3");}
	else if (ch.mvt.numcapteur==2){ strcpy(ch.mvt.emp,"etage 2");}
        else strcpy(ch.mvt.emp,"etage 1") ;

	gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,EJOUR,ch.mvt.jour,EHEURE,ch.mvt.heure,ENUMCAPTEUR,ch.mvt.numcapteur,EVALEUR,ch.mvt.valeurs.valeur,EEMP,ch.mvt.emp,ETYPE,ch.mvt.type,-1);
}}} fclose(F);
    
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);

}
}

//////////////////////defectueux////////////////////////////////////////
void affiche_defect(GtkWidget *liste){
choix ch ;

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;



store=NULL ;
FILE *F ;

store=gtk_tree_view_get_model(liste);
if (store==NULL) {
       renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("heure",renderer,"text",EHEURE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("numcapteur",renderer,"text",ENUMCAPTEUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",EVALEUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("emplacement",renderer,"text",EEMP,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}
store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_FLOAT, G_TYPE_STRING, G_TYPE_STRING);
F=fopen("temperature.txt","r");
if (F==NULL){ return ;}
else { 
while(fscanf(F,"%d %d %d %f\n",&ch.temp.jour,&ch.temp.heure,&ch.temp.numcapteur,&ch.temp.valeurs.val)!=EOF){
       if((ch.temp.valeurs.val<10) || (ch.temp.valeurs.val>30)){
	strcpy(ch.temp.type,"capteur de temperature");
        if (ch.temp.numcapteur==3){
            strcpy(ch.temp.emp,"etage 3");}
	else if (ch.temp.numcapteur==2){ strcpy(ch.temp.emp,"etage 2");}
        else strcpy(ch.temp.emp,"etage 1") ;
	gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,EJOUR,ch.temp.jour,EHEURE,ch.temp.heure,ENUMCAPTEUR,ch.temp.numcapteur,EVALEUR,ch.temp.valeurs.val,EEMP,ch.temp.emp,ETYPE,ch.temp.type,-1);
}} fclose(F); 
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);

}
}
/////////////////////////////panne//////////////////////////

void affiche_panne(GtkWidget *liste){
choix ch ;

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;



store=NULL ;
FILE *F ;

store=gtk_tree_view_get_model(liste);
if (store==NULL) {
       renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("heure",renderer,"text",EHEURE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("numcapteur",renderer,"text",ENUMCAPTEUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",EVALEUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("emplacement",renderer,"text",EEMP,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}
store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_FLOAT, G_TYPE_STRING, G_TYPE_STRING);
F=fopen("debit.txt","r");
if (F==NULL){ return ;}
else { 
while(fscanf(F,"%d %d %d %f",&ch.debit.jour,&ch.debit.heure,&ch.debit.numcapteur,&ch.debit.valeurs.val)!=EOF){
       if((ch.debit.valeurs.val<0) || (ch.debit.valeurs.val>30)){
	strcpy(ch.debit.type,"capteur de debit eau");
        if (ch.debit.numcapteur==3){
            strcpy(ch.debit.emp,"etage 3");}
	else if (ch.debit.numcapteur==2){ strcpy(ch.debit.emp,"etage 2");}
        else strcpy(ch.debit.emp,"etage 1") ;
	gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,EJOUR,ch.debit.jour,EHEURE,ch.debit.heure,ENUMCAPTEUR,ch.debit.numcapteur,EVALEUR,ch.debit.valeurs.val,EEMP,ch.debit.emp,ETYPE,ch.debit.type,-1);
}} fclose(F); 
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

/////////////////////////////cherchercapteur//////////////
void chercher_capteur(char ref[50])
{
	

	FILE *f1,*f2;

char reference[50];
char marque [50];
char type[50];
char valeur[50] ;
char valeur_min[50] ;
char valeur_max[50] ;
char place [50];
int etage;
int jour;
char mois[50];
int annees;


	f1=fopen("capteurs.txt","r");
	f2=fopen("old.txt","w");

while(fscanf(f1,"%s %s %s %s %s %s %s %d %d %s %d\n",reference,marque,type,valeur,valeur_min,valeur_max,place,&etage,&jour,mois,&annees)!=EOF){
	if(strcmp(ref,reference)==0||strcmp(ref,type)==0){
	fprintf(f2,"%s %s %s %s %s %s %s %d %d %s %d\n"
,reference,marque,type,valeur,valeur_min,valeur_max,place,etage,jour,mois,annees);
}
}

	fclose(f1);
	fclose(f2);

}
///////////////////////////////afficheevent/////////////
/*void affiche_historique(GtkWidget *liste ,char j [],char m[],char a[]){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
store=NULL ;
FILE *F ;

char reference[50];
char marque [50];
char type[50];
char valeur[50] ;
char valeur_min[50] ;
char valeur_max[50] ;
char place [50];
int etage;
int jour;
char mois[50];
int annees;
int jourcalendar;
jourcalendar=atoi(j);

store=gtk_tree_view_get_model(liste);
if (store==NULL) {
       renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("reference",renderer,"text",EREF,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("marque",renderer,"text",EMARQUE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPES,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",EVALEURS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("valeur_min",renderer,"text",EVALEURMIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("valeur_max",renderer,"text",EVALEURMAX,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("place",renderer,"text",EPLACE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etage",renderer,"text",EETAGE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOURS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annees",renderer,"text",EANNES,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}
store=gtk_list_store_new(COLUMN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT);
F=fopen("capteurs.txt","r");
if (F==NULL){ return ;}
else { 
while (fscanf(F,"%s %s %s %s %s %s %s %d %d %s %d\n",reference,marque,type,valeur,valeur_min,valeur_max,place,&etage,&jour,mois,&annees)!=EOF)
{ if(jourcalendar==jour){
gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,EREF,reference,EMARQUE,marque,ETYPES,type,EVALEURS,valeur,EVALEURMIN,valeur_min,EVALEURMAX,valeur_max,EPLACE,place,EETAGE,etage,EJOURS,jour,EMOIS,mois,EANNES,annees, -1);
}}fclose(F); 
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);

}
}*/


/*int mail()
{
    
    pid_t pid=fork();
    if (pid==0) { 
      static char *argv[]={"a.out",NULL};
        execv("a.out",argv);
        exit(127); 
    }
    else { 
        waitpid(pid,0,0); 
    }
    return 0;
}*/








