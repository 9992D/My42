/* Bibliothèques C de base */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Readline */
#include <readline/readline.h>
#include <readline/history.h>

/* Accès fichiers et métadonnées */
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Processus et synchronisation */
#include <sys/wait.h>
#include <sys/resource.h>

/* Signaux */
#include <signal.h>

/* Répertoires */
#include <dirent.h>

/* Termios (attributs du terminal) */
#include <termios.h>

/* Contrôle des périphériques */
#include <sys/ioctl.h>

/* utmp pour ttyslot */
#include <utmp.h>

/* Termcap */
#include <termcap.h>

// -lreadline -ltermcap <-> linkage pour compiler


