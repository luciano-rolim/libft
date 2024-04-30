#include "libft.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <strings.h>
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

void test_ft_putstr_fd(void) 
{
    int all_tests_passed = 1;
    char s[150];  // Ensure the buffer is large enough for the test messages

    // Test 1: Normal usage with standard output
    strcpy(s, "...Testing output to standard output (fd 1): ");
    write(1, s, strlen(s));
    ft_putstr_fd("Hello, World!\n", 1);

    // Test 2: Normal usage with standard error
    strcpy(s, "...Testing output to standard error (fd 2): ");
    write(2, s, strlen(s));  // Correctly using fd 2 for writing to stderr
    ft_putstr_fd("Hello, Error World!\n", 2);

    // Test 3: Testing with NULL string
    strcpy(s, "Testing output of NULL string to standard output (fd 1): ");
    ft_putstr_fd(NULL, 1);

    if (all_tests_passed)
        printf("32 - ft_putstr_fd is OK\n");
}

void test_ft_putchar_fd(void) 
{
    int all_tests_passed = 1;
    char s[100];

    // Test 1: Output to a file descriptor representing standard output (typically 1)
    strcpy(s, "...Testing output 'A' to standard output (fd 1): ");
    write(1, s, strlen(s));
    ft_putchar_fd('A', 1);
    write(1, "\n", 1);

    // Test 2: Output to a file descriptor representing standard error (typically 2)
    strcpy(s, "...Testing output 'B' to standard error (fd 2): ");
    write(1, s, strlen(s));  // Should likely be write(2, s, strlen(s)) to write to stderr
    ft_putchar_fd('B', 2);
    write(1, "\n", 1);  // Again, for stderr use write(2, "\n", 1);

    if (all_tests_passed)
        printf("31 - ft_putchar_fd is OK\n");
}

// Transformation function 1: Uppercase conversion
char uppercase(unsigned int i, char c) {
    (void)i;  // Unused parameter
    return toupper(c);
}

// Transformation function 2: Lowercase conversion
char lowercase(unsigned int i, char c) {
    (void)i;
    return tolower(c);
}

// Transformation function 3: Toggle case
char toggle_case(unsigned int i, char c) {
    (void)i;
    if (islower(c))
        return toupper(c);
    else if (isupper(c))
        return tolower(c);
    else
        return (c);
    return c;
}

void add_index_to_char(unsigned int i, char *c) {
    *c += i;
}

// Transformation function 4: Shift char by its index (cyclic within 'a'-'z' and 'A'-'Z')
char shift_by_index(unsigned int i, char c) {
    if (islower(c))
        return 'a' + (c - 'a' + i) % 26;
    else if (isupper(c))
        return 'A' + (c - 'A' + i) % 26;
    return c;
}

// Transformation function 5: Replace every char with '*'
char replace_with_star(unsigned int i, char c) {
    (void)i; (void)c;
    return '*';
}

// Transformation function 6: Insert a marker ('-') every 3 characters, starting with 0
char marker_insertion(unsigned int i, char c) {
    if (i % 3 == 0) 
        return '-';
    return c;
}

void test_ft_strmapi(void) {
    char *str = "Hello World!";
    char *result;
    int all_tests_passed = 1;

    // Using uppercase transformation
    result = ft_strmapi(str, uppercase);
    if (strcmp(result, "HELLO WORLD!") != 0) {
        printf("KO - ft_strmapi - Uppercase transformation failed. Expected 'HELLO WORLD!', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Using lowercase transformation
    result = ft_strmapi(str, lowercase);
    if (strcmp(result, "hello world!") != 0) {
        printf("KO - ft_strmapi - Lowercase transformation failed. Expected 'hello world!', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Using toggle case transformation
    result = ft_strmapi("HeLlO WoRlD!", toggle_case);
    if (strcmp(result, "hElLo wOrLd!") != 0) {
        printf("KO - ft_strmapi - Toggle case transformation failed. Expected 'hElLo wOrLd!', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Using shift by index transformation
    result = ft_strmapi("abcdefghijklmnopqrstuvwxyz", shift_by_index);
    if (strcmp(result, "acegikmoqsuwyacegikmoqsuwy") != 0) {
        printf("KO - ft_strmapi - Shift by index transformation failed. Expected 'ace', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Using replace with star transformation
    result = ft_strmapi("Hello World!", replace_with_star);
    if (strcmp(result, "************") != 0) {
        printf("KO - ft_strmapi - Replace with star transformation failed. Expected '************', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case: Marker Insertion every 3 characters
    result = ft_strmapi("abcdef", marker_insertion);
    if (strcmp(result, "-bc-ef") != 0) {
        printf("KO - ft_strmapi - Marker insertion transformation failed. Expected 'ab-cd-ef', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    if (all_tests_passed)
        printf("29 - ft_strmapi is OK\n");

}

void test_ft_itoa(void)
{
    char *result;
    int all_tests_passed = 1;

    // Test Case 1: Zero
    result = ft_itoa(0);
    if (strcmp(result, "0") != 0)
    {
        printf("KO - ft_itoa - '0' should return '0', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 2: Positive Number
    result = ft_itoa(12345);
    if (strcmp(result, "12345") != 0)
    {
        printf("KO - ft_itoa - '12345' should return '12345', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 3: Negative Number
    result = ft_itoa(-12345);
    if (strcmp(result, "-12345") != 0)
    {
        printf("KO - ft_itoa - '-12345' should return '-12345', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 4: INT_MAX
    result = ft_itoa(2147483647);
    if (strcmp(result, "2147483647") != 0)
    {
        printf("KO - ft_itoa - '2147483647' should return '2147483647', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 5: INT_MIN
    result = ft_itoa(-2147483648);
    if (strcmp(result, "-2147483648") != 0)
    {
        printf("KO - ft_itoa - '-2147483648' should return '-2147483648', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 6: Small Positive Number
    result = ft_itoa(1);
    if (strcmp(result, "1") != 0)
    {
        printf("KO - ft_itoa - '1' should return '1', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 7: Small Negative Number
    result = ft_itoa(-1);
    if (strcmp(result, "-1") != 0)
    {
        printf("KO - ft_itoa - '-1' should return '-1', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 8: Larger Numbers
    result = ft_itoa(100000);
    if (strcmp(result, "100000") != 0)
    {
        printf("KO - ft_itoa - '100000' should return '100000', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    if (all_tests_passed)
        printf("28 - ft_itoa is OK\n");

}

void free_split_result(char **result) 
{
    if (result != NULL) {
        int i = 0;
        while (result[i] != NULL) 
        {
            free(result[i]);
            i++;
        }
        free(result);
    }
}
void test_ft_split(void) {
    char **result;
    int all_tests_passed = 1;

    // Test Case 1: Normal scenario
    result = ft_split("Hello World", ' ');
    if (strcmp(result[0], "Hello") != 0 || strcmp(result[1], "World") != 0 || result[2] != NULL) {
        printf("KO - ft_split - Normal case failed. Expected ['Hello', 'World'], got ['%s', '%s']\n", result[0], result[1]);
        all_tests_passed = 0;
    }
    free_split_result(result);

    // Test Case 2: Multiple delimiters
    result = ft_split("Hello  World", ' ');
    if (strcmp(result[0], "Hello") != 0 || strcmp(result[1], "World") != 0 || result[2] != NULL) {
        printf("KO - ft_split - Multiple delimiters failed. Expected ['Hello', 'World'], got ['%s', '%s']\n", result[0], result[1]);
        all_tests_passed = 0;
    }
    free_split_result(result);

    // Test Case 3: Delimiters at the ends
    result = ft_split(" Hello World ", ' ');
    if (strcmp(result[0], "Hello") != 0 || strcmp(result[1], "World") != 0 || result[2] != NULL) {
        printf("KO - ft_split - Delimiters at the ends failed. Expected ['Hello', 'World'], got ['%s', '%s']\n", result[0], result[1]);
        all_tests_passed = 0;
    }
    free_split_result(result);

    // Test Case 4: NULL string
    result = ft_split(NULL, ' ');
    if (result != NULL) {
        printf("KO - ft_split - NULL string should return NULL, got non-NULL\n");
        all_tests_passed = 0;
    }

    // Test Case 5: Empty string
    result = ft_split("", ' ');
    if (result[0] != NULL) {
        printf("KO - ft_split - Empty string should return [''], got ['%s']\n", result[0]);
        all_tests_passed = 0;
    }
    free_split_result(result);

    // Test Case 6: String without delimiters
    result = ft_split("HelloWorld", ' ');
    if (strcmp(result[0], "HelloWorld") != 0 || result[1] != NULL) {
        printf("KO - ft_split - String without delimiters failed. Expected ['HelloWorld'], got ['%s']\n", result[0]);
        all_tests_passed = 0;
    }
    free_split_result(result);

    // Test Case 7: String with only delimiters
    result = ft_split("    ", ' ');
    if (result[0] != NULL) {
        printf("KO - ft_split - String with only delimiters should return [''], got non-NULL\n");
        all_tests_passed = 0;
    }
    free_split_result(result);

    // Test Case 8: Using a non-printable delimiter
    result = ft_split("Hello\eWorld\e", '\e');
    if (strcmp(result[0], "Hello") != 0 || strcmp(result[1], "World") != 0 || result[2] != NULL) {
        printf("KO - ft_split - Non-printable delimiter failed. Expected ['Hello', 'World'], got ['%s', '%s']\n", result[0], result[1]);
        all_tests_passed = 0;
    }
    free_split_result(result);

    // Test Case 9: Multiple consecutive spaces
    result = ft_split("          ", ' ');
    if (result[0] != NULL) {
        printf("KO - ft_split - Multiple consecutive spaces failed. Expected [], got ");
        all_tests_passed = 0;
    }
    free_split_result(result);

    // Test Case 10: Normal sentence
    result = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
    if (strcmp(result[0], "lorem") != 0 || strcmp(result[5], "consectetur") != 0 || result[12] != NULL) 
    {
        printf("KO - ft_split - Normal sentence divided by space failed.\n");
        all_tests_passed = 0;
    }
    free_split_result(result);

    // Test Case 11: Sentence with multiple spaces
    result = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
    if (strcmp(result[0], "lorem") != 0 || strcmp(result[5], "consectetur") != 0 || result[12] != NULL) {
        printf("KO - ft_split - Sentence with multiple spaces failed. Expected ['lorem', ..., 'Suspendisse'], got ");
        all_tests_passed = 0;
    }
    free_split_result(result);

    // Test Case 12: Long complex sentence with '0' as delimiter
    result = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", '0');
    if (strcmp(result[0], "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.") != 0 || result[1] != NULL) {
        printf("KO - ft_split - Long complex sentence with '0' failed. Expected ['lorem ipsum ... mi.'], got ");
        all_tests_passed = 0;
    }
    free_split_result(result);

    // Test Case 13: Long complex sentence with 'z' as delimiter
    result = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z');
    if (strcmp(result[0], "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.") != 0 || result[1] != NULL) {
        printf("KO - ft_split - Long complex sentence with 'z' failed. Expected ['lorem ipsum ... mi.'], got ");
        all_tests_passed = 0;
    }
    free_split_result(result);

    // Test Case 15: Empty string
    result = ft_split("", 'z');
    if (result[0] != NULL) {
        printf("KO - ft_split - Empty string should return [], got ");
        all_tests_passed = 0;
    }
    free_split_result(result);

    if (all_tests_passed)
        printf("27 - ft_split is OK\n");
}

void test_ft_strtrim(void)
{
    char *result;
    int all_tests_passed = 1;

    // Test Case 1: Normal scenario
    result = ft_strtrim("  Hello World  ", " ");
    if (strcmp(result, "Hello World") != 0)
    {
        printf("KO - ft_strtrim - Normal case failed. Expected 'Hello World', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 2: NULL s1
    result = ft_strtrim(NULL, "abc");
    if (result != NULL)
    {
        printf("KO - ft_strtrim - NULL s1 should return NULL, got non-NULL\n");
        all_tests_passed = 0;
    }

    // Test Case 3: NULL set
    result = ft_strtrim("Hello World", NULL);
    if (result != NULL)
    {
        printf("KO - ft_strtrim - NULL set should return NULL, got non-NULL\n");
        all_tests_passed = 0;
    }

    // Test Case 4: Both parameters NULL
    result = ft_strtrim(NULL, NULL);
    if (result != NULL)
    {
        printf("KO - ft_strtrim - Both NULL should return NULL, got non-NULL\n");
        all_tests_passed = 0;
    }

    // Test Case 5: Empty string
    result = ft_strtrim("", "abc");
    if (strcmp(result, "") != 0)
    {
        printf("KO - ft_strtrim - Empty string should return '', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 6: Set is empty
    result = ft_strtrim("Hello World", "");
    if (strcmp(result, "Hello World") != 0)
    {
        printf("KO - ft_strtrim - Empty set should return original string, got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 7: String matches set entirely
    result = ft_strtrim("xxxxx", "x");
    if (strcmp(result, "") != 0)
    {
        printf("KO - ft_strtrim - String matches set entirely should return '', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 8: Non-matching set
    result = ft_strtrim("Hello World", "xyz");
    if (strcmp(result, "Hello World") != 0)
    {
        printf("KO - ft_strtrim - Non-matching set should return original string, got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 9: String with only null characters
    char str_with_nulls[4] = {0};
    result = ft_strtrim(str_with_nulls, "abc");
    if (strcmp(result, "") != 0)
    {
        printf("KO - ft_strtrim - String with only nulls should return '', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 10: Trimming null characters (impossible scenario)
    char normal_str[] = "abc\0xyz";
    result = ft_strtrim(normal_str, "\0");
    if (strcmp(result, "abc") != 0)
    {
        printf("KO - ft_strtrim - Trimming null characters, expected 'abc', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    if (all_tests_passed)
        printf("26 - ft_strtrim is OK\n");
}

void test_ft_strjoin(void)
{
    char *result;
    int all_tests_passed = 1;

    // Test Case 1: Normal scenario
    result = ft_strjoin("Hello", "World");
    if (strcmp(result, "HelloWorld") != 0)
    {
        printf("KO - ft_strjoin - 'Hello' + 'World' should return 'HelloWorld', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 2: First string NULL
    result = ft_strjoin(NULL, "World");
    if (result != NULL)
    {
        printf("KO - ft_strjoin - NULL + 'World' should handle NULL properly, got '%s'\n", result);
        all_tests_passed = 0;
    }

    // Test Case 3: Second string NULL
    result = ft_strjoin("Hello", NULL);
    if (result != NULL)
    {
        printf("KO - ft_strjoin - 'Hello' + NULL should handle NULL properly, got '%s'\n", result);
        all_tests_passed = 0;
    }

    // Test Case 4: Both strings NULL
    result = ft_strjoin(NULL, NULL);
    if (result != NULL)
    {
        printf("KO - ft_strjoin - NULL + NULL should return NULL, got '%s'\n", result);
        all_tests_passed = 0;
    }

    // Test Case 5: Empty strings
    result = ft_strjoin("", "");
    if (strcmp(result, "") != 0)
    {
        printf("KO - ft_strjoin - '' + '' should return '', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 6: First string empty
    result = ft_strjoin("", "World");
    if (strcmp(result, "World") != 0)
    {
        printf("KO - ft_strjoin - '' + 'World' should return 'World', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 7: Second string empty
    result = ft_strjoin("Hello", "");
    if (strcmp(result, "Hello") != 0)
    {
        printf("KO - ft_strjoin - 'Hello' + '' should return 'Hello', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 8: Large strings
    char large1[1001];  // Create a large string of 1000 'a's
    char large2[1001];  // Create a large string of 1000 'b's
    memset(large1, 'a', 1000);
    memset(large2, 'b', 1000);
    large1[1000] = '\0';
    large2[1000] = '\0';

    result = ft_strjoin(large1, large2);
    char expected[2001];
    memset(expected, 'a', 1000);
    memset(expected + 1000, 'b', 1000);
    expected[2000] = '\0';

    if (strcmp(result, expected) != 0)
    {
        printf("KO - ft_strjoin - Large strings did not concatenate correctly.\n");
        all_tests_passed = 0;
    }
    free(result);

    if (all_tests_passed)
        printf("25 - ft_substr is OK\n");
}

void test_ft_substr(void)
{
    char const *test_string = "Hello, World!";
    char *result;
    int all_tests_passed = 1;

    // Test Case 1: Normal scenario
    result = ft_substr(test_string, 7, 5);
    if (strcmp(result, "World") != 0) 
    {
        printf("KO - ft_substr - Normal scenario failed. Expected 'World', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 2: Start index beyond string length
    result = ft_substr(test_string, 20, 5);
    if (strcmp(result, "") != 0) 
    {
        printf("KO - ft_substr - Start index beyond length. Expected '', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 3: Null string input
    result = ft_substr(NULL, 0, 5);
    if (result != NULL) 
    {
        printf("KO - ft_substr - Null string input. Expected NULL, got '%s'\n", result);
        all_tests_passed = 0;
    }

    // Test Case 4: Length zero
    result = ft_substr(test_string, 0, 0);
    if (strcmp(result, "") != 0) 
    {
        printf("KO - ft_substr - Length zero. Expected '', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 5: Start at zero, normal length
    result = ft_substr(test_string, 0, 5);
    if (strcmp(result, "Hello") != 0) 
    {
        printf("KO - ft_substr - Start at zero. Expected 'Hello', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 6: Large length request
    result = ft_substr(test_string, 0, 100);
    if (strcmp(result, "Hello, World!") != 0) 
    {
        printf("KO - ft_substr - Large length request. Expected 'Hello, World!', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 7: Start in the middle, request past end
    result = ft_substr(test_string, 5, 100);
    if (strcmp(result, ", World!") != 0) 
    {
        printf("KO - ft_substr - Start in the middle, request past end. Expected ', World!', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 8: Invalid high start with normal length
    result = ft_substr(test_string, 50, 5);
    if (strcmp(result, "") != 0) 
    {
        printf("KO - ft_substr - Invalid high start. Expected '', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    // Test Case 9: Start exactly at string length
    result = ft_substr(test_string, strlen(test_string), 5);
    if (strcmp(result, "") != 0) 
    {
        printf("KO - ft_substr - Start exactly at string length. Expected '', got '%s'\n", result);
        all_tests_passed = 0;
    }
    free(result);

    if (all_tests_passed)
        printf("24 - ft_substr is OK\n");

}

void test_ft_strdup(void)
{
    char *result1, *result2;
    int all_tests_passed = 1;

    // Test Case 1: Normal string
    result1 = ft_strdup("Hello, world!");
    result2 = strdup("Hello, world!");
    if ((result1 == NULL && result2 != NULL) || (result1 != NULL && result2 == NULL) || (result1 && strcmp(result1, result2) != 0))
    {
        printf("KO - ft_strdup - Normal string with error\n");
        all_tests_passed = 0;

    }
    free(result1);
    free(result2);

    // Test Case 2: Empty string
    result1 = ft_strdup("");
    result2 = strdup("");
    if ((result1 == NULL && result2 != NULL) || (result1 != NULL && result2 == NULL) || (result1 && strcmp(result1, result2) != 0))
    {
        printf("KO - ft_strdup - Empty string failed\n");
        all_tests_passed = 0;
    }
    free(result1);
    free(result2);

    // Test Case 3: String with only spaces
    result1 = ft_strdup("   ");
    result2 = strdup("   ");
    if ((result1 == NULL && result2 != NULL) || (result1 != NULL && result2 == NULL) || (result1 && strcmp(result1, result2) != 0))
    {
        printf("KO - ft_strdup - '   ' failed\n");
        all_tests_passed = 0;
    }
    free(result1);
    free(result2);

    // Test Case 4: String with escape characters
    result1 = ft_strdup("\n\t\v\f\r");
    result2 = strdup("\n\t\v\f\r");
    if ((result1 == NULL && result2 != NULL) || (result1 != NULL && result2 == NULL) || (result1 && strcmp(result1, result2) != 0))
    {
        printf("KO - ft_strdup - Escape characters failed\n");
        all_tests_passed = 0;
    }
    free(result1);
    free(result2);

    // Test Case 5: Numeric string
    result1 = ft_strdup("1234567890");
    result2 = strdup("1234567890");
    if ((result1 == NULL && result2 != NULL) || (result1 != NULL && result2 == NULL) || (result1 && strcmp(result1, result2) != 0))
    {
        printf("KO - ft_strdup - Numeric string failed\n");
        all_tests_passed = 0;
    }
    free(result1);
    free(result2);

    // Test Case 6: INT_MAX as string
    result1 = ft_strdup("2147483647");
    result2 = strdup("2147483647");
    if ((result1 == NULL && result2 != NULL) || (result1 != NULL && result2 == NULL) || (result1 && strcmp(result1, result2) != 0))
    {
        printf("KO - ft_strdup - INT_MAX string failed\n");
        all_tests_passed = 0;
    }
    free(result1);
    free(result2);

    // Test Case 7: INT_MIN as string
    result1 = ft_strdup("-2147483648");
    result2 = strdup("-2147483648");
    if ((result1 == NULL && result2 != NULL) || (result1 != NULL && result2 == NULL) || (result1 && strcmp(result1, result2) != 0))
    {
        printf("KO - ft_strdup - INT_MIN string failed\n");
        all_tests_passed = 0;
    }
    free(result1);
    free(result2);

    // Test Case 8: Long string
    result1 = ft_strdup("longstringlongstringlongstringlongstringlongstringlongstringlongstringlongstring");
    result2 = strdup("longstringlongstringlongstringlongstringlongstringlongstringlongstringlongstring");
    if ((result1 == NULL && result2 != NULL) || (result1 != NULL && result2 == NULL) || (result1 && strcmp(result1, result2) != 0))
    {
        printf("KO - ft_strdup - Long string failed\n");
        all_tests_passed = 0;
    }
    free(result1);
    free(result2);

    if (all_tests_passed)
        printf("23 - ft_strdup is OK\n");
}

void test_ft_atoi(void)
{
    char c_num[100] = "  -56^&*(7";
    char *ptr;
    int response;
    int all_tests_passed = 1;

    ptr = c_num;

    response = ft_atoi(ptr);
    if (response != atoi(ptr)) {
        printf("KO - ft_atoi - '  -56^&*(7' should return -56\n");
        all_tests_passed = 0; // Set to 0 if any test fails
    }

    ptr = "  --56^&*(7";
    response = ft_atoi(ptr);
    if (response != atoi(ptr)) {
        printf("KO - ft_atoi - '  --56^&*(7' should return 0\n");
        all_tests_passed = 0; // Set to 0 if any test fails
    }

    ptr = "67";
    response = ft_atoi(ptr);
    if (response != atoi(ptr)) {
        printf("KO - ft_atoi - '67' should return 67\n");
        all_tests_passed = 0; // Set to 0 if any test fails
    }

    ptr = "0";
    response = ft_atoi(ptr);
    if (response != atoi(ptr)) {
        printf("KO - ft_atoi - '0' should return 0\n");
        all_tests_passed = 0; // Set to 0 if any test fails
    }

    ptr = "-0";
    response = ft_atoi(ptr);
    if (response != atoi(ptr)) {
        printf("KO - ft_atoi - '-0' should return 0\n");
        all_tests_passed = 0; // Set to 0 if any test fails
    }

    ptr = "   --+++---1";
    response = ft_atoi(ptr);
    if (response != atoi(ptr)) {
        printf("KO - ft_atoi - '   --+++---1' should return 0\n");
        all_tests_passed = 0; // Set to 0 if any test fails
    }

    ptr = "   --+++-++20]67";
    response = ft_atoi(ptr);
    if (response != atoi(ptr)) {
        printf("KO - ft_atoi - '   --+++-++20]67' should return 0\n");
        all_tests_passed = 0; // Set to 0 if any test fails
    }

    ptr = "-2147483648";
    response = ft_atoi(ptr);
    if (response != atoi(ptr)) {
        printf("KO - ft_atoi - '-2147483648' should return -2147483648\n");
        all_tests_passed = 0; // Set to 0 if any test fails
    }

    ptr = "   2147483647";
    response = ft_atoi(ptr);
    if (response != atoi(ptr)) {
        printf("KO - ft_atoi - '   2147483647' should return 2147483647\n");
        all_tests_passed = 0; // Set to 0 if any test fails
    }

    ptr = "10";
    response = ft_atoi(ptr);
    if (response != atoi(ptr)) {
        printf("KO - ft_atoi - '10' should return 10\n");
        all_tests_passed = 0; // Set to 0 if any test fails
    }

    ptr = "   ^&* 1(0";
    response = ft_atoi(ptr);
    if (response != atoi(ptr)) {
        printf("KO - ft_atoi - '   ^&* 1(0' should return 0\n");
        all_tests_passed = 0; // Set to 0 if any test fails
    }

    ptr = "";
    response = ft_atoi(ptr);
    if (response != atoi(ptr)) {
        printf("KO - ft_atoi - '' should return 0\n");
        all_tests_passed = 0; // Set to 0 if any test fails
    }

    ptr = "\e475";
    response = ft_atoi(ptr);
    if (response != atoi(ptr)) {
        printf("KO - ft_atoi - '\e475' should return 0\n");
        all_tests_passed = 0; // Set to 0 if any test fails
    }

    if (all_tests_passed)
        printf("21 - ft_atoi is OK\n");
}

void test_ft_memcmp(void) 
{
    char s1[100];
    char s2[100];
    int result;
    int all_tests_passed = 1; 

    // Test: Identical blocks
    memset(s1, 'x', 100);
    memset(s2, 'x', 100);
    result = ft_memcmp(s1, s2, 100);
    if (result != 0) 
	{
        printf("KO - ft_memcmp - Identical blocks should return 0\n");
        all_tests_passed = 0;
    }

    // Test: First block is less
    memset(s1, 'a', 100);
    memset(s2, 'b', 100);
    result = ft_memcmp(s1, s2, 100);
    if (result >= 0) 
	{
        printf("KO - ft_memcmp - 'a' block should be less than 'b' block\n");
        all_tests_passed = 0;
    }

    // Test: Second block is less
    memset(s1, 'c', 100);
    memset(s2, 'b', 100);
    result = ft_memcmp(s1, s2, 100);
    if (result <= 0) 
	{
        printf("KO - ft_memcmp - 'c' block should be greater than 'b' block\n");
        all_tests_passed = 0;
    }

    // Test: Comparison with zero length
    result = ft_memcmp(s1, s2, 0);
    if (result != 0) 
	{
        printf("KO - ft_memcmp - Comparison with zero length should return 0\n");
        all_tests_passed = 0;
    }

    // Test: Blocks with null characters
    memset(s1, '\0', 100);
    memset(s2, '\0', 100);
    s1[50] = 'z';
    s2[50] = 'z';
    result = ft_memcmp(s1, s2, 100);
    if (result != 0) 
	{
        printf("KO - ft_memcmp - Blocks with null characters should be identical\n");
        all_tests_passed = 0;
    }

    // Test: Unsigned char
    memset(s1, 0x01, 100); // 0xFF is 1 both signed or unsigned
    memset(s2, 0xFF, 100); // 0xFF is -1 if signed, 255 if unsigned
    result = ft_memcmp(s1, s2, 100); //should return -254
	int result2 = memcmp(s1, s2, 100); //returns -254
    if (result != result2) 
	{
        printf("KO - ft_memcmp - Probably error with char overflow\n");
        all_tests_passed = 0;
    }

    // Test: Different characters at end of block
    memset(s1, 'y', 99);
    memset(s2, 'y', 99);
    s1[99] = 'z';
    s2[99] = 'x';
    result = ft_memcmp(s1, s2, 100);
    if (result <= 0) {
        printf("KO - ft_memcmp - Last characters differ, 'z' should be greater than 'x'\n");
        all_tests_passed = 0;
    }

    // Test: Non-ASCII characters
    memset(s1, 0xe3, 100);
    memset(s2, 0xe3, 100);
    s1[0] = 0x82; // Non-ASCII higher byte
    s2[0] = 0x81; // Non-ASCII lower byte
    result = ft_memcmp(s1, s2, 100);
    if (result <= 0) {
        printf("KO - ft_memcmp - Non-ASCII comparison should show first byte of s1 is higher\n");
        all_tests_passed = 0;
    }

    if (all_tests_passed == 1)
        printf("19 - ft_memcmp is OK\n");

}

void test_ft_memchr(void) 
{
    char arr[100];
    void *result1, *result2;
    int all_tests_passed = 1;

    // Test: Find a character in the middle
    memset(arr, 'a', sizeof(arr));
    arr[50] = 'b';
    result1 = ft_memchr(arr, 'b', 100);
    result2 = memchr(arr, 'b', 100);
    if (result1 != result2) 
	{
        printf("KO - ft_memchr - 'b' should be found in the middle\n");
        all_tests_passed = 0;
    }

    // Test: Character not present
    result1 = ft_memchr(arr, 'c', 100);
    result2 = memchr(arr, 'c', 100);
    if (result1 != result2) 
	{
        printf("KO - ft_memchr - 'c' should not be found\n");
        all_tests_passed = 0;
    }

    // Test: Search with zero length
    result1 = ft_memchr(arr, 'b', 0);
    result2 = memchr(arr, 'b', 0);
    if (result1 != result2) 
	{
        printf("KO - ft_memchr - No search should happen with zero length\n");
        all_tests_passed = 0;
    }

    // Test: Find the null character
    arr[20] = '\0';
    result1 = ft_memchr(arr, '\0', 100);
    result2 = memchr(arr, '\0', 100);
    if (result1 != result2) 
	{
        printf("KO - ft_memchr - Null character should be found\n");
        all_tests_passed = 0;
    }

    // Test: Unsigned char wraparound
    arr[10] = (char)0xFF; // Assuming char is signed and 0xFF is -1
    result1 = ft_memchr(arr, 0xFF, 100);
    result2 = memchr(arr, 0xFF, 100);
    if (result1 != result2) 
	{
        printf("KO - ft_memchr - Unsigned char 0xFF should be found\n");
        all_tests_passed = 0;
    }

    // Test: Search in non-ASCII data
    unsigned char non_ascii_data[] = {0xe3, 0x81, 0x82, 0xe3, 0x81, 0x84, 0x00};
    result1 = ft_memchr(non_ascii_data, 0x82, 7);
    result2 = memchr(non_ascii_data, 0x82, 7);
    if (result1 != result2) 
	{
        printf("KO - ft_memchr - Non-ASCII character 0x82 should be found\n");
        all_tests_passed = 0;
    }

    if (all_tests_passed == 1)
        printf("18 - ft_memchr is OK\n");

}

void test_ft_strncmp(void) 
{
    char s1[100];
    char s2[100];
    int value;
    int all_tests_passed = 1;

    // Test: Identical strings
    strcpy(s1, "Hello, world!");
    strcpy(s2, "Hello, world!");
    value = ft_strncmp(s1, s2, 13);
    if (value != strncmp(s1, s2, 13)) 
	{
        printf("KO - ft_strncmp - Identical strings should return 0\n");
        all_tests_passed = 0;
    }

    // Test: Comparison with zero length
    value = ft_strncmp(s1, s2, 0);
    if (value != strncmp(s1, s2, 0)) 
	{
        printf("KO - ft_strncmp - Comparison with zero length should return 0\n");
        all_tests_passed = 0;
    }

    // Test: Strings with null characters
    strcpy(s1, "Hel\0lo");
    strcpy(s2, "Hel\0lo123");
    value = ft_strncmp(s1, s2, 8);
    if (value != strncmp(s1, s2, 8)) 
	{
        printf("KO - ft_strncmp - Strings with null char in same position should return 0, as the original function\n");
        all_tests_passed = 0;
    }

    // Test: Unsigned char wraparound
    s1[0] = (char)0xFF; // 255 if unsigned, -1 if signed
    s2[0] = 0x01;       // 1
    value = ft_strncmp(s1, s2, 1);
    if (value != strncmp(s1, s2, 1)) 
	{
        printf("KO - ft_strncmp - Unsigned char wraparound should be handled correctly\n");
        all_tests_passed = 0;
    }

    // Test: Different characters
    strcpy(s1, "aaaaa");
    strcpy(s2, "aaaab");
    value = ft_strncmp(s1, s2, 5);
    if (value != strncmp(s1, s2, 5)) 
	{
        printf("KO - ft_strncmp - 'aaaaa' should be less than 'aaaab'\n");
        all_tests_passed = 0;
    }

    if (all_tests_passed == 1)
        printf("17 - ft_strncmp is OK\n");
}

void test_ft_strlcat(void)
{
    char dst[100];
    size_t result;
    int all_tests_passed = 1;

    // Test 1: Basic concatenation
    memset(dst, 0, 100);
    strcpy(dst, "Hello");
    result = ft_strlcat(dst, " World", 100);
    if (strcmp(dst, "Hello World") != 0 || result != 11)
    {
        printf("KO - ft_strlcat - Basic concatenation failed\n");
        all_tests_passed = 0;
    }

    // Test 2: Buffer exactly fits src
    memset(dst, 0, 100);
    strcpy(dst, "Hello");
    result = ft_strlcat(dst, " World", 6);
    if (strcmp(dst, "Hello") != 0 || result != 11)  // Only space for null terminator
    {
        printf("KO - ft_strlcat - Buffer exactly fits src failed\n");
        all_tests_passed = 0;
    }
    
    // Test 3: Buffer too small to do anything
    memset(dst, 0, 100);
    strcpy(dst, "Hello");
    result = ft_strlcat(dst, " World", 5);
    if (strcmp(dst, "Hello") != 0 || result != 11)
    {
        printf("KO - ft_strlcat - Buffer too small to do anything failed\n");
        all_tests_passed = 0;
    }

    // Test 4: Non-empty dst, large size
    memset(dst, 'A', 50);  // Pre-fill dst with 'A' to simulate non-empty uninitialized area
    dst[5] = '\0';         // Properly null-terminate dst
    result = ft_strlcat(dst, " Test", 100);
    if (strcmp(dst, "AAAAA Test") != 0 || result != 10)
    {
        printf("KO - ft_strlcat - Non-empty dst, large size failed\n");
        all_tests_passed = 0;
    }

    // Test 5: Appending an empty string
    memset(dst, 0, 100);
    strcpy(dst, "Hello");
    result = ft_strlcat(dst, "", 100);
    if (strcmp(dst, "Hello") != 0 || result != 5)
    {
        printf("KO - ft_strlcat - Appending an empty string failed\n");
        all_tests_passed = 0;
    }

    // Test 6: Buffer partially enough to copy "src" with a proper null terminator
    memset(dst, 0, 100);
    strcpy(dst, "Hello");
    result = ft_strlcat(dst, " World", 8);
    if (strcmp(dst, "Hello W") != 0 || result != 11)
    {
        printf("KO - ft_strlcat - Buffer partially enough to copy src with a proper null terminator failed\n");
        all_tests_passed = 0;
    }

    if (all_tests_passed)
        printf("16 - ft_strlcat is OK\n");
}

void test_ft_strrchr(void)
{
    const char *test_string = "Hello, world!";
    char *result;
    int all_tests_passed = 1;

    // Test finding 'w'
    result = ft_strrchr(test_string, 'w');
    if (result != strrchr(test_string, 'w'))
    {
        printf("KO - ft_strrchr - 'w' should be found\n");
        all_tests_passed = 0;
    }

    // Test finding 'l' (multiple occurrences)
    result = ft_strrchr(test_string, 'l');
    if (result != strrchr(test_string, 'l'))
    {
        printf("KO - ft_strrchr - 'l' should be found at the last occurrence\n");
        all_tests_passed = 0;
    }

    // Test finding 'H' (at the beginning)
    result = ft_strrchr(test_string, 'H');
    if (result != strrchr(test_string, 'H'))
    {
        printf("KO - ft_strrchr - 'H' should be found at the beginning\n");
        all_tests_passed = 0;
    }

    // Test finding '!' (at the end)
    result = ft_strrchr(test_string, '!');
    if (result != strrchr(test_string, '!'))
    {
        printf("KO - ft_strrchr - '!' should be found at the end\n");
        all_tests_passed = 0;
    }

    // Test finding a character not present
    result = ft_strrchr(test_string, 'x');
    if (result != strrchr(test_string, 'x'))
    {
        printf("KO - ft_strrchr - 'x' should not be found\n");
        all_tests_passed = 0;
    }

    // Test finding the null terminator '\0'
    result = ft_strrchr(test_string, '\0');
    if (result != strrchr(test_string, '\0'))
    {
        printf("KO - ft_strrchr - '\\0' should be found at the end\n");
        all_tests_passed = 0;
    }

    // Test with a character having an overflow condition
    result = ft_strrchr(test_string, 255 + 77);
    if (result != strrchr(test_string, 255 + 77))
    {
        printf("KO - ft_strrchr - '332' should have same overflow conditions\n");
        all_tests_passed = 0;
    }

    if (all_tests_passed)
        printf("12 - ft_strrchr is OK\n");
}

void test_ft_strchr(void)
{
    const char *test_string = "Hello, world!";
    char *result;
    // char *result2;
    int all_tests_passed = 1;

    result = ft_strchr(test_string, 'w');
    if (result != strchr(test_string, 'w'))
    {
        printf("KO - ft_strchr - 'w' should be found\n");
        all_tests_passed = 0;
    }

    result = ft_strchr(test_string, 'H');
    if (result != strchr(test_string, 'H'))
    {
        printf("KO - ft_strchr - 'H' should be found at the beginning\n");
        all_tests_passed = 0;
    }

    result = ft_strchr(test_string, '!');
    if (result != strchr(test_string, '!'))
    {
        printf("KO - ft_strchr - '!' should be found at the end\n");
        all_tests_passed = 0;
    }

    result = ft_strchr(test_string, 'x');
    if (result != strchr(test_string, 'x'))
    {
        printf("KO - ft_strchr - 'x' should not be found\n");
        all_tests_passed = 0;
    }

    result = ft_strchr(test_string, '\0');
    if (result != strchr(test_string, '\0'))
    {
        printf("KO - ft_strchr - '\\0' should be found at the end\n");
        all_tests_passed = 0;
    }

    result = ft_strchr(test_string, 255 + 77);
    if (result != strchr(test_string, 255 + 77))
    {
        printf("KO - ft_strchr - '332' should have same overflow conditions\n");
        all_tests_passed = 0;
    }

    if (all_tests_passed)
        printf("11 - ft_strchr is OK\n");
}

void test_ft_tolower(void)
{
    if (ft_tolower('A') != 'a')
        printf("KO - ft_tolower - 'A' should be 'a'\n");
    else if (ft_tolower('Z') != 'z')
        printf("KO - ft_tolower - 'Z' should be 'z'\n");
    else if (ft_tolower('a') != 'a')
        printf("KO - ft_tolower - 'a' should remain 'a'\n");
    else if (ft_tolower('z') != 'z')
        printf("KO - ft_tolower - 'z' should remain 'z'\n");
    else if (ft_tolower('0') != '0')
        printf("KO - ft_tolower - '0' should remain '0'\n");
    else if (ft_tolower('!') != '!')
        printf("KO - ft_tolower - '!' should remain '!'\n");
    else if (ft_tolower('@') != '@')
        printf("KO - ft_tolower - '@' should remain '@'\n");
    else if (ft_tolower('[') != '[')
        printf("KO - ft_tolower - '[' should remain '['\n");
    else if (ft_tolower(300) != 300)
        printf("KO - ft_tolower - 300 should remain 300 - Probably overflow error\n");
    else
        printf("10 - ft_tolower is OK\n");
}

void test_ft_bzero(void)
{
    char buffer[100];
    int i;
    int all_tests_passed = 1;

    ft_bzero(buffer, 100);
    i = 0;
    while (i < 100) 
    {
        if (buffer[i] != 0) 
        {
            printf("KO - ft_bzero - Buffer should be filled with 0\n");
            all_tests_passed = 0;
        }
        i++;
    }

    memset(buffer, 'a', 100);
    ft_bzero(buffer, 10);
    i = 0;
    while (i < 10) 
    {
        if (buffer[i] != 0) 
        {
            printf("KO - ft_bzero - First 10 bytes should be 0\n");
            all_tests_passed = 0;
        }
        i++;
    }
    while (i < 100)
    {
        if (buffer[i] != 'a')
        {
            printf("KO - ft_bzero - Rest should still be 'a'\n");
            all_tests_passed = 0;
        }
        i++;
    }

    if (all_tests_passed)
        printf("9 - ft_bzero is OK\n");
}

void test_ft_memset(void)
{
    unsigned char buffer[100];
    int i;
    int all_tests_passed = 1;

    ft_memset(buffer, 'A', 100);
    i = 0;
    while (i < 100) 
    {
        if (buffer[i] != 'A') 
        {
            printf("KO - ft_memset - Buffer should be filled with 'A'\n");
            all_tests_passed = 0;
        }
        i++;
    }

    memset(buffer, 0, 100);
    ft_memset(buffer, 'B', 10);
    i = 0;
    while (i < 10) 
    {
        if (buffer[i] != 'B') 
        {
            printf("KO - ft_memset - First 10 bytes should be 'B'\n");
            all_tests_passed = 0;
        }
        i++;
    }
    while (i < 100)
    {
        if (buffer[i] != 0)
        {
            printf("KO - ft_memset - Rest should still be 0\n");
            all_tests_passed = 0;
        }
        i++;
    }

    memset(buffer, 0, 100);
    ft_memset(buffer, 304, 100);
    i = 0;
    while (i < 100) 
    {
        if (buffer[i] != 48)
        {
            printf("KO - ft_memset - Buffer should overflow to 48\n");
            all_tests_passed = 0;
        }
        i++;
    }

    memset(buffer, 0, 100);
    ft_memset(buffer, 177, 100);
    i = 0;
    while (i < 100) 
    {
        if (buffer[i] != 177)
        {
            printf("KO - ft_memset - Buffer should be filled with 177\n");
            all_tests_passed = 0;
        }
        i++;
    }

    memset(buffer, 'A', 100);
    ft_memset(buffer, 'B', 0);
    i = 0;
    while (i < 100)
    {
        if (buffer[i] != 'A')
        {
            printf("KO - ft_memset - Buffer should remain as 'A'\n");
            all_tests_passed = 0;
        }
        i++;
    }

    if (all_tests_passed)
        printf("7 - ft_memset is OK\n");
}

void	test_ft_isprint(void)
{
	if (!ft_isprint('0'))
		printf("KO - ft_isprint - '0' should be not null\n");
	else if (!ft_isprint('h'))
		printf("KO - ft_isprint - 'h' should be not null\n");
	else if (!ft_isprint('~'))
		printf("KO - ft_isprint - '~' should be not null\n");
	else if (!ft_isprint(' '))
		printf("KO - ft_isprint - ' ' should be not null\n");
	else if (ft_isprint(0))
		printf("KO - ft_isprint - 0 should be null\n");
	else if (ft_isprint(127))
		printf("KO - ft_isprint - 127 should be null\n");
	else if (ft_isprint(-1))
		printf("KO - ft_isprint - -1 should be null\n");
	else if (ft_isprint(128))
		printf("KO - ft_isprint - 128 should be null\n");
	else if (ft_isprint(257))
		printf("KO - ft_isprint - 257 should be null - Probably overflow error\n");
	else
		printf("5 - ft_isprint is OK\n");
}

void	test_ft_isascii(void)
{
	if (!ft_isascii('0'))
		printf("KO - ft_isascii - '0' should be not null\n");
	else if (!ft_isascii('h'))
		printf("KO - ft_isascii - 'h' should be not null\n");
	else if (!ft_isascii('Z'))
		printf("KO - ft_isascii - 'Z' should be not null\n");
	else if (!ft_isascii('!'))
		printf("KO - ft_isascii - '!' should be not null\n");
	else if (!ft_isascii(0))
		printf("KO - ft_isascii - 0 should be not null\n");
	else if (!ft_isascii(127))
		printf("KO - ft_isascii - 127 should be not null\n");
	else if (ft_isascii(-1))
		printf("KO - ft_isascii - -1 should be null\n");
	else if (ft_isascii(128))
		printf("KO - ft_isascii - 128 should be null\n");
	else if (ft_isascii(257))
		printf("KO - ft_isascii - 257 should be null - Probably overflow error\n");
	else
		printf("4 - ft_isascii is OK\n");
}

void	test_ft_toupper(void)
{
    int all_tests_passed = 1; 
    if (ft_toupper('a') != 'A') {
        printf("KO - ft_toupper - 'a' should be converted to 'A'\n");
        all_tests_passed = 0;
    }
    if (ft_toupper('z') != 'Z') {
        printf("KO - ft_toupper - 'z' should be converted to 'Z'\n");
        all_tests_passed = 0;
    }
    if (ft_toupper('A') != 'A') {
        printf("KO - ft_toupper - 'A' should not change\n");
        all_tests_passed = 0;
    }
    if (ft_toupper('Z') != 'Z') {
        printf("KO - ft_toupper - 'Z' should not change\n");
        all_tests_passed = 0;
    }
    if (ft_toupper('0') != '0') {
        printf("KO - ft_toupper - '0' should not change\n");
        all_tests_passed = 0;
    }
    if (ft_toupper('9') != '9') {
        printf("KO - ft_toupper - '9' should not change\n");
        all_tests_passed = 0;
    }
    if (ft_toupper('!') != '!') {
        printf("KO - ft_toupper - '!' should not change\n");
        all_tests_passed = 0;
    }
    if (ft_toupper('~') != '~') {
        printf("KO - ft_toupper - '~' should not change\n");
        all_tests_passed = 0;
    }
    if (ft_toupper(' ') != ' ') {
        printf("KO - ft_toupper - ' ' should not change\n");
        all_tests_passed = 0;
    }
    if (ft_toupper('\n') != '\n') {
        printf("KO - ft_toupper - newline should not change\n");
        all_tests_passed = 0;
    }
    if ((ft_toupper(224) == 'A') || (ft_toupper(224) == 'a')) {
        printf("KO - ft_toupper - Value 224 should not change to 'a' or 'A' - Probably overflow error\n");
        all_tests_passed = 0;
    }
    if ((ft_toupper(352) == 'A') || (ft_toupper(352) == 'a')) {
        printf("KO - ft_toupper - Value 352 should not change to 'a' or 'A' - Probably overflow error\n");
        all_tests_passed = 0;
    }
    if (all_tests_passed == 1)
        printf("8 - ft_toupper is OK\n");
}

void test_ft_strlen(void)
{
    if (ft_strlen("") != 0)
        printf("KO - ft_strlen - Empty string should return 0\n");
    else if (ft_strlen("Hello") != 5)
        printf("KO - ft_strlen - 'hello' should return 5\n");
    else if (ft_strlen("Hello world") != 11)
        printf("KO - ft_strlen - 'Hello world' should return 11\n");
    else if (ft_strlen(" ") != 1)
        printf("KO - ft_strlen - Single space should return 1\n");
    else if (ft_strlen("a b c") != 5)
        printf("KO - ft_strlen - 'a b c' should return 5\n");
    else if (ft_strlen("@#$^&*()") != 8)
        printf("KO - ft_strlen - '@#$^&*()' should return 10\n");
    else if (ft_strlen("1234567890") != 10)
        printf("KO - ft_strlen - '1234567890' should return 10\n");
    else if (ft_strlen("ação") != 6)
        printf("KO - ft_strlen - 'ação' should return 6\n");
    else
        printf("6 - ft_strlen is OK\n");
}

void test_ft_isalnum(void)
{
    if (!ft_isalnum('0'))
        printf("KO - ft_isalnum - '0' should be not null\n");
    else if (!ft_isalnum('h'))
        printf("KO - ft_isalnum - 'h' should be not null\n");
    else if (!ft_isalnum('Z'))
        printf("KO - ft_isalnum - 'Z' should be not null\n");
    else if (!ft_isalnum('5'))
        printf("KO - ft_isalnum - '5' should be not null\n");
    else if (ft_isalnum(32))
        printf("KO - ft_isalnum - 32 should be null\n");
    else if (ft_isalnum(305))
        printf("KO - ft_isalnum - 305 should be null - Probably overflow error\n");
    else
        printf("3 - ft_isalnum is OK\n");
}

void test_ft_isdigit(void)
{
    if (!ft_isdigit('0'))
        printf("KO - ft_isdigit - '0' should be not null\n");
    else if (!ft_isdigit('5'))
        printf("KO - ft_isdigit - '5' should be not null\n");
    else if (ft_isdigit(2))
        printf("KO - ft_isdigit - 2 should be null\n");
    else if (ft_isdigit(32))
        printf("KO - ft_isdigit - 32 should be null\n");
    else if (ft_isdigit(305))
        printf("KO - ft_isdigit - 305 should be null - Probably overflow error\n");
    else
        printf("2 - ft_isdigit is OK\n");
}

void test_ft_isalpha(void)
{
    if (!ft_isalpha('h'))
        printf("KO - ft_isalpha - 'h' should be not null\n");
    else if (!ft_isalpha('Z'))
        printf("KO - ft_isalpha - 'Z' should be not null\n");
    else if (ft_isalpha(32))
        printf("KO - ft_isalpha - 32 should be null\n");
    else if (ft_isalpha('0'))
        printf("KO - ft_isalpha - '0' should be null\n");
    else if (ft_isalpha(325))
        printf("KO - ft_isalpha - 325 should be null - Probably overflow error\n");
    else
        printf("1 - ft_isalpha is OK\n");
}


int	main(void)
{
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_strlen();
    test_ft_memset();
    test_ft_toupper();
    test_ft_bzero();
    test_ft_tolower();
    test_ft_strchr();
    test_ft_strrchr();
    printf("13 - ft_memcpy not tested here\n");
    printf("14 - ft_memmove not tested here\n");
    printf("15 - ft_strlcpy not tested here\n");
    test_ft_strlcat();
    test_ft_strncmp();
    test_ft_memchr();
    test_ft_memcmp();
    printf("20 - ft_strnstr not tested here\n");
	test_ft_atoi();
    printf("22 - ft_calloc not tested here, but check the overflow scenario just in case\n");
    test_ft_strdup();
    test_ft_substr();
    test_ft_strjoin();
    test_ft_strtrim();
    test_ft_split();
    test_ft_itoa();
    test_ft_strmapi();
    printf("30 - striteri not tested here\n");
    test_ft_putchar_fd();
    test_ft_putstr_fd();
    printf("33 - ft_putendl_fd not tested here\n");
    printf("34 - ft_putnbr_fd not tested here\n");
	return (0);
}
