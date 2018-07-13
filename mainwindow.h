#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QVBoxLayout>

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void OnEncodeButtonClicked();
    void OnDecodeButtonClicked();
private:
    QPlainTextEdit *TextBox;
    QPushButton *EncodeButton, *DecodeButton;
    QVBoxLayout *VboxLayout;
};

#endif // MAINWINDOW_H
