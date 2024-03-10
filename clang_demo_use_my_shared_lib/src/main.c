#include <stdio.h>
#include <libutils.h>

int main(int argc, char** argv)
{
	(void)argc; (void)argv;
    printf("Hello from my shared library = %s\n", say_hello_dynamically());
    return 0;
}