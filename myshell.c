#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rmline( char *sen ) {
sen[ strlen(sen) -1 ] = '\0';
}

char * rmSp( char *ptr ){
while ( *ptr == ' ') ptr++;
return ptr;
}

int main()
{
while(1)
{
char sen[80] = "";
   int i = 0;
   int thing = 1;
   int retract = 0;
      fflush(0);
  printf("myShell1$ ");
    fgets( sen, 80, stdin);
      char *ptr = sen;
        rmline( sen );
   ptr = rmSp( ptr );
      if ( *ptr == '\n' )
      continue;
  if ( strcmp(ptr,"exit") == 0 )
    return 0;
      char *token;
       char sn[2] = " ";
   token = strtok(sen, sn);
    while( token != NULL )
      {
       if ( thing == 1 ){
   printf("Command: %s\n", token);
        thing = 0;
   }
     else if ( *token == '-')
       {
          ++token;

    while( *token != '\0'){
          printf("Option : %c\n", *token);
         ++token;
    }
         }
     else if ( strcmp(token,"<") == 0 )
       {
      printf("File : %c\n", *token);
             retract = 1;
        }
     else if ( strcmp(token,">") == 0 )
        {
     printf("File : %c\n", *token);
          retract = 1;
        }
 else if ( strcmp(token,"|") == 0 )
      {
       printf("pipe\n");
       thing = 1;
         }
       else{
    
       if ( retract == 1 ){
       printf("File : %s\n", token);
       retract = 0;
            }
          else
        printf("Argument : %s\n", token);
          }
token = strtok(NULL,sn);
      }   
  }
  }
  
