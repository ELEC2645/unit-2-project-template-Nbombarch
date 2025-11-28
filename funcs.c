#include "funcs.h"

// Utility functions
int get_int_input(const char* prompt) {
    char buffer[100];
    int value;
    
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Input error!\n");
            continue;
        }
        
        // Remove newline character
        buffer[strcspn(buffer, "\n")] = 0;
        
        if (sscanf(buffer, "%d", &value) == 1) {
            return value;
        }
        printf("Please enter a valid integer!\n");
    }
}

double get_double_input(const char* prompt) {
    char buffer[100];
    double value;
    
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Input error!\n");
            continue;
        }
        
        buffer[strcspn(buffer, "\n")] = 0;
        
        if (sscanf(buffer, "%lf", &value) == 1) {
            return value;
        }
        printf("Please enter a valid number!\n");
    }
}

void wait_for_enter(void) {
    printf("\nPress Enter to continue...");
    char buffer[10];
    fgets(buffer, sizeof(buffer), stdin);
}

// Scientific Calculator functions
double degrees_to_radians(double degrees) {
    return degrees * M_PI / 180.0;
}

double radians_to_degrees(double radians) {
    return radians * 180.0 / M_PI;
}

void basic_arithmetic(void) {
    printf("\n=== Basic Arithmetic ===\n");
    double num1 = get_double_input("Enter first number: ");
    double num2 = get_double_input("Enter second number: ");
    
    printf("\nSelect operation:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Power (^)\n");
    
    int choice = get_int_input("Choose (1-5): ");
    
    double result;
    char operation;
    
    switch (choice) {
        case 1:
            result = num1 + num2;
            operation = '+';
            break;
        case 2:
            result = num1 - num2;
            operation = '-';
            break;
        case 3:
            result = num1 * num2;
            operation = '*';
            break;
        case 4:
            if (num2 == 0) {
                printf("Error: Division by zero!\n");
                return;
            }
            result = num1 / num2;
            operation = '/';
            break;
        case 5:
            result = pow(num1, num2);
            operation = '^';
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }
    
    printf("\nResult: %.2lf %c %.2lf = %.4lf\n", num1, operation, num2, result);
}

void trigonometric_functions(void) {
    printf("\n=== Trigonometric Functions ===\n");
    printf("1. Sine (sin)\n");
    printf("2. Cosine (cos)\n");
    printf("3. Tangent (tan)\n");
    printf("4. Arcsine (asin)\n");
    printf("5. Arccosine (acos)\n");
    printf("6. Arctangent (atan)\n");
    
    int choice = get_int_input("Choose (1-6): ");
    
    if (choice < 1 || choice > 6) {
        printf("Invalid choice!\n");
        return;
    }
    
    double value = get_double_input("Enter value: ");
    double result;
    
    switch (choice) {
        case 1:
            result = sin(degrees_to_radians(value));
            printf("sin(%.2lf°) = %.4lf\n", value, result);
            break;
        case 2:
            result = cos(degrees_to_radians(value));
            printf("cos(%.2lf°) = %.4lf\n", value, result);
            break;
        case 3:
            result = tan(degrees_to_radians(value));
            printf("tan(%.2lf°) = %.4lf\n", value, result);
            break;
        case 4:
            if (value < -1.0 || value > 1.0) {
                printf("Error: Arcsine input must be between -1 and 1!\n");
                return;
            }
            result = asin(value) * 180.0 / M_PI;
            printf("asin(%.4lf) = %.2lf°\n", value, result);
            break;
        case 5:
            if (value < -1.0 || value > 1.0) {
                printf("Error: Arccosine input must be between -1 and 1!\n");
                return;
            }
            result = acos(value) * 180.0 / M_PI;
            printf("acos(%.4lf) = %.2lf°\n", value, result);
            break;
        case 6:
            result = atan(value) * 180.0 / M_PI;
            printf("atan(%.4lf) = %.2lf°\n", value, result);
            break;
    }
}

void logarithmic_functions(void) {
    printf("\n=== Logarithmic Functions ===\n");
    printf("1. Natural Logarithm (ln)\n");
    printf("2. Common Logarithm (log10)\n");
    printf("3. Exponential (e^x)\n");
    
    int choice = get_int_input("Choose (1-3): ");
    
    if (choice < 1 || choice > 3) {
        printf("Invalid choice!\n");
        return;
    }
    
    double value = get_double_input("Enter value: ");
    double result;
    
    switch (choice) {
        case 1:
            if (value <= 0) {
                printf("Error: Natural logarithm input must be greater than zero!\n");
                return;
            }
            result = log(value);
            printf("ln(%.4lf) = %.4lf\n", value, result);
            break;
        case 2:
            if (value <= 0) {
                printf("Error: Common logarithm input must be greater than zero!\n");
                return;
            }
            result = log10(value);
            printf("log10(%.4lf) = %.4lf\n", value, result);
            break;
        case 3:
            result = exp(value);
            printf("e^(%.4lf) = %.4lf\n", value, result);
            break;
    }
}

void unit_conversions(void) {
    printf("\n=== Unit Conversions ===\n");
    printf("1. Degrees to Radians\n");
    printf("2. Radians to Degrees\n");
    printf("3. Celsius to Fahrenheit\n");
    printf("4. Fahrenheit to Celsius\n");
    
    int choice = get_int_input("Choose (1-4): ");
    
    if (choice < 1 || choice > 4) {
        printf("Invalid choice!\n");
        return;
    }
    
    double value = get_double_input("Enter value: ");
    double result;
    
    switch (choice) {
        case 1:
            result = degrees_to_radians(value);
            printf("%.2lf° = %.4lf radians\n", value, result);
            break;
        case 2:
            result = radians_to_degrees(value);
            printf("%.2lf radians = %.2lf°\n", value, result);
            break;
        case 3:
            result = (value * 9.0 / 5.0) + 32.0;
            printf("%.2lf°C = %.2lf°F\n", value, result);
            break;
        case 4:
            result = (value - 32.0) * 5.0 / 9.0;
            printf("%.2lf°F = %.2lf°C\n", value, result);
            break;
    }
}

void scientific_calculator(void) {
    while (1) {
        printf("\n=== Scientific Calculator ===\n");
        printf("1. Basic Arithmetic\n");
        printf("2. Trigonometric Functions\n");
        printf("3. Logarithmic Functions\n");
        printf("4. Unit Conversions\n");
        printf("5. Back to Main Menu\n");
        
        int choice = get_int_input("Choose (1-5): ");
        
        switch (choice) {
            case 1:
                basic_arithmetic();
                wait_for_enter();
                break;
            case 2:
                trigonometric_functions();
                wait_for_enter();
                break;
            case 3:
                logarithmic_functions();
                wait_for_enter();
                break;
            case 4:
                unit_conversions();
                wait_for_enter();
                break;
            case 5:
                return;
            default:
                printf("Invalid choice!\n");
                wait_for_enter();
        }
    }
}

// Circuit Analysis functions
void series_resistance(void) {
    printf("\n=== Series Resistance Calculation ===\n");
    int n = get_int_input("Enter number of resistors: ");
    
    if (n <= 0) {
        printf("Error: Number of resistors must be greater than zero!\n");
        return;
    }
    
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        double r = get_double_input("Enter resistance value (ohms): ");
        if (r < 0) {
            printf("Error: Resistance cannot be negative!\n");
            return;
        }
        total += r;
    }
    
    printf("Total series resistance: %.2lf ohms\n", total);
}

void parallel_resistance(void) {
    printf("\n=== Parallel Resistance Calculation ===\n");
    int n = get_int_input("Enter number of resistors: ");
    
    if (n <= 0) {
        printf("Error: Number of resistors must be greater than zero!\n");
        return;
    }
    
    double total_conductance = 0.0;
    for (int i = 0; i < n; i++) {
        double r = get_double_input("Enter resistance value (ohms): ");
        if (r <= 0) {
            printf("Error: Resistance must be greater than zero!\n");
            return;
        }
        total_conductance += 1.0 / r;
    }
    
    double total_resistance = 1.0 / total_conductance;
    printf("Total parallel resistance: %.4lf ohms\n", total_resistance);
}

void rc_circuit_analysis(void) {
    printf("\n=== RC Circuit Analysis ===\n");
    double r = get_double_input("Enter resistance (ohms): ");
    double c = get_double_input("Enter capacitance (farads): ");
    double vin = get_double_input("Enter supply voltage (volts): ");
    double time = get_double_input("Enter time (seconds): ");
    
    if (r <= 0 || c <= 0 || time < 0) {
        printf("Error: Resistance and capacitance must be greater than zero, time cannot be negative!\n");
        return;
    }
    
    double tau = r * c;
    double vc = vin * (1.0 - exp(-time / tau));
    double ic = (vin / r) * exp(-time / tau);
    
    printf("\nAnalysis Results:\n");
    printf("Time constant (τ): %.4lf seconds\n", tau);
    printf("Capacitor voltage: %.4lf volts\n", vc);
    printf("Capacitor current: %.4lf amperes\n", ic);
}

void voltage_divider(void) {
    printf("\n=== Voltage Divider Calculation ===\n");
    double r1 = get_double_input("Enter R1 resistance (ohms): ");
    double r2 = get_double_input("Enter R2 resistance (ohms): ");
    double vin = get_double_input("Enter input voltage (volts): ");
    
    if (r1 <= 0 || r2 <= 0) {
        printf("Error: Resistance values must be greater than zero!\n");
        return;
    }
    
    double vout = vin * r2 / (r1 + r2);
    double current = vin / (r1 + r2);
    
    printf("Output voltage: %.4lf volts\n", vout);
    printf("Current: %.4lf amperes\n", current);
}

void circuit_analysis(void) {
    while (1) {
        printf("\n=== Circuit Analysis ===\n");
        printf("1. Series Resistance\n");
        printf("2. Parallel Resistance\n");
        printf("3. RC Circuit Analysis\n");
        printf("4. Voltage Divider\n");
        printf("5. Back to Main Menu\n");
        
        int choice = get_int_input("Choose (1-5): ");
        
        switch (choice) {
            case 1:
                series_resistance();
                wait_for_enter();
                break;
            case 2:
                parallel_resistance();
                wait_for_enter();
                break;
            case 3:
                rc_circuit_analysis();
                wait_for_enter();
                break;
            case 4:
                voltage_divider();
                wait_for_enter();
                break;
            case 5:
                return;
            default:
                printf("Invalid choice!\n");
                wait_for_enter();
        }
    }
}

// Signal Generator functions
int save_signal_data(double* data, int points, double time_step, const char* filename) {
    char full_filename[100];
    snprintf(full_filename, sizeof(full_filename), "%s.csv", filename);
    
    FILE* file = fopen(full_filename, "w");
    if (!file) {
        printf("Error: Cannot create file!\n");
        return 0;
    }
    
    fprintf(file, "Time,Amplitude\n");
    for (int i = 0; i < points; i++) {
        fprintf(file, "%.6lf,%.6lf\n", i * time_step, data[i]);
    }
    
    fclose(file);
    printf("Data saved to %s\n", full_filename);
    return 1;
}

void generate_sine_wave(void) {
    printf("\n=== Sine Wave Generator ===\n");
    double amplitude = get_double_input("Enter amplitude: ");
    double frequency = get_double_input("Enter frequency (Hz): ");
    double duration = get_double_input("Enter duration (seconds): ");
    double time_step = get_double_input("Enter time step (seconds): ");
    
    if (amplitude <= 0 || frequency <= 0 || duration <= 0 || time_step <= 0) {
        printf("Error: All parameters must be greater than zero!\n");
        return;
    }
    
    int points = (int)(duration / time_step);
    if (points <= 0) {
        printf("Error: Cannot generate data points!\n");
        return;
    }
    
    if (points > 100000) {
        printf("Warning: Will generate %d data points, this may require significant memory!\n", points);
        printf("Continue? (y/n): ");
        char response[10];
        fgets(response, sizeof(response), stdin);
        if (response[0] != 'y' && response[0] != 'Y') {
            return;
        }
    }
    
    double* data = malloc(points * sizeof(double));
    if (!data) {
        printf("Error: Memory allocation failed!\n");
        return;
    }
    
    printf("\nGenerating sine wave...\n");
    printf("First 5 data points:\n");
    for (int i = 0; i < points && i < 5; i++) {
        double t = i * time_step;
        data[i] = amplitude * sin(2.0 * M_PI * frequency * t);
        printf("t=%.4lfs, y=%.4lf\n", t, data[i]);
    }
    if (points > 5) {
        printf("... (%d more data points)\n", points - 5);
    }
    
    printf("Save to file? (y/n): ");
    char response[10];
    fgets(response, sizeof(response), stdin);
    if (response[0] == 'y' || response[0] == 'Y') {
        char filename[50];
        printf("Enter filename (without extension): ");
        fgets(filename, sizeof(filename), stdin);
        filename[strcspn(filename, "\n")] = 0;
        
        if (strlen(filename) == 0) {
            strcpy(filename, "sine_wave");
        }
        
        if (save_signal_data(data, points, time_step, filename)) {
            printf("Save successful!\n");
        }
    }
    
    free(data);
}

void generate_square_wave(void) {
    printf("\n=== Square Wave Generator ===\n");
    double amplitude = get_double_input("Enter amplitude: ");
    double frequency = get_double_input("Enter frequency (Hz): ");
    double duration = get_double_input("Enter duration (seconds): ");
    double time_step = get_double_input("Enter time step (seconds): ");
    
    if (amplitude <= 0 || frequency <= 0 || duration <= 0 || time_step <= 0) {
        printf("Error: All parameters must be greater than zero!\n");
        return;
    }
    
    int points = (int)(duration / time_step);
    if (points <= 0) {
        printf("Error: Cannot generate data points!\n");
        return;
    }
    
    double* data = malloc(points * sizeof(double));
    if (!data) {
        printf("Error: Memory allocation failed!\n");
        return;
    }
    
    double period = 1.0 / frequency;
    printf("\nGenerating square wave...\n");
    printf("First 5 data points:\n");
    for (int i = 0; i < points && i < 5; i++) {
        double t = i * time_step;
        double phase = fmod(t, period) / period;
        data[i] = (phase < 0.5) ? amplitude : -amplitude;
        printf("t=%.4lfs, y=%.4lf\n", t, data[i]);
    }
    if (points > 5) {
        printf("... (%d more data points)\n", points - 5);
    }
    
    printf("Save to file? (y/n): ");
    char response[10];
    fgets(response, sizeof(response), stdin);
    if (response[0] == 'y' || response[0] == 'Y') {
        char filename[50];
        printf("Enter filename (without extension): ");
        fgets(filename, sizeof(filename), stdin);
        filename[strcspn(filename, "\n")] = 0;
        
        if (strlen(filename) == 0) {
            strcpy(filename, "square_wave");
        }
        
        if (save_signal_data(data, points, time_step, filename)) {
            printf("Save successful!\n");
        }
    }
    
    free(data);
}

void generate_triangle_wave(void) {
    printf("\n=== Triangle Wave Generator ===\n");
    double amplitude = get_double_input("Enter amplitude: ");
    double frequency = get_double_input("Enter frequency (Hz): ");
    double duration = get_double_input("Enter duration (seconds): ");
    double time_step = get_double_input("Enter time step (seconds): ");
    
    if (amplitude <= 0 || frequency <= 0 || duration <= 0 || time_step <= 0) {
        printf("Error: All parameters must be greater than zero!\n");
        return;
    }
    
    int points = (int)(duration / time_step);
    if (points <= 0) {
        printf("Error: Cannot generate data points!\n");
        return;
    }
    
    double* data = malloc(points * sizeof(double));
    if (!data) {
        printf("Error: Memory allocation failed!\n");
        return;
    }
    
    double period = 1.0 / frequency;
    printf("\nGenerating triangle wave...\n");
    printf("First 5 data points:\n");
    for (int i = 0; i < points && i < 5; i++) {
        double t = i * time_step;
        double phase = fmod(t, period) / period;
        if (phase < 0.5) {
            data[i] = 4.0 * amplitude * phase - amplitude;
        } else {
            data[i] = -4.0 * amplitude * phase + 3.0 * amplitude;
        }
        printf("t=%.4lfs, y=%.4lf\n", t, data[i]);
    }
    if (points > 5) {
        printf("... (%d more data points)\n", points - 5);
    }
    
    printf("Save to file? (y/n): ");
    char response[10];
    fgets(response, sizeof(response), stdin);
    if (response[0] == 'y' || response[0] == 'Y') {
        char filename[50];
        printf("Enter filename (without extension): ");
        fgets(filename, sizeof(filename), stdin);
        filename[strcspn(filename, "\n")] = 0;
        
        if (strlen(filename) == 0) {
            strcpy(filename, "triangle_wave");
        }
        
        if (save_signal_data(data, points, time_step, filename)) {
            printf("Save successful!\n");
        }
    }
    
    free(data);
}

void signal_generator(void) {
    while (1) {
        printf("\n=== Signal Generator ===\n");
        printf("1. Sine Wave\n");
        printf("2. Square Wave\n");
        printf("3. Triangle Wave\n");
        printf("4. Back to Main Menu\n");
        
        int choice = get_int_input("Choose (1-4): ");
        
        switch (choice) {
            case 1:
                generate_sine_wave();
                wait_for_enter();
                break;
            case 2:
                generate_square_wave();
                wait_for_enter();
                break;
            case 3:
                generate_triangle_wave();
                wait_for_enter();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice!\n");
                wait_for_enter();
        }
    }
}

// User Guide
void user_guide(void) {
    printf("\n=== Engineering Calculator User Guide ===\n\n");
    
    printf("1. Scientific Calculator\n");
    printf("   - Basic Arithmetic: Supports addition, subtraction, multiplication, division, and power operations\n");
    printf("   - Trigonometric Functions: Supports sin, cos, tan and their inverse functions\n");
    printf("   - Logarithmic Functions: Natural logarithm, common logarithm, and exponential functions\n");
    printf("   - Unit Conversions: Angle conversions and temperature conversions\n\n");
    
    printf("2. Circuit Analysis\n");
    printf("   - Series Resistance: Calculate total resistance of multiple series resistors\n");
    printf("   - Parallel Resistance: Calculate total resistance of multiple parallel resistors\n");
    printf("   - RC Circuit Analysis: Analyze transient response of RC circuits\n");
    printf("   - Voltage Divider: Calculate output voltage of voltage divider circuits\n\n");
    
    printf("3. Signal Generator\n");
    printf("   - Sine Wave Generation: Adjustable amplitude and frequency\n");
    printf("   - Square Wave Generation: Generate standard square wave signals\n");
    printf("   - Triangle Wave Generation: Generate linear triangle waves\n");
    printf("   - Data Export: Save generated data as CSV files for analysis in other software\n\n");
    
    printf("Usage Instructions:\n");
    printf("- All inputs require pressing Enter to confirm\n");
    printf("- Select corresponding numbers in menus for operations\n");
    printf("- Press Enter to return to previous menu\n");
    printf("- Signal data can be exported in CSV format for analysis in other software\n");
    
    wait_for_enter();
}