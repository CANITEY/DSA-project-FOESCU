build:
	g++ main.cpp doctors.cpp patients.cpp

run: build
	./a.out
