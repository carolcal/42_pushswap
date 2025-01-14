# Libft

Libft is a custom C library built as a foundational project at 42 School. This library recreates standard C library functions and includes additional utilities for string manipulation, memory management, and linked list operations.

## Project Structure

Libft includes both mandatory and bonus functions:

### Standard Library Function Implementations Part 1

- **ft_isalpha**: Checks if a character is alphabetic.
- **ft_isdigit**: Checks if a character is a digit (0-9).
- **ft_isalnum**: Checks if a character is alphanumeric.
- **ft_isascii**: Checks if a character is part of the ASCII table.
- **ft_isprint**: Checks if a character is printable.
- **ft_toupper**: Converts a lowercase letter to uppercase.
- **ft_tolower**: Converts an uppercase letter to lowercase.
- **ft_bzero**: Sets a block of memory to zero.
- **ft_strncmp**: Compares two strings up to a specified number of characters.
- **ft_strlen**: Returns the length of a string.
- **ft_strlcpy**: Copies a string to a buffer with size limit.
- **ft_strlcat**: Concatenates a string to a buffer with size limit.
- **ft_strchr**: Finds the first occurrence of a character in a string.
- **ft_strrchr**: Finds the last occurrence of a character in a string.
- **ft_strnstr**: Searches for a substring within a string up to a specified length.
- **ft_strdup**: Duplicates a string by allocating memory.
- **ft_memcmp**: Compares two memory blocks.
- **ft_memset**: Sets a block of memory to a specified value.
- **ft_memcpy**: Copies a block of memory.
- **ft_memmove**: Moves a block of memory safely.
- **ft_memchr**: Searches for a byte in a block of memory.
- **ft_atoi**: Converts a string to an integer.
- **ft_calloc**: Allocates memory and initializes it to zero.

### Standard Library Function Implementations Part 2

- **ft_itoa**: Converts an integer to a string.
- **ft_split**: Splits a string into an array of substrings based on a delimiter.
- **ft_striteri**: Applies a function to each character of a string with index.
- **ft_substr**: Creates a substring from a string.
- **ft_strjoin**: Concatenates two strings into a new string.
- **ft_strtrim**: Removes specified characters from the beginning and end of a string.
- **ft_strmapi**: Maps a function to each character of a string to create a new string.
- **ft_putchar_fd**: Outputs a character to a specified file descriptor.
- **ft_putstr_fd**: Outputs a string to a specified file descriptor.
- **ft_putendl_fd**: Outputs a string followed by a newline to a specified file descriptor.
- **ft_putnbr_fd**: Outputs an integer to a specified file descriptor.

### Linked List Bonus Functions

- **ft_lstnew**: Creates a new linked list element.
- **ft_lstadd_front**: Adds a new element at the beginning of a linked list.
- **ft_lstsize**: Returns the number of elements in a linked list.
- **ft_lstlast**: Returns the last element of a linked list.
- **ft_lstadd_back**: Adds a new element at the end of a linked list.
- **ft_lstdelone**: Deletes a linked list element and frees its memory.
- **ft_lstclear**: Deletes all elements of a linked list.
- **ft_lstiter**: Iterates over a linked list and applies a function to each element.
- **ft_lstmap**: Applies a function to each element of a list to create a new list.

---

### Compilation and Testing

Libft can be compiled as a static library:

```bash
make
```

### Usage

To use Libft in your project, compile it as follows:

```c
cc -Wall -Werror -Wexta file.c -o yourprogram
```
