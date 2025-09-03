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
int quantites[MAX_LIVRES];
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

// Fonction pour afficher le menu principal
void afficherMenu() {
    printf("\n========== MENU PRINCIPAL =================\n");
    printf("1. Ajouter un livre\n");
    printf("2. Afficher tous les livres\n");
    printf("3. Rechercher un livre\n");
    printf("4. Mettre a jour la quantite\n");
    printf("5. Supprimer un livre\n");
    printf("6. Afficher le total du stock\n");
    printf("0. Quitter\n");
    printf("                © copyright houssam bensiyed \n");
    printf("=============================================\n");
}

// Fonction pour vider le buffer d'entrée
void viderBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Fonction pour ajouter un livre au stock
void ajouterLivre() {
    if (nombre_livres >= MAX_LIVRES) {
        printf("\nErreur : Stock maximum atteint!\n");
        return;
    }
    
    printf("\n========== AJOUTER UN LIVRE ==========\n");
    
    printf("Titre du livre : ");
    fgets(titres[nombre_livres], MAX_TITRE, stdin);
    titres[nombre_livres][strcspn(titres[nombre_livres], "\n")] = 0;
    
    printf("Auteur du livre : ");
    fgets(auteurs[nombre_livres], MAX_AUTEUR, stdin);
    auteurs[nombre_livres][strcspn(auteurs[nombre_livres], "\n")] = 0;
    
    printf("Prix du livre : ");
    scanf("%f", &prix[nombre_livres]);
    
    printf("Quantite en stock : ");
    scanf("%d", &quantites[nombre_livres]);
    viderBuffer();
    
    nombre_livres++;
    printf("\nLivre ajoute avec succes!\n");
}

// Fonction pour afficher tous les livres disponibles
void afficherTousLesLivres() {
    if (nombre_livres == 0) {
        printf("\nAucun livre en stock.\n");
        return;
    }
    
    printf("\n========== LISTE DES LIVRES ==========\n");
    printf("%-30s %-25s %-10s %-10s\n", "TITRE", "AUTEUR", "PRIX", "QUANTITE");
    printf("--------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < nombre_livres; i++) {
        printf("%-30s %-25s %-10.2f %-10d\n", 
               titres[i], auteurs[i], prix[i], quantites[i]);
    }
    printf("--------------------------------------------------------------------------------\n");
    printf("Total : %d livre(s) different(s) en stock\n", nombre_livres);
}

// Fonction pour rechercher un livre par son title
void rechercherLivre() {
    char titre_recherche[MAX_TITRE];
    int trouve = 0;

    if (nombre_livres == 0) {
        printf("\nAucun livre en stock. \n");
        return;
    }

    printf("\n==================== RECHERCHER UN LIVRE =============\n");
    printf("Entrez le titre du livre a rechercher: ");
    fgets(titre_recherche, MAX_TITRE, stdin);
    titre_recherche[strcspn(titre_recherche, "\n")] = 0;

    for (int i = 0; i < nombre_livres; i++) {
        if (strcasecmp(titres[i], titre_recherche) == 0) {
            printf("\nLivre trouve: \n");
            printf("================\n");
            printf("Titre    : %s\n", titres[i]);
            printf("Auteur   : %s\n", auteurs[i]);
            printf("Prix     : %.2f\n", prix[i]);
            printf("Quantite : %d\n", quantites[i]);
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("\nLivre non trouve dans le stock.\n");
    }
}

void mettreAJourQuantite() {
    char titre_recherche[MAX_TITRE];
    int nouvell_quantite;
    int trouve = 0;

    if (nombre_livres == 0) {
        printf("\nAucun livre en stock.\n");
        return;
    }

    printf("\n========== METTRE A JOUR LA QUANTITE ==========\n");
    printf("Entrez le titre du livre: ");
    fgets(titre_recherche, MAX_TITRE, stdin);
    titre_recherche[strcspn(titre_recherche, "\n")] = 0;

    for (int i = 0; i < nombre_livres; i++) {
        if (strcasecmp(titres[i], titre_recherche) == 0) {
            printf("Quantite actuelle : %d\n", quantites[i]);
            printf("Nouvell quantite: ");
            scanf("%d", &nouvell_quantite);
            viderBuffer();

            
            quantites[i] = nouvell_quantite;
            printf("\nQuantite mise a jour avec succes!\n");
            trouve = 1;
            break;
        }
    }



    if (!trouve) {
        printf("\nLivre non trouve dans le stock. \n");
    }
}

// Fonction pour supprimer un livre du stock
void supprimerLivre() {
    char titre_recherche[MAX_TITRE];
    int trouve = 0;
    char confirmation;
    
    if (nombre_livres == 0) {
        printf("\nAucun livre en stock.\n");
        return;
    }
    
    printf("\n========== SUPPRIMER UN LIVRE ==========\n");
    printf("Entrez le titre du livre a supprimer : ");
    fgets(titre_recherche, MAX_TITRE, stdin);
    titre_recherche[strcspn(titre_recherche, "\n")] = 0;
    
    for (int i = 0; i < nombre_livres; i++) {
        if (strcasecmp(titres[i], titre_recherche) == 0) {
            printf("\nLivre trouve :\n");
            printf("Titre : %s\n", titres[i]);
            printf("Auteur : %s\n", auteurs[i]);
            printf("\nConfirmer la suppression (o/n) : ");
            scanf("%c", &confirmation);
            viderBuffer();
            
            if (confirmation == 'o' || confirmation == 'O') {
                // Décaler les éléments pour supprimer le livre
                for (int j = i; j < nombre_livres - 1; j++) {
                    strcpy(titres[j], titres[j + 1]);
                    strcpy(auteurs[j], auteurs[j + 1]);
                    prix[j] = prix[j + 1];
                    quantites[j] = quantites[j + 1];
                }
                nombre_livres--;
                printf("\nLivre supprime avec succes!\n");
            } else {
                printf("\nSuppression annulee.\n");
            }
            trouve = 1;
            break;
        }
    }
    
    if (!trouve) {
        printf("\nLivre non trouve dans le stock.\n");
    }
}

// Fonction pour afficher le nombre total de livres en stock
void afficherTotalStock() {
    int total = 0;

    if (nombre_livres == 0) {
        printf("\nAucun livre en stock.\n");
        return;
    }

    printf("\n=========== TOTAL DU STOCK ============\n");

    for (int i = 0; i < nombre_livres; i++) {
        total += quantites[i];
        printf("%s: %d exemplaire(s)\n", titres[i], quantites[i]);
    }


    printf("\n----------------------------------------\n");
    printf("Nombre de titres differents: %d\n", nombre_livres);
    printf("Nombre total d'exemplaires: %d\n", total);
    printf("-------------------------------------------\n");
 }