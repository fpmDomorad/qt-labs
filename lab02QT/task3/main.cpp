#include <QCoreApplication>
#include <QString>
#include <QTextStream>
#include <QStringList>
#include <QSet>

bool isSymmetric(const QString &word) {
    QString reversedWord = word;
    std::reverse(reversedWord.begin(), reversedWord.end());
    return word.compare(reversedWord, Qt::CaseInsensitive) == 0;
}
/*
bool hasUniqueChars(const QString &word) {
  QSet<QChar> charSet;
    for (const QChar &ch : word) {
        if (charSet.contains(ch)) {
            return false;
        }
        charSet.insert(ch);
    }
    return true;
}*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream cin(stdin);
    QTextStream cout(stdout);

    cout << "Enter a sequence of words: ";
    cout.flush();
    QString input = cin.readLine();

    QStringList words = input.split(' ', QString::SkipEmptyParts);

    QString firstWord = words.first();
    words.removeFirst();

    cout << "Words that satisfy the conditions: ";
    for (const QString &word : words) {
        if (!word.contains(firstWord, Qt::CaseInsensitive) &&
            isSymmetric(word)){
//&&
           // hasUniqueChars(word))

           cout << word << " ";
       }
    }
    cout << endl;

    return 0;
}
