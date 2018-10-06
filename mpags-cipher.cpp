#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
  //Puts command line arguments into a vector
  const std::vector<std::string> cmdLineArgs { argv, argv+argc };
  
  if(cmdLineArgs[1] == "-h" || cmdLineArgs[1] == "--help"){
    std::cout << "Usage: mpags-cipher numbers" << std::endl;
    std::cout << "Currently this program will print your arguments capitalised and convert numbers to text"
	      << std::endl;
    return 0;
  }
  
  std::string output{""};

  // Loops over each command line string
  for(int i{1}; i<argc ; i++)
    {
      std::string argument{cmdLineArgs[i]};
      for(int j{0}; j<argument.size(); j++)
	{
	  /*This allows the programme to continue to work with minimal changes.
	    If aiming to be as efficent as possible making this a pointer would 
	    probably save some memory */
	  char in_char{argument[j]}; 
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
    }
  std::cout << output << std::endl;
}
