#! /bin/sh
BLUE=$'\e[0;36m'
NC=$'\e[0m'

echo "~ Makefile is compiling ~\n";
make re
./containers_test

echo "~ Test diff output from std container and your work ~";
if diff -u result/ft_vector.txt result/std_vector.txt;then
    echo "${BLUE}No differences${NC}";
else 
    echo "${BLUE}Try again${NC}";
fi

echo "";
make fclean
