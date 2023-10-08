#ifndef EJERCICIOQT_H
#define EJERCICIOQT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class EjercicioQt; }
QT_END_NAMESPACE

class EjercicioQt : public QMainWindow
{
    Q_OBJECT

public:
    EjercicioQt(QWidget *parent = nullptr);
    ~EjercicioQt();


private slots:
    void on_digit_button_clicked(const QString& digit);
    void on_operator_button_clicked(char op);
    void on_equals_button_clicked();
    void on_button_ac_clicked();

private:
    Ui::EjercicioQt *ui;
    QString display;
    int n1, n2, res;
    char operador;

    void setupConnections();
};
#endif // EJERCICIOQT_H
