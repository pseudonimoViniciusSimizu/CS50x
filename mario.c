#include <stdio.h>
#include <cs50.h>

// indicate functions
void bricks_constructure();
void spaces_distance();

int main(void)
{
    // get the user's input
    int height;
    do
    {
        height = get_int("Height: ");
    } 
    while (height < 1 || height > 8);

    // print the numbers of line
    for (int i = 0; height > i; i++)
    {
        // print the left distance
        spaces_distance(i, height);

        // print the left bricks
        bricks_constructure(i);

        //print the two spaces between the sides
        printf(" ");
        printf(" ");

        // print the right bricks
        bricks_constructure(i);

        printf("\n");
    }
}

void bricks_constructure(i)
{
    // print the width of bricks
    for (int j = 0; i > j - 1; j++)
    {
        printf("#");
    }
}

void spaces_distance(i, height)
{
    // print the distance of bricks
    for (int j = i; height - 1 > j; j++)
    {
        printf(" ");
    }
}

// http://ide.cs50.io/
