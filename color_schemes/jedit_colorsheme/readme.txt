#instructions d'utilisation de la coloration syntaxique jedit
le fichier de coloration syntaxique pour JEdit réconnait en plus de la syntaxe d'ezlanguage, la syntaxe du c et du c++ 


1. pour utiliser la coloration syntaxique avec JEdit un fichier catalog est nécéssaire
   ce fichier est fourni lors de l'installation de jedit et est localisé dans le repertoire:
   /home/VOTRE_USER/.jedit/modes/ 
   c'est ce fichier qui permet à jedit de reconnaitre le language pour lequel vous venez de créer un fichier de coloration
   il faut donc ajouter dans ce fichier entre les balises <MODES> </MODES> la ligne :
   <MODE NAME="ezlanguage" FILE="ezlanguage.xml" FILE_NAME_GLOB="*.ezl" /> 
2. copier le fichier de coloration syntaxique "ezlanguage.xml" dans le même repertoire que ce fichier catalog à savoir 
   /home/VOTRE_USER/.jedit/modes/ 
   
3. pour faire simple rassurez vous que le fichier catalog est bien présent dans le répertoire /home/VOTRE_USER/.jedit/modes/ 
   puis exécutez le script color.sh
   
4. si le fichier catalog n'est pas présent dans l'arborescence il faut exécuter le script
   catalog_color.sh
   
   
5. si vous ajoutez de nouveaux mots clés ou de nouveaux types pour les faire réconnaitre il faut les ajouter dans le fichier de coloration de jedit
   à savoir ezlanguage.xml
   
   - pour cela, selon la couleur que vous voulez utiliser pour ces mots clés les ajouter entre les balises
   
   <KEYWORD1> mot_cle </KEYWORD1>
   <KEYWORD2>mot_cle</KEYWORD2>
   <KEYWORD3>mot_cle</KEYWORD3>
   
   ou même plus en utilisant <LITERAL2>mot_cle</LITERAL2>
   
   référence
   http://fr.ancestris.org/index.php?title=Fichier_de_coloration_syntaxique
   

