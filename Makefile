CPP_FLAGS=-O2 -Wall -std=c++11

render: bin/render

bin/render: bin/main.o bin/colors.o bin/shapes.o bin/light.o bin/ray.o bin/scene.o
	clang++ -o bin/render $(CPP_FLAGS)  -L/usr/X11R6/lib -lm -lpthread -lX11 bin/main.o bin/colors.o bin/shapes.o bin/light.o bin/ray.o bin/scene.o

bin/main.o: src/main.cpp src/vector.h src/shapes.h src/light.h src/ray.h src/vector.h src/scene.h external/CImg.h
	clang++ -o bin/main.o -c $(CPP_FLAGS) src/main.cpp

bin/colors.o: src/colors.h src/vector.h src/colors.cpp
	clang++ -o bin/colors.o -c $(CPP_FLAGS) src/colors.cpp

bin/shapes.o: src/shapes.h src/shapes.cpp
	clang++ -o bin/shapes.o -c $(CPP_FLAGS) src/shapes.cpp

bin/light.o: src/light.h src/light.cpp
	clang++ -o bin/light.o -c $(CPP_FLAGS) src/light.cpp

bin/ray.o: src/ray.h src/ray.cpp
	clang++ -o bin/ray.o -c $(CPP_FLAGS) src/ray.cpp

bin/scene.o: src/scene.h src/scene.cpp
	clang++ -o bin/scene.o -c $(CPP_FLAGS) src/scene.cpp