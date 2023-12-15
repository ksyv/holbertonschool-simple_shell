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

## Using

1. Clone the Repo :

   git clone https://github.com/ksyv/holbertonschool-simple_shell.git

2. Program compilation :

   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 \*.c -o hsh

3. Exécutez le shell :

   ./hsh

4. Entrez des commandes dans le shell et observez son fonctionnement.

## Exemples d'utilisation

$ ls 
