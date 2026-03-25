#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} DATE;

int buffer() {
    int character = 0;
    while (getchar() != '\n') {
        character++;
    }
    return character;
}

int input( const char *text, int min, int max) {
    int number;
    int character;

    do {
        printf("Please enter your %s in between %d - %d:\n", text, min, max);
        scanf("%d", &number);

        character = buffer();

        if (character != 0) {
            printf("You entered the wrong input!\n");
        } else if (number < min || number > max) {
            printf("You entered the wrong input, the number has to be between the interval!\n");
        }
    } while (character != 0 || number < min || number > max);

    return number;
}

int main(void) {
    DATE date;
    int sex;

    printf("-- Birth number generator --\n");
    date.year = input( "year of birth", 1954, 2053);
    date.month = input( "month of birth", 1, 12);
    date.day = input( "day of birth", 1, 30);

    sex = input("sex: male = 0 - female = 1", 0, 1);

    if (sex) {
        date.month += 50;
    }

    printf("%d", date.month);

    return 0;
}
