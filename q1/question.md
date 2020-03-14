# Question 1

Implement the function:

    string* createWordsArray(string sentence, int& outWordsArrSize)

This function gets a string sentence containing a sentence. When called, it 
should create and return a new array (of strings), that contains all the
words in sentence. The function should also update the output parameter,
outWordsArrSize, with the logical size of the new array that was created.

Note: Assume that the words in the sentence are separated by a single space.

For example, if sentence=”You can do it”, after calling
`createWordsArray(sentence, outWordsArrSize)`, the function should create
and return an array that contains `[”You” , ”can” , ”do” , ”it”]`, and update 
the value in `outWordsArrSize` to be 4.

## Implementation requirements

1. You may want to use some of the string methods, such as find, substr, etc.
2. Your function should run in linear time. That is, if sentence contains n characters,
   your function should run in θ(n).
3. Write a `main()` function that tests this function.
