#include "callbacks.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reclamation.h"
enum{
	RCIN,
	RNOM,
	RPRENOM,
	RTEXT,
	RJOUR,
	RMOIS,
	RANNEE,
	RETAT,
	COLUMNS
};
void ajouter_reclamation(reclamation r){
	FILE *f,*g;
	f=fopen("reclamationH.txt","a+");
	g=fopen("reclamationR.txt","a+");
	if(f!=NULL){
		if(r.etat==0)
			fprintf(f,"%s %s %s %s %d %d %d %d\n",r.cin,r.nom,r.prenom,r.text,r.d.jour,r.d.mois,r.d.annee,r.etat);
		else
			fprintf(g,"%s %s %s %s %d %d %d %d\n",r.cin,r.nom,r.prenom,r.text,r.d.jour,r.d.mois,r.d.annee,r.etat);
	}
	fclose(f);
	fclose(g);
}
void supprimer_reclamation(char cin[30],char file[20]){
	reclamation r;
	FILE *f,*g;
	f=fopen(file,"r");
	g=fopen("tmp.txt","a+");
	if(f!=NULL && g!=NULL){
		while(fscanf(f,"%s %s %s %s %d %d %d %d\n",r.cin,r.nom,r.prenom,r.text,&r.d.jour,&r.d.mois,&r.d.annee,&r.etat)!=EOF)
		{
			if(strcmp(r.cin,cin)!=0){
				fprintf(g,"%s %s %s %s %d %d %d %d\n",r.cin,r.nom,r.prenom,r.text,r.d.jour,r.d.mois,r.d.annee,r.etat);
			}
		}
	}
	remove(file);
	rename("tmp.txt",file);
	fclose(f);
	fclose(g);
}
void modifier_reclamation(reclamation r,char file[20]){
	reclamation r1;
	FILE *f,*g;
	f=fopen(file,"r");
	g=fopen("tmp.txt","a+");
	if(f!=NULL && g!=NULL){
		while(fscanf(f,"%s %s %s %s %d %d %d %d\n",r1.cin,r1.nom,r1.prenom,r1.text,&r1.d.jour,&r1.d.mois,&r1.d.annee,&r1.etat)!=EOF)
		{
			if(strcmp(r1.cin,r.cin)!=0){
				fprintf(g,"%s %s %s %s %d %d %d %d\n",r1.cin,r1.nom,r1.prenom,r1.text,r1.d.jour,r1.d.mois,r1.d.annee,r1.etat);
			}
			else{
				
				fprintf(g,"%s %s %s %s %d %d %d %d\n",r.cin,r.nom,r.prenom,r.text,r.d.jour,r.d.mois,r.d.annee,r.etat);
				
			}
		}
	}
	remove(file);
	rename("tmp.txt",file);
	fclose(f);
	fclose(g);
}
int cinexiste(char cin[30],char file[20]){
	reclamation r;
	FILE *f;
	f=fopen(file,"r");
	if(f!=NULL){
		while(fscanf(f,"%s %s %s %s %d %d %d %d\n",r.cin,r.nom,r.prenom,r.text,&r.d.jour,&r.d.mois,&r.d.annee,&r.etat)!=EOF)
		{
			if(strcmp(r.cin,cin)==0){
				return 1;
			}
			else
				return 0;
		}
	}

}
void afficher_reclamation(GtkWidget *liste,char file[20]){
	GtkCellRenderer *renderer;
        GtkTreeViewColumn *column;
        GtkTreeIter iter;
        GtkListStore *store;
       
        reclamation r;
     
        FILE *f;
        store = NULL;
        store = gtk_tree_view_get_model(liste);

        if(store == NULL){

            renderer = gtk_cell_renderer_text_new();
            column = gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",RCIN,NULL);
            column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer = gtk_cell_renderer_text_new();
            column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",RNOM,NULL);
            column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer = gtk_cell_renderer_text_new();
            column = gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",RPRENOM,NULL);
            column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer = gtk_cell_renderer_text_new();
            column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",RJOUR,NULL);
            column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer = gtk_cell_renderer_text_new();
            column=gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",RMOIS,NULL);
            column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer = gtk_cell_renderer_text_new();
            column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",RANNEE,NULL);
            column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer = gtk_cell_renderer_text_new();
            column=gtk_tree_view_column_new_with_attributes("Etat",renderer,"text",RETAT,NULL);
            column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        }
    store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
       
       
        f = fopen(file,"r");
    if(f == NULL){
            return;
        }
    else{
            while(fscanf(f,"%s %s %s %s %d %d %d %d\n",r.cin,r.nom,r.prenom,r.text,&r.d.jour,&r.d.mois,&r.d.annee,&r.etat)!=EOF){            
    		gtk_list_store_append(store,&iter);
                gtk_list_store_set(store,&iter,RCIN,r.cin,RNOM,r.nom,RPRENOM,r.prenom,RTEXT,r.text,RJOUR,r.d.jour,RMOIS,r.d.mois,RANNEE,r.d.annee,RETAT,r.etat,-1);
               
            }
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
    g_object_unref(store);
            fclose(f);
        }
       
}
void recherche_reclamation(char cin[30],char file[20]){
	reclamation r;
	FILE *f,*g;
	f=fopen(file,"r");
	g=fopen("recherche.txt","a+");
	if(f!=NULL){
		while(fscanf(f,"%s %s %s %s %d %d %d %d\n",r.cin,r.nom,r.prenom,r.text,&r.d.jour,&r.d.mois,&r.d.annee,&r.etat)!=EOF)
		{
			if(strcmp(r.cin,cin)==0){
				fprintf(g,"%s %s %s %s %d %d %d %d\n",r.cin,r.nom,r.prenom,r.text,r.d.jour,r.d.mois,r.d.annee,r.etat);
			}
			
		}
	}
	fclose(f);
	fclose(g);
}
int service_le_plus_reclame()
{
	int s=0,s1=0;
	reclamation r;
	FILE *f,*g;
	f=fopen("reclamationH.txt","r");
	g=fopen("reclamationR.txt","r");
	if(f!=NULL && g!=NULL){
		while(fscanf(f,"%s %s %s %s %d %d %d %d\n",r.cin,r.nom,r.prenom,r.text,&r.d.jour,&r.d.mois,&r.d.annee,&r.etat)!=EOF)
		{
			s++;
			
		}
		while(fscanf(g,"%s %s %s %s %d %d %d %d\n",r.cin,r.nom,r.prenom,r.text,&r.d.jour,&r.d.mois,&r.d.annee,&r.etat)!=EOF)
		{
			s1++;
			
		}
	}
	if(s>s1)
		return 1;//si hebergement est plus reclame return 1
	else
		return 0;
}











