/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lE_Ordem;
    QTextBrowser *tb_Informacoes;
    QPushButton *btn_Atualizar;
    QPushButton *btn_Solucionar;
    QPushButton *btn_GerarVazio;
    QPushButton *btn_GerarJogo;
    QTextEdit *tb_Jogo;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(781, 692);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(23, 15, 65, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 10, 90, 17));
        lE_Ordem = new QLineEdit(centralWidget);
        lE_Ordem->setObjectName(QStringLiteral("lE_Ordem"));
        lE_Ordem->setGeometry(QRect(80, 10, 41, 27));
        tb_Informacoes = new QTextBrowser(centralWidget);
        tb_Informacoes->setObjectName(QStringLiteral("tb_Informacoes"));
        tb_Informacoes->setGeometry(QRect(170, 30, 251, 121));
        btn_Atualizar = new QPushButton(centralWidget);
        btn_Atualizar->setObjectName(QStringLiteral("btn_Atualizar"));
        btn_Atualizar->setGeometry(QRect(20, 40, 101, 27));
        btn_Solucionar = new QPushButton(centralWidget);
        btn_Solucionar->setObjectName(QStringLiteral("btn_Solucionar"));
        btn_Solucionar->setGeometry(QRect(20, 130, 101, 27));
        btn_GerarVazio = new QPushButton(centralWidget);
        btn_GerarVazio->setObjectName(QStringLiteral("btn_GerarVazio"));
        btn_GerarVazio->setGeometry(QRect(20, 70, 101, 27));
        btn_GerarJogo = new QPushButton(centralWidget);
        btn_GerarJogo->setObjectName(QStringLiteral("btn_GerarJogo"));
        btn_GerarJogo->setGeometry(QRect(20, 100, 101, 27));
        tb_Jogo = new QTextEdit(centralWidget);
        tb_Jogo->setObjectName(QStringLiteral("tb_Jogo"));
        tb_Jogo->setGeometry(QRect(20, 190, 741, 441));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 781, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Ordem:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Informa\303\247\303\265es", 0));
        btn_Atualizar->setText(QApplication::translate("MainWindow", "Atualizar", 0));
        btn_Solucionar->setText(QApplication::translate("MainWindow", "Solucionar", 0));
        btn_GerarVazio->setText(QApplication::translate("MainWindow", "Gerar vazio", 0));
        btn_GerarJogo->setText(QApplication::translate("MainWindow", "Gerar Jogo", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
