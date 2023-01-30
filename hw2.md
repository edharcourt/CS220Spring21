# Homework 2 (20 points)

Due Monday February 5th by the start of class at 9:20AM.

Due Monday February 1 by 1:30PM. Remember you can turn it in late with a 10% per day late penalty. 

In this assignment you will write a few different C functions and call them from your main function. Create a directory named `hw2` in your course repo. Make sure the directory is named lowercase `hw2` and not `HW2` or `Hw2`, etc. Make sure all of the files outlined below are in your `hw2` directory and updated in your personal course repo by the due date and time. 

1. [5 points] Write a C function `first_nonrepeat` that takes a string and returns the index of the first non-repeated chracter in the string. Put this function in a file `first_nonrepeat.c`. For instance, the index of the first nonrepeated character in "total" is 1 (because it is the index of "o")  and the index of the first non-repeated character in "teeter" is is 5 (because the index of "r" is 5). If the string does not have any non-repeated characters (such as "meme" and "unprosperousness") the function should return -1. 

    extern int first_nonrepeat(char \*str);

    Hint: I can think of two obvious ways to write this function. One is a brute force way that looks at the characters in the input string multiple times. The other way only loops through the string at most twice and uses the fact that characters in C are really 8 bit integers and you could use a character as an index into an array that kept track of character frequencies. (How big does the array need to be?). Partial credit for the brute force technique and full credit for using the characters as an index into an array. 

    // These should all print 1 (true)
	printf("%d\n", first_nonrepeat("total") == 1); 
    printf("%d\n", first_nonrepeat("teeter") == 5);
    printf("%d\n", first_nonrepeat("unprosperousness") == -1); 
    printf("%d\n", first_nonrepeat("palatial") == 0);

2. [5 points] Write a C function `unique_region` that takes an array of integers and returns the length of the longest region of the array where all of the elements are unique.  Put this in a file named `unique_region.c`. For example, if given the C array `5, 1, 3, 5, 2, 3, 4, 1` the function would return 5 because the subarray `5, 2, 3, 4, 1` is the longest subarray where all of the elements are different. 

    extern int unique_region(int vec[], int n);

    // Here are some more tests
    int test1[] = {1, 1, 1, 1, 1, 1};
    printf("%d\n", unique_region(test1, 6) == 1);

    int test2[] = {1, 1, 2, 3, 4, 5, 3};
    printf("%d\n", unique_region(test2, 7) == 5);

    int test3[] = {129, 990000000, 12345, 99};
    printf("%d\n", unique_region(test3, 4) == 4);


3. [5 points] Write a function `mirror` (in the file `mirror.c`) that takes an `unsigned char n` (an 8 bit unsigned an integer) and returns a 1 (true) if the bits of `n` read the same forward and backwards. For example, 195 in base ten is 11000011 in binary. So `mirror` would return 1. The call `mirror(1)` would return 0 because the reverse of 1 (1 is really 
`00000001`) is an 8 bit integer is `10000000`. Use bit operations to write this function. Don’t use strings.  

    printf("%d\n", mirror(195) == 1); 
    printf("%d\n", mirror(1) == 0);  
    printf("%d\n", mirror(255) == 1);  
    printf("%d\n", mirror(165) == 1);  

Hint: Don’t overthink this problem and make it more complicated than it 
needs to be.  Think about our bit operatations `&`, `|`, `<<`, `>>`. 

4. [5 points] Write a `main.c` that calls each of your functions above. 
 