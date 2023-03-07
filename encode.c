#include <stdio.h>

unsigned long hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + (c + 1);
    }
    return hash;
}



unsigned char encode_char(unsigned char c, unsigned long shift) {
    if (c >= 'a' && c <= 'z') {
        return (c - 'a' + shift) % 26 + 'a';
    } else if (c >= 'A' && c <= 'Z') {
        return (c - 'A' + shift) % 26 + 'a';
    } else if (c >= '0' && c <= '9') {
        return (c - '0' + shift) % 10 + '0';
    } else if( c == ' ' || c == '\t' || c== '\n'){
        return c;
    } else {
        return 42;
    }
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Please invoke as %s <key>\n", argv[0]);
        return 1;
    }

    unsigned char *key = (unsigned char *) argv[1];
    unsigned long shift = hash(key);

    int next_char = getchar();
    while (next_char != EOF) {
        unsigned char encoded_char = encode_char(next_char, shift);
        putchar(encoded_char);
        next_char = getchar();
    }

    return 0;
}
