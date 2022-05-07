#ifndef SRC_MAINWINDOW_H_
#define SRC_MAINWINDOW_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "smartCalc.h"
#ifdef __cplusplus
}
#endif

#include <graphicus.h>

#include <QMainWindow>
#include <QMessageBox>
#include <clocale>

#include "creditcalc.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  int expAreas = 1;
  int xAreas = 0;
  CreditCalc *creditCalcWin;
  Graphicus *graphicWin;

 private slots:
  void digits();
  void AreaDigs();
  void xAreaDigs();
  void on_pushButton_eq_clicked();
  void on_creditus_triggered();
  void on_pushButton_ques_clicked();

 signals:
  void signalus(QString);
  void cleanSig();
};
#endif  // SRC_MAINWINDOW_H_
