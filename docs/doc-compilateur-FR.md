# Utilisation du compilateur
EZ_language_compiler [options] fichier


# Liste complète des options en ligne de commande
## Options de base
**--output:** spécifie le nom du fichier binaire en sortie.  
Version courte :  -o  
**--help:** affiche la liste des options du compilateur EZ et leurs fonctions.   
Version courte :  -h  
## Options d’optimisation
**--optimisation=n:** Indique au compilateur d’optimiser le code binaire généré, correspond aux options o 1..3 du compilateur g++.    
Version courte : -o n  
## Options de debug
**--verbose:** affiche toutes les étapes de compilation du compilateur EZ.  
**--warning:** affiche l’ensemble des messages de type « warning ».  
Version courte : -w  
## Options autres
**--noexec:** indique au compilateur qu’il ne faut pas lancer l’exécutable après la compilation  .
