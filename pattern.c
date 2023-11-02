#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage() {
    printf("Usage: program_name -l <length> -s <ABC,def,123>\n");
}

void create_pattern(int length, char* sets[]) {
    int num_sets = 0;
    for (int i = 0; sets[i] != NULL; i++) {
        num_sets++;
    }

    char* pattern = (char*)malloc((length + 1) * num_sets * sizeof(char));
    int pattern_index = 0;

    for (int i = 0; i < num_sets; i++) {
        int set_length = strlen(sets[i]);

        for (int j = 0; j < length; j++) {
            pattern[pattern_index] = sets[i][j % set_length];
            pattern_index++;
        }
    }

    pattern[length * num_sets] = '\0';

    printf("Pattern: %s\n", pattern);

    free(pattern);
}

int main(int argc, char* argv[]) {
    int length = 0;
    char* sets[10] = {0}; // Assuming a maximum of 10 sets provided

    for (int i = 1; i < argc; i += 2) {
        if (strcmp(argv[i], "-l") == 0) {
            length = atoi(argv[i+1]);
        } else if (strcmp(argv[i], "-s") == 0) {
            char* token = strtok(argv[i+1], ",");
            int index = 0;

            while (token != NULL) {
                sets[index++] = token;
                token = strtok(NULL, ",");
            }
        } else {
            print_usage();
            return 1;
        }
    }

    if (length <= 0 || sets[0] == NULL) {
        print_usage();
        return 1;
    }

    create_pattern(length, sets);

    return 0;
}
