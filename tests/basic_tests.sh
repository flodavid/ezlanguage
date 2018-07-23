#!/bin/bash

. $(dirname "$0")/test_functions.sh

echo -e "\n\033[1;33m=========================================="
echo -e "\t\033[1;33mComponents tests execution"
echo -e "\033[1;33m==========================================\033[0m\n"

debug=false

while getopts "hv" arg; do
  case $arg in
    h)
      echo "usage: $0 [-v] [-h]" 1>&2; exit 1; 
      ;;
    v)
      debug=true
      ;;
  esac
done

# Execute tests
echo "Test 1 : main_simple"
if [ "$debug" = true ]
then run_test_traces 1_main_simple.ez 4_display_module.ez
else run_test 1_main_simple.ez 4_display_module.ez
fi

echo "Test 2 : procedure_vide"
if [ "$debug" = true ]
then run_test_traces 2_procedure_vide.ez
else run_test 2_procedure_vide.ez
fi

check_tests_success
#echo "Test 3 : julia"
#$ROOT/../bin/EZ_language_compiler julia.ez
