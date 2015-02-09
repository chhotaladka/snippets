#ifndef SIMPLELOGS_H_
#define SIMPLELOGS_H_

/* Move this include to your master include file */
#include <assert.h>

#ifdef I_WANT_TO_DEBUG
#define PRINT_ARG(a) printf a
#define TRACE_INFO(arg) 																\
	do{																				    \
	printf("\n\e[1;32mINFO\t%20s\t\e[0m%5d  %30s  ", __FILE__ , __LINE__, __func__); \
	printf arg;																		    \
	printf("\n");																		\
	fflush(stdout);																		\
	}while(0)

/***************************************************************************/
/* Tracing functions.													   */
/***************************************************************************/
#define TRACE_ERROR(arg) 																\
	do{																					\
	printf("\n\e[0;31mERROR\t%20s\t\e[0m%5d  %30s  ", __FILE__ , __LINE__, __func__);\
	printf arg;																			\
	printf("\n");																		\
	fflush(stdout);																		\
	}while(0)

#define TRACE_WARN(arg) 																\
	do{																					\
	printf("\n\e[1;33mWARN\t%20s\t\e[0m%5d  %30s  ", __FILE__ , __LINE__, __func__); \
	printf arg;																			\
	printf("\n");																		\
	fflush(stdout);																		\
	}while(0)
/***************************************************************************/
/* arg must be passed as double bracketed value						   	   */
/***************************************************************************/
#define TRACE_DETAIL(arg) 																\
	do{																					\
	printf("\n\e[1;34mDETAIL\t%20s\t\e[0m%5d  %30s\t", __FILE__,__LINE__, __func__); \
	printf arg;																			\
	printf("\n");																		\
	fflush(stdout);																		\
	}while(0)

#define TRACE_ASSERT(arg)	assert(arg)

#define TRACE_ENTRY()																	\
	do{																					\
	printf("\n\e[1;34mENTER\t%20s\t\e[0m%5d  %30s  ", __FILE__ , __LINE__, __func__);\
	printf ("{");																		\
	printf("\n");																		\
	fflush(stdout);																		\
	}while(0)
#define TRACE_EXIT()																	\
	do{																					\
	printf("\n\e[1;34mEXIT\t%20s\t\e[0m%5d  %30s  ", __FILE__ , __LINE__, __func__); \
	printf ("}");																		\
	printf("\n");																		\
	fflush(stdout);																		\
	}while(0)
#define TRACE_LOG_ERROR(arg)															\
	{																					\
	TRACE_ERROR(arg);																	\
	TRACE_ERROR(("System returned : %d",errno));										\
	}
#else
#define PRINT_ARG(a)
#define TRACE_INFO(arg)
#define TRACE_ERROR(arg)
#define TRACE_WARN(arg)
#define TRACE_DETAIL(arg)
#define TRACE_ASSERT(arg)
#define TRACE_ENTRY()
#define TRACE_EXIT()
#define TRACE_LOG_ERROR()
#endif


#endif /* SIMPLELOGS_H_ */
