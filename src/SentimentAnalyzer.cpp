#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>

struct
SentimentAnalyzer
{
    std::vector<std::string> PositiveWords, NegativeWords;

    std::vector<std::string>
    ReadToVector(std::string path)
    {
        std::vector<std::string> result;
        std::ifstream file(path);
        
        std::string line;
        while (std::getline(file, line))
            result.push_back(line);
        file.close();
        
        return result;
    }

    void
    Setup(std::string posPath, std::string negPath)
    {
        PositiveWords.clear();
        NegativeWords.clear();

        PositiveWords = ReadToVector(posPath);
        NegativeWords = ReadToVector(negPath);
    }

    int
    Analyze(std::string text)
    {
        unsigned int Positive = 0, Negative = 0;
        std::istringstream iss(text);

        do
        {
            std::string word;
            iss >> word;
            if (word != "")
            {
                if (std::find(PositiveWords.begin(), PositiveWords.end(), word) != PositiveWords.end())
                    Positive++;
                
                if (std::find(NegativeWords.begin(), NegativeWords.end(), word) != NegativeWords.end())
                    Negative++;
            }
        } while (iss);
    
        unsigned short Verdict = 0;
        if (Positive || Negative) Verdict = (Positive - Negative) / (Positive + Negative);
        else Verdict = 0;
        return Verdict;
    }
};


// Uncomment to run the example 

// int
// main()
// {
//     SentimentAnalyzer analyzer;
//     analyzer.Setup("words/positive.txt", "words/negative.txt");
//  
//     std::string input;
//     std::getline(std::cin, input);
//
//     switch (analyzer.Analyze(input))
//     {
//         case 0: std::cout << "Neutral"; break;
//         case 1: std::cout << "Positive"; break;
//         case -1: std::cout << "Negative"; break;
//     }
// }