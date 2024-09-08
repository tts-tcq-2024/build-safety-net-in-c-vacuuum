#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits_1)
{
    //tests for zero padding and soundex for 'X' [CASE 2]
    char soundex[5];
    const char *answer = "A200";
    generateSoundex("AX", soundex);
    for(int i =0; i<5;i++)
    {
        ASSERT_EQ(answer[i],soundex[i]);
    }
}
