#include <stdio.h>

unsigned long hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
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
        if (next_char >= 'A' && next_char <= 'Z') {
            next_char += 'a' - 'A';
        }
        if ((next_char >= 'a' && next_char <= 'z')) {
            int decoded_char = (next_char - 'a' + (26 - (shift % 26))) % 26 + 'a';
            putchar(decoded_char);
        } else {
            putchar(next_char);
        }
        next_char = getchar();
    }

    return 0;
}
