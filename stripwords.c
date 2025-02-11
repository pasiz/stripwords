#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_WORD 50

// tokenize
void tokenize_line(char *line, char *words[], int max_words) {
    int count = 0;
    char *token = strtok(line, " \t\n");
    while (token != NULL && count < max_words) {
        words[count++] = token;
        token = strtok(NULL, " \t\n");
    }
    words[count] = NULL; // Null-terminate the array
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <first_word_in_row> <count>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int n = atoi(argv[2]);
    int x = 0;
    if (argv[3])
	x = atoi(argv[3]);

    if (n < 1) {
        fprintf(stderr, "Error: <first_word> must be greater than 0\n");
        fclose(file);
        return 1;
    }
    if (x < 0)
	x=0;

    char line[MAX_LINE];
    char *words[MAX_WORD];

    // Read file
    while (fgets(line, sizeof(line), file)) {
        tokenize_line(line, words, MAX_WORD);

        // Check if there are at least 'n' words
        if (words[n - 1] != NULL) {
            printf("%s", words[n - 1]); // Print the nth word

            // Print 'count' words after 'first_word_in_row'
            for (int i = 0; i < x && words[n + i] != NULL; ++i) {
                printf(" %s", words[n + i]);
            }
            printf("\n");
        }
    }

    fclose(file);
    return 0;
}
