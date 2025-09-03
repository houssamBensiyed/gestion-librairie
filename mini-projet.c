#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LIVRES 100
#define MAX_TITRE 100
#define MAX_AUTEUR 100

// Variables globales pour stocker les informations des livres
char titres[MAX_LIVRES][MAX_TITRE];
char auteurs[MAX_LIVRES][MAX_AUTEUR];
float prix[MAX_LIVRES];
int quantities[MAX_LIVRES];
int nombre_livres = 0;

// Prototypes des fonctions
void afficherMenu();
void ajouterLivre();
void afficherTousLesLivres();
void rechercherLivre();
void mettreAJourQuantite();
void supprimerLivre();
void afficherTotalStock();
void viderBuffer();

