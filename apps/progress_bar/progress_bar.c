/*
 * progress_bar.c
 *
 * @info: To display the status of any task in the form of
 * progress bar. It will look like this-
 * 
 * 	Read burst starting ...
 *	[Read burst ######################################################## 100%]
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* progress_string;
static const int screen_width = 60;
static int max_size = 0;
static int resolution = 0;

/*
 * Initialize progress bar parameters
 *
 * @aName: Name of the progress bar
 * @aTotalSize: Number of iteration needed to complete the task
 *
 * Returns:	0 -> Init Success
 * 			1 -> The progress bar is already initialized or still running
 */
unsigned int progress_bar_init(const char* aName, int aTotalSize)
{
	if (progress_string == NULL) {
		progress_string = (char*) malloc(strlen(aName));
		strcpy(progress_string, aName);
		max_size = aTotalSize;
		printf("%s starting ...\n\n", progress_string);

		if (max_size >= 100)
			resolution = aTotalSize / 100; // 1%
		else
			resolution = (aTotalSize % 100 ) / 10;

		return 0;
	}

	return 1;
}


/*
 * Print the status as progress bar after @current_size iteration.
 *
 * @current_size: iteration number
 */
void progress_bar(int current_size)
{
	if (progress_string == NULL) {
		printf("Please initialize the progress bar, exiting!!!\n");
		return;
	}
	// Check if the current size is in resolution
	int check = (max_size - current_size) % resolution;
	if (check != 0)
		return;


	// Calculate the ratio of complete-to-incomplete.
	float ratio = current_size / (float) max_size;
	int c = ratio * (screen_width - 4);

	// ANSI Control codes to go back to the previous line and clear it.
	printf("\033[A\033[K");

	// Show the percentage complete.
	printf("\033[32m[%s ", progress_string);

	// Show the load bar.
	int x = 0;
	for (x = 0; x < c; x++)
		printf("#");
	for (x = c; x <= screen_width - 4; x++)
		printf(" ");
	printf("%3d%%]\033[0m\n", (int) (ratio * 100));
	if (current_size == max_size) {
		free(progress_string);
		progress_string = NULL;
	}

	return;
}
