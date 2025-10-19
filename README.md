# get_next_line

**get_next_line** is a function that reads a file or input stream **line by line**, regardless of the buffer size.  
It continues reading until a newline (`\n`) or end of file is reached, and it can handle multiple file descriptors at the same time.

## 🧠 Project Overview
The goal of this project is to create a function:
```c
char *get_next_line(int fd);
```
that returns one line from the file descriptor `fd` each time it’s called.

### Key Requirements
- Read from a file descriptor without knowing its size in advance.  
- Handle files, standard input, and multiple FDs simultaneously.  
- Manage dynamic memory properly to avoid leaks.  
- Keep reading until there is no more data to return.

## ⚙️ Features
- Works with any buffer size (`BUFFER_SIZE` is defined at compile time).  
- Supports multiple file descriptors.  
- Efficient memory allocation and cleanup.  
- Returns `NULL` when the end of the file is reached or an error occurs.

## 💡 Example
```c
int fd = open("example.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

## 🧩 Compilation
To compile with a custom buffer size:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

Or using a Makefile (if provided):
```bash
make
```

## 🧾 Author
**Mohammad Alhindi**  
DevOps Engineer | Cloud & System Development  
[GitHub](https://github.com/mohammadalhindi1)
