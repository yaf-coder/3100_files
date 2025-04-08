#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//TODO
//Implement the below function
//Simulate one particle moving n steps in random directions
//Use a random number generator to decide which way to go at every step
//When the particle stops at a final location, use the memory pointed to by grid to 
//record the number of particles that stop at this final location
//Feel free to declare, implement and use other functions when needed

void one_particle(int *grid, int n)
{
	int x = 0, y = 0, z = 0;
	for (int _ = 0; _ < n; _++){
        int r = rand() % 6;
        if (r == 0)
            x--;
        else if (r == 1)
            x++;
        else if (r == 2)
            y--;
        else if (r == 3)
            y++;
        else if (r == 4)
            z--;
        else if (r == 5)
            z++;
    }
	int size = 2 * n + 1;
    int index = (x + n) * size * size + (y + n) * size + (z + n);
    grid[index]++;
}

//TODO
//Implement the following function
//This function returns the fraction of particles that lie within the distance
//r*n from the origin (including particles exactly r*n away)
//The distance used here is Euclidean distance
//Note: you will not have access to math.h when submitting on Mimir
double density(int *grid, int n, double r)
{
	int size = 2*n+1;
    long total = 0;
    long inside = 0;
    double limit_sq = (r * n) * (r * n);
	
	for (int x = -n; x <= n; x++){
        for (int y = -n; y <= n; y++){
            for (int z = -n; z <= n; z++){
                int count = grid[(x+n) * size * size + (y+n) * size + z+n];
                total += count;
                int dist_sq = x*x + y*y + z*z;
                if (dist_sq <= limit_sq){
                    inside += count;
                }
            }
        }
    }
	return (double) inside / total;
}

//use this function to print results
void print_result(int *grid, int n)
{
    printf("radius density\n");
    for(int k = 1; k <= 20; k++)
    {
        printf("%.2lf   %lf\n", 0.05*k, density(grid, n, 0.05*k));
    }
}

//TODO
//Finish the following function
//See the assignment decription on Piazza for more details
void diffusion(int n, int m)
{
	int size = 2*n+1;
    int totalCells = size*size*size;
    int *grid = (int *) calloc(totalCells, sizeof(int));
    
	for(int i = 1; i<=m; i++) one_particle(grid, n);

	print_result(grid, n);
	free(grid);
}

int main(int argc, char *argv[])
{
	
	if(argc != 3)
	{
		printf("Usage: %s n m\n", argv[0]);
		return 0; 
	}
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	assert(n >= 1 && n <=50);
	assert(m >= 1 && m <= 1000000);
	srand(12345);
	diffusion(n, m);
	return 0;
}
