#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/todo.h"   // include your header file

char tasks[MAX_TASKS][MAX_LENGTH];
int taskCount = 0;

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task list full!\n");
        return;
    }
    printf("Enter new task: ");
    getchar();
    fgets(tasks[taskCount], MAX_LENGTH, stdin);
    tasks[taskCount][strcspn(tasks[taskCount], "\n")] = '\0';
    taskCount++;
    printf("Task added successfully!\n");
}

void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }
    printf("\n--- To-Do List ---\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
}

void deleteTask() {
    int num;
    viewTasks();
    if (taskCount == 0) return;

    printf("Enter task number to delete: ");
    scanf("%d", &num);
    if (num < 1 || num > taskCount) {
        printf("Invalid task number!\n");
        return;
    }
    for (int i = num - 1; i < taskCount - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
    }
    taskCount--;
    printf("Task deleted successfully!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- To-Do List Menu ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: deleteTask(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}