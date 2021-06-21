#! /bin/sh
BLUE=$'\e[0;36m'
NC=$'\e[0m'

echo "~ Makefile is compiling ~\n";
make re
rm -rf results/*.txt
./containers_test

echo "~ Test diff output from std::vector and your work ~";
if diff results/vector_ft.txt results/vector_std.txt > /dev/null;then
    echo "${BLUE}No differences${NC}";
else 
	diff results/vector_ft.txt results/vector_std.txt > results/vector_diff.txt
    echo "${BLUE}Try again${NC}";
fi

echo "~ Test diff output from std::list and your work ~";
if diff results/list_ft.txt results/list_std.txt > /dev/null;then
    echo "${BLUE}No differences${NC}";
else 
	diff results/list_ft.txt results/list_std.txt > results/list_diff.txt
    echo "${BLUE}Try again${NC}";
fi

echo "~ Test diff output from std::stack and your work ~";
if diff results/stack_ft.txt results/stack_std.txt > /dev/null;then
    echo "${BLUE}No differences${NC}";
else 
	diff results/stack_ft.txt results/stack_std.txt > results/stack_diff.txt
    echo "${BLUE}Try again${NC}";
fi

echo "~ Test diff output from std::queue and your work ~";
if diff results/queue_ft.txt results/queue_std.txt > /dev/null;then
    echo "${BLUE}No differences${NC}";
else 
	diff results/queue_ft.txt results/queue_std.txt > results/queue_diff.txt
    echo "${BLUE}Try again${NC}";
fi

echo "~ Test diff output from std::map and your work ~";
if diff results/map_ft.txt results/map_std.txt > /dev/null;then
    echo "${BLUE}No differences${NC}";
else 
	diff results/map_ft.txt results/map_std.txt > results/map_diff.txt
    echo "${BLUE}Try again${NC}";
fi

echo "";
make fclean
