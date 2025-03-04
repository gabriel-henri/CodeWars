/*
Complete the method/function so that it converts dash/underscore delimited words 
into camel casing. The first word within the output should be capitalized only if
the original word was capitalized (known as Upper Camel Case, also often referred 
to as Pascal case). The next words should be always capitalized.

Examples
"the-stealth-warrior" gets converted to "theStealthWarrior"

"The_Stealth_Warrior" gets converted to "TheStealthWarrior"

"The_Stealth-Warrior" gets converted to "TheStealthWarrior"
*/

#include <string>
#include <vector>
#include <cctype>
#include <regex>

std::vector<std::string> separates_by_space(const std::string& text){
  std::vector<std::string> words;
  std::regex regex("[-_]+");
  
  std::sregex_token_iterator it(text.begin(), text.end(), regex, -1);
  std::sregex_token_iterator end;
  
  for(; it != end; ++it){
    words.push_back(*it);
  }
  
  return words;
}


std::string to_camel_case(std::string text) {
  std::vector<std::string> words = separates_by_space(text);
  std::string newText;
  newText.reserve(text.size());
  
  bool isFirstWord = true;
  for(std::string& word : words){
    if(isFirstWord){
      for(char letter : word){
        if(std::isalpha(letter)){
          newText += letter;
        }
      }
      isFirstWord = false;
    }else{
      
      bool isFirstLetter = true;
      
      for(char letter : word){
        if(std::isalpha(letter)){
          if(isFirstLetter){
            newText += std::toupper(letter);
            isFirstLetter = false;
          }else{
            newText += letter;
          }
        
        }
      }
    }
  }
  
  return newText;
}