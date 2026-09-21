# Simple Line Editor in C

## Project Description

This project implements a simple command-line Line Editor using the C programming language.

The editor allows users to create, view, insert, delete, and modify lines of a text document through terminal-based commands.

The project was first designed on paper and then implemented and tested in VS Code using GCC. The completed project is documented and maintained in a GitHub repository as a portfolio artifact.

## Team Members

* Prarthana HS

## Objectives

* Understand how a text editor manages lines of a document.
* Design the data structure before implementation.
* Implement line operations using C.
* Practice arrays, strings, functions, loops, and dynamic memory allocation.
* Handle invalid input and memory safely.
* Use Git and GitHub to document and maintain the project.

## Features

### Core Features

* Create and store text lines
* Insert a line at a specified position
* Delete a line from a specified position
* Modify an existing line
* Display the complete document

### Additional Features

* Count the number of lines
* Help menu
* Error handling
* Dynamic memory allocation
* Memory cleanup before exiting

## Commands

| Command           | Description                       | Example           |
| ----------------- | --------------------------------- | ----------------- |
| `I <line> <text>` | Insert a new line                 | `I 1 Hello`       |
| `D <line>`        | Delete a line                     | `D 2`             |
| `M <line> <text>` | Modify an existing line           | `M 1 Hello World` |
| `P`               | Display the complete document     | `P`               |
| `C`               | Display the total number of lines | `C`               |
| `H`               | Display the help menu             | `H`               |
| `Q`               | Quit the editor                   | `Q`               |

## Data Structure

The project uses an array of dynamically allocated strings:

```c
char *lines[MAX_LINES];
```

Each element of the array stores one line of the document.

The constants used are:

```c
#define MAX_LINES 100
#define MAX_LENGTH 200
```

Therefore, the editor can store up to **100 lines**, with each input line supporting up to **199 characters** plus the null terminator.

### Why This Data Structure?

An array of character pointers is suitable for a small command-line editor because:

* Each line can have a different length.
* Lines can be accessed using their index.
* Insertion and deletion can be implemented by shifting pointers.
* Dynamic memory allows each line to use only the memory it needs.

## Project Structure

```text
line-editor/
│
├── .gitignore
├── HELP.md
├── README.md
└── line_editor.c
```

## Program Functions

The program is divided into separate functions:

| Function            | Purpose                                   |
| ------------------- | ----------------------------------------- |
| `main()`            | Handles commands and controls the program |
| `insertLine()`      | Inserts a new line                        |
| `deleteLine()`      | Deletes an existing line                  |
| `modifyLine()`      | Modifies an existing line                 |
| `displayDocument()` | Displays all lines                        |
| `showLineCount()`   | Displays the number of lines              |
| `showHelp()`        | Displays available commands               |
| `freeDocument()`    | Releases allocated memory                 |

## How the Editor Works

### Insert

The command:

```text
I 1 Hello
```

inserts `Hello` as line 1.

When a line is inserted in the middle of the document, existing line pointers are shifted downward to make space.

### Delete

The command:

```text
D 2
```

deletes line 2.

The memory allocated for that line is released using `free()`, and the remaining lines are shifted upward.

### Modify

The command:

```text
M 1 Hello World
```

replaces the existing contents of line 1.

The old memory is released and new memory is allocated for the modified text.

### Display

The command:

```text
P
```

displays all lines with their line numbers.

### Line Count

The command:

```text
C
```

displays the current number of lines.

## Example Run

```text
=====================================
       SIMPLE LINE EDITOR IN C
=====================================
Type H for help.

> I 1 Hello
Line inserted successfully.

> I 2 Welcome to C
Line inserted successfully.

> I 2 This is line two
Line inserted successfully.

> P

----- DOCUMENT -----
1: Hello
2: This is line two
3: Welcome to C
--------------------

> M 1 Hello World
Line modified successfully.

> P

----- DOCUMENT -----
1: Hello World
2: This is line two
3: Welcome to C
--------------------

> C
Total number of lines: 3

> D 2
Line deleted successfully.

> P

----- DOCUMENT -----
1: Hello World
2: Welcome to C
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

## Running the Program

### Windows PowerShell

```powershell
.\line_editor.exe
```

### Linux/macOS

```bash
./line_editor
```

## Error Handling

The program handles the following situations:

* Invalid line numbers
* Empty document
* Full document
* Memory allocation failure
* Unknown commands

For example, attempting to delete a line from an empty document produces:

```text
Error: Document is empty.
```

## Memory Management

The program uses dynamic memory allocation with `malloc()`.

When a line is inserted, memory is allocated based on the length of the text.

When a line is deleted or modified, the previously allocated memory is released using `free()`.

Before the program exits, `freeDocument()` releases all remaining allocated memory.

This prevents unnecessary memory usage and helps avoid memory leaks.

## Time Complexity

| Operation  | Time Complexity |
| ---------- | --------------- |
| Insert     | O(n)            |
| Delete     | O(n)            |
| Modify     | O(n)            |
| Display    | O(n)            |
| Line Count | O(1)            |

The insert and delete operations may require shifting multiple line pointers.

## Design Process

Before coding, the data structure and core algorithms were designed on paper.

The paper design includes:

* Problem understanding
* Required features
* Data structure
* Data structure diagram
* Command table
* Insert algorithm
* Delete algorithm
* Modify logic
* Display algorithm
* Line count algorithm
* Function design
* Program flow
* Error handling
* Complexity analysis

## Testing

The program was compiled using GCC and tested through the terminal.

The following operations were tested:

* Inserting lines
* Displaying lines
* Modifying lines
* Deleting lines
* Counting lines
* Displaying help
* Invalid line numbers
* Empty document operations
* Quitting and freeing memory

## Technologies Used

* **Language:** C
* **Compiler:** GCC
* **IDE:** Visual Studio Code
* **Version Control:** Git
* **Repository:** GitHub

## Learning Outcomes

Through this project, the following concepts were practiced:

* C functions
* Arrays
* Character strings
* Pointers
* Dynamic memory allocation
* `malloc()` and `free()`
* Loops
* Conditional statements
* Command-line input
* Error handling
* Algorithm design
* Git and GitHub

## Conclusion

The Simple Line Editor demonstrates how basic text-editing operations can be implemented using C.

The project combines data structure design, algorithm implementation, dynamic memory management, testing, documentation, and GitHub-based version control into a small command-line application 
