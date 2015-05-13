all: align.o Output.o Input.o Sequence.o Matrix.o Score.o Traceback.o NeedlemanWunsch.o
	g++ align.o Output.o Input.o Sequence.o Matrix.o Score.o Traceback.o NeedlemanWunsch.o -o align

align.o: align.cpp
	g++ -c -o align.o align.cpp

Input.o: Input.cpp
	g++ -c -o Input.o Input.cpp;

Output.o: Output.cpp
	g++ -c -o Output.o Output.cpp; 

NeedlemanWunsch.o: NeedlemanWunsch.cpp
	g++ -c -o NeedlemanWunsch.o NeedlemanWunsch.cpp;

Traceback.o: Traceback.cpp
	g++ -c -o Traceback.o Traceback.cpp;

Score.o: Score.cpp
	g++ -c -o Score.o Score.cpp; 

Matrix.o: Matrix.cpp
	g++ -c -o Matrix.o Matrix.cpp;   

Sequence.o: Sequence.cpp
	g++ -c -o Sequence.o Sequence.cpp;       

clean:
	rm -rf *.o hello