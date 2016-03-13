#include "Rectangle.h"
namespace engine{
	/*Defult that initializes everything to 0*/
	Rectangle::Rectangle(){
		x = y = w = h = 0;
	}

	/*Rectangle constructor which initializes the values of x and y position, and width and height*/
	Rectangle::Rectangle(int x_value, int y_value, int width, int height){
		x = x_value; y = y_value; w = width; h = height;
	}

}