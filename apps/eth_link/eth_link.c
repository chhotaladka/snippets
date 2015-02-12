/*
 * eth_link.c
 *
 * @Info: To monitor the Ethernet Link 
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/ethtool.h>
#include <linux/sockios.h>
#include <time.h>


#define LINK_DOWN	0
#define LINK_UP		1
#define LINK_ERR	2

unsigned int prv_status;

/*
 * Detect link status using ethtool ioctl call
 */
static int detect_link(int skfd, char *ifname)
{
	struct ifreq ifr;
	struct ethtool_value edata;
	
	memset(&ifr, 0, sizeof(ifr));
	edata.cmd = ETHTOOL_GLINK;

	strncpy(ifr.ifr_name, ifname, sizeof(ifr.ifr_name)-1);
	ifr.ifr_data = (char *) &edata;
                                                                                
	if (ioctl(skfd, SIOCETHTOOL, &ifr) == -1) {
		printf("Error: ETHTOOL_GLINK ioctl failed < %s (%d) >\n", strerror(errno), errno);
		if (errno == EBUSY)
			return LINK_ERR;
		else
			exit(-1);
	}
                                                                                
	return (edata.data ? LINK_UP : LINK_DOWN);
}

/*
 * Read the link status of the ethernet interface 'ifname'
 */
int get_link_status(char *ifname)
{
	int skfd = -1;
	int retval;

	if ((skfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		printf("Error: failed to open socket < %s >\n", strerror(errno));
		exit(-1);
	}

	retval = detect_link(skfd, ifname);
	close(skfd);

	return retval;
}

/*
 * Display usage of the application
 */
void display_usage(char *app_name)
{
        fprintf(stderr, "\nUsage: %s {interface}\n", app_name);
}

/*
 * Main
 */
int main(int argc, char **argv)
{
	int retval;
	char *ifname;

        if (argc < 2) {
		display_usage(argv[0]);
                exit(0);
        }

	ifname = (char *) malloc(strlen(argv[1]));
	strcpy(ifname, argv[1]);

	printf( "\n[%ld] Starting ethernet Link Monitoring of %s\n", time(NULL), ifname);

	/*
	 * Read and store initial state
	 */
	retval = get_link_status(ifname);
	if (retval == LINK_DOWN) {
		prv_status = LINK_DOWN;
		printf("[%ld] %s: Link is Down\n", time(NULL), ifname);
	}
	else if (retval == LINK_UP) {
		prv_status = LINK_UP;
		printf("[%ld] %s: Link is Up\n", time(NULL), ifname);
	}
	else if (retval == 2) {
		printf("[%ld] %s: Error: Could not determine link status\n", time(NULL), ifname);
	}


	/*
	 * Start Polling
	 */
	while(1) {
		retval = get_link_status(ifname);
		if (retval == LINK_DOWN) {
			if (prv_status != LINK_DOWN) 
				printf("[%ld] %s: Link is Down\n", time(NULL), ifname);
			prv_status = LINK_DOWN;

		} else	if (retval == LINK_UP) {
			if (prv_status != LINK_UP)
				printf("[%ld] %s: Link is Up\n", time(NULL), ifname);
			prv_status = LINK_UP;
		} else {
                	printf("[%ld] %s: Error: Could not determine link status\n", time(NULL), ifname);
		}
		usleep(100);
	}

	return 0;
}
