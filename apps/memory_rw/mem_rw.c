/*
 * mem_rw.c
 *
 * @Info: Functions to read/write from/to any location in memory (/dev/mem)
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <stdint.h>

/*
 * Error Codes
 */
#define ERR_MEM_DEV_OPEN		(unsigned int) 1
#define ERR_MEM_DEV_MMAP		(unsigned int) 2


#define MAP_SIZE	4096UL
#define MAP_MASK (MAP_SIZE - 1)


static inline uint8_t read8(volatile void *addr)
{
	return *(volatile uint8_t*) addr;
}

static inline void write8(volatile void *addr, uint8_t b)
{
	*(volatile uint8_t*) addr = b;
}

static inline uint16_t read16(volatile void *addr)
{
	return *(volatile uint16_t*) addr;
}

static inline void write16(volatile void *addr, uint16_t b)
{
	*(volatile uint16_t*) addr = b;
}

static inline uint32_t read32(volatile void *addr)
{
	return *(volatile uint32_t*) addr;
}

static inline void write32(volatile void *addr, uint32_t b)
{
	*(volatile uint32_t*) addr = b;
}


/*
 * Read 32-bit value from a location specified by target
 */
unsigned int read_mem32(off_t target, uint32_t* val)
{
	int fd;
	void *map_base, *virt_addr;

	fd = open("/dev/mem", O_RDWR | O_SYNC);
	if( fd < 0 )
		return ERR_MEM_DEV_OPEN;

	map_base = mmap(0, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, target & ~MAP_MASK);
	if (map_base == (void *) -1)
		return ERR_MEM_DEV_MMAP;

	virt_addr = map_base + (target & MAP_MASK);

	*val = read32(virt_addr);

	munmap(map_base, MAP_SIZE);
	close(fd);
	return 0;
}

/*
 * Read 16-bit value from a location specified by target
 */
unsigned int read_mem16(off_t target, uint16_t* val)
{
	int fd;
	void *map_base, *virt_addr;

	fd = open("/dev/mem", O_RDWR | O_SYNC);
	if( fd < 0 )
		return ERR_MEM_DEV_OPEN;

	map_base = mmap(0, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, target & ~MAP_MASK);
	if (map_base == (void *) -1)
		return ERR_MEM_DEV_MMAP;

	virt_addr = map_base + (target & MAP_MASK);

	*val = read16(virt_addr);

	munmap(map_base, MAP_SIZE);
	close(fd);
	return 0;
}

/*
 * Read 8-bit value from a location specified by target
 */
unsigned int read_mem8(off_t target, uint8_t* val)
{
	int fd;
	void *map_base, *virt_addr;

	fd = open("/dev/mem", O_RDWR | O_SYNC);
	if( fd < 0 )
		return ERR_MEM_DEV_OPEN;

	map_base = mmap(0, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, target & ~MAP_MASK);
	if (map_base == (void *) -1)
		return ERR_MEM_DEV_MMAP;

	virt_addr = map_base + (target & MAP_MASK);

	*val = read8(virt_addr);

	munmap(map_base, MAP_SIZE);
	close(fd);
	return 0;
}


/*
 *  Write 32-bit value to a location specified by target
 */
unsigned int write_mem32(off_t target, uint32_t val)
{
	int fd;
	void *map_base, *virt_addr;

	fd = open("/dev/mem", O_RDWR | O_SYNC);
	if( fd < 0 )
		return ERR_MEM_DEV_OPEN;

	map_base = mmap(0, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, target & ~MAP_MASK);
	if (map_base == (void *) -1)
		return ERR_MEM_DEV_MMAP;

	virt_addr = map_base + (target & MAP_MASK);

	write32(virt_addr, val);

	munmap(map_base, MAP_SIZE);
	close(fd);
	return 0;
}

/*
 *  Write 16-bit value to a location specified by target
 */
unsigned int write_mem16(off_t target, uint16_t val)
{
	int fd;
	void *map_base, *virt_addr;

	fd = open("/dev/mem", O_RDWR | O_SYNC);
	if( fd < 0 )
		return ERR_MEM_DEV_OPEN;

	map_base = mmap(0, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, target & ~MAP_MASK);
	if (map_base == (void *) -1)
		return ERR_MEM_DEV_MMAP;

	virt_addr = map_base + (target & MAP_MASK);

	write16(virt_addr, val);

	munmap(map_base, MAP_SIZE);
	close(fd);
	return 0;
}

/*
 *  Write 8-bit value to a location specified by target
 */
unsigned int write_mem8(off_t target, uint8_t val)
{
	int fd;
	void *map_base, *virt_addr;

	fd = open("/dev/mem", O_RDWR | O_SYNC);
	if( fd < 0 )
		return ERR_MEM_DEV_OPEN;

	map_base = mmap(0, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, target & ~MAP_MASK);
	if (map_base == (void *) -1)
		return ERR_MEM_DEV_MMAP;

	virt_addr = map_base + (target & MAP_MASK);

	write8(virt_addr, val);

	munmap(map_base, MAP_SIZE);
	close(fd);
	return 0;
}
