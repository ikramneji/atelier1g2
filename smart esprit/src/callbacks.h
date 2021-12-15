#include <gtk/gtk.h>
typedef struct{
	int jour;
	int mois;
	int annee;
}date;

void
on_button1_login_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_login_clicked               (GtkButton       *button,
                                        gpointer         user_data);


void
on_hazemkh_inscri_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_hazemkh_connecter_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_hazemkh_femme_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_hazemkh_homme_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_hazem33inscrit_enter                (GtkWidget       *objet_graphique,gpointer  user_data);

void
on_hazemtreeview1_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_hazemkh_ajouter2_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_hazem_modifier_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_hazemkhrecherche_clicked            (GtkWidget       *objet_graphique,gpointer  user_data);

void
on_hazemkh_supprimer_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_hazemkh_actualiser_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_hazemhomme11_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_hazem_radiobuton666modif_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_hazem_non_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_hazem_ajout_tache2_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_hazem_bouton_hk_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_hazem_bouton_eleve_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_hazem_modifer55_clicked             (GtkWidget       *objet_graphique,gpointer  user_data);

void
on_hazem_confermation_ok_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton1_yessshazem_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_hazem_recharger_clicked             (GtkWidget       *objet_graphique,gpointer  user_data);


void
on_button12_retour_kh_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_quiter_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonajouter_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_radiobuttonebergement_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonrestoration_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonafficher_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeviewhebergement_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeviewrestoration_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonrecherche1_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttongotomodifier_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonreturn_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonrecherche2_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonrecherche_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonmodifier_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button1serviceplusreclame_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_closebutton1_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_modifier_st_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_st_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_actualiser_st_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercher_st_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouterpr_st_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_anuulerajout_st_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_annulersupp_st_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_confirmersupp_st_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_st_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_supprimer_st_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_annulerM_st_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier1_st_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_fr_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_nr_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton11_st_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton22_st_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_st_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton11_st_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_retire_st_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview2_st_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_afficher_tache2_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_confirme_ut_st_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_annuler_ut_st_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_date_stt_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_stock_stt_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button3_forget_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_ok_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_logout_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_chercher_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonV_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonVV_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button13_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button14_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button15_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton1_agent_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_agent_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_pti_dej_menu_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_dej_menu_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_list_menu_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_din_menu_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_add_pti_dej_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_add_dej_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radio_avec_regime_dej_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radio_sans_regime_dej_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_check_avec_regime_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_check_sans_regime_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_add_dinnee_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_F5_clicked                          (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_modif_menu_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_rech_edit_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_modif_clicked                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_supprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_s_back_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_sr_edit_valid_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_check_edit_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_check_annuler_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ss_best_menu_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_ss_best_menu_w_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1_nutris_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
#include <gtk/gtk.h>


void
on_capteur_defect_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_dk_butt_rech1_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_dk_butt_aj_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_dk_butt_mod_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_dk_butt_aff_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_dk_annuleraj_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data);


void
on_dk_annuler_mo_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_dk_valider_mo_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_dk_butt_rech_mo_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_dk_butt_act_panne_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_dk_butt_act_alarm_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_dk_butt_quit_alarm_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_dk_butt_quit_panne_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_dk_butt_act_defect_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

//void
//on_dk_butt_quit_defect_clicked         (GtkButton       *button,
                                        //gpointer         user_data);

//void
//on_dk_butt_quit_defect_clicked         (GtkWidget       *objet,
                                        //gpointer         user_data);

void
on_liste_alarme_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_capteurgestion_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_dk_butt_quit_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_dk_valideraj_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_dk_butt_quit_defectu_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_calendaraj_day_selected             (GtkCalendar     *calendar,
                                        gpointer         user_data);

void
on_calendarmo_day_selected             (GtkCalendar     *calendar,
                                        gpointer         user_data);

void
on_checkbuttonresto_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttoncuiaj_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonhallaj_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonfoyeraj_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonrestomo_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttoncuimo_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonhallmo_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonfoyermo_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeviewalarme_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeviewdefect_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_radiobuttonrestoaj_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttoncui_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonfoyeraj_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonrestomo_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttoncuimo_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonhallmo_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonfoyermo_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonhall_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeviewpanne_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_calendar_day_selected               (GtkCalendar     *calendar,
                                        gpointer         user_data);

void
on_treeviewdata_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttondeco_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_calendarh_day_selected              (GtkCalendar     *calendar,
                                        gpointer         user_data);

void
on_treeviewh_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonh_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_cancelbutton1_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbutton1_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmaildk_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_HELP_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1_capteur_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
