#########################################
#				My Makefile				#
#########################################

# GCC = /mnt/d/MCU_Modeling/mcu/common/appl/gcc/gcc-6.2.0_mbd/bin/g++

GCC = g++

main:
	$(GCC) -o ouput main.cpp
	./ouput
	rm -rf ouput

struct_vector:
	$(GCC) -o ouput struct_vector.cpp -I ./
	./ouput
	rm -rf ouput

serial: serial.o SerialStream.o SerialStreamBuf.o PosixSignalDispatcher.o SerialPort.o
	$(GCC) serial.o SerialStream.o SerialStreamBuf.o PosixSignalDispatcher.o SerialPort.o -o ouput

serial.o: serial.cpp
	$(GCC) -c serial.cpp -I ./

SerialStream.o:
	$(GCC) -c SerialStream.cc -I ./

SerialPort.o:
	$(GCC) -c SerialPort.cpp -I ./

SerialStreamBuf.o:
	$(GCC) -c SerialStreamBuf.cc -I ./

PosixSignalDispatcher.o:
	$(GCC) -c PosixSignalDispatcher.cpp -I ./

run:
	./ouput
	
clean:
	rm -rf ouput
	rm -rf *.o