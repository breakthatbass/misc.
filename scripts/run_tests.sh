#!/bin/bash

# this script was created to run multiple test files created with the minunit
# testing framework for C programs.
# each file needs its own main function so each file has to be compiled seperately
# 
# this script attempts to compile each file, if successful, runs it.
# at the end it deletes all compiled files and print out information

#!/bin/bash

# colors for printing
RED='\033[1;31m'
GREEN='\033[1;32m'
BLUE='\033[1;36m'
NC='\033[0m' # No Color

FLAGS='add flags here'
DEPENDENCIES='add files to test here'

for i in *_tests.c
do
    echo -e "- building ${BLUE}$i${NC}"
    if gcc $i $DEPENDENCIES $FLAGS -o "${i%.c}.out"; then
        echo -e "- build ${GREEN}succeeded!${NC}"
        echo "- running file"
        ./"${i%.c}.out"
    else
        echo -e "$i build ${RED}failed${NC}..."
    fi
done

rm *.out