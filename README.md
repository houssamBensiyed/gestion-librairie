# 📚 Système de Gestion de Stock - Librairie

Un système de gestion de stock simple et efficace pour une librairie, développé en langage C.

## 📖 Description

Ce programme permet de gérer efficacement le stock de livres dans une librairie. Il offre une interface en ligne de commande simple et intuitive pour effectuer toutes les opérations de base nécessaires à la gestion d'inventaire.

## ✨ Fonctionnalités

### Fonctionnalités Principales

- **➕ Ajouter un livre** : Enregistrer un nouveau livre avec ses détails complets
- **📋 Afficher tous les livres** : Visualiser l'inventaire complet sous forme de tableau
- **🔍 Rechercher un livre** : Trouver un livre spécifique par son titre
- **✏️ Mettre à jour la quantité** : Modifier le stock d'un livre existant
- **🗑️ Supprimer un livre** : Retirer un livre de l'inventaire
- **📊 Statistiques du stock** : Afficher le total des livres et exemplaires

### Caractéristiques Techniques

- Stockage en mémoire avec tableaux statiques
- Recherche insensible à la casse
- Validation des entrées utilisateur
- Interface utilisateur claire et formatée
- Gestion des erreurs

## 🔧 Prérequis

- **Compilateur C** : GCC, Clang, ou tout compilateur C standard
- **Système d'exploitation** : Windows, Linux, macOS
- **Mémoire** : Minimum 1 MB RAM
- **Terminal** : Support des caractères ASCII étendus recommandé

## 💻 Installation

### Linux/macOS

```bash
# Cloner le repository (ou télécharger le fichier)
git clone https://github.com/votre-username/gestion-librairie.git
cd gestion-librairie

# Compiler le programme
gcc -o gestion_librairie gestion_librairie.c

# Donner les permissions d'exécution
chmod +x gestion_librairie

# Exécuter le programme
./gestion_librairie
```

### Windows

```cmd
# Compiler avec MinGW
gcc -o gestion_librairie.exe gestion_librairie.c

# Exécuter le programme
gestion_librairie.exe
```

### Avec Makefile (Optionnel)

Créez un fichier `Makefile` :

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = gestion_librairie

$(TARGET): gestion_librairie.c
	$(CC) $(CFLAGS) -o $(TARGET) gestion_librairie.c

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
```

Puis compilez avec :
```bash
make
make run
```

## 📘 Utilisation

### Menu Principal

Lors du lancement, vous verrez le menu suivant :

```
========================================
   SYSTEME DE GESTION DE LIBRAIRIE     
========================================

========== MENU PRINCIPAL ==========
1. Ajouter un livre
2. Afficher tous les livres
3. Rechercher un livre
4. Mettre a jour la quantite
5. Supprimer un livre
6. Afficher le total du stock
0. Quitter
====================================
Votre choix : 
```

### Guide d'Utilisation

#### 1️⃣ Ajouter un Livre

```
Votre choix : 1

========== AJOUTER UN LIVRE ==========
Titre du livre : Le Petit Prince
Auteur du livre : Antoine de Saint-Exupéry
Prix du livre : 15.99
Quantite en stock : 25

Livre ajoute avec succes!
```

#### 2️⃣ Afficher Tous les Livres

```
========== LISTE DES LIVRES ==========
TITRE                          AUTEUR                    PRIX       QUANTITE  
--------------------------------------------------------------------------------
Le Petit Prince                Antoine de Saint-Exupéry  15.99      25        
1984                          George Orwell              18.50      12        
L'Étranger                    Albert Camus               14.00      8         
--------------------------------------------------------------------------------
Total : 3 livre(s) different(s) en stock
```

#### 3️⃣ Rechercher un Livre

```
========== RECHERCHER UN LIVRE ==========
Entrez le titre du livre a rechercher : 1984

Livre trouve :
----------------
Titre    : 1984
Auteur   : George Orwell
Prix     : 18.50
Quantite : 12
```

#### 4️⃣ Mettre à Jour la Quantité

```
========== METTRE A JOUR LA QUANTITE ==========
Entrez le titre du livre : Le Petit Prince
Quantite actuelle : 25
Nouvelle quantite : 30

Quantite mise a jour avec succes!
```

#### 5️⃣ Supprimer un Livre

```
========== SUPPRIMER UN LIVRE ==========
Entrez le titre du livre a supprimer : L'Étranger

Livre trouve :
Titre : L'Étranger
Auteur : Albert Camus

Confirmer la suppression (o/n) : o

Livre supprime avec succes!
```

#### 6️⃣ Afficher le Total du Stock

```
========== TOTAL DU STOCK ==========
Le Petit Prince : 30 exemplaire(s)
1984 : 12 exemplaire(s)

--------------------------------
Nombre de titres differents : 2
Nombre total d'exemplaires : 42
--------------------------------
```

## 🏗️ Structure du Projet

```
gestion-librairie/
│
├── gestion_librairie.c    # Code source principal
├── README.md              # Documentation
├── Makefile              # Fichier de compilation (optionnel)
└── examples/             # Exemples de données (optionnel)
    └── sample_data.txt
```

## 🔍 Détails Techniques

### Structures de Données

```c
#define MAX_LIVRES 100     // Nombre maximum de livres différents
#define MAX_TITRE 100      // Longueur maximale d'un titre
#define MAX_AUTEUR 100     // Longueur maximale d'un nom d'auteur

// Tableaux pour stocker les données
char titres[MAX_LIVRES][MAX_TITRE];
char auteurs[MAX_LIVRES][MAX_AUTEUR];
float prix[MAX_LIVRES];
int quantites[MAX_LIVRES];
int nombre_livres;         // Compteur de livres
```

### Fonctions Principales

| Fonction | Description | Complexité |
|----------|-------------|------------|
| `ajouterLivre()` | Ajoute un nouveau livre au stock | O(1) |
| `afficherTousLesLivres()` | Affiche tous les livres | O(n) |
| `rechercherLivre()` | Recherche un livre par titre | O(n) |
| `mettreAJourQuantite()` | Modifie la quantité d'un livre | O(n) |
| `supprimerLivre()` | Supprime un livre du stock | O(n) |
| `afficherTotalStock()` | Calcule et affiche les statistiques | O(n) |

### Gestion des Erreurs

- ✅ Vérification de la capacité maximale avant l'ajout
- ✅ Validation des entrées numériques
- ✅ Gestion du buffer d'entrée
- ✅ Confirmation avant suppression
- ✅ Messages d'erreur explicites

## 📝 Exemples d'Utilisation

### Scénario 1 : Gestion Quotidienne

```
1. Ajouter plusieurs livres au début de la journée
2. Consulter le stock disponible
3. Mettre à jour les quantités après ventes
4. Vérifier le total en fin de journée
```

### Scénario 2 : Inventaire

```
1. Afficher tous les livres
2. Rechercher les livres en rupture (quantité = 0)
3. Mettre à jour les quantités après réapprovisionnement
4. Supprimer les livres discontinués
```

## ⚠️ Limitations

- Maximum de 100 livres différents
- Pas de persistance des données (perte à la fermeture)
- Recherche uniquement par titre
- Pas de gestion multi-utilisateurs
- Pas d'historique des transactions

## 🚀 Améliorations Futures

### Court Terme
- [ ] Sauvegarde dans un fichier
- [ ] Chargement des données au démarrage
- [ ] Recherche par auteur
- [ ] Tri des livres (par titre, prix, quantité)

### Moyen Terme
- [ ] Interface graphique
- [ ] Base de données SQLite
- [ ] Gestion des catégories
- [ ] Système d'alertes pour stock faible

### Long Terme
- [ ] API REST pour accès distant
- [ ] Application mobile
- [ ] Intégration avec système de caisse
- [ ] Rapports et analyses

## 🛠️ Dépannage

### Problèmes Courants

**Problème : Le programme ne compile pas**
```bash
# Solution : Vérifier la version du compilateur
gcc --version

# Utiliser la norme C99 ou plus récente
gcc -std=c99 -o gestion_librairie gestion_librairie.c
```

**Problème : Caractères spéciaux non affichés**
```bash
# Windows : Changer l'encodage du terminal
chcp 65001

# Linux/Mac : Vérifier les locales
locale
```

**Problème : Erreur de segmentation**
```bash
# Compiler avec les symboles de débogage
gcc -g -o gestion_librairie gestion_librairie.c

# Utiliser gdb pour déboguer
gdb ./gestion_librairie
```

## 🤝 Contribution

Les contributions sont les bienvenues ! Pour contribuer :

1. Fork le projet
2. Créer une branche (`git checkout -b feature/AmazingFeature`)
3. Commit les changements (`git commit -m 'Add some AmazingFeature'`)
4. Push vers la branche (`git push origin feature/AmazingFeature`)
5. Ouvrir une Pull Request

### Conventions de Code

- Indentation : 4 espaces
- Noms de fonctions : camelCase
- Noms de variables : snake_case
- Commentaires en français
- Maximum 80 caractères par ligne

## 📊 Tests

### Tests Unitaires Recommandés

```c
// Test d'ajout de livre
void test_ajout_livre() {
    // Ajouter un livre
    // Vérifier que nombre_livres a augmenté
    // Vérifier que les données sont correctes
}

// Test de suppression
void test_suppression_livre() {
    // Ajouter plusieurs livres
    // Supprimer un livre
    // Vérifier que nombre_livres a diminué
    // Vérifier que le livre n'existe plus
}
```

## 👤 Auteur

**Votre Nom**
- GitHub: [@houssamBensiyed](https://github.com/HoussamBensiyed)
- Email: houssam.benssiyed123@gmail.com

## 📄 Licence

Ce projet est sous licence MIT - voir le fichier [LICENSE](LICENSE) pour plus de détails.

```
MIT License

Copyright (c) 2025 [Houssam Bensiyed]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction...
```

## 📞 Support

Pour toute question ou problème, veuillez ouvrir une [issue](https://github.com/houssamBensiyed/gestion-librairie/issues).

⭐ **N'oubliez pas de mettre une étoile si ce projet vous a été utile !** ⭐
