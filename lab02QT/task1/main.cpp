#include <QCoreApplication>
#include <QString>
#include <QTextStream>
//#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Enter a word from the keyboard
    QString word;
    QTextStream out(stdout);
    out << "Input word:";
    out.flush();
    QTextStream in(stdin);
    in >> word;

    // Checking that the word is not empty
    if (word.isEmpty()) {
        out << "The word cannot be empty.";
    }

    // Looking for two identical letters in a word
    QChar letter; // Letter that repeats
    bool found = false; // Flag indicating that a pair has been found
    for (int i = 0; i < word.length() - 1; i++) {
        // Compare the current letter with the next ones
        for (int j = i + 1; j < word.length(); j++) {
            if (word[i] == word[j]) {
                // Found a couple(нашли пару)
                letter = word[i];
                found = true;
                break;
            }
        }
        if (found) {
            // Exiting the cycle
            break;
        }
    }

    // Output of the result
    if(found){
        out << "In a word " << word << " there are two identical letters " << letter << "\n";
    }
    else{
   out << "In a word " << word << " no identical letters\n";
    }

    return 0;
}
