#include <QApplication>
#include "air_widget.h"  // Tu nuevo widget
#include <mpi.h>

void procesarAIRSlave(int rankAIR);

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        QApplication app(argc, argv);
        AIR_Widget ventanaAIR;  // <-- aquí corregimos el tipo
        ventanaAIR.show();
        int resultado = app.exec();
        MPI_Finalize();
        return resultado;
    } else {
        procesarAIRSlave(rank);
        MPI_Finalize();
        return 0;
    }
}
