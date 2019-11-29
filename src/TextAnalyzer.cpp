#include <iostream>
#include <fstream>
#include <set>
#include <locale.h>
#include <vector>

class Dictionary {
    private:
        std::string path;
        std::ifstream file;
        std::set <std::string> existsWord;
    public:

    std::string& leftTrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
    {
        str.erase(0, str.find_first_not_of(chars));
        return str;
    }
    
    std::string& rightTrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
    {
        str.erase(str.find_last_not_of(chars) + 1);
        return str;
    }

    std::string& myTrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
    {
        return leftTrim(rightTrim(str, chars), chars);
    }
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
              std::string cleanWord = myTrim(word);
               std::cout << cleanWord << std::endl;
               existsWord.insert(cleanWord);
            }
            //std::cout << "---------------" << std::endl;
        }
        bool isWordInDictionary(std::string &word)
        {
            return (existsWord.find(word) != existsWord.end());
        }
        int countNotFound(const std::vector<std::string> &words)
        {
            int cont = 0;
            for(auto w: words)
            {
                if(!isWordInDictionary(w))
                cont++;
            }
            return cont;
        }
};