#include <stdio.h>

float celsiusToFahrenheit(float c);
float fahrenheitToCelsius(float f);

int main() {
    float celsiusInput = 37.0f;
    float fahrenheitInput = 98.6f;

    float fahrenheitOutput = celsiusToFahrenheit(celsiusInput);
    float celsiusOutput = fahrenheitToCelsius(fahrenheitInput);

    printf("%.2f Celsius is %.2f Fahrenheit\n", celsiusInput, fahrenheitOutput);
    printf("%.2f Fahrenheit is %.2f Celsius\n", fahrenheitInput, celsiusOutput);

    return 0;
}

float celsiusToFahrenheit(float c) {
    return (c * 9.0f / 5.0f) + 32.0f;
}

float fahrenheitToCelsius(float f) {
    return (f - 32.0f) * 5.0f / 9.0f;
}
