#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include <windows.h>
#ifndef fct_h
#define fct_h
#define taille_pseudo 20
#define max_joueur 20
#define taille_pion 2
#define LIGNES 17
#define COLONNES 51
typedef struct {
    char pseudo[taille_pseudo];
    int score;
    int mur;
    int x;
    int y;
    char symbole;
}joueur;
extern joueur joueurs[max_joueur];
extern int nbjoueurs;
extern joueur jo[3];
extern joueur jou[1];
extern int joueurpartie;
void nouveau_joueur();
void quatresjoueurs();
void deuxjoueurs();
void placerPions2(char plateau[LIGNES][COLONNES], joueur *joueur1, joueur *joueur2);
void placerPions4(char plateau[LIGNES][COLONNES], joueur joueur1, joueur*joueur2, joueur joueur3, joueur*joueur4);
void deplacerPion2j(char plateau[17][51], joueur *joueurp, joueur *adversaire);
void deplacerPion4j(char plateau[LIGNES][COLONNES], joueur *joueurp, joueur *adversaire1, joueur *adversaire2, joueur *adversaire3);
void gotoligcol( int lig, int col );
void color(int texte, int fond);
void initialiserPlateau(char plateau[17][51]);
void afficherPlateau(char plateau[17][51]);
int est_dans_liste(int n);
int est_dans(int n);
extern char plateau[17][51];
void initialiserMurs2(joueur *j);
void initialiserMurs4(joueur *j);
void placer_mur(joueur *j, char plateau[17][51]);
void afficherAide();
int mouvementValide(char plateau[17][51], int x, int y, int newX, int newY);
int verifierVictoireDeuxJoueurs(char plateau[17][51]);
int verifierVictoireQuatreJoueurs(char plateau[17][51]);
void affichage_menu();
void action_possible();
void joueurs_affichage(joueur *j);
void affichage_nbjoueurspartie();
void affichage_scores();
void affichage_apres_menu();
void demarrage_partie();
void partie2joueurs();
void partie4joueurs();
#endif