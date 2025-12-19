.PHONY: all setup run clean

all:
	@meson compile -C build

setup:
	@meson setup build

run: all
	@./build/raytracer

clean:
	@rm -rf build
