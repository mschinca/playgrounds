// Dynamically load LZ4 and print library version number
// compile with:
// gcc print_version_runtime.c -o print_version_runtime

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char** argv)
{
	(void)argc; (void)argv;
    

    // Open liblz4 library.
    void* lib_handle = dlopen("/usr/local/lib/liblz4.dylib", RTLD_LOCAL|RTLD_LAZY);
    if (!lib_handle) {
        printf("[%s] Unable to load library: %s\n", __FILE__, dlerror());
        exit(1);
    }

    // typedef int (*fptr)();
    // fptr func;
    int (*func)() = dlsym(lib_handle, "LZ4_versionNumber");
    if (!func) {       // addRating is guaranteed to exist in libRatings.A.dylib
        printf("[%s] Unable to get symbol: %s\n", __FILE__, dlerror());
        exit(2);
    }

    printf("Hello World ! LZ4 Library dynamically loaded, version = %d\n", func());
    int dlclose_result = dlclose(lib_handle);
    if (dlclose_result != 0) {
        printf("[%s] Unable to close library: %s\n", __FILE__, dlerror());
    };

    return 0;
}