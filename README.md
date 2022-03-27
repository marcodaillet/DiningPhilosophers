# Philosophers

This project is a common computing problem known as the dining philosophers problem.
There is x philosophers around a tabled who do three distincts activities : eat, think and sleep.
There is x forks, one by philosopher. While doing any action, a philosopher doesn't do the other two.
To eat, a philosopher needs two forks, which put restrictions on the number of philosophers able to eat at the same time.

The goal of this project is simple, we have to keep all the philosophers alive, and they have to do cycles of their three activities.
To solve this problem, I used threads, one per philosophers, and mutexes, one per fork. This to make sure that no fork was used by multiples philosophers at the same time.

It was a very interesting project to learn more about multi-processes programation and how to lock and unlock key variables.

The parameters of this program:  
  --> nb_of_philosophers : the number of philosophers around the table.  
  --> time_to_die : the limit delay between two meals for a philosopher to die.  
  --> time_to_eat : the delay for a philosopher to eat.  
  --> time_to_sleep : the delay for a philosopher to sleep.  
  --> nb_of_meals_before_exit : an optionnal argument fixing a number of meals after which the philosophers will be satisfied.  

To use :
  ./philo nb_of_philosophers time_to_die time_to_eat time_to_sleep [optionnal] nb_of_meals_before_exit

![philo](https://user-images.githubusercontent.com/55747965/147947208-d7889ffa-5646-4ad0-858f-c917ced87ba9.gif)
