#!/bin/bash

. $(dirname "$0")/test_functions.sh

echo -e "\n\033[1;33m=========================================="
echo -e "\t\033[1;33m Valid programs tests execution"
echo -e "\033[1;33m==========================================\033[0m\n"

# Execute tests
echo "Test 1 : main_simple" 
run_test 1_main_simple.ez
run_test 2_procedure_vide.ez
run_test 3_fonction_vide.ez
run_test 4_affichage.ez

# Program modules tests
run_test example.ez
run_test module_program/person.ez
run_test module_program/progam.ez

check_tests_success
