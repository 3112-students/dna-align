all: align.o Output.o Input.o Sequence.o Matrix.o Score.o Traceback.o NeedlemanWunsch.o
	c++ align.o Output.o Input.o Sequence.o Matrix.o Score.o Traceback.o NeedlemanWunsch.o -o align

align.o: align.cpp
	c++ -c -o align.o align.cpp

Input.o: Input.cpp
	c++ -c -o Input.o Input.cpp;

Output.o: Output.cpp
	c++ -c -o Output.o Output.cpp; 

NeedlemanWunsch.o: NeedlemanWunsch.cpp
	c++ -c -o NeedlemanWunsch.o NeedlemanWunsch.cpp;

Traceback.o: Traceback.cpp
	c++ -c -o Traceback.o Traceback.cpp;

Score.o: Score.cpp
	c++ -c -o Score.o Score.cpp; 

Matrix.o: Matrix.cpp
	c++ -c -o Matrix.o Matrix.cpp;   

Sequence.o: Sequence.cpp
	c++ -c -o Sequence.o Sequence.cpp;       

clean:
	rm -rf *.o hello