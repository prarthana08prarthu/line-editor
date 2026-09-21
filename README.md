# Simple Line Editor in C

## Project Description

This project implements a simple command-line line editor using the C programming language.

The editor allows users to insert, delete, and display lines of text. It also provides a line count feature, help menu, and safe exit with memory cleanup.

## Team Members

* Prarthana HS

## Features

### Core Features

* Insert a line at a specified position
* Delete a line from a specified position
* Display the complete document

### Additional Features

* Count the number of lines
* Help menu
* Error handling
* Dynamic memory allocation
* Memory cleanup before exiting

## Data Structure

The project uses an array of dynamically allocated strings:

```c
char *lines[MAX_LINES];
```

Each element stores one line of the document.

The maximum number of lines is 100.

## Commands

| Command           | Description        | Example     |
| ----------------- | ------------------ | ----------- |
| `I <line> <text>` | Insert a line      | `I 1 Hello` |
| `D <line>`        | Delete a line      | `D 2`       |
| `P`               | Display document   | `P`         |
| `C`               | Display line count | `C`         |
| `H`               | Show help          | `H`         |
| `Q`               | Quit               | `Q`         |

## Example

```text
=====================================
       SIMPLE LINE EDITOR IN C
=====================================
Type H for help.

> I 1 Hello
Line inserted successfully.

> I 2 Welcome to C
Line inserted successfully.

> P

----- DOCUMENT -----
1: Hello
2: Welcome to C
--------------------

> C
Total number of lines: 2

> D 1
Line deleted successfully.

> P

----- DOCUMENT -----
1: Welcome to C
--------------------

> Q
Exiting editor...
```

## Compilation

Make sure GCC is installed and available in the terminal.

Compile the program using:

```bash
gcc line_editor.c -o line_editor
```

## Run

### Windows PowerShell

```powershell
.\line_editor.exe
```

### Linux/macOS

```bash
./line_editor
```

## Complexity

| Operation  | Time Complexity |
| ---------- | --------------- |
| Insert     | O(n)            |
| Delete     | O(n)            |
| Display    | O(n)            |
| Line Count | O(1)            |

## Error Handling

The program checks for:

* Invalid line numbers
* Empty document
* Full document
* Memory allocation failure
* Unknown commands

## Memory Management

Each inserted line is dynamically allocated using `malloc()`.

When a line is deleted, its allocated memory is released using `free()`.

Before the program exits, all remaining allocated memory is freed.

## Files

```text
line-editor/
│
├── line_editor.c
├── HELP.md
└── README.md
```

## Conclusion

This project demonstrates the implementation of a basic command-line text editor using arrays, strings, dynamic memory allocation, functions, loops, and error handling in C.
