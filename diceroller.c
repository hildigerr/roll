#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

inline void display_usage( char* argv0 )
{
    fprintf( stderr, "\nUsage:\n  %s xdy\n%s", argv0,
        "Where x is number of dice and y is number of sides on die\n\n");
}/* End display_usage Func */

int main(int argc, char *argv[])
{
    char *argxy, *xch, *ych;
    int xin, yin, z;
    int tot = 0;

    srand(time(NULL));

    
    if( argc < 2 ) display_usage(argv[0]); /* Wrong number of parameters */
    else {
        argxy = argv[1];

        ych = strchr(argxy, 'd');
        if( ych ) {
        
            xch = argxy;
            *ych++ = '\0';
            xin = atoi(xch);
            yin = atoi(ych);
            
            for( z = 1; xin > 0; xin-- ) {
                if(z == 0) printf(" + ");
                z = (rand() % yin) +1;
                printf("%d", z);
                tot += z;
                z = 0;
            } printf(" = %d\n", tot);
            
         } else {       
            fprintf(stderr, "\nERROR: Argument %s is not in expected format.", argv[1]);
            display_usage(argv[0]);
        }/* End 'd' If-Else */
    } return tot;	
}/* End main Func */

