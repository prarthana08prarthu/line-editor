# Line Editor - Help

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

## How to Use

### 1. Insert a line

Enter:

`I 1 Hello World`

This inserts "Hello World" as line 1.

### 2. Insert another line

Enter:

`I 2 Welcome to C`

This inserts the text as line 2.

### 3. Display the document

Enter:

`P`

The editor displays all stored lines with their line numbers.

### 4. Delete a line

Enter:

`D 2`

This deletes line 2 and shifts the remaining lines upward.

### 5. Modify a line

Enter:

`M 1 Hello World`

This replaces the existing text on line 1 with "Hello World".

### 6. Count lines

Enter:

`C`

This displays the current number of lines.

### 7. Quit

Enter:

`Q`

The editor frees allocated memory and exits safely.

## Error Handling

The program handles:

* Invalid line numbers
* Empty document
* Full document
* Memory allocation failure
* Unknown commands

## Data Structure

The editor uses an array of dynamically allocated strings:

`char *lines[MAX_LINES];`

Each array element stores one line of the document.

Maximum lines: **100**

Maximum line length: **199 characters**

## Complexity

* Insert: O(n)
* Delete: O(n)
* Modify: O(n) for text allocation/replacement
* Display: O(n)
* Line count: O(1)
