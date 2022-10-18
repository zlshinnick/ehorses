run_yifan:
	g++ horse.cpp comphorse_yifan.cpp racetrack.cpp userhorse.cpp user.cpp yifansDriver.cpp -o runy
	./runy

run_zach:
	g++ main.cpp user.cpp userhorse.cpp game.cpp horse.cpp  stable.cpp  shop.cpp item.cpp  market.cpp inventory.cpp bred_horse.cpp racetrack.cpp comphorse_yifan.cpp -o run_zachs
	./run_zachs

run_race:
	g++ -c raceGraphics.cpp -I"C:\SFML-2.5.1\include"
	g++ raceGraphics.o -o raceGraphics -L"C:\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
	./raceGraphics

run_test_graphics_yifan:
	g++ -c raceGraphics.cpp -I"C:\SFML-2.5.1\include"
	g++ raceGraphics.o main.cpp user.cpp userhorse.cpp game.cpp horse.cpp stable.h stable.cpp shop.h shop.cpp item.cpp market.h market.cpp inventory.h inventory.cpp bred_horse.cpp racetrack.cpp comphorse_yifan.cpp -o run_test -L"C:\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
	./run_test

run_test_graphics_zach:
	g++ -c raceGraphics.cpp -I"C:\Desktop\SFML-2.5.1-macos-clang\include"
	g++ raceGraphics.o main.cpp user.cpp userhorse.cpp game.cpp horse.cpp stable.cpp shop.cpp item.cpp market.cpp inventory.cpp bred_horse.cpp 
	racetrack.cpp comphorse_yifan.cpp -o run_test -L"C:\Desktop\SFML-2.5.1-macos-clang\lib" -lsfml-graphics -lsfml-window -lsfml-system
	./run_test

run_test_userhorse:
	g++ horse.cpp userhorse.cpp userhorse_driver.cpp -o test
	./test
