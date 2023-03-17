#include "cachelab.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct Cache {
	uint32_t hit;
	uint32_t miss;
	uint32_t eviction;
};

struct Parameter {
	uint32_t num_of_set_idx;
	uint32_t associ;
	uint32_t num_of_block_bit;
	char trace_file[64];
};

static struct Parameter para;

int parse_arg(int argc, char *argv[])
{
	for (int i = 1; i < argc; ++i) {
		if (!strcmp(argv[i], "-s")) {
			para.num_of_set_idx = atoi(argv[++i]);
		} else if (!strcmp(argv[i], "-E")) {
			para.associ = atoi(argv[++i]);
		} else if (!strcmp(argv[i], "-b")) {
			para.num_of_block_bit = atoi(argv[++i]);
		} else if (!strcmp(argv[i], "-t")) {
			i++;
			memcpy(para.trace_file, argv[i], strlen(argv[i]));
		} else {
			printf("no such argument %s\n", argv[i]);
		}
	}
	return 0;
}

void print_arg()
{
	printf("associ %d\n", para.associ);
	printf("para.num_of_block_bit %d\n", para.num_of_block_bit);
	printf("para.num_of_set_idx %d\n", para.num_of_set_idx);
	printf("trace file %s\n", para.trace_file);
}

int main(int argc, char *argv[])
{
	// printSummary(0, 0, 0);
	parse_arg(argc, argv);
	print_arg();
	return 0;
}
