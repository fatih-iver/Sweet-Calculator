#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QObject>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QVector>
#include <QString>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow()
    {
        // Instantiate and Initialize Vertical Layout
        QVBoxLayout *vBoxLayout = new QVBoxLayout;

        // Set spacing and margins to 0
        vBoxLayout->setSpacing(0);
        vBoxLayout->setMargin(0);

        {

            // Initialize Display Row
            labelDisp = new QLabel("");

            // Set Aligment to be Right Justified
            labelDisp->setAlignment(Qt::AlignRight);

            // Style Display by using CSS Style Sheet as String
            labelDisp->setStyleSheet("QLabel { "
                                     "font-size: 18px;"
                                     "background-color : #D9F3F3; "
                                     "border: 1px solid black;"
                                     " }");
            // Set maximum witdt to prevent overflow
            labelDisp->setMaximumWidth(300);

            // Add display to the vertical layout
            vBoxLayout->addWidget(labelDisp);

            // Initialize First Row Elements

            buttonMult = new QPushButton("*");
            buttonDiv = new QPushButton("/");
            buttonHex = new QPushButton("Hex");
            buttonDec = new QPushButton("Dec");


            // Connect Slots (Click Handler) to the initialized first frow elements
            QObject::connect(buttonMult, SIGNAL (clicked()), this, SLOT (buttonMultAction()));
            QObject::connect(buttonDiv, SIGNAL (clicked()), this, SLOT (buttonDivAction()));
            QObject::connect(buttonHex, SIGNAL (clicked()), this, SLOT (buttonHexAction()));
            QObject::connect(buttonDec, SIGNAL (clicked()), this, SLOT (buttonDecAction()));

            // Create a horizontal layout to display 4 buttons next to each other
            QHBoxLayout *hBoxLayout1 = new QHBoxLayout;

            // Again set horizontal layout spacing to 0
            hBoxLayout1->setSpacing(0);

            // Add first row buttons to the horizontal layout
            hBoxLayout1->addWidget(buttonMult);
            hBoxLayout1->addWidget(buttonDiv);
            hBoxLayout1->addWidget(buttonHex);
            hBoxLayout1->addWidget(buttonDec);

            // Add horizontal layout to the vertical layout
            vBoxLayout -> addLayout(hBoxLayout1);

            // Initialize Second Row Elements - For Comments Look At First Row - They are Same

            buttonAdd = new QPushButton("+");
            buttonSub = new QPushButton("-");
            buttonEq = new QPushButton("=");
            buttonClr = new QPushButton("Clr");

            QObject::connect(buttonAdd, SIGNAL (clicked()), this, SLOT (buttonAddAction()));
            QObject::connect(buttonSub, SIGNAL (clicked()), this, SLOT (buttonSubAction()));
            QObject::connect(buttonEq, SIGNAL (clicked()), this, SLOT (buttonEqAction()));
            QObject::connect(buttonClr, SIGNAL (clicked()), this, SLOT (buttonClrAction()));

            QHBoxLayout *hBoxLayout2 = new QHBoxLayout;

            hBoxLayout2->setSpacing(0);

            hBoxLayout2->addWidget(buttonAdd);
            hBoxLayout2->addWidget(buttonSub);
            hBoxLayout2->addWidget(buttonEq);
            hBoxLayout2->addWidget(buttonClr);

            vBoxLayout->addLayout(hBoxLayout2);

            // Initialize Third Row Elements

            button0 = new QPushButton("0");
            button1 = new QPushButton("1");
            button2 = new QPushButton("2");
            button3 = new QPushButton("3");

            QObject::connect(button0, SIGNAL (clicked()), this, SLOT (button0Action()));
            QObject::connect(button1, SIGNAL (clicked()), this, SLOT (button1Action()));
            QObject::connect(button2, SIGNAL (clicked()), this, SLOT (button2Action()));
            QObject::connect(button3, SIGNAL (clicked()), this, SLOT (button3Action()));

            QHBoxLayout *hBoxLayout3 = new QHBoxLayout;

            hBoxLayout3->setSpacing(0);

            hBoxLayout3->addWidget(button0);
            hBoxLayout3->addWidget(button1);
            hBoxLayout3->addWidget(button2);
            hBoxLayout3->addWidget(button3);

            vBoxLayout -> addLayout(hBoxLayout3);

            // Initialize Fourth Row Elements - For Comments Look At First Row - They are Same

            button4 = new QPushButton("4");
            button5 = new QPushButton("5");
            button6 = new QPushButton("6");
            button7 = new QPushButton("7");

            QObject::connect(button4, SIGNAL (clicked()), this, SLOT (button4Action()));
            QObject::connect(button5, SIGNAL (clicked()), this, SLOT (button5Action()));
            QObject::connect(button6, SIGNAL (clicked()), this, SLOT (button6Action()));
            QObject::connect(button7, SIGNAL (clicked()), this, SLOT (button7Action()));

            QHBoxLayout *hBoxLayout4 = new QHBoxLayout;

            hBoxLayout4->setSpacing(0);

            hBoxLayout4->addWidget(button4);
            hBoxLayout4->addWidget(button5);
            hBoxLayout4->addWidget(button6);
            hBoxLayout4->addWidget(button7);

            vBoxLayout -> addLayout(hBoxLayout4);

            // Initialize Fifth Row Elements - For Comments Look At First Row - They are Same

            button8 = new QPushButton("8");
            button9 = new QPushButton("9");
            buttonA = new QPushButton("A");
            buttonB = new QPushButton("B");

            QObject::connect(button8, SIGNAL (clicked()), this, SLOT (button8Action()));
            QObject::connect(button9, SIGNAL (clicked()), this, SLOT (button9Action()));
            QObject::connect(buttonA, SIGNAL (clicked()), this, SLOT (buttonAAction()));
            QObject::connect(buttonB, SIGNAL (clicked()), this, SLOT (buttonBAction()));

            QHBoxLayout *hBoxLayout5 = new QHBoxLayout;

            hBoxLayout5->setSpacing(0);

            hBoxLayout5->addWidget(button8);
            hBoxLayout5->addWidget(button9);
            hBoxLayout5->addWidget(buttonA);
            hBoxLayout5->addWidget(buttonB);

            vBoxLayout -> addLayout(hBoxLayout5);

            // Initialize Sixth Row Elements - For Comments Look At First Row - They are Same

            buttonC = new QPushButton("C");
            buttonD = new QPushButton("D");
            buttonE = new QPushButton("E");
            buttonF = new QPushButton("F");

            QObject::connect(buttonC, SIGNAL (clicked()), this, SLOT (buttonCAction()));
            QObject::connect(buttonD, SIGNAL (clicked()), this, SLOT (buttonDAction()));
            QObject::connect(buttonE, SIGNAL (clicked()), this, SLOT (buttonEAction()));
            QObject::connect(buttonF, SIGNAL (clicked()), this, SLOT (buttonFAction()));

            QHBoxLayout *hBoxLayout6 = new QHBoxLayout;

            hBoxLayout6->setSpacing(0);

            hBoxLayout6->addWidget(buttonC);
            hBoxLayout6->addWidget(buttonD);
            hBoxLayout6->addWidget(buttonE);
            hBoxLayout6->addWidget(buttonF);

            vBoxLayout -> addLayout(hBoxLayout6);

            // Disable Hex Buttons
            updateHexButtons();

            // Disable Buttons
            updateOperatorButtons(false);

        }
        // Create widget to display previosly created item
        QWidget *widget = new QWidget();
        // Set Layout of the widget as the previously created vertical layout
        widget->setLayout(vBoxLayout);
        // Set is as central widget so that user is able to see it
        setCentralWidget(widget);
    }

    QString calculateResult(QString inputString){

        int indexCounter = 0;
        QVector<QString> inputs(inputString.size(), "");
        for(QChar &inputChar: inputString){
            if (inputChar == '*' || inputChar == '/' || inputChar == '+' || inputChar == '-'){
                indexCounter += 1;
                inputs[indexCounter] += inputChar;
                indexCounter += 1;
            } else{
                inputs[indexCounter] += inputChar;
            }
        }

        inputs.erase(inputs.begin()+indexCounter+1, inputs.end());

        if(isHex){
            for(QString &elem: inputs){
                if (elem != '*' && elem != '/' && elem != '+' && elem != '-'){

                    bool bStatus = false;
                    int nHex = elem.toInt(&bStatus,16);

                    if(bStatus)
                        elem = QString::number(nHex);
                    else
                        return "Error: HEX Conversion!";

                }
            }
        }

        QVector<QString> afterMult;

        while (inputs.size() != 0){
            QString input = inputs.front();
            inputs.erase(inputs.begin());

            if(input == "*" || input == "/"){

                int secondOperand = inputs.front().toInt();
                inputs.pop_front();

                int firstOperand = afterMult.back().toInt();
                afterMult.pop_back();

                if(input == "*")
                    afterMult.push_back(QString::number(firstOperand * secondOperand));
                else{

                    if(secondOperand == 0)
                        return "Error: Division by Zero";

                    afterMult.push_back(QString::number(firstOperand / secondOperand));
                }

            }else{
               afterMult.push_back(input);
            }

        }

        QVector<QString> afterSum;

        while (afterMult.size() != 0){
            QString input = afterMult.front();
            afterMult.erase(afterMult.begin());

            if(input == "+" || input == "-"){

                int secondOperand = afterMult.front().toInt();
                afterMult.pop_front();

                int firstOperand = afterSum.back().toInt();
                afterSum.pop_back();

                if(input == "+")
                    afterSum.push_back(QString::number(firstOperand+secondOperand));
                else
                    afterSum.push_back(QString::number(firstOperand-secondOperand));

            }else{
               afterSum.push_back(input);
            }

        }
        // Return first element which is result of calculation

        // if Hex is pressed, convert result to hex - base 16, use toUpper to have it with uppercase letters
        if(isHex){
           return  QString::number( afterSum.front().toInt(), 16).toUpper();
        }

        return afterSum.front();
    }

    // Reset Display - Set it to Empty String
    void resetDisplay(){
        labelDisp->setText("");
        reset = false;
    }

    // Lock Hex Buttons when Mode is DEC
    void updateHexButtons(){
        buttonA->setEnabled(isHex);
        buttonB->setEnabled(isHex);
        buttonC->setEnabled(isHex);
        buttonD->setEnabled(isHex);
        buttonE->setEnabled(isHex);
        buttonF->setEnabled(isHex);
    }

    // Lock Operator Buttons after an Operator is Present
    void updateOperatorButtons(bool value){
        buttonMult->setEnabled(value);
        buttonDiv->setEnabled(value);
        buttonAdd->setEnabled(value);
        buttonSub->setEnabled(value);
        buttonEq->setEnabled(value);
    }

private slots:
    void buttonMultAction(){
        // Add * operator to the screen
        labelDisp->setText(labelDisp->text() + "*");
        updateOperatorButtons(false);
    }
    void buttonDivAction(){
        // Add / operator to the screen
        labelDisp->setText(labelDisp->text() + "/");
        updateOperatorButtons(false);
    }
    // Enable Hex Buttons
    void buttonHexAction(){
        // Let other components to know Hex is enabled
        isHex = true;
        // Enable Hex Buttons
        updateHexButtons();
        // Tell user hex is enabled
        labelDisp->setText("Number System: HEX");
        // After clicking a hex digit, notification will be lost and entered digit will be seen
        reset = true;
        // A digit is expecting from now on, disable operator buttons
        updateOperatorButtons(false);
    }

    // Disable Hex Buttons - Look for buttonHexAction() for comments - Functionality Same
    void buttonDecAction(){
        isHex = false;
        updateHexButtons();
        labelDisp->setText("Number System: DEC");
        reset = true;
        updateOperatorButtons(false);
    }
    // Add + operator to the screen and disable operators
    void buttonAddAction(){
        labelDisp->setText(labelDisp->text() + "+");
        updateOperatorButtons(false);
    }
    // Add - operator to the screen and disable operators
    void buttonSubAction(){
        labelDisp->setText(labelDisp->text() + "-");
        updateOperatorButtons(false);
    }
    // Read Screen then call calculateResult, set reset to be true and disable operator buttons
    void buttonEqAction(){
        labelDisp->setText(calculateResult(labelDisp->text()));
        reset = true;
        updateOperatorButtons(false);
    }
    // Set empty string to the screen, disable operator buttons, set reset to false
    void buttonClrAction(){
        labelDisp->setText("");
        reset = false;
        updateOperatorButtons(false);
    }
    // This comment are valid for all these 0-F actions buttons

    // If reset is true, which means screen needs to be reseted, then reset it by calling resetDisplay()
    // After cleaning screen, add pressed digit to the screen
    // Then enable operator buttons, it is enough to have one digit to accept next operator

    void button0Action(){
        if(reset) resetDisplay();
        labelDisp->setText(labelDisp->text() + "0");
        updateOperatorButtons(true);
    }
    void button1Action(){
        if(reset) resetDisplay();
        labelDisp->setText(labelDisp->text() + "1");
        updateOperatorButtons(true);
    }
    void button2Action(){
        if(reset) resetDisplay();
        labelDisp->setText(labelDisp->text() + "2");
        updateOperatorButtons(true);
    }
    void button3Action(){
        if(reset) resetDisplay();
        labelDisp->setText(labelDisp->text() + "3");
        updateOperatorButtons(true);
    }

    // If reset is true, which means screen needs to be reseted, then reset it by calling resetDisplay()
    // After cleaning screen, add pressed digit to the screen
    // Then enable operator buttons, it is enough to have one digit to accept next operator

    void button4Action(){
        if(reset) resetDisplay();
        labelDisp->setText(labelDisp->text() + "4");
        updateOperatorButtons(true);
    }
    void button5Action(){
        if(reset) resetDisplay();
        labelDisp->setText(labelDisp->text() + "5");
        updateOperatorButtons(true);
    }
    void button6Action(){
        if(reset) resetDisplay();
        labelDisp->setText(labelDisp->text() + "6");
        updateOperatorButtons(true);
    }
    void button7Action(){
        if(reset) resetDisplay();
        labelDisp->setText(labelDisp->text() + "7");
        updateOperatorButtons(true);
    }

    // If reset is true, which means screen needs to be reseted, then reset it by calling resetDisplay()
    // After cleaning screen, add pressed digit to the screen
    // Then enable operator buttons, it is enough to have one digit to accept next operator

    void button8Action(){
        if(reset) resetDisplay();
        labelDisp->setText(labelDisp->text() + "8");
        updateOperatorButtons(true);
    }
    void button9Action(){
        if(reset) resetDisplay();
        labelDisp->setText(labelDisp->text() + "9");
        updateOperatorButtons(true);
    }
    void buttonAAction(){
        if(reset) resetDisplay();
        labelDisp->setText(labelDisp->text() + "A");
        updateOperatorButtons(true);
    }
    void buttonBAction(){
        if(reset) resetDisplay();
        labelDisp->setText(labelDisp->text() + "B");
        updateOperatorButtons(true);
    }

    // If reset is true, which means screen needs to be reseted, then reset it by calling resetDisplay()
    // After cleaning screen, add pressed digit to the screen
    // Then enable operator buttons, it is enough to have one digit to accept next operator

    void buttonCAction(){
        if(reset) resetDisplay();
        labelDisp->setText(labelDisp->text() + "C");
        updateOperatorButtons(true);
    }
    void buttonDAction(){
        if(reset) resetDisplay();
        labelDisp->setText(labelDisp->text() + "D");
        updateOperatorButtons(true);
    }
    void buttonEAction(){
        if(reset) resetDisplay();
        labelDisp->setText(labelDisp->text() + "E");
        updateOperatorButtons(true);
    }
    void buttonFAction(){
        if(reset) resetDisplay();
        labelDisp->setText(labelDisp->text() + "F");
        updateOperatorButtons(true);
    }

private:
   // Instantiate Display - QLabel
   QLabel *labelDisp;

   // Instantiate *, /, Hex, Dec - Buttons
   QPushButton *buttonMult;
   QPushButton *buttonDiv;
   QPushButton *buttonHex;
   QPushButton *buttonDec;

   // Instantiate +, -, Eq, Clr - Buttons
   QPushButton *buttonAdd;
   QPushButton *buttonSub;
   QPushButton *buttonEq;
   QPushButton *buttonClr;

   // Instantiate 0, 1, 2, 3 - Buttons
   QPushButton *button0;
   QPushButton *button1;
   QPushButton *button2;
   QPushButton *button3;

   // Instantiate 4, 5, 6, 7 - Buttons
   QPushButton *button4;
   QPushButton *button5;
   QPushButton *button6;
   QPushButton *button7;

   // Instantiate 8, 9, A, B - Buttons
   QPushButton *button8;
   QPushButton *button9;
   QPushButton *buttonA;
   QPushButton *buttonB;

   // Instantiate C, D, E, F - Buttons
   QPushButton *buttonC;
   QPushButton *buttonD;
   QPushButton *buttonE;
   QPushButton *buttonF;

   // is Hex Button Pressed
   bool isHex = false;
   // is Reset Required
   bool reset = false;

};

#endif // MAINWINDOW_H
