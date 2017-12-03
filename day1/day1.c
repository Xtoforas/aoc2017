/*******************************************************************************
 * Day 1
 * The captcha requires you to review a sequence of digits (your puzzle input)
 * and find the sum of all digits that match the next digit in the list. The
 * list is circular, so the digit after the last digit is the first digit in
 * the list.
 *
 ******************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <cstring>

static bool debugPrintf = false;

#define PRINT(...) if (debugPrintf) printf(__VA_ARGS__);

void usage(char** argv) {
    printf("%s: Invalid number of arguments\n", argv[0]);
    printf("%s <list of numbers>\n", argv[0]);
}

void partOne(int argc, char** argv) {
    size_t numChars = strlen(argv[1]);

    // To match with the last character
    int total = 0;
    int charIndex = 1;

    for (; charIndex < numChars; ++charIndex) {
        PRINT("Index %d Total %d Char %c Runner %c\n",
            charIndex, total, argv[1][charIndex], argv[1][charIndex-1]);

        if (argv[1][charIndex-1] == argv[1][charIndex]) {
            total += (argv[1][charIndex]-'0');
        }
    }

    if (argv[1][charIndex-1] == argv[1][0]) {
        PRINT("Adding last time Char %c First %c\n", argv[1][charIndex-1], argv[1][0]);
        total += (argv[1][0]-'0');
    }

    printf("Input was %s\n", argv[1]);
    printf("Sum is %d\n", total);
}

void partTwo(int argc, char** argv) {
    size_t numChars = strlen(argv[1]);
    int offset = (numChars / 2);

    // To match with the last character
    int total = 0;
    int charIndex = 1;

    printf("Offset is %d, numChars is %zu\n", offset, numChars);

    for (; charIndex < numChars; ++charIndex) {
        printf("%d - %d,%c %zu,%c\n",
            total,
            charIndex-1, argv[1][charIndex-1],
            ((charIndex-1+offset)%(numChars)),
            argv[1][(charIndex-1+offset)%(numChars)]);

        if (argv[1][charIndex-1] == argv[1][(charIndex-1+offset)%(numChars)]) {
            total += (argv[1][charIndex-1]-'0');
        }
    }

    if (argv[1][charIndex-1] == argv[1][(charIndex-1+offset)%(numChars)]) {
        printf("Adding last time Char %c First %c\n",
            argv[1][charIndex-1],
            argv[1][(charIndex-1+offset)%(numChars)]);
        total += (argv[1][charIndex-1]-'0');
    }

    printf("Input was %s\n", argv[1]);
    printf("Sum is %d\n", total);
}

void reverseCaptcha(int argc, char** argv, int offset) {
    size_t numChars = strlen(argv[1]);

    // To match with the last character
    int total = 0;
    int charIndex = 1;

    printf("Offset is %d, numChars is %zu\n", offset, numChars);

    for (; charIndex < numChars; ++charIndex) {
        printf("%d - %d,%c %zu,%c\n",
            total,
            charIndex-1, argv[1][charIndex-1],
            ((charIndex-1+offset)%(numChars)),
            argv[1][(charIndex-1+offset)%(numChars)]);

        if (argv[1][charIndex-1] == argv[1][(charIndex-1+offset)%(numChars)]) {
            total += (argv[1][charIndex-1]-'0');
        }
    }

    if (argv[1][charIndex-1] == argv[1][(charIndex-1+offset)%(numChars)]) {
        printf("Adding last time Char %c First %c\n",
            argv[1][charIndex-1],
            argv[1][(charIndex-1+offset)%(numChars)]);
        total += (argv[1][charIndex-1]-'0');
    }

    printf("Input was %s\n", argv[1]);
    printf("Sum is %d\n", total);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        usage(argv);
        exit(-1);
    }

    size_t numChars = strlen(argv[1]);
    if (numChars == 1 || (numChars % 2)) {
        usage(argv);
        exit(-1);
    }

    reverseCaptcha(argc, argv, 1);
    //partOne(argc, argv);
    //partTwo(argc, argv);
}
