/*
 * progress_bar.h
 *
 * @info: To display the status of any task in the form of
 * progress bar. It will look like this-
 * 
 * 	Read burst starting ...
 *	[Read burst ######################################################## 100%]
 *
 *  Created on: Mar 5, 2014
 *
 */

#ifndef PROGRESS_BAR_H_
#define PROGRESS_BAR_H_


/*
 * Initialize progress bar parameters
 *
 * @aName: Name of the progress bar
 * @aTotalSize: Number of iteration needed to complete the task
 *
 * Returns:	0 -> Init Success
 * 			1 -> The progress bar is already initialized or still running
 */
extern unsigned int progress_bar_init(const char* aName, int aTotalSize);

/*
 * Print the status as progress bar after @current_size iteration.
 *
 * @current_size: iteration number
 */
extern void progress_bar(int current_size);

#endif /* PROGRESS_BAR_H_ */
