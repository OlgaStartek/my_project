# my_project
Olga Startek, Kraków czerwiec 2020
Projekt na zaliczenie kursu C++ rok akademicki 2019/20 (Informatyka Stosowana, WFAIS)

Opis: gra polega na klikaniu spadających obiektow, zanim przekroczą dół ekranu. W przypadku, gdy nie zdążymy, tracimy życie. 
Po stracie 10 żyć następuje koniec gry.

Projekt zawiera: główny program main.cpp, plik nagłówkowy game.h wraz z plikiem game.cpp gdzie są definicje funkcji,
folder z czcionką i folder z grafiką 
Wymagania: aby program poprawnie działał wymagana jest zainstalowana biblioteka SFML

Sposób uruchomienia:
-git clone https://github.com/OlgaStartek/my_project
-utworzyć projekt w visual studio
-w miejscu Projekt->Wlasciwosci->C/C++->Ogólne->Dodatkowe katalogi  wpisać  <sfml-install-path>/include 
-Konsolidator->Ogólne->Dodatkowe katalogi wpisać <sfml-install-path>/lib
-Konsolidator->Dane wejściowe (dla Release) dołączyć sfml-graphics-s.lib;sfml-system-s.lib;sfml-window-s.lib;sfml-audio-s.lib
-(a dla debug) sfml-graphics-d.lib;sfml-system-d.lib;sfml-window-d.lib;sfml-audio-d.lib
-(dla release) C/C++->Preprocesor->Definicje dopisać SFML_STATIC;
-Konsolidator->dane wejściowe->dodatkowe zależności->edytuj dopisać jeśli nie ma:
winmm.lib
opengl32.lib
freetype.lib
-W folderze projektu powinny się też znaleźć skopiowane pliki .dll dla odpowiedniego typu pochodzące z zainstalowanego
SFML\bin

//jest też plik makefile, jednak mi nie dziala, i nie jestem pewna dlaczego, dlatego również go dołączam, przepraszam za utrudnienia
oraz taką długą instrukcję
	

Zagadnienia:
1. Projekt obiektowy: 
- klasy:
	game.h : 15
- konstruktory, destruktory:
	game.h : 52, 54
- konstruktor kopiujący:
	game.h : 53
 
2. STL 
- szablony:
	game.h : 43
 
3. C++ 
- zakresowa pętla for:
	game.cpp : 186
- plik .h z deklaracja i .cpp z definicją metod:
	game.cpp i game.h
- linker

