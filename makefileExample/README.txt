In this directory, you will find two make files: Makefile and MakefileWithCycle. Use them to test
your Make project. I have a target called clean so that you can remove and recreate targets.

1. MakefileWithCycle
   This make file has a cycle. When you run your solution with this make file, it should detect the
   cycle and print a message to that effect and stop.

2. Makefile
   Use this one to test your solution. The idea is to use this make file so you can test your
   solution against the make command. The output of both, your solution and the make command should
   be identical. The following show a few examples. You run these examples at a Linux/Unix shell
   prompt. We have used %% for the shell prompt. Lines that do not begin with the prompt are output
   lines. You should call the target of your make file make.x so that when you make your project, it
   places the executable in make.x. Therefore, in what follows, ./make.x refers to your solution.


%% make clean
rm -f wheat dinner salad garden-salad fruit-salad bread lunch cereal beakfast daily-meals salad
%% make
touch wheat
touch cereal
touch breakfast
touch bread
touch fruit-salad
touch lunch
touch garden-salad
touch dinner
touch salad
touch daily-meals
%% make clean
rm -f wheat dinner salad garden-salad fruit-salad bread lunch cereal beakfast daily-meals salad
%% ./make.x Makefile  # your output is expected to match that of the make command.
touch wheat
touch cereal
touch breakfast
touch bread
touch fruit-salad
touch lunch
touch garden-salad
touch dinner
touch salad
touch daily-meals
%% make
make: `daily-meals' is up to date.
%% ./make.x Makefile
./make.x: 'daily-meals' is up to date.
%% touch garden-salad
%% make
touch dinner
touch salad
touch daily-meals
%% touch garden-salad
%% ./make.x Makefile
touch dinner
touch salad
touch daily-meals
%% touch wheat
%% make
touch cereal
touch breakfast
touch bread
touch lunch
touch dinner
touch daily-meals
%% touch wheat
%% ./make.x Makefile
touch cereal
touch breakfast
touch bread
touch lunch
touch dinner
touch daily-meals
%% make clean
rm -f wheat dinner salad garden-salad fruit-salad bread lunch cereal beakfast daily-meals salad
%% make
touch wheat
touch cereal
touch breakfast
touch bread
touch fruit-salad
touch lunch
touch garden-salad
touch dinner
touch salad
touch daily-meals
%% make clean
rm -f wheat dinner salad garden-salad fruit-salad bread lunch cereal beakfast daily-meals salad
%% ./make.x Makefile
touch wheat
touch cereal
touch breakfast
touch bread
touch fruit-salad
touch lunch
touch garden-salad
touch dinner
touch salad
touch daily-meals
