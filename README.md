# Project 1 - Encoding and Decoding Text

## Introduction

The goal of this project is to learn about UNIX filters, as well as get some insight into ASCII characters and abstract C programming. This project builds on the work we did in Lab 1 to introduce filters.

You will need to write the code for two C filter programs, an encoding program and a decoding program. Both of these programs should behave as UNIX filters; they should read character input from standard input (stdin), and write character output to standard output (stdout). Any messages designed for human consumption should be written to standard error (stderr). That allows us to use UNIX standard input and output redirection, and we can create invocations such as:

```bash
>./encode key <raw.txt >encoded.txt # Read input from raw.txt and write encoded output to encoded.txt
>./decode key <encoded.txt # Read input from encoded.txt and write results to the screen
>/.encode key <raw.txt | ./decode key # Read input from raw.txt, encode it, decode it, and write results to the screen
```

(See [Introduction to Linux: I/O Redirection](https://tldp.org/LDP/intro-linux/html/sect_05_01.html) if you don't understand redirection.)

You will first need to choose an encode/decode algorithm. There are many valid alternatives. The basic ground rules are as follows:

1. Your algorithms must read ASCII text as input, and produce ASCII text as output.

2. Your algorithms should accept a key, an ASCII blank delimited "word" as a parameter. Different keys should produce different enciphered text. We are assuming that the key is known by both the sender (encipherer) and receiver (decipherer) of the message.

3. No command line parameters other than the key command line parameter should be required to run either encode or decode.

4. The output of the encode program must not match the input. The output of the encode program should not indicate the original text message.

5. If you encipher input text with a specific key, and then use that same key to decipher the result, the result should match the original input text, where "matching" is defined as follows:

   1. Alphabetic characters must match, but the case (upper case or lower case) does not need to be maintained. For example, if the input text is "Testing", then the output result can be "testing" or "TESTING" or "tESTING".
   2. Any white-space character or string of characters, such as blanks, tabs, or newlines, should match.
   3. Any numeric ASCII characters such as '1' or '7' should match.
   4. Any character that is not alphabetic, white space, or numeric, such a punctuation or symbols may match, or may be translated to '*'

6. If you encipher input text with a specific key, and then use a *different* key to decipher the result, the results should **not** match the original input text.

The simplest encoding/decoding mechanism is a simple substitution. See Wikipedia [Substitution Cipher / Simple Substitution](https://en.wikipedia.org/wiki/Substitution_cipher#Simple_substitution) for details. In this case, the "key" parameter should either define or select the substitution alphabet.

Note that it is perfectly valid, and relatively common for an encode algorithm to be an *involution*; that is, the decode function is exactly the same as the encode function. If you choose such an algorithm, then just copy encode.c to decode.c after debugging encode.

Don't spend too much time choosing an encode/decode algorithm. The point of this project is not to come up with the most sophisticated encryption/decryption algorithm, but to learn about coding and redirection.

## Provided to you

The proj01 repository already contains some infrastructure to get you started, as follows:
  
- **encode.c** - The start of the program to encode raw text into ciphered text. You will need to edit this file to implement your encoding algorithm. The file includes some comments that give some high level pseudo-code to get you started.

- **decode.c** - The start of the program to decode the encoded text and recover the raw text. You will need to edit this file to implement your decoding algorithm. Ths file includes some comments that give some high level pseudo-code to get you started.

- **test.txt** - Some arbitrary raw text to try out your encode and decode programs.

- **Makefile** - A make file to simplify building and testing your code. It includes targets to make the encode and decode programs, as well as `test` and `clean` targets.

## Coding the project

Your job is to code and test the code in `encode.c` and `decode.c`. You may use anything from the C library code, but I've highlighted some useful library code in the hints below.

## Hints and Suggestions

1. I found it easiest to do most of the standard input and output I/O one character at a time using `getchar` and `putchar`.

2. You may use `feof(stdin)` to check to see if you have reached the end of file for standard input. If you have read a character into an `input` variable, you can also use `(input==EOF)` to test for the end of file for standard input.

3. You may use `toLower(input)` to convert a single input character to lower case. Don't forget to include `ctype.h`.

4. To look up a character in a string, you can use `char * foundPtr=strchr(string,input)`. This will return a pointer to the first instance of `input` in `string`, where `input` is a single character, and `string` is an array of characters (or pointer to a list of characters.) If `input` is not present in `string`, this will return a NULL pointer. For non-null results, you can use pointer arithmetic: `foundPtr-string` to get the index of `input` in `string`. Don't forget to include `string.h`.

5. Use the `rand()` function to return a random integer value between 0 and `RAND_MAX`, where RAND_MAX is guaranteed to be at least 32,767 (the largest positive two's complement integer that fits in 16 bits), but may be larger. To get a random number evenly distributed between 0 and N-1, where N is an integer value less than RAND_MAX, use the remainder function `rand()%N`. For example, to get a random number between 1 and 8, use `1+rand()%8`. Or, to get a random value in a string, use `string[rand()%strlen(string)]`.

6. I have included the line of code `srand(time(0));` in encode.c and decode.c to "seed" the random number generator with the current time. This means that every time you run encode or decode, you will get a different stream of random numbers when you invoke `rand()`. Ultimately, this is the correct behavior, but it can make debugging your code difficult. If you are debugging, you may want to comment out this line of code. Then you will get the same stream of random numbers every time you run encode or decode. Don't forget to remove the comment and restore the random seed when you are finished debugging your code.

7. In the decode program, you may assume the input provided to you was produced by a valid encoding program. That means you can assume each character is a valid ASCII character produced by your encode program.

8. The make test command runs the UNIX `diff` command to check to see if the raw input text matches the encoded and decoded result. The `-i` flag tells the diff command to ignore differences in the case of letters. However, diff will still report differences between the original punctuation or symbols and the decoded result unless your encode/decode handles all symbols and punctuation. Thus, the diff command is not a completely valid check of your program. You may get false negatives for punctuation or symbols.

## Submitting the Project

When you have finished coding and testing your encode and decode programs, make sure you do a final git commit and push to update your main git repository. Then, retrieve the 16 digit git hash code either from browsing your updated repository on the web, or using the command `git rev-parse HEAD` on the command line. Paste the git hash code in the Brightspace PROJ01 assignment. You may resubmit as many times as you would like to. Only the last submission will be graded.

## Grading Criteria

Your repository will be downloaded onto an LDAP machine at the level corresponding to the hash code retrieved from Brightspace, and compiled and run using the Makefile. The project is worth 100 points, and the following deductions will occur:

- -100 if your code matches or is significantly similar to any other student's code.
- -80 If your code does not attempt to address the problem.
- -50 if encode does not compile
- -50 if decode does not compile
- -10 if encode has warning messages with -Wall specified
- -10 if decode has warning messages with -Wall specified

If the correct results are not produced for make test, the TA will try to fix your code. For each fix, there will be a deduction of -15. If the TA cannot fix your code, or if you code requires more than 4 fixes, you will get a -60 deduction.

If your code passes the make test, we will run two further tests... We will run your encode and decode program on two unpublished test cases. There will be up to a 20 point deduction for each unpublished test case that produces incorrect results, depending on the severity of the mismatches.

There will also be a -10 point deduction each 24 hours (or part of 24 hours) the assignment is late, up to 5 days. After 5 days, there will be a -100 deduction.
