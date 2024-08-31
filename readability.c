#include "cs50.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    float L = ((float)letters / words) * 100;
    float S = ((float)sentences / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Print the grade level
    if (index >= 13)
    {
        printf("Grade 16+\n");
    }
    else if (index >= 7)
    {
        printf("Grade 10\n");
    }
    else if (index >= 6)
    {
        printf("Grade 7\n");
    }
    else if (index >= 5)
    {
        printf("Grade 9\n");
    }
    else if (index >= 3 && index < 5)
    {
        printf("Grade 8\n");
    }
    else if (index >= 2.4)
    {
        printf("Grade 5\n");
    }
    else if (index <= 2.39 && index >= -1)
    {
        printf("Grade 2\n");
    }
    else if (index < -1 && index > -9)
    {
        printf("Grade 3\n");
    }
    else if (index <= -9)
    {
        printf("Before Grade 1\n");
    }
}

int count_letters(string text)
{
    // Return the number of letters in text
    int num = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            num += 1;
        }
    }
    return num;
}

int count_words(string text)
{
    // Return the number of words in text
    int num = 1;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (isblank(text[i]))
        {
            num += 1;
        }
    }
    return num;
}

int count_sentences(string text)
{
    // Return the number of sentences in text
    int num = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (ispunct(text[i]))
        {
            num += 1;
        }
    }
    return num;
}
