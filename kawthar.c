#include <stdio.h>

char *kawthar[100]; // Array of strings to store tasks
int ikram = 0;      // Variable to keep track of the number of tasks

void addTask() {
    if (ikram < 100) {
        kawthar[ikram] = malloc(100); // Allocate memory for the task description
        printf("Enter your task: ");
        scanf("%s", kawthar[ikram]);
        ikram++;
        printf("Task added successfully!\n");
    } else {
        printf("Task list is full!\n");
    }
}

void showTasks() {
    if (ikram == 0) {
        printf("No tasks available.\n");
    } else {
        printf("Task List:\n");
        for (int i = 0; i < ikram; i++) {
            printf("%d. %s\n", i + 1, kawthar[i]);
        }
    }
}

void deleteTask() {
    if (ikram == 0) {
        printf("No tasks available to delete.\n");
    } else {
        free(kawthar[ikram - 1]); // Free memory for the deleted task
        ikram--;
        printf("Task deleted successfully!\n");
    }
}

void editTask() {
    if (ikram == 0) {
        printf("No tasks available to edit.\n");
    } else {
        printf("Enter the task number to edit (1-%d): ", ikram);
        int taskNumber;
        scanf("%d", &taskNumber);

        if (taskNumber >= 1 && taskNumber <= ikram) {
            printf("Enter the new task description: ");
            scanf("%s", kawthar[taskNumber - 1]);
            printf("Task edited successfully!\n");
        } else {
            printf("Invalid task number. Please try again.\n");
        }
    }
}

int main() {
    int choice;

    do {
        printf("Welcome to your to-do list!\n");
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

    // Free memory for task descriptions
    for (int i = 0; i < ikram; i++) {
        free(kawthar[i]);
    }

    return 0;
}

