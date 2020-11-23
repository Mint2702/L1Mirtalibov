#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "text_editor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_textEdit_textChanged();

    void on_undo_but_clicked();

    void on_redo_but_clicked();

private:
    Ui::MainWindow* ui;
    text_editor m_textEditor;
};
#endif // MAINWINDOW_H
