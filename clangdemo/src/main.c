#include "lib/hello.h"
#include "customlibs/hello.h"
int main() {
    say_hello();
    for(int i=1; i<=7; i++) {
        say_hello_again(i);    
    }
    return 0;
}