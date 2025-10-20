#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int main(int argc, char **argv) {
	// Check n of arguments (moulinette probably tries this first)
	if (argc != 4)
		return 1;

	// Get parameters (maybe add validation?)
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	int iters = atoi(argv[3]);

	// Create and fill grid with spaces
	char grid[height][width];
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++)
			grid[y][x] = ' ';
	}

	// Draw the thing from stdin instructions
	char c;
	int xp, yp = 0;
	bool drawing = false;
	while(read(0, &c, 1) > 0) {
		if (c == 'w')
			yp--;
		else if (c == 's')
			yp++;
		else if (c == 'a')
			xp--; 
		else if (c == 'd')
			xp++;
		else if (c == 'x')
			drawing = !drawing;
		else if (c == '\n')
			break;
		else
			return 1;
		if (yp < 0 || yp >= height || xp < 0 || xp >= width)
			return 1;
		if (drawing)
			grid[yp][xp] = '0';
	}

	// Starting iterations
	char new_grid[height][width];
	for (int i = 0; i < iters; i++) {
		// Iterate each cell
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				// Check around each cell how many are alive
				int n_alive = 0;
				for (int dy = -1; dy < 2; dy++) {
					for (int dx = -1; dx < 2; dx++) {
						// Neighbor x, y, position
						int ny = y + dy;
						int nx = x + dx;
						// If we are not in own cell and inside the grid
						// and cell we are checking is alive
						if (!(ny == y && nx == x)
								&& ny >= 0 && ny < height
								&& nx >= 0 && nx < width
								&& grid[ny][nx] == '0')
							n_alive++;
					}
				}
				// MAIN ALGORITHM: 
				// If cell is dead and there are 3 alive neighbors near it, it revives.
				// If its alive and there are 2-3 neighbors stays alive
				// Else it dies or stays dead
				if (n_alive == 3 || (grid[y][x] == '0' && n_alive == 2))
					new_grid[y][x] = '0';
				else
					new_grid[y][x] = ' ';
			}
		}
		// Put new grid into grid (we dont care about new_arr contents anymore)
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++)
				grid[y][x] = new_grid[y][x];
		}
	}

	// Print the grid
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++)
			write(1, &grid[y][x], 1);
		write(1, "\n" ,1);
	}
	return 0;
}
