#include <iostream>
#include <fstream>
#include <set>
#include <locale.h>

class Dictionary {
    private:
        std::string path;
        std::ifstream file;
        std::set <std::string> existsWord;
    public:
        Dictionary()
        {
            path = "10000_formas.TXT";
            file = std::ifstream(this->path, std::ifstream::in);
            setlocale(LC_ALL, "esp");
        }
        Dictionary(std::string path)
        {
            file = std::ifstream(path, std::ifstream::in);
        }
        void loadDictionary()
        {
            std::string current_line;
            int flag = 0;
            while(getline(file, current_line))
            {
                if(flag == 0)
                {
                    flag = 1;
                    continue;
                }
               int index = 0;
               while(current_line[index] < 'a' || current_line[index] > 'z') index++;
               std::string word;
               //std::cout << std::endl;
               while(current_line[index] != 9 && current_line[index] != 32)
               { 
                   word.push_back(current_line[index++]);        
               }
               std::cout << word << std::endl;
               existsWord.insert(word);
            }
            std::cout << "---------------" << std::endl;
        }
        bool isWordInDictionary(std::string &word)
        {
            return (existsWord.find(word) != existsWord.end());
        }
};