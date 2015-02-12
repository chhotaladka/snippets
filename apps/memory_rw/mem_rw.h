/*
 * mem_rw.h
 *
 * @Info: Functions to read/write from/to any location in memory (/dev/mem)
 *
 */

#ifndef MEM_RW_H_
#define MEM_RW_H_

#include <sys/types.h>
#include <stdint.h>


/*
 * Read 32-bit value from a location specified by target
 */
extern unsigned int read_mem32(off_t target, uint32_t* val);

/*
 * Read 16-bit value from a location specified by target
 */
extern unsigned int read_mem16(off_t target, uint16_t* val);

/*
 * Read 8-bit value from a location specified by target
 */
extern unsigned int read_mem8(off_t target, uint8_t* val);

/*
 *  Write 32-bit value to a location specified by target
 */
extern unsigned int write_mem32(off_t target, uint32_t val);

/*
 *  Write 16-bit value to a location specified by target
 */
extern unsigned int write_mem16(off_t target, uint16_t val);

/*
 *  Write 8-bit value to a location specified by target
 */
extern unsigned int write_mem8(off_t target, uint8_t val);


#endif /* MEM_RW_H_ */
