#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QString>
#include <QLabel>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onclick();

private:
    void loadPhrases();

private:
    Ui::MainWindow *ui;

    QLabel* displayPhrase;
    std::vector<QString>phrases;
};

#endif // MAINWINDOW_H
