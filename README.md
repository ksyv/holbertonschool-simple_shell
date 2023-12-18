




# SimpleShell

This Shell is a simple shell write with C language. This shell supports basic commands, process creation, program execution and offers an intuitive user interface.

## Flowchart

<a href="https://zupimages.net/viewer.php?id=23/50/8off.png"><img src="https://zupimages.net/up/23/50/8off.png" alt="" /></a>

## Fonctionnalités

- Read command user
- Separat command with token
- Creat a child processus with `fork`
- Execut external program with `execvp`
- Wait the chilmd process with `wait`

## List of allowed functions and system calls

   all functions from string.h
   access (man 2 access)
   chdir (man 2 chdir)
   close (man 2 close)
   closedir (man 3 closedir)
   execve (man 2 execve)
   exit (man 3 exit)
   _exit (man 2 _exit)
   fflush (man 3 fflush)
   fork (man 2 fork)
   free (man 3 free)
   getcwd (man 3 getcwd)
   getline (man 3 getline)
   getpid (man 2 getpid)
   isatty (man 3 isatty)
   kill (man 2 kill)
   malloc (man 3 malloc)
   open (man 2 open)
   opendir (man 3 opendir)
   perror (man 3 perror)
   printf (man 3 printf)
   fprintf (man 3 fprintf)
   vfprintf (man 3 vfprintf)
   sprintf (man 3 sprintf)
   putchar (man 3 putchar)
   read (man 2 read)
   readdir (man 3 readdir)
   signal (man 2 signal)
   stat (__xstat) (man 2 stat)
   lstat (__lxstat) (man 2 lstat)
   fstat (__fxstat) (man 2 fstat)
   strtok (man 3 strtok)
   wait (man 2 wait)
   waitpid (man 2 waitpid)
   wait3 (man 2 wait3)
   wait4 (man 2 wait4)
   write (man 2 write)

## File

executeFunction.c --- This function is responsible for executing a command with its arguments.

realshell.c --- code is a simple implementation of a command interpreter.

recreateFunction.c ---
storedPath.c ---
tokeniseCommand.c ---
shell.h ---
_strdup ---
README.md ---
Authors ---

## Using

# 1. Clone the Repo :

   git clone https://github.com/ksyv/holbertonschool-simple_shell.git

# 2. Program compilation :

   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 \*.c -o hsh

# 3. Exécutez le shell :

   ./hsh

# 4. Entrez des commandes dans le shell et observez son fonctionnement.

ls
pwd
cd
touch
mkdir
...

## Exemples d'utilisation

$ ls
 AUTHORS             hsh      README.md             shell.h       'test and exercices'
 executeFunction.c   man      realshell.c           storedPath.c   tokeniseCommand.c
 freeall.c           output   recreaeteFunction.c   _strdup.c


$ pwd
/home/vscode/holbertonschool-simple_shell


$ ls -la
total 88
drwxr-xr-x 4 vscode vscode  4096 Dec 18 13:27 .
drwxr-x--- 1 vscode vscode  4096 Dec 18 08:29 ..
-rw-r--r-- 1 vscode vscode 61864 Dec 18 13:27 Flowchart.png
drwxr-xr-x 8 vscode vscode  4096 Dec 18 13:27 .git
drwxr-xr-x 2 vscode vscode  4096 Dec 15 09:15 output
-rw-r--r-- 1 vscode vscode  2293 Dec 18 13:27 README.md
$

## Release Notes
0.0.1
Initial Release