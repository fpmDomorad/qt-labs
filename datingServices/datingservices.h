#ifndef DATINGSERVICES_H
#define DATINGSERVICES_H

#include <QMainWindow>
#include <QJsonArray>

QT_BEGIN_NAMESPACE
namespace Ui {
class datingServices;
}
QT_END_NAMESPACE

class datingServices : public QMainWindow
{
    Q_OBJECT

public:
    datingServices(QWidget *parent = nullptr);
    ~datingServices();
    void writeJsonFile();
    void displayFemaleCandidates();
    void displayMaleCandidates();
    void sortFemaleCandidatesAlphabetically();
    void sortMaleCandidatesAlphabetically();
    void updateCandidates();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_lineEdit_3_editingFinished();

    void on_lineEdit_4_editingFinished();

    void on_comboBox_activated(int index);

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();


    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);


    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();



private:
    Ui::datingServices *ui;
 QJsonArray jsonArray;
};
#endif // DATINGSERVICES_H
