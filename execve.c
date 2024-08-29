#include "main.h"

void fork_process(char *cmd) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return (1);
    }

    if (pid == 0) {
        char *args[] = {cmd, NULL};

        if (execve(cmd, args, environ) == -1) {
            perror("execve");
            exit(1);
        }
    } else {
        wait(&status);
    }
}
