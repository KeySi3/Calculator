#pragma once
#include <QtWidgets/QMainWindow>
#include <vector>
#include <string>
#include <cmath>
#include <qmessagebox.h>
#include <qshortcut.h>
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
    void parsing(string s);  // Метод разбора строки с выражением
    float evaluate(vector<string> vec, int n);  // Метод рассчета значения выражения
    float evaluate_numbers(float a, float b, char op);  // Метод вычислисления бинарных операторов
    float evaluate_numbers(float a, char op);  // Метод расчета значений математических функций 
    void addNumSymbol();  // Метод цифру
    void addPlusMinusSymbol();  // Метод добавления символов плюч и минус
    void addOpSymbol();  // Метод добавления символа оператора
    void addFuncSymbol();  // Метод добавления математической функции
    void addBracketSymbol();  // Метод добавления скобки
    void addDotSymbol();  // Метод добавления разделителя
    void clearAll();  // Метод удаления выражения
    void deleteSymbol();  // Метод удаления символа
    void solve();  // Метод решения выражения
    void setupShortcuts();  // Метод установки быстрых клавиш
    

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
