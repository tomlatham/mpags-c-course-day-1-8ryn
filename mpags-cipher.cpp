#include <iostream>
#include <string>
#include <vector>

const std::string helpMsg = "Usage: mpahs-cipher \n Currently this program will print any alphanumeric text capitalised and convert numbers to text. Text entry continu\
es until CTRL + D is pressed. The program also prints any arguments passed to the program.";
const std::string vNum = "0.2.0";

int main(int argc, char* argv[])
{
  //Puts command line arguments into a vector
  const std::vector<std::string> cmdLineArgs { argv, argv+argc };
  std::string input_file{"None"};
  std::string output_file{"None"};

  if(argc>1){
    for(int i{1}; i<argc ; i++){
      const std::string &argument = cmdLineArgs[i];
      
      if(argument == "-h" || argument == "--help"){
	std::cout << helpMsg << std::endl;
      }
      else if(argument == "--version"){
	std::cout << "Version number = " << vNum << std::endl;
      }
      else if(argument == "-i"){
	if(++i < argc){
	  input_file = cmdLineArgs[i];
	  std::cout << "Input file = " << input_file << std::endl;
	}
	else{
	  std::cout << "Error: No input file provided after \"-i\"" << std::endl;
	}
      }
      else if(argument == "-o"){
	if(++i < argc){
	  output_file = cmdLineArgs[i];
	  std::cout << "Output file = " << output_file << std::endl;
	}
	else{
	  std::cout << "Error: No output file provided after \"-o\"" << std::endl;
	}
      }
      else{
	std::cout << "Argument " << i << " \"" << argument << "\" is invalid." << std::endl;
      }
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
