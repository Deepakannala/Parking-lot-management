
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
    char plateNumber[20];
} Vehicle;

Vehicle parkingLot[MAX];
int front = -1, rear = -1;

// Check if parking is full
int isFull() {
    return rear == MAX - 1;
}

// Check if parking is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Add a vehicle
void addVehicle() {
    if (isFull()) {
        printf("Parking lot is full! Cannot add more vehicles.\n");
        return;
    }

    Vehicle v;
    printf("Enter vehicle plate number: ");
    scanf("%s", v.plateNumber);

    if (isEmpty()) {
        front = 0;
    }

    rear++;
    parkingLot[rear] = v;

    printf("Vehicle %s parked at spot %d.\n", v.plateNumber, rear + 1);
}

// Remove a vehicle (from front)
void removeVehicle() {
    if (isEmpty()) {
        printf("Parking lot is empty! No vehicles to remove.\n");
        return;
    }

    printf("Vehicle %s removed from spot %d.\n", parkingLot[front].plateNumber, front + 1);
    front++;

    if (front > rear) {
        front = rear = -1; // Reset if lot becomes empty
    }
}

// Check available space
void checkSpace() {
    if (isEmpty()) {
        printf("Parking lot is empty. %d spots available.\n", MAX);
    } else {
        printf("%d spots available.\n", MAX - (rear - front + 1));
    }
}

// Display parked vehicles
void displayVehicles() {
    if (isEmpty()) {
        printf("Parking lot is empty.\n");
        return;
    }

    printf("Vehicles in the parking lot:\n");
    for (int i = front; i <= rear; i++) {
        printf("Spot %d: %s\n", i + 1, parkingLot[i].plateNumber);
    }
}

// Menu
void menu() {
    printf("\n---- Parking Lot Menu ----\n");
    printf("1. Add Vehicle\n");
    printf("2. Remove Vehicle\n");
    printf("3. Check Available Space\n");
    printf("4. Display Parked Vehicles\n");
    printf("5. Exit\n");
    printf("--------------------------\n");
}

int main() {
    int choice;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addVehicle(); break;
            case 2: removeVehicle(); break;
            case 3: checkSpace(); break;
            case 4: displayVehicles(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }

    } while(choice != 5);

    return 0;
}
