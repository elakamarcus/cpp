/**
 * Euler 035, fast c++
 */
#include <iostream>
#include <cstring>

const int MAX_DIGITS35 = 6;
bool IsPrime35(int n)
{
	if (n % 2 == 0)
		return (n == 2);

	for (int d = 3; d * d <= n; d += 2)
		if (n % d == 0)
			return false;

	return true;
}

int NextDigit35(int d) //d mustn't be 9
{
	if (d != 3)
		return d + 2;
	else
		return 5;
}

int DigitsToNum35(int digits[], int len)
{
	int n = 0;
	
	for (int i = 0; i < len; i++)
	{
		n *= 10;
		n += digits[i];
	}

	return n;
}

bool IsCyclicPrime35(int original_digits[], int len)
{
	int digits[MAX_DIGITS35];
	memcpy(digits, original_digits, len * sizeof(int));

	int rotation_count = 0;

	while (IsPrime35(DigitsToNum35(digits, len)))
	{
		//Check whether we got back to the first number
		if (rotation_count == len - 1)
			return true;

		//Rotate
		int last_digit = digits[len - 1];

		for (int i = (len - 1); i > 0; i--)
			digits[i] = digits[i - 1];
		digits[0] = last_digit;

		rotation_count++;
	}

	return false; //One of the variations was not prime!
}

void Problem35()
{
	int final_count = 0;
	int digits[MAX_DIGITS35];

	for (int digit_count = 1; digit_count <= MAX_DIGITS35; digit_count++)
	{
		for (int i = 0; i < digit_count; i++)
			digits[i] = 1;

		while (true)
		{
			if (IsCyclicPrime35(digits, digit_count))
				final_count++;
    
			int nine_count = 0;
			while ((digits[nine_count] == 9) && (nine_count != digit_count))
				nine_count++;

			if (nine_count == digit_count)
				break; //That's it for this digit_count

			digits[nine_count] = NextDigit35(digits[nine_count]);
			for (int i = 0; i < nine_count; i++)
				digits[i] = 1;
		}
	}
	std::cout << final_count << std::endl;
}

int main(){
    Problem35();
}