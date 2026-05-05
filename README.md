# Automate cellulaire – Jeu de la Vie étendu en C

## Description

Ce projet est une implémentation en langage C d’un automate cellulaire inspiré du Jeu de la Vie de Conway.

Contrairement à la version classique, cette simulation introduit :
- un **seuil de survie**
- un **compteur de vie pour chaque cellule**

Le système évolue sur une grille 2D en fonction des états des cellules voisines, permettant d’explorer des dynamiques différentes du modèle original.

---

## Fonctionnalités

- Simulation d’un automate cellulaire sur une grille carrée
- Lecture de la configuration initiale via l’entrée standard ou fichiers `.dat`
- Calcul des voisins (8 directions)
- Évolution du système sur plusieurs itérations
- Gestion d’un seuil de survie
- Intégration d’un compteur de vie pour chaque cellule

---

## Règles de simulation

Pour chaque cellule de la grille :

- On calcule la somme des 8 voisins
- Si la somme est **supérieure au seuil** → la cellule meurt
- Si la somme est **égale au seuil** :
  - la cellule survit
  - son “niveau de vie” est ajusté (incrément ou décrément)
- Sinon :
  - la cellule reste inchangée

Cette approche constitue une **variante du Jeu de la Vie**, permettant d’étudier d’autres comportements émergents.

---

## Structure du projet

```text id="gol_struct_final"
.
├── src/
│   └── main.c
├── tests/
│   ├── F0.dat
│   ├── F1.dat
│   ├── F2.dat
│   ├── F3.dat
│   ├── F4.dat
│   ├── F5.dat
│   ├── F6.dat
│   ├── F7.dat
│   ├── F8.dat
└── README.md
