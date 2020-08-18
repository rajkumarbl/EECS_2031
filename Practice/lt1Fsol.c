#include <stdio.h> 
#include <stdlib.h>

typedef struct {
  char *text;
  int length;
} line;

void outputline(line *l, int max)
{
  if (l->length == max) printf("%s",l->text);
}

void readline(line *l, int *max)
{
  int i, len;
  scanf("%d", &len);
  // Consume the newline after the length
  getchar();
  l->length = len;
  // Allocate enough memory for newline and null character as well
  l->text = (char *) malloc ((len+2) * sizeof(char));
  // Read len+1 characters to include newline
  for (i = 0; i < len + 1; i++) l->text[i] = getchar();
  l->text[len+1] = '\0';
  if (*max < len) *max = len;
}

int main()
{
  line *lines;
  int i, nol;
  int maxlength = 0;
  scanf("%d", &nol);
  // Allocate memory for all the line pairs
  lines = (line *) malloc (nol * sizeof(line));
  for (i = 0; i < nol; i++) readline(lines + i, &maxlength);
  for (i = 0; i < nol; i++) outputline(lines + i, maxlength);
}
