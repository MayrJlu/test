// test -m 12:34:56:AB:CD:EF
#include <stdio.h>
#include <string.h>
#include <stdint.h>


int main(int argc, char **argv)
{
	if(argc <= 1)
	{
		printf("syntax : \n\t%s --help or\n\t./p -m [12:34:56:AB:CD:EF]\n", argv[0]);
		return 2;
	}
	if(!strcmp(argv[1], "--help"))
	{
		printf("You requested help message.\n");
		return 2;
	}
	if(!strcmp(argv[1], "-s"))
	{
		printf("-s argument returns 1.\n");
		return(1);
	}
	else if(!strcmp(argv[1], "-m"))
	{
		if(argc <= 2 || argc > 4)
		{
			printf("'-m' operation requires one parameter.\n");
			return 2;
		}
		else
		{
			if( strlen(argv[2]) == 17)
			{
				static int counter = 0;
				static int byte_counter = 0;
				//printf("length is ok\n");
				for(int i = 0; i < 17; i++)
				{
					if ((uint8_t)argv[2][i] >= 0x30 && (uint8_t)argv[2][i] <=  0x3A)
					{
						if ((uint8_t)argv[2][i] == 0x3A)
						{
							if (counter == 2)
							{
								//printf("simbol%c\n", argv[2][i]); 
								byte_counter++;
								counter = 0;
							}
							else
							{
								printf("ERROR%c\n", argv[2][i]); 
								return (2);
							}
						}
						else
						{
							//printf("number%c\n", argv[2][i]); 
							//printf("counter%i\n", counter); 
							byte_counter++;
							counter++;
						}
					}
					else if ((uint8_t)argv[2][i] >=  0x41 && (uint8_t)argv[2][i] <=  0x5A)
					{
						//printf("big liter%c\n", argv[2][i]); 
						//printf("counter%i\n", counter); 
						byte_counter++;
						counter++;
					}
					else if ((uint8_t)argv[2][i] >=  0x61 && (uint8_t)argv[2][i] <=  0x7A)
					{
						//printf("small liter%c\n", argv[2][i]); 
						//printf("counter%i\n", counter); 
						byte_counter++;
						counter++;
					}
					else
					{
						printf("ERROR\n");
						return 2;
					}
				}
				//printf("%i\n", byte_counter);
				if (byte_counter == 17)
				{
					printf("CORRECT\n");
					return (0);
				}
			}
			else
			{
				printf("ERROR\n");
				return 2;
			}
		}
	}
	else
	{
		printf("Unknown parameter: '%s'. Type %s --help for help.\n", argv[1], argv[0]);
		return 2;
	}
}
