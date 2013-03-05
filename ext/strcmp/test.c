#include <stdio.h>
#include "jaro_winkler.h"

int main(int argc, char *argv[]) {
    //char *str1 = argv[1];
    //char *str2 = argv[2];
    char *str1[] = { "", "foobar", "martha", "dwayne", "dixon" };
    char *str2[] = { "", "", "marhta", "duane", "dicksonx" };
    for (int i = 0; i < 5; i++) {
        double dist_1 = jaro_distance(str1[i], str2[i]);
        double dist_2 = jaro_distance(str2[i], str1[i]);
        printf("jaro_distance(\"%s\", \"%s\") => %f\n", str1[i], str2[i], dist_1);
        printf("jaro_distance(\"%s\", \"%s\") => %f\n", str2[i], str1[i], dist_2);
    }
}
