#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXLEN 10

int main(int argc, char *argv[])
{
     size_t len;
     char *loc, argxy[MAXLEN+1], xch[MAXLEN], ych[MAXLEN];
     int i, xin, yin, z =0;
     int tot =0;
     
     srand(time(NULL));

     if( argc != 2 )
     {
          /*printf("\nERROR: Wrong number of parameters...");*/
          printf("\nUsage:\n  %s xdy\n", argv[0]);
          printf("Where x is number of dice and y is number of sides on die\n\n");
          return -1;
     }

     len = strlen(argv[1]);
     if(len>MAXLEN)
     {
          printf("\nERROR: Argument %s is too long.\n\n", argv[1]);
          return -1;
     }
	strcpy(argxy, argv[1]);

     loc = strchr(argxy, 'd');
     if ( loc == NULL ) 
     {
          printf("\nERROR: Argument %s does not in expected format.", argv[1]);
          printf("\nUsage:\n  %s xdy\n", argv[0]);
          printf("Where x is number of dice and y is number of sides on die\n\n");
          return -1;
     }

     for(i=0; argxy[i] != 'd'; i++)
     {
          xch[i] = argxy[i];
          xch[i+1] = '\0';
     }
     xin = atoi(xch);

     for(i +=1; argxy[i] != '\0'; i++, z++)
     {
          ych[z] = argxy[i];
          ych[z+1] = '\0';
     }
     yin = atoi(ych);

     for(; xin>0; xin--)
     {
          if(i == 0) printf("+");
          z = (rand() % yin) +1;
          printf("%d", z);
          tot += z;
          i=0;
     }
     printf("=%d\n", tot);

     return tot;	
}
