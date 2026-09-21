# Testing Report

## Project

Simple Line Editor in C

## Team Members

* Prarthana HS
* Pradnya
* Priya

## Testing Environment

* Operating System: Windows
* IDE: Visual Studio Code
* Compiler: GCC
* Language: C

## Test Cases

| Test Case           | Input             | Expected Result                | Status |
| ------------------- | ----------------- | ------------------------------ | ------ |
| Insert line         | `I 1 Hello`       | Line inserted                  | Passed |
| Insert another line | `I 2 Welcome`     | Line inserted                  | Passed |
| Display document    | `P`               | All lines displayed            | Passed |
| Modify line         | `M 1 Hello World` | Line 1 modified                | Passed |
| Delete line         | `D 2`             | Line 2 deleted                 | Passed |
| Count lines         | `C`               | Number of lines displayed      | Passed |
| Help                | `H`               | Help menu displayed            | Passed |
| Invalid line number | `D 10`            | Error message displayed        | Passed |
| Empty document      | `D 1`             | Empty document error displayed | Passed |
| Quit                | `Q`               | Program exits safely           | Passed |

## Result

The Simple Line Editor was successfully compiled using GCC and tested through the terminal.

The core operations Insert, Delete, Modify, Display, and Line Count were tested successfully. Error handling for invalid operations was also tested.

The program successfully releases dynamically allocated memory before exiting.
