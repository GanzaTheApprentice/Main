#include "creditcalc.h"

#include "ui_creditcalc.h"

CreditCalc::CreditCalc(QWidget *parent)
    : QWidget(parent), ui(new Ui::CreditCalc) {
  ui->setupUi(this);
}

CreditCalc::~CreditCalc() { delete ui; }

void CreditCalc::cleaning() {
  ui->yeaArea->clear();
  ui->monArea->clear();
  ui->sumArea->clear();
  ui->perArea->clear();
  ui->firstDep->setText("0");
  ui->lastDep->setText("0");
  ui->percDep->setText("0");
  ui->sumDep->setText("0");
}

void CreditCalc::on_pushButton_res_clicked() {
  bool isNum1, isNum2, isNum3, isNum4;
  double data, sum, per;

  if (ui->yeaArea->text().isEmpty() && !ui->monArea->text().isEmpty()) {
    ui->yeaArea->setText("0");
  }
  if (ui->monArea->text().isEmpty() && !ui->yeaArea->text().isEmpty()) {
    ui->monArea->setText("0");
  }

  data = (ui->monArea->text().toDouble(&isNum1) +
          ui->yeaArea->text().toDouble(&isNum2) * 12);
  sum = ui->sumArea->text().toDouble(&isNum3);
  per = ((ui->perArea->text().toDouble(&isNum4) / 100) / 12);

  if (isNum1 && isNum2 && isNum3 && isNum4 && data > 0 && data < 601 &&
      sum > 0 && per > 0) {
    if (ui->difRadio->isChecked()) {
      double res = sum / data + sum * per;
      double constPart, sumDebt, totalSum = 0;
      QString fDep = QString::number(res, 'f', 2);
      ui->firstDep->setText(fDep);
      constPart = sum / data;
      sumDebt = sum - constPart;
      totalSum += res;
      data--;
      while (data) {
        res = sumDebt / data + sumDebt * per;
        sumDebt = sumDebt - constPart;
        totalSum += res;
        data--;
      }
      fDep = QString::number(res, 'f', 2);
      ui->lastDep->setText(fDep);

      fDep = QString::number(totalSum, 'f', 2);
      ui->sumDep->setText(fDep);

      totalSum -= sum;
      fDep = QString::number(totalSum, 'f', 2);
      ui->percDep->setText(fDep);
    } else if (ui->anuRadio->isChecked()) {
      double res = sum * (per + (per / (pow(1 + per, data) - 1)));
      QString fDep = QString::number(res, 'f', 2);
      ui->firstDep->setText(fDep);
      ui->lastDep->setText(fDep);

      res = res * data;
      fDep = QString::number(res, 'f', 2);
      ui->sumDep->setText(fDep);

      res -= sum;
      fDep = QString::number(res, 'f', 2);
      ui->percDep->setText(fDep);
    } else {
      QMessageBox *error = new QMessageBox;
      error->setWindowTitle("Ошибка!");
      error->setText("Одна ошибка и ты ошибся!\n(Некорректный ввод)");
      error->show();
    }
  } else {
    QMessageBox *error = new QMessageBox;
    error->setWindowTitle("Ошибка!");
    error->setText("Одна ошибка и ты ошибся!\n(Некорректный ввод)");
    error->show();
  }
}

void CreditCalc::on_pushButton_res_2_clicked() {
  ui->yeaArea->clear();
  ui->monArea->clear();
  ui->sumArea->clear();
  ui->perArea->clear();
  ui->firstDep->setText("0");
  ui->lastDep->setText("0");
  ui->percDep->setText("0");
  ui->sumDep->setText("0");
}
