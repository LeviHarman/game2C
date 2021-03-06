
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


  /*
   * bottom left triangle
   */

  int blp1[2];  //bottom left triangle point 1 (top)
  int blp2[2];  //bottom left triangle point 2 (bottom left)
  int blp3[2];  //bottom left triangle point 3 (bottom right)
  
  //Algorithm for calculating top triangles first point (top)
  blp1[0] = tp2[0];  //same as the bottom left x axis of the top triangle (tp2[0])
  blp1[1] = tp2[1];  //same as the bottom left y axis of the top triangle (tp2[1])

  //Algorithm for calculating top triangles second point (bottom left)
  blp2[1] = p2[1];  //same as the initial triangle
  blp2[0] = p2[0];  //same as the initial triangle

  //Algorithm for calculating top triangles third point (bottom right)
  blp3[0] = p3[0]/2;  //half as big as point 3 x axis (p3[0] / 2)
  blp3[1] = blp2[1];  //always same as blp2[1]

  al_draw_filled_triangle(blp1[0], blp1[1], blp2[0], blp2[1], blp3[0], blp3[1], al_map_rgb(50,50,50));


  /*
   * bottom right triangle
   */

  int brp1[2];  //bottom right triangle point 1 (top)
  int brp2[2];  //bottom right triangle point 2 (bottom left)
  int brp3[2];  //bottom right triangle point 3 (bottom right)
  
  //Algorithm for calculating top triangles first point (top)
  brp1[0] = tp3[0];
  brp1[1] = tp3[1];

  //Algorithm for calculating top triangles second point (bottom left)
  brp2[1] = blp3[1];
  brp2[0] = blp3[0];

  //Algorithm for calculating top triangles third point (bottom right)
  brp3[0] = p3[0];
  brp3[1] = p3[1];

  al_draw_filled_triangle(brp1[0], brp1[1], brp2[0], brp2[1], brp3[0], brp3[1], al_map_rgb(50,50,50));  

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

