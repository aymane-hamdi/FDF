#include <stdio.h>

typedef struct {
    int r;
    int g;
    int b;
} Color;

unsigned int color_to_int(Color color) {
    return (color.r << 16) | (color.g << 8) | color.b;
}

Color get_gradient(Color start, Color end, float ratio) {
    Color result;
    result.r = (int)(start.r + ratio * (end.r - start.r));
    result.g = (int)(start.g + ratio * (end.g - start.g));
    result.b = (int)(start.b + ratio * (end.b - start.b));
    return result;
}

int main() {
    Color red = {255, 0, 0};
    Color green = {0, 255, 0};
    Color blue = {0, 0, 255};

    float ratio = 0.5; // Halfway

    Color gradient1 = get_gradient(red, green, ratio);
    Color gradient2 = get_gradient(green, blue, ratio);

    printf("Gradient color 1: %u\n", color_to_int(gradient1));
    printf("Gradient color 2: %u\n", color_to_int(gradient2));

    return 0;
}