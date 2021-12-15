#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "fonction.h"

void ajouter_1(holybody r)
{

    
    FILE *f=NULL;

    
f=fopen("users.txt","a");
if(f!=NULL)
{
    
    printf("your safe now be happy");

fprintf(f,"%d %d %d %s %s %s %s %s %s %s \n",r.jour,r.mois,r.annee,r.nom,r.prenom,r.Cin,r.Email,r.Modps,r.Role,r.sexe);
fclose(f);
}
else
printf("\n not found baby ");



}
void ajouter_2(char e[20])
{

    
    FILE *f=NULL;

    
f=fopen("niveaux.txt","a");
if(f!=NULL)
{
    
    

fprintf(f,"%s \n",e);
fclose(f);
}
else
printf("\n not found baby ");



}



enum
{
Ejour,
Emois,
Eannee,
Enom,
Eprenom,
ECIN,
Eemail,
Emdp,
Erole,
Esexe,
COLUMNS
};

void affich(GtkWidget *liste)
{




    GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	
       char jour[20];
      char mois[20];
      char annee[20];
     char nom[20];
    char prenom[20];
    char Cin[20];
    char Email[20];
  char Modps[20];
  char Role[20];
  char sexe[20];
	store=NULL;

	FILE *f;
	if(store==NULL)
	{






	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",Ejour,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",Emois,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",Eannee,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",Enom,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",Eprenom,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Cin",renderer,"text",ECIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Email",renderer,"text",Eemail,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

       renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Modps",renderer,"text",Emdp,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Role",renderer,"text",Erole,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);



        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",Esexe,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	}
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("users.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("users.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",jour,mois,annee,nom,prenom,Cin,Email,Modps,Role,sexe)!=EOF)

		{
			gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,Ejour,jour,Emois,mois,Eannee,annee,Enom,nom,Eprenom,prenom,ECIN,Cin,Eemail,Email,Emdp,Modps,Erole,Role,Esexe,sexe,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
		g_object_unref (store);

	}

}
enum
{
Ejou,
Emoi,
Eanne,
Eno,
Epreno,
ECI,
Eemai,
Emd,
Erol,
Esex,
COLUMN
};



void chercher(char n[20] ,char p[20],GtkWidget *liste)

{




    GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	
       char jour[20];
      char mois[20];
      char annee[20];
     char nom[20];
    char prenom[20];
    char Cin[20];
    char Email[20];
  char Modps[20];
  char Role[20];
  char sexe[20];
	store=NULL;

	FILE *f;
	if(store==NULL)
	{






	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",Ejou,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",Emoi,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",Eanne,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",Eno,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",Epreno,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Cin",renderer,"text",ECI,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Email",renderer,"text",Eemai,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

       renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Modps",renderer,"text",Emdp,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Role",renderer,"text",Erol,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);



        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",Esex,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	}
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("users.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("users.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",jour,mois,annee,nom,prenom,Cin,Email,Modps,Role,sexe)!=EOF)

		{


       if ((strcmp(n,Email)==0)&(strcmp(p,Cin)==0))
       {


			gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,Ejour,jour,Emois,mois,Eannee,annee,Enom,nom,Eprenom,prenom,ECIN,Cin,Eemail,Email,Emdp,Modps,Erole,Role,Esexe,sexe,-1);
  }
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
		g_object_unref (store);

	}




}
enum
{
Ejo,
Emo,
Eann,
En,
Epren,
COLUM
};


void NiveauEtud(GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
    FILE *f;
    char ktu[20];
    int a=0,b=0,c=0,d=0,e=0;
    char Niveau_1[20],Niveau_2[20],Niveau_3[20],Niveau_4[20],Niveau_5[20];
    
  f=fopen("niveaux.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("niveaux.txt","a+");
		while(fscanf(f,"%s \n",ktu)!=EOF)

		{


       if ((strcmp("5",ktu)==0))
       {
         a++;  
       }
       if ((strcmp("4",ktu)==0))
       {
        b++;   
       }
       if ((strcmp("3",ktu)==0))
       {
           c++;
       }
       if ((strcmp("2",ktu)==0))
       {
          d++; 
       }
       if ((strcmp("1",ktu)==0))
       {
         e++;  
       }
		}
		fclose(f);

	}
	
	sprintf(Niveau_1, "%d",a);
	sprintf(Niveau_2, "%d",b);
	sprintf(Niveau_3, "%d",c);
	sprintf(Niveau_4, "%d",d);
	sprintf(Niveau_5, "%d",e);
	
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Niveau_1",renderer,"text",Ejo,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Niveau_2",renderer,"text",Emo,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Niveau_3",renderer,"text",Eann,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Niveau_4",renderer,"text",En,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Niveau_5",renderer,"text",Epren,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	store=gtk_list_store_new(COLUM,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,Ejo,Niveau_1,Emo,Niveau_2,Eann,Niveau_3,En,Niveau_4,Epren,Niveau_5,-1);
	gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
		g_object_unref (store);

}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////








void modifier_reclam( userty p ,holybody r)
{
holybody tmp;

FILE *f=NULL;
FILE *fich=NULL;
f=fopen("users.txt","r");
fich=fopen("tmp.txt","a");
if(f!=NULL)
{
while(fscanf(f,"%d %d %d %s %s %s %s %s %s %s \n",&tmp.jour,&tmp.mois,&tmp.annee,tmp.nom,tmp.prenom,tmp.Cin,tmp.Email,tmp.Modps,tmp.Role,tmp.sexe)!=EOF)
{
 if (strcmp(p.Cin,tmp.Cin)!=0)
{
fprintf(fich,"%d %d %d %s %s %s %s %s %s %s \n",tmp.jour,tmp.mois,tmp.annee,tmp.nom,tmp.prenom,tmp.Cin,tmp.Email,tmp.Modps,tmp.Role,tmp.sexe);
}
else
fprintf(fich,"%d %d %d %s %s %s %s %s %s %s \n",r.jour,r.mois,r.annee,r.nom,r.prenom,r.Cin,r.Email,r.Modps,r.Role,r.sexe);
}
}
fclose(fich);
fclose(f);
remove("users.txt");
rename("tmp.txt","users.txt");
}
void supprimer_reclam(userty p)
{
holybody tmp;
FILE *f=NULL;
FILE *fich=NULL;
f=fopen("users.txt","r");
fich=fopen("tmp.txt","a");
if(f!=NULL)
{
while(fscanf(f,"%d %d %d %s %s %s %s %s %s %s \n",&tmp.jour,&tmp.mois,&tmp.annee,tmp.nom,tmp.prenom,tmp.Cin,tmp.Email,tmp.Modps,tmp.Role,tmp.sexe)!=EOF)
{
if(strcmp(p.Cin,tmp.Cin)!=0)
{
fprintf(fich,"%d %d %d %s %s %s %s %s %s %s \n",tmp.jour,tmp.mois,tmp.annee,tmp.nom,tmp.prenom,tmp.Cin,tmp.Email,tmp.Modps,tmp.Role,tmp.sexe);

}

}
}
fclose(fich);
fclose(f);
remove("users.txt");
rename("tmp.txt","users.txt");
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
int Login( char id[20] ,char psw[20])
{

holybody tmp;
int xch=0;
FILE *f=NULL;
f=fopen("users.txt","r");
if(f!=NULL)
{
	while(fscanf(f,"%d %d %d %s %s %s %s %s %s %s \n",&tmp.jour,&tmp.mois,&tmp.annee,tmp.nom,tmp.prenom,tmp.Cin,tmp.Email,tmp.Modps,tmp.Role,tmp.sexe)!=EOF)
	{
		
		if((strcmp(id,tmp.Cin)==0)&(strcmp(psw,tmp.Modps)==0))
		{

			if(strcmp("Administrateur",tmp.Role)==0)
				xch=1;
			else if(strcmp("AgentFoyer",tmp.Role)==0)
				xch=2;
			else if(strcmp("AgentRestaurant",tmp.Role)==0)
				xch=3;
			else if(strcmp("Direction",tmp.Role)==0)
				xch=4;
			else if(strcmp("Nutritionniste",tmp.Role)==0)
				xch=5;
			else if(strcmp("Technicien",tmp.Role)==0)
				xch=6;
		}
	}
}
fclose(f);
return(xch);
}



int verification(holybody z)
{
int xr;

holybody tmp;
FILE *f=NULL;
f=fopen("users.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%d %d %d %s %s %s %s %s %s %s \n",&tmp.jour,&tmp.mois,&tmp.annee,tmp.nom,tmp.prenom,tmp.Cin,tmp.Email,tmp.Modps,tmp.Role,tmp.sexe)!=EOF)
{
	 if (strcmp(z.Cin,tmp.Cin)==0)
	{
	xr=1;
		fclose(f);
		return(xr);
	}
	else
	xr=0;
	}
}
fclose(f);
return(xr);
}

