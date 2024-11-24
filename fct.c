#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include<string.h>
#include <conio.h>
#include "fct.h"
joueur joueurs[max_joueur];
joueur jo[3];
joueur jou[1];
int nbjoueurs;
int joueurpartie;
char plateau[17][51];
void nouveau_joueur() {
    joueur j;
    do {
        system("cls");
        gotoligcol(1,10);
        printf("entrez votre pseudo :");
        scanf("%s",j.pseudo);
        for(int i=0;i<nbjoueurs;i++) {
            if(strcmp(j.pseudo,joueurs[i].pseudo)==0) {
                gotoligcol(3,10);
                printf("pseudo deja existant");
                gotoligcol(2,10);
                printf("entrez votre pseudo :");
                scanf("%s",j.pseudo);
            }
        }
    }while(strlen(j.pseudo)>taille_pseudo );
    joueurs[nbjoueurs++]=j;
}
void quatresjoueurs(){
    int chose;
    int trouvé=0;
    int tr;
    for(int i=0;i<4;i++) {
        system("cls");
        do {
            gotoligcol(0,10);
            printf("joueur n %d : avez vous deja un profil ?",i+1);
            gotoligcol(1,10);
            printf("1.oui");gotoligcol(2,10);
            printf("2.non");
            gotoligcol(3,10);
            printf("reponse:");
            scanf("%d",&chose);
        }while(chose!=1 && chose!=2);
        if(chose==1) {
            system("cls");
            color(12,0);
            char nom[taille_pseudo];
            gotoligcol(0,10);
            printf("quel est votre pseudo :");
            scanf("%s",nom);
            for(int j=0;j<nbjoueurs;j++) {
                if(strcmp(joueurs[j].pseudo,nom)==0) {
                    trouvé++;
                    j=tr;
                }
            }
            if(trouvé !=0) {
                system("cls");
                gotoligcol(2,10);
                printf("joueur : %s",joueurs[tr].pseudo);
                gotoligcol(3,10);
                jo[i]=joueurs[tr];
                getchar();
                getchar();
            }
            else if(trouvé==0){
                gotoligcol(2,10);
                printf("le joueur %s n'a pas ete trouve",nom);
                getchar();
                getchar();
                nouveau_joueur();
                jo[i]=joueurs[nbjoueurs-1];
            }
        }
        else if(chose==2) {
            nouveau_joueur();
            jo[i]=joueurs[nbjoueurs-1];
        }
    }
    joueurpartie =4;
    initialiserMurs4(jou[0]);
    initialiserMurs4(jou[1]);
    initialiserMurs4(jou[2]);
    initialiserMurs4(jou[3]);
}
void deuxjoueurs() {
    int chose;
    int trouvé=0;
    int tr;
    for(int i=0;i<2;i++) {
        system("cls");
        do {
            gotoligcol(0,10);
            printf("joueur n %d : avez vous deja un profil ?",i+1);
            gotoligcol(1,10);
            printf("1.oui");gotoligcol(2,10);
            printf("2.non");
            gotoligcol(3,10);
            printf("reponse:");
            scanf("%d",&chose);
        }while(chose!=1 && chose!=2);
        if(chose==1) {
            system("cls");
            color(12,0);
            char nom[taille_pseudo];
            gotoligcol(0,10);
            printf("quel est votre pseudo :");
            scanf("%s",nom);
            for(int j=0;j<nbjoueurs;j++) {
                if(strcmp(joueurs[j].pseudo,nom)==0) {
                    trouvé++;
                    j=tr;
                }
            }
            if(trouvé !=0) {
                system("cls");
                gotoligcol(2,10);
                printf("joueur : %s",joueurs[tr].pseudo);
                gotoligcol(3,10);
                jou[i]=joueurs[tr];
                getchar();
                getchar();
            }
            else if(trouvé==0){
                gotoligcol(2,10);
                printf("le joueur %s n'a pas ete trouve",nom);
                getchar();
                getchar();
                nouveau_joueur();
                jou[i]=joueurs[nbjoueurs-1];
            }
        }
        else if(chose==2) {
            nouveau_joueur();
            jou[i]=joueurs[nbjoueurs-1];
        }
    }
    joueurpartie =2;
    initialiserMurs2(jou[0]);
    initialiserMurs2(jou[1]);
}
void affichage_menu(){
    system("cls");
    color(12,0);
    gotoligcol(1,20);
    printf("MENU");
    gotoligcol(3,10);
    printf("1.Lancer une nouvelle partie ");
    gotoligcol(4,10);
    printf("2.Reprendre une partie sauvegardee");
    gotoligcol(5,10);
    printf("3.Afficher l'aide ");
    gotoligcol(6,10);
    printf("4.Afficher les scores des joueurs");
    gotoligcol(7,10);
    printf("5.Quitter ");
    gotoligcol(9,10);
    printf("saisissez un nombre puis appuyez sur entrer:");
}
void action_possible() {
    gotoligcol(19,5);
    printf("action possible :");
    gotoligcol(20,5);
    printf("1.deplacer son pion");
    gotoligcol(21,5);
    printf("2.poser un mur");
    gotoligcol(22,5);
    printf("3.passer son tour");
    gotoligcol(23,5);
    printf("4. annuler la derniere action");
    gotoligcol(24,5);
    printf("entrer votre choix : ");
}
void joueurs_affichage(joueur *j) {
    color(12,0);
    gotoligcol(1,54);
    printf("nombre de joueurs : %d",joueurpartie);
    gotoligcol(2,54);
    printf("joueur : %s",j->pseudo);
    gotoligcol(3,54);
    printf("pion : %c",j->symbole);
    gotoligcol(4,54);
    printf("mur restant %d : ",j->mur);
}
void affichage_nbjoueurspartie() {
    system("cls");
    color(12,0);
    gotoligcol(1,10);
    printf("choisisez le nombre de joueur :");
    gotoligcol(3,10);
    printf("1.partie a 2 joueurs ");
    gotoligcol(4,10);
    printf("2.partie a 4 joueurs ");
    gotoligcol(5,10);
    printf("3.retour en arriere");
    gotoligcol(7,10);
    printf("veuillez selectionner un numero :");
}
void affichage_scores() {
    int trouvé;
    system("cls");
    color(12,0);
    char nom[taille_pseudo];
    gotoligcol(0,10);
    printf("quel est votre pseudo :");
    scanf("%s",nom);
    for(int i=0;i<nbjoueurs;i++) {
        if(strcmp(joueurs[i].pseudo,nom)==0) {
            system("cls");
            gotoligcol(1,10);
            printf("joueur : %s",joueurs[i].pseudo);
            gotoligcol(2,10);
            printf("votre score est de %d victoire",joueurs[i].score);
            trouvé++;
        }
        else if(trouvé == 0) {
            gotoligcol(2,10);
            printf("le joueur %s n'a pas ete trouve",nom);
        }
    }
    gotoligcol(5,10);
    printf("pour quitter appuyer sur entrer");
    getchar();
    getchar();
}
void affichage_apres_menu() {
    int choix;
    do {
        system("cls");
        color(12,0);
        affichage_menu();
        scanf("%d",&choix);
        switch(choix) {
            case 1:
                demarrage_partie();
            break;
            case 2:
                printf("Quel est votre partie :");
                //reprendre partie sauvegarde
            break;
            case 3:
                afficherAide();
            break;
            case 4:
                affichage_scores();
            break;
            case 5:
                system("cls");
                gotoligcol(0,10);
                printf("merci d'avoir jouer a QUORIDOR");
            break;
            default:
                system("cls");
                printf("choix impossible");
            break;
        }
    }while(choix!=5);
}
void demarrage_partie() {
    system("cls");
    int choix;
    do {
        affichage_nbjoueurspartie();
        scanf("%d",&choix);
        switch (choix) {
            case 1:
                partie2joueurs();
            break;
            case 2:
                partie4joueurs();
            break;
            case 3:
                break;
        }
    }while(choix<1 || choix >3);
}
void partie2joueurs() {
    deuxjoueurs();
    initialiserPlateau(plateau);
    initialiserMurs2(jou[0]);
    initialiserMurs2(jou[1]);
    placerPions2(plateau,&jou[0], &jou[1]);
    afficherPlateau(plateau);
    int choix;
    do {
        joueurs_affichage(&jou[0]);
        action_possible();
        scanf("%d",&choix);
        switch(choix) {
            case 1:
                deplacerPion2j(plateau,&jou[0],&jou[1]);
            break;
            case 2:
                placer_mur(jou[0],plateau);
            break;
            case 3:
                break;
            case 4:
                break;
        }
        afficherPlateau(plateau);
        joueurs_affichage(&jou[1]);
        action_possible();
        scanf("%d",&choix);
        switch(choix) {
            case 1:
                deplacerPion2j(plateau,&jou[1],&jou[0]);
            break;
            case 2:
                placer_mur(jou[1],plateau);
            break;
            case 3:
                break;
            case 4:
                break;
        }
        afficherPlateau(plateau);
    }while(verifierVictoireDeuxJoueurs(plateau)==0);
}
void partie4joueurs() {
    quatresjoueurs();
    initialiserPlateau(plateau);
    placerPions4(plateau,&jo[0], &jo[1],&jo[2],&jo[3]);
    int choix;
    do {
        afficherPlateau(plateau);
        joueurs_affichage(&jo[0]);
        action_possible();
        scanf("%d",&choix);
        switch(choix) {
            case 1:
                deplacerPion4j(plateau,&jo[0],&jo[1],&jo[2],&jo[3]);
            break;
            case 2:
                placer_mur(jo[0],plateau);
            break;
            case 3:
                break;
            case 4:
                break;
        }
        afficherPlateau(plateau);
        joueurs_affichage(&jo[1]);
        action_possible();
        scanf("%d",&choix);
        switch(choix) {
            case 1:
                deplacerPion4j(plateau,&jo[1],&jo[0],&jo[2],&jo[3]);
            break;
            case 2:
                placer_mur(jo[1],plateau);
            break;
            case 3:
                break;
            case 4:
                break;
        }
        afficherPlateau(plateau);
        joueurs_affichage(&jo[2]);
        action_possible();
        scanf("%d",&choix);
        switch(choix) {
            case 1:
                deplacerPion4j(plateau,&jo[2],&jo[0],&jo[1],&jo[3]);
            break;
            case 2:
                placer_mur(jo[2],plateau);
            break;
            case 3:
                break;
            case 4:
                break;
        }
        afficherPlateau(plateau);
        joueurs_affichage(&jo[3]);
        action_possible();
        scanf("%d",&choix);
        switch(choix) {
            case 1:
                deplacerPion4j(plateau,&jo[3],&jo[0],&jo[1],&jo[2]);
            break;
            case 2:
                placer_mur(jo[3],plateau);
            break;
            case 3:
                break;
            case 4:
                break;
        }
    }while(verifierVictoireQuatreJoueurs(plateau)==0);
}
void placerPions2(char plateau[LIGNES][COLONNES], joueur *joueur1, joueur *joueur2) {
    joueur1->x = 0;
    joueur1->y = COLONNES / 2;
    joueur1->symbole = '@';
    plateau[joueur1->x][joueur1->y] = joueur1->symbole;

    joueur2->x = LIGNES - 1;
    joueur2->y = COLONNES / 2;
    joueur2->symbole = 'X';
    plateau[joueur2->x][joueur2->y] = joueur2->symbole;
}
void deplacerPion2j(char plateau[17][51], joueur *joueurp, joueur *adversaire) {
    char touche;
    int old_x = joueurp->x;
    int old_y = joueurp->y;
    int new_x = old_x;
    int new_y = old_y;

    while (1) {
        gotoligcol(26, 5);
        printf("Entrez une direction (z: haut, s: bas, q: gauche, d: droite): ");
        scanf(" %c", &touche);

        switch (touche) {
            case 'z': new_x -= 2; break;
            case 's': new_x += 2; break;
            case 'q': new_y -= 6; break;
            case 'd': new_y += 6; break;
            default:
                gotoligcol(27, 5);
            printf("Direction invalide. Reessayez.\n");
            continue;
        }

        if (new_x < 0 || new_x >= 17 || new_y < 0 || new_y >= 51) {
            gotoligcol(28, 5);
            printf("Déplacement hors limites. Reessayez.\n");
            new_x = old_x;
            new_y = old_y;
            continue;
        }

        if ((touche == 'z' && plateau[old_x - 1][old_y] == '-') ||
            (touche == 's' && plateau[old_x + 1][old_y] == '-') ||
            (touche == 'q' && plateau[old_x][old_y - 1] == '|') ||
            (touche == 'd' && plateau[old_x][old_y + 1] == '|')) {
            gotoligcol(29, 5);
            printf("Déplacement bloqué par une barrière. Reessayez.\n");
            new_x = old_x;
            new_y = old_y;
            continue;
            }

        break;
    }

    plateau[old_x][old_y] = ' ';
    plateau[new_x][new_y] = joueurp->symbole;
    joueurp->x = new_x;
    joueurp->y = new_y;

    gotoligcol(30, 5);
    printf("Déplacement effectué : (%d, %d) -> (%d, %d)\n", old_x, old_y, new_x, new_y);
}
void deplacerPion4j(char plateau[LIGNES][COLONNES], joueur *joueurp, joueur *adversaire1, joueur *adversaire2, joueur *adversaire3) {
    char touche;
    int old_x = joueurp->x;
    int old_y = joueurp->y;
    int new_x = old_x;
    int new_y = old_y;
    gotoligcol(26,5);
    printf("Entrez une direction (z: haut, s: bas, q: gauche, d: droite): ");
    scanf(" %c", &touche);

    switch (touche) {
        case 'z': new_x -= 2; break; // Haut
        case 's': new_x += 2; break; // Bas
        case 'q': new_y -= 6; break; // Gauche
        case 'd': new_y += 6; break; // Droite
        default:
            gotoligcol(27,5);
            printf("Direction invalide. Reessayez.");
        return;
    }
    if (new_x < 0 || new_x >= LIGNES || new_y < 0 || new_y >= COLONNES) {
        gotoligcol(27,5);
        printf("Deplacement hors limites. Reessayez.");
        return;
    }
    if ((touche == 'z' && plateau[old_x - 1][old_y] == '-') ||
        (touche == 's' && plateau[old_x + 1][old_y] == '-') ||
        (touche == 'q' && plateau[old_x][old_y - 1] == '|') ||
        (touche == 'd' && plateau[old_x][old_y + 1] == '|')) {
        gotoligcol(27,5);
        printf("Deplacement bloque par une barriere. Reessayez.");
        return;
        }
    if (new_x == adversaire1->x && new_y == adversaire1->y || new_x == adversaire2->x && new_y == adversaire2->y || new_x == adversaire3->x && new_y == adversaire3->y ) {
        int saut_x = new_x + (new_x - old_x);
        int saut_y = new_y + (new_y - old_y);

        if (saut_x >= 0 && saut_x < LIGNES && saut_y >= 0 && saut_y < COLONNES &&
            plateau[saut_x][saut_y] == '.') {
            new_x = saut_x;
            new_y = saut_y;
            } else {
                gotoligcol(27,5);
                printf("Impossible de sauter par-dessus l'adversaire. Reessayez.");
                return;
            }
    }

    plateau[old_x][old_y] = ' ';
    plateau[new_x][new_y] = joueurp->symbole;
    joueurp->x = new_x;
    joueurp->y = new_y;
    gotoligcol(27,5);
    printf("Deplacement effectue : (%d, %d) -> (%d, %d)", old_x, old_y, new_x, new_y);
}
void placerPions4(char plateau[LIGNES][COLONNES], joueur *joueur1, joueur *joueur2, joueur *joueur3, joueur *joueur4) {

    joueur1->x = 0;
    joueur1->y = COLONNES / 2;
    joueur1->symbole = '@';
    plateau[joueur1->x][joueur1->y] = joueur1->symbole;

    joueur2->x = LIGNES - 1;
    joueur2->y = COLONNES / 2;
    joueur2->symbole = 'X';
    plateau[joueur2->x][joueur2->y] = joueur2->symbole;

    joueur3->x = LIGNES / 2;
    joueur3->y = 1;
    joueur3->symbole = '*';
    plateau[joueur3->x][joueur3->y] = joueur3->symbole;

    joueur4->x = LIGNES / 2;
    joueur4->y = COLONNES - 2;
    joueur4->symbole = '0';
    plateau[joueur4->x][joueur4->y] = joueur4->symbole;
}
void gotoligcol( int lig, int col ) {
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}
void color(int texte, int fond) {
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,fond*16+texte);
}
void initialiserPlateau(char plateau[17][51]) {
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 51; j++) {
            plateau[i][j] = ' ';
        }
    }
}
void afficherPlateau(char plateau[17][51]) {
    system("cls");
    gotoligcol(0, 0);
    color(15,0);
    printf("  A     B     C     D     E     F     G     H     I\n");
    for (int i = 0; i < 17; i++) {
        color(15,0);
        if (i%2 == 0) {
            printf("%d",(i+1)/2+1);
        }
        else {
            printf(" ");
        }
        for (int j = 0; j < 51; j++) {
            color(0,8);
            if (est_dans_liste(i)||est_dans(j)) {
                color(0,4);
            }
            printf("%c", plateau[i][j]);
        }
        printf("\n");
    }
}
int est_dans_liste(int n) {
    int liste[] = {1, 3, 5, 7, 9, 11, 13, 15,};
    int taille = sizeof(liste) / sizeof(liste[0]);
    for (int i = 0; i < taille; i++) {
        if (n == liste[i]) {
            return 1;
        }
    }
    return 0;
}
int est_dans(int n) {
    int liste[] = { 3,4,5,9,10,11,15,16,17,21,22,23,27,28,29,33,34,35,39,40,41,45,46,47 };
    int taille = sizeof(liste) / sizeof(liste[0]);
    for (int i = 0; i < taille; i++) {
        if (n == liste[i]) {
            return 1;
        }
    }
    return 0;
}
void initialiserMurs2(joueur *j) {
    j.mur=10;
}
void initialiserMurs4(joueur *j) {
    j.mur=5;
}
void placer_mur(joueur *j, char plateau[17][51]) {
    while (1) {
        if (j->mur <= 0) {
            gotoligcol(26, 5);
            printf("Le joueur n'a plus de mur à placer. Entrez une autre action.\n");
            break; // Sortir de la boucle en cas d'erreur
        }

        int lig, col;
        char orientation;

        do {
            gotoligcol(26, 5);
            printf("Choisissez la ligne sur laquelle vous voulez placer le mur : ");
            scanf("%d", &lig);
        } while (lig < 1 || lig > 15 || lig % 2 == 0);

        do {
            gotoligcol(27, 5);
            printf("Choisissez la colonne sur laquelle vous voulez placer le mur : ");
            scanf("%d", &col);
        } while (col < 3 || col > 48 || col % 3 != 0);

        do {
            gotoligcol(28, 5);
            printf("Choisissez l'orientation du mur (v pour vertical, h pour horizontal) : ");
            scanf(" %c", &orientation);
        } while (orientation != 'v' && orientation != 'h');

        int mur_possible = 1;
        if (orientation == 'v') {
            for (int i = 0; i < 3; i++) {
                if (plateau[lig][col + i] == '|') {
                    gotoligcol(31, 5);
                    printf("Il y a déjà un mur ici. Reessayez.\n");
                    mur_possible = 0;
                    break;
                }
            }
            if (mur_possible) {
                for (int i = 0; i < 3; i++) {
                    plateau[lig][col + i] = '|';
                }
                j->mur--;
                gotoligcol(33, 5);
                printf("Mur placé avec succès\n");
                break;
            }
        } else if (orientation == 'h') {
            for (int i = 0; i < 3; i++) {
                if (plateau[lig + i][col] == '-') {
                    gotoligcol(32, 5);
                    printf("Il y a déjà un mur ici. Reessayez.\n");
                    mur_possible = 0;
                    break;
                }
            }
            if (mur_possible) {
                for (int i = 0; i < 3; i++) {
                    plateau[lig + i][col] = '-';
                }
                j->mur--;
                gotoligcol(33, 5);
                printf("Mur placé avec succès\n");
                break;
            }
        }
    }
}
void afficherAide() {
    system("cls");
    color(12,0);
    gotoligcol(1,20);
    printf("Aide du Jeu Quorridor");
    gotoligcol(3,10);
    printf("Si tu ne sais pas comment jouer, voici quelques informations utiles :");
    gotoligcol(5,10);
    printf("1. Chaque joueur dispose d'un pion et d'un nombre limite de murs.");
    gotoligcol(6,10);
    printf("2. Le joueur peut soit deplacer son pion, soit poser un mur sur le plateau.");
    gotoligcol(7,10);
    printf("3. Le jeu se deroule en tours successifs. À chaque tour, un joueur peut deplacer son pion ou poser un mur.");
    gotoligcol(8,10);
    printf("4. Pour gagner, il faut amener son pion de l'autre cote du plateau avant l'adversaire.");
    gotoligcol(10,10);
    printf("pour quitter appuyer sur entrer");
    getchar();
    getchar();
}
int mouvementValide(char plateau[17][51], int x, int y, int newX, int newY) {
    if (x % 2 != 0 || y % 6 != 3 || newX % 2 != 0 || newY % 6 != 3) {
        return 0;
    }
    int dx = newX - x;
    int dy = newY - y;

    if (!((dx == 2 && dy == 0) || (dx == -2 && dy == 0) || (dy == 6 && dx == 0) || (dy == -6 && dx == 0))) {
        return 0;
    }
    if (dx == 2 && (plateau[x + 1][y] == '|')) {
        return 0;
    }
    if (dx == -2 && (plateau[x - 1][y] == '|')) {
        return 0;
    }
    if (dy == 6 && (plateau[x][y + 3] == '-')) {
        return 0;
    }
    if (dy == -6 && (plateau[x][y - 3] == '-')) {
        return 0;
    }
    return 1;
}
int verifierVictoireDeuxJoueurs(char plateau[17][51]) {
    system("cls");
    // Joueur 1 (jou[0]) doit atteindre la dernière ligne (ligne 16)
    for (int j = 0; j < 51; j++) {
        if(plateau[16][j] == jou[0].symbole) {
            gotoligcol(0,10);
            printf("Le joueur %s a gagne !\n", jou[0].pseudo);
            jou[0].score++;
            return 1;
        }
    }
    // Joueur 2 (jou[1]) doit atteindre la première ligne (ligne 0)
    for (int j = 0; j < 51; j++) {
        if (plateau[0][j] == jou[1].symbole) {
            gotoligcol(0,10);
            printf("Le joueur %s a gagne !\n", jou[1].pseudo);
            jou[1].score++;
            return 1;
        }
    }
    // Pas de victoire
    return 0;
}
// Vérifie la victoire pour une partie à quatre joueurs
int verifierVictoireQuatreJoueurs(char plateau[17][51]) {
    system("cls");
    // Joueur 1 (jo[0]) doit atteindre la dernière ligne (ligne 16)
    for (int j = 0; j < 51; j++) {
        if (plateau[16][j] == jo[0].symbole) {
            gotoligcol(0,10);
            printf("Le joueur %s a gagne !", jo[0].pseudo);
            return 1;
        }
    }
    // Joueur 2 (jo[1]) doit atteindre la première ligne (ligne 0)
    for (int j = 0; j < 51; j++) {
        if (plateau[0][j] == jo[1].symbole) {
            gotoligcol(0,10);
            printf("Le joueur %s a gagne !", jo[1].pseudo);
            return 1;
        }
    }
    // Joueur 3 (jo[2]) doit atteindre la dernière colonne (colonne 50)
    for (int i = 0; i < 17; i++) {
        if (plateau[i][50] == jo[2].symbole) {
            gotoligcol(0,10);
            printf("Le joueur %s a gagne !", jo[2].pseudo);
            return 1;
        }
    }
    // Joueur 4 (jo[3]) doit atteindre la première colonne (colonne 0)
    for (int i = 0; i < 17; i++) {
        if (plateau[i][0] == jo[3].symbole) {
            gotoligcol(0,10);
            printf("Le joueur %s a gagne !", jo[3].pseudo);
            return 1;
        }
    }
    // Pas de victoire
    return 0;
}
