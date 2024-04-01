#include <QCoreApplication>
#include <QString>
#include <QTextStream>
#include <QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream cin(stdin);
    QTextStream cout(stdout);

    cout << "Enter a sentence: ";
    cout.flush();
    QString sentence = cin.readLine();

    QStringList words = sentence.split(' ', QString::SkipEmptyParts);

    cout << "Sentence not equal to 'hello': ";
    for (const QString &word : words) {
        if (word.compare("hello", Qt::CaseSensitive) != 0) {
            cout << word << " ";
        }
    }
    cout << endl;

    return 0;
}
