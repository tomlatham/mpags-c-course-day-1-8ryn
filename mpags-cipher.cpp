#include <iostream>
#include <string>
#include <vector>


int main(int argc, char* argv[])
{
  const std::string vNum = "0.2.1";

  //Puts command line arguments into a vector
  const std::vector<std::string> cmdLineArgs { argv, argv+argc };

  bool helpRequested{false};
  bool versionRequested{false};
  std::string input_file{""};
  std::string output_file{""};

  for(int i{1}; i<argc ; i++){
    const std::string &argument = cmdLineArgs[i];

    if(argument == "-h" || argument == "--help"){
      helpRequested = true;
    }
    else if(argument == "--version"){
      versionRequested = true;
    }
    else if(argument == "-i"){
      if(++i < argc){
	input_file = cmdLineArgs[i];
      }
      else{
	std::cout << "Error: No input file provided after \"-i\"" << std::endl;
	return 1;
      }
    }
    else if(argument == "-o"){
      if(++i < argc){
	output_file = cmdLineArgs[i];
      }
      else{
	std::cout << "Error: No output file provided after \"-o\"" << std::endl;
	return 1;
      }
    }
    else{
      std::cout << "Argument " << i << " \"" << argument << "\" is invalid." << std::endl;
      return 1;
    }
  }

  if ( helpRequested ) {
    std::cout
      << "Usage: mpags-cipher [options] \n"
      << "Options: \n"
      << "-h   Display this information \n"
      << "--help Display this information \n"
      << "-i   The following argument will be used as the input file \n"
      << "-o   The following argument will be used as the output file \n"
      << "--version   Prints the current program version\n\n"
      << "Currently this program will print any alphanumeric text capitalised and convert numbers to text.\n"
      << "Text entry continues until CTRL + D is pressed.\n"
      << std::endl;
    return 0;
  }

  if ( versionRequested ) {
    std::cout << "Version number = " << vNum << std::endl;
    return 0;
  }

  if ( ! input_file.empty() ) {
    std::cout << "[warning] input from file not yet implemented, using standard input instead.\nRequested input file = " << input_file << std::endl;
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

  if ( ! output_file.empty() ) {
    std::cout << "[warning] output to file not yet implemented, using standard output instead.\nRequested output file = " << output_file << std::endl;
  }

  std::cout << output << std::endl;
}
