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
#include "dej.h"
#include "din.h"
#define MAX 256



/**-----------------[Ajouter Petit Dej]----------------**/
void ajouter_pdej (char fname[],pdej p)
{
    FILE *f,*fw;
    f=fopen(fname,"a+");
    fw=fopen("petit_dej.txt","a+");
    fprintf(f,"%s %s %s %s\n",p.cafe,p.viennoiserie,p.jus,p.date);
   
    fclose(f);
    fclose(fw);
}
/**-----------------[Ajouter Dejeune]----------------**/
void ajouter_dej (char fname[],dej dj)
{
    FILE *f,*fw;
    f=fopen(fname,"a+");
    fw=fopen("dej.txt","a+");
    fprintf(f,"%s %s %s %s\n",dj.dj_entree,dj.dj_plat_p,dj.dj_dessert,dj.date);
   
    fclose(f);
    fclose(fw);
}
/**-----------------[Ajouter Diner]----------------**/
void ajouter_din (char fname[],din dn)
{
    FILE *f,*fw;
    f=fopen(fname,"a+");
    fw=fopen("din.txt","a+");
    fprintf(f,"%s %s %s %s\n",dn.dn_entree,dn.dn_plat_p,dn.dn_dessert,dn.date);
   
    fclose(f);
    fclose(fw);
}
