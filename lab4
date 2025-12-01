#include <iostream>

int _strcmp(char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    
    if (*str1 < *str2) return -1;
    if (*str1 > *str2) return 1;
    return 0;
}

int string_length(const char* str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

void string_copy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

bool is_digit_word(const char* word) {
    int i = 0;
    while (word[i] != '\0') {
        if (word[i] < '0' || word[i] > '9')
            return false;
        i++;
    }
    return true;
}

void reorganize_string(char* str) {
    const char* word_ptrs[150];
    int word_lengths[150];
    int word_count = 0;
    
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            i++;
            continue;
        }
        
        word_ptrs[word_count] = &str[i];
        int j = 0;
        
        while (str[i] != '\0' && str[i] != ' ') {
            i++;
            j++;
        }
        word_lengths[word_count] = j;
        word_count++;
    }
    
    char temp[301] = {0};
    int temp_pos = 0;
    
    for (int w = 0; w < word_count; w++) {
        bool is_digit = true;
        for (int k = 0; k < word_lengths[w]; k++) {
            if (word_ptrs[w][k] < '0' || word_ptrs[w][k] > '9') {
                is_digit = false;
                break;
            }
        }
        
        if (is_digit) {
            if (temp_pos > 0) {
                temp[temp_pos++] = ' ';
            }
            for (int k = 0; k < word_lengths[w]; k++) {
                temp[temp_pos++] = word_ptrs[w][k];
            }
        }
    }
    
    for (int w = 0; w < word_count; w++) {
        bool is_digit = true;
        for (int k = 0; k < word_lengths[w]; k++) {
            if (word_ptrs[w][k] < '0' || word_ptrs[w][k] > '9') {
                is_digit = false;
                break;
            }
        }
        
        if (!is_digit) {
            if (temp_pos > 0) {
                temp[temp_pos++] = ' ';
            }
            for (int k = 0; k < word_lengths[w]; k++) {
                temp[temp_pos++] = word_ptrs[w][k];
            }
        }
    }
    
    temp[temp_pos] = '\0';
    
    string_copy(str, temp);
}

int main() {
    std::cout << "Task A: Testing _strcmp function\n";
    
    int comparisons;
    std::cout << "How many string comparisons do you want to perform? ";
    std::cin >> comparisons;
    std::cin.ignore();
    
    for (int i = 0; i < comparisons; i++) {
        char str1[101], str2[101];
        
        std::cout << "\nComparison " << i + 1 << ":\n";
        std::cout << "Enter first string: ";
        std::cin.getline(str1, 101);
        
        std::cout << "Enter second string: ";
        std::cin.getline(str2, 101);
        
        int result = _strcmp(str1, str2);
        std::cout << "Result: " << result;
        
        if (result == -1) {
            std::cout << " (first string is lexicographically smaller than second)\n";
        } else if (result == 0) {
            std::cout << " (strings are equal)\n";
        } else {
            std::cout << " (first string is lexicographically greater than second)\n";
        }
    }
    
    std::cout << "\nTask B: Reorganize string\n";
    std::cout << "Enter a string (words separated by single spaces, no leading/trailing spaces (no more than 300 characters)):\n";
    
    char input[301];
    std::cin.getline(input, 301);
    
    if (string_length(input) == 0) {
        std::cout << "Empty string!\n";
        return 0;
    }
    
    reorganize_string(input);
    std::cout << "Result: " << input << std::endl;
    
    return 0;
}
