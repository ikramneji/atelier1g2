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
#include "nutr.h"
#include "pdej.h"
#include "din.h"
#include "dej.h"

enum
{	
	EENTREE,
	EPLAT,
	EDESSERT,
	EDATE,
	COLUMNS,
};
/**------------------[Afficher Pti_Dej]---------------------**/
void afficher_dej(char fname [],GtkWidget *liste)
{


dej dj;

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char dj_entree[30];
	char dj_plat_p[30];
	char dj_dessert[30];
	char date[30];

	store=NULL;

	FILE*f;

	store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("dj_entree", renderer, "text",EENTREE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("dj_plat_p", renderer, "text",EPLAT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("dj_dessert", renderer, "text",EDESSERT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("date", renderer, "text",EDATE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);


	f=fopen(fname,"r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen(fname,"a+");
		while(fscanf(f,"%s %s %s %s\n",dj_entree,dj_plat_p,dj_dessert,date)!=EOF)

		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set(store,&iter,EENTREE,dj_entree,EPLAT,dj_plat_p,EDESSERT,dj_dessert,EDATE,date, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}
}
/**------------------[Supprimer]--------------------**/
void supprimer_dej ( char fname[] ,char e [])
{

	char dj_entree[30];
	char dj_plat_p[30];
	char dj_dessert[30];
	char date[100];


FILE *f,*fw;
f=fopen(fname,"r");
fw=fopen("dump.txt","w");
while(fscanf(f,"%s %s %s %s\n",dj_entree,dj_plat_p,dj_dessert,date)!=EOF)
{
if(strcmp(dj_entree,e)!=0)
{
fprintf(fw,"%s %s %s %s\n",dj_entree,dj_plat_p,dj_dessert,date);
}
}
fclose(f);
fclose(fw);
remove("dej.txt");
rename("dump.txt","dej.txt");
}
/**-------------[Search To Edit]---------------**/
int recherche_dej(char nom[])
{
	char dj_entree[30];
	char dj_plat_p[30];
	char dj_dessert[30];
	char date[100];
	int ligne=0;
FILE*f;
f=fopen("dej.txt","r"); 
if(f!=NULL) 
	{
		while(fscanf(f,"%s %s %s %s\n",dj_entree,dj_plat_p,dj_dessert,date)!=EOF)
		{
                        ligne++;
			if(strcmp(nom,date)==0)
			{
                        fclose(f);
			return(ligne);
			}
		}
		fclose(f);
		return(-1);
	}
	return(-1);
}
/**-------------[Edit]-----------------**/
void modif_dej(int a,char dj_entree[20],char dj_plat_p[20],char dj_dessert[20],char date[100])
{
    FILE *f;
    f=fopen("dej.txt", "r");
    int line=0;
    while(fscanf(f,"%s %s %s %s\n",dj_entree,dj_plat_p,dj_dessert,date)!=EOF)
{
        line++;
        if(line == a) break;
}
fclose(f);
}


/**------------------[Modifier]--------------------**/

void modifier_dej (char fname [],char e [],dej dj)
{
	char dj_entree[30];
	char dj_plat_p[30];
	char dj_dessert[30];
	char date[100];
FILE *f,*fw;
f=fopen(fname,"r");
fw=fopen("dump.txt","w");
while(fscanf(f,"%s %s %s %s\n",dj_entree,dj_plat_p,dj_dessert,date)!=EOF)
{
if(strcmp(dj_entree,e)!=0)
{
fprintf(fw,"%s %s %s %s\n",dj_entree,dj_plat_p,dj_dessert,date);
}
else
{
fprintf(fw,"%s %s %s %s\n",dj.dj_entree,dj.dj_plat_p,dj.dj_dessert,dj.date);
}
}
fclose(f);
fclose(fw);
remove("dej.txt");
rename("dump.txt","dej.txt");
}
