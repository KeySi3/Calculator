#pragma once

#include <iostream>

#include <QtWidgets/QMainWindow>
#include <vector>
#include <string>
#include <cmath>
#include <qmessagebox.h>
#include <qdebug.h>
#include <qshortcut.h>
#include <qkeyeventtransition.h>
#include <qaction.h>

#include "ui_Calculator.h"

using namespace std;

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);  // Конструктор главного окна
    ~Calculator();  // Деструктор главного окна
   

private:
    void parsing(string s);  // Функция разбора строки с выражением
    float evaluate(vector<string> vec, int n);  // Функция рассчета значения выражения
    float evaluate_numbers(float a, float b, char op);  // Функция вычислисления бинарных операторов
    float evaluate_numbers(float a, char op);  // Функция расчета значений математических функций 
    void addNumSymbol();  // Добавить цифру
    void addPlusMinusSymbol();  // Функция добавления символов плюч и минус
    void addOpSymbol();  // Функция добавления символа оператора
    void addFuncSymbol();  // Функция добавления математической функции
    void addBracketSymbol();  // Функция добавления скобки
    void addDotSymbol();  // Функция добавления разделителя
    void clearAll();  // Функция удаления выражения
    void deleteSymbol();  // Функция удаления символа
    void solve();  // Функция решения выражения
    void setupShortcuts();  // Функция установки быстрых клавиш
    

private:
    const double PI = 4 * atan(1.0);  // Число ПИ
    Ui::CalculatorClass ui;
    string exp = "";  // Выражение
    vector<string> vecExp;  // Массив содержимого выражения
    bool errorFlag = false;  // Флаг ошибок

    int numBrackets = 0;  // Сбалансированность скобок в выражении

    // Массивы символов
    string brackets = "()";
    string operators = "+-*/^";
    string func = "sc";
    string numbers = ".0123456789";

    QList<QShortcut*> m_shortcuts;  // Быстрые клавиши
    QAction* toggleAction;  // Перевести градусы-радиваны
};
