# Question 3

In this question, you will write two versions of a program that reads from the 
user a sequence of positive integers ending with -1, and another positive 
integer num that the user wishes to search for.

The program should then print all the line numbers in sequence entered by the 
user that contain num, or a message saying that num does not show at all in 
the sequence.

Your program should interact with the user exactly as it shows in the following example:

    Please enter a sequence of positive integers, each in a separate line.
    End your input by typing -1.
    13
    5
    8
    2
    9
    5
    8
    8
    -1
    Please enter a number you want to search.
    5
    5 shows in lines 2, 6.

The first version of the program is not allowed to use the vector data structure.
The second version of the program should use the vector data structure.

## Implementation requirements (for both programs)

1. Think how to break down your implementation to functions.
2. Your programs should run in linear time. That is, if there are n numbers in 
   the input sequence, your program should run in θ(n).
3. Write the two programs in two functions named `main1()` and `main2()`. Also 
   have the `main()` test these two functions.

