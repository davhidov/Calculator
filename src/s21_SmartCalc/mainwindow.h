#ifndef MAINWINDOW_H
#define MAINWINDOW_H
extern "C" {
#include "credit.h"
#include "deposit.h"
#include "input.h"
}
#include <QDate>
#include <QDateTime>
#include <QMainWindow>
#include <QMessageBox>
#include <QStringList>

#include "qcustomplot.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

 private slots:

  void on_butt_X_clicked();
  void on_butt_openBracket_clicked();
  void on_butt_closeBracket_clicked();
  void on_butt_mod_clicked();
  void on_butt_sqrt_clicked();
  void on_butt_pow_clicked();
  void on_butt_log_clicked();
  void on_butt_ln_clicked();

  void on_butt_sin_clicked();
  void on_butt_asin_clicked();
  void on_butt_cos_clicked();
  void on_butt_acos_clicked();
  void on_butt_tg_clicked();
  void on_butt_atg_clicked();

  void on_butt_0_clicked();
  void on_butt_1_clicked();
  void on_butt_2_clicked();
  void on_butt_3_clicked();
  void on_butt_4_clicked();
  void on_butt_5_clicked();
  void on_butt_6_clicked();
  void on_butt_7_clicked();
  void on_butt_8_clicked();
  void on_butt_9_clicked();

  void on_butt_AC_clicked();
  void on_butt_C_clicked();

  void on_butt_plus_clicked();
  void on_butt_sub_clicked();
  void on_butt_mult_clicked();
  void on_butt_div_clicked();
  void on_butt_eq_clicked();
  void on_butt_dot_clicked();

  void on_butPlotGraf_clicked();

  void on_butCalcCredit_clicked();

  void on_butAddReff_clicked();

  void on_buttDelReff_clicked();

  void on_butAddWith_clicked();

  void on_buttDelWith_clicked();

  void on_butDepCalc_clicked();

 private:
  Ui::MainWindow *ui;
  QCustomPlot *wGraphic;
  QStringList freq = {"Once", "Once a month", "Once a quarter", "Half-yearly",
                      "Once a year"};
};

#endif  // MAINWINDOW_H
