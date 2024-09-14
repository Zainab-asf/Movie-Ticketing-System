#include <stdio.h>
#include <string.h>

#define MAX_SEATS 100

struct Ticket {
    int ticketID;
    char movieName[50];
    int seatNumber;
    float price;
};

struct Ticket tickets[MAX_SEATS];
int numTickets = 0;

void bookTicket() {
    if (numTickets < MAX_SEATS) {
        struct Ticket newTicket;
        printf("Enter ticket ID: ");
        scanf("%d", &newTicket.ticketID);
        printf("Enter movie name: ");
        scanf("%s", newTicket.movieName);
        printf("Enter seat number: ");
        scanf("%d", &newTicket.seatNumber);
        printf("Enter ticket price: ");
        scanf("%f", &newTicket.price);

        tickets[numTickets] = newTicket;
        numTickets++;
        printf("Ticket booked successfully.\n");
    } else {
        printf("All seats are booked.\n");
    }
}

void cancelTicket() {
    int ticketID, found = 0;
    printf("Enter ticket ID to cancel: ");
    scanf("%d", &ticketID);

    for (int i = 0; i < numTickets; i++) {
        if (tickets[i].ticketID == ticketID) {
            for (int j = i; j < numTickets - 1; j++) {
                tickets[j] = tickets[j + 1];
            }
            numTickets--;
            found = 1;
            printf("Ticket canceled successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Ticket not found.\n");
    }
}

void displayTickets() {
    if (numTickets == 0) {
        printf("No tickets booked.\n");
    } else {
        printf("****** Ticket Details ******\n");
        for (int i = 0; i < numTickets; i++) {
            printf("Ticket ID: %d\n", tickets[i].ticketID);
            printf("Movie Name: %s\n", tickets[i].movieName);
            printf("Seat Number: %d\n", tickets[i].seatNumber);
            printf("Price: %.2f\n", tickets[i].price);
            printf("-----------------------------\n");
        }
    }
}

int main() {
    int choice;
    do {
        printf("**********************************************\n");
        printf("*          Movie Ticket Booking System       *\n");
        printf("**********************************************\n");
        printf("* 1. Book Ticket                             *\n");
        printf("* 2. Cancel Ticket                           *\n");
        printf("* 3. Display All Tickets                     *\n");
        printf("* 4. Exit                                    *\n");
        printf("**********************************************\n");
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
            displayTickets();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice, try again.\n");
        }
    } while (choice != 4);

    return 0;
}
