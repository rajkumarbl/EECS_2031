#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_CHUNK 10

static int counter, multiplier;
static char **rel, **ent1, **ent2;

char *readAllocLine(FILE * source)
{
  char buffer[20];
  char *line;
  int mult = 1;
  if (fgets(buffer, sizeof buffer, source) == NULL) return NULL;
  line = malloc ( sizeof buffer );
  strncpy(line, buffer, strlen(buffer) + 1);
  while ( line[strlen(line) - 1] != '\n')
  {
    char *tmp;
    mult++;
    fgets(buffer, sizeof buffer, source);
    if ((tmp = realloc ( line, sizeof buffer * mult )) == NULL)
    {
      fprintf(stderr, "ERROR: realloc failed");
      exit(1);
    }
    line = tmp;
    strncat(line, buffer, strlen(buffer));
  }
  return line;
}

void addfact(char *crel, char *cent1, char *cent2)
{
    if (counter >= multiplier * ARRAY_CHUNK)
    {
      multiplier++;
      rel = realloc (rel, multiplier * ARRAY_CHUNK * sizeof (char *)); 
      ent1 = realloc (ent1, multiplier * ARRAY_CHUNK * sizeof (char *)); 
      ent2 = realloc (ent2, multiplier * ARRAY_CHUNK * sizeof (char *)); 
    }
    rel[counter] = malloc ((strlen(crel)+1) * sizeof(char));
    ent1[counter] = malloc ((strlen(cent1)+1) * sizeof(char));
    ent2[counter] = malloc ((strlen(cent2)+1) * sizeof(char));
    strncpy(rel[counter],crel,strlen(crel)+1);
    strncpy(ent1[counter],cent1,strlen(cent1)+1);
    strncpy(ent2[counter],cent2,strlen(cent2)+1);
    counter++;
}

main() {
  int i, res, args, badcounter, noTokens; 
  FILE *database;
  char *commandString; 
  char *command; 
  char *arguments; 
  char *arg1; 
  char *rest; 
  char *extra; 
  char *fact; 
  char *crel, *cent1, *cent2;
  counter = 0;
  printf("Grock- ");
  commandString = readAllocLine(stdin);
  while (strncmp("quit\n", commandString, 6))
  {
    //printf("Commandstring: %s", commandString);
    command = malloc (strlen(commandString) * sizeof(char));
    arguments = malloc (strlen(commandString) * sizeof(char));
    res = sscanf(commandString, "%s %[^\n]s", command, arguments);
    //printf("res = %d",res);
    if (res > 0)
    {
      if (strncmp(command, "setdb", 6) == 0)
      {
        //printf("Command entered: %s\n", command);
        if (res > 1)
        {
          arg1 = malloc ( strlen(arguments) * sizeof(char));
          rest = malloc ( strlen(arguments) * sizeof(char));
          args = sscanf(arguments, "%s %s", arg1, rest);
          //printf("Arguments entered: %s\n", arguments);
          //printf("Arguments entered: %s\n", arg1);
          database = fopen(arg1,"r");
          if (database != NULL)
          {
            multiplier = 1;
            counter = 0;
            badcounter = 0;
            rel = malloc( ARRAY_CHUNK * sizeof (char *));
            ent1 = malloc( ARRAY_CHUNK * sizeof (char *));
            ent2 = malloc( ARRAY_CHUNK * sizeof (char *));
            //while (fgets(line, sizeof(line), database)) 
            while (fact = readAllocLine(database)) 
            {
              crel = malloc (strlen(fact) * sizeof(char));
              cent1 = malloc (strlen(fact) * sizeof(char));
              cent2 = malloc (strlen(fact) * sizeof(char));
              extra = malloc (strlen(fact) * sizeof(char));
              noTokens = sscanf(fact, "%s %s %s %s", crel, cent1, cent2, extra);             
              if (noTokens == 3)
              {
                addfact(crel,cent1,cent2);
              }
              else
              {
                badcounter++;
              }
              free(crel);
              free(cent1);
              free(cent2);
              //printf("%s\n", rel[counter]);
              //printf("%s\n", ent1[counter]);
              //printf("%s\n", ent2[counter]);
              //printf("%d\n", counter);
            }
            fclose(database);
            printf("Read %d facts from %s\n", counter, arg1);
            if (badcounter > 0)
              printf("%d malformed lines were ignored.\n", badcounter);
          }
          else
            printf("Unable to read from %s\n", arg1);
          if (args > 1) printf("Extra arguments ignored.\n");
        }
        else
          printf("Missing argument.\n");
      }
      else if (strncmp(command, "printdb",128) == 0)
      {
        int i;
        if (counter == 0)
          printf("Database is empty.\n");
        else
          for (i = 0; i < counter; i++)
          {
            printf("%s %s %s\n", rel[i], ent1[i], ent2[i]);
          } 
      }
      else if (strncmp(command, "addrel",128) == 0)
      {
        char *rel1, *rel2, *newrel;
        int i, oldcounter, newfacts = 0;
        if (res > 1)
        {
          rel1 = malloc ( strlen(arguments) * sizeof(char));
          rel2 = malloc ( strlen(arguments) * sizeof(char));
          newrel = malloc ( strlen(arguments) * sizeof(char));
          rest = malloc ( strlen(arguments) * sizeof(char));
          args = sscanf(arguments, "%s %s %s %s", rel1, rel2, newrel, rest);
          //printf("Arguments entered: %s\n", arguments);
          //printf("Arguments entered: %s\n", arg1);
          if (args > 2)
          {
            oldcounter = counter;
            for (i=0; i < oldcounter; i++)
            {
              if (strncmp(rel[i],rel1, strlen(rel1) + 1) == 0)
                {
                  addfact(newrel, ent1[i], ent2[i]);
                  newfacts++;
                }
            }
            for (i=0; i < oldcounter; i++)
            {
              if (strncmp(rel[i],rel2, strlen(rel2) + 1) == 0)
                {
                  addfact(newrel, ent1[i], ent2[i]);
                  newfacts++;
                }
            }
            printf("Added %d facts to the factbase.\n", newfacts);
          }
          else
            printf("Missing arguments.\n");
        }
        else
          printf("Missing arguments.\n");
      }
      else if (strncmp(command, "inverse",128) == 0)
      {
        char *rel1, *newrel;
        int i, oldcounter, newfacts = 0;
        if (res > 1)
        {
          rel1 = malloc ( strlen(arguments) * sizeof(char));
          newrel = malloc ( strlen(arguments) * sizeof(char));
          rest = malloc ( strlen(arguments) * sizeof(char));
          args = sscanf(arguments, "%s %s %s", rel1, newrel, rest);
          //printf("Arguments entered: %s\n", arguments);
          //printf("Arguments entered: %s\n", arg1);
          if (args > 1)
          {
            oldcounter = counter;
            for (i=0; i < oldcounter; i++)
            {
              if (strncmp(rel[i],rel1, strlen(rel1) + 1) == 0)
                {
                  addfact(newrel, ent2[i], ent1[i]);
                  newfacts++;
                }
            }
            printf("Added %d facts to the factbase.\n", newfacts);
          }
          else
            printf("Missing arguments.\n");
        }
        else
          printf("Missing arguments.\n");
      }
      else
        printf("Unrecognized command.\n");
    }
    printf("Grock- ");
    commandString = readAllocLine(stdin);
  }
}

