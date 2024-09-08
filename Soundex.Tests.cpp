#include <gtest/gtest.h>
#include "Soundex.h"

//tests for single character and for 'F' [CASE 1]
TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits_1)
{

    char soundex[5];
    const char *answer = "F000";
    generateSoundex("F", soundex);
    for(int i =0; i<5;i++)
    {
        ASSERT_EQ(answer[i],soundex[i]);
    }
}

//tests zero padding and soundex for 'X' [CASE 2]
TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits_2)
{
    char soundex[5];
    const char *answer = "A200";
    generateSoundex("AX", soundex);
    for(int i =0; i<5;i++)
    {
        ASSERT_EQ(answer[i],soundex[i]);
    }
}

//tests if the function drops occurances of vowels for 'D' [CASE 3]
TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits_3)
{
    char soundex[5];
    const char *answer = "D000";
    generateSoundex("DIOU", soundex);
    for(int i =0; i<5;i++)
    {
        ASSERT_EQ(answer[i],soundex[i]);
    }
}

//tests for when 2 adjacent letters encode to the same number 'M' and 'N' [CASE 4,5]
TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits_4)
{
    char soundex[5];
    const char *answer = "L500";
    generateSoundex("LMNO", soundex);
    for(int i =0; i<5;i++)
    {
        ASSERT_EQ(answer[i],soundex[i]);
    }
}

//tests for when 2 adjacent letters encode to the same number and is separated by a vowel
TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits_5)
{
    char soundex[5];
    const char *answer = "P141";
    generateSoundex("PAVLOV", soundex);
    for(int i =0; i<5;i++)
    {
        ASSERT_EQ(answer[i],soundex[i]);
    }
}

//tests for when 2 letters with the same no are separated by hw
TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits_6)
{
    char soundex[5];
    const char *answer = "H300";
    generateSoundex("HDTW", soundex);
    for(int i =0; i<5;i++)
    {
        ASSERT_EQ(answer[i],soundex[i]);
    }
}
