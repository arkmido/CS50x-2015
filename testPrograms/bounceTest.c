/* 
* bounce sample
*
* algorithm for bouncing objects using SPL
*/

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>

// Stanford Portable Library
#include </usr/include/spl/gevents.h>
#include </usr/include/spl/gobjects.h>
#include </usr/include/spl/gwindow.h>

int main(void){
    int winH = 240;
    int winW = 320;
    int cirW = 20;
    int cirH = 20;
    
    GWindow window = newGWindow(winW, winH);
    // circle =  x , y, w, h
    GOval circle = newGOval(winW/2 - cirW/2, winH/2 - cirH/2, cirW, cirH);
    setColor(circle, "BLACK");
    setFilled(circle, true);
    add(window, circle);
    
    double velX = drand48() + 2.5;
    double velY = 2.0;
    
    while(true){
        // move (object, dx, dy)
        move(circle, velX, velY);
        
        if(getX(circle) + getWidth(circle) >= getWidth(window))
            velX = -velX;
        else if(getX(circle) <= 0)
            velX = -velX;
            
        if(getY(circle) + getHeight(circle) >= getHeight(window))
            velY = -velY;
        else if(getY(circle) <= 0)
            velY = -velY;
        
        pause(20);
    }
}
