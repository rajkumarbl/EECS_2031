#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char text[21];
  int points;
} hand;

void outputhand(hand *h, int max)
{
  if (h->points == max) printf("%s", h->text);
}

void readhand(hand *h, int *max)
{
  int i;
  int p = 0;
  for (i = 0; i < 21; i++)
  {
    char c = getchar();
    h->text[i] = c;
    switch (c) {
      case 'A': p += 4; break;
      case 'K': p += 3; break;
      case 'Q': p += 2; break;
      case 'J': p += 1; break;
      default: break;
    }
  }
  h->points = p;
  if (*max < p) *max = p;
}

int main()
{
  hand *hands;
  int i, noh;
  int maxpoints = 0;
  scanf("%d", &noh);
  // Consume the newline after the number of hands
  getchar();
  hands = (hand *) malloc (noh * sizeof(hand));
  for (i = 0; i < noh; i++) readhand(hands + i, &maxpoints);
  for (i = 0; i < noh; i++) outputhand(hands + i, maxpoints);
}
