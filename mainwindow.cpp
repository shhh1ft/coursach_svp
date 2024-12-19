#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDate>
#include <QDialog>
#include <QCalendarWidget>
#include <QVBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    QStringList headers;
    headers << "Дата" << "Вес (кг)";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addEntry);
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::saveData);
    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::loadData);
    connect(ui->calendarButton, &QToolButton::clicked, this, &MainWindow::chooseDate);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::removeEntry);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addEntry()
{
    QString dateStr = ui->dateEdit->text().trimmed();
    QString weightStr = ui->weightEdit->text().trimmed();

    if(dateStr.isEmpty() || weightStr.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, выберите дату и введите вес.");
        return;
    }

    QDate date = QDate::fromString(dateStr, "yyyy-MM-dd");
    if(!date.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Некорректная дата. Используйте формат ГГГГ-ММ-ДД или выберите дату из календаря.");
        return;
    }

    bool ok = false;
    double weight = weightStr.toDouble(&ok);
    if(!ok || weight <= 0) {
        QMessageBox::warning(this, "Ошибка", "Некорректный вес. Введите число больше 0.");
        return;
    }

    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);
    ui->tableWidget->setItem(rowCount, 0, new QTableWidgetItem(date.toString("yyyy-MM-dd")));
    ui->tableWidget->setItem(rowCount, 1, new QTableWidgetItem(QString::number(weight)));

    ui->dateEdit->clear();
    ui->weightEdit->clear();
}

void MainWindow::saveData()
{
    QFile file("data.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для записи.");
        return;
    }

    QTextStream out(&file);

    for(int i = 0; i < ui->tableWidget->rowCount(); i++) {
        QString date = ui->tableWidget->item(i, 0)->text();
        QString weight = ui->tableWidget->item(i, 1)->text();
        out << date << ";" << weight << "\n";
    }

    file.close();
    QMessageBox::information(this, "Сохранено", "Данные успешно сохранены.");
}

void MainWindow::loadData()
{
    QFile file("data.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для чтения.");
        return;
    }

    ui->tableWidget->setRowCount(0);
    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if(line.isEmpty()) continue;

        QStringList parts = line.split(";");
        if(parts.size() == 2) {
            int rowCount = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rowCount);
            ui->tableWidget->setItem(rowCount, 0, new QTableWidgetItem(parts[0]));
            ui->tableWidget->setItem(rowCount, 1, new QTableWidgetItem(parts[1]));
        }
    }

    file.close();
}

void MainWindow::chooseDate()
{
    // Создаём диалог для выбора даты
    QDialog dialog(this);
    dialog.setWindowTitle("Выбор даты");
    QVBoxLayout *layout = new QVBoxLayout(&dialog);

    QCalendarWidget *calendar = new QCalendarWidget(&dialog);
    calendar->setSelectedDate(QDate::currentDate());
    layout->addWidget(calendar);

    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    QPushButton *okButton = new QPushButton("OK", &dialog);
    QPushButton *cancelButton = new QPushButton("Отмена", &dialog);
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addWidget(cancelButton);

    layout->addLayout(buttonsLayout);

    connect(okButton, &QPushButton::clicked, &dialog, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    if(dialog.exec() == QDialog::Accepted) {
        QDate selectedDate = calendar->selectedDate();
        ui->dateEdit->setText(selectedDate.toString("yyyy-MM-dd"));
    }
}

void MainWindow::removeEntry()
{
    // Удаляем выбранную строку из таблицы
    QList<QTableWidgetItem*> selection = ui->tableWidget->selectedItems();
    if(selection.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, выберите запись для удаления.");
        return;
    }

    int row = selection.first()->row();
    ui->tableWidget->removeRow(row);
}
