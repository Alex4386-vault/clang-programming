
#ifndef __schedule_h__
#define __schedule_h__

// fn: read_proc_list
// desc: read process file list
// param
// 	file_name: process list name
void read_proc_list(const char* file_name);

// fn: set_schedule
// desc: set scheduling method
//
// param: method
// 	scheduling method
// 	1. FCFS (Nonpreemptive)
// 	2. Shortest Job First (Nonpreemptive)
// 	3. Shortest Remaining Time First (Prremptive)
//
// return none
void set_schedule(int method);

// fn: do_schedule
// desc: scheduling function called every tick from main
// param
// 	tick: time tick beginning from 0
// return
//     -1: when all process are terminated
//      0: CPU is idle
// others: PID od running state
int do_schedule(int tick);

// fn: print_performance();
// desc: print system performance
void print_performance();



#endif
