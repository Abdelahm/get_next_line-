*This project has been created as part of the 42 curriculum by abdelahm.*

## Description

The `get_next_line` project implements a function in C that reads a line from a file descriptor. The function returns the line read, including the newline character (`\n`) if present, or NULL if there is nothing more to read or an error occurs. It is designed to handle reading from multiple file descriptors simultaneously by using a static variable to store the remaining content for each descriptor.

The goal of this project is to deepen understanding of file I/O in C, dynamic memory allocation, and efficient buffer management. It provides a robust way to read text files line by line without loading the entire file into memory, which is crucial for handling large files or streams.

## Algorithm Explanation and Justification

The algorithm uses a static stash (a dynamically allocated string) to accumulate data read from the file descriptor. Here's how it works:

1. **Reading and Storing**: The `read_and_store` function reads data in chunks of `BUFFER_SIZE` bytes using the `read` system call. It appends each chunk to the stash until a newline character (`\n`) is found or the end of file is reached.

2. **Line Extraction**: Once a newline is detected in the stash, `extract_line` creates a new string containing the line up to and including the newline.

3. **Stash Update**: `update_stash` removes the extracted line from the stash, keeping only the remaining data for the next call.

4. **Memory Management**: All allocations are handled carefully, with proper freeing of memory to avoid leaks. The stash persists across function calls due to the static variable.

This approach is justified because:
- It allows reading lines without knowing the file size in advance.
- The static stash enables handling multiple file descriptors independently.
- Buffered reading improves efficiency by minimizing system calls.
- It handles partial reads and edge cases like files without newlines or empty files.
- Memory usage is optimized by only storing necessary data.

Compared to alternatives like reading the entire file at once, this method is more memory-efficient for large files and suitable for real-time processing.

## Instructions

### Compilation
To compile the project, use the following command:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o get_next_line
```

- `-Wall -Wextra -Werror`: Enable all warnings and treat them as errors, as per 42 norms.
- `-D BUFFER_SIZE=42`: Define the buffer size (can be changed as needed).
- Replace `get_next_line.c` and `get_next_line_utils.c` with your source files.

### Execution
The `get_next_line` function requires a main function to test it. Here's a simple example:

```c
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

Compile and run:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o test_gnl
./test_gnl
```

This will read and print lines from `test.txt`.

## Resources

- **C Programming References**:
  - [The C Programming Language by Brian W. Kernighan and Dennis M. Ritchie](https://en.wikipedia.org/wiki/The_C_Programming_Language) - Classic book on C.
  - [Beej's Guide to C Programming](https://beej.us/guide/bgc/) - Free online tutorial.

- **File I/O in C**:
  - `man 2 read` - Manual page for the read system call.
  - `man 3 malloc` - Manual page for dynamic memory allocation.

- **42 Curriculum**:
  - [42 School Intranet](https://intra.42.fr/) - Project specifications and guidelines.