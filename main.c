// ELEC2645 Unit 2 Project Template
// Command Line Application Menu Handling Code

#include "funcs.h"

int main(void) {
    printf("========================================\n");
    printf("      Engineering Calculator v1.0\n");
    printf("      ELEC2645 Unit 2 Project\n");
    printf("========================================\n");
    
    while (1) {
        printf("\n=== Main Menu ===\n");
        printf("1. Scientific Calculator\n");
        printf("2. Circuit Analysis\n");
        printf("3. Signal Generator\n");
        printf("4. User Guide\n");
        printf("5. Exit\n");
        
        int choice = get_int_input("Choose (1-5): ");
        
        switch (choice) {
            case 1:
                scientific_calculator();
                break;
            case 2:
                circuit_analysis();
                break;
            case 3:
                signal_generator();
                break;
            case 4:
                user_guide();
                break;
            case 5:
                printf("Thank you for using Engineering Calculator! Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                wait_for_enter();
        }
    }
    
    return 0;
}