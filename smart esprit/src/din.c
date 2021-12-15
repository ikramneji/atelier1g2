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
void afficher_din(char fname [],GtkWidget *liste)
{


din dn;

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char dn_entree[30];
	char dn_plat_p[30];
	char dn_dessert[30];
	char date[30];

	store=NULL;

	FILE*f;

	store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("dn_entree", renderer, "text",EENTREE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("dn_plat_p", renderer, "text",EPLAT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("dn_dessert", renderer, "text",EDESSERT, NULL);
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
		while(fscanf(f,"%s %s %s %s\n",dn_entree,dn_plat_p,dn_dessert,date)!=EOF)

		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set(store,&iter,EENTREE,dn_entree,EPLAT,dn_plat_p,EDESSERT,dn_dessert,EDATE,date, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}
}
/**------------------[Supprimer]--------------------**/
void supprimer_din ( char fname[] ,char e [])
{

	char dn_entree[30];
	char dn_plat_p[30];
	char dn_dessert[30];
	char date[100];


FILE *f,*fw;
f=fopen(fname,"r");
fw=fopen("dump.txt","w");
while(fscanf(f,"%s %s %s %s\n",dn_entree,dn_plat_p,dn_dessert,date)!=EOF)
{
if(strcmp(dn_entree,e)!=0)
{
fprintf(fw,"%s %s %s %s\n",dn_entree,dn_plat_p,dn_dessert,date);
}
}
fclose(f);
fclose(fw);
remove("din.txt");
rename("dump.txt","din.txt");
}
/**-------------[Search To Edit]---------------**/
int recherche_din(char nom[])
{
	char dn_entree[30];
	char dn_plat_p[30];
	char dn_dessert[30];
	char date[100];
	int ligne=0;
FILE*f;
f=fopen("din.txt","r"); 
if(f!=NULL) 
	{
		while(fscanf(f,"%s %s %s %s\n",dn_entree,dn_plat_p,dn_dessert,date)!=EOF)
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
void modif_din(int a,char dn_entree[20],char dn_plat_p[20],char dn_dessert[20],char date[100])
{
    FILE *f;
    f=fopen("din.txt", "r");
    int line=0;
    while(fscanf(f,"%s %s %s %s\n",dn_entree,dn_plat_p,dn_dessert,date)!=EOF)
{
        line++;
        if(line == a) break;
}
fclose(f);
}


/**------------------[Modifier]--------------------**/

void modifier_din (char fname [],char e [],din dn)
{
	char dn_entree[30];
	char dn_plat_p[30];
	char dn_dessert[30];
	char date[100];
FILE *f,*fw;
f=fopen(fname,"r");
fw=fopen("dump.txt","w");
while(fscanf(f,"%s %s %s %s\n",dn_entree,dn_plat_p,dn_dessert,date)!=EOF)
{
if(strcmp(dn_entree,e)!=0)
{
fprintf(fw,"%s %s %s %s\n",dn_entree,dn_plat_p,dn_dessert,date);
}
else
{
fprintf(fw,"%s %s %s %s\n",dn.dn_entree,dn.dn_plat_p,dn.dn_dessert,dn.date);
}
}
fclose(f);
fclose(fw);
remove("din.txt");
rename("dump.txt","din.txt");
}
