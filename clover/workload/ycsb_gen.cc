// Your First C++ Program

#include <iostream>
#include <inttypes.h>
#include <assert.h>

#define READ 0
#define WRITE 1
#define YCSB_NAME_SIZE 256


enum workload
{
    ycsb_a = 0,
    ycsb_b = 1,
    ycsb_c = 2,
};

const static char *ycsb_str[] = {"a", "b", "c"};

enum distribution
{
    uniform_random = 0,
};

const static char *dist_str[] = {"Uniform Random"};

char ycsb_string[256];
int global_threads = 8;
workload global_workload = ycsb_b;
distribution global_distribution = uniform_random;
int global_keyspace_size = 100000;

int debug = 0;

int get_operation(workload wl)
{
    int op;
    switch (wl)
    {
    case ycsb_a:
        //50% write
        if ((rand() % 100) > 50)
        {
            op = WRITE;
        }
        else
        {
            op = READ;
        }
        break;
    case ycsb_b:
        //5% write
        if ((rand() % 100) > 95)
        {
            op = WRITE;
        }
        else
        {
            op = READ;
        }
        break;
    case ycsb_c:
        op = READ;
        break;
    default:
        fprintf(stderr, "Unimplemented ycsb workload %d", (int)wl);
        exit(EXIT_FAILURE);
        break;
    }
    return op;
}

uint64_t get_key(distribution dist, int size)
{
    uint64_t key;
    switch (dist)
    {
    case uniform_random:
        key = rand() % size;
        break;
    default:
        fprintf(stderr, "Unimplemented ycsb distribution %d", (int)dist);
        exit(EXIT_FAILURE);
        break;
    }
    return key;
}

int write_workload(const char *filename, int size, workload wl, distribution dist)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Unable to open file %s exiting\n", filename);
        exit(EXIT_FAILURE);
    }

    int op;
    uint64_t key;

    printf("Writing to file: %s\n", filename);
    for (int i = 0; i < size; i++)
    {
        op = get_operation(wl);
        key = get_key(dist, size);
        if (debug)
        {
            printf("Op:%d Key:%" PRIu64 "\n", op, key);
        }
        fprintf(fp, "%d %" PRIu64 "\n", op, key);
    }

    fclose(fp);
    return 0;
}

void set_filename(char *ycsb_string, workload wl, int thread_num)
{
    assert(ycsb_string);
    sprintf(ycsb_string, "ycsb/workload%s_%d", ycsb_str[wl], thread_num);
    return;
}

int write_thread_workload(int thread_count, int size, workload wl, distribution dist)
{
    for (int i = 0; i < thread_count; i++)
    {
        set_filename((char *)ycsb_string, ycsb_b, i);
        write_workload(ycsb_string, size, wl, dist);
    }
}

int main()
{
    printf(
        "Workload Generation Description\n"
        "Threads:        %d\n"
        "Workload:       YCSB-%s\n"
        "Distribution:   %s\n"
        "Key Space       %d\n",
        global_threads,
        ycsb_str[global_workload],
        dist_str[global_distribution],
        global_keyspace_size);

    write_thread_workload(global_threads, global_keyspace_size, global_workload, global_distribution);
    return EXIT_SUCCESS;
}