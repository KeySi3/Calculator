#include "Calculator.h"

// Конструктор главного окна
Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // Установить сигналы
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
    
    // Установить начальное значение
    ui.lineEdit->setText("0");

    // Установить быстрые клавиши
    setupShortcuts();
    
    // Создать меню главного окна
    QToolBar* toolBar = addToolBar("Настройки");

    // Создать кнопку-переключатель
    toggleAction = new QAction("Градусы", this);
    toggleAction->setCheckable(true);
    toggleAction->setChecked(true);
    toggleAction->setToolTip("Переключить отображение результатов расчета\nтригонометрических функция между градусами и радианами");

    // Подключить сигнал кнопки-переключателя
    connect(toggleAction, &QAction::toggled, this, [this](bool checked) {
        if (checked) {
            toggleAction->setText("Градусы");
        }
        else {
            toggleAction->setText("Радианы");
        }
        });
    toolBar->addAction(toggleAction);
}

Calculator::~Calculator()
{}


// Функция разбора строки с выражением
void Calculator::parsing(string s) {
    // Перебрать все элементы строки
    for (int i = 0; i < s.size(); i++) {
        char charact = s[i];
        // Если символ - цифра или разделитель
        if (numbers.find(charact) != string::npos) {
            bool findflag = true;
            string word = "";
            // Если первый симво числа - разделитель, добавить 0
            if (s[i] == '.') word += "0";
            // Считать все число
            while (findflag) {
                word += s[i];
                i++;
                if (numbers.find(s[i]) == string::npos) findflag = false;
            }
            i--;
            vecExp.push_back(word);
        } 
        // Если символ - оператор или скобка, добавить в вектор
        else if (operators.find(charact) != string::npos || brackets.find(charact) != string::npos) {
            string buf = "";
            buf += charact;
            vecExp.push_back(buf);
        }
        // Если символ - функция, добавить первую букву
        else if (func.find(charact) != string::npos) {
            string buf = "";
            buf += charact;
            i += 2;
            vecExp.push_back(buf);
        }
    }
}


// Функция рассчета значения выражения
float Calculator::evaluate(vector<string> vec, int n) {
    if (vecExp.empty()) return 1.0;
    // Если первый символ в векторе - оператор, учесть знак в первом числе
    if (operators.find(vec[0]) != string::npos) {
        if (vec[0] == "-") {
            vec[1] = "-" + vec[1];
            vec.erase(vec.begin());
        }
        else if (vec[0] == "+") {
            vec.erase(vec.begin());
        }
    }
    vector<float> val;  // Вектор чисел
    vector<char> op;  // Вектор операторов

    int i = 0, j = 0;
    while (j < vec.size()) {
        if (vec[j] == "(") {
            i = ++j;
            // Определить наличие внутренних скобок в выражении
            for (int numbrack = 0; j < vec.size(); j++) {
                if (vec[j] == "(") numbrack++;
                else if (vec[j] == ")") {
                    if (numbrack == 0) break;
                    numbrack--;
                }
            }
            // Создать новый массив для внутренней скобки в выражении
            vector<string> nvec(vec.begin() + i, vec.begin() + j);
            // Вычислить значение внутренней скобки
            val.push_back(evaluate(nvec, n + j));
        }
        // Выйти из рассчета при делении на 0
        if (errorFlag) {
            return 0;
        }
        // Если найден оператор или функция, поместить в массив операторов
        if (operators.find(vec[j].c_str()[0]) != string::npos && vec[j].size() == 1 ||
            func.find(vec[j].c_str()[0]) != string::npos) {
            op.push_back(vec[j].c_str()[0]);
        }

        int ind = 0;
        if (vec[j].c_str()[0] == '-') ind = 1;
        char ch = vec[j].c_str()[ind];
        // Если найдено число, добавить в массив чисел
        if (numbers.find(ch) != string::npos) {
            i = j;
            val.push_back(stof(vec[j]));
        }
        j++;
    }
    j--;
    
    // Выполнить расчет всех функций
    string oper = "sc";
    for (int k = 0; k < op.size();) {
        if (oper.find(op[k]) != string::npos) {
            val[k] = evaluate_numbers(val[k], op[k]);
            op.erase(op.begin() + k);
        }
        else k++;
    }

    // Выполнить все возведения в степень
    oper = "^";
    for (int k = 0; k < op.size();) {
        if (oper.find(op[k]) != string::npos) {
            val[k] = evaluate_numbers(val[k], val[k + 1], op[k]);
            op.erase(op.begin() + k);
            val.erase(val.begin() + k + 1, val.begin() + k + 2);
        }
        else k++;
    }

    // Выполнить все умножения, деления
    oper = "*/";
    for (int k = 0; k < op.size();) {
        if (oper.find(op[k]) != string::npos) {
            val[k] = evaluate_numbers(val[k], val[k + 1], op[k]);
            // Если есть деление на 0, закончить расчет
            if (errorFlag) {
                return 0;
            }
            op.erase(op.begin() + k);
            val.erase(val.begin() + k + 1, val.begin() + k + 2);
        }
        else k++;
    }

    // Выполнить все сложения, вычитания
    oper = "+-";
    for (int k = 0; k < op.size();) {
        if (oper.find(op[k]) != string::npos) {
            val[k] = evaluate_numbers(val[k], val[k + 1], op[k]);
            op.erase(op.begin() + k);
            val.erase(val.begin() + k + 1, val.begin() + k + 2);
        }
        else k++;
    }
    // Вернуть полученный результат расчета
    return val[0];
}


// Функция вычислисления бинарных операторов
float Calculator::evaluate_numbers(float a, float b, char op) {
    if (op == '+') a = a + b;
    else if (op == '-') a = a - b;
    else if (op == '*') a = a * b;
    else if (op == '/') {
        // При делении на 0 вызвать ошибку
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


// Функция расчета значений математических функций 
float Calculator::evaluate_numbers(float a, char op) {
    // Перевести градусы в радианы
    if (toggleAction->isChecked()) {
        a = (PI / 180 * a);
    }
    if (op == 's') a = sin(a);
    else if (op == 'c') a = cos(a);
    if (-1E-06 <= a && a <= 1E-06) 
        a = 0;
    return a;
}


// Добавить цифру
void Calculator::addNumSymbol() {
    // Определить, от какой кнопки поступил сигнал
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if (exp.length() != 0)
        // Нельзя ставить цифру после закрывающейся скобки
        if (exp[exp.length() - 1] == ')')
            return;
    if (btn && !btn->text().isEmpty()) {
        bool haveDot = false;
        QChar symbol = btn->text()[0];  // Определить цифру
        int countZero = 0;
        int countNotZero = 0;
        // Определить наличие разделителя в числе
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
        // Нельзя добавить 0 при наличии нуля и отсутствии разделителя
        if (symbol == '0') {
            if (!haveDot) 
                if (countZero > 0 && countNotZero == 0) return;
        }
        // Нельзя добавить любую цифру, если число состоит только из 0
        if (exp.length() != 0)
            if (!haveDot && exp[exp.length() - 1] == '0' && symbol != '0' && countNotZero == 0) return;
        // Добавить символ в выражение
        exp = exp + symbol.toLatin1();
        QString e = QString::fromStdString(exp);
        ui.lineEdit->setText(e);
    }
}


// Функция добавления символов плюч и минус
void Calculator::addPlusMinusSymbol()
{
    // Определить, от какой кнопки поступил сигнал
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    // Нельзя вставить символ, если предыдущий символ - оператор или разделитель
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

// Функция добавления символа оператора
void Calculator::addOpSymbol()
{
    // Определить, от какой кнопки поступил сигнал
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    // Нельзя вставить оператор первым в выражении
    if (exp.length() == 0) return;
    // Нельзя вставить символ, если предыдущий симвл - оператор, открывающаяся скобка или разделитель
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


// Функция добавления математической функции
void Calculator::addFuncSymbol()
{
    // Определить, от какой кнопки поступил сигнал
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    int a = exp.length() - 1;
    // Нельзя вставить мат. функцию, если предыдущий символ - число, разделитель или закрывающаяся скобка
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


// Функция добавления скобки
void Calculator::addBracketSymbol()
{
    // В начале выражения - добавить открывающуюся скобку
    if (exp.length() == 0) {
        exp += "(";
        numBrackets++;
    }
    else {
        string openbr = "(";
        // Если предыдущий символ - не оепратор или не открывающаяся скобка и не разделитель
        if ((operators.find(exp[exp.length() - 1]) != string::npos || openbr.find(exp[exp.length() - 1]) != string::npos) && exp[exp.length() - 1] != '.') {
            exp += "(";
            numBrackets++;
        }
        else {
            // Нельзя ставить закрывающуюся скобку после разделителя и их количество с открытыми должно быть сбалансировано
            if (numBrackets > 0 && exp[exp.length() - 1] != '.') {
                exp += ")";
                numBrackets--;
            }
        }
    }
    QString e = QString::fromStdString(exp);
    ui.lineEdit->setText(e);
}


// Функция добавления разделителя
void Calculator::addDotSymbol()
{
    // Определить, от какой кнопки поступил сигнал
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if (exp.length() != 0)
        // Нельзя ставить разделитель, если последний символ - разделитель или не число
        if (numbers.find(exp[exp.length() - 1]) == string::npos || exp[exp.length() - 1] == '.') return;
        else {
            // Нельзя ставить разделитель, если он уже есть в числе
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


// Функция удаления выражения
void Calculator::clearAll()
{
    exp = "";
    numBrackets = 0;
    ui.lineEdit->setText("0");
}


// Функция удаления символа
void Calculator::deleteSymbol()
{
    if (exp.length() == 0) return;
    if (exp.length() >= 2) {
        // Удалить полностью математическую функцию
        if (exp[exp.length() - 2] == 'n' || exp[exp.length() - 2] == 's') {
            for (int i = 0; i < 4; i++) {
                exp.pop_back();
            }
            numBrackets--;
        }
        // Удалить скобку или другой символ
        else {
            if (exp[exp.length() - 1] == ')')
                numBrackets++;
            else if (exp[exp.length() - 1] == '(')
                numBrackets--;
            exp.pop_back();
        }
    }
    // Удалить другой символ
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


// Функция решения выражения
void Calculator::solve()
{
    // Проверить сбалансированность скобок
    if (numBrackets != 0) {
        QMessageBox::warning(this, "Ошибка",
            "Количество открывающих и закрывающих скобок не совпадает!");
        return;
    }
    // Проверить корректность выражения (последний символ - не оператор и не разделитель)
    if (exp.length() == 0) exp += "0";
    else if (exp.length() != 0) if (operators.find(exp[exp.length() - 1]) != string::npos || exp[exp.length() - 1] == '.') {
        QMessageBox::warning(this, "Ошибка",
            "Выражение не закончено или содержит лишние символы.");
        return;
    }

    // Вычислить значение выражения
    parsing(exp);
    float b = evaluate(vecExp, 0);

    if (!errorFlag) {
        string s = to_string(b);
        // Удалить лишние нули после разделителя
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '0') s.pop_back();
            else break;
        }
        // Удалить разделитель, если после него нет знаков
        if (s[s.length() - 1] == '.') s.pop_back();
        if (s == "0") s = "0.0";
        QString e = QString::fromStdString(s);
        ui.lineEdit->setText(e);
        // Обновить значение выражения для будущих расчетов
        if (isinf(b)) exp = "";
        else exp = "" + s;
        numBrackets = 0;
    }
    vecExp.clear();
    errorFlag = false;
}


// Функция установки быстрых клавиш
void Calculator::setupShortcuts()
{
    QList<int> numberKeys = {
        Qt::Key_1, Qt::Key_2, Qt::Key_3,
        Qt::Key_4, Qt::Key_5, Qt::Key_6,
        Qt::Key_7, Qt::Key_8, Qt::Key_9
    };
    
    QList<QPushButton*> numberButtons = {
        ui.pushButton_3, ui.pushButton_6, ui.pushButton_9,
        ui.pushButton_2, ui.pushButton_5, ui.pushButton_8,
        ui.pushButton, ui.pushButton_4, ui.pushButton_7
    };

    // Установить шорткаты для цифр 1-9
    for (int i = 0; i < numberKeys.size(); ++i) {
        QShortcut* shortcut = new QShortcut(QKeySequence(numberKeys[i]), this);
        shortcut->setContext(Qt::ApplicationShortcut);
        connect(shortcut, &QShortcut::activated, this, [this, i, numberButtons]() {
            if (i < numberButtons.size() && numberButtons[i]) {
                numberButtons[i]->click();
            }
            });
        m_shortcuts.append(shortcut);
    }

    // Установить шорткат для кнопки 0
    QShortcut* shortcut0 = new QShortcut(QKeySequence(Qt::Key_0), this);
    shortcut0->setContext(Qt::ApplicationShortcut);
    connect(shortcut0, &QShortcut::activated, this, [this]() {
        ui.pushButton_14->click();
        });
    m_shortcuts.append(shortcut0);

    // Установить шорткат для сложения 
    QShortcut* shortcutPlus = new QShortcut(QKeySequence(Qt::Key_Plus), this);
    shortcutPlus->setContext(Qt::ApplicationShortcut);
    connect(shortcutPlus, &QShortcut::activated, this, [this]() {
        ui.pushButton_12->click(); 
        });
    m_shortcuts.append(shortcutPlus);

    // Установить шорткат для вычитания
    QShortcut* shortcutMinus = new QShortcut(QKeySequence(Qt::Key_Minus), this);
    shortcutMinus->setContext(Qt::ApplicationShortcut);
    connect(shortcutMinus, &QShortcut::activated, this, [this]() {
        ui.pushButton_13->click();
        });
    m_shortcuts.append(shortcutMinus);

    // Установить шорткат для умножения 
    QShortcut* shortcutMultiply = new QShortcut(QKeySequence(Qt::Key_Asterisk), this);
    shortcutMultiply->setContext(Qt::ApplicationShortcut);
    connect(shortcutMultiply, &QShortcut::activated, this, [this]() {
        ui.pushButton_10->click();
        });
    m_shortcuts.append(shortcutMultiply);

    // Установить шорткат для * через Shift+8
    QShortcut* shortcutMultiplyAlt = new QShortcut(QKeySequence(Qt::SHIFT + Qt::Key_8), this);
    shortcutMultiplyAlt->setContext(Qt::ApplicationShortcut);
    connect(shortcutMultiplyAlt, &QShortcut::activated, this, [this]() {
        ui.pushButton_10->click();
        });
    m_shortcuts.append(shortcutMultiplyAlt);

    // Установить шорткат для деления
    QShortcut* shortcutDivide = new QShortcut(QKeySequence(Qt::Key_Slash), this);
    shortcutDivide->setContext(Qt::ApplicationShortcut);
    connect(shortcutDivide, &QShortcut::activated, this, [this]() {
        ui.pushButton_11->click();
        });
    m_shortcuts.append(shortcutDivide);

    // Установить шорткат для точки
    QShortcut* shortcutDot = new QShortcut(QKeySequence(Qt::Key_Period), this);
    shortcutDot->setContext(Qt::ApplicationShortcut);
    connect(shortcutDot, &QShortcut::activated, this, [this]() {
        ui.pushButton_15->click();
        });
    m_shortcuts.append(shortcutDot);

    // Установить шорткат для знака равно
    QShortcut* shortcutEqual = new QShortcut(QKeySequence(Qt::Key_Equal), this);
    shortcutEqual->setContext(Qt::ApplicationShortcut);
    connect(shortcutEqual, &QShortcut::activated, this, [this]() {
        ui.pushButton_19->click();
        });
    m_shortcuts.append(shortcutEqual);

    // Установить шорткат для = через Enter
    QShortcut* shortcutEnter = new QShortcut(QKeySequence(Qt::Key_Enter), this);
    shortcutEnter->setContext(Qt::ApplicationShortcut);
    connect(shortcutEnter, &QShortcut::activated, this, [this]() {
        ui.pushButton_19->click();
        });
    m_shortcuts.append(shortcutEnter);

    // Установить шорткат для = через Return
    QShortcut* shortcutReturn = new QShortcut(QKeySequence(Qt::Key_Return), this);
    shortcutReturn->setContext(Qt::ApplicationShortcut);
    connect(shortcutReturn, &QShortcut::activated, this, [this]() {
        ui.pushButton_19->click();
        });
    m_shortcuts.append(shortcutReturn);

    // Установить шорткат для возведения в степень через Shift+6
    QShortcut* shortcutPower = new QShortcut(QKeySequence(Qt::SHIFT + Qt::Key_AsciiCircum), this);
    shortcutPower->setContext(Qt::ApplicationShortcut);
    connect(shortcutPower, &QShortcut::activated, this, [this]() {
        ui.pushButton_16->click();
        });
    m_shortcuts.append(shortcutPower);

    // Установить шорткат для ^
    QShortcut* shortcutPowerAlt = new QShortcut(QKeySequence(Qt::Key_AsciiCircum), this);
    shortcutPowerAlt->setContext(Qt::ApplicationShortcut);
    connect(shortcutPowerAlt, &QShortcut::activated, this, [this]() {
        ui.pushButton_16->click();
        });
    m_shortcuts.append(shortcutPowerAlt);

    // Установить шорткат для Backspace
    QShortcut* shortcutBackspace = new QShortcut(QKeySequence(Qt::Key_Backspace), this);
    shortcutBackspace->setContext(Qt::ApplicationShortcut);
    connect(shortcutBackspace, &QShortcut::activated, this, [this]() {
        ui.pushButton_22->click(); 
    });
    m_shortcuts.append(shortcutBackspace);

    // Установить шорткат для очистки
    QShortcut* shortcutC = new QShortcut(QKeySequence(Qt::Key_C), this);
    shortcutC->setContext(Qt::ApplicationShortcut);
    connect(shortcutC, &QShortcut::activated, this, [this]() {
        ui.pushButton_20->click();
    });
    m_shortcuts.append(shortcutC);

    // Установить шорткат для Esc (очистки)
    QShortcut* shortcutEscape = new QShortcut(QKeySequence(Qt::Key_Escape), this);
    shortcutEscape->setContext(Qt::ApplicationShortcut);
    connect(shortcutEscape, &QShortcut::activated, this, [this]() {
        ui.pushButton_20->click();
    });
    m_shortcuts.append(shortcutEscape);
}
