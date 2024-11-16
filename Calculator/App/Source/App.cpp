#include <bits/stdc++.h>

using namespace std;

void Log(const string& message)
{
	cout << message << '\n' << endl;
}

void Log(const int& message){
	Log(to_string(message));
}

void Log(const double& message){
	Log(to_string(message));
}


void Log(const float& message){
	Log(to_string(message));
}


void Log(){
	Log("\n");
}



int main()
{

	Log("###Welcome in my calculator###");
	bool quit = false;
	do {

		reset:
		Log("First number:");
			double a;

			std::cin >> a;

			Log("Second number:");
			double b;

			std::cin >> b;

			const int OPERATIONS_COUNT = 4;
			char operations[OPERATIONS_COUNT] = {'+', '-', '*', '/'};


			int  operation = -1;
			double result;

			do  {

				Log("Pick the operation: ");
				for (int i = 0; i < OPERATIONS_COUNT; i++) {
					std::cout << i << ". " << operations[i]  << std::endl;
				}

				std::cin >> operation;

				switch(operations[operation]) {
				case '+':
					result = a + b;
					break;
				case '-':
					result = a - b;
					break;
				case '*':
					result = a * b;
					break;
				case '/':
					if (b <= 0.0){
						Log("Division by zero is not supported!");
						goto reset;
					}

					result = a / b;
					break;
				default:
					Log("Incorrect value!");
					operation = -1;
					break;
				}
			} while(operation == -1);

			Log("The result is: ");
			Log(result);

			Log("New round ? [y/N]");
			char q;
			std::cin >> q;

			quit = q != 'y' && q != 'Y';

			if(quit){
				Log("Bye!");
				return 0;
			}

	} while(!quit);
}
