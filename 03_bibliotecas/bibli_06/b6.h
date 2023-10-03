#ifndef _B6_H
#define _B6_H

float convert_celsius_to_kelvin(float temperature);
float convert_celsius_to_fahrenheit(float temperature);
float convert_kelvin_to_celsius(float temperature);
float convert_kelvin_to_fahrenheit(float temperature);
float convert_fahrenheit_to_celsius(float temperature);
float convert_fahrenheit_to_kelvin(float temperature);
float convert_temperature(float temperature, float convert_func(float temperature));

#endif