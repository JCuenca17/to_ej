#include "ejercicioqt.h"
#include "./ui_ejercicioqt.h"

EjercicioQt::EjercicioQt(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::EjercicioQt),
    n1(0),
    n2(0),
    res(0),
    operador('\0')
{
    ui->setupUi(this);
    setupConnections(); // Configurar conexiones usando funciones lambda

    /*
    connect(ui->button_cero, SIGNAL(clicked()), this, SLOT(on_digitButton_clicked()));
    connect(ui->button_uno, SIGNAL(clicked()), this, SLOT(on_digitButton_clicked()));
    connect(ui->button_dos, SIGNAL(clicked()), this, SLOT(on_digitButton_clicked()));
    connect(ui->button_tres, SIGNAL(clicked()), this, SLOT(on_digitButton_clicked()));
    connect(ui->button_cuatro, SIGNAL(clicked()), this, SLOT(on_digitButton_clicked()));
    connect(ui->button_cinco, SIGNAL(clicked()), this, SLOT(on_digitButton_clicked()));
    connect(ui->button_seis, SIGNAL(clicked()), this, SLOT(on_digitButton_clicked()));
    connect(ui->button_siete, SIGNAL(clicked()), this, SLOT(on_digitButton_clicked()));
    connect(ui->button_ocho, SIGNAL(clicked()), this, SLOT(on_digitButton_clicked()));
    connect(ui->button_nueve, SIGNAL(clicked()), this, SLOT(on_digitButton_clicked()));

    connect(ui->button_suma, SIGNAL(clicked()), this, SLOT(on_operatorButton_clicked()));
    connect(ui->button_resta, SIGNAL(clicked()), this, SLOT(on_operatorButton_clicked()));
    connect(ui->button_multip, SIGNAL(clicked()), this, SLOT(on_operatorButton_clicked()));
    connect(ui->button_divi, SIGNAL(clicked()), this, SLOT(on_operatorButton_clicked()));

    connect(ui->button_igual, SIGNAL(clicked()), this, SLOT(on_equalsButton_clicked()));
    connect(ui->button_ac, SIGNAL(clicked()), this, SLOT(on_buttonAc_clicked()));
    */

    display = "0";
    ui->lcdNumber->display(display);
    ui->label->setText(display);
}

EjercicioQt::~EjercicioQt()
{
    delete ui;
}

void EjercicioQt::setupConnections()
{
    // Conexiones usando funciones lambda para manejar eventos de los botones
    connect(ui->button_cero, &QPushButton::clicked, this, [this]() { on_digit_button_clicked("0"); });
    connect(ui->button_uno, &QPushButton::clicked, this, [this]() { on_digit_button_clicked("1"); });
    connect(ui->button_dos, &QPushButton::clicked, this, [this]() { on_digit_button_clicked("2"); });
    connect(ui->button_tres, &QPushButton::clicked, this, [this]() { on_digit_button_clicked("3"); });
    connect(ui->button_cuatro, &QPushButton::clicked, this, [this]() { on_digit_button_clicked("4"); });
    connect(ui->button_cinco, &QPushButton::clicked, this, [this]() { on_digit_button_clicked("5"); });
    connect(ui->button_seis, &QPushButton::clicked, this, [this]() { on_digit_button_clicked("6"); });
    connect(ui->button_siete, &QPushButton::clicked, this, [this]() { on_digit_button_clicked("7"); });
    connect(ui->button_ocho, &QPushButton::clicked, this, [this]() { on_digit_button_clicked("8"); });
    connect(ui->button_nueve, &QPushButton::clicked, this, [this]() { on_digit_button_clicked("9"); });

    connect(ui->button_suma, &QPushButton::clicked, this, [this]() { on_operator_button_clicked('+'); });
    connect(ui->button_resta, &QPushButton::clicked, this, [this]() { on_operator_button_clicked('-'); });
    connect(ui->button_multip, &QPushButton::clicked, this, [this]() { on_operator_button_clicked('*'); });
    connect(ui->button_divi, &QPushButton::clicked, this, [this]() { on_operator_button_clicked('/'); });

    connect(ui->button_igual, &QPushButton::clicked, this, [this]() { on_equals_button_clicked(); });
    connect(ui->button_ac, &QPushButton::clicked, this, [this]() { on_button_ac_clicked(); });
}

void EjercicioQt::on_button_ac_clicked()
{
    display = "0";
    ui->lcdNumber->display(display);
    n1 = 0;
    n2 = 0;
    res = 0;
    operador = '\0';
    ui->label->setText(display);
}

void EjercicioQt::on_digit_button_clicked(const QString& digit)
{
    if (display == "0") {
        display = digit;
    } else {
        display.append(digit);
    }
    ui->lcdNumber->display(display);
    ui->label->setText(display);
}

void EjercicioQt::on_operator_button_clicked(char op)
{
    operador = op;
    n1 = display.toInt();
    display = "0";
    ui->lcdNumber->display(display);
}

void EjercicioQt::on_equals_button_clicked()
{
    if (operador != '\0') {
        n2 = display.toInt();
        switch (operador) {
        case '+':
            res = n1 + n2;
            break;
        case '-':
            res = n1 - n2;
            break;
        case '*':
            res = n1 * n2;
            break;
        case '/':
            if (n2 != 0) {
                res = n1 / n2;
            } else {
                display = "Error";
                ui->lcdNumber->display(display);
                ui->label->setText(display);
                return;
            }
            break;
        }
        display = QString::number(res);
        ui->lcdNumber->display(display);
        ui->label->setText(display);
        operador = '\0';
    }
}

/*

void EjercicioQt::on_buttonAc_clicked()
{
    display = "0";
    ui->lcdNumber->display(display);
    n1 = 0;
    n2 = 0;
    res = 0;
    operador = '\0';
    ui->label->setText(display);
}

void EjercicioQt::on_digitButton_clicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString digit = clickedButton->text();
    if (display == "0") {
        display = digit;
    } else {
        display.append(digit);
    }
    ui->lcdNumber->display(display);
    ui->label->setText(display);
}

void EjercicioQt::on_operatorButton_clicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    operador = clickedButton->text().at(0).toLatin1(); // Obtener el primer carácter del texto del botón
    n1 = display.toInt();
    display = "0";
    ui->lcdNumber->display(display);
}

void EjercicioQt::on_equalsButton_clicked()
{
    if (operador != '\0') {
        n2 = display.toInt();
        switch (operador) {
        case '+':
            res = n1 + n2;
            break;
        case '-':
            res = n1 - n2;
            break;
        case '*':
            res = n1 * n2;
            break;
        case '/':
            if (n2 != 0) {
                res = n1 / n2;
            } else {
                display = "Error";
                ui->lcdNumber->display(display);
                ui->label->setText(display);
                return;
            }
            break;
        }
        display = QString::number(res);
        ui->lcdNumber->display(display);
        ui->label->setText(display);
        operador = '\0';
    }
}*/
