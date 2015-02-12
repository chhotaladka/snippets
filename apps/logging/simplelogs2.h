/*
 * simplelogs2.h
 *
 * @Info: To manage the logs
 *
 */

#ifndef	DEBUG_H_
#define DEBUG_H_

/*
 * System Include
 */
#ifdef __KERNEL__
#include <linux/kernel.h>

#else
#include <stdio.h>
#endif /* __KERNEL__ */


/* Comment the following to disable the debug prints */
//#define DEBUG

/*
 * Name of the module (used as the print prefix)
 * TODO: Change here for new module
 */
#define MODULE_NAME		"logging"

#ifdef __KERNEL__
#define PRINT(fmt, args...) \
		do {				\
			printk("["MODULE_NAME"] " fmt, ##args);\
		} while (0)

#else
#define PRINT(fmt, args...) \
		do {				\
			printf("["MODULE_NAME"] " fmt, ##args);\
		} while (0)

#endif /* __KERNEL__ */

/* Printing DEBUG message */
#ifdef DEBUG
#define DBG(fmt, args...) \
            do { PRINT("%s: " fmt, __func__, ## args); } while (0)
#else
#define DBG(fmt, args...) \
			do { } while (0)
#endif  /* DEBUG */

/* Printing INFO message */
#define INFO(fmt, args...) \
            do { PRINT(fmt, ## args); } while (0)

/* Printing ERROR message */
#define ERR(fmt, args...) \
            do { PRINT("%s: <Error> " fmt, __func__, ## args); } while (0)

/* Printing Warning message */
#define WARN(fmt, args...) \
            do { PRINT("%s: <Warning> " fmt, __func__, ## args); } while (0)


#endif /* DEBUG_H_ */
