compile-all:
	g++ driver.cpp -c
	g++ WorkPay.cpp -c
	g++ Simulation.cpp -c
	g++ driver.o WorkPay.o Simulation.o -o infinity.out
compile-simulation:
	g++ Simulation.cpp -c
compile-workpay:
	g++ WorkPay.cpp -c 
run:
	./infinity.out
clean:
	rm *.o
	rm *.out

