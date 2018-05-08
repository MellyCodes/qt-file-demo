#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QFile>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadPhrases();

    QVBoxLayout* vlmain = new QVBoxLayout(ui->centralWidget);
    QHBoxLayout* hlmain = new QHBoxLayout();
    vlmain->addLayout(hlmain);

    QPushButton* newPhraseBtn = new QPushButton();
    newPhraseBtn->setText("New Phrase");

    connect(newPhraseBtn, &QPushButton::clicked, this, &MainWindow::onclick);

    hlmain->addWidget(newPhraseBtn);

    displayPhrase = new QLabel();
    vlmain->addWidget((displayPhrase));
    displayPhrase->setText("Look at me");
}

void MainWindow::onclick()
{
    displayPhrase->setText(phrases[qrand()%phrases.size()]);

}

void MainWindow::loadPhrases()
{
    QFile iFile(":/text/hangman.txt");
    if(!iFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        qWarning()<<"Error opening file\n";
        exit(EXIT_FAILURE);
    }

    QTextStream in(&iFile);
    QString line = in.readLine();

    while(!in.atEnd()){
        phrases.push_back(line);
        line = in.readLine();
    }

    iFile.close();

}

MainWindow::~MainWindow()
{
    delete ui;
}
