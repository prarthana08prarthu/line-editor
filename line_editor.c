#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char *lines[MAX_LINES];
int lineCount = 0;

/* Function Prototypes */
void insertLine(int lineNumber, char *text);
void deleteLine(int lineNumber);
void displayDocument(void);
void showLineCount(void);
void showHelp(void);
void freeDocument(void);

/* Main Function */
int main(void)
{
    char command;
    int lineNumber;
    char text[MAX_LENGTH];

    printf("=====================================\n");
    printf("       SIMPLE LINE EDITOR IN C\n");
    printf("=====================================\n");

    printf("Type H for help.\n");

    while (1)
    {
        printf("\n> ");

        scanf(" %c", &command);

        if (command == 'I' || command == 'i')
        {
            scanf("%d", &lineNumber);

            getchar();

            fgets(text, MAX_LENGTH, stdin);

            text[strcspn(text, "\n")] = '\0';

            insertLine(lineNumber, text);
        }
        else if (command == 'D' || command == 'd')
        {
            scanf("%d", &lineNumber);

            deleteLine(lineNumber);
        }
        else if (command == 'P' || command == 'p')
        {
            displayDocument();
        }
        else if (command == 'C' || command == 'c')
        {
            showLineCount();
        }
        else if (command == 'H' || command == 'h')
        {
            showHelp();
        }
        else if (command == 'Q' || command == 'q')
        {
            printf("Exiting editor...\n");
            freeDocument();
            break;
        }
        else
        {
            printf("Unknown command. Type H for help.\n");
        }
    }

    return 0;
}

/* Insert a new line */
void insertLine(int lineNumber, char *text)
{
    if (lineCount >= MAX_LINES)
    {
        printf("Error: Document is full.\n");
        return;
    }

    if (lineNumber < 1 || lineNumber > lineCount + 1)
    {
        printf("Error: Invalid line number.\n");
        return;
    }

    /* Shift existing lines downward */
    for (int i = lineCount; i >= lineNumber; i--)
    {
        lines[i] = lines[i - 1];
    }

    /* Allocate memory for new line */
    lines[lineNumber - 1] = malloc(strlen(text) + 1);

    if (lines[lineNumber - 1] == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        return;
    }

    strcpy(lines[lineNumber - 1], text);

    lineCount++;

    printf("Line inserted successfully.\n");
}

/* Delete a line */
void deleteLine(int lineNumber)
{
    if (lineCount == 0)
    {
        printf("Error: Document is empty.\n");
        return;
    }

    if (lineNumber < 1 || lineNumber > lineCount)
    {
        printf("Error: Invalid line number.\n");
        return;
    }

    /* Free memory of the line being deleted */
    free(lines[lineNumber - 1]);

    /* Shift remaining lines upward */
    for (int i = lineNumber - 1; i < lineCount - 1; i++)
    {
        lines[i] = lines[i + 1];
    }

    lineCount--;

    lines[lineCount] = NULL;

    printf("Line deleted successfully.\n");
}

/* Display the document */
void displayDocument(void)
{
    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    printf("\n----- DOCUMENT -----\n");

    for (int i = 0; i < lineCount; i++)
    {
        printf("%d: %s\n", i + 1, lines[i]);
    }

    printf("--------------------\n");
}

/* Display number of lines */
void showLineCount(void)
{
    printf("Total number of lines: %d\n", lineCount);
}

/* Display help */
void showHelp(void)
{
    printf("\n========== HELP ==========\n");
    printf("I <line> <text>  - Insert a new line\n");
    printf("D <line>         - Delete a line\n");
    printf("P                - Display document\n");
    printf("C                - Show line count\n");
    printf("H                - Show help\n");
    printf("Q                - Quit editor\n");
    printf("==========================\n");
}

/* Free all allocated memory */
void freeDocument(void)
{
    for (int i = 0; i < lineCount; i++)
    {
        free(lines[i]);
        lines[i] = NULL;
    }

    lineCount = 0;
}