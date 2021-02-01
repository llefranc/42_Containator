#! /bin/sh

NUMBERLINE=""

while grep "TOREPLACE" list_tests.hpp > /dev/null;
	do
	NUMBERLINE=$(grep -n "TOREPLACE" list_tests.hpp | head -1 | cut -d ':' -f1)
	tr '\n' '~' < list_tests.hpp | sed "s/TOREPLACE/$NUMBERLINE/1" | tr '~' '\n' > tmp.cpp
	cat tmp.cpp > list_tests.hpp
	# awk '{for(i=1;i<=NF;i++){if(x<27&&$i=="TOREPLACE"){x++;sub("TOREPLACE", $NUMBERLINE,$i)}}}1' main.cpp
	# echo $NUMBERLINE
	done


# grep -n "TOREPLACE" main.cpp | head -1 | cut -d ':' -f1;