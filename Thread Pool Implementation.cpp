#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>

class ReverbGUI : public QMainWindow {
    Q_OBJECT

public:
    ReverbGUI() {
        QWidget *centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);

        QVBoxLayout *layout = new QVBoxLayout(centralWidget);
        textEdit = new QTextEdit(this);
        QPushButton *executeButton = new QPushButton("Execute", this);

        layout->addWidget(textEdit);
        layout->addWidget(executeButton);

        connect(executeButton, &QPushButton::clicked, this, &ReverbGUI::executeCommand);
    }

private slots:
    void executeCommand() {
        QString command = textEdit->toPlainText();
        // Here we would execute the command using Reverb runtime logic
        // For demonstration, just print the command
        std::cout << "Executing: " << command.toStdString() << std::endl;
    }

private:
    QTextEdit *textEdit;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ReverbGUI window;
    window.show();
    return app.exec();
}
