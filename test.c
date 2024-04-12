#include <stdio.h>
#include <gnu/libc-version.h>

int main(int argc, char *argv[]) {
  printf("Hello world!!!\n");
  printf("Major = %d\n", __GLIBC__);
  printf("Minor = %d\n", __GLIBC_MINOR__);
  printf("%s\n", gnu_get_libc_version());
}

