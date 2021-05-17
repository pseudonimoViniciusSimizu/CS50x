#include <stdio.h>
#include <cs50.h>

int pair(int);

int main(void)
{
    long card_number = 0;
    
    // Get the card number
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 0);
    
    // Create a card copy
    long cloned_card = card_number;
    
    int temp;
    int sum = 0;
    int digits = 0;

    // Process each number in the card
    for (int i = 1; card_number > 0; i++)
    {
        // The actual card's number
        temp = card_number % 10;
        
        // If the number is pair
        if (i % 2 == 0)
        {  
            // Store the output value in the sum
            sum += pair(temp);
        }
        
        // If the number is odd
        else
        {
            // Store the output value in the sum
            sum += temp;
        }
        
        // Go to the next number
        card_number = card_number / 10;
        
        // Store the digits
        digits += 1;
    }
    
    // Get the two firsts numbers in the card
    long zeros = 1;
    for (int i = 0; digits - 2 > i; i++)
    {
        zeros *= 10;
    }
    int starts_digits = cloned_card / zeros;
    
    // Do the checksum
    if (sum % 10 == 0)
    {
        // If it's AMEX's card
        if ((digits == 15) && ((starts_digits == 34) || (starts_digits == 37)))
        {
            printf("AMEX\n");
        }
        
        // If it's MASTERCARD's card
        else if ((digits == 16) && ((starts_digits == 51) || (starts_digits == 52) || (starts_digits == 53) || (starts_digits == 54) 
                                    || (starts_digits == 55)))
        {
            printf("MASTERCARD\n");
        }
        
        // If it's VISA's card
        else if ((starts_digits / 10 == 4) && ((digits == 13) || (digits == 16)))
        {
            printf("VISA\n");
        }
        
        // Otherwise print "INVALID"
        else
        {
            printf("INVALID\n");
        }
        
        // If it doesn't pass the checksum print "INVALID"
    }
    else
    {
        printf("INVALID\n");
    }
}

int pair(number)
{
    // Store the processed final value
    int result = 0;
    
    // Multiply the number by two
    int multiplied = number * 2;
    
    // If the number multiplied is highter than ten, sum each digits of them
    if (multiplied >= 10)
    {
        for (; multiplied > 0;)
        {
            int temp_numb = multiplied % 10;
            result += temp_numb;
            multiplied = multiplied / 10;
        }
    }
    
    // If it's odd, then store the result's value in the sum
    else
    {
        result = multiplied;
    }
    return (result);
}
