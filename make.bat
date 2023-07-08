set SFML_DIR="c:/projects/SFML"
g++ -I%SFML_DIR%/include -I. -L%SFML_DIR%/lib linalg.cpp demo.cpp -o demo -lsfml-graphics -lsfml-window -lsfml-system