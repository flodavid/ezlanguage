#!/bin/bash

error_encountered=0
function run_test {
        output=$(echo "${1//.ez/.run}")
        $(dirname $0)/../bin/EZ_language_compiler --warning --noexec $(dirname $0)/$1 -o $output
        if [ $? -ne 0 ]
        then echo -e "\n\n    \033[1;31mTest failed \e[0m\n"; error_encountered=1
        else echo -e "\n\n    \033[1;32mTest succeeded !\e[0m\n"
        fi
}
function check_tests_success {
        if [ $error_encountered != 0 ]
        then
                echo -e "\n\033[1;31m=========================================="
                echo -e "\t\033[1;31m Some tests have failed :("
                echo -e "\033[1;31m==========================================\033[0m\n"
        else
                echo -e "\n\033[1;32m=========================================="
                echo -e "\t\033[1;32m All tests succeeded :)"
                echo -e "\033[1;32m==========================================\033[0m\n"
        fi
}
