#! /bin/sh
BLUE=$'\e[0;36m'
NC=$'\e[0m'

echo "~ Makefile is compiling ~\n";
make re
./containers_test

echo "~ Test diff output from std container and your work ~";
if diff results/ft_vector.txt results/std_vector.txt > /dev/null;then
    echo "${BLUE}No differences${NC}";
else 
	diff results/ft_vector.txt results/std_vector.txt > results/diff_vector.txt
    echo "${BLUE}Try again${NC}";
fi

echo "";
make fclean
