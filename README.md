# Philosophers 🍝
This project is about learning how to use threads and mutexes in C.   

## Overview 🚀

In this simulation, one or more philosophers sit around a table, with a large bowl of spaghetti in the center. There are as many forks on the table as there are philosophers, right next to each of them.
However, for a philosopher to eat, they need two forks, meaning they will have to share forks. The philosophers alternatively eat, sleep, and think, in this order. 
While they are doing one of these actions, they cannot do another, and they do not communicate with each other. The simulation continues until a philosopher dies of starvation, or until each philosopher has eaten at least a specified number of meals.

## Getting Started 🛠️

To get started, clone this repository to your local machine.

```bash
git clone https://github.com/damachad/42_philosophers.git
cd 42_philosophers/philo
```

## Usage 📝
Run the program with the appropriate arguments to set the number of philosophers and various time parameters.

```bash
./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
### Arguments
- number_of_philosophers: The number of philosophers.
- time_to_die: Time (in milliseconds) until a philosopher dies if they have not started eating or since the beginning of the simulation.
- time_to_eat: Time (in milliseconds) it takes for a philosopher to eat.
- time_to_sleep: Time (in milliseconds) a philosopher spends sleeping.
- number_of_times_each_philosopher_must_eat (optional): The number of times each philosopher must eat before the simulation stops.
Example
```bash
./philosophers 5 800 200 200
```
This command simulates 5 philosophers, with a time_to_die of 800ms, time_to_eat of 200ms, and time_to_sleep of 200ms.

Each philosopher has a number ranging from 1 to number_of_philosophers. Philosopher number 1 sits next to philosopher number number_of_philosophers.
Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.   
The output is formatted as follows:
```
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
```
timestamp_in_ms is the current timestamp in milliseconds and X is the philosopher number.

## Rules ✅
- Each philosopher should be a thread.
- Global variables are forbidden.
- A displayed state message should not be mixed up with another message.
- A message announcing a philosopher died should be displayed no more than 10ms after the actual death of the philosopher.
- Each fork should have its own mutex.
- The program must not have data races.
- Philosophers should avoid dying.

### Allowed external functions:
```
memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
```

