
#ifndef MITSUME_BENCHMARK
#define MITSUME_BENCHMARK

//macro magic
#define DO_EXPAND(VAL)  VAL ## 1
#define EXPAND(VAL)     DO_EXPAND(VAL)

#include "mitsume.h"
#include "mitsume_tool.h"

#include <atomic>
#include <mutex>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int mitsume_benchmark(struct mitsume_ctx_clt *local_ctx_clt);
const static char MITSUME_YCSB_WORKLOAD_A_STRING[] =
    "workload/ycsb/workloada_%d";
const static char MITSUME_YCSB_WORKLOAD_B_STRING[] =
    "workload/ycsb/workloadb_%d";
const static char MITSUME_YCSB_WORKLOAD_C_STRING[] =
    "workload/ycsb/workloadc_%d";

const static char MITSUME_YCSB_WORKLOAD_STRING[] =
    "workload/ycsb/workload%s_%s_%d";

#define MITSUME_BENCHMARK_WORKLOAD_NAME_LEN 256
#define MITSUME_YCSB_SIZE 1000000
#define MITSUME_YCSB_MODE_A 50
#define MITSUME_YCSB_MODE_B 5
#define MITSUME_YCSB_MODE_C 0
/*
#ifdef MITSUME_YCSB_OP_MODE
    #if MITSUME_YCSB_OP_MODE == ""
        #undef MITSUME_YCSB_OP_MODE
    #endif
#endif
#ifndef MITSUME_YCSB_OP_MODE
    #define MITSUME_YCSB_OP_MODE MITSUME_YCSB_MODE_C
#endif
*/
#if !defined(MITSUME_YCSB_OP_MODE) || (EXPAND(MITSUME_YCSB_OP_MODE) == 1)
    //Only here if MYVARIABLE is not defined
    //OR MYVARIABLE is the empty string
    #undef MITSUME_YCSB_OP_MODE
    #define MITSUME_YCSB_OP_MODE MITSUME_YCSB_MODE_C
#endif
/*
#ifdef MITSUME_YCSB_KEY_RANGE
    #if MITSUME_YCSB_KEY_RANGE==""
        #undef MITSUME_YCSB_YCSB_KEY_RANGE
    #endif
#endif
#ifndef MITSUME_YCSB_KEY_RANGE
    #define MITSUME_YCSB_KEY_RANGE 100000
#endif
*/
#if !defined(MITSUME_YCSB_KEY_RANGE) || (EXPAND(MITSUME_YCSB_KEY_RANGE) == 1)
    //Only here if MYVARIABLE is not defined
    //OR MYVARIABLE is the empty string
    #undef MITSUME_YCSB_KEY_RANGE
    #define MITSUME_YCSB_KEY_RANGE 100
#endif

#define MITSUME_YCSB_DISTRIBUTION_MODE_UNIFORM 1
#define MITSUME_YCSB_DISTRIBUTION_MODE_ZIPF 2
#define MITSUME_YCSB_DISTRIBUTION_MODE MITSUME_YCSB_DISTRIBUTION_MODE_ZIPF

//#define MITSUME_YCSB_TEST_TIME 100000000
#define MITSUME_YCSB_TEST_TIME 100
#define MITSUME_YCSB_VERIFY_LEVEL 0

#define MITSUME_YCSB_COROUTINE 6
#define MITSUME_MASTER_COROUTINE 0

#define MITSUME_TEST_LOAD_WRITE_NUM 4
#define MITSUME_TEST_LOAD_READ_NUM 2
/*
#ifdef MITSUME_BENCHMARK_THREAD_NUM
    #if MITSUME_BENCHMARK_THREAD_NUM==""
        #undef MITSUME_BENCHMARK_THREAD_NUM
    #endif
#endif
#ifndef MITSUME_BENCHMARK_THREAD_NUM
    #define MITSUME_BENCHMARK_THREAD_NUM  8
#endif
*/
#if !defined(MITSUME_BENCHMARK_THREAD_NUM) || (EXPAND(MITSUME_BENCHMARK_THREAD_NUM) == 1)
    //Only here if MYVARIABLE is not defined
    //OR MYVARIABLE is the empty string
    #undef MITSUME_BENCHMARK_THREAD_NUM
    #define MITSUME_BENCHMARK_THREAD_NUM 1
#endif

#define MITSUME_BENCHMARK_REPLICATION           1
#define MITSUME_BENCHMARK_SIZE                  1000
#define MITSUME_BENCHMARK_TIME                  MITSUME_YCSB_TEST_TIME
#define MITSUME_BENCHMARK_RUN_TIME              10

#endif
