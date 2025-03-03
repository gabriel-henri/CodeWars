/*
Timed Reading is an educational tool used in many schools to improve and advance 
reading skills. A young elementary student has just finished his very first timed 
reading exercise.
Unfortunately he's not a very good reader yet, so whenever he encountered a word 
longer than maxLength, he simply skipped it and read on.

Help the teacher figure out how many words the boy has read by calculating 
the number of words in the text he has read, no longer than maxLength.

Formally, a word is a substring consisting of English letters, such that 
characters to the left of the leftmost letter and to the right of the 
rightmost letter are not letters.

Example
For maxLength = 4 and text = "The Fox asked the stork, 'How is the soup?'", the 
output should be 7

The boy has read the following words: "The", "Fox", "the", "How", "is", "the", 
"soup".

Input/Output
[input] integer maxLength

A positive integer, the maximum length of the word the boy can read.

Constraints: 1 ≤ maxLength ≤ 10.

[input] string text

A non-empty string of English letters and punctuation marks.

[output] an integer

The number of words the boy has read.


*/

#include <vector>
#include <sstream>
#include <string>
#include <cctype>
#include <chrono> // for some reason the codewars it was not acepting my code without this, even though I am not usgin it

std::vector<std::string> split(const std::string &text){
  std::vector<std::string> words;
  
  std::stringstream ss(text);
  std::string word;
  
  while(ss >> word){
    words.push_back(word);
  }
  
  return words;
}

int countLetters(const std::string &word){
  int count = 0;
  
  for(char letter : word){
    if(std::isalpha(letter)){
      count++;
    }
  }
  
  return count;
}

int timed_reading(int maxLength, const std::string &text)
{
  int readable = 0; 
  std::vector<std::string> words = split(text);
  
  for(const std::string& word : words){
    int lettersCounted = countLetters(word);
    if(lettersCounted <= maxLength && lettersCounted > 0){
      readable++;
    }
  }
  return readable;
}