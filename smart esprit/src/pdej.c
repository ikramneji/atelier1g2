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

enum
{	
	ECAFE,
	EVIN,
	EJUS,
	EDATE,
	COLUMNS,
};

/**------------------[Afficher Pti_Dej]---------------------**/
void afficher_peti_dej(char fname [],GtkWidget *liste)
{
	
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char cafe[100];
	char viennoiserie[100];
	char jus[100];
	char date[100];
	

	store=NULL;


	FILE *f;

store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("cafe", renderer, "text",ECAFE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("viennoiserie", renderer, "text",EVIN, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("jus", renderer, "text",EJUS, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("date", renderer, "text",EDATE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	store=gtk_list_store_new (COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen(fname,"r");
	if(f==NULL)
	{
	return;
	}
	else
	{
		f = fopen(fname,"a+");
		while(fscanf(f,"%s %s %s %s\n",cafe,viennoiserie,jus,date)!=EOF)

		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,ECAFE,cafe,EVIN,viennoiserie,EJUS,jus,EDATE,date, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref(store);
}
}
}

/**------------------[Supprimer]--------------------**/
void supprimer_pdej ( char fname[] ,char c [])
{

	char cafe[100];
	char viennoiserie[100];
	char jus[100];
	char date[100];


FILE *f,*fw;
f=fopen(fname,"r");
fw=fopen("dump.txt","w");
while(fscanf(f,"%s %s %s %s\n",cafe,viennoiserie,jus,date)!=EOF)
{
if(strcmp(cafe,c)!=0)
{
fprintf(fw,"%s %s %s %s\n",cafe,viennoiserie,jus,date);
}
}
fclose(f);
fclose(fw);
remove("petit_dej.txt");
rename("dump.txt","petit_dej.txt");
}

/**-------------[Search To Edit]---------------**/
int recherche_pdej(char nom[])
{
	char cafe[30];
	char viennoiserie[30];
	char jus[30];
	char date[30];
	int ligne=0;
FILE*f;
f=fopen("petit_dej.txt","r"); 
if(f!=NULL) 
	{
		while(fscanf(f,"%s %s %s %s\n",cafe,viennoiserie,jus,date)!=EOF)
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
void modif_pdej(int a,char cafe[20],char viennoiserie[20],char jus[20],char date[100])
{
    FILE *f;
    f=fopen("petit_dej.txt", "r");
    int line=0;
    while(fscanf(f,"%s %s %s %s\n",cafe,viennoiserie,jus,date)!=EOF)
{
        line++;
        if(line == a) break;
}
fclose(f);
}
/**------------------[Modifier]--------------------**/

void modifier (char fname [],char c [],pdej p)
{
	char cafe[100];
	char viennoiserie[100];
	char jus[100];
	char date[100];
FILE *f,*fw;
f=fopen(fname,"r");
fw=fopen("dump.txt","w");
while(fscanf(f,"%s %s %s %s\n",cafe,viennoiserie,jus,date)!=EOF)
{
if(strcmp(cafe,c)!=0)
{
fprintf(fw,"%s %s %s %s\n",cafe,viennoiserie,jus,date);
}
else
{
fprintf(fw,"%s %s %s %s\n",p.cafe,p.viennoiserie,p.jus,p.date);
}
}
fclose(f);
fclose(fw);
remove("petit_dej.txt");
rename("dump.txt","petit_dej.txt");
}

