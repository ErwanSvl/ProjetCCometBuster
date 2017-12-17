# ProjetCCometBuster

## Contributeurs

- Killian THEZELAIS
- Erwan SEVELLEC

## Fonction réalisé

- Fichier linked_list.c complété :
  - Fonctions pour copier la liste chainé pas complétement implémentée car pas utilisées

- Système de gestion des scores en mode console :
  - Ajout de fichier score.h et score.c. Les scores sont convertis dans un type structuré contenant un nom et un score.
  - Toutes les stuctures contenants les scores sont ensuite ajouté dans un tableau de highscores.
  - Le score du joueur courant est sauvegardé au bon endroit dans le tableau (1 iteration tri insertion).
  - Enfin sauvegarde du tableau dans le fichier de score.
  - Note : Il est possible de changer le nombre de caractères maximum du nom & le nombre de scores disponibles en modifiant les constantes dans scores.h.
- Sélection du mode affichage :
  - Exécuter le programme sans arguments lance l'affichage des highscores en mode console.
  - Exécuter le programme avec l'argument "graphic" (./cometbuster graphic) lance en mode graphic (Pas encore implémenté).

## Améliorations en cours

- Ajout de l'affichage des meilleurs scores en mode graphique à la fin de la partie.
- Option pour rejouer directement aprés une partie.

## Bugs

- [x] ~~Segmentation fault lorsque l'on perds notre dernière vie sur les PC de l'école.~~ (Résolu).
- Si le fichier score.txt n'existe pas, on retourne un message d'erreur et on ne cherche pas à le créer (le cas fichier vide est géré).
- Enregistrement du meilleur score en mode console même si quitté avec 'q'.

## Remarques

- Git a ici été utilisé comme un outil de gestion des sources et non comme outil de pair programming, cela explique pourquoi tous les commit sont issus de la même machine.