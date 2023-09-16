#include <stdio.h>
#include "main.h"
/**
 * Welcome to your to-do list!
 * creating 4 functions
 * 1=> add task
 * 2=> show tasks
 * 3=> edit task
 * 4=> delet task
 * 5 Return => quit
 */
char kawthar[100][100]; //=>  two-dimensional character array
int ikram = 0;
/*
 *[100] indicates that there are 100 rows in the array.
 *[100] indicates that each row can hold up to 100 characters.
*/
void addTask() {
    if (ikram < 100) {
        printf("Enter your task: ");
        scanf("%s", kawthar[ikram]);
        ikram++;
        printf("Task added successfully!\n");
    } else {
        printf("nothing\n");
    }
}

void showTasks() {
    if (ikram == 0) {
        printf("No tasks available.\n");
    }
    else {
        printf("Task List:\n");
        for (int i = 0; i < ikram; i++) {
            printf("%d. %s\n", i + 1, kawthar[i]);       //"i+1"to start numbering from 1 instead of 0
        }
    }
}

void deleteTask() {
    if (ikram == 0) {
        printf("No tasks available to delete.\n");
    } else {
        ikram--;
        printf("Task deleted successfully!\n");
    }
}

void editTask() {
    if (ikram == 0) {
        printf("No tasks available to edit.\n");
    } else {
        printf("Enter the task number to edit: ");
        int num;
        scanf("%d", &num);

        if (num >= 1 && num <= ikram) {
            printf("Enter the new task description: ");
            scanf("%s", kawthar[num - 1]);
            printf("Task edited successfully!\n");
        }

    }
}


int main() {
    int choice;

    do {
        printf("**Welcome to your to-do list**!\n");
        printf("Enter your choice:\n");
        printf("1 => Add task\n");
        printf("2 => Show tasks\n");
        printf("3 => Delete task\n");
        printf("4 => Edit task\n");
        printf("5 => Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                showTasks();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                editTask();
                break;
            case 5:
                printf("Goodbye!\n");
                break;


        }
    } while (choice != 5);

    return 0;
}
