# MonShell - Un Shell Simple en C

MonShell est un projet de shell simple écrit en langage C. Ce shell prend en charge les commandes de base, la création de processus, l'exécution de programmes, et offre une interface utilisateur intuitive.

## Fonctionnalités

- Lecture de commandes utilisateur
- Division des commandes en tokens
- Création de processus enfants avec `fork`
- Exécution de programmes externes avec `execvp`
- Attente de la fin des processus enfants avec `wait`

## Utilisation

1. Clonez le référentiel :

    ```bash
    git clone https://github.com/votre-utilisateur/monshell.git
    ```

2. Compilez le programme :

    ```bash
    cd monshell
    gcc monshell.c -o monshell
    ```

3. Exécutez le shell :

    ```bash
    ./monshell
    ```

4. Entrez des commandes dans le shell et observez son fonctionnement.

## Exemples d'utilisation

```bash
MonShell> ls -l
MonShell> gcc -o monprogramme monprogramme.c
MonShell> ./monprogramme
MonShell> exit
