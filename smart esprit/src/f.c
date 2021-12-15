
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "f.h"

enum
{
	EID,
	ENOM,
	EPRENOM,
	ECLASSE,
	EREFCH,
	EPAYEMENT,
	EJOUR,
	EMOIS,	
	EANNEE,
	COLUMNS,
};
enum
{	
	EETAGE,
	ENB,
	COLUMN,
};


void afficher_heb(){
eheb e;
FILE *f=NULL;
f=fopen("fichier.txt","r");
if(f!=NULL)
while(fscanf(f,"%s %s %s %s %s %d %d %d %d\n",e.id,e.nom,e.prenom,e.classe,
e.refch,&e.payement,&e.date_entree.jour,&e.date_entree.mois,&e.date_entree.annee)!=EOF)
{

printf("%s %s %s %s %s %d %d %d %d\n",e.id,e.nom,e.prenom,e.classe,
e.refch,e.payement,e.date_entree.jour,e.date_entree.mois,e.date_entree.annee);
}
fclose(f);
}

void ajouter_heb(eheb e){
FILE *f=NULL;
f=fopen("fichier.txt","a");

fprintf(f,"%s %s %s %s %s %d %d %d %d\n",e.id,e.nom,e.prenom,e.classe,
e.refch,e.payement,e.date_entree.jour,e.date_entree.mois,e.date_entree.annee);
fclose(f);

chambre c;
FILE*fic=NULL;

f=fopen("chambre.txt","r");
fic=fopen("fic.txt","w");

while(fscanf(f,"%s %d\n",c.refch,&c.etat)!=EOF){

if( strcmp(c.refch,e.refch)!=0    )
{
fprintf(fic,"%s %d\n",c.refch,c.etat);
}
else
{fprintf(fic,"%s %d\n",c.refch,c.etat+1);


}}
fclose(f);
fclose(fic);
remove("chambre.txt");
rename("fic.txt","chambre.txt");
}

int chercher_heb(char id[]){

FILE *f=NULL;
eheb e;int t=-1;
f=fopen("fichier.txt","r");

while(fscanf(f,"%s %s %s %s %s %d %d %d %d\n",e.id,e.nom,e.prenom,e.classe,
e.refch,&e.payement,&e.date_entree.jour,&e.date_entree.mois,&e.date_entree.annee)!=EOF)
{
if(strcmp(e.id,id)==0)
     t=1;
}


fclose(f);
return(t);
}

void modifier_heb(eheb e){
eheb x;
FILE*f=NULL;
FILE*fic=NULL;
char ref[5];

f=fopen("fichier.txt","r");
fic=fopen("fic.txt","w");

while(fscanf(f,"%s %s %s %s %s %d %d %d %d\n",x.id,x.nom,x.prenom,x.classe,
x.refch,&x.payement,&x.date_entree.jour,&x.date_entree.mois,&x.date_entree.annee)!=EOF){

if( strcmp(x.id,e.id)!=0    )
{
fprintf(fic,"%s %s %s %s %s %d %d %d %d\n",x.id,x.nom,x.prenom,x.classe,
x.refch,x.payement,x.date_entree.jour,x.date_entree.mois,x.date_entree.annee);
}
else
{strcpy(ref,x.refch);
fprintf(fic,"%s %s %s %s %s %d %d %d %d\n",e.id,e.nom,e.prenom,e.classe,
e.refch,e.payement,e.date_entree.jour,e.date_entree.mois,e.date_entree.annee);


}}
fclose(f);
fclose(fic);
remove("fichier.txt");
rename("fic.txt","fichier.txt");
if (strcmp(ref,e.refch)!=0){
chambre c;


f=fopen("chambre.txt","r");
fic=fopen("fic.txt","w");

while(fscanf(f,"%s %d\n",c.refch,&c.etat)!=EOF){
if(strcmp(ref,c.refch)==0    )
{
fprintf(fic,"%s %d\n",c.refch,c.etat-1);
}
else if(strcmp(c.refch,e.refch)==0    )
{
fprintf(fic,"%s %d\n",c.refch,c.etat+1);
}
else
fprintf(fic,"%s %d\n",c.refch,c.etat);


}
fclose(f);
fclose(fic);
remove("chambre.txt");
rename("fic.txt","chambre.txt");
}


}

void supprimer_heb(char id[]){
char ch[20];
eheb e;
FILE *f=NULL;
FILE *fic=NULL;
f=fopen("fichier.txt","r");
fic=fopen("fic.txt","w");
while(fscanf(f,"%s %s %s %s %s %d %d %d %d\n",e.id,e.nom,e.prenom,e.classe,
e.refch,&e.payement,&e.date_entree.jour,&e.date_entree.mois,&e.date_entree.annee)!=EOF) 

{

if (strcmp(id,e.id)!=0)
fprintf(fic,"%s %s %s %s %s %d %d %d %d\n",e.id,e.nom,e.prenom,e.classe,
e.refch,e.payement,e.date_entree.jour,e.date_entree.mois,e.date_entree.annee);
}
fclose(fic);
fclose(f);
remove("fichier.txt");
rename("fic.txt","fichier.txt");

chambre c;


f=fopen("chambre.txt","r");
fic=fopen("fic.txt","w");

while(fscanf(f,"%s %d\n",c.refch,&c.etat)!=EOF){

if( strcmp(e.refch,c.refch)!=0    )
{
fprintf(fic,"%s %d\n",c.refch,c.etat);
}
else
{fprintf(fic,"%s %d\n",c.refch,c.etat-1);


}}
fclose(f);
fclose(fic);
remove("chambre.txt");
rename("fic.txt","chambre.txt");
}



int nbres(char refch[]){
FILE*f=NULL;
int i,res;
char refc[10];
f=fopen("chambre.txt","r");

while(fscanf(f,"%s %d\n",refc,&i)!=EOF)
{
if(strcmp(refc,refch)==0)
     res=i;
};


fclose(f);
return(res);


}

void affiche_heb(GtkWidget *liste)
{

FILE*f;
eheb e;

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char id[20];
	char nom[20];
	char prenom[20];
	char classe[10];
	char refch[10];
	int payement;
	int jour;
	int mois;	
	int annee;	
	store=NULL;
	store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",EID, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",EPRENOM, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("classe", renderer, "text",ECLASSE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("refch", renderer, "text",EREFCH, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("payement", renderer, "text",EPAYEMENT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("jour_entree", renderer, "text",EJOUR, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("mois_entree", renderer, "text",EMOIS, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("annee_entree", renderer, "text",EANNEE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);


	f=fopen("fichier.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("fichier.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %d %d %d %d\n",e.id,e.nom,e.prenom,e.classe,e.refch,&e.payement,&e.date_entree.jour,&e.date_entree.mois,&e.date_entree.annee)!=EOF)
		{	 
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store,&iter,EID,e.id,ENOM,e.nom,EPRENOM,e.prenom,ECLASSE,e.classe,EREFCH,e.refch,EPAYEMENT,e.payement,EJOUR,e.date_entree.jour,EMOIS,e.date_entree.mois,EANNEE,e.date_entree.annee,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}
}


void affich_f(GtkWidget *liste)
{

FILE*f;
eheb e;

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char etage[20];
	int nb;
		
	store=NULL;
	store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("etage", renderer, "text",EETAGE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nombre etudiants", renderer, "text",ENB, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	}
	store=gtk_list_store_new (COLUMN, G_TYPE_STRING, G_TYPE_INT);


	f=fopen("fichier.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("fichier.txt","a+");
int nb0=0,nb1=0,nb2=0;
		while(fscanf(f,"%s %s %s %s %s %d %d %d %d\n",e.id,e.nom,e.prenom,e.classe,e.refch,&e.payement,&e.date_entree.jour,&e.date_entree.mois,&e.date_entree.annee)!=EOF){
if (e.refch[1]=='0')
nb0=nb0+1;
if (e.refch[1]=='1')
nb1=nb1+1;
if (e.refch[1]=='2')
nb2=nb2+1;}
fclose(f);
	 
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store,&iter,EETAGE,"etage 0",ENB,nb0,-1);
		gtk_list_store_append (store, &iter);
			gtk_list_store_set (store,&iter,EETAGE,"etage 1",ENB,nb1,-1);
gtk_list_store_append (store, &iter);
			gtk_list_store_set (store,&iter,EETAGE,"etage 2",ENB,nb2,-1);
		
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}
}


