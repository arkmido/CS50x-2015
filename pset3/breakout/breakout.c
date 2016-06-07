//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// height and width of paddle in pixels
#define PADHEIGHT 15
#define PADWIDTH 75

// height, width, and initial x and y of bricks
#define BHEIGHT 10
#define BWIDTH 35
#define BX 2
#define BY 60 

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    
    // ball movement    
    double vel_X = drand48() + 0.9;
    double vel_Y = drand48() + 2.8;
    
    // keep playing until game over   
    while (lives > 0 && bricks > 0)
    {
        // TODO
        GEvent event = getNextEvent(MOUSE_EVENT);
        if (event != NULL)
        {   
            // paddle movements
            if (getEventType(event) == MOUSE_MOVED)
            {
                double x = 0.0;
                /*if ((getX(paddle) + getWidth(paddle)) >= getWidth(window))
                    x = getWidth(window) - getWidth(paddle);
                else*/
                    x = getX(event) - getWidth(paddle)/2;
                setLocation(paddle, x, getY(paddle));
            }
        }
        
        // ball movements
        move(ball, vel_X, vel_Y);
        
         // x detection
        if (getX(ball) + getWidth(ball) >= getWidth(window))
            vel_X = -vel_X;
        else if (getX(ball) <= 0)
            vel_X = -vel_X;
            
         // y detection
        if (getY(ball) + getHeight(ball) >= getHeight(window))
        {
            // decrease lives and pause the game
            lives--;
            while(true)
            {
                event = getNextEvent(MOUSE_EVENT);   
                if (event != NULL)
                {
                    if (getEventType(event) == MOUSE_CLICKED)
                    {
                        setLocation(ball, WIDTH/2 - RADIUS, HEIGHT/2 - RADIUS);
                        break;
                    }
                }
            }
        }
        else if (getY(ball) <= 0)
            vel_Y = -vel_Y;
        
        // get ball and object collision
        GObject object = detectCollision(window, ball);
        
            if (object != NULL){
                if (strcmp(getType(object), "GRect") == 0){
                    if (object != paddle)
                    {
                        removeGWindow(window, object);
                        bricks--;
                        points++;
                        updateScoreboard(window, label, points);
                    }
                    vel_Y = -vel_Y;
                }   
                    
            }   
        
        pause(2);
    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // TODO
    int x = BX, y = BY;
    string color[5] = {"RED", "ORANGE", "YELLOW", "CYAN", "LIGHT_GRAY"};
    for(int i = 0; i < ROWS; i++)
    {  
        for(int j = 0; j < COLS; j++)
        {
            GRect brick = newGRect(x, y, BWIDTH, BHEIGHT);
            setFilled(brick, true);
            setColor(brick, color[i]);
            add(window, brick);
            x = x + (BWIDTH + 5);
        }
        x = BX;
        y = y + (BHEIGHT + 5);
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // TODO
    GOval circle = newGOval(WIDTH/2 - RADIUS, HEIGHT/2 - RADIUS, RADIUS*2, RADIUS*2);
    setFilled(circle, true);
    setColor(circle, "DARK_GRAY");
    add(window, circle);
    return circle;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // TODO
    GRect paddle = newGRect((WIDTH/2) - (PADWIDTH/2), (HEIGHT - (PADHEIGHT * 5)), PADWIDTH, PADHEIGHT);
    setFilled(paddle, true);
    setColor(paddle, "BLUE");
    add(window, paddle);
    
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO
    GLabel label= newGLabel("");
    setFont(label, "SansSerif-36");
    add(window, label);
    
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
