
#include <stdio.h>
#include <allegro5/allegro.h>

#include "link1.h"
#include "link2.h"

const int SCREEN_W = 400;
const int SCREEN_H = 400;

int main(void)
{
  int a = returnas5();
  int b = returnas6();
  
  al_init();
  
  ALLEGRO_DISPLAY *display = al_create_display(SCREEN_W, SCREEN_H);
  

  printf("link1 returns %d", a);
  printf("link2 returns %d", b);

  al_destroy_display(display);
  
  return 0;
}

