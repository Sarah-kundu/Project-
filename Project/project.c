#include <stdio.h>
#include <string.h>

typedef struct passenger { //creating a structure for passanger info
    char name[30];
    int age;
    char gender[10];
    char pref[10];
} passenger;

int main(){
    char SOURCE[20];  // creating character array
    char DESTINATION[20];
    float TICKET_PRICE= 2300; //the amount of the ticket will be stored here
    int AVAILABLE_SEATS= 50; //this shows the number of tickets that available
    char date_of_journey[15]; //stores the date of journey
    
    
    passenger p;

    printf("Search Train \n"); //searching the train
    printf("Route\nTo: "); //  taking input of desired destination from the user
    fgets(DESTINATION, sizeof(DESTINATION), stdin);
    DESTINATION[strcspn(DESTINATION, "\n")] = 0;

    printf("From: "); 
    fgets(SOURCE, sizeof(SOURCE), stdin);
    SOURCE[strcspn(SOURCE, "\n")] = 0;

    char class[30];
    printf("Choose class: \n AC1/AC2/AC3/ Sleeper\n");
    scanf("%s", class); // asking the user for their desired choice of class

    printf("\nEnter Date of Journey (DD/MM/YYYY): \n");
    scanf("%s", date_of_journey); //taking the input of the date

    if(AVAILABLE_SEATS > 30){
        printf("Ticket Available\n"); //checking the availability of the seat using if and else and comparing the values of seats present.
    }
    else if (AVAILABLE_SEATS <15 && AVAILABLE_SEATS > 0){ //if the tickets present are less than 15 then it will print Waitlist
        printf("Waitlist\n");
    }
    else {
        printf("Ticket unavailable\n"); //or else the program will end since there are no seats available
        return 0;
    }
    

    printf("Enter your personal details\n"); //asking the user the personal details as input

    printf("Passenger Name: \n");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0;

    
    printf("Passenger Age: \n");
    scanf("%d", &p.age); 
    
    printf("Gender (M/F/O): \n");
    scanf("%s",p.gender);

    printf("Berth Preference (Lower/Upper/None): \n");
    char p_pref[10];
    scanf("%s", p.pref);
    
    printf("Details recorded.\nAge: %d\nGender: %s\nPreference: %s\n", p.age, p.gender, p.pref);//Printing all the details taken as input from the user

    printf("Payment\n");
    printf("Ticket price: %.2f\n", TICKET_PRICE); //proceeding towards the payment for the ticket

    char confirm[3]; //creating a character array to ask for confirmation for payment
    printf("DO you want to proceed with the payment?\n");
    scanf("%s", &confirm);

    if (strcasecmp(confirm, "no") == 0) { // Check if 'confirm' is exactly "no"
        printf("Payment cancelled.\n"); // Added for clarity
        return 0; // Exit the program
        }

    printf("Payment successful\n");
    if (AVAILABLE_SEATS <15 && AVAILABLE_SEATS > 0){ //
        printf("Waitlist\n");
        return 0; //exit the program since the booking is not confirmed yet.
        }
    printf("Booking Confirmed!!\n"); // Otherwise booking will be confirmed 

    printf("E- TICKET CONFIRMED!!\n");// Generate an e-ticket which will contain the neccessary information along with with PNR and confirmation
    printf("PNR: JRU40953486\n");
    printf("Passanger: %s\n", p.name);
    printf("Date: %s\n", date_of_journey);
    printf("TO: %s\nFROM: %s\n", DESTINATION,SOURCE);
    printf("Class: %s\n", class);
    printf("Status: CONFIRMED!\n");

    
    getchar();
    getchar();

    return 0;
}