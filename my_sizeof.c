#include <stdio.h>

typedef enum {
	INT = 1,
	CHAR,
	FLOAT,
	DOUBLE,
}DATA_TYPE;

unsigned int size_of(void *ptr, DATA_TYPE type, unsigned short count)
{
	int *intPtr = NULL;
	char *chrPtr = NULL;
	float *fltPtr = NULL;
	double *dblPtr = NULL;
	unsigned int size = 0;

	switch(type)
	{
		case INT:
		{
			intPtr = (int *)ptr;
			size = ((char *)(intPtr+1)) - ((char *)intPtr);
		}
		break;
		case CHAR:
		{
			chrPtr = (char *)ptr;
			size = ((char *)(chrPtr+1)) - ((char *)chrPtr);
		}
		break;
		case FLOAT:
		{
			fltPtr = (float *)ptr;
			size = ((char *)(fltPtr+1)) - ((char *)fltPtr);
		}
		break;
		case DOUBLE:
		{
			dblPtr = (double *)ptr;
			size = ((char *)(dblPtr+1)) - ((char *)dblPtr);
		}
		break;
		default:
			printf("Undefined Datatype '%d' received\n", type);
	}

	if(count)
		return (size * count);
	else
		return size;
}

int main(int argc, char **argv)
{
	char opt;
	int i = 0;
	char c = 'a';
	float f = 3.14;
	double d = 123.456;

	while(opt != '0')
	{
		printf("Choose one of the following Datatype to know its size\n"
			"1.Integer, 2.Char, 3.Float, 4.Double, 5.Float array[4], 6.Double array[3] and 0.Exit\n");
		scanf(" %c", &opt);
		switch(opt)
		{
			case '1':
				printf("Size of Interger = %u\n", size_of(&i, INT, 0));
			break;
			case '2':
				printf("Size of Char = %u\n", size_of(&c, CHAR, 0));
			break;
			case '3':
				printf("Size of Float = %u\n", size_of(&f, FLOAT, 0));
			break;
			case '4':
				printf("Size of Double = %u\n", size_of(&d, DOUBLE, 0));
			break;
			case '5':
				printf("Size of Float arr[4] = %u\n", size_of(&f, FLOAT, 4));
			break;
			case '6':
				printf("Size of Double arr[3] = %u\n", size_of(&d, DOUBLE, 3));
			break;
			case '0':
				printf("Exiting from program\n");
			break;
			default:
				printf("Invalid option. Please choose correct one\n");
		}
	}
	return 0;
}
