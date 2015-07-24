// main.cpp


#include "FenPrincipale.h"
#include "FenAdmin.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FenAdmin fenetre;
    fenetre.setWindowTitle("Interface Administrateur");
    fenetre.show();
    return app.exec();
}
