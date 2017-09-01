#include "Header.h"

void welcome_screen(void)
{
	int end = 0, option = 0, press = 0, size = 0, target = 0, target_index = 0;
	int list[100] = { 0 };
	char destination[30] = { '\0' }, source[30] = { '\0' };
	char *dest_ptr = &destination, *src_ptr = &source;
	char word[20] = { '\0' };
	int left = 0, right = 4;
	int result = 0;
	do {
		do
		{
			printf("1. Option 1\n");
			printf("2. Option 2\n");
			printf("3. Option 3\n");
			scanf("%d", &option);
			system("cls");
		} while ((option < 1) || (option > 3));

		switch (option)
		{
		case 1: // my_str_n_copy
			printf("Enter what we will be copying.\n");
			scanf("%s", src_ptr);
			my_str_n_copy(dest_ptr, src_ptr);
			printf("Copied String: %s\n", dest_ptr);
			break;
		case 2: // binary search
			printf("How long will the list be in which we're looking?\n");
			scanf("%d", &size);
			for (int i = 0; i < size; i++)
			{
				list[i] = i;
			}
			printf("What is the target we are looking for?\n");
			scanf("%d", &target);
			target_index = binary_search(list, target, size);
			printf("The target is at location %d\n", target_index);
			break;
		case 3: // palindrome
				printf("Please enter a word in order to\n");
				printf("determine if it is a palindrome.\n");
				scanf("%s", &word);
				int length = strlen(word);

				result = palindrome(left, length - 1, word);

				if (result == 1)
				{
				printf("it is a palindrome\n");
				}
				else if (result == 0)
				{
				printf("it is not a palindrome\n");
				}
				
			break;
		default: // catch all would execute if the other cases are not matched
			break;
		}
	} while (end != 1);
}

void my_str_n_copy(char *dest_ptr, char *src_ptr)
{
	int number = 0, i = 0;
	printf("How many characters do we plan on copying from the source?\n");
	scanf("%d", &number);

	while ((i != number) && (*src_ptr != '\0'))
	{
		*dest_ptr = *src_ptr;
		dest_ptr++;
		src_ptr++;
		i++;
	}
	
}

int binary_search(int list[], int target, int size)
{
	int left = 1, right = size, found = 0;
	int index = -1, mid = (left + right) / 2;

	while ((found == 0) && (left <= right))
	{
		if (list[mid] == target)
		{
			found = 1;
			index = mid;
		}
		else if (list[mid] > target)
		{
			right = mid - 1;
		}
		else if (list[mid] < target)
		{
			left = mid + 1;
		}
		
	}
	return index;
}

int palindrome(int left, int right, char array[])
{
	//If check = 0, not palindrome. If check = 1, palindrome
	int check = 0;
	if (array[left] == array[right])
	{
		check = 1;
	}

	else
	{
		check = 0;
	}

	if (left < right)
	{
		check = palindrome(left + 1, right - 1, array);
	}

	return check;
}