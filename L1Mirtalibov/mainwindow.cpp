#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->redo_but->setEnabled(false);
    ui->undo_but->setEnabled(false);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_textEdit_textChanged() {
    m_textEditor.replace(ui->textEdit->toPlainText().toStdString(), 0, m_textEditor.text().length());
    ui->undo_but->setEnabled(true);
    if (m_textEditor.redo_stack.is_empty()) {
        ui->redo_but->setEnabled(false);
    }
}

void MainWindow::on_undo_but_clicked() {
    ui->redo_but->setEnabled(true);
    m_textEditor.undo();
    ui->textEdit->blockSignals(true);
    ui->textEdit->setPlainText(m_textEditor.text().c_str());
    ui->textEdit->blockSignals(false);
    if (m_textEditor.undo_stack.is_empty()) {
        ui->undo_but->setEnabled(false);
    }
}

void MainWindow::on_redo_but_clicked() {
    ui->undo_but->setEnabled(true);
    m_textEditor.redo();
    ui->textEdit->blockSignals(true);
    ui->textEdit->setPlainText(m_textEditor.text().c_str());
    ui->textEdit->blockSignals(false);
    if (m_textEditor.redo_stack.is_empty()) {
        ui->redo_but->setEnabled(false);
    }
}
