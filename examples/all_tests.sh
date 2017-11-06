#!/bin/bash

sh $(dirname $0)/valid_tests.sh
sh $(dirname $0)/unvalid_tests.sh
sh $(dirname $0)/other_tests.sh

