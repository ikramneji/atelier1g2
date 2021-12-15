#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include <time.h>
#include "reclamation.h"
#include "stock.h"
#include "stock.c"
#include "f.h"
#include "nutr.h"
#include "pdej.h"
#include "dej.h"
#include "din.h"
#include "capteur.h"
void
on_button1_login_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *entry1,*entry2,*window,*window2;
	entry1=lookup_widget(button,"entry1_login");
	entry2=lookup_widget(button,"entry2_login");
	char nom[20],psw[20];
	strcpy(nom,gtk_entry_get_text(entry1));
	strcpy(psw,gtk_entry_get_text(entry2));
	if (Login(nom,psw)==1){
		window=create_Dashbord();
		gtk_widget_show(window);
		window2=lookup_widget(button,"Login");
		gtk_widget_destroy(window2);
	}
	else if (Login(nom,psw)==3){
		window=create_windowafficher();
		gtk_widget_show(window);
		window2=lookup_widget(button,"Login");
		gtk_widget_destroy(window2);
	}
	else if (Login(nom,psw)==2){
		window=create_principale();
		gtk_widget_show(window);
		window2=lookup_widget(button,"Login");
		gtk_widget_destroy(window2);
	}
	else if (Login(nom,psw)==4){
		window=create_windowajouter();
		gtk_widget_show(window);
		window2=lookup_widget(button,"Login");
		gtk_widget_destroy(window2);
	}
	else if (Login(nom,psw)==5){
		window=create_menu_nutris();
		gtk_widget_show(window);
		window2=lookup_widget(button,"Login");
		gtk_widget_destroy(window2);
	}
	else if (Login(nom,psw)==6){
		window=create_home();
		gtk_widget_show(window);
		window2=lookup_widget(button,"Login");
		gtk_widget_destroy(window2);
	}
		
		
}


void
on_button2_login_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	window1=create_Inscription();
	gtk_widget_show(window1);
}






holybody z;
userty p;

int h;
int g[2];

/*   bouton inscription dans la fenêtre Authentification  */

void
on_hazemkh_inscri_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowr,*Authentification;
windowr=create_Inscription();
gtk_widget_show (windowr);
Authentification = lookup_widget(button,"Authentification");
gtk_widget_destroy(Authentification);
}

/*   bouton connecter dans la fenêtre Authentification  */

void
on_hazemkh_connecter_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *nom, *prenom;
int eio;
nom=lookup_widget(button,"hazemusername");
prenom=lookup_widget(button,"hazemmotpasse");

//eio=login( gtk_entry_get_text(GTK_ENTRY(nom)),gtk_entry_get_text(GTK_ENTRY(prenom)));

if(eio==1)
{
    GtkWidget *windo;
windo=create_Dashbord();
gtk_widget_show (windo);
}
else if (eio==2)
{
    GtkWidget *affiche_etud ;
affiche_etud=create_affiche_etud();
gtk_widget_show (affiche_etud);
}
else if (eio==3)
{
     GtkWidget *windowr;
windowr=create_menu();
gtk_widget_show (windowr);
}
}

/* radio button femme da la fentêre "insncription"   */
void
on_hazemkh_femme_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{



if(gtk_toggle_button_get_active(togglebutton))
h=1;




}

/*  radio button "homme" da la fentêre "insncription"   */
void
on_hazemkh_homme_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(togglebutton))
h=2;

}

/*  bouton "inscrir" de la fenêtre "inscription"  */

void
on_hazem33inscrit_enter                (GtkWidget       *objet_graphique,gpointer  user_data)


{



holybody z;

int xe;

GtkWidget *nom, *prenom, *cin, *role, *email, *mdp;
GtkWidget *jouro;
GtkWidget *moiso;
GtkWidget *annneo;
nom=lookup_widget(objet_graphique,"hazemkh_nom");
prenom=lookup_widget(objet_graphique,"hazemkh_prenom");
cin=lookup_widget(objet_graphique,"hazemkh_cin");
email=lookup_widget(objet_graphique,"hazemkh_email");
mdp=lookup_widget(objet_graphique,"hazemkh_mdp");
jouro=lookup_widget(objet_graphique,"spinbutton1_hazem");
moiso=lookup_widget(objet_graphique,"spinbutton2_hazemmois");
annneo=lookup_widget(objet_graphique,"spinbutton3_hazzzem");
role=lookup_widget(objet_graphique,"combobox1_role");

if(strcmp("Administrateur",gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)))==0)
strcpy(z.Role,"Administrateur");

else if(strcmp("Direction",gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)))==0)
strcpy(z.Role,"Direction");
else if(strcmp("Technicien",gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)))==0)
strcpy(z.Role,"Technicien");
else if(strcmp("Nutritionniste",gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)))==0)
strcpy(z.Role,"Nutritionniste");
else if(strcmp("AgentFoyer",gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)))==0)
strcpy(z.Role,"AgentFoyer");
else if(strcmp("AgentRestaurant",gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)))==0)
strcpy(z.Role,"AgentRestaurant");
else if(strcmp("Etudiant",gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)))==0)
{
strcpy(z.Role,"Etudiant");


GtkWidget *windowr;
windowr=create_Eleve();
gtk_widget_show (windowr);



}



z.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jouro));
z.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moiso));
z.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annneo));



strcpy(z.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(z.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(z.Cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(z.Email,gtk_entry_get_text(GTK_ENTRY(email)));
strcpy(z.Modps,gtk_entry_get_text(GTK_ENTRY(mdp)));


 if (h==2) 
strcpy(z.sexe,"Homme");
else if(h==1)
strcpy(z.sexe,"Femme");

/*  vérification de CIN */

xe=verification(z);
if(xe==0)
ajouter_1(z);
else if (xe==1)
{

GtkWidget *verification;
verification=create_verification();
gtk_widget_show (verification);
}
}

/*  treeview de "dashbord" pour les utilisateurs  */
void
on_hazemtreeview1_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* nom;
gchar* prenom;
gchar* Cin;
gchar* Email;
gchar* Modps;
gchar* Role;
gchar* sexe;

GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{

gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&jour,1,&mois,2,&annee,3,&nom,4,&prenom,5,&Cin,6,&Email,7,&Modps,8,&Role,9,&sexe,-1);
strcpy(p.jour,jour);
strcpy(p.mois,mois);
strcpy(p.annee,annee);
strcpy(p.nom,nom);
strcpy(p.prenom,prenom);
strcpy(p.Cin,Cin);
strcpy(p.Email,Email);
strcpy(p.Modps,Modps);
strcpy(p.Role,Role);
strcpy(p.sexe,sexe);
}
}

/*  bouton "ajouter" de "dashbord"  */
void
on_hazemkh_ajouter2_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowr;
windowr=create_Inscription();
gtk_widget_show (windowr);
}

/*  bouton "modifier" de "dashbord"  */
void
on_hazem_modifier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowre;
windowre=create_modificationhazem();
gtk_widget_show (windowre);
}

/*  bouton "Recherche" de "dashbord"  */
void
on_hazemkhrecherche_clicked            (GtkWidget       *objet_graphique,gpointer  user_data)
{



GtkWidget *treevieww;

treevieww=lookup_widget(objet_graphique,"hazemtreeview1");
char n[20];
char p[20];


GtkWidget *email;
GtkWidget *cin;

email=lookup_widget(objet_graphique,"hazem_recherche_cin");
cin=lookup_widget(objet_graphique,"hazem_recherche_entryo");
strcpy(n,gtk_entry_get_text(GTK_ENTRY(email)));
strcpy(p,gtk_entry_get_text(GTK_ENTRY(cin)));
chercher(n,p,treevieww);
}

/*  bouton Supprimer de dashbord  */
void
on_hazemkh_supprimer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowre;
windowre=create_hazemconfirmation();
gtk_widget_show (windowre);

}

/*  bouton actualiser de dashbord  */
void
on_hazemkh_actualiser_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;


treeview=lookup_widget(button,"hazemtreeview1");
 affich(treeview);




}

/*  bouton homme de modification  */
void
on_radiobutton_hazemhomme11_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
h=2;
}

/*  bouton Femme de la fenetre "modification"  */
void
on_hazem_radiobuton666modif_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
h=1;

}

/*  check button "Non" de la fenêtre "confirmation" */
void
on_checkbutton_hazem_non_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
g[1]=3;

}

/*  confirmation de niveau de l'etudiant de la fenrêtre "Eleve"  */
void
on_hazem_ajout_tache2_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *uuyt;
char hp[20];

uuyt=lookup_widget(button,"combobox1_hazzrty");
if(strcmp("1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(uuyt)))==0)
strcpy(hp,"1");
if(strcmp("2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(uuyt)))==0)
strcpy(hp,"2");

if(strcmp("3",gtk_combo_box_get_active_text(GTK_COMBO_BOX(uuyt)))==0)
strcpy(hp,"3");

if(strcmp("4",gtk_combo_box_get_active_text(GTK_COMBO_BOX(uuyt)))==0)
strcpy(hp,"4");

if(strcmp("5",gtk_combo_box_get_active_text(GTK_COMBO_BOX(uuyt)))==0)
strcpy(hp,"5");
ajouter_2(hp);
}

/*  boutton pour affichier les niveaux des etudiants dans la fenetre tache2  */ 
void
on_hazem_bouton_hk_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
   
GtkWidget *treeview;

treeview=lookup_widget(button,"hazem_treeview2");
 NiveauEtud(treeview);
}

/*  boutton etoile de la fênetre "dashbord" pour deriger vers la fenêtre "Eleve"   */ 
void
on_hazem_bouton_eleve_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowre;
windowre=create_tache2();
gtk_widget_show (windowre);
}

/* bouton "modifier" de la fenêtre "modificion"   */
void
on_hazem_modifer55_clicked             (GtkWidget       *objet_graphique,gpointer  user_data)
{
holybody z;
int xe;


GtkWidget *nom, *prenom, *cin, *role, *email, *mdp,*calanderofthisar;
GtkWidget *jouro;
GtkWidget *moiso;
GtkWidget *annneo;
nom=lookup_widget(objet_graphique,"hazemttds");
prenom=lookup_widget(objet_graphique,"hazemyy");
cin=lookup_widget(objet_graphique,"hazemkh556");
email=lookup_widget(objet_graphique,"hazem77");
mdp=lookup_widget(objet_graphique,"hazemkhttr");
role=lookup_widget(objet_graphique,"hazemcombomodif");
calanderofthisar=lookup_widget(objet_graphique,"calendar1hazem");


if(strcmp("Administrateur",gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)))==0)
strcpy(z.Role,"Administrateur");

else if(strcmp("Direction",gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)))==0)
strcpy(z.Role,"Direction");
else if(strcmp("Technicien",gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)))==0)
strcpy(z.Role,"Technicien");
else if(strcmp("Nutritionniste",gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)))==0)
strcpy(z.Role,"Nutritionniste");
else if(strcmp("AgentFoyer",gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)))==0)
strcpy(z.Role,"AgentFoyer");
else if(strcmp("AgentRestaurant",gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)))==0)
strcpy(z.Role,"AgentRestaurant");
else if(strcmp("Etudiant",gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)))==0)
{
strcpy(z.Role,"Etudiant");


}

gtk_calendar_get_date(GTK_CALENDAR(calanderofthisar),
                          &z.annee,
                          &z.mois,
                          &z.jour);



strcpy(z.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(z.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(z.Cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(z.Email,gtk_entry_get_text(GTK_ENTRY(email)));
strcpy(z.Modps,gtk_entry_get_text(GTK_ENTRY(mdp)));


 if (h==2) 
strcpy(z.sexe,"Homme");
else if(h==1)
strcpy(z.sexe,"Femme");




modifier_reclam(p,z);

}

/*  bouton "ok" de la fenêtre "confirmation"  */
void
on_hazem_confermation_ok_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *hazemconfirmation,*Dashbord;

if (g[0]==1)
supprimer_reclam(p);
else
g[1]=3;


hazemconfirmation = lookup_widget(button,"hazemconfirmation");
gtk_widget_destroy(hazemconfirmation);


}

/*  check button "Yes" de la fenêtre "confirmation" */

void
on_checkbutton1_yessshazem_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
g[0]=1;

}

/*   bouton de "recharger" les textes dans la fenêtre "modification"  */
void
on_hazem_recharger_clicked             (GtkWidget       *objet_graphique,gpointer  user_data)
{



GtkWidget *nom, *prenom, *cin, *role, *email, *mdp,*calanderofthisar;
GtkWidget *jouro;
GtkWidget *moiso;
GtkWidget *annneo;
nom=lookup_widget(objet_graphique,"hazemttds");
prenom=lookup_widget(objet_graphique,"hazemyy");
cin=lookup_widget(objet_graphique,"hazemkh556");
email=lookup_widget(objet_graphique,"hazem77");
mdp=lookup_widget(objet_graphique,"hazemkhttr");
role=lookup_widget(objet_graphique,"hazemcombomodif");

gtk_entry_set_text(GTK_ENTRY(nom),p.nom);
gtk_entry_set_text(GTK_ENTRY(prenom),p.prenom);
gtk_entry_set_text(GTK_ENTRY(cin),p.Cin);
gtk_entry_set_text(GTK_ENTRY(email),p.Email);
gtk_entry_set_text(GTK_ENTRY(mdp),p.Modps);
gtk_entry_set_text(GTK_ENTRY(role),p.Role);






}

/* bouton retour de l'inscription vers l'authentification  */
void
on_button12_retour_kh_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Authentification,*Inscription;
Inscription = lookup_widget(button,"Inscription");
gtk_widget_destroy(Inscription);
Authentification = create_Authentification();
gtk_widget_show(Authentification);

}

int x,y;
void
on_buttonajouter_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *cin,*nom,*prenom,*text,*jour,*mois,*annee;
	reclamation r;
	cin=lookup_widget(objet_graphique,"entrycin");
	nom=lookup_widget(objet_graphique,"entrynom");
	prenom=lookup_widget(objet_graphique,"entryprenom");
	text=lookup_widget(objet_graphique,"entrytext");
	jour=lookup_widget(objet_graphique,"spinbuttonjour");
	mois=lookup_widget(objet_graphique,"spinbuttonmois");
	annee=lookup_widget(objet_graphique,"spinbuttonannee");
	strcpy(r.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
	strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(r.text,gtk_entry_get_text(GTK_ENTRY(text)));
	r.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
	r.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	r.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
	r.etat=x;
	if(y==1 && strlen(r.cin)==8)
	{
		ajouter_reclamation(r);
		y=0;
	}
}


void
on_radiobuttonebergement_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		x=0;

}


void
on_radiobuttonrestoration_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		x=1;
}


void
on_buttonafficher_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *windowajouter,*windowafficher,*treeviewhebergement,*treeviewrestoration;
	windowajouter=lookup_widget(objet_graphique,"windowajouter");
	windowafficher=lookup_widget(objet_graphique,"windowafficher");
	gtk_widget_destroy(windowajouter);
	windowafficher=create_windowafficher();
	gtk_widget_show(windowafficher);
	treeviewhebergement=lookup_widget(windowafficher,"treeviewhebergement");
	treeviewrestoration=lookup_widget(windowafficher,"treeviewrestoration");
	afficher_reclamation(treeviewhebergement,"reclamationH.txt");
	afficher_reclamation(treeviewrestoration,"reclamationR.txt");

}


void
on_treeviewhebergement_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkWidget *dialog1;
	GtkTreeIter iter;
	gchar *cin;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
		gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&cin,-1);
		supprimer_reclamation(cin,"reclamationH.txt");
		afficher_reclamation(treeview,"reclamationH.txt");
		dialog1=create_dialog1_foyer();
		gtk_widget_show(dialog1);
	}

}


void
on_treeviewrestoration_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkWidget *dialog1;
	GtkTreeIter iter;
	gchar *cin;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
		gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&cin,-1);
		supprimer_reclamation(cin,"reclamationR.txt");
		afficher_reclamation(treeview,"reclamationR.txt");
		dialog1=create_dialog1_foyer();
		gtk_widget_show(dialog1);
		
	}
}





void
on_buttongotomodifier_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *windowafficher,*windowajouter,*treeviewhebergement,*treeviewrestoration;
	GtkTreeModel *model;
	GtkTreeSelection *selection1,*selection2;
	GtkTreeIter iter;
	gchar *cin,*nom,*prenom,*text;
	gint jour,mois,annee,etat;
	windowajouter=lookup_widget(objet_graphique,"windowajouter");
	windowafficher=lookup_widget(objet_graphique,"windowafficher");
	treeviewhebergement=lookup_widget(windowafficher,"treeviewhebergement");
	treeviewrestoration=lookup_widget(windowafficher,"treeviewrestoration");
	selection1=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeviewhebergement));
	selection2=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeviewrestoration));
	if(gtk_tree_selection_get_selected(selection1,&model,&iter)){
		gtk_tree_model_get(model,&iter,0,&cin,1,&nom,2,&prenom,3,&text,4,&jour,5,&mois,6,&annee,-1);
		gtk_widget_destroy(windowafficher);
		windowajouter=create_windowajouter();
		gtk_widget_show(windowajouter);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(windowajouter,"entrycin")),cin);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(windowajouter,"entrynom")),nom);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(windowajouter,"entryprenom")),prenom);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(windowajouter,"entrytext")),text);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(windowajouter,"spinbuttonjour")),jour);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(windowajouter,"spinbuttonmois")),mois);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(windowajouter,"spinbuttonannee")),annee);
	}
	else if(gtk_tree_selection_get_selected(selection2,&model,&iter)){
		gtk_tree_model_get(model,&iter,0,&cin,1,&nom,2,&prenom,3,&text,4,&jour,5,&mois,6,&annee,-1);
		gtk_widget_destroy(windowafficher);
		windowajouter=create_windowajouter();
		gtk_widget_show(windowajouter);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(windowajouter,"entrycin")),cin);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(windowajouter,"entrynom")),nom);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(windowajouter,"entryprenom")),prenom);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(windowajouter,"entrytext")),text);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(windowajouter,"spinbuttonjour")),jour);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(windowajouter,"spinbuttonmois")),mois);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(windowajouter,"spinbuttonannee")),annee);
	}
	else{}

}


void
on_buttonreturn_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *windowajouter,*windowafficher;
	windowajouter=lookup_widget(objet_graphique,"windowajouter");
	windowafficher=lookup_widget(objet_graphique,"windowafficher");
	gtk_widget_destroy(windowafficher);
	windowajouter=create_windowajouter();
	gtk_widget_show(windowajouter);

}




void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
		y=1;
	else
		y=0;
   	

}


void
on_buttonrecherche_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *windowafficher,*treeviewhebergement,*treeviewrestoration,*choix,*cin;
	char cin1[30];
	windowafficher=lookup_widget(objet_graphique,"windowafficher");
	choix=lookup_widget(objet_graphique,"comboboxchoix");
	cin=lookup_widget(objet_graphique,"entryrecherche1");
	treeviewhebergement=lookup_widget(windowafficher,"treeviewhebergement");
	treeviewrestoration=lookup_widget(windowafficher,"treeviewrestoration");
	strcpy(cin1,gtk_entry_get_text(GTK_ENTRY(cin)));
	if(strcmp(cin1,"")!=0)
	{
		if(strcmp("Hebergement",gtk_combo_box_get_active_text(GTK_COMBO_BOX(choix)))==0){
			recherche_reclamation(cin1,"reclamationH.txt");
			afficher_reclamation(treeviewhebergement,"recherche.txt");
			remove("recherche.txt");
		}
		else{
			recherche_reclamation(cin1,"reclamationR.txt");
			afficher_reclamation(treeviewrestoration,"recherche.txt");
			remove("recherche.txt");
		}
	}
	else
	{
		afficher_reclamation(treeviewhebergement,"reclamationH.txt");
		afficher_reclamation(treeviewrestoration,"reclamationR.txt");
	}
}


void
on_buttonmodifier_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *cin,*nom,*prenom,*text,*jour,*mois,*annee;
	reclamation r;
	cin=lookup_widget(objet_graphique,"entrycin");
	nom=lookup_widget(objet_graphique,"entrynom");
	prenom=lookup_widget(objet_graphique,"entryprenom");
	text=lookup_widget(objet_graphique,"entrytext");
	jour=lookup_widget(objet_graphique,"spinbuttonjour");
	mois=lookup_widget(objet_graphique,"spinbuttonmois");
	annee=lookup_widget(objet_graphique,"spinbuttonannee");
	strcpy(r.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
	strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(r.text,gtk_entry_get_text(GTK_ENTRY(text)));
	r.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
	r.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	r.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
	r.etat=x;
	if(y==1)
	{
		if(x==1)
		{
			modifier_reclamation(r,"reclamationR.txt");
			y=0;
		}
		else
		{
			modifier_reclamation(r,"reclamationH.txt");
			y=0;
		}
	}
}


void
on_button1serviceplusreclame_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	int r;
	GtkWidget *resultat;
	resultat=lookup_widget(objet_graphique,"label6serviceleplusreclame");
	r=service_le_plus_reclame();
	if(r==1)
		gtk_label_set_text(GTK_LABEL(resultat),"Le service le plus reclame est : Hebergement");
	else
		gtk_label_set_text(GTK_LABEL(resultat),"Le service le plus reclame est : Restauration");
}


void
on_closebutton1_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	gtk_widget_destroy(lookup_widget(objet_graphique,"dialog1_foyer"));
}

produit o;
char tyy[20]="froid";

char tyy1[20]="froid";
int x1=0;int x2=0;
int stq = 1;





void
on_modifier_st_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
gtk_widget_destroy(afiicher_st);
produit p;
FILE *f;
f=fopen("produit.txt","r");
GtkWidget *modifier_st;
  modifier_st = create_modifier_st ();
  gtk_widget_show (modifier_st);
GtkWidget *Mref_st;
Mref_st = lookup_widget (modifier_st ,"Mref_st");
GtkWidget *Mnom_st;
Mnom_st = lookup_widget (modifier_st ,"Mnom_st");
GtkWidget *combobox2_st;
combobox2_st = lookup_widget (modifier_st ,"combobox2_st");
GtkWidget *spinbutton11_st;
spinbutton11_st = lookup_widget (modifier_st ,"spinbutton11_st");
GtkWidget *spinbutton22_st;
spinbutton22_st = lookup_widget (modifier_st ,"spinbutton22_st");

while(fscanf(f,"%s %s %s %d %s %s %d\n",p.ref,p.nom,p.categ,&p.quant,p.type,p.date,&p.poid)!=-1){
 if (strcmp(p.ref,o.ref)==0){
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier_st,"Mref_st")),p.ref);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier_st,"Mnom_st")),p.nom);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier_st,"combobox2_st")),p.categ);
                gtk_range_set_value(GTK_ENTRY(lookup_widget(modifier_st,"spinbutton11_st")),p.quant);
                gtk_range_set_value(GTK_ENTRY(lookup_widget(modifier_st,"spinbutton22_st")),p.poid);

}}
GtkWidget *erreur_nom2,*erreur_ref2,*erreur_conf2;

erreur_nom2=lookup_widget(modifier_st,"erreur_nom2");
erreur_ref2=lookup_widget(modifier_st,"erreur_ref2");
erreur_conf2=lookup_widget(modifier_st,"erreur_conf2");
 
gtk_widget_hide(erreur_nom2);  
gtk_widget_hide(erreur_ref2);  
gtk_widget_hide(erreur_conf2);
}


void
on_ajouter_st_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
gtk_widget_destroy(afiicher_st);
GtkWidget *ajouter_st;
ajouter_st = create_ajouter_st ();
  gtk_widget_show (ajouter_st);


GtkWidget *erreur_nom1,*erreur_ref1,*erreur_categ1,*erreur_conf1;

erreur_nom1=lookup_widget(ajouter_st,"erreur_nom1");
erreur_ref1=lookup_widget(ajouter_st,"erreurref_1");
erreur_categ1=lookup_widget(ajouter_st,"erreur_categ1");
erreur_categ1=lookup_widget(ajouter_st,"erreur_conf1");

gtk_widget_hide(erreur_nom1);  
gtk_widget_hide(erreur_ref1);  
gtk_widget_hide(erreur_categ1);
gtk_widget_hide(erreur_conf1);



}


void
on_actualiser_st_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1_st;
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
treeview1_st=lookup_widget(afiicher_st,"treeview1_st");
afficher_st(treeview1_st);


}


void
on_chercher_st_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cherch;
char ch[20];
GtkWidget *treeview1_st;
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");

treeview1_st=lookup_widget(afiicher_st,"treeview1_st");
cherch = lookup_widget (button ,"entre_rechercher_st");
strcpy(ch, gtk_entry_get_text(GTK_ENTRY(cherch)));
 chercher_st(treeview1_st,ch);
}


void
on_ajouterpr_st_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ref;
GtkWidget *nom;
GtkWidget *categ;
GtkWidget *quant;
GtkWidget *type;

GtkWidget *poid;
GtkWidget *ajouter_st;


produit p;
int aa,mm,jj;
char a[3];
char b[3];
char c[6];
char y[15]="";
int o=0;
ref = lookup_widget (button ,"entryref_st");
nom = lookup_widget (button ,"entrynom_st");
categ = lookup_widget (button ,"combobox1_categorie");
quant = lookup_widget (button ,"spinbutton1_qt_st");
type = lookup_widget (button ,"radiobutton1_fr");
poid = lookup_widget (button ,"spinbutton1_poid");


GtkWidget *erreur_nom1,*erreur_ref1,*erreur_categ1,*erreur_conf1;
ajouter_st=lookup_widget(button,"ajouter_st");
erreur_nom1=lookup_widget(ajouter_st,"erreur_nom1");
erreur_ref1=lookup_widget(ajouter_st,"erreurref_1");
erreur_categ1=lookup_widget(ajouter_st,"erreur_catg1");
erreur_conf1=lookup_widget(ajouter_st,"erreur_conf1");
gtk_widget_hide(erreur_nom1);  
gtk_widget_hide(erreur_ref1);  
gtk_widget_hide(erreur_categ1);

gtk_widget_hide(erreur_conf1);





GtkWidget *calendar;
calendar=lookup_widget(button,"calendar1_st");
gtk_calendar_get_date (GTK_CALENDAR(calendar),
                       &aa,
                       &mm,
                       &jj);
mm=mm+1;


p.quant=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quant));
p.poid=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(poid));

strcpy(p.ref, gtk_entry_get_text(GTK_ENTRY(ref)));
strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p.categ, gtk_combo_box_get_active_text(GTK_COMBO_BOX(categ)));


sprintf(a,"%d",jj);sprintf(b,"%d",mm);sprintf(c,"%d",aa);
strcat(y,c);strcat(y,"-");strcat(y,b);strcat(y,"-");strcat(y,a);


strcpy(p.date,y);
strcpy(p.type,tyy);

if (strcmp(p.ref,"")==0 || id_def(p.ref)==1)
{o=1;
gtk_widget_show(erreur_ref1);
}
else o=0;
 if (strcmp(p.nom,"")==0)
{o=1;
gtk_widget_show(erreur_nom1);
}
else o=0;

 if (x1==0)
{
gtk_widget_show(erreur_conf1);
}
if (strcmp(p.categ,"")==0)
{o=1;
gtk_widget_show(erreur_categ1);
}else o=0;



 if(o==0 && x1==1  && id_def(p.ref)==0){
ajouter_produit(p);



gtk_widget_destroy(ajouter_st);
GtkWidget *afiicher_st;
afiicher_st = create_afiicher_st ();
  gtk_widget_show (afiicher_st);
x1=0;


}

}


void
on_anuulerajout_st_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_st;
ajouter_st=lookup_widget(button,"ajouter_st");
gtk_widget_destroy(ajouter_st);
GtkWidget *afiicher_st;
afiicher_st = create_afiicher_st ();
  gtk_widget_show (afiicher_st);
GtkWidget* resultat_st;

}


void
on_annulersupp_st_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimer_st;
supprimer_st=lookup_widget(button,"supprimer_st");
gtk_widget_destroy(supprimer_st);
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
  gtk_widget_show (afiicher_st);



}


void
on_confirmersupp_st_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
 supprimer_st(o.ref);
GtkWidget *supprimer_st;
supprimer_st=lookup_widget(button,"supprimer_st");
gtk_widget_destroy(supprimer_st);
GtkWidget *afiicher_st;

  gtk_widget_show (afiicher_st);

}


void
on_treeview1_st_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
                                    
{GtkTreeIter iter;
	gchar* ref;
	gchar* nom;
	gchar* categ;
	gchar* type;
	gchar* quant;
	gchar* date;
	gchar* poid;
	

	GtkTreeModel *model =gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{ 
	  gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0 , &ref, 1, &nom,2,&categ,3,&type,4,&quant,5,&date,6,&poid,-1);
	strcpy(o.ref,ref);
	o.quant=atoi(quant); 
	}

}


void
on_supprimer_st_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");

GtkWidget *supprimer_st;
supprimer_st = create_supprimer_st ();
  gtk_widget_show (supprimer_st);
}


void
on_annulerM_st_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifier_st;
modifier_st=lookup_widget(button,"modifier_st");
gtk_widget_destroy(modifier_st);
GtkWidget *afiicher_st;
afiicher_st = create_afiicher_st ();
  gtk_widget_show (afiicher_st);


}


void
on_modifier1_st_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ref;
GtkWidget *nom;
GtkWidget *categ;
GtkWidget *quant;
GtkWidget *type;

GtkWidget *poid;



produit p;
int aa,mm,jj;
char a[3];
char b[3];
char c[6];
char y[15]="";
int x=0;
GtkWidget *modifier_st;
modifier_st=lookup_widget(button,"modifier_st");
ref = lookup_widget (button ,"Mref_st");
nom = lookup_widget (button ,"Mnom_st");
categ = lookup_widget (button ,"combobox2_st");
quant = lookup_widget (button ,"spinbutton11_st");
type = lookup_widget (button ,"radiobutton11_st");
poid = lookup_widget (button ,"spinbutton22_st");

GtkWidget *erreur_nom2,*erreur_ref2,*erreur_conf2,*erreur_categ1;
erreur_categ1=lookup_widget(modifier_st,"erreur_catg2");
erreur_nom2=lookup_widget(modifier_st,"erreur_nom2");
erreur_ref2=lookup_widget(modifier_st,"erreur_ref2");
erreur_conf2=lookup_widget(modifier_st,"erreur_conf2");

 
gtk_widget_hide(erreur_nom2);  
gtk_widget_hide(erreur_ref2);  
gtk_widget_hide(erreur_conf2);
gtk_widget_hide(erreur_categ1);
GtkWidget *calendar;
calendar=lookup_widget(button,"calendar1_dateM");
gtk_calendar_get_date (GTK_CALENDAR(calendar),
                       &aa,
                       &mm,
                       &jj);
mm=mm+1;


p.quant=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quant));
p.poid=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(poid));

strcpy(p.ref, gtk_entry_get_text(GTK_ENTRY(ref)));
strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p.categ, gtk_combo_box_get_active_text(GTK_COMBO_BOX(categ)));


sprintf(a,"%d",jj);sprintf(b,"%d",mm);sprintf(c,"%d",aa);
strcat(y,c);strcat(y,"-");strcat(y,b);strcat(y,"-");strcat(y,a);


strcpy(p.date,y);
strcpy(p.type,tyy1);
if (strcmp(p.ref,"")==0)
{x=1;
gtk_widget_show(erreur_ref2);
}else x=0;
 if (strcmp(p.nom,"")==0)
{x=1;
gtk_widget_show(erreur_nom2);
}else x=0;
if (strcmp(p.categ,"")==0)
{x=1;
gtk_widget_show(erreur_categ1);
}else x=0;

 if (x2==0)
{
gtk_widget_show(erreur_conf2);
}

 if(x==0 && x2 ==1){
modifier_stt(o.ref,p);

gtk_widget_destroy(modifier_st);
GtkWidget *afiicher_st;
afiicher_st = create_afiicher_st ();
  gtk_widget_show (afiicher_st);
x2=0;
}}


void
on_radiobutton1_fr_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tyy,"froid");
}


void
on_radiobutton2_nr_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tyy,"normal");
}


void
on_radiobutton11_st_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tyy1,"froid");
}


void
on_radiobutton22_st_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tyy1,"normal");
}


void
on_checkbutton1_st_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
x1=1;
}


void
on_checkbutton11_st_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
x2=1;
}


void
on_retire_st_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"tache2_stock");

GtkWidget *tache2;
tache2 = create_tache2_stock ();
  gtk_widget_show (tache2);
}


void
on_treeview2_st_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_afficher_tache2_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
int aa,mm,jj;
char a[3];
char b[3];
char c[6];
char y[15]="";
GtkWidget *calendar;
calendar=lookup_widget(button,"calendar3_st");
gtk_calendar_get_date (GTK_CALENDAR(calendar),
                       &aa,
                       &mm,
                       &jj);
mm=mm+1;

sprintf(a,"%d",jj);sprintf(b,"%d",mm);sprintf(c,"%d",aa);
strcat(y,c);strcat(y,"-");strcat(y,b);strcat(y,"-");strcat(y,a);

GtkWidget *treeview2_st;
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
treeview2_st=lookup_widget(afiicher_st,"treeview2_st");
stoq_ep(treeview2_st,y,stq);
}


void
on_confirme_ut_st_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *quant1;
GtkWidget *tache2;
GtkWidget *erreur_qnt;
int x;
int y=0;
int bb=0;
quant1 = lookup_widget (button ,"spinbutton111_st");

tache2=lookup_widget(button,"tache2_stock");

erreur_qnt=lookup_widget(tache2,"erreur_qnt");
y=0;
 
gtk_widget_hide(erreur_qnt);  


x=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quant1));



bb = ret_qp( o);

if (x >bb)
{y=1;
gtk_widget_show(erreur_qnt);
}
if (x <= bb){
utiliser_stt(o.ref,x);

gtk_widget_destroy(tache2);
GtkWidget *afiicher_st;
afiicher_st = create_afiicher_st ();
  gtk_widget_show (afiicher_st);
}



}


void
on_annuler_ut_st_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tache2;
tache2=lookup_widget(button,"tache2_stock");
gtk_widget_destroy(tache2);
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
  gtk_widget_show (afiicher_st);
}


void
on_date_stt_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
stq=1;
}


void
on_stock_stt_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
stq=0;
}


void
on_button3_forget_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{


	
}


int supp;
int payement,payementm;
char refch[10];
void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkWidget *principale;
	
	GtkTreeIter iter;
	gchar *nb;
	gchar *etage;
	
	eheb e;
	
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter, path))
	{
		

		gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&etage,1,&nb,-1);
		
		
		affich(treeview);
}
}


void
on_button_ok_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *classe, *outputMsg;char class[20];
float s=0,i=0;
char text[60];eheb e;
classe = lookup_widget (button,"entry8_agent");
strcpy(class,gtk_entry_get_text(GTK_ENTRY(classe)));
FILE *f=NULL;

f=fopen("fichier.txt","r");
if(f!=NULL){
while(fscanf(f,"%s %s %s %s %s %d %d %d %d\n",e.id,e.nom,e.prenom,e.classe,
e.refch,&e.payement,&e.date_entree.jour,&e.date_entree.mois,&e.date_entree.annee)!=EOF)
{
g_print("%s",e.id);i=i+1;
if(strcmp(e.classe,class)==0)
     s=s+1;}fclose(f);s=(float)s*100/i;sprintf(text, "%.2f", s);strcat(text,"%");
	     outputMsg=lookup_widget(button,("label38_agent"));
	     gtk_label_set_text(GTK_LABEL(outputMsg),text);}
else {outputMsg=lookup_widget(button,("label38_agent"));
	     gtk_label_set_text(GTK_LABEL(outputMsg),"0%");}
}


void
on_button_logout_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_chercher_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *idd, *outputMsg;
char id[20];char ch[10];strcpy(ch," ");
char text[60];
idd = lookup_widget (button,"entry_chercher");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(idd)));
if (chercher_heb(id)==-1){
strcpy (text,"id introuvable");
	     outputMsg=lookup_widget(button,("label36_agent"));
	     gtk_label_set_text(GTK_LABEL(outputMsg),text);
}
else {
FILE *f=NULL;
eheb e;
f=fopen("fichier.txt","r");

while(fscanf(f,"%s %s %s %s %s %d %d %d %d\n",e.id,e.nom,e.prenom,e.classe,
e.refch,&e.payement,&e.date_entree.jour,&e.date_entree.mois,&e.date_entree.annee)!=EOF)
{
if(strcmp(e.id,id)==0)
     {
 strcpy (text,strcat(e.nom,strcat(ch,strcat(e.prenom,strcat(ch,e.classe)))));}}fclose(f);
	     outputMsg=lookup_widget(button,"label36_agent");
	     gtk_label_set_text(GTK_LABEL(outputMsg),text);}

}



void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *principale;
	
	GtkTreeIter iter;
	gchar *nom;
	gchar *prenom;
	gchar *id;
	gchar *classe;
	gchar *refch;
	gint payement;
	gint jour;
	gint mois;	
	gint annee;
	
	eheb e;
	
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter, path))
	{
		

		gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&id,1,&nom,2,&prenom,3,&classe,4,&refch,5,&payement,6,&jour,7,&mois,8,&annee,-1);
		
		strcpy(e.id,id);
		strcpy(e.nom,nom);
		strcpy(e.prenom,prenom);
		strcpy(e.classe,classe);
		strcpy(e.refch,refch);
		e.payement=payement;
		e.date_entree.jour=jour;
		e.date_entree.mois=mois;
		e.date_entree.annee=annee;
		affiche_heb(treeview);
}
}


void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)

{
GtkWidget *treeview,*principale;
principale=lookup_widget(button,"principale");
treeview=lookup_widget(principale,"treeview2_agent");
affiche_heb(treeview);
}



void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button1_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *idd,*nom,*prenom,*classe,*Ajouter,*outputMsg;
Ajouter=lookup_widget(objet_graphique,"Ajouter");
eheb e ;
char id[20];
GtkWidget  *combobox8,*combobox9,*combobox10;
char bloc[10];char etage[10];char num[10];


idd = lookup_widget (objet_graphique,"entry1_agent");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(idd)));
if (chercher_heb(id)==-1)
{
strcpy(e.id,id);
combobox8 = lookup_widget (objet_graphique,"combobox8_agent");
combobox9 = lookup_widget (objet_graphique,"combobox9_agent");
combobox10 = lookup_widget (objet_graphique,"combobox10_agent");
if (strcmp("A",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox8)))==0)
strcpy(bloc,"A");
if (strcmp("B",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox8)))==0)
strcpy(bloc,"B");
if (strcmp("C",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox8)))==0)
strcpy(bloc,"C");

if (strcmp("0",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox9)))==0)
strcpy(etage,"0");
if (strcmp("1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox9)))==0)
strcpy(etage,"1");
if (strcmp("2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox9)))==0)
strcpy(etage,"2");

if (strcmp("1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"1");
if (strcmp("2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"2");
if (strcmp("3",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"3");
if (strcmp("4",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"4");
if (strcmp("5",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"5");
if (strcmp("6",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"6");
if (strcmp("7",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"7");
if (strcmp("8",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"8");
strcpy(e.refch,strcat(strcat(bloc,etage),num));

nom = lookup_widget (objet_graphique,"entry2_agent");
prenom = lookup_widget (objet_graphique,"entry3_agent");
classe= lookup_widget (objet_graphique,"entry7_agent");


strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(e.classe,gtk_entry_get_text(GTK_ENTRY(classe)));


GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;

jour=lookup_widget(objet_graphique,"spinbutton1_agent");
mois=lookup_widget(objet_graphique,"spinbutton2_agent");
annee=lookup_widget(objet_graphique,"spinbutton3_agent");

e.date_entree.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
e.date_entree.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois));
e.date_entree.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
e.payement=payement;
if ((nbres(refch)==0||nbres(refch)==1))
 { ajouter_heb(e);
	     outputMsg=lookup_widget(objet_graphique,("label30_agent"));
	     gtk_label_set_text(GTK_LABEL(outputMsg),"ajout reussi");}
else {outputMsg=lookup_widget(objet_graphique,("label30_agent"));
	     gtk_label_set_text(GTK_LABEL(outputMsg),"ressayer");}}
else {outputMsg=lookup_widget(objet_graphique,("label30_agent"));
	     gtk_label_set_text(GTK_LABEL(outputMsg),"ressayer");
}
}





void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)));
payement=1;
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
payement=2;
}


void
on_buttonV_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget  *combobox8,*combobox9,*combobox10,*id,*outputMsg;
char bloc[10];char etage[10];char num[10];
char ref[10];
char text[20];
id = lookup_widget (objet_graphique,"entry10_agent");
combobox8 = lookup_widget (objet_graphique,"combobox8_agent");
combobox9 = lookup_widget (objet_graphique,"combobox9_agent");
combobox10 = lookup_widget (objet_graphique,"combobox10_agent");
if (strcmp("A",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox8)))==0)
strcpy(bloc,"A");
if (strcmp("B",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox8)))==0)
strcpy(bloc,"B");
if (strcmp("C",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox8)))==0)
strcpy(bloc,"C");

if (strcmp("0",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox9)))==0)
strcpy(etage,"0");
if (strcmp("1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox9)))==0)
strcpy(etage,"1");
if (strcmp("2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox9)))==0)
strcpy(etage,"2");

if (strcmp("1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"1");
if (strcmp("2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"2");
if (strcmp("3",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"3");
if (strcmp("4",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"4");
if (strcmp("5",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"5");
if (strcmp("6",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"6");
if (strcmp("7",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"7");
if (strcmp("8",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"8");
strcpy(ref,strcat(strcat(bloc,etage),num));
strcpy(refch,ref);
eheb x;
FILE*f=NULL;
char refchh[10];

f=fopen("fichier.txt","r");

while(fscanf(f,"%s %s %s %s %s %d %d %d %d\n",x.id,x.nom,x.prenom,x.classe,
x.refch,&x.payement,&x.date_entree.jour,&x.date_entree.mois,&x.date_entree.annee)!=EOF){

if( strcmp(x.id,gtk_entry_get_text(GTK_ENTRY(id)))==0    )
strcpy(refchh,x.refch);

}
fclose(f);

if ((nbres(ref)<2)||(strcmp(ref,refchh)==0)){
strcpy (text,"disponible");
	     outputMsg=lookup_widget(objet_graphique,("label29_agent"));
	     gtk_label_set_text(GTK_LABEL(outputMsg),text);
}
else { strcpy (text,"non disponible");
	     outputMsg=lookup_widget(objet_graphique,("label29_agent"));
	     gtk_label_set_text(GTK_LABEL(outputMsg),text);}
}


void
on_buttonVV_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *idd, *outputMsg;
char id[20];
char text[20];
idd = lookup_widget (objet_graphique,"entry1_agent");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(idd)));
if (chercher_heb(id)==-1){
strcpy (text,"acceptable");
	     outputMsg=lookup_widget(objet_graphique,("labelv"));
	     gtk_label_set_text(GTK_LABEL(outputMsg),text);
}
else { strcpy (text,"non acceptable");
	     outputMsg=lookup_widget(objet_graphique,("labelv"));
	     gtk_label_set_text(GTK_LABEL(outputMsg),text);}
}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *idd,*nom,*prenom,*classe,*modifier,*outputMsg;
modifier=lookup_widget(button,"modifier");
eheb e ;
char id[20];char text[100];
GtkWidget  *combobox8,*combobox9,*combobox10;
char bloc[10];char etage[10];char num[10];


idd = lookup_widget (button,"entry10_agent");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(idd)));
if (chercher_heb(id)!=-1)
{
strcpy(e.id,id);
combobox8 = lookup_widget (button,"combobox15_agent");
combobox9 = lookup_widget (button,"combobox16_agent");
combobox10 = lookup_widget (button,"combobox14_agent");
if (strcmp("A",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox8)))==0)
strcpy(bloc,"A");
if (strcmp("B",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox8)))==0)
strcpy(bloc,"B");
if (strcmp("C",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox8)))==0)
strcpy(bloc,"C");

if (strcmp("0",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox9)))==0)
strcpy(etage,"0");
if (strcmp("1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox9)))==0)
strcpy(etage,"1");
if (strcmp("2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox9)))==0)
strcpy(etage,"2");

if (strcmp("1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"1");
if (strcmp("2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"2");
if (strcmp("3",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"3");
if (strcmp("4",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"4");
if (strcmp("5",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"5");
if (strcmp("6",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"6");
if (strcmp("7",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"7");
if (strcmp("8",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"8");
strcpy(e.refch,strcat(strcat(bloc,etage),num));

nom = lookup_widget (button,"entry5_agent");
prenom = lookup_widget (button,"entry6_agent");
classe= lookup_widget (button,"entry9_agent");


strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(e.classe,gtk_entry_get_text(GTK_ENTRY(classe)));


GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;

jour=lookup_widget(button,"spinbutton4_agent");
mois=lookup_widget(button,"spinbutton5_agent");
annee=lookup_widget(button,"spinbutton6_agent");

e.date_entree.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
e.date_entree.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois));
e.date_entree.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
e.payement=payementm;
eheb x;
FILE*f=NULL;

char refchh[10];

f=fopen("fichier.txt","r");


while(fscanf(f,"%s %s %s %s %s %d %d %d %d\n",x.id,x.nom,x.prenom,x.classe,
x.refch,&x.payement,&x.date_entree.jour,&x.date_entree.mois,&x.date_entree.annee)!=EOF){

if( strcmp(x.id,e.id)==0    )

strcpy(refchh,x.refch);
}
fclose(f);

if ((strcmp(refchh,e.refch)==0)||(nbres(e.refch)<2)){
 modifier_heb(e);
	   
outputMsg=lookup_widget(button,("label34_agent"));
	     gtk_label_set_text(GTK_LABEL(outputMsg),"modification faite");}
else {outputMsg=lookup_widget(button,("label34_agent"));
	     gtk_label_set_text(GTK_LABEL(outputMsg),"ressayer");}}
else {outputMsg=lookup_widget(button,("label34_agent"));
	     gtk_label_set_text(GTK_LABEL(outputMsg),"ressayer");
}
}


void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}



void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *idd, *outputMsg;
char id[20];
char text[30];
idd = lookup_widget (button,"entry11_agent");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(idd)));
if (chercher_heb(id)==-1){
strcpy (text,"id introuvable");
	     outputMsg=lookup_widget(button,("label39_agent"));
	     gtk_label_set_text(GTK_LABEL(outputMsg),text);
}
else {if(supp==1){supprimer_heb(id);
 strcpy (text,"suppression avec succes");
	     outputMsg=lookup_widget(button,"label39_agent");
	     gtk_label_set_text(GTK_LABEL(outputMsg),text);}}

}


void
on_checkbutton1_agent_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
supp=1;
}


void
on_checkbutton2_agent_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
supp=0;
}


void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *combobox8,*combobox9,*combobox10,*outputMsg;
char bloc[10];char etage[10];char num[10];
char ref[10];
char text[20];
combobox8 = lookup_widget (button,"combobox15_agent");
combobox9 = lookup_widget (button,"combobox16_agent");
combobox10 = lookup_widget (button,"combobox14_agent");
if (strcmp("A",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox8)))==0)
strcpy(bloc,"A");
if (strcmp("B",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox8)))==0)
strcpy(bloc,"B");
if (strcmp("C",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox8)))==0)
strcpy(bloc,"C");

if (strcmp("0",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox9)))==0)
strcpy(etage,"0");
if (strcmp("1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox9)))==0)
strcpy(etage,"1");
if (strcmp("2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox9)))==0)
strcpy(etage,"2");

if (strcmp("1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"1");
if (strcmp("2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"2");
if (strcmp("3",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"3");
if (strcmp("4",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"4");
if (strcmp("5",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"5");
if (strcmp("6",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"6");
if (strcmp("7",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"7");
if (strcmp("8",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)))==0)
strcpy(num,"8");
strcpy(ref,strcat(strcat(bloc,etage),num));
strcpy(refch,ref);
if (nbres(ref)==0||nbres(ref)==1){
strcpy (text,"disponible");
	     outputMsg=lookup_widget(button,("label41_agent"));
	     gtk_label_set_text(GTK_LABEL(outputMsg),text);
}
else { strcpy (text,"non disponible");
	     outputMsg=lookup_widget(button,("label41_agent"));
	     gtk_label_set_text(GTK_LABEL(outputMsg),text);}
}


void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *idd, *outputMsg;
char id[20];
char text[20];
idd = lookup_widget (button,"entry10_agent");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(idd)));
if (chercher_heb(id)==-1){
strcpy (text,"n'existe pas");
	     outputMsg=lookup_widget(button,("label40_agent"));
	     gtk_label_set_text(GTK_LABEL(outputMsg),text);
}
else { strcpy (text,"ok");
	     outputMsg=lookup_widget(button,("label40_agent"));
	     gtk_label_set_text(GTK_LABEL(outputMsg),text);}
}


void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview,*principale;
principale=lookup_widget(button,"principale");
treeview=lookup_widget(principale,"treeview1_agent");
affich_f(treeview);
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)));
payementm=2;
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)));
payementm=1;
}


void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkNotebook   *notebook1;
	GtkWidget *entryid; 
entryid=lookup_widget(button,"entry11_agent");

	GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p;

	gchar *id ;
	
        p=lookup_widget(button,"treeview2_agent");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);

gtk_entry_set_text (GTK_ENTRY(entryid),id);
      	
 //gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
notebook1=(GTK_NOTEBOOK(lookup_widget(button,"notebook2_agent")));
gint page = gtk_notebook_get_current_page (notebook1);
gtk_notebook_set_current_page (notebook1, 3);
}
}



void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkNotebook   *notebook1;
	GtkWidget *entryid; GtkWidget *entrynom; GtkWidget *entryprenom;
	GtkWidget *entryclasse; GtkWidget *combobox8;GtkWidget *combobox9;GtkWidget *combobox10;GtkWidget *entryjour;GtkWidget *entrymois;GtkWidget *entryannee;  GtkWidget *entrypayement;
entryid=lookup_widget(button,"entry10_agent");
entrynom=lookup_widget(button,"entry5_agent"); 
entryprenom=lookup_widget(button,"entry6_agent");
entryclasse=lookup_widget(button,"entry9_agent");
combobox10=lookup_widget(button,"combobox14_agent");
combobox8=lookup_widget(button,"combobox15_agent");
combobox9=lookup_widget(button,"combobox16_agent");
	GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p;

	gchar *id ;
	gchar *nom ;
	gchar *prenom;
	gchar *classe ;
	gchar *refch;
	gint *jour;
	gint *mois;
	gint *annee;
	gint *payement;
        p=lookup_widget(button,"treeview2_agent");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,1,&nom,2,&prenom,3,&classe,4,&refch,5,&jour,6,&mois,7,&annee,8,payement,-1);

gtk_entry_set_text (GTK_ENTRY(entryid),id);
gtk_entry_set_text (GTK_ENTRY(entrynom),nom);
gtk_entry_set_text (GTK_ENTRY(entryprenom),prenom);
gtk_entry_set_text (GTK_ENTRY(entryclasse),classe);
if ('A'==refch[0])
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox8),0);
if ('B'==refch[0])
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox8),1);
if ('C'==refch[0])
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox8),2);
if ('0'==refch[1])
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox9),0);
if ('1'==refch[1])
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox9),1);
if ('2'==refch[1])
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox9),2);

 if ('1'==refch[2])
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox10),0);
 if ('2'==refch[2])
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox10),1);
 if ('3'==refch[2])
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox10),2);
 if ('4'==refch[2])
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox10),3);
 if ('5'==refch[2])
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox10),4);
 if ('6'==refch[2])
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox10),5);
 if ('7'==refch[2])
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox10),6);
 if ('8'==refch[2])
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox10),7);

          	
 //gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
notebook1=(GTK_NOTEBOOK(lookup_widget(button,"notebook2_agent")));
gint page = gtk_notebook_get_current_page (notebook1);
gtk_notebook_set_current_page (notebook1, 2);
}
}


void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(button,"notebook2_agent")));
}


void
on_button13_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkNotebook   *notebook1;

      	
 //gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
notebook1=(GTK_NOTEBOOK(lookup_widget(button,"notebook2_agent")));
gint page = gtk_notebook_get_current_page (notebook1);
gtk_notebook_set_current_page (notebook1, 0);

}


void
on_button14_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkNotebook   *notebook1;

      	
 //gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
notebook1=(GTK_NOTEBOOK(lookup_widget(button,"notebook2_agent")));
gint page = gtk_notebook_get_current_page (notebook1);
gtk_notebook_set_current_page (notebook1, 0);
}


void
on_button15_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkNotebook   *notebook1;

      	
 //gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
notebook1=(GTK_NOTEBOOK(lookup_widget(button,"notebook2_agent")));
gint page = gtk_notebook_get_current_page (notebook1);
gtk_notebook_set_current_page (notebook1, 0);
}


int e=1;
void
on_list_menu_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu, *dashboard;

dashboard=lookup_widget(objet,"dashboard");

//gtk_widget_destroy(menu);
dashboard=create_dashboard();
gtk_widget_show(dashboard);
}


void
on_din_menu_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu, *dinnee;

menu=lookup_widget(objet,"menu");

//gtk_widget_destroy(menu);
dinnee=create_dinnee();
gtk_widget_show(dinnee);
}


void
on_pti_dej_menu_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu, *petit_dej;

menu=lookup_widget(objet,"menu");

//gtk_widget_destroy(menu);
petit_dej=create_petit_dej();
gtk_widget_show(petit_dej);
}


void
on_dej_menu_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu, *dejeune;

menu=lookup_widget(objet,"menu");

//gtk_widget_destroy(menu);
dejeune=create_dejeune();
gtk_widget_show(dejeune);
}


void
on_add_pti_dej_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{

char sj [100];
char sm [100];
char sa [100];
char dt [100];
int j;
int m;
int n;

GtkWidget *input_cafe, *input_viennoiserie, *input_jus, *input_jour, *input_mois, *input_annee ;
GtkWidget *petit_dej;

pdej p;

petit_dej=lookup_widget(objet,"petit_dej");

input_cafe=lookup_widget(objet,"entry_cafe");
input_viennoiserie=lookup_widget(objet,"entry_vin");
input_jus=lookup_widget(objet,"entry_jus");
input_jour=lookup_widget(objet,"pti_dej_jour");
input_mois=lookup_widget(objet,"pti_dej_mois");
input_annee=lookup_widget(objet,"pti_dej_annee");

strcpy(p.cafe,gtk_entry_get_text(GTK_ENTRY(input_cafe)));
strcpy(p.viennoiserie,gtk_entry_get_text(GTK_ENTRY(input_viennoiserie)));
strcpy(p.jus,gtk_entry_get_text(GTK_ENTRY(input_jus)));

j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input_jour));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input_mois));
n=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input_annee));

sprintf(sj,"%d",j);
sprintf(sm,"%d",m);
sprintf(sa,"%d",n);
strcat(sj,"/");
strcat(sm,"/");
strcat(sm,sa);
strcat(sj,sm);
strcpy(dt,sj);

strcpy(p.date,dt);
ajouter_pdej ("petit_dej.txt",p);


GtkWidget *add_succe;
add_succe = create_add_succe ();
gtk_widget_show (add_succe);
}


void
on_add_dej_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

char sj [100];
char sm [100];
char sa [100];
char dt [100];
int j;
int m;
int n;

GtkWidget *input_entree, *input_plat_p, *input_dessert, *input_jour, *input_mois, *input_annee ;
GtkWidget *dejeune;

dej dj;

dejeune=lookup_widget(objet,"dejeune");

input_plat_p=lookup_widget(objet,"entry_plat_dej");
input_entree=lookup_widget(objet,"entry_entree_dej");
input_dessert=lookup_widget(objet,"combo_dessert_dej");
input_jour=lookup_widget(objet,"dej_jour");
input_mois=lookup_widget(objet,"dej_mois");
input_annee=lookup_widget(objet,"dej_annee");

strcpy(dj.dj_plat_p,gtk_entry_get_text(GTK_ENTRY(input_plat_p)));
strcpy(dj.dj_entree,gtk_entry_get_text(GTK_ENTRY(input_entree)));
strcpy(dj.dj_dessert,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input_dessert)));


j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input_jour));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input_mois));
n=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input_annee));


sprintf(sj,"%d",j);
sprintf(sm,"%d",m);
sprintf(sa,"%d",n);
strcat(sj,"/");
strcat(sm,"/");
strcat(sm,sa);
strcat(sj,sm);
strcpy(dt,sj);

strcpy(dj.date,dt);
ajouter_dej ("dej.txt",dj);


GtkWidget *add_succe;
add_succe = create_add_succe ();
gtk_widget_show (add_succe);
}


void
on_radio_avec_regime_dej_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radio_sans_regime_dej_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_check_sans_regime_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_add_dinnee_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{

char sj [100];
char sm [100];
char sa [100];
char dt [100];
int j;
int m;
int n;

GtkWidget *input_entree_din, *input_plat_p_din, *input_dessert_din, *input_jour_din, *input_mois_din, *input_annee_din ;
GtkWidget *dejeune;

din dn;

dejeune=lookup_widget(objet,"dejeune");

input_plat_p_din=lookup_widget(objet,"entry_plat_din");
input_entree_din=lookup_widget(objet,"entry_entree_din");
input_dessert_din=lookup_widget(objet,"combo_dessert_din");
input_jour_din=lookup_widget(objet,"din_jour");
input_mois_din=lookup_widget(objet,"din_mois");
input_annee_din=lookup_widget(objet,"din_annee");


strcpy(dn.dn_plat_p,gtk_entry_get_text(GTK_ENTRY(input_plat_p_din)));
strcpy(dn.dn_entree,gtk_entry_get_text(GTK_ENTRY(input_entree_din)));
strcpy(dn.dn_dessert,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input_dessert_din)));


j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input_jour_din));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input_mois_din));
n=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input_annee_din));


sprintf(sj,"%d",j);
sprintf(sm,"%d",m);
sprintf(sa,"%d",n);
strcat(sj,"/");
strcat(sm,"/");
strcat(sm,sa);
strcat(sj,sm);
strcpy(dt,sj);

strcpy(dn.date,dt);
ajouter_din ("din.txt",dn);


GtkWidget *add_succe;
add_succe = create_add_succe ();
gtk_widget_show (add_succe);
}


void
on_check_avec_regime_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}

pdej p2;


dej dj;
void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

	GtkTreeIter iter;
	gchar* dj_entree;
	gchar* dj_plat_p;
	gchar* dj_dessert;
	gchar* date;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0, &dj_entree,1, &dj_plat_p,2,&dj_dessert,3,&date,-1);
//copie des valeurs dans la variable P de type personne pour le passer  à la fonction de suppression
		strcpy(dj.dj_entree,dj_entree);
		strcpy(dj.dj_plat_p,dj_plat_p);
		strcpy(dj.dj_dessert,dj_dessert);
		strcpy(dj.date,date);
}
}

din dn;
void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* dn_entree;
	gchar* dn_plat_p;
	gchar* dn_dessert;
	gchar* date;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0, &dn_entree,1, &dn_plat_p,2,&dn_dessert,3,&date,-1);
//copie des valeurs dans la variable P de type personne pour le passer  à la fonction de suppression
		strcpy(dn.dn_entree,dn_entree);
		strcpy(dn.dn_plat_p,dn_plat_p);
		strcpy(dn.dn_dessert,dn_dessert);
		strcpy(dn.date,date);
}
}


void
on_F5_clicked                          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *dashboard;
GtkWidget *treeview1, *treeview4, *treeview3;
dashboard = lookup_widget(objet,"dashboard");
gtk_widget_destroy(dashboard);
dashboard=create_dashboard ();
gtk_widget_show (dashboard);
treeview1 = lookup_widget(dashboard,"treeview1");
treeview4 = lookup_widget(dashboard,"treeview4_nutris");
treeview3 = lookup_widget(dashboard,"treeview3_nutris");
afficher_peti_dej("petit_dej.txt",treeview1);
afficher_dej("dej.txt",treeview3);
afficher_din("din.txt",treeview4);
}


void
on_modif_menu_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *dashboard, *sr_Modification;

dashboard=lookup_widget(objet_graphique,"dashboard");

sr_Modification=create_sr_Modification();
gtk_widget_show(sr_Modification);
}


void
on_rech_edit_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input_sarra;
GtkWidget* input_jour;
GtkWidget* input_mois;
GtkWidget* input_annee;

	char cafe[30];
	char viennoiserie[30];
	char jus[30];
	int j;
	int m;
	char sj [100];
	char sm [100];
	char date[100];
	char sarra[30];

GtkWidget	*input_cafe		=	lookup_widget(objet,"entry2_nutris");
GtkWidget	*input_viennoiserie	=	lookup_widget(objet,"entry3_nutris");
GtkWidget	*input_jus		=	lookup_widget(objet,"entry4_nutris");
/**---------------------------------------------------------------**/
	char dj_entree[30];
	char dj_plat_p[30];
	char dj_dessert[30];
GtkWidget	*input_entree	=	lookup_widget(objet,"entry2_nutris");
GtkWidget	*input_plat_p	=	lookup_widget(objet,"entry3_nutris");
GtkWidget	*input_dessert	=	lookup_widget(objet,"entry4_nutris");
/**------------------------------------------------------------------**/
	char dn_entree[30];
	char dn_plat_p[30];
	char dn_dessert[30];
GtkWidget	*input_dn_entree	=	lookup_widget(objet,"entry2_nutris");
GtkWidget	*input_dn_plat_p	=	lookup_widget(objet,"entry3_nutris");
GtkWidget	*input_dn_dessert	=	lookup_widget(objet,"entry4_nutris");



input_sarra=lookup_widget(objet,"comboboxentry1_nutris");

char nom[20];
GtkWidget	*input		=	lookup_widget(objet,"entry1_nutris");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));

int a=0;
/**----------------------------------------------------------------------**/

if (strcmp(strcpy(sarra,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input_sarra))),"Petit_dej")==0)
{
a=recherche_pdej(nom);
if (a==-1)
{
GtkWidget *add_succe;
add_succe = create_add_succe ();
gtk_widget_show (add_succe);
}
else 
{
modif_pdej(a,cafe,viennoiserie,jus,date);
gtk_entry_set_text (GTK_ENTRY(input_cafe),cafe);
gtk_entry_set_text (GTK_ENTRY(input_viennoiserie),viennoiserie);
gtk_entry_set_text (GTK_ENTRY(input_jus),jus);
}
}
/**----------------------------------------------------------------------**/
else if (strcmp(strcpy(sarra,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input_sarra))),"Dejeune")==0)
{
a=recherche_dej(nom);
if (a==-1)
{
GtkWidget *add_succe;
add_succe = create_add_succe ();
gtk_widget_show (add_succe);
}
else 
{
modif_dej(a,dj_entree,dj_plat_p,dj_dessert,date);
gtk_entry_set_text (GTK_ENTRY(input_entree),dj_entree);
gtk_entry_set_text (GTK_ENTRY(input_plat_p),dj_plat_p);
gtk_entry_set_text (GTK_ENTRY(input_dessert),dj_dessert);
}
}
/**----------------------------------------------------------------------**/
else if (strcmp(strcpy(sarra,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input_sarra))),"Dinnee")==0)
{
a=recherche_din(nom);
if (a==-1)
{
GtkWidget *add_succe;
add_succe = create_add_succe ();
gtk_widget_show (add_succe);
}
else 
{
modif_din(a,dn_entree,dn_plat_p,dn_dessert,date);
gtk_entry_set_text (GTK_ENTRY(input_dn_entree),dn_entree);
gtk_entry_set_text (GTK_ENTRY(input_dn_plat_p),dn_plat_p);
gtk_entry_set_text (GTK_ENTRY(input_dn_dessert),dn_dessert);
}
}
}

void
on_modif_clicked                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
calander c;
pdej p;
GtkWidget* input2;
GtkWidget* input3;
GtkWidget* input4;
GtkWidget* input_jour;
GtkWidget* input_mois;
GtkWidget* input_annee;
GtkWidget* calander_sarra;

calander_sarra=lookup_widget(objet_graphique,"calendar_sarra");
input2= lookup_widget(objet_graphique, "entry2_nutris");
input3= lookup_widget(objet_graphique, "entry3_nutris");
input4= lookup_widget(objet_graphique, "entry4_nutris");
/**----------------------------------------------------------------**/

input_jour= lookup_widget(objet_graphique, "sp_j");
input_mois= lookup_widget(objet_graphique, "sp_m");
input_annee= lookup_widget(objet_graphique, "sp_a");
char v [100];
char jus [100];
char cafe [100];
int j ;
int m;
int a;
char sc [100];
char sj [100];
char sm [100];
char sa [100];
char date [100];

strcpy(cafe,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(v,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(jus,gtk_entry_get_text(GTK_ENTRY(input4)));
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input_jour));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input_mois));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input_annee));

pdej pjn;
strcpy(pjn.cafe,cafe);
strcpy(pjn.viennoiserie,v);
strcpy(pjn.jus,jus);

gtk_calendar_get_date(GTK_CALENDAR(calander_sarra),
                          &c.a,
                          &c.m,
                          &c.j);  // copier le jour / mois / annee


c.m=c.m+1;
sprintf(sj,"%d",c.j);
sprintf(sm,"%d",c.m);
sprintf(sa,"%d",c.a);
strcat(sj,"/");
strcat(sm,"/");
strcat(sm,sa);
strcat(sj,sm+1);
strcpy(date,sj);
strcpy(pjn.date,date);
modifier("petit_dej.txt",pjn.cafe,pjn);

/*---------------------------------------------*/
/*-----------------------------------------------*/
GtkWidget *pInfo2;
pInfo2=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nmodifier ce menu?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo2)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(pInfo2);


/*---------------------------------------------*/
dej djn;
dej dj;

strcpy(cafe,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(v,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(jus,gtk_entry_get_text(GTK_ENTRY(input4)));


strcpy(djn.dj_entree,cafe);
strcpy(djn.dj_plat_p,v);
strcpy(djn.dj_dessert,jus);


gtk_calendar_get_date(GTK_CALENDAR(calander_sarra),
                          &c.a,
                          &c.m,
                          &c.j);  // copier le jour / mois / annee
c.m=c.m+1;
sprintf(sj,"%d",c.j);
sprintf(sm,"%d",c.m);
sprintf(sa,"%d",c.a);
strcat(sj,"/");
strcat(sm,"/");
strcat(sm,sa);
strcat(sj,sm);
strcpy(date,sj);
strcpy(djn.date,date);

modifier_dej("dej.txt",djn.dj_entree,djn);

/*--------------------------------------------------*/
din dnn;
din dn;

strcpy(cafe,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(v,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(jus,gtk_entry_get_text(GTK_ENTRY(input4)));


strcpy(dnn.dn_entree,cafe);
strcpy(dnn.dn_plat_p,v);
strcpy(dnn.dn_dessert,jus);

gtk_calendar_get_date(GTK_CALENDAR(calander_sarra),
                          &c.a,
                          &c.m,
                          &c.j);  // copier le jour / mois / annee

c.m=c.m+1;
sprintf(sj,"%d",c.j);
sprintf(sm,"%d",c.m);
sprintf(sa,"%d",c.a);
strcat(sj,"/");
strcat(sm,"/");
strcat(sm,sa);
strcat(sj,sm);
strcpy(date,sj);
strcpy(dnn.date,date);

modifier_din("din.txt",dnn.dn_entree,dnn);

        break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pInfo2);
	break;
}
}



void
on_supprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *confirm, *dashboard;

dashboard=lookup_widget(objet,"dashboard");

confirm=create_confirm_supp();
gtk_widget_show(confirm);
}


void
on_s_back_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *dashboard, *sr_Modification;

sr_Modification=lookup_widget(objet,"sr_Modification");

gtk_widget_destroy(sr_Modification);
}

int g[2];
void
on_sr_edit_valid_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
if (g[0]==1)
{
supprimer_pdej("petit_dej.txt",p2.cafe);
supprimer_dej ("dej.txt" ,dj.dj_entree);
supprimer_din ("din.txt" ,dn.dn_entree);

GtkWidget *confirm_supp;
confirm_supp=lookup_widget(objet,"confirm_supp");
gtk_widget_destroy(confirm_supp);
}
if (g[1]==3)
{
GtkWidget *confirm_supp;
confirm_supp=lookup_widget(objet,"confirm_supp");
gtk_widget_destroy(confirm_supp);
}
}


void
on_check_edit_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
g[0]=1;
}


void
on_check_annuler_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
g[1]=3;
}


void
on_ss_best_menu_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *dialog, *meilleur_menu;
  dialog = gtk_message_dialog_new(GTK_WINDOW(meilleur_menu),
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_WARNING,
            GTK_BUTTONS_OK,
            "Unallowed operation");
  gtk_window_set_title(GTK_WINDOW(dialog), "Warning");
  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
}


void
on_ss_best_menu_w_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *dashboard, *meilleur_menu;

dashboard=lookup_widget(objet,"dashboard");

meilleur_menu=create_meilleur_menu();
gtk_widget_show(meilleur_menu);
}




void
on_treeview1_nutris_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* cafe;
	gchar* viennoiserie;
	gchar* jus;
	gchar* date;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0, &cafe,1, &viennoiserie,2,&jus,3,&date,-1);
//copie des valeurs dans la variable P de type personne pour le passer  à la fonction de suppression
		strcpy(p2.cafe,cafe);
		strcpy(p2.viennoiserie,viennoiserie);
		strcpy(p2.jus,jus);
		strcpy(p2.date,date);
}
}




void
on_liste_alarme_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
     GtkWidget *home,*listedesalarmes;
    home=lookup_widget(objet,"home");
    gtk_widget_destroy(home);
    listedesalarmes=create_listedesalarmes();
    gtk_widget_show(listedesalarmes);
}


void
on_capteurgestion_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *home,*gestioncapteur;
    home=lookup_widget(objet,"home");
    gtk_widget_destroy(home);
    gestioncapteur=create_gestioncapteur();
    gtk_widget_show(gestioncapteur);
}


void
on_capteur_defect_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *home,*capteursdefect;
    home=lookup_widget(objet,"home");
    gtk_widget_destroy(home);
    capteursdefect=create_capteursdefect();
    gtk_widget_show(capteursdefect);
}


void
on_dk_butt_aj_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(objet,"notebook1_capteur")));
}


void
on_dk_butt_mod_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{  GtkNotebook   *notebook1 ;
	GtkWidget *entryref; GtkWidget *entrymarque; GtkWidget *entryval;
	GtkWidget *entrymin; GtkWidget *entrymax;  GtkWidget *entrytype;
entryref=lookup_widget(objet,"entryrefmo");
entrymarque=lookup_widget(objet,"entrymarquemo"); 
entryval=lookup_widget(objet,"entryvalmo");
entrymin=lookup_widget(objet,"entryminmo");
entrymax=lookup_widget(objet,"entrymaxmo");
entrytype=lookup_widget(objet,"comboboxtypemo");

	GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p;

	gchar *reference  ;
	gchar *marque ;
	gchar *type;
	gchar *valeur ;
	gchar *valeur_min ;
	gchar *valeur_max ;
	char ref [50] ;	
        p=lookup_widget(objet,"treeview1_capteur");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&reference,1,&marque,2,&type,3,&valeur,4,&valeur_min,5,&valeur_max,-1);
strcpy(ref,reference);
gtk_entry_set_text (GTK_ENTRY(entryref),reference);
gtk_entry_set_text (GTK_ENTRY(entrymarque),marque);
gtk_entry_set_text (GTK_ENTRY(entryval),valeur);
gtk_entry_set_text (GTK_ENTRY(entrymin),valeur_min);
gtk_entry_set_text (GTK_ENTRY(entrymax),valeur_max);
if (strcmp(type,"Temperature")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(entrytype),0);
}
if (strcmp(type,"Debit")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(entrytype),1);
}if (strcmp(type,"Dechet")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(entrytype),2);
}if (strcmp(type,"Fumee")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(entrytype),3);
}if (strcmp(type,"Mouvement")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(entrytype),4);
}
notebook1=(GTK_NOTEBOOK(lookup_widget(objet,"notebook1_capteur")));
gint page = gtk_notebook_get_current_page (notebook1);
gtk_notebook_set_current_page (notebook1, 2);
}
}


void
on_dk_butt_aff_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestioncapteur;
	GtkWidget *treeview1;
	gestioncapteur=lookup_widget(objet,"gestioncapteur");
	treeview1=lookup_widget(gestioncapteur,"treeview1_capteur");
	vider(treeview1);
	Afficher(treeview1,"capteurs.txt");
         
}


void
on_dk_butt_quit_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
    window1=lookup_widget(objet,"gestioncapteur");
    gtk_widget_destroy(window1);
    window2=create_home();
    gtk_widget_show(window2);
}


void
on_dk_butt_rech1_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{       capteur c ;
        GtkWidget *refe;
	GtkWidget *mess;
	GtkWidget *treeview1;
	
	char ref[50];
	mess=lookup_widget(objet,"label51dk");
	refe=lookup_widget (objet,"entryrechtb");
	strcpy(ref, gtk_entry_get_text(GTK_ENTRY(refe)));
	//strcpy(c.type, gtk_entry_get_text(GTK_ENTRY(refe)));
	if(existm(ref)==0){
     gtk_label_set_text(GTK_LABEL(mess),"non trouver");}
else {gtk_label_set_text(GTK_LABEL(mess),"trouve");}
chercher_capteur(ref);
treeview1=lookup_widget(objet,"treeview1_capteur");
Afficher(treeview1,"old.txt");
}



////////////////////////////////

void
on_dk_valideraj_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{  
 capteur c ; 
char ref[50];
char place [50];
	GtkWidget *entryref;
	GtkWidget *entrymarque;
	GtkWidget *entrytype;
	GtkWidget *entryval;
	GtkWidget *entrymin;
	GtkWidget *entrymax;
	GtkWidget *entryresto;
	GtkWidget *entrycui;
	GtkWidget *entryhall;
	GtkWidget *entryfoyer;
	GtkWidget *entrybloc;
	GtkWidget *entryetage;
 	GtkWidget *jour;
	GtkWidget *message;
	GtkWidget *mois;
	GtkWidget *anne;
	GtkWidget *image ;
		
entryref=lookup_widget(objet,"entryrefaj");
entrymarque=lookup_widget(objet,"entrymarqueaj");
entrytype=lookup_widget(objet,"comboboxtypeaj");
entryval=lookup_widget(objet,"entryvalaj");
entrymin=lookup_widget(objet,"entryminaj");
entrymax=lookup_widget(objet,"entrymaxaj");
entryresto=lookup_widget(objet,"radiobuttonrestoaj");
entrycui=lookup_widget(objet,"checkbuttoncui");
entryhall=lookup_widget(objet,"checkbuttonhall");
entryfoyer=lookup_widget(objet,"radiobuttonfoyeraj");
entrybloc=lookup_widget(objet,"comboboxblocaj");
entryetage=lookup_widget(objet,"spinbuttonetagaj");
jour=lookup_widget(objet,"spinbuttonjouraj");
mois=lookup_widget(objet,"comboboxmoisaj");
anne=lookup_widget(objet,"spinbuttonanneaj");
message=lookup_widget(objet,"sortieaj");
image=lookup_widget(objet,"image20_capteur");

strcpy(c.reference,gtk_entry_get_text(GTK_ENTRY(entryref) ) );
strcpy(ref,c.reference);
strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(entrymarque) ) );
strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrytype)));
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(entryval) ) );
strcpy(c.valeur_min,gtk_entry_get_text(GTK_ENTRY(entrymin) )) ;
strcpy(c.valeur_max,gtk_entry_get_text(GTK_ENTRY(entrymax) )) ;
c.date_ajout.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
strcpy(c.date_ajout.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));
c.date_ajout.annees=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anne));
	if (ea==1){
           strcpy(c.emplacement.place,"restaurant/");
		c.emplacement.etage=0;
            if(ra==1){
	strcat(c.emplacement.place,"cuisine");}
	else if (ra==2) {
	strcat(c.emplacement.place,"hall");}
}
   else if (ea==2) {
	strcpy(c.emplacement.place,"foyer/");
        strcat(c.emplacement.place,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrybloc)));
        c.emplacement.etage=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryetage));} 
        
 strcpy(place,c.emplacement.place);  

if ((strcmp(c.reference,"")==0)||(strcmp(c.marque,"")==0)||(strcmp(c.valeur,"")==0)){
    gtk_label_set_text(GTK_LABEL(message),"veillez remplir tous les champs") ;
	
	}
else if (exist(ref,c)==1) 
             gtk_label_set_text(GTK_LABEL(message),"existe") ;
                
        else {
	      gtk_widget_hide (message);
               AjouterCapteur(c);
                 gtk_label_set_text(GTK_LABEL(message),"capteur ajouter avec succée") ; 
		 gtk_widget_show (message);
		gtk_image_set_from_file(GTK_IMAGE(image),"/home/dora/Bureau/lasthope/project/pixmaps/check.png");
        	}
	
}


void
on_dk_annuleraj_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkNotebook   *notebook1 ;
notebook1=(GTK_NOTEBOOK(lookup_widget(objet,"notebook1_capteur")));
gint page = gtk_notebook_get_current_page (notebook1);
gtk_notebook_set_current_page (notebook1, 0);
}


void
on_dk_annuler_mo_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkNotebook   *notebook1 ;
notebook1=(GTK_NOTEBOOK(lookup_widget(objet,"notebook1_capteur")));
gint page = gtk_notebook_get_current_page (notebook1);
gtk_notebook_set_current_page (notebook1, 0);
}


void
on_dk_valider_mo_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
    
capteur c ;  
char ref[50];
char place[50];
	GtkWidget *entryref;
	GtkWidget *entrymarque;
	GtkWidget *entrytype;
	GtkWidget *entryval;
	GtkWidget *entrymin;
	GtkWidget *entrymax;
	GtkWidget *entryresto;
	GtkWidget *entrycui;
	GtkWidget *entryhall;
	GtkWidget *entryfoyer;
	GtkWidget *entrybloc;
	GtkWidget *entryetage;
 	GtkWidget *jour;
	GtkWidget *message;
	GtkWidget *mois;
	GtkWidget *anne;
	GtkWidget *refrech;
	
refrech=lookup_widget (objet,"entryrechmo") ;
char refe[10];		
entryref=lookup_widget(objet,"entryrefmo");
entrymarque=lookup_widget(objet,"entrymarquemo");
entrytype=lookup_widget(objet,"comboboxtypemo");
entryval=lookup_widget(objet,"entryvalmo");
entrymin=lookup_widget(objet,"entryminmo");
entrymax=lookup_widget(objet,"entrymaxmo");
entryresto=lookup_widget(objet,"radiobuttonrestomo");
entrycui=lookup_widget(objet,"checkbuttoncuimo");
entryhall=lookup_widget(objet,"checkbuttonhallmo");
entryfoyer=lookup_widget(objet,"radiobuttonfoyermo");
entrybloc=lookup_widget(objet,"comboboxblocmo");
entryetage=lookup_widget(objet,"spinbuttonetagemo");
jour=lookup_widget(objet,"spinbuttonjourmo");
mois=lookup_widget(objet,"comboboxmoismo");
anne=lookup_widget(objet,"spinbuttonannemo");
message=lookup_widget(objet,"sortiemo");

strcpy(c.reference,gtk_entry_get_text(GTK_ENTRY(entryref) ) );
strcpy(ref,c.reference);
suppancien(ref);
strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(entrymarque) ) );
strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrytype)));
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(entryval) ) );
strcpy(c.valeur_min,gtk_entry_get_text(GTK_ENTRY(entrymin) )) ;
strcpy(c.valeur_max,gtk_entry_get_text(GTK_ENTRY(entrymax) )) ;
c.date_ajout.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
strcpy(c.date_ajout.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));
c.date_ajout.annees=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anne));
	if (em==1){
           strcpy(c.emplacement.place,"restaurant/");
		c.emplacement.etage=0;
            if(rm==2){
	strcat(c.emplacement.place,"cuisine");}
	else if (rm==1) {
	strcat(c.emplacement.place,"hall");}
}
   else if (em==2) {
	strcpy(c.emplacement.place,"foyer/");
        strcat(c.emplacement.place,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrybloc)));
        c.emplacement.etage=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryetage));} 
        strcpy(place,c.emplacement.place);
   

if ((strcmp(c.reference,"")==0)||(strcmp(c.marque,"")==0)){
    gtk_label_set_text(GTK_LABEL(message),"veillez remplir tous les champs") ;
	
	}
    else{   
	      gtk_widget_hide (message);
		
               AjouterCapteur(c);
		
                 gtk_label_set_text(GTK_LABEL(message),"capteur Modifier avec succée") ; 
		 gtk_widget_show (message);}
        	
	
}



void
on_dk_butt_rech_mo_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{  char reference[20] ;
char marque[20];
char valeur[20];
char valeur_min[20];
char valeur_max[20];
char type [20] ;


	GtkWidget *entryref; GtkWidget *entrymarque; GtkWidget *entryval;
	GtkWidget *entrymin; GtkWidget *entrymax; GtkWidget *message; GtkWidget *refrech; GtkWidget *entrytype;
entryref=lookup_widget(objet,"entryrefmo");
entrymarque=lookup_widget(objet,"entrymarquemo"); 
entryval=lookup_widget(objet,"entryvalmo");
entrymin=lookup_widget(objet,"entryminmo");
entrymax=lookup_widget(objet,"entrymaxmo");
entrytype=lookup_widget(objet,"comboboxtypemo");

message=lookup_widget(objet,"sortiemo");      
refrech=lookup_widget (objet,"entryrechmo") ;
char ref[10];
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(refrech)));	

	if(existm(ref)==1){
     gtk_label_set_text(GTK_LABEL(message),"reference trouver") ;
     rechercheraffiche(ref,reference,marque,valeur,valeur_min,valeur_max,type);

gtk_entry_set_text (GTK_ENTRY(entryref),reference);
gtk_entry_set_text (GTK_ENTRY(entrymarque),marque);
gtk_entry_set_text (GTK_ENTRY(entryval),valeur);
gtk_entry_set_text (GTK_ENTRY(entrymin),valeur_min);
gtk_entry_set_text (GTK_ENTRY(entrymax),valeur_max);
if (strcmp(type,"Temperature")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(entrytype),0);
}
if (strcmp(type,"Debit")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(entrytype),1);
}if (strcmp(type,"Dechet")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(entrytype),2);
}if (strcmp(type,"Fumee")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(entrytype),3);
}if (strcmp(type,"Mouvement")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(entrytype),4);
}

    }else gtk_label_set_text(GTK_LABEL(message),"reference n'existe pas") ;



}






void
on_dk_butt_act_panne_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
       GtkWidget *gestioncapteur;
	GtkWidget *treeviewpanne;
	gestioncapteur=lookup_widget(objet,"gestioncapteur");
	treeviewpanne=lookup_widget(gestioncapteur,"treeviewpanne");
	affiche_panne(treeviewpanne);
}


void
on_dk_butt_act_alarm_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
        GtkWidget *listedesalarmes;
	GtkWidget *treeviewalarme;
	listedesalarmes=lookup_widget(objet,"listedesalarmes");
	treeviewalarme=lookup_widget(listedesalarmes,"treeviewalarme");
	affiche_alarm(treeviewalarme);
}


void
on_dk_butt_quit_alarm_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
    window1=lookup_widget(objet,"listedesalarmes");
    gtk_widget_destroy(window1);
    window2=create_home();
    gtk_widget_show(window2);
//mail();
}


void
on_dk_butt_quit_defectu_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window6,*window2;
    window6=lookup_widget(objet,"capteursdefect");
    gtk_widget_destroy(window6);
    window2=create_home();
    gtk_widget_show(window2);
}


void
on_dk_butt_act_defect_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *capteursdefect;
	GtkWidget *treeviewdefect;
	capteursdefect=lookup_widget(objet,"capteursdefect");
	treeviewdefect=lookup_widget(objet,"treeviewdefect");
	affiche_defect(treeviewdefect);
	
}






void
on_treeviewalarme_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkWidget *listedesalarmes ;
	GtkTreeIter iter;
		choix ch ;
		

GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&ch.fume.jour,1,&ch.fume.heure,2,&ch.fume.numcapteur,3,&ch.fume.valeurs.valeur,4,&ch.fume.emp,5,&ch.fume.type,-1);
	
	affiche_alarm(treeview); 
	
}



}


void
on_treeview1_capteur_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{  	GtkWidget *warning;
	GtkTreeIter iter;
	capteur c ;
	gchar *reference  ;
	gchar *marque ;
	gchar *type;
	gchar *valeur ;
	gchar *valeur_min ;
	gchar *valeur_max ;
	gchar *place ;
	gint  etage ;
	gint  jour ;
	gchar *mois;
	gint annees ;
	//gpointer user_data;

GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&reference,1,&marque,2,&type,3,&valeur,4,&valeur_min,5,&valeur_max,6,&place,7,&etage,8,&jour,9,&mois,10,&annees, -1);
strcpy(c.reference,reference);
strcpy(c.marque,marque);
strcpy(c.type,type);
strcpy(c.valeur,valeur);
strcpy(c.valeur_min,valeur_min);
strcpy(c.valeur_max,valeur_max);
strcpy(c.emplacement.place,place);
c.emplacement.etage=etage;
c.date_ajout.jour=jour;
strcpy(c.date_ajout.mois,mois);
c.date_ajout.annees=annees ;
warning=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer ce capteur?");
	switch(gtk_dialog_run(GTK_DIALOG(warning)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(warning);
	SuppCapteur(c);
	Afficher(treeview,"capteurs.txt");
        break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(warning);
	break;
}      
}
}


void
on_treeviewdefect_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkWidget *capteursdefect ;
	GtkTreeIter iter;
		choix ch ;
		

GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&ch.temp.jour,1,&ch.temp.heure,2,&ch.temp.numcapteur,3,&ch.temp.valeurs.val,4,&ch.temp.emp,5,&ch.temp.type,-1);
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&ch.mvt.jour,1,&ch.mvt.heure,2,&ch.mvt.numcapteur,3,&ch.mvt.valeurs.val,4,&ch.mvt.emp,5,&ch.mvt.type,-1);
	

	affiche_defect(treeview); 
}
}


void
on_radiobuttonrestoaj_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton));
ea=1 ;

}


void
on_checkbuttoncui_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton));
ra=1 ;

}




void
on_radiobuttonfoyeraj_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton));
ea=2 ;
}


void
on_radiobuttonrestomo_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton));
em=1 ;
}


void
on_checkbuttoncuimo_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton));
rm=1 ;
}


void
on_checkbuttonhallmo_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton));
rm=2 ;
}


void
on_radiobuttonfoyermo_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton));
em=2 ;
}


void
on_checkbuttonhall_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton));
ra=2 ;
}


void
on_treeviewpanne_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *gestioncapteur ;
	GtkTreeIter iter;
		choix ch ;
		gint  jour;
		gint  heure;
		gint  numcapteur;
		gfloat valeur;
		gchar emplacement ;
		gchar type ;

GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&ch.debit.jour,1,&ch.debit.heure,2,&ch.debit.numcapteur,3,&ch.debit.valeurs.val,4,&ch.debit.emp,5,&ch.debit.type,-1);
	ch.debit.jour=jour ;
	ch.debit.heure=heure ;
	ch.debit.numcapteur=numcapteur ;
	ch.debit.valeurs.valeur= valeur ;
	strcpy(ch.debit.emp,emplacement);
        strcpy(ch.debit.type,type);
	affiche_panne(treeview); 
	
}
}





void
on_calendar_day_selected               (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_treeviewdata_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{





}




void
on_buttondeco_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
  gtk_main_quit() ;
}


void
on_calendarh_day_selected              (GtkCalendar     *calendar,
                                        gpointer         user_data)
{
//GtkCalendar *calendar1;
//calendar1=lookup_widget(calendar, "calendarh");
//affiche_historique(GtkWidget *liste,GtkCalendar *c) ;
}


void
on_treeviewh_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)

{  
	/*GtkTreeIter iter;
	capteur c ;
	gchar *reference  ;
	gchar *marque ;
	gchar *type;
	gchar *valeur ;
	gchar *valeur_min ;
	gchar *valeur_max ;
	gchar *place ;
	gint  etage ;
	gint  jour ;
	gchar *mois;
	gint annees ;
	//gint j,m,a ;

GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&reference,1,&marque,2,&type,3,&valeur,4,&valeur_min,5,&valeur_max,6,&place,7,&etage,8,&jour,9,&mois,10,&annees, -1);
strcpy(c.reference,reference);
strcpy(c.marque,marque);
strcpy(c.type,type);
strcpy(c.valeur,valeur);
strcpy(c.valeur_min,valeur_min);
strcpy(c.valeur_max,valeur_max);
strcpy(c.emplacement.place,place);
c.emplacement.etage=etage;
c.date_ajout.jour=jour;
strcpy(c.date_ajout.mois,mois);
c.date_ajout.annees=annees ;
//affiche_historique(treeview,1,2,3) ;
//Afficher(treeview,"old.txt");
    
}*/
}



void
on_buttonh_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{ 
/*
char j [12];
char m [12];
char a [12];
 GtkWidget *gestioncapteur;
	GtkWidget *treeviewh;
	GtkWidget *calendarh;
	guint jour,mois,anne ;
//int pp ;
//pp=1;
	gestioncapteur=lookup_widget(objet,"gestioncapteur");
	calendarh=lookup_widget(gestioncapteur,"calendar1");
	gtk_calendar_get_date(GTK_CALENDAR(calendarh), &jour, &mois, &anne);
	treeviewh=lookup_widget(gestioncapteur,"treeviewh");

sprintf(j,"%d",jour);
	
	affiche_historique(treeviewh,j,m,a) ;
*/
}




void
on_cancelbutton1_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_okbutton1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonmaildk_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{



}


void
on_HELP_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("Login.png", NULL);

  GtkWidget *dialog = gtk_about_dialog_new();
  gtk_about_dialog_set_name(GTK_ABOUT_DIALOG(dialog), "DEMANDE");
  gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), "D'AIDE"); 
 // gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog),"(c) Kadri Dorra");
  gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog), 
     "198 ");
 
  gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(dialog), pixbuf);
  g_object_unref(pixbuf), pixbuf = NULL;
  gtk_dialog_run(GTK_DIALOG (dialog));
  gtk_widget_destroy(dialog);
}



