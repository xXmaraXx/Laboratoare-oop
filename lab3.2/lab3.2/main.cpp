#include "Canvas.h"
#include <iostream>

int main()
{
	Canvas canvas(30, 30);
	int choice;

	do {
		std::cout << "Choose a shape to draw: \n";
		std::cout << "1. Circle outline\n";
		std::cout << "2. Circle\n";
		std::cout << "3. Rectangle outline\n";
		std::cout << "4. Rectangle\n";
		std::cout << "5. Line\n";
		std::cout << "6. Exit\n";

		std::cin >> choice;

		switch(choice) {
		case 1:
			canvas.DrawCircle(20, 20, 10, '*');
			canvas.Print();
			canvas.Clear();
			break;

		case 2:
			canvas.FillCircle(20, 20, 8, '@');
			canvas.Print();
			canvas.Clear();
			break;

		case 3:
			canvas.DrawRect(10, 10, 17, 18, '#');
			canvas.Print();
			canvas.Clear();
			break;

		case 4:
			canvas.FillRect(12, 2, 18, 8, '$');
			canvas.Print();
			canvas.Clear();
			break;

		case 5:
			canvas.DrawLine(19, 0, 0, 0, '_');
			canvas.Print();
			canvas.Clear();
			break;

		case 6:
			std::cout << "Press ENTER to exit the program!";
			break;

		default:
			std::cout << "Invalid choice. Please try again!\n";
			std::cout << "\n";
			break;

		}

	} while (choice != 6);

	return 0;
}