#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE    1
#define FALSE   0

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define equal(a, b) (tolower(a) == tolower(b))
#define not_equal(a, b) (tolower(a) != tolower(b))

double jaro_distance(char *foo, char *bar) {
    // length of the strings, stops the repeated use of strlen
    int foo_len = strlen(foo);
    int bar_len = strlen(bar);

    // if both strings are empty return 1
    // if only one of the strings is empty return 0
    if (foo_len == 0) return bar_len == 0 ? 1.0 : 0.0;

    // max distance between two chars to be considered matching
    // floor() is ommitted due to integer division rules
    int match_distance = (int) max(foo_len, bar_len)/2 - 1;

    // arrays of bools that signify if that char in the matcing string has a match
    int *foo_matches = calloc(foo_len, sizeof(int));
    int *bar_matches = calloc(bar_len, sizeof(int));

    // number of matches and transpositions
    double matches = 0.0;
    double transpositions = 0.0;

    // find the matches
    for (int i = 0; i < foo_len; i++) {
        // start and end take into account the match distance
        int start = max(0, i - match_distance);
        int end = min(i + match_distance + 1, bar_len);

        // add comments...
        for (int k = start; k < end; k++) {
            // if bar already has a match continue
            if (bar_matches[k]) continue;
            // if foo and bar are not
            if (not_equal(foo[i], bar[k])) continue;
            // otherwise assume there is a match
            foo_matches[i] = TRUE;
            bar_matches[k] = TRUE;
            matches++;
            break;
        }
    }

    // if there are no matches return 0
    if (matches == 0) {
        free(foo_matches);
        free(bar_matches);
        return 0.0;
    }

    // count transpositions
    int k = 0;
    for (int i = 0; i < foo_len; i++) {
        // if there are no matches in foo continue
        if (!foo_matches[i]) continue;
        // while there is no match in bar increment k
        while (!bar_matches[k]) k++;
        // increment transpositions
        if (not_equal(foo[i], bar[k])) transpositions++;
        k++;
    }

    // divide the number of transpositions by two as per the algorithm specs
    // this division is valid because the counted transpositions include both
    // instances of the transposed characters.
    transpositions /= 2.0;

    // free dat allocated memory !VERY IMPORTANT!
    free(foo_matches);
    free(bar_matches);

    // return the jaro distance
    return ((matches / foo_len) +
        (matches / bar_len) +
        ((matches - transpositions) / matches)) / 3.0;
}

double jaro_winkler_distance(char *foo, char *bar) {
    // compute the jaro distance
    double jaro = jaro_distance(foo, bar);

    // finds the number of common terms in the first 3 strings, max 3.
    int prefix_length = 0;
    if (strlen(foo) != 0 && strlen(bar) != 0)
        while (prefix_length < 3 && equal(*foo++, *bar++)) prefix_length++;

    // 0.1 is the default scaling factor
    return jaro + prefix_length * 0.1 * (1 - jaro);
}