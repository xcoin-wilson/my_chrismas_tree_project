#include <stdio.h>
#include <stdlib.h>

// Function to calculate the total number of stars in the last row of the tree
int calculateLastRowStars(int userRows) {
    int starsCount = 1;
    int decrease = 2;
    

    for (int i = 0; i < userRows; i++) {
        starsCount -= decrease;
        decrease += !(i % 2) ? 2 : 0;

        for (int a = 0; a < i + 4; a++) {
            starsCount += 2;
        }
    }
    return starsCount;
}

// Function to print the base pattern of the tree
void printBasePattern(int userRows, int maxStars) {
    int spaceCount = ((maxStars / 2) - userRows / 2) + !(userRows % 2);
    
    for (int i = 0; i < userRows; i++) {
        for (int a = 0; a < spaceCount; a++) {
            printf(" ");
        }
        for (int b = 0; b < userRows; b++) {
            printf("|");
        }
        printf("\n");
    }
}

// Function to print the Christmas tree pattern
void printChristmasTree(int userRows) {
    // Calculate the total number of stars in the last row of the tree
    int maxStars = calculateLastRowStars(userRows);
    int spaceCount = maxStars / 2;
    int starsCount = 1;
    int decrease = 2;

    // Loop through each row of the tree
    for (int i = 0; i < userRows; i++) {
        spaceCount += decrease / 2;
        starsCount -= decrease;
        decrease += !(i % 2) ? 2 : 0;

        // Loop to print each line of the current row
        for (int a = 0; a < i + 4; a++) {
            spaceCount -= 1;
            starsCount += 2;

            // Print leading spaces
            for (int b = 0; b < spaceCount; b++) {
                printf(" ");
            }
            // Print stars for the current line
            for (int c = 0; c < starsCount; c++) {
                printf("*");
            }
            printf("\n");
        }
    }

    // Print the base pattern of the tree
    printBasePattern(userRows, maxStars);
}

// Main function
int main(int argc, char** argv) {
    // Check if the correct number of command-line arguments is provided
    if (argc != 2) {
        printf("Usage: %s <number_of_rows>\n", argv[0]);
        return 1;
    }

    // Convert the input argument to an integer
    int numRows = atoi(argv[1]);

    // Call the function to print the Christmas tree pattern
    printChristmasTree(numRows);

    return 0;
}
