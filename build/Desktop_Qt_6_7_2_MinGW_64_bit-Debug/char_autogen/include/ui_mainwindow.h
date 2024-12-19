/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *vboxLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *hboxLayout;
    QLineEdit *dateEdit;
    QToolButton *calendarButton;
    QLineEdit *weightEdit;
    QPushButton *addButton;
    QHBoxLayout *hboxLayout1;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QPushButton *removeButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        vboxLayout = new QVBoxLayout(centralwidget);
        vboxLayout->setObjectName("vboxLayout");
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName("tableWidget");

        vboxLayout->addWidget(tableWidget);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName("hboxLayout");
        dateEdit = new QLineEdit(centralwidget);
        dateEdit->setObjectName("dateEdit");

        hboxLayout->addWidget(dateEdit);

        calendarButton = new QToolButton(centralwidget);
        calendarButton->setObjectName("calendarButton");

        hboxLayout->addWidget(calendarButton);

        weightEdit = new QLineEdit(centralwidget);
        weightEdit->setObjectName("weightEdit");

        hboxLayout->addWidget(weightEdit);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");

        hboxLayout->addWidget(addButton);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName("hboxLayout1");
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");

        hboxLayout1->addWidget(saveButton);

        loadButton = new QPushButton(centralwidget);
        loadButton->setObjectName("loadButton");

        hboxLayout1->addWidget(loadButton);

        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName("removeButton");

        hboxLayout1->addWidget(removeButton);


        vboxLayout->addLayout(hboxLayout1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\226\321\203\321\200\320\275\320\260\320\273 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\262\320\265\321\201\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\201", nullptr));
        dateEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\264\320\260\321\202\321\203", nullptr));
        calendarButton->setText(QCoreApplication::translate("MainWindow", "\360\237\223\205", nullptr));
#if QT_CONFIG(tooltip)
        calendarButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\264\320\260\321\202\321\203 \320\270\320\267 \320\272\320\260\320\273\320\265\320\275\320\264\320\260\321\200\321\217", nullptr));
#endif // QT_CONFIG(tooltip)
        weightEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\262\320\265\321\201 (\320\272\320\263)", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\203\321\216 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
