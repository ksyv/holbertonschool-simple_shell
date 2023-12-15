# SimpleShell

This Shell is a simple shell write with C language. This shell supports basic commands, process creation, program execution and offers an intuitive user interface.

## Flowchart

<a href="https://zupimages.net/viewer.php?id=23/50/8off.png"><img src="https://zupimages.net/up/23/50/8off.png" alt="" /></a>

## Fonctionnalités

- Lecture de commandes utilisateur
- Division des commandes en tokens
- Création de processus enfants avec `fork`
- Exécution de programmes externes avec `execvp`
- Attente de la fin des processus enfants avec `wait`

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
