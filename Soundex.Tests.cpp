#include <gtest/gtest.h>
#include "Soundex.h"

/*
TEST CASE 01
Scenario: Single letter input should return the letter followed by three zeros.
Desired Output: The result should contain the letter in uppercase followed by 3 zeros.
*/
TEST(SoundexTestsuite, ReplacesSingleCharacterInputWithitsUpperCaseLetterandZeroPadding)
{
    char soundex[5];
    const char *answer1 = "F000";
    const char *answer2 = "A000";
    const char *answer3 = "F000";
    ASSERT_STREQ(answer1,generateSoundex("F", soundex));
    ASSERT_STREQ(answer2,generateSoundex("a", soundex));
    ASSERT_STREQ(answer3,generateSoundex("f", soundex));
}

/*
TEST CASE 02
Scenario: When input contains two same consonant letters, only the first one should be encoded.
Desired Output: The result should encode only the first letter's Soundex code, followed by zeros.
*/
TEST(SoundexTestsuite, ForSameConsonantsRetainFirstLetterandEncodeOnce)
{
    char soundex[5];
    const char *answer1 = "B100";
    const char *answer2 = "C200";
    const char *answer3 = "G200";
    ASSERT_STREQ(answer1,generateSoundex("bb", soundex));
    ASSERT_STREQ(answer2,generateSoundex("CC", soundex));
    ASSERT_STREQ(answer3,generateSoundex("gg", soundex));
}

/*
TEST CASE 03
*Scenario:* Input contains mixed case letters and should be case insensitive.
*Desired Output:* The result should be case insensitive, and the first letter should be in uppercase.
*/
TEST(SoundexTestsuite, MixedLettersRetainFistLetterinUpperCaseandRestisCaseInsensitive)
{
    char soundex[5];
    const char *answer = "A123";
    ASSERT_STREQ(answer,generateSoundex("AbCd", soundex));
    ASSERT_STREQ(answer,generateSoundex("aBcD", soundex));
}

/*
TEST CASE 04
*Scenario:* Vowel-only input should result in the first vowel followed by three zeros.
*Desired Output:* The result should contain the first letter (vowel) in uppercase followed by 3 zeros.
*/
TEST(SoundexTestsuite, VowelsOnlyInputRetainsFirstLetterFollowedbyZeroPadding)
{
    char soundex[5];
    const char *answer = "A000";
    ASSERT_STREQ(answer,generateSoundex("AEIOU", soundex));
    ASSERT_STREQ(answer,generateSoundex("aeiou", soundex));
}

/*
TEST CASE 05
*Scenario:* Letters with the same Soundex code should not be repeated in the result.
*Desired Output:* Only the first occurrence of the letter or letters with the same Soundex code should be encoded.
*/
TEST(SoundexTestsuite, OnlyFirstOccurenceofLetterofSameSoundexCodetobeEncoded)
{
    char soundex[5];
    const char *answer1 = "B100";
    const char *answer2 = "C200";
    const char *answer3 = "D300";
    ASSERT_STREQ(answer1,generateSoundex("BP", soundex));
    ASSERT_STREQ(answer2,generateSoundex("CK", soundex));
    ASSERT_STREQ(answer3,generateSoundex("dt", soundex));
}

/*
TEST CASE 06
*Scenario:* Consonants should be encoded, and vowels should be ignored after the first letter.
*Desired Output:* The consonants should be encoded according to the lookup table, and vowels should be ignored after the first letter.
*/
TEST(SoundexTestsuite, EncodeConsonantsandIgnoreVowelsExceptIfFirstLetter)
{
    char soundex[5];
    const char *answer1 = "A100";
    const char *answer2 = "E240";
    ASSERT_STREQ(answer1,generateSoundex("Abe", soundex));
    ASSERT_STREQ(answer2,generateSoundex("Eagle", soundex));

}

/*
TEST CASE 07
*Scenario:* Input longer than 4 characters should only return the first 4 Soundex codes.
*Desired Output:* Only the first 4 characters should be included in the output, ignoring the rest.
*/
TEST(SoundexTestsuite, ForLongInputEncodeOnlyFirstFourLetters)
{
    char soundex[5];
    const char *answer1 = "A425";
    const char *answer2 = "C623";
    ASSERT_STREQ(answer1,generateSoundex("Alexander", soundex));
    ASSERT_STREQ(answer2,generateSoundex("Christopher", soundex));

}

/*
TEST CASE 08
*Scenario:* Input with non-alphabetic characters should return only valid Soundex characters.
*Desired Output:* Non-alphabetic characters should be ignored, and only valid Soundex-encoded letters should be returned.
*/
TEST(SoundexTestsuite, ReturnEmptyStringforNoInput)
{
    char soundex[5];
    const char *answer = "";
    ASSERT_STREQ(answer,generateSoundex("", soundex));
}

/*
TEST CASE 09
*Scenario:* Input with non-alphabetic characters should return only valid Soundex characters.
*Desired Output:* Non-alphabetic characters should be ignored, and only valid Soundex-encoded letters should be returned.
*/
TEST(SoundexTestsuite, InputWithNonAlphabeticCharactersShouldbeIgnoredandEncodeOnlyValidSoundexCharacters)
{
    char soundex[5];
    const char *answer1 = "A120";
    const char *answer2 = "H400";
    ASSERT_STREQ(answer1,generateSoundex("A1B@C", soundex));
    ASSERT_STREQ(answer2,generateSoundex("H#E!L2O", soundex));
}

/*
TEST CASE 10
*Scenario:* Consecutive characters that map to the same Soundex code should be treated as one.
*Desired Output:* Repeated characters with the same Soundex code should be encoded only once.
*/
TEST(SoundexTestsuite, ConsecutiveCharactersWithSameSoundextobeEncodedOnce)
{
    char soundex[5];
    const char *answer1 = "B100";
    const char *answer2 = "C200";
    ASSERT_STREQ(answer1,generateSoundex("BFPV", soundex));
    ASSERT_STREQ(answer2,generateSoundex("ccgg", soundex));
}
