## Measurement Methodology
I've captured the tick value at the begining and at the end of each separated function and also in their globality. (clock to clock\_t)

I've substracted begining to end in order to get the number of ticks it took for each function analyzed then converted it in seconds for it to be human-readable. (clock\_t to CLOCKS\_PER\_SEC)

Float is used to be precise (6 decimals here) as this code runs in so much less time than 1 second.


## Observed Performance Differences
By simplifying how the code is runned, from Naive to Single-pass, I've noticed that performances are +31000 times faster.

Expanding it to make it more meaningful, it means that the job previously done in 3.5 years is now done in 1 hour.


## Relation Between Runtime and Energy Consumption
The longer the task takes to be executed, the higher the consumption is, at least in terms of time.


## Limitations of the Experiment
This experiment could be way more meaningful by running way more datas for the difference of performance to be expressed in minutes or even hours rather than milli-seconds.

There's also a lack of information of how much the machine consumes itself. It could become more precise regarding where the economies are made exactly and in regards of what exactly.

Having a machine with better performance could also reduce the running time of a task but it needs to be compared to how much the machine really consumes.

A less performant machine could use more time to run code but consuming less at the end than a more performant machine craving for more energy basis.

The conception of the machine itself must be involved, how long did it take in R&D, what resources were used and in what quantity to make it a concrete physical tool etc...

As long as every parameters are not mesured, the experimentation remains incomplete. To be more precise we would also need:

\- real consumption basis of the machine used

\- the machine itself needs resources to be build so at what point the machine would be paid for itself compared to another

\- the internet connection may have an incidence too if the code calls external datas

\- and so on...


## Practical Engineering Takeaway
More than just ensuring a good result, we need to code smart to save resources as much as possible. Especially nowadays, where reducing environmental footprint is made by small gesturess of everyday life.

But for more precise and meaningful results, experimentations must included way more parameters in order to be as exhaustive as possible.

