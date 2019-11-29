#include <iostream>
#include <fstream>
#include <set>
#include <locale.h>
#include <vector>

class Util {
    public:
    static std::string& leftTrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
    {
        str.erase(0, str.find_first_not_of(chars));
        return str;
    }
    static std::string& lower(std::string& str, const std::string& chars = "\t\n\v\f\r ")
    {
        std::string low;
        for(int j = 0; j < str.length(); j++)
        {
            if(str[j] >= 'A' && str[j] <= 'Z')
            {
                low.push_back(str[j] + 'a'-'A');
            }
            else
                low.push_back(str[j]);
        }
        str = low;
        return str;
    }
    static std::string& rightTrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
    {
        str.erase(str.find_last_not_of(chars) + 1);
        return str;
    }

    static std::string& myTrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
    {
        return leftTrim(rightTrim(str, chars), chars);
    }
    static void eraseAllSubStr(std::string & mainStr, const std::string & toErase)
    {
        size_t pos = std::string::npos;
    
        // Search for the substring in string in a loop untill nothing is found
        while ((pos  = mainStr.find(toErase) )!= std::string::npos)
        {
            // If found then erase it from string
            mainStr.erase(pos, toErase.length());
        }
    }
};
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
              std::string cleanWord = Util::myTrim(word);
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
        int getSize()
        {
            return existsWord.size();
        }
};