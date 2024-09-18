
# This makefile is used as follows to regenerate files for the coffee shop program:
#   make register     --  Regenerates the executable register file by compiling
#
register: coffee_shop.o register.o
	gcc -g -Wall coffee_shop.o register.o -lm -o ./register

	
