/*******************************************************************************
 * Day 2
 * The spreadsheet consists of rows of apparently-random numbers. To make sure
 * the recovery process is on the right track, they need you to calculate the
 * spreadsheet's checksum. For each row, determine the difference between the
 * largest value and the smallest value; the checksum is the sum of all of
 * these differences.
 *
 ******************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

static bool debugPrintf = false;

#define PRINT(...) if (debugPrintf) printf(__VA_ARGS__);

static int testInput[3][4] = {
    {5, 1, 9, 5},
    {7, 5, 3, 3},
    {2, 4, 6, 8}
};

static int testInput2[16][16] = {
{278, 1689, 250, 1512, 1792, 1974, 175, 1639, 235, 1635, 1690, 1947, 810, 224, 928, 859},
{160, 50, 55, 81, 68, 130, 145, 21, 211, 136, 119, 78, 174, 155, 149, 72},
{4284, 185, 4499, 273, 4750, 4620, 4779, 4669, 2333, 231, 416, 1603, 197, 922, 5149, 2993},
{120, 124, 104, 1015, 1467, 110, 299, 320, 1516, 137, 1473, 132, 1229, 1329, 1430, 392},
{257, 234, 3409, 2914, 2993, 3291, 368, 284, 259, 3445, 245, 1400, 3276, 339, 2207, 233},
{1259, 78, 811, 99, 2295, 1628, 3264, 2616, 116, 3069, 2622, 1696, 1457, 1532, 268, 82},
{868, 619, 139, 522, 168, 872, 176, 160, 1010, 200, 974, 1008, 1139, 552, 510, 1083},
{1982, 224, 3003, 234, 212, 1293, 1453, 3359, 326, 3627, 3276, 3347, 1438, 2910, 248, 2512},
{4964, 527, 5108, 4742, 4282, 4561, 4070, 3540, 196, 228, 3639, 4848, 152, 1174, 5005, 202},
{1381, 1480, 116, 435, 980, 1022, 155, 1452, 1372, 121, 128, 869, 1043, 826, 1398, 137},
{2067, 2153, 622, 1479, 2405, 1134, 2160, 1057, 819, 99, 106, 1628, 1538, 108, 112, 1732},
{4535, 2729, 4960, 241, 4372, 3960, 248, 267, 230, 5083, 827, 1843, 3488, 4762, 2294, 3932},
{3245, 190, 2249, 2812, 2620, 2743, 2209, 465, 139, 2757, 203, 2832, 2454, 177, 2799, 2278},
{1308, 797, 498, 791, 1312, 99, 1402, 1332, 521, 1354, 1339, 101, 367, 1333, 111, 92},
{149, 4140, 112, 3748, 148, 815, 4261, 138, 1422, 2670, 32, 334, 2029, 4750, 4472, 2010},
{114, 605, 94, 136, 96, 167, 553, 395, 164, 159, 284, 104, 530, 551, 544, 18}
};

static int testInput3[3][4] = {
{5,9,2,8},
{9,4,7,3},
{3,8,6,5}
};

int star1(std::vector<int> v) {
    int max = *std::max_element(v.begin(), v.end());
    int min = *std::min_element(v.begin(), v.end());
    return (max-min);
}

int star2(std::vector<int> v) {
    int total = 0;
    std::sort(v.begin(), v.end());
    for (std::vector<int>::iterator lowest = v.begin(); lowest != std::prev(v.end()); ++lowest) {
        for (std::vector<int>::iterator runner = std::next(lowest); runner != v.end(); ++runner) {
            if ((*runner % *lowest) == 0) {
                PRINT("%d/%d\n", *runner, *lowest);
                total += (*runner/(*lowest));
            }
        }
    }
    return total;
}

    /*
    int rows = sizeof(testInput3)/sizeof(testInput3[0]);
    int cols = sizeof(testInput3[0])/sizeof(int);
    printf("%d rows, %d cols\n", rows, cols);
    int total = 0;
    for (int rowIndex = 0; rowIndex < rows; ++rowIndex) {
        std::vector<int> v(testInput3[rowIndex], testInput3[rowIndex] + cols);
        std::sort(v.begin(), v.end());
        printf("Row %d\n", rowIndex);
        for (std::vector<int>::iterator lowest = v.begin(); lowest != std::prev(v.end()); ++lowest) {
            for (std::vector<int>::iterator runner = std::next(lowest); runner != v.end(); ++runner) {
                if ((*runner % *lowest) == 0) {
                    printf("%d/%d\n", *runner, *lowest);
                    total += (*runner/(*lowest));
                }
            }
        }
        //int max = *std::max_element(testInput3[rowIndex], testInput3[rowIndex]+cols);
        //int min = *std::min_element(testInput3[rowIndex], testInput3[rowIndex]+cols);
        //total += (max-min);
    }
    printf("Checksum %d\n", total);
    */
int main(int argc, char** argv) {
    int rows = sizeof(testInput2)/sizeof(testInput2[0]);
    int cols = sizeof(testInput2[0])/sizeof(int);
    printf("%d rows, %d cols\n", rows, cols);
    int total_star1 = 0;
    int total_star2 = 0;
    for (int rowIndex = 0; rowIndex < rows; ++rowIndex) {
        std::vector<int> v(testInput2[rowIndex], testInput2[rowIndex] + cols);
        total_star1 += star1(v);
        total_star2 += star2(v);
    }

    printf("Checksum star1 %d star2 %d\n", total_star1, total_star2);
    return 0;
}
