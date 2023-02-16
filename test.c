#include<stdio.h>
#include<unistd.h>

int	check_id(int id[3], int i)
{
	while (i >= 0)
	{
		if (!id[i])
			return (0);
		i--;
	}
	return (1);
}


int main()
{
	int id[3];

	int i = 0;
	while (i < 3)
	{
		id[i] = fork();
		if (check_id(id, i))
			dprintf(1, "test\n");
		i++;
	}
}