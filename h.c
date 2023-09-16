#include <stdio.h>
#include <string.h>



char kawthar[100];
int ikram = 0;

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

void editTask() {
    printf("Enter the task number to edit (1-%d): ", taskCount);
    int taskNumber;
    scanf("%d", &taskNumber);

    printf("Enter the new task description: ");
    scanf("%s", taskDescriptions[taskNumber - 1]);
    printf("Task edited successfully!\n");
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

    return 0;
}

