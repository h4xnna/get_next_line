# Get Next Line (GNL)

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](#)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](#)

`get_next_line` est un projet 42 en C qui lit un fichier ligne par ligne à partir d'un descripteur de fichier.
Chaque appel retourne la ligne suivante, avec le caractère de saut de ligne (`\n`) s'il est présent.

## ✅ Objectif

- Lire un flux entier ligne par ligne
- Gérer plusieurs descripteurs de fichiers simultanément
- Utiliser une mémoire dynamique efficace
- Respecter les restrictions du projet 42 sans utiliser de bibliothèques externes inutiles

## 📁 Fichiers

- `get_next_line.h` — prototype de fonctions et constantes
- `get_next_line.c` — implémentation principale
- `get_next_line_utils.c` — utilitaires de gestion de chaînes

## 🛠 Compilation

### Avec `main.c` et taille de buffer par défaut (42) :

```bash
gcc -Wall -Wextra -Werror -c get_next_line.c
cc -Wall -Wextra -Werror -c get_next_line_utils.c
cc -Wall -Wextra -Werror main.c get_next_line.o get_next_line_utils.o -o gnl
```

### Avec une taille de buffer personnalisée :

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=4096 get_next_line.c get_next_line_utils.c main.c -o gnl
```

> `BUFFER_SIZE` définit le nombre de bytes lus à chaque appel `read()`.

## ▶️ Exemple d'utilisation

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
    int     fd;
    char    *line;

    if (ac != 2)
        return (1);
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## 🔧 Fonction principale

### `char *get_next_line(int fd)`

Lit la ligne suivante du descripteur de fichier `fd` et retourne un buffer alloué dynamiquement.

**Paramètre**
- `fd` : descripteur de fichier ouvert

**Retour**
- Ligne lue, y compris le caractère `\n` si présent
- `NULL` si la fin de fichier est atteinte ou en cas d'erreur

**Important**
- La ligne renvoyée doit être libérée avec `free()` après utilisation.

## 🧩 Fonctions utilitaires

- `ft_strlen()` — calcul de la longueur d'une chaîne
- `ft_strchr()` — recherche d'un caractère dans une chaîne
- `ft_strjoin()` — concaténation de deux chaînes

## ⚠️ Notes importantes

- Libérer chaque ligne retournée pour éviter les fuites mémoire
- Le projet supporte plusieurs `fd` en même temps
- Le code fonctionne avec des fichiers de toutes tailles
- Le `BUFFER_SIZE` peut être adapté pour optimiser les performances

## 📌 Licence

MIT

