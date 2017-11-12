#!/bin/bash

# les fichiers de tests 'person' et 'julia' sont incohérents avec ce l'equipe langage a definit, et contient des instructions que je viens de voir pour la première fois ( genre : structure -  for  in parallel ), la raison pour laquelle le teste sur ces deux fichiers ne réussira pas.

# Execute tests
echo "Test 1 : exemple" 
../bin/EZ_language_compiler exemple.ez
echo "Test 2 : person" 
#../bin/EZ_language_compiler person.ez
echo "Test 3 : julia" 
#../bin/EZ_language_compiler julia.ez

