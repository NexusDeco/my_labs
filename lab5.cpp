#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int countWordsInString(const string& line) {
    int count = 0;
    bool inWordNow = false;
    
    for (char ch : line) {
        if (ch == ' ') {
            if (inWordNow) {
                count++;
                inWordNow = false;
            }
        } else {
            inWordNow = true;
        }
    }
    
    if (inWordNow) {
        count++;
    }
    
    return count;
}

int main() {
    cout << "Enter input filename: ";
    string inputFile;
    cin >> inputFile;
    
    cout << "Enter first output filename: ";
    string outputFile1;
    cin >> outputFile1;
    
    cout << "Enter second output filename: ";
    string outputFile2;
    cin >> outputFile2;
    
    ifstream inputStream(inputFile);
    ofstream outputStream1(outputFile1);
    ofstream outputStream2(outputFile2);

    if (!outputStream1) {
        ofstream tempFile1(outputFile1);
    }
    if (!outputStream2) {
        ofstream tempFile2(outputFile2);
    }

    cout << "Show input file content? [Y/n]: ";
    string choice;
    cin >> choice;

    vector<string> fileLines;
    string lineText;
    
    while (getline(inputStream, lineText)) {
        fileLines.pb(lineText);
    }

    if (choice == "Y" || choice == "y") {
        cout << "\n\n----------- Input file content -----------\n";
        for (auto currentLine : fileLines) {
            cout << currentLine << "\n";
        }    
        cout << "-----------------------------------------\n\n";
    }

    for (auto currentLine : fileLines) {
        int wordCount = countWordsInString(currentLine);
        
        if (wordCount <= 2) {
            outputStream1 << currentLine << "\n";
        } else if (wordCount >= 3 && wordCount <= 6) {
            outputStream2 << currentLine << "\n";
        }
    }

    inputStream.close();
    outputStream1.close();
    outputStream2.close();

    cout << "Show output files content? [Y/n]: ";
    cin >> choice;

    if (choice == "Y" || choice == "y") {
        ifstream viewFile1(outputFile1);
        cout << "\n----------- First output file content (<= 2 words) -----------\n";
        string fileContent;
        while (getline(viewFile1, fileContent)) {
            cout << fileContent << "\n";
        }
        viewFile1.close();

        ifstream viewFile2(outputFile2);
        cout << "\n----------- Second output file content (3-6 words) -----------\n";
        while (getline(viewFile2, fileContent)) {
            cout << fileContent << "\n";
        }
        viewFile2.close();
        cout << "------------------------------------------------------------\n";
    }

    cout << "Processing finished!\n";
    cout << "Lines with 1-2 words in: " << outputFile1 << "\n";
    cout << "Lines with 3-6 words in: " << outputFile2 << "\n";

    return 0;
}
