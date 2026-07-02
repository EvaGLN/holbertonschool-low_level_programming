## Measurement Methodology

1) Baseline loop

By running the same amount of iterations 3 times, the performance of the CPU has been measured by revealing its execution time for each try.

2) Comparison algorithms

For the same result at the end, we have ran three times an executable designed to compare two ways of writing code, one more efficient than the other: the nested loop (naive) and the single loop (single).

3) Instrumentation lab

We have analyzed the execution time of global code (TOTAL) and its separated steps (BUILD\_DATA, PROCESS, REDUCE) in order to reveal the most time consuming ones that could lead to performances resolutions.

For this complex experimentation, the tick value at the begining and at the end of each section analyzed have been captured (clock to clock\_t).

Begining value has been subtracted to ending value for each section then converted in seconds for it to be human-readable (clock\t to CLOCKS\_PER\_SEC).

## Observed Performance Differences

1) Baseline loop

Results show a minor difference between the 3 execution times:

    Minimum: 0.063545 seconds

    Maximum: 0.070049 seconds

    Average: 0.066206 seconds

2) Comparison algorithms

Results here left no doubts that the way of writing code have a huge impact on performances, no matter the fact it has been ran three times:

    Naive:

        Minimum: 0.879670 seconds

        Maximum: 0.885650 seconds

        Average: 0.882176 seconds

    Single:

        Minimum, maximum and average: less than 0.000029 seconds (as we have revealed only 6 decimals and the systems truncated to 0.000028 everytime, we can assume that values were between 0.000028 and 0.000029 seconds.)

The average execution time for nested loop (naive) is 31506.285714 times slower than for the single loop (single).

3) Instrumentation lab

Sadly, the results can't prove anything as each one were showing 0.000000 seconds.

This can be explained by the fact the performance of the hardware itself influences execution time of programs.

What is certain is that the global section (TOTAL), which contains every separated step (BUILD\_DATA, PROCESS, REDUCE) is higher than each separated one and equal to all combined.

## Relation Between Runtime and Energy Consumption

The higher the execution time is, the longer the CPU is activated. The longer the CPU is activated, the longer it consumes energy (hardware on, cooler on etc...).

## Limitations of the Experiment

This experiment could be way more meaningful by running way more datas for the difference of performance to be expressed in minutes or even hours rather than milli-seconds.

There's also a lack of information of how much the hardware consumes itself. It could become more precise regarding where the economies are made exactly and in regards of what exactly.

A less performant machine could use more time to run code but consuming less at the end than a more performant machine craving for more energy basis.

The conception of the machine itself must be involved, how long did it take in R&D, what resources and their quantity were used to make it a concrete physical tool etc...

## Practical Engineering Takeaway

More than just ensuring a good result, we need to code smart to save resources as much as possible. Especially nowadays, where reducing environmental footprint is made by small gestures of everyday life.

But for more precise and meaningful results, experimentations must include way more parameters in order to be as exhaustive as possible and reduce assumptions.
