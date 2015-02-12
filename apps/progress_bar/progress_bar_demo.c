/*
 * progress_bar_demo.c
 *
 * @info: Demo application for progress bar usage
 *
 */

#include <stdio.h>
#include "progress_bar.h"

int main()
{
	int i;

	/*
	 * For example the operation name is "demo" and
	 * total number of iteration is 100 to complete the operation
	 */
	progress_bar_init("demo", 100);

	for (i = 1; i <= 100; i++) {
		progress_bar(i);

		/* Do your operation here */
		usleep(10000);
	}

	return 0;
}
