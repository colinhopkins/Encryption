##Caesar Cipher Implementation in C

This is a implementation of the Caesar Cipher algorithm in C. The Caesar Cipher is a simple substitution cipher in which each letter in the plaintext is replaced by a letter some fixed number of positions down the alphabet.

This implementation allows the user to encrypt and decrypt text using a key provided as a command line argument. The key is used to generate a shift value, which is applied to each character in the input text to produce the output text.


#Implementation Details

The implementation of the Caesar Cipher in this project is fairly straightforward. The key is passed as a command line argument and is used to generate a shift value using a simple hash function based on the djb2 hash algorithm. The hash function generates a hash value by iterating through each byte in the input string and combining it with a running hash value using a bit shift and addition operation.

The encode_char and decode_char functions are used to encode and decode individual characters in the input text, respectively. These functions apply the shift value to each character based on its ASCII value and whether it is a letter, digit, or whitespace character.

The main function is responsible for reading input text from the console and passing it to the encode_char or decode_char function as appropriate. The output of these functions is then printed to the console.
