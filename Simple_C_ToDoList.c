#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * Welcome to your to-do list!
 * Creating 4 functions:
 * 1 => addTask
 * 2 => showTasks
 * 3 => editTask
 * 4 => deleteTask
 * 5 Return => quit
 */

char taskList[100][100]; // A two-dimensional character array to store tasks
int taskCount = 0;       // To keep track of the number of tasks or elements in the list

/*
 * [100] indicates that there are 100 rows in the array.
 * [100] indicates that each row can hold up to 100 characters.
 */

void addTask() {
    if (taskCount < 100) {
        printf("Enter your task: ");
        scanf("%s", taskList[taskCount]); // scanf is used to read and store user input or data from files.
        taskCount++;
        printf("Task added successfully!\n");
    } else {
        printf("Task list is full. Cannot add more tasks.\n");
    }
}

void showTasks() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
    }
    else {
        printf("Task List:\n");
        for (int i = 0; i < taskCount; i++) {
            printf("%d. %s\n", i + 1, taskList[i]); // "i+1" to start numbering from 1 instead of 0
        }
    }
}

void deleteTask() {
    if (taskCount == 0) {
        printf("No tasks available to delete.\n");
    } else {
        int taskNumber; // This variable will store the task number you want to delete
        printf("Enter the task number to delete: ");
        scanf("%d", &taskNumber); // Read the number you enter from the keyboard and store it in the taskNumber variable.

        if (taskNumber >= 1 && taskNumber <= taskCount) {
            for (int i = taskNumber - 1; i < taskCount - 1; i++) {
                strcpy(taskList[i], taskList[i + 1]);
            }
            taskCount--;
            // Start at the task to be deleted (taskNumber - 1),
            // continue while there are tasks left (i < taskCount - 1),
            // and move to the next task in each iteration (i++)
            printf("The task list after deleting the task is: \n");
            for (int i = 0; i < taskCount; i++) {
                printf("%d. %s\n", i + 1, taskList[i]);
            }
        } else {
            printf("Invalid task number. No task deleted.\n");
        }
    }
}

void editTask() {
    if (taskCount == 0) {
        printf("No tasks available to edit.\n");
    } else {
        printf("Enter the task number to edit: ");
        int taskNumber;
        scanf("%d", &taskNumber);

        if (taskNumber >= 1 && taskNumber <= taskCount) {
            printf("Enter the new task description: ");
            scanf("%s", taskList[taskNumber - 1]);
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
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

