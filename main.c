
#include <stdio.h>
#include <allegro5/allegro.h>
#include "link1.h"
#include "link2.h"

const int SCREEN_W = 400;
const int SCREEN_H = 400;

void draw_bg_green(ALLEGRO_DISPLAY **display)
{
  al_set_target_backbuffer(*display);
  al_clear_to_color(al_map_rgb(0,100,0));
  al_flip_display();
}

int main(void)
{
  int a = returnas5();
  int b = returnas6();
  
  al_init();
  
  ALLEGRO_DISPLAY *display = al_create_display(SCREEN_W, SCREEN_H);

  draw_bg_green(&display);

  al_rest(5.0);

  al_destroy_display(display);
  
  return 0;
}

