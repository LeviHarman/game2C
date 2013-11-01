
/*
 * I will use this file to store drawing functions.
 */
#include<stdio.h>
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

void draw_triangle()
{

  int x1 = 200;
  int y1 = 0;
  int x2 = 0;
  int y2 = 400;
  int x3 = 400;
  int y3 = 400;

  al_draw_filled_triangle(x1, y1, x2, y2, x3, y3, al_map_rgb(0,50,50));
  al_flip_display();
  al_rest(1.0);

  /*
   * top triangle
   *  keep x1, and y1 the same
   *  add some to x2 and remove some from y2 so that they are twice as close
   *  subtract 1/4 from x3, and 1/2 from y3
   *  y2 and y3 always the same
   */
  //al_draw_filled_triangle(200, 0, 100, 200, 300, 200, al_map_rgb(50,50,50));
  x1 = 200; //doesnt change
  y1 = 0; //doesn't change
  x2 = 100; //x2 and x3 always add up to 400 x2 gets larger as the triangle gets smaller
  y2 = 200; //always same as y3
  x3 = 300; //x2 and x3 always add up to 400 x3 gets smaller as the triangle gets smaller
  y3 = 200; //always same as y2

  al_draw_filled_triangle(x1, y1, x2, y2, x3, y3, al_map_rgb(50,50,50));
  
  x1 = 200;
  y1 = 0;
  x2 = 250;
  y2 = 100;
  x3 = 150;
  y3 = 100;

  al_draw_filled_triangle(x1, y1, x2, y2, x3, y3, al_map_rgb(100,50,50));
  
  
  printf("y2/3: %d\n", y2/3);
  printf("y2-(y2/3): %d\n", y2-(y2/3));

  //al_draw_filled_triangle(x1, y1, x2, y2, x3, y3, al_map_rgb(50,50,50));
  //al_draw_filled_triangle(x1, y1, x2, y2, x3, y3, al_map_rgb(50,50,50));
  
  //these are to mark corners
  al_draw_filled_rectangle(x1, y1, x1+20, y1+20, al_map_rgb(70,10,65));//top point
  al_draw_filled_rectangle(x2, y2, x2+20, y2-20, al_map_rgb(70,140,65));//bottom left point
  al_draw_filled_rectangle(x3, y3, x3-20, y3-20, al_map_rgb(0,10,65));//bottom right point

  int i;
  for (i = 0; i < 3; i++)
    {

    }
}



void draw_main(ALLEGRO_DISPLAY **display)
{
  al_set_target_backbuffer(*display);

  draw_bg_green();
  al_flip_display();
  al_rest(.5);

  draw_square();
  al_flip_display();
  al_rest(.5);

  draw_triangle();
  al_flip_display();
  al_rest(2.0);
}

