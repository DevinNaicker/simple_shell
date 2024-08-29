#include "main.h"

#define PROMPT "$: "

int main(void) {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while (1) {
        printf(PROMPT);

        nread = getline(&line, &len, stdin);
        if (nread == -1) {
            if (feof(stdin)) {
                printf("\n");
                break;
            } else {
                perror("getline");
                return (1);
            }
        }

        line[strcspn(line, "\n")] = 0;

        if (line[0] == '\0') {
            continue;
        }

        fork_process(line);
    }

    free(line);
    return 0;
}i}
