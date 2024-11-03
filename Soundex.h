#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

typedef struct
{
    char character;
    char value;
} soundexLookup;

// Function to search in the lookup table and return the corresponding Soundex value
char searchSoundexLookupTable(soundexLookup *lookupTable, int tableSize, char letter)
{
    for (int index = 0; index < tableSize; index++)
    {
        if (lookupTable[index].character == letter)
        {
            return lookupTable[index].value;
        }
    }
    return '0';  // Return '0' if the character is not found in the lookup table
}

// Function to get the Soundex code for a character
char getSoundexCode(char letter)
{
    letter = toupper(letter);  // Convert the character to uppercase
    soundexLookup lookupTable[18] =
    {
        {'B','1'}, {'F', '1'}, {'P','1'}, {'V','1'},
        {'C','2'}, {'G','2'}, {'J','2'}, {'K','2'}, {'Q','2'},
        {'S','2'}, {'X','2'}, {'Z','2'},
        {'D','3'}, {'T','3'},
        {'L','4'},
        {'M','5'}, {'N','5'},
        {'R','6'}
    };
    int tableSize = sizeof(lookupTable) / sizeof(lookupTable[0]);
    return searchSoundexLookupTable(lookupTable, tableSize, letter);
}

// Function to check if the Soundex code should be added to the result
int addSoundexCodetoResult(char code, char previousCode)
{
    return (code != '0' && code != previousCode);
}

// Function to check the iteration size for the loop in `generateSoundex`
int checkIterationSize(int index, int length, int soundexIndex)
{
    return (index < length && soundexIndex < 4);
}

char* generateSoundex(const char *name, char *soundex) 
{
    int length = strlen(name);
    soundex[0] = toupper(name[0]);
    int soundexIndex = 1;
    char previousCode = '0';
    for (int index = 1; checkIterationSize(index, length, soundexIndex); index++) 
    {
        char code = getSoundexCode(name[index]);
        // If the Soundex code is valid and not the same as the previous code, add it to result
        if (addSoundexCodetoResult(code, previousCode))
        {
            soundex[soundexIndex++] = code;
            previousCode = code;  // Update the previous code
        }
    }
    // Fill the remaining places with '0'
    memset(soundex + soundexIndex, '0', 4 - soundexIndex);
    soundex[4] = '\0';  // Ensure the Soundex code is null-terminated
    return soundex;
}

#endif // SOUNDEX_H
