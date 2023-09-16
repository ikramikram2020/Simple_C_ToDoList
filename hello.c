#include <stdio.h>

#define MAX_TASKS 100 
#define MAX_DESCRIPTION_LENGTH 100 // Define the maximum length of a task description

char taskDescriptions[MAX_TASKS][MAX_DESCRIPTION_LENGTH]; // An array to store task descriptions
int taskCount = 0; // A counter to keep track of the number of tasks

void addTask() {
    if (taskCount < MAX_TASKS) {
        printf("Enter your task: ");
        scanf("%s", taskDescriptions[taskCount]);
        taskCount++;
        printf("Task added successfully!\n");
    } else {
        printf("Task list is full!\n");
    }
}

void showTasks() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
    } else {
        printf("Task List:\n");
        for (int i = 0; i < taskCount; i++) {
            printf("%d. %s\n", i + 1, taskDescriptions[i]);
        }
    }
}

void deleteTask() {
    if (taskCount == 0) {
        printf("No tasks available to delete.\n");
    } else {
        taskCount--;
        printf("Task deleted successfully!\n");
    }
}

int main() {
    int choice;

    do {
        printf("*welcome to your to-do list!*\n");
        printf("Enter your choice:\n");
        printf("1 => Add task\n");
        printf("2 => Show tasks\n");
        printf("3 => Delete task\n");
        printf("4 => Quit\n");
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
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

