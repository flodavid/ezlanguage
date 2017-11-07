#!/bin/bash

COMPILER=$(dirname $0)/../bin/EZ_language_compiler

echo -e "\n\033[1;32m=========================================="
echo -e "\tExécution des tests valides"
echo -e "==========================================\033[0m\n"
# Execute tests
echo "Test 1 : empty_program"
$COMPILER empty_program.ez
echo "Test 2 : example"
$COMPILER example.ez
echo "Test 3 : affectations_calculs"
$COMPILER affectations_calculs.ezl

rm -f empty_program.cpp example.cpp affectations_calculs.cpp
