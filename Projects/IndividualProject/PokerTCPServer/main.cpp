#include <QApplication>
#include <pokerserver.h>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PokerServer server;
    if (!server.listen(QHostAddress::Any, 2015)) {
        qDebug() << "Failed to bind to port";
        return 1;
    }

    QPushButton quitButton("Quit");
    quitButton.setWindowTitle("Poker Server");
    QObject::connect(&quitButton, SIGNAL(clicked()),
                     &a, SLOT(quit()));
    quitButton.setMinimumWidth(250);
    quitButton.setMinimumHeight(100);
    quitButton.show();

    return a.exec();
}

