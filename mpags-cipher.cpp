#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
  //Puts command line arguments into a vector
  const std::vector<std::string> cmdLineArgs { argv, argv+argc };
  if(argc>1){
    if(cmdLineArgs[1] == "-h" || cmdLineArgs[1] == "--help"){
      std::cout << "Usage: mpags-cipher " << std::endl;
      std::cout << "Currently this program will print any alphanumeric text capitalised and convert numbers to text. Text entry continues until CTRL + D is pressed. The program also prints any arguments passed to the program."
		<< std::endl;
    }
    for(int i{1}; i<argc; i++){
      std::cout << cmdLineArgs[i] << std::endl;

    }
  }


  //This is the main functionality of the program
  std::string output{""};
  char in_char{'x'};
  while(std::cin >> in_char)
    {
      //Ensures any alphanmeric input is capitalised and adds to output
      if(isalpha(in_char))
	{
	  output += std::toupper(in_char);
	}
      //Converts any numbers to strings and discards any other characters
      else{
	switch (in_char){
	case '0':
	  output += "ZERO";
	  break;

	case '1':
	  output += "ONE";
	  break;

	case '2':
	  output += "TWO";
	  break;

	case '3':
	  output += "THREE";
	  break;

	case '4':
	  output += "FOUR";
	  break;

	case '5':
	  output += "FIVE";
	  break;

	case '6':
	  output += "SIX";
	  break;

	case '7':
	  output += "SEVEN";
	  break;

	case '8':
	  output += "EIGHT";
	  break;

	case '9':
	  output += "NINE";
	  break;

	default:
	  break;

	}
      }

      
    }
  std::cout << output << std::endl;
}
