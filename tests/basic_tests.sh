#!/bin/bash

. $(dirname "$0")/test_functions.sh

echo -e "\n\033[1;33m=========================================="
echo -e "\t\033[1;33mComponents tests execution"
echo -e "\033[1;33m==========================================\033[0m\n"

# Execute tests
echo "Test 1 : main_simple"
run_test 1_main_simple.ez

echo "Test 2 : procedure_vide"
run_test 2_procedure_vide.ez

check_tests_success
#echo "Test 3 : julia"
#$ROOT/../bin/EZ_language_compiler julia.ez
