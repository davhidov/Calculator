#include "mainwindow.h"

#include <stdio.h>
#include <stdlib.h>

#include <QString>
#include <iostream>

#include "input.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  std::locale().global(std::locale("C"));
}
MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_butt_eq_clicked() {
  QString text = ui->textEdit->toPlainText();
  ui->textEdit_2->setPlainText(text);
  ui->textEdit_2->setAlignment(Qt::AlignRight);
  char *str = (char *)calloc(text.length() + 2, sizeof(char));
  for (int i = 0; i < text.length(); i++) str[i] = text[i].toLatin1();
  str[text.length()] = '\n';
  str[text.length() + 1] = '\0';
  Graf graf;
  graf.y = NULL;
  graf.num_of_point = 100;

  int er = draw(str, &graf, 0, ui->textXValue->toPlainText().toDouble(), 1);
  if (er == 1) {
    std::cout << "Problebn\n";
    QMessageBox::critical(this, "Wrong input!",
                          "Incorrect statment.\nTry again");
    return;
  }
  if (graf.rez - static_cast<int>(graf.rez) > 1e-7)
    ui->textEdit->setText(QString::number(graf.rez, 'f', 8));
  else
    ui->textEdit->setText(QString::number(graf.rez));
  ui->textEdit->setAlignment(Qt::AlignRight);
}

void MainWindow::on_butPlotGraf_clicked() {
  QString text2 = ui->textEdit_2->toPlainText();
  char *str = (char *)calloc(text2.length() + 2, sizeof(char));
  for (int i = 0; i < text2.length(); i++) str[i] = text2[i].toLatin1();
  str[text2.length()] = '\n';
  str[text2.length() + 1] = '\0';
  Graf graf;
  graf.y = NULL;
  graf.num_of_point = 100000;
  graf.start = ui->textMinX->toPlainText().toDouble();
  graf.end = ui->textMaxX->toPlainText().toDouble();
  int er = draw(str, &graf, 1, 0, 1);
  if (er == 1) {
    std::cout << "Problebn in paradise\n";
    QMessageBox::critical(this, "Wrong input!",
                          "Incorrect function.\nTry again");
    return;
  }
  ui->textEdit_2->setAlignment(Qt::AlignRight);

  QVector<double> x1, y1;
  for (int i = 0; i <= graf.num_of_point; i++) {
    y1.push_back(graf.y[i]);
    x1.push_back(graf.x[i]);
  }
  free(graf.y);
  free(graf.x);
  wGraphic = ui->widget;
  wGraphic->addGraph();
  wGraphic->xAxis->setRange(ui->textMinX->toPlainText().toDouble(),
                            ui->textMaxX->toPlainText().toDouble());
  wGraphic->yAxis->setRange(ui->textMinY->toPlainText().toDouble(),
                            ui->textMaxY->toPlainText().toDouble());
  wGraphic->graph(0)->setData(x1, y1);
  wGraphic->replot();
}

void MainWindow::on_butt_X_clicked() { ui->textEdit->insertPlainText("x"); }
void MainWindow::on_butt_openBracket_clicked() {
  ui->textEdit->insertPlainText("(");
}
void MainWindow::on_butt_closeBracket_clicked() {
  ui->textEdit->insertPlainText(")");
}
void MainWindow::on_butt_mod_clicked() { ui->textEdit->insertPlainText("mod"); }
void MainWindow::on_butt_sqrt_clicked() {
  ui->textEdit->insertPlainText("sqrt()");
}
void MainWindow::on_butt_pow_clicked() { ui->textEdit->insertPlainText("^"); }
void MainWindow::on_butt_log_clicked() {
  ui->textEdit->insertPlainText("log()");
}
void MainWindow::on_butt_ln_clicked() { ui->textEdit->insertPlainText("ln()"); }
void MainWindow::on_butt_sin_clicked() {
  ui->textEdit->insertPlainText("sin()");
}
void MainWindow::on_butt_asin_clicked() {
  ui->textEdit->insertPlainText("asin()");
}
void MainWindow::on_butt_cos_clicked() {
  ui->textEdit->insertPlainText("cos()");
}
void MainWindow::on_butt_acos_clicked() {
  ui->textEdit->insertPlainText("acos()");
}
void MainWindow::on_butt_tg_clicked() {
  ui->textEdit->insertPlainText("tan()");
}
void MainWindow::on_butt_atg_clicked() {
  ui->textEdit->insertPlainText("atan()");
}
void MainWindow::on_butt_0_clicked() { ui->textEdit->insertPlainText("0"); }
void MainWindow::on_butt_1_clicked() { ui->textEdit->insertPlainText("1"); }
void MainWindow::on_butt_2_clicked() { ui->textEdit->insertPlainText("2"); }
void MainWindow::on_butt_3_clicked() { ui->textEdit->insertPlainText("3"); }
void MainWindow::on_butt_4_clicked() { ui->textEdit->insertPlainText("4"); }
void MainWindow::on_butt_5_clicked() { ui->textEdit->insertPlainText("5"); }
void MainWindow::on_butt_6_clicked() { ui->textEdit->insertPlainText("6"); }
void MainWindow::on_butt_7_clicked() { ui->textEdit->insertPlainText("7"); }
void MainWindow::on_butt_8_clicked() { ui->textEdit->insertPlainText("8"); }
void MainWindow::on_butt_9_clicked() { ui->textEdit->insertPlainText("9"); }

void MainWindow::on_butt_AC_clicked() {
  ui->textEdit->setPlainText("");
  ui->textEdit->setAlignment(Qt::AlignRight);
}
void MainWindow::on_butt_C_clicked() {
  ui->textEdit->textCursor().deletePreviousChar();
}
void MainWindow::on_butt_plus_clicked() { ui->textEdit->insertPlainText("+"); }
void MainWindow::on_butt_sub_clicked() { ui->textEdit->insertPlainText("-"); }
void MainWindow::on_butt_mult_clicked() { ui->textEdit->insertPlainText("*"); }
void MainWindow::on_butt_div_clicked() { ui->textEdit->insertPlainText("/"); }
void MainWindow::on_butt_dot_clicked() { ui->textEdit->insertPlainText("."); }

void MainWindow::on_butCalcCredit_clicked() {
  double debt = ui->spinMoney->value(), rate = ui->spinRate->value();
  int time = ui->comTime->currentText() == "Months" ? 1 : 12;
  int dur = ui->spinTime->value() * time;
  CreditInfo res;
  QString result;
  int error = 0;
  if (dur == 0 || debt == 0 || rate == 0) error = 1;
  if (ui->boxType->currentText() == "Annuity" && !error)
    res = resultAn(dur, rate, debt),
    result =
        "Monthly payment:" + QString::number(res.monthlyPayment[0], 'f', 2) +
        " | Overpayment: " + QString::number(res.overpayment, 'f', 2) +
        " | Total debt: " + QString::number(res.totalDebt, 'f', 2);
  else if (!error)
    res = resultDif(dur, rate, debt),
    result =
        "Monthly payment:" + QString::number(res.monthlyPayment[1], 'f', 2) +
        " - " + QString::number(res.monthlyPayment[0], 'f', 2) +
        " | Overpayment: " + QString::number(res.overpayment, 'f', 2) +
        " | Total debt: " + QString::number(res.totalDebt, 'f', 2);
  else
    result = "ERROR";
  ui->lineRezalt->setText(result);
}

void MainWindow::on_butAddReff_clicked() {
  int row = ui->tabReff->rowCount();
  QComboBox *buff_cb = new QComboBox(this);
  QDoubleSpinBox *buff_db = new QDoubleSpinBox(this);
  QDateTimeEdit *buff_dt = new QDateTimeEdit(this);
  buff_cb->addItems(freq);
  ui->tabReff->insertRow(row);
  buff_db->setMaximum(1000000000);
  buff_db->setMinimum(0);
  buff_dt->setDisplayFormat("dd.MM.yyyy");
  ui->tabReff->setCellWidget(row, 0, buff_dt);
  ui->tabReff->setCellWidget(row, 1, buff_db);
  ui->tabReff->setCellWidget(row, 2, buff_cb);
}

void MainWindow::on_buttDelReff_clicked() {
  int row = ui->tabReff->rowCount() - 1;
  ui->tabReff->removeRow(row);
}

void MainWindow::on_butAddWith_clicked() {
  int row = ui->tabWith->rowCount();
  QComboBox *buff_cb = new QComboBox(this);
  QDoubleSpinBox *buff_db = new QDoubleSpinBox(this);
  QDateTimeEdit *buff_dt = new QDateTimeEdit(this);
  buff_cb->addItems(freq);
  ui->tabWith->insertRow(row);
  buff_db->setMaximum(1000000000);
  buff_db->setMinimum(0);
  buff_dt->setDisplayFormat("dd.MM.yyyy");
  ui->tabWith->setCellWidget(row, 0, buff_dt);
  ui->tabWith->setCellWidget(row, 1, buff_db);
  ui->tabWith->setCellWidget(row, 2, buff_cb);
}

void MainWindow::on_buttDelWith_clicked() {
  int row = ui->tabWith->rowCount() - 1;
  ui->tabWith->removeRow(row);
}

void MainWindow::on_butDepCalc_clicked() {
  ui->calendarWidget->update();
  QDate data = ui->calendarWidget->selectedDate();
  QTime time(0, 0);
  QDateTime tmp(data, time);
  time_t st_d = tmp.toSecsSinceEpoch(), buff = 0;
  double deposit = ui->spinDepos->value(), tax = ui->spinTax->value(),
         ir = ui->spinDepRate->value();
  int payment_freq = 0;
  switch (ui->boxFreq->currentIndex()) {
    case 0:
      payment_freq = 100;
      break;
    case 1:
      payment_freq = 1;
      break;
    case 2:
      payment_freq = 3;
      break;
    case 3:
      payment_freq = 6;
      break;
    case 4:
      payment_freq = 12;
      break;
  }
  int cap = ui->boxCap->isChecked();
  int n_a = ui->tabReff->rowCount(), r_a = ui->tabWith->rowCount();
  unit *ads = (unit *)calloc(n_a, sizeof(unit)),
       *rms = (unit *)calloc(r_a, sizeof(unit));
  if (ads == NULL || rms == NULL) exit(0);
  int t = ui->boxDepTime->currentText() == "Months" ? 1 : 12;
  int duration = ui->spinDepTime->value() * t;
  QDateTimeEdit *buff_dt;
  QDoubleSpinBox *buff_db;
  QComboBox *buff_cb;
  tmp = tmp.addMonths(duration);
  time_t end_d = tmp.toSecsSinceEpoch();
  double tmp_db = 0;
  struct tm *temp;
  int tmp_freq = 0, error = 0;
  QString result;
  for (int i = 0; i < n_a; i++) {
    buff_dt = static_cast<QDateTimeEdit *>(ui->tabReff->cellWidget(i, 0));
    tmp = buff_dt->dateTime();
    buff = tmp.toSecsSinceEpoch();
    temp = localtime(&buff);
    ads[i].date = *temp;
    buff_db = static_cast<QDoubleSpinBox *>(ui->tabReff->cellWidget(i, 1));
    tmp_db = buff_db->value();
    ads[i].amount = tmp_db;
    buff_cb = static_cast<QComboBox *>(ui->tabReff->cellWidget(i, 2));
    tmp_freq = 0;
    switch (buff_cb->currentIndex()) {
      case 0:
        tmp_freq = 0;
        break;
      case 1:
        tmp_freq = 1;
        break;
      case 2:
        tmp_freq = 3;
        break;
      case 3:
        tmp_freq = 6;
        break;
      case 4:
        tmp_freq = 12;
        break;
    }
    ads[i].freq = tmp_freq;
  }
  for (int i = 0; i < r_a; i++) {
    buff_dt = static_cast<QDateTimeEdit *>(ui->tabWith->cellWidget(i, 0));
    tmp = buff_dt->dateTime();
    buff = tmp.toSecsSinceEpoch();
    temp = localtime(&buff);
    rms[i].date = *temp;
    buff_db = static_cast<QDoubleSpinBox *>(ui->tabWith->cellWidget(i, 1));
    tmp_db = buff_db->value();
    rms[i].amount = -tmp_db;
    buff_cb = static_cast<QComboBox *>(ui->tabWith->cellWidget(i, 2));
    tmp_freq = 0;
    switch (buff_cb->currentIndex()) {
      case 0:
        tmp_freq = 0;
        break;
      case 1:
        tmp_freq = 1;
        break;
      case 2:
        tmp_freq = 3;
        break;
      case 3:
        tmp_freq = 6;
        break;
      case 4:
        tmp_freq = 12;
        break;
    }
    rms[i].freq = tmp_freq;
  }
  if (st_d == 0 || deposit == 0 || ir == 0) error = 1;
  resInfo fin;
  fin.deposit = 0, fin.gained = 0, fin.taxes = 0;
  if (!error)
    fin = res(ads, rms, n_a, r_a, st_d, end_d, ir, deposit, cap, tax,
              payment_freq),
    tmp.setSecsSinceEpoch(fin.date);
  if (fin.taxes < 0.1) fin.taxes = 0;
  if (!error)
    result = "Deposit withdrawal: " + tmp.toString("dd.MM.yyyy") +
             " | Interest rate gained: " + QString::number(fin.gained, 'f', 2) +
             " | Taxes payed: " + QString::number(fin.taxes, 'f', 2) +
             " | Deposit: " + QString::number(fin.deposit, 'f', 2);
  else
    result = "ERROR";
  ui->lineDepRez->setText(result);
  free(ads), free(rms);
}
