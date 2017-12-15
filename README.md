# ProjetCCometBuster

## Fonction réalisé : 

  - Fichier linked_list.c complété : 
    - Fonctions pour copier la liste chainé pas complétement implémentée car pas utilisées
  
  - Système de gestion des scores en mode console : 
    - Ajout de fichier score.h et score.c. Les scores sont convertis dans un type structuré contenant un nom et un score.
    - Toutes les stuctures contenants les scores sont ensuite ajouté dans un tableau de highscores.
    - Le score du joueur courant est sauvegardé au bon endroit dans le tableau (1 iteration tri insertion).
    - Enfin sauvegarde du tableau dans le fichier de score.
    - Note : Il est possible de changer le nombre de caractères maximum du nom & le nombre de scores disponibles en modifiant les constantes dans scores.h
  
  ## Améliorations en cours :
  - Ajout de l'affichage des meilleurs scores en mode graphique à la fin de la partie.
  - Option pour rejouer directement aprés une partie.
  
  ## Bugs :
  
  - Segmentation fault lorsque l'on perds notre dernière vie sur les PC de l'école.
