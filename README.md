# Containator

![Alt text](https://github.com/llefranc/42_Containator/blob/main/cartoon_containator.png)

Containator is a personnal project that I did with Hélène Herin (@hherin). It’s a tester for ft_containers, a 42 school project, where you have to reimplement some containers from the C++ STL. It will test the 5 following containers :
- :arrow_right: **Vector**
- :arrow_right: **List**
- :arrow_right: **Stack**
- :arrow_right: **Queue**
- :arrow_right: **Map**
  
You can choose which containers and which  methods you want to test. It’s running **several hundreads of tests for each of your containers**, then doing the same with the real STL containers and making **a diff of the two outputs**.   
**Each test on the output has a line number** indicating where the test is situated in the test file. That way, you can easily find which test isn't working if an error occured.

## How to run it

1. Git clone the project into your ft_containers repository.
    ```shell
    git clone https://github.com/llefranc/42_Containator.git
    ```

2. Open `include_your_files.hpp` at the root directory and includes your containers files. It's not a problem if you haven't done all containers, you can later choose which container you want to test. Just comment the container's includes you're missing. You have to include aswell your ft_pair. If you didn't implemented it, you can use my own version (`includes_and_utils/my_ft_pair.hpp`).
    ```c++
    #include "../42_ft_containers/pair.hpp"

    #include "../42_ft_containers/vector.hpp"   // Comment if you don't want to test VECTOR   
    // #include "../42_ft_containers/list.hpp"     // Comment if you don't want to test LIST
    #include "../42_ft_containers/stack.hpp"    // Comment if you don't want to test STACK
    // #include "../42_ft_containers/queue.hpp"    // Comment if you don't want to test QUEUE
    #include "../42_ft_containers/map.hpp"      // Comment if you don't want to test MAP
    ```

3. In the file `select_your_tests/select_containers.cpp`, you can choose which containers you want to test by commenting the calls to the containers' test functions, and commenting also the code of the test function.
    ```c++
    // ---------------------------------------------------------------------------
    // CHOOSE HERE WHICH CONTAINERS YOU WANT TO TEST. YOU HAVE ALSO TO COMMENT
    // THE WHOLE FUNCTION BELOW.
      
    testVector(arrInt, arrString);  // Comment if you don't want to test VECTOR   
    // testList(arrInt, arrString);    // Comment if you don't want to test LIST   
    testStack(arrInt, arrString);   // Comment if you don't want to test STACK 
    // .... 

    // And then commenting the function below
    // ---------------------------------------------------------------------------
    // COMMENT THE WHOLE FUNCTION IF YOU DON'T WANT TO TEST LIST.
    // ---------------------------------------------------------------------------
    // void    testList(const int (&arrInt)[20], const std::string (&arrString)[20])
    // {
    //
    //     std::streambuf *coutbuf = std::cout.rdbuf();
    //     std::ofstream stdFile("results/list_std.txt");
    // ....
    ```
3. In the five others files (`select_your_tests/select_xxx_tests.hpp`), you can choose for each containers with methods you want to test by commenting the calls to the methods' test functions.
    ```c++
    // In the file selecs_list_tests.hpp, not testing method empty.
    template <typename T>
    void    testNotConstList(T& l, int testNb)
    {
        printContainerInfo<T>("LIST", testNb);
        
        listTest_Size(l);                       //  size
        // listTest_Empty(l);                      //  empty
        listTest_Iterators(l);                  //  iterators / begin / end
        // ....
        ```

4. Run then the shell script to launch the tester.
    ```shell
    ./testContainers.sh
    ```

5. Result outputs of the STL containers and yours will be created in `results/` directory. If your output for a container differs from STL container, a diff file will be also created.
    ```shell
    cat results/list_diff.txt
    ```

## I got some differences with STL containers, how to check my errors more precisely ?

In the files created in `results/` directory, **line numbers of each test are indicated** (+ the name of the method tested). You just have to open the `xxx_diff.txt` file and look for the line number of the failed test, and then looks directly to the test in the `each_tests/` directory.  
For example, if you have failed iterators test for list container, diff file will look like this:

```shell
# the first result line is FT file, the other STL file
13c13
< line 42: iterators: operator++:             589667777 | # << YOUR FT FILE
---
> line 42: iterators: operator++:             58966     | # << STL FILE (correct result)
```

You then just have to open `each_tests/list_tests.hpp` and jump to the `line 42` to see the code that created a bug, and then use this piece of code to test it by yourself in order to solve the problem.

## Some tips to help you to solve more easily the bugs

:sos: **We know that it can be a little bit tricky to make the tester compile the first time.** :sos:  
  
It's using a lot of templates functions, and if you have something wrong in your code a lot of compilation error messages will appear. Don't be scared and take the time to look the error messages and **find which method isn't compiling**.  
Try to do more testing by yourself on the errored method to find the problem, **fix it and run the tester again**.  
  
If you're thinking that there is an error inside the tester, you can check that nothing is wrong by opening `each_tests/exec_each_test.cpp` file, and commenting all the calls to the FT test functions, and then run again the tester. You will see that with the STL, the tester is compiling normally, so you have something to fix in your code.