#ifndef SRC_CREDITCALC_H_
#define SRC_CREDITCALC_H_

#include <QMessageBox>
#include <QWidget>

namespace Ui {
class CreditCalc;
}

class CreditCalc : public QWidget {
  Q_OBJECT

 public:
  explicit CreditCalc(QWidget *parent = nullptr);
  ~CreditCalc();

 private slots:
  void on_pushButton_res_clicked();

  void on_pushButton_res_2_clicked();

 private:
  Ui::CreditCalc *ui;

 public slots:
  void cleaning();
};

#endif  // SRC_CREDITCALC_H_
