#ifndef ARRAY_LEN
#define ARRAY_LEN 16
#endif

int
main (int argc, char *argv)
{
  int values[ARRAY_LEN];
  int sum = 0;
  int i;

  for (i = 0; i < ARRAY_LEN; i++)
    sum += values[i];

  return sum;
} // example9
