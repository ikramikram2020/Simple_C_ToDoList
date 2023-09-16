#include <stdio.h>
#include "main.h"

#define ikram 100

char tasks[ikram][100];
int kawtharIkram = 0;

void addTask() {
    if (kawtharIkram < ikram) {
        printf("Enter your task: ");
        scanf("%s", tasks[kawtharIkram]);
        kawtharIkram++;
        printf("Task added successfully!\n");
    } else {
        printf("Task list is full!\n");
    }
}

void showTasks() {
    printf("Task List:\n");
    for (int i = 0; i < kawtharIkram; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
}

void deleteTask() {
    if (kawtharIkram == 0) {
        printf("No tasks available to delete.\n");
        return;
    }

    printf("Enter the task number to delete: ");
    int taskNumber;
    scanf("%d", &taskNumber);

    if (taskNumber < 1 || taskNumber > kawtharIkram) {
        printf("Invalid task number.\n");
    } else {
        for (int i = taskNumber - 1; i < kawtharIkram - 1; i++) {
            strcpy(tasks[i], tasks[i + 1]);
        }
        kawtharIkram--;
        printf("Task deleted successfully!\n");
    }
}

void editTask() {
    if (kawtharIkram == 0) {
        printf("No tasks available to edit.\n");
        return;
    }

    printf("Enter the task number to edit: ");
    int taskNumber;
    scanf("%d", &taskNumber);

    if (taskNumber < 1 || taskNumber > kawtharIkram) {
        printf("Invalid task number.\n");
        return;
    }

    printf("Enter the new task description: ");
    scanf("%s", tasks[taskNumber - 1]);
    printf("Task edited successfully!\n");
}

int main() {
    int choice;

    do {
        printf("\nWelcome to your to-do list!\n");
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

