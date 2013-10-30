
#include<allegro5/allegro.h>

void draw_bg_green(ALLEGRO_DISPLAY **display)
{
  al_set_target_backbuffer(*display);
  al_clear_to_color(al_map_rgb(0,100,0));
  al_flip_display();
}

