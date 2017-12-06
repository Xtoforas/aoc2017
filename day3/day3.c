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
#include <cmath>
#include <algorithm>

static bool debugPrintf = false;

#define PRINT(...) if (debugPrintf) printf(__VA_ARGS__);

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage:\n");
        printf("%s <portID>\n", argv[0]);
        return -1;
    }
    // Generate grid
    int portNumber = atoi(argv[1]);
    if (portNumber > 0) {
        --portNumber;
    }
    int lastDimensions = sqrt(portNumber);
    int lastCorner = pow(lastDimensions,2);
    int nextCorner = pow(lastDimensions+1,2);
    int bottomLeftCorner = lastCorner + lastDimensions;
    int topRightCorner = lastCorner - lastDimensions;
    if (lastCorner % 2) {
        std::swap(topRightCorner, bottomLeftCorner);
    }
    int ring = (nextCorner % 2) ? sqrt(lastCorner)/2 : sqrt(nextCorner)/2;
    int topLeftCorner = (lastDimensions % 2) ? nextCorner : lastCorner;
    int bottomRightCorner = (lastDimensions % 2) ? lastCorner : nextCorner;

    typedef enum RINGLENGTH {
        BOTTOM_L = 0,
        TOP_R = 1,
    } RINGLENGTH;

    printf("Ring %d LastDim %d\n", ring, lastDimensions);
    RINGLENGTH ringLength = (lastDimensions % 2) ? TOP_R : BOTTOM_L;

    int distanceToMid = 0;
    if (ringLength == BOTTOM_L) {
        if (portNumber > bottomLeftCorner) {
            // between BL and BR
            printf("a\n");
            distanceToMid = abs(portNumber - (bottomLeftCorner + (bottomRightCorner - bottomLeftCorner)/2));
        } else {
            // between BL and TL
            printf("b\n");
            distanceToMid = abs(portNumber - (topLeftCorner + (bottomLeftCorner - topLeftCorner)/2));
        }
    } else {
        if (portNumber > topRightCorner) {
            // between TR and TL
            printf("c\n");
            distanceToMid = abs(portNumber - (topRightCorner + (topLeftCorner - topRightCorner)/2));
        } else {
            // between TR and BR
            printf("d\n");
            distanceToMid = abs(portNumber - (bottomRightCorner + (topRightCorner - bottomRightCorner)/2));
        }
    }

    printf("TL %d TR %d BL %d BR %d, ring %d mid %d total steps %d\n",
        topLeftCorner, topRightCorner,
        bottomLeftCorner, bottomRightCorner, ring, distanceToMid, ring+distanceToMid);
}
