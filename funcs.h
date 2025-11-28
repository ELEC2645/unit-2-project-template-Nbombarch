#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Utility functions
int get_int_input(const char* prompt);
double get_double_input(const char* prompt);
void wait_for_enter(void);

// Scientific Calculator functions
double degrees_to_radians(double degrees);
double radians_to_degrees(double radians);
void basic_arithmetic(void);
void trigonometric_functions(void);
void logarithmic_functions(void);
void unit_conversions(void);
void scientific_calculator(void);

// Circuit Analysis functions
void series_resistance(void);
void parallel_resistance(void);
void rc_circuit_analysis(void);
void voltage_divider(void);
void circuit_analysis(void);

// Signal Generator functions
int save_signal_data(double* data, int points, double time_step, const char* filename);
void generate_sine_wave(void);
void generate_square_wave(void);
void generate_triangle_wave(void);
void signal_generator(void);

// User Guide
void user_guide(void);

#endif