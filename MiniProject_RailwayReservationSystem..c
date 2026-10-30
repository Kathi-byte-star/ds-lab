#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Passenger {
    int id;
    char name[50];
    int age;
    int trainNo;
    int seatNo;
    struct Passenger *next;
};

struct Passenger *head = NULL;
int seat = 1;

void bookTicket() {
    struct Passenger *newNode;

    newNode = (struct Passenger*)
              malloc(sizeof(struct Passenger));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter Passenger ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Passenger Name: ");
    scanf(" %49[^\n]", newNode->name);

    printf("Enter Age: ");
    scanf("%d", &newNode->age);

    printf("Enter Train Number: ");
    scanf("%d", &newNode->trainNo);

    newNode->seatNo = seat++;
    newNode->next = head;
    head = newNode;

    printf("\nTicket Booked Successfully!\n");
    printf("Seat Number: %d\n", newNode->seatNo);
}

void cancelTicket() {
    int id;
    struct Passenger *temp = head;
    struct Passenger *prev = NULL;

    printf("Enter Passenger ID to cancel: ");
    scanf("%d", &id);

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Reservation Not Found!\n");
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Ticket Cancelled Successfully!\n");
}

void displayReservations() {
    struct Passenger *temp = head;

    if (temp == NULL) {
        printf("No Reservations Available!\n");
        return;
    }

    printf("\n--- Passenger Reservation Details ---\n");

    while (temp != NULL) {
        printf("\nPassenger ID : %d", temp->id);
        printf("\nName         : %s", temp->name);
        printf("\nAge          : %d", temp->age);
        printf("\nTrain Number : %d", temp->trainNo);
        printf("\nSeat Number  : %d\n", temp->seatNo);

        temp = temp->next;
    }
}

int main() {
    int choice;

    do {
        printf("\n===== RAILWAY RESERVATION SYSTEM =====\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Display Reservations\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket();
                break;

            case 2:
                cancelTicket();
                break;

            case 3:
                displayReservations();
                break;

            case 4:
                printf("Thank You!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}
