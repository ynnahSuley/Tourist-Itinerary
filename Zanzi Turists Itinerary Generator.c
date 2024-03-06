#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // Include the standard header for boolean type


// Define struct Activity, struct Location, struct UserAccount
struct Activity {
    // Define struct Activity
    char name[100];
    char location[100];
    char time[100];
    float cost;
    struct Activity* next;
};

struct Location {
    // Define struct Location
    char name[100];
    char description[500];
    char category[100];
    char openingHours[100];
    float cost;
    float locationCoordinates[2];
    char review[500];
    char recommendation[500];
    int selected;
    struct Activity* activities;
    struct Location* next;
};

struct UserAccount {
    // Define struct UserAccount
    char fullName[100];
    char country[50];
    char email[100];
    char username[50];
    char password[50];
    char purpose[200];
    struct UserAccount* next;
};


// Define struct ActivityNode
struct ActivityNode {
    char activityName[50];
    char location[50];
    char time[20];
    float expectedPrice;
    struct ActivityNode* next;
};
// Function prototypes
void initializeData(struct Location** locations, struct Activity** activityQueue);
void createAccount(struct UserAccount** accounts);
void addActivity(struct Activity** activityQueue, char name[], char location[], char time[], float cost);
void searchLocations(struct Location* locations);
void searchLocationsByCategory(struct Location* locations, char category[]);
void displayLocationList(struct Location* locations);
void createAndDisplayItinerary(struct Location** locations, struct Activity** activityQueue);
void createUserItinerary(struct Activity** activityQueue);
void viewItinerary(struct Activity* activityQueue, struct Location* locations);
int login(struct UserAccount* accounts, struct UserAccount** currentUser);
void modifyAccountInfo(struct UserAccount* currentUser);
void changePassword(struct UserAccount* currentUser);
void changeUsername(struct UserAccount* currentUser);
void changeFullName(struct UserAccount* currentUser);
bool isValidTimeFormat(const char *time);
bool isValidDouble(const char *str);




// Function to initialize predefined data
void initializeData(struct Location** locations, struct Activity** activityQueue) {
    struct Location* loc = (struct Location*)malloc(sizeof(struct Location));
    strcpy(loc->name, "Stone Town");
    strcpy(loc->description, "Historic central district of Zanzibar City");
    strcpy(loc->category, "Historical Site");
    strcpy(loc->openingHours, "9:00 AM");
    loc->cost = 40.0; // Entry fee changed to cost
    loc->locationCoordinates[0] = -6.1651; // Latitude
    loc->locationCoordinates[1] = 39.1910; // Longitude
    loc->activities = NULL;
    loc->next = NULL;
    loc->selected = 0;
    *locations = loc;

    // Add activities for Stone Town
    addActivity(&(*locations)->activities, "Historical Walking Tour", "Stone Town", "10:00 AM", (*locations)->cost);

    // Kendwa Beach
    loc = (struct Location*)malloc(sizeof(struct Location));
    strcpy(loc->name, "Kendwa Beach");
    strcpy(loc->description, "Beautiful white sand beach");
    strcpy(loc->category, "Beach");
    strcpy(loc->openingHours, "3:00 PM");
    loc->cost = 10.0; // Entry fee changed to cost
    loc->locationCoordinates[0] = -5.8033; // Latitude
    loc->locationCoordinates[1] = 39.2825; // Longitude
    loc->activities = NULL;
    loc->next = *locations;
    loc->selected = 0;
    *locations = loc;

    // Add activities for Kendwa Beach
    addActivity(&(*locations)->activities, "Beach Relaxation", "Kendwa Beach", "2:00 PM", (*locations)->cost);

    // Nungwi Village
    loc = (struct Location*)malloc(sizeof(struct Location));
    strcpy(loc->name, "Nungwi Village");
    strcpy(loc->description, "Quaint coastal village");
    strcpy(loc->category, "Village");
    strcpy(loc->openingHours, "8:00 AM");
    loc->cost = 12.0; // Entry fee changed to cost
    loc->locationCoordinates[0] = -5.7269; // Latitude
    loc->locationCoordinates[1] = 39.2944; // Longitude
    loc->activities = NULL;
    loc->next = *locations;
    loc->selected = 0;
    *locations = loc;

    // Add activities for Nungwi Village
    addActivity(&(*locations)->activities, "Cultural Experience in Nungwi", "Nungwi Village", "3:00 PM", (*locations)->cost);

    // Paje Beach
    loc = (struct Location*)malloc(sizeof(struct Location));
    strcpy(loc->name, "Paje Beach");
    strcpy(loc->description, "Popular spot for kite surfing");
    strcpy(loc->category, "Beach");
    strcpy(loc->openingHours, "10:00 AM");
    loc->cost = 15.0; // Entry fee changed to cost
    loc->locationCoordinates[0] = -6.2500; // Latitude
    loc->locationCoordinates[1] = 39.4833; // Longitude
    loc->activities = NULL;
    loc->next = *locations;
    loc->selected = 0;
    *locations = loc;

    // Add activities for Paje Beach
    addActivity(&(*locations)->activities, "Kite Surfing Adventure", "Paje Beach", "9:00 AM", (*locations)->cost);

    // Jozani Chwaka Bay National Park
    loc = (struct Location*)malloc(sizeof(struct Location));
    strcpy(loc->name, "Jozani Chwaka Bay National Park");
    strcpy(loc->description, "Home to the rare Red Colobus monkeys");
    strcpy(loc->category, "National Park");
    strcpy(loc->openingHours, "8:00 AM");
    loc->cost = 25.0; // Entry fee changed to cost
    loc->locationCoordinates[0] = -6.2000; // Latitude
    loc->locationCoordinates[1] = 39.3700; // Longitude
    loc->activities = NULL;
    loc->next = *locations;
    loc->selected = 0;
    *locations = loc;

    // Add activities for Jozani Chwaka Bay National Park
    addActivity(&(*locations)->activities, "Wildlife Safari", "Jozani Chwaka Bay National Park", "8:00 AM", (*locations)->cost);

    // Prison Island
    loc = (struct Location*)malloc(sizeof(struct Location));
    strcpy(loc->name, "Prison Island");
    strcpy(loc->description, "Former prison and home to giant tortoises");
    strcpy(loc->category, "Historical Site");
    strcpy(loc->openingHours, "9:00 AM ");
    loc->cost = 20.0; // Entry fee changed to cost
    loc->locationCoordinates[0] = -6.1575; // Latitude
    loc->locationCoordinates[1] = 39.1922; // Longitude
    loc->activities = NULL;
    loc->next = *locations;
    loc->selected = 0;
    *locations = loc;

    // Add activities for Prison Island
    addActivity(&(*locations)->activities, "Prison History Tour", "Prison Island", "10:30 AM", (*locations)->cost);

    // Kizimkazi Village
    loc = (struct Location*)malloc(sizeof(struct Location));
    strcpy(loc->name, "Kizimkazi Village");
    strcpy(loc->description, "Fishing village and dolphin watching spot");
    strcpy(loc->category, "Village");
    strcpy(loc->openingHours, "5:00 PM");
    loc->cost = 10.0; // Entry fee changed to cost
    loc->locationCoordinates[0] = -6.5936; // Latitude
    loc->locationCoordinates[1] = 39.1953; // Longitude
    loc->activities = NULL;
    loc->next = *locations;
    loc->selected = 0;
    *locations = loc;

    // Add activities for Kizimkazi Village
    addActivity(&(*locations)->activities, "Dolphin Watching Excursion", "Kizimkazi Village", "7:00 AM", (*locations)->cost);

    // Mbudya Island
    loc = (struct Location*)malloc(sizeof(struct Location));
    strcpy(loc->name, "Mbudya Island");
    strcpy(loc->description, "Small island with pristine beaches");
    strcpy(loc->category, "Island");
    strcpy(loc->openingHours, "9:00 AM ");
    loc->cost = 30.0; // Entry fee changed to cost
    loc->locationCoordinates[0] = -6.2139; // Latitude
    loc->locationCoordinates[1] = 39.2350; // Longitude
    loc->activities = NULL;
    loc->next = *locations;
    loc->selected = 0;
    *locations = loc;

    // Add activities for Mbudya Island
    addActivity(&(*locations)->activities, "Island Relaxation", "Mbudya Island", "11:00 AM", (*locations)->cost);

    // Kiwengwa Beach
    loc = (struct Location*)malloc(sizeof(struct Location));
    strcpy(loc->name, "Kiwengwa Beach");
    strcpy(loc->description, "Long stretch of white sand beach");
    strcpy(loc->category, "Beach");
    strcpy(loc->openingHours, "11:00 AM ");
    loc->cost = 18.0; // Entry fee changed to cost
    loc->locationCoordinates[0] = -5.9850; // Latitude
    loc->locationCoordinates[1] = 39.3236; // Longitude
    loc->activities = NULL;
    loc->next = *locations;
    loc->selected = 0;
    *locations = loc;

    // Add activities for Kiwengwa Beach
    addActivity(&(*locations)->activities, "Beach Day at Kiwengwa", "Kiwengwa Beach", "9:00 AM", (*locations)->cost);

    // Kendwa Village
    loc = (struct Location*)malloc(sizeof(struct Location));
    strcpy(loc->name, "Kendwa Village");
    strcpy(loc->description, "Charming coastal village");
    strcpy(loc->category, "Village");
    strcpy(loc->openingHours, "8:00 AM");
    loc->cost = 14.0; // Entry fee changed to cost
    loc->locationCoordinates[0] = -5.8033; // Latitude
    loc->locationCoordinates[1] = 39.2825; // Longitude
    loc->activities = NULL;
    loc->next = *locations;
    loc->selected = 0;
    *locations = loc;

    // Add activities for Kendwa Village
    addActivity(&(*locations)->activities, "Village Exploration in Kendwa", "Kendwa Village", "2:00 PM", (*locations)->cost);

    // Nungwi Beach
    loc = (struct Location*)malloc(sizeof(struct Location));
    strcpy(loc->name, "Nungwi Beach");
    strcpy(loc->description, "Popular tourist destination with beautiful beaches");
    strcpy(loc->category, "Beach");
    strcpy(loc->openingHours, "9:00 AM");
    loc->cost = 20.0; // Entry fee changed to cost
    loc->locationCoordinates[0] = -5.7269; // Latitude
    loc->locationCoordinates[1] = 39.2944; // Longitude
    loc->activities = NULL;
    loc->next = *locations;
    loc->selected = 0;
    *locations = loc;

    // Add activities for Nungwi Beach
    addActivity(&(*locations)->activities, "Sunset at Nungwi Beach", "Nungwi Beach", "5:00 PM", (*locations)->cost);

    // Paje Village
    loc = (struct Location*)malloc(sizeof(struct Location));
    strcpy(loc->name, "Paje Village");
    strcpy(loc->description, "Quaint village known for kite surfing");
    strcpy(loc->category, "Village");
    strcpy(loc->openingHours, "2:00 PM");
    loc->cost = 13.0; // Entry fee changed to cost
    loc->locationCoordinates[0] = -6.2500; // Latitude
    loc->locationCoordinates[1] = 39.4833; // Longitude
    loc->activities = NULL;
    loc->next = *locations;
    loc->selected = 0;
    *locations = loc;

    // Add activities for Paje Village
    addActivity(&(*locations)->activities, "Cultural Experience in Paje", "Paje Village", " 3:00 PM ", (*locations)->cost);

    // Jambiani Beach
    loc = (struct Location*)malloc(sizeof(struct Location));
    strcpy(loc->name, "Jambiani Beach");
    strcpy(loc->description, "Scenic beach in a peaceful village");
    strcpy(loc->category, "Beach");
    strcpy(loc->openingHours, "9:00 AM");
    loc->cost = 16.0; // Entry fee changed to cost
    loc->locationCoordinates[0] = -6.2497; // Latitude
    loc->locationCoordinates[1] = 39.5221; // Longitude
    loc->activities = NULL;
    loc->next = *locations;
    loc->selected = 0;
    *locations = loc;

    // Add activities for Jambiani Beach
    addActivity(&(*locations)->activities, "Beach Day at Jambiani", "Jambiani Beach", "10:00 AM", (*locations)->cost);

    // Chumbe Island Coral Park
    loc = (struct Location*)malloc(sizeof(struct Location));
    strcpy(loc->name, "Chumbe Island Coral Park");
    strcpy(loc->description, "Protected coral reef and forest reserve");
    strcpy(loc->category, "Island");
    strcpy(loc->openingHours, "9:00 AM ");
    loc->cost = 28.0; // Entry fee changed to cost
    loc->locationCoordinates[0] = -6.2400; // Latitude
    loc->locationCoordinates[1] = 39.2069; // Longitude
    loc->activities = NULL;
    loc->next = *locations;
    loc->selected = 0;
    *locations = loc;

    // Add activities for Chumbe Island Coral Park
    addActivity(&(*locations)->activities, "Snorkeling at Chumbe Island", "Chumbe Island Coral Park", "11:00 AM", (*locations)->cost);

    // Initialize the activity queue
    *activityQueue = NULL;
}


// Function to add an activity to the queue
// Function to add an activity to the queue
void addActivity(struct Activity** activityQueue, char name[], char location[], char time[], float cost) {
    struct Activity* newActivity = (struct Activity*)malloc(sizeof(struct Activity));
    strcpy(newActivity->name, name);
    strcpy(newActivity->location, location);
    strcpy(newActivity->time, time);  // Set the time information
    newActivity->cost = cost; // Use the provided cost
    newActivity->next = NULL;

    if (*activityQueue == NULL) {
        *activityQueue = newActivity;
    } else {
        struct Activity* temp = *activityQueue;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newActivity;
    }
}



// Function to create an account
void createAccount(struct UserAccount** accounts) {
    struct UserAccount* newUser = (struct UserAccount*)malloc(sizeof(struct UserAccount));

    printf("Enter your full name: ");
    fgets(newUser->fullName, sizeof(newUser->fullName), stdin);
    printf("Enter your country: ");
    fgets(newUser->country, sizeof(newUser->country), stdin);
    printf("Enter your email: ");
    fgets(newUser->email, sizeof(newUser->email), stdin);
    printf("Enter a username: ");
    fgets(newUser->username, sizeof(newUser->username), stdin);
    printf("Enter a password: ");
    fgets(newUser->password, sizeof(newUser->password), stdin);
    printf("Enter purpose for visiting Zanzibar: ");
    fgets(newUser->purpose, sizeof(newUser->purpose), stdin);

    // Remove trailing newline characters
    strtok(newUser->fullName, "\n");
    strtok(newUser->country, "\n");
    strtok(newUser->email, "\n");
    strtok(newUser->username, "\n");
    strtok(newUser->password, "\n");
    strtok(newUser->purpose, "\n");

    newUser->next = *accounts;
    *accounts = newUser;

    printf("Account created successfully!\n");
}

// Function to log in
int login(struct UserAccount* accounts, struct UserAccount** currentUser) {
    char username[50];
    char password[50];

    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);

    // Remove trailing newline characters
    strtok(username, "\n");
    strtok(password, "\n");

    while (accounts != NULL) {
        if (strcmp(accounts->username, username) == 0 && strcmp(accounts->password, password) == 0) {
            printf("Login successful!\n");
            // Assign the logged-in user to currentUser
            *currentUser = accounts;
            return 1; // Login successful
        }
        accounts = accounts->next;
    }

    printf("Invalid username or password. Please try again.\n");
    return 0; // Login failed
}




// Function to search for locations based on user preferences (category)
void searchLocationsByCategory(struct Location* locations, char category[]) {
    // Take only the first letter of the category
    char firstLetter = category[0];

    printf("\nSearch Results:\n");
    int locationNumber = 1;
    while (locations != NULL) {
        // Check if the first letter of the location's category matches the user's provided first letter
        if (toupper(locations->category[0]) == toupper(firstLetter)) {
            printf("--------------------------------------\n");
            printf("%d. Location: %s\n", locationNumber, locations->name);
            printf("Description: %s\n", locations->description);
            printf("Category: %s\n", locations->category);
            printf("Time at : %s\n", locations->openingHours);
            printf("Cost: %.2f Tsh\n", locations->cost); // Updated to use cost instead of entryFees
            printf("Coordinates: %.4f, %.4f\n", locations->locationCoordinates[0], locations->locationCoordinates[1]);
            locationNumber++;
        }
        locations = locations->next;
    }

    if (locationNumber == 1) {
        printf("No locations found matching the given category.\n");
    }
}


// Function to display a list of locations
// Function to display a list of locations with details
void displayLocationList(struct Location* locations) {
    printf("Location List:\n");
    int count = 1;
    while (locations != NULL) {
        printf("--------------------------------------\n");
        printf("%d. Location: %s\n", count, locations->name);
        printf("Description: %s\n", locations->description);
        printf("Category: %s\n", locations->category);
        printf("Time at: %s\n", locations->openingHours);
        printf("Cost: $%.2f\n", locations->cost); // Updated entryFees to cost and changed to dollars
        printf("Coordinates: %.4f, %.4f\n", locations->locationCoordinates[0], locations->locationCoordinates[1]);
        printf("Selected for Itinerary: %s\n", locations->selected ? "Yes" : "No");
        locations = locations->next;
        count++;
    }
}



// Function to create and display an itinerary
void createAndDisplayItinerary(struct Location** locations, struct Activity** activityQueue) {
    struct Activity* act;

    displayLocationList(*locations);

    printf("\nEnter the numbers of the locations you want to add to your itinerary (separated by commas): ");
    char input[100];
    fgets(input, sizeof(input), stdin);

    char* token = strtok(input, ",");
    while (token != NULL) {
        int locationNumber = atoi(token);
        if (locationNumber >= 1 && locationNumber <= 15) {
            struct Location* temp = *locations;
            for (int i = 1; i < locationNumber; i++) {
                temp = temp->next;
            }
            if (temp->selected == 1) {
                printf("Location '%s' is already added to the itinerary.\n", temp->name);
                printf("1. Choose another location\n");
                printf("2. Return to create itinerary menu\n");
                printf("Enter your choice: ");
                int choice;
                scanf("%d", &choice);
                getchar(); // Consume the newline character
                if (choice == 1) {
                    // Prompt user to choose another location
                    printf("\nEnter the numbers of the locations you want to add to your itinerary (separated by commas): ");
                    fgets(input, sizeof(input), stdin);
                    token = strtok(input, ",");
                    continue; // Restart the loop
                } else if (choice == 2) {
                    // Return to create itinerary menu
                    return;
                } else {
                    printf("Invalid choice. Returning to create itinerary menu.\n");
                    return;
                }
            } else {
                temp->selected = 1;
                struct Activity* activity = temp->activities;
                while (activity != NULL) {
                    addActivity(activityQueue, activity->name, activity->location, activity->time, temp->cost); // Modified to use location's cost
                    activity = activity->next;
                }
            }
        }
        token = strtok(NULL, ",");
    }

    printf("\nItinerary created successfully!\n");
}



// Function to create a new activity node
struct ActivityNode* createActivityNode(char activityName[], char location[], char time[], float expectedPrice) {
    struct ActivityNode* newNode = (struct ActivityNode*)malloc(sizeof(struct ActivityNode));
    if (newNode != NULL) {
        strcpy(newNode->activityName, activityName);
        strcpy(newNode->location, location);
        strcpy(newNode->time, time);
        newNode->expectedPrice = expectedPrice;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to insert a new activity node at the end of the itinerary
void insertActivity(struct ActivityNode** head, char activityName[], char location[], char time[], float expectedPrice) {
    struct ActivityNode* newNode = createActivityNode(activityName, location, time, expectedPrice);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct ActivityNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}



// Function prototypes for time format and double number validation
bool isValidTimeFormat(const char *time);
bool isValidDouble(const char *str);

void createUserItinerary(struct Activity** activityQueue) {
    printf("\nAdd Activity to Itinerary:\n");
    char name[100];
    char location[100];
    char time[100];
    double cost;

    printf("Enter Activity Name: ");
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n");

    printf("Enter Location: ");
    fgets(location, sizeof(location), stdin);
    strtok(location, "\n");

    // Prompt the user until a valid time format is entered
    do {
        printf("Enter Time (HH:MM AM/PM): ");
        fgets(time, sizeof(time), stdin);
        strtok(time, "\n");

        if (!isValidTimeFormat(time)) {
            printf("Invalid time format. Please enter time in HH:MM AM/PM format.\n");
        }
    } while (!isValidTimeFormat(time));

    // Prompt the user until a valid double number is entered for the cost
    do {
        char costStr[100];
        printf("Enter Cost: ");
        fgets(costStr, sizeof(costStr), stdin);
        strtok(costStr, "\n");

        if (!isValidDouble(costStr)) {
            printf("Invalid input. Please enter a valid double number.\n");
        } else {
            cost = atof(costStr); // Convert the validated string to a double
            break; // Exit the loop if a valid double is entered
        }
    } while (true);

    // Create a new activity node
    struct Activity* newActivity = (struct Activity*)malloc(sizeof(struct Activity));
    if (newActivity == NULL) {
        printf("Memory allocation failed. Unable to add activity to itinerary.\n");
        return;
    }

    // Initialize the new activity node
    strcpy(newActivity->name, name);
    strcpy(newActivity->location, location);
    strcpy(newActivity->time, time);
    newActivity->cost = cost;
    newActivity->next = NULL;

    // Add the new activity to the end of the activity queue
    if (*activityQueue == NULL) {
        // If the activity queue is empty, set the new activity as the head
        *activityQueue = newActivity;
    } else {
        // Otherwise, find the last activity in the queue and append the new activity
        struct Activity* currentActivity = *activityQueue;
        while (currentActivity->next != NULL) {
            currentActivity = currentActivity->next;
        }
        currentActivity->next = newActivity;
    }

    printf("Activity added to itinerary successfully.\n");
}

// Validation function to check if the time format is valid
bool isValidTimeFormat(const char *time) {
    int hours, minutes;
    char am_pm[3];
    if (sscanf(time, "%d:%d %2s", &hours, &minutes, am_pm) != 3) {
        return false; // Unable to parse the time string
    }

    if ((hours < 1 || hours > 12) || (minutes < 0 || minutes > 59)) {
        return false; // Hour or minutes out of range
    }

    if (strcmp(am_pm, "AM") != 0 && strcmp(am_pm, "PM") != 0) {
        return false; // AM/PM indicator is not valid
    }

    return true; // Time format is valid
}

// Validation function to check if the string represents a valid double number
bool isValidDouble(const char *str) {
    char* endptr; // Pointer to character after the converted number
    strtod(str, &endptr); // Attempt to convert the string to a double

    // Check if conversion was successful and if the entire string was consumed
    return *endptr == '\0';
}



// Function to compare two times in HH:MM AM/PM format
int compareTimes(char time1[], char time2[]) {
    int hours1, hours2, mins1, mins2;
    char period1[3], period2[3];

    sscanf(time1, "%d:%d %2s", &hours1, &mins1, period1);
    sscanf(time2, "%d:%d %2s", &hours2, &mins2, period2);

    if (strcmp(period1, "AM") == 0 && strcmp(period2, "PM") == 0)
        return -1; // time1 is earlier
    else if (strcmp(period1, "PM") == 0 && strcmp(period2, "AM") == 0)
        return 1; // time2 is earlier
    else if (hours1 < hours2)
        return -1; // time1 is earlier
    else if (hours1 > hours2)
        return 1; // time2 is earlier
    else if (mins1 < mins2)
        return -1; // time1 is earlier
    else if (mins1 > mins2)
        return 1; // time2 is earlier

    return 0; // times are equal
}

// Function to sort activities by time
void sortActivitiesByTime(struct Activity** activityQueue) {
    struct Activity* current = *activityQueue;
    struct Activity* prev = NULL;

    while (current != NULL && compareTimes(current->time, "12:00 PM") > 0) {
        prev = current;
        current = current->next;
    }

    if (prev != NULL)
        prev->next = NULL;

    struct Activity* amQueue = *activityQueue;
    struct Activity* pmQueue = current;

    // Sorting activities in the AM queue
    struct Activity* temp;
    for (struct Activity* i = amQueue; i != NULL; i = i->next) {
        for (struct Activity* j = i->next; j != NULL; j = j->next) {
            if (compareTimes(i->time, j->time) > 0) {
                temp = i;
                i = j;
                j = temp;
            }
        }
    }

    // Sorting activities in the PM queue
    for (struct Activity* i = pmQueue; i != NULL; i = i->next) {
        for (struct Activity* j = i->next; j != NULL; j = j->next) {
            if (compareTimes(i->time, j->time) > 0) {
                temp = i;
                i = j;
                j = temp;
            }
        }
    }

    // Merging AM and PM queues
    if (prev != NULL)
        prev->next = amQueue;
    else
        *activityQueue = amQueue;

    while (amQueue->next != NULL)
        amQueue = amQueue->next;

    amQueue->next = pmQueue;
}

// Function to view the itinerary and calculate total cost
void viewItinerary(struct Activity* activityQueue, struct Location* locations) {
    printf("\nVIEW ITINERARY:\n");

    if (activityQueue == NULL) {
        printf("No activities in the itinerary.\n");
        return;
    }

    printf("Activities in Your Itinerary:\n");
    int activityNumber = 1;
    struct Activity* currentActivity = activityQueue;
    while (currentActivity != NULL) {
        printf("%d. %s at %s - %s - Cost: %.2f Tsh\n", activityNumber, currentActivity->name, currentActivity->location, currentActivity->time, currentActivity->cost);
        activityNumber++;
        currentActivity = currentActivity->next;
    }

    // Calculate and display total prices for all activities
    float totalCost = 0;
    currentActivity = activityQueue;
    while (currentActivity != NULL) {
        totalCost += currentActivity->cost;
        currentActivity = currentActivity->next;
    }
    printf("\nTotal Cost for All Activities: %.2f $\n", totalCost);
}




// Merge function for merge sort
void merge(struct Location* arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    struct Location* L[n1];
    struct Location* R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (strcmp(L[i]->name, R[j]->name) < 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(struct Location* arr[], int left, int right) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to write recommendations for a specific itinerary
void writeRecommendations(struct Location* locations, struct Activity* activityQueue) {
    // Check if there are any itineraries created
    if (activityQueue == NULL) {
        printf("No itinerary created. Please create an itinerary first.\n");
        return;
    }

    struct Location* temp = locations; // Temporary pointer for traversing

    // Display the list of locations with selected itineraries
    printf("\nItinerary List with Selected Locations:\n");
    int count = 1;
    while (temp != NULL) {
        if (temp->selected) {
            printf("--------------------------------------\n");
            printf("%d. Location: %s\n", count, temp->name);
            printf("Description: %s\n", temp->description);
            printf("Category: %s\n", temp->category);
            printf("Time at : %s\n", temp->openingHours);
            printf("Entry Fees: %.2f Tsh\n", temp->cost);
            printf("Coordinates: %.4f, %.4f\n", temp->locationCoordinates[0], temp->locationCoordinates[1]);
            printf("Review: %s\n", temp->review);
            printf("Recommendation: %s\n", temp->recommendation);
            count++;
        }
        temp = temp->next;
    }

    // Reset temp pointer to the beginning of the list
    temp = locations;

    // Sort the locations before asking the user to choose a location
    int numLocations = 0;
    while (temp != NULL) {
        if (temp->selected)
            numLocations++;
        temp = temp->next;
    }

    struct Location* locationArr[numLocations];
    temp = locations;
    int index = 0;
    while (temp != NULL) {
        if (temp->selected) {
            locationArr[index] = temp;
            index++;
        }
        temp = temp->next;
    }

    // Perform merge sort on the array of locations
    mergeSort(locationArr, 0, numLocations - 1);

    // Display the sorted list of locations with selected itineraries
    printf("\nSorted Itinerary List with Selected Locations:\n");
    count = 1;
    for (int i = 0; i < numLocations; i++) {
        printf("--------------------------------------\n");
        printf("%d. Location: %s\n", count, locationArr[i]->name);
        printf("Description: %s\n", locationArr[i]->description);
        printf("Category: %s\n", locationArr[i]->category);
        printf("Time at : %s\n", locationArr[i]->openingHours);
        printf("Entry Fees: %.2f Tsh\n", locationArr[i]->cost);
        printf("Coordinates: %.4f, %.4f\n", locationArr[i]->locationCoordinates[0], locationArr[i]->locationCoordinates[1]);
        printf("Review: %s\n", locationArr[i]->review);
        printf("Recommendation: %s\n", locationArr[i]->recommendation);
        count++;
    }

    // Ask the user to choose a location to write a recommendation for
    int locationChoice;
    printf("\nEnter the number of the location to write a recommendation for (0 to return to main menu): ");
    scanf("%d", &locationChoice);
    getchar(); // Consume newline character

    // Check if the user wants to return to the main menu
    if (locationChoice == 0) {
        printf("Returning to Main Menu.\n");
        return;
    }

    // Find the selected location based on the user's choice
    struct Location* selectedLocation = NULL;
    count = 1;
    for (int i = 0; i < numLocations; i++) {
        if (locationArr[i]->selected) {
            if (count == locationChoice) {
                selectedLocation = locationArr[i];
                break;
            }
            count++;
        }
    }

    // Check if a valid location was found
    if (selectedLocation == NULL) {
        printf("Invalid location choice.\n");
        return;
    }

    // Ask the user to write a recommendation
    printf("\nWrite your recommendation for %s:\n", selectedLocation->name);
    fgets(selectedLocation->recommendation, sizeof(selectedLocation->recommendation), stdin);
    strtok(selectedLocation->recommendation, "\n"); // Remove trailing newline characters

    // Confirmation message
    printf("\nRecommendation for %s saved successfully!\n", selectedLocation->name);

    // Ask the user if they want to write another recommendation or return to main menu
    char choice;
    printf("Do you want to write a recommendation for another location? (y/n): ");
    scanf(" %c", &choice);
    getchar(); // Consume newline character

    if (choice == 'y' || choice == 'Y') {
        writeRecommendations(locations, activityQueue);
    } else {
        printf("Returning to Main Menu.\n");
    }
}

// Function to display recommendations for a specific location
void displayRecommendations(const struct Location* locations) {
    // Iterate through the locations
    const struct Location* temp = locations;
    while (temp != NULL) {
        if (temp->selected) {
            // Display recommendations for selected locations
            printf("--------------------------------------\n");
            printf("Location: %s\n", temp->name);
            printf("Recommendation: %s\n", temp->recommendation);
        }
        temp = temp->next;
    }
}



// Function to change the password of the current user
void changePassword(struct UserAccount* currentUser) {
    printf("Enter new password: ");
    fgets(currentUser->password, sizeof(currentUser->password), stdin);
    strtok(currentUser->password, "\n");
    printf("Password changed successfully.\n");
}

// Function to change the username of the current user
void changeUsername(struct UserAccount* currentUser) {
    printf("Enter new username: ");
    fgets(currentUser->username, sizeof(currentUser->username), stdin);
    strtok(currentUser->username, "\n");
    printf("Username changed successfully.\n");
}

// Function to change the full name of the current user
void changeFullName(struct UserAccount* currentUser) {
    printf("Enter new full name: ");
    fgets(currentUser->fullName, sizeof(currentUser->fullName), stdin);
    strtok(currentUser->fullName, "\n");
    printf("Full name changed successfully!\n");
}

// Function to modify account information
void modifyAccountInfo(struct UserAccount* account) {
    printf("\nModify Account Information:\n");
    printf("1. Change Password\n");
    printf("2. Change Username\n");
    printf("3. Change Full Name\n");
    printf("4. Return to Main Menu\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);
    getchar(); // Consume newline character

    switch (choice) {
        case 1:
            changePassword(account);
            break;
        case 2:
            changeUsername(account);
            break;
        case 3:
            changeFullName(account);
            break;
        case 4:
            printf("Returning to Main Menu.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
    }
}




int getIntInput() {
    int input;
    char buffer[256]; // Buffer to store input

    while (1) {
        // Display the prompt message
        printf("Enter your choice: ");

        // Read the input
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Remove trailing newline character, if present
            buffer[strcspn(buffer, "\n")] = '\0';

            // Check if the input contains only digits
            int valid = 1;
            for (int i = 0; buffer[i] != '\0'; i++) {
                if (!isdigit(buffer[i])) {
                    valid = 0;
                    break;
                }
            }

            // If the input contains only digits, convert it to an integer
            if (valid) {
                if (sscanf(buffer, "%d", &input) == 1) {
                    return input;
                }
            }
        }

        // Display the error message
        printf("Invalid input. Please enter a number.\n");
    }
}






// Main function
int main() {
    struct Location* locations = NULL;
    struct Activity* activityQueue = NULL;
    struct UserAccount* accounts = NULL;

    // Initialize data
    initializeData(&locations, &activityQueue);

    int choice;
    do {
        printf("WELCOME \n\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Exit\n");

        // Get user input
        choice = getIntInput();

        switch (choice) {
            case 1:
                createAccount(&accounts);
                break;

            case 2:
                if (accounts == NULL) {
                    printf("No accounts created yet. Please create an account first.\n");
                    break;
                }

				// Declare currentUser as a pointer to a pointer to a struct UserAccount
				struct UserAccount* currentUser = NULL;
				
				// Call the login function with the address of currentUser
				if (login(accounts, &currentUser)) {
                    // Proceed to main menu
                    int mainChoice;
                    do {
                        printf("\nMAIN MENU:\n");
                        printf("1. CREATE ITINERARY\n");
                        printf("2. REVIEW AND RECOMMENDATIONS\n");
                        printf("3. ACCOUNT SETTING\n");
                        printf("4. LOGOUT\n");

                        // Get user input
                        mainChoice = getIntInput();

                        switch (mainChoice) {
                            case 1:
                                {
                                    // Sub-menu for creating itinerary
                                    int subChoice; // Move the declaration here
                                    do {
                                        printf("\nCREATE ITINERARY:\n");
                                        printf("1. Create Your Own Itinerary\n");
                                        printf("2. Recommended Location and Activities list\n");
                                        printf("3. View Itinerary\n");
                                        printf("4. Search Locations by Category\n");
                                        printf("5. Return to Main Menu\n");

                                        // Get user input
                                        subChoice = getIntInput();

                                        switch (subChoice) {
                                            case 1:
                                                createUserItinerary(&activityQueue); // Call createUserItinerary function
                                                break;
                                            case 2:
                                                createAndDisplayItinerary(&locations, &activityQueue);
                                                break;
                                            case 3:
                                                viewItinerary(activityQueue, locations);
                                                break;
                                            case 4:
                                                {
                                                    // Search locations by category
                                                    char searchCategory[20]; // Move the declaration here
                                                    printf("Enter category for search: ");
                                                    scanf("%19s", searchCategory); // Limit input to 19 characters to avoid buffer overflow
                                                    getchar(); // Consume newline character
                                                    searchLocationsByCategory(locations, searchCategory);
                                                }
                                                break;
                                            case 5:
                                                printf("Returning to Main Menu.\n");
                                                break;
                                            default:
                                                printf("Invalid choice. Please enter a valid option.\n");
                                                // Clear the input buffer
                                                while (getchar() != '\n');
                                                break;
                                        }
                                    } while (subChoice != 5); // Continue looping until the user chooses to return to the main menu
                                }
                                break;

                            case 2:
                                // REVIEW AND RECOMMENDATIONS
                                if (locations != NULL) {
                                    writeRecommendations(locations, activityQueue);
                                } else {
                                    printf("No itinerary created yet. Please create an itinerary first.\n");
                                }
                                break;

                            case 3:
                                {
                                    // ACCOUNT SETTING
                                    // Your code for account setting here
                                    int accountSettingChoice;
                                    do {
                                        printf("\nACCOUNT SETTING:\n");
                                        printf("1. Change Password\n");
                                        printf("2. Change Username\n");
                                        printf("3. Change Full Name\n");
                                        printf("4. Return to Main Menu\n");

                                        // Get user input
                                        accountSettingChoice = getIntInput();

                                        switch (accountSettingChoice) {
                                            case 1:
                                                // Change Password
                                               changePassword(currentUser);
                                                break;
                                            case 2:
                                                // Change Username
                                                changeUsername(currentUser);
                                                break;
                                            case 3:
                                                // Change Full Name
                                               changeFullName(currentUser);
                                                break;
                                            case 4:
                                                printf("Returning to Main Menu.\n");
                                                break;
                                            default:
                                                printf("Invalid choice. Please enter a valid option.\n");
                                                // Clear the input buffer
                                                while (getchar() != '\n');
                                                break;
                                        }
                                    } while (accountSettingChoice != 4);
                                }
                                break;

                            case 4:
                                printf("Logging out.\n");
                                break;

                            default:
                                printf("Invalid choice. Please enter a valid option.\n");
                        }
                    } while (mainChoice != 4);
                }
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    // Free allocated memory before exiting
    // Free allocated memory for locations
    struct Location* tempLoc;
    while (locations != NULL) {
        tempLoc = locations;
        locations = locations->next;
        free(tempLoc);
    }

    // Free allocated memory for activityQueue
    struct Activity* tempActivity;
    while (activityQueue != NULL) {
        tempActivity = activityQueue;
        activityQueue = activityQueue->next;
        free(tempActivity);
    }

    return 0;
}
