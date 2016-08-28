CPP_FLAGS=-O2 -Wall -std=c++11 -L/usr/X11R6/lib -lm -lpthread -lX11

render: bin/render

bin/render: bin/main.o bin/Colors.o bin/Shapes.o bin/Light.o bin/Ray.o bin/Scene.o
	clang++ -o bin/render $(CPP_FLAGS) bin/main.o bin/Colors.o bin/Shapes.o bin/Light.o bin/Ray.o bin/Scene.o

bin/main.o: src/main.cpp src/Vector.h src/Shapes.h src/Light.h src/Ray.h src/Vector.h src/Scene.h src/CImg.h
	clang++ -o bin/main.o -c $(CPP_FLAGS) src/main.cpp

bin/Colors.o: src/Colors.h src/Vector.h src/Colors.cpp
	clang++ -o bin/Colors.o -c $(CPP_FLAGS) src/Colors.cpp

bin/Shapes.o: src/Shapes.h src/Shapes.cpp
	clang++ -o bin/Shapes.o -c $(CPP_FLAGS) src/Shapes.cpp

bin/Light.o: src/Light.h src/Light.cpp
	clang++ -o bin/Light.o -c $(CPP_FLAGS) src/Light.cpp

bin/Ray.o: src/Ray.h src/Ray.cpp
	clang++ -o bin/Ray.o -c $(CPP_FLAGS) src/Ray.cpp

bin/Scene.o: src/Scene.h src/Scene.cpp
	clang++ -o bin/Scene.o -c $(CPP_FLAGS) src/Scene.cpp
