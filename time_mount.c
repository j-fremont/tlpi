#include <sys/times.h>
#include <time.h>
#include "lib/tlpi_hdr.h"

#define MAX 999999

int
main(int argc, char *argv[])
{
    clock_t clockTime; 
    int j, opt, nf;
    char *dir;

    nf = 0;
    dir = NULL;


    while ((opt = getopt(argc, argv, "n:d:")) != -1) {
        switch(opt) {
            case 'n':
                nf = strtol(optarg, NULL, 10);
                break;
            case 'd':
                dir = optarg;
                break;
            default:
                break;


        
        
        
        
        }
    }

    srand(time(NULL));

    printf("%ld\n", nf);

    for (j = 0; j <= nf; j++) {

        printf("%06d\n", rand() % MAX); 
    }
    
    
    
    clockTime = clock();
    if (clockTime == -1)
        errExit("clock");

    printf("clock() returns: %.2f secs\n", (double) clockTime / CLOCKS_PER_SEC);



}
