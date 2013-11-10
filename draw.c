
/*
 * This file is used to store drawing functions.
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

  /*
   * initial triangle
   *  try to fill screen
   */

  int p1[2]; //initial triangle point 1
  int p2[2]; //initial triangle point 2
  int p3[2]; //initial triangle point 3

  p1[0] = 200;
  p1[1] = 0;
  p2[0] = 0;
  p2[1] = 400;
  p3[0] = 400;
  p3[1] = 400;

  al_draw_filled_triangle(p1[0], p1[1], p2[0], p2[1], p3[0], p3[1], al_map_rgb(0,50,50));
  al_flip_display();
  al_rest(1.0);

  /*
   * top triangle
   */

  int tp1[2]; //top triangle point 1 (top)
  int tp2[2]; //top triangle point 2 (bottom left)
  int tp3[2]; //top triangle point 3 (bottom right)
  
  //Algorithm for calculating top triangles first point (top)
  tp1[0] = p1[0];  //doesnt change
  tp1[1] = p2[0];  //doesn't change

  //Algorithm for calculating top triangles second point (bottom left)
  tp2[1] = p2[1] / 2;      //always same as p3[1]
  tp2[0] = tp2[1] / 2;  //p2[0] and p3[0] always add up to 400 x2 gets larger as the triangle gets smaller

  //Algorithm for calculating top triangles third point (bottom right)
  tp3[0] = 400 - tp2[0];   //p2[0] and p3[0] always add up to 400 x3 gets smaller as the triangle gets smaller
  tp3[1] = tp2[1];         //always same as p2[1]

  al_draw_filled_triangle(tp1[0], tp1[1], tp2[0], tp2[1], tp3[0], tp3[1], al_map_rgb(50,50,50));
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

