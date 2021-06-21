# Containator

Containator is a personnal project that I did with Hélène Herin. It’s a tester for ft_containers, a 42 school project, where you have to reimplement some containers from the C++ STL.

It will test the 5 following containers : vector, list, queue, stack and map. You can choose which containers and which  methods you want to test.

It’s running several hundreads of tests for each of your containers, then doing the same with the real STL containers and making a diff of the two outputs. 

It will first generate anEach test on the output has a line number indicating to indicate where the test is situated in the test file. That way, you can easily find which test isn't working if an error occured.

## How to run it

Git clone the project into your ft_containers repository.

Open 'include_your_files.hpp' and includes your containers files. It's not a problem if you haven't done all containers, you can later choose which container you want to test.

In the directory select_your_tests, you can choose:
	- With the file 'select_containers.cpp', which containers you want to test by commenting the calls to the containers' test functions.
	- With all the other files, you can choose for each containers with methods you want to test by commenting the calls to the methods' test functions.

Run then the shell script to launch the tester. Result outputs of the STL containers and yours will be created in 'results' directory. If your output for a container differs from STL container, a diff file will be also created.

## I got some differences with STL containers, how to check my errors more precisely ?

In the files created in 'results' directory, line numbers of each test are indicated (+ the name of the method tested). You just have to open the diff file and look for the line number of the failed test, and then looks directly to the test in the 'each_tests' directory.

For example, if you have failed iterators test for list container, diff file will look like this:
(the first result line if FT file, the other STL file)

13c13
< line 42: iterators: operator++:             589667777 | << YOUR FT FILE
---
> line 42: iterators: operator++:             58966 |     << STL FILE (correct result)

You then just have to open 'each_tests/list_tests.hpp' and jump to the line 42 to see the code that created a bug, and then use this piece of code to test it by yourself in order to solve the problem.

## Some tips to help you to solve more easily the bugs

We know that it can be a little bit tricky to make the tester compile the first time. It's using a lot of templates functions, and if you have something wrong in your code a lot of compilation error messages will appear. Don't be scary and take the time to look the error messages and find which method isn't compiling. Try to do more testing by yourself on the errored method to find the problem, fix it and run the tester again.

If you're thinking that there is an error inside the tester, you can check that nothing is wrong by opening 'each_tests/exec_each_test.cpp' file, and commenting all the calls to the FT test functions, and then run again the tester. You will see that with the STL, the tester is compiling normally, so you have something to fix in your code.

If you're facing some differences,

<<<<<<<<<<<<<<<<<<<< AJOUTER UN TRUC QUI CHECK QUAND UN CONTAINER N'EST PAS TEST, DIFF BUG >>>>>>>>>>>>>>>>>>>>
<<<<<<<<<<<<<<<<<<<< CHANGER PEUT ETRE AUSSI L'OUTPUT DU TESTER >>>>>>>>>>>>>>>>>>>>
