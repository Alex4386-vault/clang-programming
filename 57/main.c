#include <stdio.h>
#include <stdlib.h>
#include "schedule.h"

// global variables
int tick = 0;

int main(int argc, char* argv[])
{
	if (argc < 3) {
		printf("[usage] ./run [file_name] [scheduling_method]\n");
		return 0;
	}

	// set scheduling method
	set_schedule(atoi(argv[2]));
	// set processes
	read_proc_list(argv[1]);

	while(1){
		int res = do_schedule(tick);
		if (res < 0 || tick > 50) break;
		printf("[tick:%04d] CPU is allocated to process No.%02d\n", tick, res);
		tick++;
	}
	print_performance();

	return 0;

}



