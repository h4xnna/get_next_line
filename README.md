# Get Next Line (GNL)

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](#)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](#)

## 🌟 Overview

`get_next_line` is a 42 project written in C that reads a file line by line using a file descriptor.
Each call to the function returns the next line, including the newline character (`\n`) if it is present.

This project focuses on:
- dynamic memory management,
- buffered reading with `read()`,
- support for multiple file descriptors,
- simple and reusable code.

## 📁 Repository Structure

- `get_next_line.h` — function prototypes, macros, and includes
- `get_next_line.c` — main implementation of `get_next_line` (includes a demo `main` for testing)
- `get_next_line_utils.c` — helper functions for string handling
- `Makefile` — build automation script
- `README.md` — project documentation

## 🛠 Compilation

### Using Makefile (recommended)

```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Rebuild from scratch
```

### Manual compilation

```bash
gcc -Wall -Wextra -Werror -c get_next_line.c
gcc -Wall -Wextra -Werror -c get_next_line_utils.c
gcc -Wall -Wextra -Werror get_next_line.o get_next_line_utils.o -o gnl
```

### Compilation with custom `BUFFER_SIZE`

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=4096 get_next_line.c get_next_line_utils.c -o gnl
```

> `BUFFER_SIZE` determines how many bytes are read at each `read()` call.

## ▶️ Usage

```bash
./gnl my_file.txt
```

> Note: A simple `main` wrapper is included in `get_next_line.c` for convenience and easy testing, even though the original 42 subject does not explicitly require it.

### Example code

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

## 🔍 How it works

The `get_next_line` function works in three main steps:

1. Read from the file descriptor until a newline or EOF is reached.
2. Extract the next full line to return.
3. Keep the remaining data in a static buffer for the next call.

### Main helper functions

- `read_line()` — reads from `fd` into a temporary buffer and appends the data.
- `extract_line()` — returns the full next line, including `\n` if present.
- `clear_stock()` — updates the internal buffer after extracting the returned line.

## 🧩 Utility functions

- `ft_strlen()` — calculates the length of a string.
- `ft_strchr()` — checks if a character exists in a string.
- `ft_strjoin()` — joins two strings and frees the first one.

## ✅ Best practices

- Always free the string returned by `get_next_line()`.
- Test with empty files, files without a final `\n`, and large files.
- Verify behavior with multiple file descriptors open at the same time.

## 💡 Suggestions to improve this repo

- Add automated tests or validation scripts.
- Add a `.gitignore` to exclude object files and executables.
- Add a `LICENSE` file if you want to publish the project.
- Add sample outputs or usage examples in the README.

## 🧪 Testing ideas

- empty file
- single line without a trailing `\n`
- file with multiple lines
- file with very long lines
- alternating reads from multiple file descriptors

## 📌 License

This project is licensed under MIT.

