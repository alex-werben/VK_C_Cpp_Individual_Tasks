check:
	./linters/run.sh

clean:
	rm -rf build

build:
	cmake -B build; cmake --build build

rebuild:
	rm -rf build; cmake -B build; cmake --build build

run:
	./build/main