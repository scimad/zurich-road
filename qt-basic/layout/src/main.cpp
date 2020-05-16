#include <QtWidgets>
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    QLabel* label = new QLabel("Name");
    QLineEdit* lineEdit = new QLineEdit();

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(label);
    layout->addWidget(lineEdit);
    window.setLayout(layout);
    window.setWindowTitle("Layout usage");
    window.show();

    return app.exec();
}
