# Dining Philosophers Problem

This project addresses the classic computing problem known as the Dining Philosophers Problem. In this scenario, a group of philosophers sits around a table, engaging in three distinct activities: eating, thinking, and sleeping. Each philosopher requires two forks to eat, which introduces constraints on the number of philosophers who can eat simultaneously.

## Objective
The goal of this project is to ensure the survival of all philosophers while they cycle through their activities. To tackle this problem, I implemented a solution using threads, with one thread per philosopher, and mutexes, with one mutex per fork. This approach ensures that no fork is used by multiple philosophers simultaneously, preventing deadlock or resource contention.

## Key Learnings
This project provided an excellent opportunity to delve into multi-process programming concepts and practice working with thread synchronization mechanisms such as mutexes. By developing this solution, I gained valuable insights into managing concurrent processes and understanding the importance of locking and unlocking critical resources.

## Program Parameters
- `nb_of_philosophers`: Number of philosophers around the table.
- `time_to_die`: Maximum delay between two meals for a philosopher to survive.
- `time_to_eat`: Time taken for a philosopher to complete a meal.
- `time_to_sleep`: Duration of sleep for a philosopher.
- `nb_of_meals_before_exit` (Optional): Number of meals after which the philosophers will exit the simulation.

## Usage
To run the program, use the following command:
```
./philo nb_of_philosophers time_to_die time_to_eat time_to_sleep [nb_of_meals_before_exit]
```
