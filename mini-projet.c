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

int main() {
    int choix;
    
    printf("\n========================================\n");
    printf("   SYSTEME DE GESTION DE LIBRAIRIE     \n");
    printf("             Created By: Houssam Bensiyed\n");
    printf("========================================\n");
    
    do {
        afficherMenu();
        printf("Votre choix : ");
        scanf("%d", &choix);
        viderBuffer();
        
        switch(choix) {
            case 1:
                ajouterLivre();
                break;
            case 2:
                afficherTousLesLivres();
                break;
            case 3:
                rechercherLivre();
                break;
            case 4:
                mettreAJourQuantite();
                break;
            case 5:
                supprimerLivre();
                break;
            case 6:
                afficherTotalStock();
                break;
            case 0:
                printf("\nMerci d'avoir utilise notre systeme. Au revoir!\n");
                break;
            default:
                printf("\nChoix invalide! Veuillez reessayer.\n");
        }
    } while(choix != 0);
    
    return 0;
}