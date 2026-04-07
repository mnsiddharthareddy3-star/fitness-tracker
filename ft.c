#include <stdio.h>

// Function declarations
void addData();
void viewReport();
void checkGoal();
void resetData();
void bmiCalculator();
void heartRateStatus();

// Global variables
int steps = 0;
float weight = 0, height = 0;
float calories = 0;
int heartRate = 0;

int main() {
    int choice;

    do {
        printf("\n===== Fitness Tracking App =====\n");
        printf("1. Enter Fitness Data\n");
        printf("2. View Fitness Report\n");
        printf("3. Check Daily Goal\n");
        printf("4. BMI Calculator\n");
        printf("5. Heart Rate Status\n");
        printf("6. Reset Data\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addData();
                break;

            case 2:
                viewReport();
                break;

            case 3:
                checkGoal();
                break;

            case 4:
                bmiCalculator();
                break;

            case 5:
                heartRateStatus();
                break;

            case 6:
                resetData();
                break;

            case 7:
                printf("Exiting program... Stay healthy! 💪\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 7);

    return 0;
}

// Add Data
void addData() {
    printf("\nEnter number of steps: ");
    scanf("%d", &steps);

    printf("Enter your weight (kg): ");
    scanf("%f", &weight);

    printf("Enter your height (meters): ");
    scanf("%f", &height);

    printf("Enter your heart rate (bpm): ");
    scanf("%d", &heartRate);

    calories = steps * 0.04;

    printf("Data saved successfully!\n");
}

// View Report
void viewReport() {
    if(steps == 0) {
        printf("\nNo data available!\n");
        return;
    }

    printf("\n----- Fitness Report -----\n");
    printf("Steps: %d\n", steps);
    printf("Weight: %.2f kg\n", weight);
    printf("Height: %.2f m\n", height);
    printf("Heart Rate: %d bpm\n", heartRate);
    printf("Calories Burned: %.2f kcal\n", calories);
}

// Check Goal
void checkGoal() {
    if(steps == 0) {
        printf("\nEnter data first!\n");
        return;
    }

    if (steps >= 10000) {
        printf("🎉 Goal Achieved! Great job!\n");
    } else {
        printf("You need %d more steps to reach goal.\n", 10000 - steps);
    }
}

// BMI Calculator
void bmiCalculator() {
    if(weight == 0 || height == 0) {
        printf("\nEnter data first!\n");
        return;
    }

    float bmi = weight / (height * height);

    printf("\nYour BMI: %.2f\n", bmi);

    if(bmi < 18.5)
        printf("Underweight\n");
    else if(bmi < 25)
        printf("Normal weight\n");
    else if(bmi < 30)
        printf("Overweight\n");
    else
        printf("Obese\n");
}

// Heart Rate Status
void heartRateStatus() {
    if(heartRate == 0) {
        printf("\nEnter data first!\n");
        return;
    }

    printf("\nHeart Rate: %d bpm\n", heartRate);

    if(heartRate < 60)
        printf("Low Heart Rate (Bradycardia)\n");
    else if(heartRate <= 100)
        printf("Normal Heart Rate\n");
    else
        printf("High Heart Rate (Tachycardia)\n");
}

// Reset Data
void resetData() {
    steps = 0;
    weight = 0;
    height = 0;
    heartRate = 0;
    calories = 0;

    printf("All data reset successfully!\n");
}