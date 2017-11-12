 #!/bin/bash

COMPILER=$(dirname $0)/../bin/EZ_language_compiler

echo -e "\n\033[1;33m=========================================="
echo -e "\tExécution des autres tests"
echo -e "==========================================\033[0m\n"
# Execute tests
echo "Test 1 : person" 
$COMPILER person.ez
echo "Test 2 : class" 
$COMPILER test_class.ez

rm -f person.cpp test_class.cpp
