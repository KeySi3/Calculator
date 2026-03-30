#pragma once

#include <QtWidgets/QMainWindow>
#include <vector>
#include <string>
#include <cmath>
#include <qmessagebox.h>
#include <qdebug.h>

#include "ui_Calculator.h"

using namespace std;

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    void parsing(string s);
    float evaluate(vector<string> vec, int n);
    float evaluate_numbers(float a, float b, char op);
    float evaluate_numbers(float a, char op);
    void addNumSymbol();
    void addPlusMinusSymbol();
    void addOpSymbol();
    void addFuncSymbol();
    void addBracketSymbol();
    void addDotSymbol();
    void clearAll();
    void deleteSymbol();
    void solve();

private:
    Ui::CalculatorClass ui;
    string exp = "";
    vector<string> vecExp;
    bool errorFlag = false;

    int numBrackets = 0;

    string brackets = "()";
    string operators = "+-*/^";
    string func = "sc";
    string numbers = ".0123456789";
};
