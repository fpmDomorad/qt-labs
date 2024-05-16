#include "datingservices.h"
#include "ui_datingservices.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QFileDialog>
#include <QMessageBox>
#include <algorithm>

datingServices::datingServices(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::datingServices)
{
    ui->setupUi(this);
}

datingServices::~datingServices()
{
    delete ui;
}

void datingServices::writeJsonFile() {
    QFile file("D:\\BSU\\QT labs\\datingServices\\test.json");
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Не удалось открыть файл для записи:" << file.errorString();
        return;
    }
    jsonArray;

    QJsonObject vladimir;
    vladimir["id"] = 1;
    vladimir["name"] = "Vladimir";
    vladimir["age"] = 30;
    vladimir["height"] = 180;
    vladimir["education"] = "Higher education";
    vladimir["hobbies"] = "Reading, hiking";
    vladimir["gender"] = "male";
    vladimir ["number"] = "963(617)7322-40-98";
    jsonArray.append(vladimir);

    QJsonObject alice;
    alice["id"] = 2;
    alice["name"] = "Alice";
    alice["age"] = 21;
    alice["height"] = 165;
    alice["education"] = "General secondary education";
    alice["hobbies"] = "Painting, traveling";
    alice["gender"] = "female";
    alice ["number"] = "2(788)8956-67-24";
    jsonArray.append(alice);

    QJsonObject ivan;
    ivan["id"] = 3;
    ivan["name"] = "Ivan";
    ivan["age"] = 35;
    ivan["height"] = 175;
    ivan["education"] = "Secondary special education";
    ivan["hobbies"] = "Photography, traveling";
    ivan["gender"] = "male";
    ivan ["number"] = "2(788)8956-67-23";
    jsonArray.append(ivan);

    QJsonObject helen;
    helen["id"] = 4;
    helen["name"] = "Helen";
    helen["age"] = 28;
    helen["height"] = 168;
    helen["education"] = "Higher education";
    helen["hobbies"] = "Dancing, reading";
    helen["gender"] = "female";
    helen ["number"] = "2(788)8926-67-25";
    jsonArray.append(helen);

    QJsonObject petr;
    petr["id"] = 5;
    petr["name"] = "Petr";
    petr["age"] = 24;
    petr["height"] = 185;
    petr["education"] = "Higher education";
    petr["hobbies"] = "Sports, cinema";
    petr["gender"] = "male";
    petr ["number"] = "2(788)8956-57-25";
    jsonArray.append(petr);

    QJsonObject olha;
    olha["id"] = 6;
    olha["name"] = "Olha";
    olha["age"] = 29;
    olha["height"] = 169;
    olha["education"] = "Secondary special education";
    olha["hobbies"] = "Drawing, traveling";
    olha["gender"] = "female";
    olha ["number"] = "2(788)8996-67-25";
    jsonArray.append(olha);

    QJsonObject mikhail;
    mikhail["id"] = 7;
    mikhail["name"] = "Mikhail";
    mikhail["age"] = 31;
    mikhail["height"] = 178;
    mikhail["education"] = "Higher education";
    mikhail["hobbies"] = "Music, sports";
    mikhail["gender"] = "male";
    mikhail ["number"] = "2(788)8956-60-25";
    jsonArray.append(mikhail);

    QJsonObject natalia;
    natalia["id"] = 8;
    natalia["name"] = "Natalia";
    natalia["age"] = 20;
    natalia["height"] = 163;
    natalia["education"] = "General secondary education";
    natalia["hobbies"] = "Photography, cooking";
    natalia["gender"] = "female";
    natalia ["number"] = "2(788)8956-67-05";
    jsonArray.append(natalia);

    QJsonObject alexander;
    alexander["id"] = 9;
    alexander["name"] = "Alexander";
    alexander["age"] = 22;
    alexander["height"] = 175;
    alexander["education"] = "Secondary special education";
    alexander["hobbies"] = "Reading, traveling";
    alexander["gender"] = "male";
    alexander ["number"] = "2(788)8156-67-25";
    jsonArray.append(alexander);


    QJsonObject svetlana;
    svetlana["id"] = 10;
    svetlana["name"] = "Svetlana";
    svetlana["age"] = 30;
    svetlana["height"] = 170;
    svetlana["education"] = "Higher education";
    svetlana["hobbies"] = "Theater, traveling";
    svetlana["gender"] = "female";
    svetlana ["number"] = "2(788)8916-67-25";
    jsonArray.append(svetlana);


    QJsonDocument jsonDoc(jsonArray);

    // Записываем JSON-документ в файл
    QTextStream out(&file);
    out << jsonDoc.toJson(QJsonDocument::Indented);

    file.close();
}


void datingServices::on_pushButton_clicked()
{
    this->close();
}
void datingServices::updateCandidates() {
    // Получаем минимальный и максимальный возраст из lineEdit
    int minAge = ui->lineEdit->text().toInt();
    int maxAge = ui->lineEdit_2->text().toInt();

    // Получаем минимальный и максимальный рост из lineEdit
    int minHeight = ui->lineEdit_3->text().toInt();
    int maxHeight = ui->lineEdit_4->text().toInt();

    // Получаем выбранное образование из comboBox
    QString selectedEducation = ui->comboBox->currentText();

    // Очищаем textBrowser перед отображением новых данных
    ui->textBrowser->clear();

    // Проверяем выбранный пол и отображаем соответствующих кандидатов
    if (ui->radioButton->isChecked()) {
        // Отображаем только женщин
        for (const auto& candidate : jsonArray) {
            // Проверяем возраст, рост, пол и образование кандидата
            int age = candidate.toObject()["age"].toInt();
            int height = candidate.toObject()["height"].toInt();
            if (age >= minAge && age <= maxAge && height >= minHeight && height <= maxHeight &&
                candidate.toObject()["gender"] == "female" && candidate.toObject()["education"] == selectedEducation) {
                // Формируем информацию о кандидате
                QString candidateInfo = candidate.toObject()["name"].toString() + ", " +
                                        QString::number(age) + " years old\n" +
                                        QString::number(height) + " cm\n" +
                                        candidate.toObject()["education"].toString() + ", " +
                                        candidate.toObject()["hobbies"].toString() + " number " +
                                        candidate.toObject()["number"].toString();

                // Выводим информацию о кандидате в textBrowser
                ui->textBrowser->append(candidateInfo);
            }
        }
    } else if (ui->radioButton_2->isChecked()) {
        // Отображаем только мужчин
        for (const auto& candidate : jsonArray) {
            // Проверяем возраст, рост, пол и образование кандидата
            int age = candidate.toObject()["age"].toInt();
            int height = candidate.toObject()["height"].toInt();
            if (age >= minAge && age <= maxAge && height >= minHeight && height <= maxHeight &&
                candidate.toObject()["gender"] == "male" && candidate.toObject()["education"] == selectedEducation) {
                // Формируем информацию о кандидате
                QString candidateInfo = candidate.toObject()["name"].toString() + ", " +
                                        QString::number(age) + " years old\n" +
                                        QString::number(height) + " cm\n" +
                                        candidate.toObject()["education"].toString() + ", " +
                                        candidate.toObject()["hobbies"].toString() + " number " +
                                        candidate.toObject()["number"].toString();

                // Выводим информацию о кандидате в textBrowser
                ui->textBrowser->append(candidateInfo);
            }
        }
    }
}


void datingServices::on_lineEdit_editingFinished()
{

     ui->lineEdit->setEnabled(false);
}


void datingServices::on_lineEdit_2_editingFinished()
{
     ui->lineEdit_2->setEnabled(false);
}


void datingServices::on_lineEdit_3_editingFinished()
{
     ui->lineEdit_3->setEnabled(false);
}


void datingServices::on_lineEdit_4_editingFinished()
{
     ui->lineEdit_4->setEnabled(false);
}


void datingServices::on_comboBox_activated(int index)
{
      ui->comboBox->setEnabled(false);

}


void datingServices::on_pushButton_7_clicked()
{
    ui->lineEdit->setEnabled(true);
    ui->lineEdit->clear();
    ui->lineEdit_2->setEnabled(true);
    ui->lineEdit_2->clear();
    ui->lineEdit_3->setEnabled(true);
    ui->lineEdit_3->clear();
    ui->lineEdit_4->setEnabled(true);
    ui->lineEdit_4->clear();
    ui->comboBox->setEnabled(true);
    ui->radioButton->setEnabled(true);
    ui->radioButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
}


void datingServices::on_pushButton_2_clicked()
{
    QString filename = "D:\\BSU\\QT labs\\datingServices\\test.json";

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Не удалось открыть файл для чтения:" << file.errorString();
        return;
    }

    QProcess::startDetached("notepad.exe", QStringList() << filename);

}


void datingServices::on_pushButton_6_clicked()
{
    ui->textBrowser->clear();

}
void datingServices::displayFemaleCandidates()
{
    // Очищаем текст в textBrowser перед отображением новой информации
    ui->textBrowser->clear();

    // Проходим по всем кандидатам из вашего JSON файла
    for (const auto& candidate : jsonArray) {
        // Проверяем, является ли кандидат женщиной
        if (candidate.toObject()["gender"] == "female") {
            // Если да, то добавляем информацию о ней в textBrowser
            QString candidateInfo = candidate.toObject()["name"].toString() + ", " +
                                    QString::number(candidate.toObject()["age"].toInt()) + " years old, " +
                                    QString::number(candidate.toObject()["height"].toInt()) + " cm\n" +
                                    candidate.toObject()["education"].toString() + ", " +  "hobbies: " +
                                    candidate.toObject()["hobbies"].toString() + " number " +
                                   candidate.toObject()["number"].toString();
            ui->textBrowser->append(candidateInfo);
        }
    }
}

void datingServices::displayMaleCandidates()
{
    // Очищаем текст в textBrowser перед отображением новой информации
    ui->textBrowser->clear();

    // Проходим по всем кандидатам из вашего JSON файла
    for (const auto& candidate : jsonArray) {
        // Проверяем, является ли кандидат мужчиной
        if (candidate.toObject()["gender"] == "male") {
            // Если да, то добавляем информацию о нем в textBrowser
            QString candidateInfo = candidate.toObject()["name"].toString() + ", " +
                                    QString::number(candidate.toObject()["age"].toInt()) + " years old, " +
                                    QString::number(candidate.toObject()["height"].toInt()) + " cm\n" +
                                    candidate.toObject()["education"].toString() + ", "  +  "hobbies: " +
                                    candidate.toObject()["hobbies"].toString() + " number " +
                                    candidate.toObject()["number"].toString();

            ui->textBrowser->append(candidateInfo);
        }
    }
}





void datingServices::on_radioButton_toggled(bool checked)
{
    if (checked) {
        displayFemaleCandidates(); // Функция для отображения только женщин
    }
    ui->radioButton_2->setEnabled(false);
}


void datingServices::on_radioButton_2_toggled(bool checked)
{
    if (checked) {
        displayMaleCandidates(); // Функция для отображения только мужчин
    }
    ui->radioButton->setEnabled(false);
}


void datingServices::on_pushButton_5_clicked()
{
        // Получаем текст из поля textBrowser
        QString searchText = ui->textBrowser->toPlainText();

        // Получаем слово для поиска из поля ввода (например, QLineEdit с именем searchLineEdit)
        QString searchWord = ui->searchLineEdit->text();

        // Проверяем, пустое ли поле ввода
        if (searchWord.isEmpty()) {
            // Если поле ввода пустое, отображаем сообщение об ошибке или выполняем другое действие
            QMessageBox::warning(this, "Пустое поле", "Введите имя для поиска.");
            return; // Выходим из функции, чтобы избежать выполнения остального кода
        }
        // Проходим по всем кандидатам из вашего JSON файла
        for (const auto& candidate : jsonArray) {
            // Проверяем, содержит ли имя кандидата искомое слово (игнорируем регистр)
            if (candidate.toObject()["name"].toString().contains(searchWord, Qt::CaseInsensitive)) {
                // Если да, то выводим всю информацию о кандидате
                QString candidateInfo = "Name: " + candidate.toObject()["name"].toString() + "\n" +
                                        "Age: " + QString::number(candidate.toObject()["age"].toInt()) + " years old\n" +
                                        "Height: " + QString::number(candidate.toObject()["height"].toInt()) + " cm\n" +
                                        "Education: " + candidate.toObject()["education"].toString() + "\n" +
                                        "Hobbies: " + candidate.toObject()["hobbies"].toString() + "\n" + "Number: " +
                                         candidate.toObject()["number"].toString();

                // Отображаем информацию в textBrowser
                ui->textBrowser->setText(candidateInfo);

                // Прерываем цикл, так как мы уже нашли нужного кандидата
                break;
            }
            }

    }

    void datingServices::sortFemaleCandidatesAlphabetically() {
        // Получаем копию массива объектов JSON только с женщинами
        QJsonArray sortedFemaleArray;
        for (const auto& candidate : jsonArray) {
            if (candidate.toObject()["gender"] == "female") {
                sortedFemaleArray.append(candidate);
            }
        }

        // Сортируем копию массива кандидатов по имени
        for (int i = 0; i < sortedFemaleArray.size(); ++i) {
            for (int j = 0; j < sortedFemaleArray.size() - 1; ++j) {
                QString nameA = sortedFemaleArray[j].toObject()["name"].toString().toLower();
                QString nameB = sortedFemaleArray[j + 1].toObject()["name"].toString().toLower();
                if (nameA > nameB) {
                    // Меняем местами элементы массива, если текущий больше следующего
                    QJsonValue temp = sortedFemaleArray[j];
                    sortedFemaleArray[j] = sortedFemaleArray[j + 1];
                    sortedFemaleArray[j + 1] = temp;
                }
            }
        }

        // Очищаем textBrowser перед отображением отсортированных кандидатов
        ui->textBrowser->clear();

        // Выводим отсортированных кандидатов в textBrowser
        for (const auto& candidate : sortedFemaleArray) {
            // Формируем строку с информацией о кандидате
            QString candidateInfo = candidate.toObject()["name"].toString() + ", " +
                                    QString::number(candidate.toObject()["age"].toInt()) + " years old, " +
                                    QString::number(candidate.toObject()["height"].toInt()) + " cm\n" +
                                    candidate.toObject()["education"].toString() + ", " +
                                    candidate.toObject()["hobbies"].toString() + " number " +
                                    candidate.toObject()["number"].toString();
            // Добавляем информацию о кандидате в textBrowser
            ui->textBrowser->append(candidateInfo);
        }
    }

    void datingServices::sortMaleCandidatesAlphabetically() {
        // Получаем копию массива объектов JSON только с мужчинами
        QJsonArray sortedMaleArray;
        for (const auto& candidate : jsonArray) {
            if (candidate.toObject()["gender"] == "male") {
                sortedMaleArray.append(candidate);
            }
        }

        // Сортируем копию массива кандидатов по имени
        for (int i = 0; i < sortedMaleArray.size(); ++i) {
            for (int j = 0; j < sortedMaleArray.size() - 1; ++j) {
                QString nameA = sortedMaleArray[j].toObject()["name"].toString().toLower();
                QString nameB = sortedMaleArray[j + 1].toObject()["name"].toString().toLower();
                if (nameA > nameB) {
                    // Меняем местами элементы массива, если текущий больше следующего
                    QJsonValue temp = sortedMaleArray[j];
                    sortedMaleArray[j] = sortedMaleArray[j + 1];
                    sortedMaleArray[j + 1] = temp;
                }
            }
        }
        // Очищаем textBrowser перед отображением отсортированных кандидатов
        ui->textBrowser->clear();

        // Выводим отсортированных кандидатов в textBrowser
        for (const auto& candidate : sortedMaleArray) {
            // Формируем строку с информацией о кандидате
            QString candidateInfo = candidate.toObject()["name"].toString() + ", " +
                                    QString::number(candidate.toObject()["age"].toInt()) + " years old, " +
                                    QString::number(candidate.toObject()["height"].toInt()) + " cm\n" +
                                    candidate.toObject()["education"].toString() + ", " +
                                    candidate.toObject()["hobbies"].toString() + " number " +
                                    candidate.toObject()["number"].toString();
            // Добавляем информацию о кандидате в textBrowser
            ui->textBrowser->append(candidateInfo);
        }
    }


void datingServices::on_pushButton_3_clicked()
{
    if (ui->radioButton->isChecked()){
        displayFemaleCandidates();
        sortFemaleCandidatesAlphabetically();
    }
    else if(ui->radioButton_2->isChecked()){
        displayMaleCandidates();
        sortMaleCandidatesAlphabetically();
    }
}

void datingServices::on_pushButton_4_clicked()
{
    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty() ||
        ui->lineEdit_3->text().isEmpty() || ui->lineEdit_4->text().isEmpty()) {
        // Если хотя бы одно поле не заполнено, выводим сообщение
        QMessageBox::warning(this, "Неполная информация", "Введите все параметры для поиска.");
        return;
    }
    ui->pushButton_3->setEnabled(false);
    updateCandidates();
}

