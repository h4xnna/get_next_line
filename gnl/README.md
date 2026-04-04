# Get Next Line (GNL)

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](#)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](#)

A C function that reads files line by line from a file descriptor. This is a school project from 42 that implements a memory-efficient solution for sequential file reading.

## Features

- Read files line by line from a file descriptor
- Efficient memory management with dynamic allocation
- Support for multiple file descriptors simultaneously
- Configurable buffer size at compile time (`BUFFER_SIZE`)
- No external functions used (except required libc functions)

## Files

- `get_next_line.h` - Header file with function prototypes
- `get_next_line.c` - Main implementation
- `get_next_line_utils.c` - Utility functions

## Compilation

### Basic compilation with default buffer size (42 bytes):

```bash
gcc -c get_next_line.c
gcc -c get_next_line_utils.c
gcc main.c get_next_line.o get_next_line_utils.o -o program
```

### With custom buffer size:

```bash
gcc -D BUFFER_SIZE=4096 get_next_line.c get_next_line_utils.c main.c -o program
```

The `BUFFER_SIZE` macro defines how many bytes are read at a time. Default is 42 bytes.

## Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);  // Must free each line
    }
    close(fd);
    return (0);
}
```

## Function Reference

### `char *get_next_line(int fd)`

Reads and returns the next line from the file descriptor.

**Parameters:**
- `fd` - Open file descriptor

**Returns:**
- Pointer to the line (including newline character)
- `NULL` when EOF is reached or on error

**Important:** Each returned line must be freed with `free()`

### Helper Functions

- `ft_strlen()` - String length
- `ft_strchr()` - Find character in string
- `ft_strjoin()` - Concatenate two strings

## Important Notes

- Each line returned must be `free()`d to avoid memory leaks
- The newline character (`\n`) is included in the returned string
- The function handles multiple file descriptors independently
- Buffer size can be adjusted at compile time for performance tuning
- Works with any file size, not limited by buffer size
