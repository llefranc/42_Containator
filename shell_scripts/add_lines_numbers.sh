#! /bin/sh

# Replace all occurences of TOREPLACE word with the line number. Usefull for printTestName
# and printContainer functions in each *container*_test.hpp files.

NUMBERLINE=""

while grep "TOREPLACE" list_tests.hpp > /dev/null;
	do
	NUMBERLINE=$(grep -n "TOREPLACE" list_tests.hpp | head -1 | cut -d ':' -f1)
	tr '\n' '~' < list_tests.hpp | sed "s/TOREPLACE/$NUMBERLINE/1" | tr '~' '\n' > tmp.cpp
	cat tmp.cpp > list_tests.hpp
	done
