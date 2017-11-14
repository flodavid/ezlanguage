#!/bin/bash

error_encountered=0
function run_test {
        $(dirname $0)/../bin/EZ_language_compiler $(dirname $0)/$1
        if [ $? -ne 0 ]
        then echo -e "\n\n    \033[1;31mTest failed \e[0m\n"; error_encountered=1
        else echo -e "\n\n    \033[1;32mTest succeeded !\e[0m\n"
        fi
}
function check_tests_success {
        if [ $error_encountered != 0 ]
        then
                echo -e "\n\033[1;31m=========================================="
                echo -e "\t Some tests have failed :("
                echo -e "==========================================\033[0m\n"
        else
                echo -e "\n\033[1;32m=========================================="
                echo -e "\t All tests succeeded :)"
                echo -e "==========================================\033[0m\n"
        fi
}

echo -e "\n\033[1;33m=========================================="
echo -e "\tComponents tests execution"
echo -e "==========================================\033[0m\n"

# Execute tests
echo "Test 1 : main_simple" 
run_test 1_main_simple.ez

echo "Test 2 : procedure_vide" 
run_test 2_procedure_vide.ez

check_tests_success
#echo "Test 3 : julia"
#$ROOT/../bin/EZ_language_compiler julia.ez
