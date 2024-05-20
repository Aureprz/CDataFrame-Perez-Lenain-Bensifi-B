# Projet CDataFrame

Réalisé par : Aurélien Perez, Titouan Lenain et Racim Bensifi



## Lien Github : 

https://github.com/Aureprz/CDataFrame-Perez-Lenain-Bensifi-C

## Installation

Pour les développeurs, il faut installer [Git](https://git-scm.com/).
Puis, il faut cloner le dépôt :
```bash
git clone https://github.com/Aureprz/CDataFrame-Perez-Lenain-Bensifi-C
```
Et enfin **run** le fichier:
-  [main.c](https://github.com/Aureprz/CDataFrame-Perez-Lenain-Bensifi-C/blob/master/main.c)

## Présentation

Ce projet a pour but de réaliser des structures permettant de recueillir des données à l'apparence d'un tableur, de manière similaire à celle utilisée par les data scientists : les dataframe.
Néanmoins, ce projet réalisé en langage C.


## Fichiers importants

* column.h : contient l'essentiel du projet, c'est-à-dire les éléments et caractéristiques d'une colonne comme son titre, ses tailles (logique et physique) ou encore le type de données qu'elle peut contienir

* list.h : comme nous avons choisi d'utiliser la structure d'une liste doublement chaînée, il était donc nécessaire de créer ce fichier

* cdataframe.h : va permettre de "regrouper" plusieurs colonnes ensembles à la manière d'un tableur et d'ensuite pouvoir manipuler l'ensemble. C'est celui-ci qui sera utilisé à travers le projet (à l'aide des autres fichiers bien évidemment)

## Précisions pour les fonctions

Si vous avez besoin d'informations sur certaines fonctions, celles-ci sont disponible dans leur fichier.h attitré. Vous pourrez alors connaître pour chaque fonction :
* @brief : le principe, le but de cette fonction
* @param : le(s) paramètre(s). S'il y en a plusieurs, ils sont numérotés
* @return: ce vers quoi la fonction retourne, seulement si elle retourne quelque chose
