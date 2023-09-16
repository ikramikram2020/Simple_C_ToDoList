#include <stdio.h>



char kawthar[100]; 
int ikram = 0;

void addTask() {
    if (ikram < 100) {
        printf("Enter your task: ");
        scanf("%s", kawthar); 
        ikram++;
        printf("Task added successfully!\n");
    } else {
        printf("Task list is full!\n");
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













void showTasks() {
    if (ikram == 0) {
        printf("No tasks available.\n");
    } else {
        printf("Task List:\n");
        for (int i = 0; i < ikram; i++) {
            printf("%d. %s\n", i + 1, kawthar); 
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("*welcome to your to-do list!*\n");
        printf("Enter your choice:\n");
        printf("1 => Add task\n");
        printf("2 => Show tasks\n");
    //    printf("3 => Delete task\n");
   printf("4 => Edit task\n");
        printf("4 => Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                showTasks();
                break;
          //  case 3:
             //   deleteTask();
            //    break;
	    case 4
		    edit task();
	    break;
	    case 5:
                printf("Goodbye!\n");
                return 0;
           
        }
    }

    return 0;
}

