#include <stdio.h>

#include "link1.h"
#include "link2.h"

int main(void)
{
  int a = returnas5();
  int b = returnas6();

  printf("link1 returns %d", a);
  printf("link2 returns %d", b);
  
  return 0;
}
