#ifndef OPTIONDIALOG_H
#define OPTIONDIALOG_H

#include <QDialog>

namespace Ui {
class OptionDialog;
}

class OptionDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit OptionDialog(QWidget *parent = 0);
    ~OptionDialog();

private slots:
    void on_accepted();
    void on_broswePushButton_clicked();
    
private:
    Ui::OptionDialog *ui;
};

#endif // OPTIONDIALOG_H