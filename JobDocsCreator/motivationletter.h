<<<<<<< HEAD
#ifndef MOTIVATIONLETTER_H
#define MOTIVATIONLETTER_H

#include <QMainWindow>

namespace Ui {
class MotivationLetter;
}

class MotivationLetter : public QMainWindow
{
    Q_OBJECT

public:
    explicit MotivationLetter(QWidget *parent = nullptr);
    ~MotivationLetter();

private slots:
    void saveLetter(); // Déclaration de la fonction saveLetter()
    void importText(); // Déclaration de la fonction importText()
    void setUnderline();
    void setBold();
    void setItalic();
    void alignLeft();
    void alignCenter();
    void alignRight();
    void alignJustify();
    void exportToPDF();


private:
    Ui::MotivationLetter *ui;
};

#endif // MOTIVATIONLETTER_H
=======
#ifndef MOTIVATIONLETTER_H
#define MOTIVATIONLETTER_H

#include <QMainWindow>

namespace Ui {
class MotivationLetter;
}

class MotivationLetter : public QMainWindow
{
    Q_OBJECT

public:
    explicit MotivationLetter(QWidget *parent = nullptr);
    ~MotivationLetter();

private slots:
    void saveLetter(); // Déclaration de la fonction saveLetter()
    void importText(); // Déclaration de la fonction importText()
    void setUnderline();
    void setBold();
    void setItalic();
    void alignLeft();
    void alignCenter();
    void alignRight();
    void alignJustify();
    void exportToPDF();


private:
    Ui::MotivationLetter *ui;
};

#endif // MOTIVATIONLETTER_H
>>>>>>> ba336fe8a1a1341289237f90e02930ca89c75333
