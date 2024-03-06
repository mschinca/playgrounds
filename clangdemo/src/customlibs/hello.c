#include <stdio.h>
#include "functions.h"
#include "hello.h"

void say_hello_again(int numTimes) {
    printf("%d %s\n", numTimes, get_custom_message());
}