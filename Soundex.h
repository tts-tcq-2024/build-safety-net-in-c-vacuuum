#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

typedef struct
{
    char ch;
    char value;
} Lookup;

char getSoundexCode(char c)
{
    Lookup lookupTable[] =
    {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'},
        {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };

    int tableSize = sizeof(lookupTable) / sizeof(lookupTable[0]);

    c = toupper(c);

    for (int i = 0; i < tableSize; i++)
    {
        if (lookupTable[i].ch == c)
        {
            return lookupTable[i].value;
        }
    }

    return '0';
}

char* generateSoundex(const char *name, char *soundex) 
{
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    char prevCode = '0';

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);

        if (code != '0' && code != prevCode) {
            soundex[sIndex++] = code;
            prevCode = code;
        }
    }

    // Fill the remaining places with '0'
    memset(soundex + sIndex, '0', 4 - sIndex);

    soundex[4] = '\0';
    return soundex;
}

#endif // SOUNDEX_H
