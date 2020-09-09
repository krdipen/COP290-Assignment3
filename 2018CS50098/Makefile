all:
	@gcc -c add.c
	@gcc -c sub.c
	@gcc -c mul.c
	@gcc -c div.c
	@gcc -c abs.c
	@gcc -c pow.c
	@gcc -c sqrt.c
	@gcc -c mainfile.c
	@gcc *.o -o mainfile
	@./mainfile input.txt output.txt
	@rm mainfile
	@rm *.o
