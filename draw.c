
/*
 * I will use this file to store drawing functions.
 */
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>

void draw_bg_green()
{
  al_clear_to_color(al_map_rgb(0,50,0));
}

void draw_square()
{
  al_draw_filled_rectangle(2.5, 30.5, 55, 55, al_map_rgb(50,0,0));
}

void draw_main(ALLEGRO_DISPLAY **display)
{
  al_set_target_backbuffer(*display);
  
  draw_bg_green();
  al_flip_display();
  al_rest(2.0);
  
  draw_square();
  al_flip_display();
  al_rest(2.0);
}

