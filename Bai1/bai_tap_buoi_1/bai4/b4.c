#include <stdio.h>
#include <stdlib.h>

void print_file(FILE *fp) {
    char buffer[1024];
    size_t n;

    while ((n = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        if (fwrite(buffer, 1, n, stdout) != n) {
            perror("Error writing to stdout");
            return;
        }
    }

    if (ferror(fp)) {
        perror("Error reading file");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> [file2 ...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            perror("Error opening file");
            continue;
        }

        print_file(fp);
        fclose(fp);
    }

    return EXIT_SUCCESS;
}
