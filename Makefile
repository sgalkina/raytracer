CPP_FLAGS=-O2 -Wall -std=c++11

display: bin/render
	./bin/render
	mogrify -format png bin/image.ppm
	mv bin/image.png images/current.png

profile: bin/render
	sudo perf record -g ./bin/render
	sudo perf script > out.perf
	cd FlameGraph && sudo ./stackcollapse-perf.pl ../out.perf > ../out.folded
	cd FlameGraph && ./flamegraph.pl ../out.folded > ../kernel.svg
	mv kernel.svg images/kernel.svg
	rm out.*
	sudo rm perf.*

render: bin/render

bin/render: bin/main.o bin/colors.o bin/triangle.o bin/sphere.o bin/shapes.o bin/light.o bin/ray.o bin/scene.o
	clang++ -o bin/render $(CPP_FLAGS) bin/main.o bin/colors.o bin/triangle.o bin/sphere.o bin/shapes.o bin/light.o bin/ray.o bin/scene.o

bin/main.o: src/main.cpp src/vector.h src/triangle.h src/sphere.h src/shapes.h src/light.h src/ray.h src/vector.h src/scene.h
	clang++ -o bin/main.o -c $(CPP_FLAGS) src/main.cpp

bin/colors.o: src/colors.h src/vector.h src/colors.cpp
	clang++ -o bin/colors.o -c $(CPP_FLAGS) src/colors.cpp

bin/shapes.o: src/shapes.h src/shapes.cpp src/vector.h src/ray.h
	clang++ -o bin/shapes.o -c $(CPP_FLAGS) src/shapes.cpp

bin/triangle.o: src/triangle.h src/triangle.cpp src/shapes.h src/vector.h src/ray.h
	clang++ -o bin/triangle.o -c $(CPP_FLAGS) src/triangle.cpp

bin/sphere.o: src/sphere.h src/sphere.cpp src/shapes.h src/vector.h src/ray.h
	clang++ -o bin/sphere.o -c $(CPP_FLAGS) src/sphere.cpp

bin/light.o: src/light.h src/light.cpp src/vector.h src/colors.h
	clang++ -o bin/light.o -c $(CPP_FLAGS) src/light.cpp

bin/ray.o: src/ray.h src/ray.cpp src/vector.h
	clang++ -o bin/ray.o -c $(CPP_FLAGS) src/ray.cpp

bin/scene.o: src/scene.h src/scene.cpp src/colors.h src/ray.h src/vector.h src/shapes.h src/light.h
	clang++ -o bin/scene.o -c $(CPP_FLAGS) src/scene.cpp
