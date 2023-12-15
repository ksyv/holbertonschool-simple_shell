#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

int main(void) {
    char commande[MAX_COMMAND_LENGTH];
    ssize_t read_chars;
	pid_t pid;

    while (1) {
        write(STDOUT_FILENO, "$ ", 2);

        if ((read_chars = read(STDIN_FILENO, commande, MAX_COMMAND_LENGTH)) == -1) {
            if (feof(stdin)) {
                printf("\nCondition de fin de fichier (Ctrl+D) détectée. Fermeture du shell...\n");
                break;
            } else {
                perror("read");
                exit(EXIT_FAILURE);
            }
        }

        if (commande[read_chars - 1] == '\n')
            commande[read_chars - 1] = '\0';


        pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            char **args = malloc(2 * sizeof(char *));
            if (args == NULL) {
                perror("malloc");
                exit(EXIT_FAILURE);
            }
            args[0] = commande;
            args[1] = NULL;

            if (execve(commande, args, NULL) == -1) {
                printf("Commande '%s' introuvable\n", commande);
                exit(EXIT_FAILURE);
            }
        } else {
            int status;
            waitpid(pid, &status, 0);
            if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
                printf("La commande '%s' s'est terminée avec le statut %d\n", commande, WEXITSTATUS(status));
            }
        }
    }
    return 0;
}
