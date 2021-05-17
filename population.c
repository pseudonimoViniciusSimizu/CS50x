#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int years = 0;
    long population = 0;
    long end_size = 0;
    
    // Get the start value
    do
    {
        population = get_long("Start size: ");
    }
    while (population < 9);
    
    // Get the end size
    do
    {
        end_size = get_long("End size: ");
    }
    while (end_size < population);
    
    // Calculate the years to reach the goal
    for (; end_size > population; years += 1)
    {
        long born = population / 3;
        long deaths = population / 4;
        population += (born - deaths);
    }
    
    // Print the necessery years
    printf("Years: %i", years);
}
