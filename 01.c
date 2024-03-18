#include <stdio.h>
#include <stdlib.h>

// Structure to represent a day
struct Day {
    char *name;
    int date;
    char *activity;
};

// Structure to represent a calendar
struct Calendar {
    struct Day days[7];
};

// Function to create a calendar
void create(struct Calendar *calendar) {
    for (int i = 0; i < 7; i++) {
        calendar->days[i].name = (char *)malloc(sizeof(char) * 20);
        calendar->days[i].activity = (char *)malloc(sizeof(char) * 50);
        
        printf("Enter day name for day %d: ", i + 1);
        scanf("%s", calendar->days[i].name);
        
        printf("Enter date for day %d: ", i + 1);
        scanf("%d", &calendar->days[i].date);
        
        printf("Enter activity for day %d: ", i + 1);
        scanf("%s", calendar->days[i].activity);
    }
}

// Function to read data from the keyboard
void read(struct Calendar *calendar) {
    printf("Enter calendar details:\n");
    create(calendar);
}

// Function to display the calendar
void display( struct Calendar *calendar) {
    printf("\nWeek's Activity Details:\n");
    for (int i = 0; i < 7; i++) {
        printf("Day %d: %s, Date: %d, Activity: %s\n", i + 1, calendar->days[i].name, calendar->days[i].date, calendar->days[i].activity);
    }
}

int main() {
    struct Calendar myCalendar;

    // Read data from the keyboard
    read(&myCalendar);

    // Display the calendar
    display(&myCalendar);

    // Free dynamically allocated memory
    for (int i = 0; i < 7; i++) {
        free(myCalendar.days[i].name);
        free(myCalendar.days[i].activity);
    }

    return 0;
}
