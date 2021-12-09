#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
		int remainder;
		int input;
		
		// User prompt for how many numbers are wanted to be generated
		do
		{
				input = get_int("How many Prime Numbers would you like to generate? ");
		}
		while(input <= 0);
		
		// Main loop
		for (int prime = 2, counter = 0, divider = 2, composite = 0; counter < input; prime+=2)
		{
				// This offsets the increments, so that it skips every even number after 2, because 2 is the only even prime number
				if (prime == 4)
				{
					prime--;
				}

				// This loop is used check if the prime variable is actually a prime number
				do
				{
						remainder = prime % divider; // gets remainder, the remainder should only be 0 when divided by itself and 1

						if (divider < prime && remainder == 0) // if remainder = 0 before the divider = prime then it must be a composite number, because of the comment above
						{
						    composite = 1;
						}

						if (divider > sqrt(prime) && remainder != 0) // This hugely speeds up the code, because mathmatically the largest possible factor is the sqrt of the prime number, so all numbers after can be ignored
						{
							remainder = 0;
							divider = prime;
						}

						if (remainder != 0) // this is so that if the remainder is not 0, then the divider increases and repeats this loop until 0 is reached
						{
						    divider++;
						}

				}
				while ((remainder != 0 || prime != divider) && composite != 1); // De Morgan's law made this a tricky and confusing part to code

				composite = 0; // Resets composite number

				if (prime == divider && remainder == 0) // Checks if the number is prime, if yes it prints it and then returns the line
				{
						printf("%i ", prime);
						counter++;
				}

				divider = 2; // This resets the divider number for each prime (variable) number

		}

		printf("\n");
}
