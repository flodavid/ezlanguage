 #!/bin/bash

COMPILER=$(dirname $0)/../bin/EZ_language_compiler

echo -e "\n\033[1;31m=========================================="
echo -e "\tExécution des tests non valides"
echo -e "==========================================\033[0m\n"
# Execute tests
echo "Test 1 : julia" 
$COMPILER julia.ez

rm -f julia.cpp
