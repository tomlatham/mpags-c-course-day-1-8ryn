#include <iostream>
#include <string>
int main(){
  char in_char{'x'};
  std::string output{""};

  // Loop until the user
  // presses Enter then Ctrl+D
  while(std::cin >> in_char)
    {

      //Ensures any alphanmeric input is capitalised and adds to output
      if(isalpha(in_char))
        {
          output += std::toupper(in_char);
        }
      //Converts any numbers and spaces and discards any other characters
      else{
        switch (in_char){
        case '0':
          output += "ZERO ";
          break;

        case '1':
          output += "ONE ";
          break;

        case '2':
          output += "TWO ";
          break;

        case '3':
          output += "THREE ";
          break;

        case '4':
          output += "FOUR ";
          break;
	    
	case '5':
	  output += "FIVE ";
	  break;
	  
	case '6':
	  output += "SIX ";
	  break;
	  
	case '7':
	  output += "SEVEN ";
	  break;
	  
	case '8':
	  output += "EIGHT ";
	  break;
	  
	case '9':
	  output += "NINE ";
	  break;

        default:
          break;

        }


      }
    }
  std::cout << output << std::endl;
}

