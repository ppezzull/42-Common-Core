#include "../includes/philo.h"

int is_numeric(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] < '0' || str[i] > '9')
      return (0);
    i++;
  }
  return (1);
}

void fail(char *error_msg)
{
  printf("\x1b[31m%s\n", error_msg);
  printf("\x1b[0mThese are the parameters:\n");
  printf("-number_of_philosophers \n");
  printf("-time_to_die \n");
  printf("-time_to_eat\n");
  printf("-time_to_sleep\n");
  printf("-[number_of_times_each_philosopher_must_eat]\n");
  exit(EXIT_FAILURE);
}

void check_input(int argc, char **argv)
{
  int i;

  if (argc > 6)
    fail("Too Many Arguments!");
  if (argc < 5)
    fail("Too Few Arguments!");
  i = 1;
  while (i < argc)
  {
    if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < 0)
      fail("Values out of range!");
    if (is_numeric(argv[i]) == 0)
      fail("You need to put numeric values!");
    i++;
  }
}