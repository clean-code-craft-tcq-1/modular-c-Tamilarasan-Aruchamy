/* ************************** Includes ************************ */

#include <stdio.h>
#include <assert.h>
#include "Cable_ColorCoding_Cfg.h"

/* ************************** Macro definitions ************************ */

#define MAX_COLORPAIR_NAME_CHARS 12

/* ************************** External Functions ************************ */
extern void ColorPairToString(const ColorPair* colorPair, char* buffer);
extern int GetPairNumberFromColor(const ColorPair* colorPair);
extern ColorPair GetColorFromPairNumber(int pairNumber);
extern void PrintColorCodingManual();

/* ************************** Function definitions ************************ */

int main() {
    testNumberToPair(4, WHITE, BROWN); /* Function call to test the pair number matching with color coding pattern */
    testNumberToPair(5, WHITE, SLATE); /* Function call to test the pair number matching with color coding pattern */

    testPairToNumber(BLACK, ORANGE, 12); /* Function call to test the Color Coding pattern matching with pair number */
    testPairToNumber(VIOLET, SLATE, 25); /* Function call to test the Color Coding pattern matching with pair number */
    
    PrintColorCodingManual();  /* Function call to print the color coding user manual */
	
    return 0;
}

void testNumberToPair(int pairNumber,enum MajorColor expectedMajor,enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor); /*If expression is zero, the assert macro writes a message to stderr and terminates the program by calling abort. */
    assert(colorPair.minorColor == expectedMinor); /*If expression is zero, the assert macro writes a message to stderr and terminates the program by calling abort. */
}

void testPairToNumber(enum MajorColor major,enum MinorColor minor,int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumberFromColor(&colorPair);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber); /*If expression is zero, the assert macro writes a message to stderr and terminates the program by calling abort. */
}
