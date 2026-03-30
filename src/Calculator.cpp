#include "Calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.pushButton, &QPushButton::clicked, this, &Calculator::addNumSymbol);
    connect(ui.pushButton_2, &QPushButton::clicked, this, &Calculator::addNumSymbol);
    connect(ui.pushButton_3, &QPushButton::clicked, this, &Calculator::addNumSymbol);
    connect(ui.pushButton_4, &QPushButton::clicked, this, &Calculator::addNumSymbol);
    connect(ui.pushButton_5, &QPushButton::clicked, this, &Calculator::addNumSymbol);
    connect(ui.pushButton_6, &QPushButton::clicked, this, &Calculator::addNumSymbol);
    connect(ui.pushButton_7, &QPushButton::clicked, this, &Calculator::addNumSymbol);
    connect(ui.pushButton_8, &QPushButton::clicked, this, &Calculator::addNumSymbol);
    connect(ui.pushButton_9, &QPushButton::clicked, this, &Calculator::addNumSymbol);
    connect(ui.pushButton_10, &QPushButton::clicked, this, &Calculator::addOpSymbol);
    connect(ui.pushButton_11, &QPushButton::clicked, this, &Calculator::addOpSymbol);
    connect(ui.pushButton_12, &QPushButton::clicked, this, &Calculator::addPlusMinusSymbol);
    connect(ui.pushButton_13, &QPushButton::clicked, this, &Calculator::addPlusMinusSymbol);
    connect(ui.pushButton_14, &QPushButton::clicked, this, &Calculator::addNumSymbol);
    connect(ui.pushButton_15, &QPushButton::clicked, this, &Calculator::addDotSymbol);
    connect(ui.pushButton_16, &QPushButton::clicked, this, &Calculator::addOpSymbol);
    connect(ui.pushButton_17, &QPushButton::clicked, this, &Calculator::addFuncSymbol);
    connect(ui.pushButton_18, &QPushButton::clicked, this, &Calculator::addFuncSymbol);
    connect(ui.pushButton_19, &QPushButton::clicked, this, &Calculator::solve);
    connect(ui.pushButton_20, &QPushButton::clicked, this, &Calculator::clearAll);
    connect(ui.pushButton_21, &QPushButton::clicked, this, &Calculator::addBracketSymbol);
    connect(ui.pushButton_22, &QPushButton::clicked, this, &Calculator::deleteSymbol);

    ui.lineEdit->setText("0");
}

Calculator::~Calculator()
{}

void Calculator::parsing(string s) {
    for (int i = 0; i < s.size(); i++) {
        char charact = s[i];
        if (numbers.find(charact) != string::npos) {
            bool findflag = true;
            string word = "";
            if (s[i] == '.') word += "0";
            while (findflag) {
                word += s[i];
                i++;
                if (numbers.find(s[i]) == string::npos) findflag = false;
            }
            i--;
            if (s[i] == '.') word += "0";
            vecExp.push_back(word);
        } 
        else if (operators.find(charact) != string::npos || brackets.find(charact) != string::npos) {
            string buf = "";
            buf += charact;
            vecExp.push_back(buf);
        }
        else if (func.find(charact) != string::npos) {
            string buf = "";
            buf += charact;
            i += 2;
            vecExp.push_back(buf);
        }
        else {
            int a; // некорректный символ - ошибка
        }
    }
}

float Calculator::evaluate(vector<string> vec, int n) {
    if (vecExp.empty()) return 1.0;
    if (operators.find(vec[0]) != string::npos) {
        if (vec[0] == "-") {
            vec[1] = "-" + vec[1];
            vec.erase(vec.begin());
        }
        else if (vec[0] == "+") {
            vec.erase(vec.begin());
        }
        else {
            int a; // Ошибка:первый знак после открывающийся скобки не может быть двоичным
        }
    }

    vector<float> val;
    vector<char> op;

    int i = 0, j = 0;
    while (j < vec.size()) {
        if (vec[j] == "(") {
            i = ++j;
            for (int numbrack = 0; j < vec.size(); j++) {
                if (vec[j] == "(") numbrack++;
                else if (vec[j] == ")") {
                    if (numbrack == 0) break;
                    numbrack--;
                }
            }
            if (j == vec.size()) {
                int a; // не достает 1 скобки
            }

            vector<string> nvec(vec.begin() + i, vec.begin() + j);
            val.push_back(evaluate(nvec, n + j));
        }
        if (errorFlag) {
            return 0;
        }
        if (operators.find(vec[j].c_str()[0]) != string::npos && vec[j].size() == 1 ||
            func.find(vec[j].c_str()[0]) != string::npos) {
            op.push_back(vec[j].c_str()[0]);
        }

        int ind = 0;
        if (vec[j].c_str()[0] == '-') ind = 1;
        char ch = vec[j].c_str()[ind];
        if (numbers.find(ch) != string::npos) {
            i = j;
            val.push_back(stof(vec[j]));
        }
        //j++;
        if (vec[j] == ")") {
            int a; // Лишняя скобка. Не работает
        }
        j++;
    }
    j--;
    if (op.size() + 1 != val.size()) {
        int a; // Количество операторов не соответствует количеству чисел
    }

    /*if (numbers.find(vec[j].c_str()[0]) != string::npos) {
        val.push_back(stof(vec[j]));
    }*/
    
    string oper = "sc";
    for (int k = 0; k < op.size();) {
        if (oper.find(op[k]) != string::npos) {
            val[k] = evaluate_numbers(val[k], op[k]);
            op.erase(op.begin() + k);
        }
        else k++;
    }

    oper = "^";
    for (int k = 0; k < op.size();) {
        if (oper.find(op[k]) != string::npos) {
            val[k] = evaluate_numbers(val[k], val[k + 1], op[k]);
            op.erase(op.begin() + k);
            val.erase(val.begin() + k + 1, val.begin() + k + 2);
        }
        else k++;
    }

    oper = "*/";
    for (int k = 0; k < op.size();) {
        if (oper.find(op[k]) != string::npos) {
            val[k] = evaluate_numbers(val[k], val[k + 1], op[k]);
            if (errorFlag) {
                return 0;
            }
            op.erase(op.begin() + k);
            val.erase(val.begin() + k + 1, val.begin() + k + 2);
        }
        else k++;
    }

    oper = "+-";
    for (int k = 0; k < op.size();) {
        if (oper.find(op[k]) != string::npos) {
            val[k] = evaluate_numbers(val[k], val[k + 1], op[k]);
            op.erase(op.begin() + k);
            val.erase(val.begin() + k + 1, val.begin() + k + 2);
        }
        else k++;
    }
    return val[0];
}

float Calculator::evaluate_numbers(float a, float b, char op) {
    if (op == '+') a = a + b;
    else if (op == '-') a = a - b;
    else if (op == '*') a = a * b;
    else if (op == '/') {
        if (b == 0) {
            QMessageBox::critical(this, "Ошибка",
                "Ошибка: деление на 0!");
            errorFlag = true;
            return 0;
        }
        a = a / b;
    }
    else if (op == '^') a = pow(a, b);
    return a;
}

float Calculator::evaluate_numbers(float a, char op) {
    if (op == 's') a = sin(a);
    else if (op == 'c') a = cos(a);
    return a;
}


void Calculator::addNumSymbol() {
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if (exp.length() != 0)
        if (exp[exp.length() - 1] == ')')
            return;
    if (btn && !btn->text().isEmpty()) {
        bool haveDot = false;
        QChar symbol = btn->text()[0];
        int countZero = 0;
        int countNotZero = 0;
        for (int i = exp.length() - 1; i >= 0; i--) {
            if (numbers.find(exp[i]) != string::npos) {
                if (exp[i] == '0') countZero++;
                else countNotZero++;
                if (exp[i] == '.') {
                    haveDot = true;
                    break;
                }
            }
            else break;
        }
        if (symbol == '0') {
            if (!haveDot) 
                if (countZero > 0 && countNotZero == 0) return;
        }
        if (exp.length() != 0)
            if (!haveDot && exp[exp.length() - 1] == '0' && symbol != '0' && countNotZero == 0) return;
        exp = exp + symbol.toLatin1();
        QString e = QString::fromStdString(exp);
        ui.lineEdit->setText(e);
    }
}

void Calculator::addPlusMinusSymbol()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if (exp.length() != 0) 
        if (operators.find(exp[exp.length() - 1]) != string::npos || exp[exp.length() - 1] == '.')
            return;
    if (btn && !btn->text().isEmpty()) {
        QChar symbol = btn->text()[0];
        exp = exp + symbol.toLatin1();
        QString e = QString::fromStdString(exp);
        ui.lineEdit->setText(e);
    }
}

void Calculator::addOpSymbol()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if (exp.length() == 0) return;
    if (exp.length() != 0)
        if (operators.find(exp[exp.length() - 1]) != string::npos || exp[exp.length() - 1] == '(' || exp[exp.length() - 1] == '.')
            return;
    if (btn && !btn->text().isEmpty()) {
        QChar symbol = btn->text()[0];
        exp = exp + symbol.toLatin1();
        QString e = QString::fromStdString(exp);
        ui.lineEdit->setText(e);
    }
}

void Calculator::addFuncSymbol()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    int a = exp.length() - 1;
    if (exp.length() != 0)
        if (numbers.find(exp[exp.length() - 1]) != string::npos || exp[exp.length() - 1] == ')')
            return;
    if (btn && !btn->text().isEmpty()) {
        QChar symbol = btn->text()[0];
        char sym = symbol.toLatin1();
        if (sym == 's') {
            exp = exp + "sin(";
            numBrackets++;
        }
        else {
            exp = exp + "cos(";
            numBrackets++;
        }
        QString e = QString::fromStdString(exp);
        ui.lineEdit->setText(e);
    }
}

void Calculator::addBracketSymbol()
{
    if (exp.length() == 0) {
        exp += "(";
        numBrackets++;
    }
    else {
        string openbr = "(";
        if ((operators.find(exp[exp.length() - 1]) != string::npos || openbr.find(exp[exp.length() - 1]) != string::npos) && exp[exp.length() - 1] != '.') {
            exp += "(";
            numBrackets++;
        }
        else {
            if (numBrackets > 0 && exp[exp.length() - 1] != '.') {
                exp += ")";
                numBrackets--;
            }
        }
    }

    QString e = QString::fromStdString(exp);
    ui.lineEdit->setText(e);
}

void Calculator::addDotSymbol()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if (exp.length() != 0)
        if (numbers.find(exp[exp.length() - 1]) == string::npos || exp[exp.length() - 1] == '.') return;
        else {
            bool haveDot = false;
            for (int i = exp.length() - 1; i >= 0; i--) {
                if (numbers.find(exp[i]) != string::npos) {
                    if (exp[i] == '.') {
                        haveDot = true;
                        break;
                    }
                }
                else break;
            }
            if (haveDot) return;
        }

    if (btn && !btn->text().isEmpty()) {
        if (exp.length() == 0) {
            exp = exp + "0.";
        }
        else {
            QChar symbol = btn->text()[0];
            exp = exp + symbol.toLatin1();
        }
        QString e = QString::fromStdString(exp);
        ui.lineEdit->setText(e);
    }
}

void Calculator::clearAll()
{
    exp = "";
    numBrackets = 0;
    ui.lineEdit->setText("0");
}

void Calculator::deleteSymbol()
{
    if (exp.length() == 0) return;
    if (exp.length() >= 2) {
        if (exp[exp.length() - 2] == 'n' || exp[exp.length() - 2] == 's') {
            for (int i = 0; i < 4; i++) {
                exp.pop_back();
            }
            numBrackets--;
        }
        else {
            if (exp[exp.length() - 1] == ')')
                numBrackets++;
            else if (exp[exp.length() - 1] == '(')
                numBrackets--;
            exp.pop_back();
        }
    }
    else {
        if (exp[exp.length() - 1] == ')')
            numBrackets++;
        else if (exp[exp.length() - 1] == '(')
            numBrackets--;
        exp.pop_back();
    }
    QString e = QString::fromStdString(exp);
    ui.lineEdit->setText(e);
}

void Calculator::solve()
{
    if (numBrackets != 0) {
        QMessageBox::warning(this, "Ошибка",
            "Количество открывающих и закрывающих скобок не совпадает!");
        return;
    }
    if (exp.length() == 0) exp += "0";
    else if (exp.length() != 0) if (operators.find(exp[exp.length() - 1]) != string::npos || exp[exp.length() - 1] == '.') {
        QMessageBox::warning(this, "Ошибка",
            "Выражение не закончено или содержит лишние символы.");
        return;
    }

    parsing(exp);
    float b = evaluate(vecExp, 0);

    if (!errorFlag) {
        string s = to_string(b);
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '0') s.pop_back();
            else break;
        }
        if (s[s.length() - 1] == '.') s.pop_back();
        if (s == "0") s = "0.0";
        QString e = QString::fromStdString(s);
        ui.lineEdit->setText(e);
        if (isinf(b)) exp = "";
        else exp = "" + s;
        numBrackets = 0;
    }
    vecExp.clear();
    errorFlag = false;
}
