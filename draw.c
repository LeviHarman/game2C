/*
 * I will use this file to store drawing functions that do certain things
 * 
 */
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>

void draw_bg_green(ALLEGRO_DISPLAY **display)
{
  al_set_target_backbuffer(*display);
  al_clear_to_color(al_map_rgb(0,50,0));
  al_flip_display();
}

void draw_square(ALLEGRO_DISPLAY **display)
{
  al_set_target_backbuffer(*display);
  al_draw_filled_rectangle(2.5, 3.5, 5.5, 5.5, al_map_rgb(50,0,0));
  al_flip_display();
}

