# SimpleShell

This Shell is a simple shell write with C language. This shell supports basic commands, process creation, program execution and offers an intuitive user interface.

## Flowchart

    ![alt tag] (https://github.com/ksyv/holbertonschool-simple_shell/issues/3#issue-2043268504)


## Fonctionnalités

- Read command user
- Separat command with token
- Creat a child processus with `fork`
- Execut external program with `execvp`
- Wait the chilmd process with `wait`

## Using

1. Clone the Repo :

   git clone https://github.com/ksyv/holbertonschool-simple_shell.git

2. Program compilation :

   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 \*.c -o hsh

3. Exécutez le shell :

4. Entrez des commandes dans le shell et observez son fonctionnement.

## Exemples d'utilisation

```bash
MonShell> ls -l
MonShell> gcc -o monprogramme monprogramme.c
MonShell> ./monprogramme
MonShell> exit
```
