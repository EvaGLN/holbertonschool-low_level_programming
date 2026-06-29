#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
    *state = (*state * 1103515245u) + 12345u;
    return *state;
}

static void build_dataset(void)
{
    unsigned int state;
    int i;

    state = SEED_VALUE;

    for (i = 0; i < DATASET_SIZE; i++)
        dataset[i] = (int)(next_value(&state) % 100000);
 }

static void process_dataset(void)
{
    int i;
    int v;

    for (i = 0; i < DATASET_SIZE; i++)
    {
        v = dataset[i];
        v = (v * 3) + (v / 7) - (v % 11);
        if (v < 0)
            v = -v;
        dataset[i] = v;
    }
}

static unsigned long reduce_checksum(void)
{
    unsigned long sum;
    int i;

    sum = 0;
    for (i = 0; i < DATASET_SIZE; i++)
        sum = (sum * 131ul) + (unsigned long)dataset[i];

    return sum;
}

int main(void)
{
	clock_t begin_total, end_total, begin_build, end_build;
	clock_t begin_process, end_process, begin_reduce, end_reduce;
	float second_total, second_build, second_process, second_reduce;
    unsigned long checksum;

    /* Students must add clock-based timing and print required lines. */

    begin_total = clock();

    begin_build = clock();
    build_dataset();
    end_build = clock();

    begin_process = clock();
    process_dataset();
    end_process = clock();

    begin_reduce = clock();
    checksum = reduce_checksum();
    end_reduce = clock();

    end_total = clock();

    if (checksum == 0ul)
        printf("impossible\n");

    /* Required output (exact format, no extra lines):
     * TOTAL seconds: <float>
     * BUILD_DATA seconds: <float>
     * PROCESS seconds: <float>
     * REDUCE seconds: <float>
     */

    second_total = (end_total - begin_total) / CLOCKS_PER_SEC;
    second_build = (end_build - begin_build) / CLOCKS_PER_SEC;
    second_process = (end_process - begin_process) / CLOCKS_PER_SEC;
    second_reduce = (end_reduce - begin_reduce) / CLOCKS_PER_SEC;

    printf("TOTAL seconds: %.6f\n", second_total);
    printf("BUILD_DATA seconds: %.6f\n", second_build);
    printf("PROCESS seconds: %.6f\n", second_process);
    printf("REDUCE seconds: %.6f\n", second_reduce);

    return 0;
}
