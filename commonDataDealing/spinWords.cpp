std::string spinWords(const std::string &str)
{
    std::istringstream iss(str);
    std::ostringstream oss;
    std::string word;

    while (iss >> word) 
    {
        if (word.length() >= 5) 
        {
            // Reverse the word if it has five or more letters
            std::reverse(word.begin(), word.end());
            // note that reverse's arguments are range
        }
        oss << word << " ";
    }

    // Remove the trailing space
    std::string result = oss.str();
    if (!result.empty()) {
        result.pop_back();
    }

    return result;
  
}// spinWords
