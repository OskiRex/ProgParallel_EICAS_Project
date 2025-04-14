#include <mpi.h>
#include <omp.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <thread>
#include <chrono>
#include <cmath>
#include <cstring>

const int AIR_TOTAL_COLUMNAS = 21;

const int AIR_FILA_TRIM_L = 15000;
const int AIR_FILA_PACK_L = 30000;
const int AIR_FILA_COMP3 = 162500;
const int AIR_FILA_FAN_UP = 450000;
const int AIR_FILA_TEMP_Z4 = 675000;
const int AIR_FILA_MANIFOLD = 1225000;
const int AIR_FILA_PACK_R = 2062500;

void procesarRank1AIR(const std::vector<float>& fila, int filaActualAIR) {
    std::ofstream debug("rank1_log.txt", std::ios::app);
    debug << "[RANK1] Procesando fila: " << filaActualAIR << std::endl;

    if (filaActualAIR >= AIR_FILA_TRIM_L && static_cast<int>(fila[8]) != 1) {
        debug << "[DEBUG][RANK1] Detectada condici\xF3n TRIM_L en fila " << filaActualAIR << std::endl;
        std::string alerta = "LEFT TRIM FAIL CLOSE|red";
        MPI_Send(alerta.c_str(), alerta.size() + 1, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
    }

    if (filaActualAIR >= AIR_FILA_TEMP_Z4 && std::abs(fila[3] - 23.0f) > 2.0f) {
        std::string alerta = "ZONE 4 TEMP HIGH|orange";
        debug << "[DEBUG] Enviando alerta desde Rank 1: " << alerta << std::endl;
        MPI_Send(alerta.c_str(), alerta.size() + 1, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
    }

#pragma omp parallel for num_threads(8)
    for (int i = 0; i < 8; ++i) {
        if (i != 3 && (fila[i] < 20.0f || fila[i] > 26.0f)) {
#pragma omp critical
            debug << "[POSIBLE FALLA] Fila " << filaActualAIR << " - Zona " << i + 1 << " TEMP fuera de rango" << std::endl;
        }
    }

    if (static_cast<int>(fila[9]) != 1) {
        debug << "[POSIBLE FALLA] Fila " << filaActualAIR << " - TRIM_R valor inesperado" << std::endl;
    }
    debug.close();
}

void procesarRank2AIR(const std::vector<float>& fila, int filaActualAIR) {
    std::ofstream debug("rank2_log.txt", std::ios::app);
    debug << "[RANK2] Procesando fila: " << filaActualAIR << std::endl;

    if (filaActualAIR >= AIR_FILA_PACK_L && fila[14] < 35.0f) {
        debug << "[DEBUG][RANK2] Detectada condici\xF3n PACK_L en fila " << filaActualAIR << std::endl;
        std::string alerta = "PACK LEFT FAIL|red";
        MPI_Send(alerta.c_str(), alerta.size() + 1, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
    }
    if (filaActualAIR >= AIR_FILA_COMP3 && static_cast<int>(fila[12]) == 0) {
        std::string alerta = "COMPRESSOR 3 OFF|orange";
        MPI_Send(alerta.c_str(), alerta.size() + 1, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
    }
    if (filaActualAIR >= AIR_FILA_FAN_UP && static_cast<int>(fila[18]) == 0) {
        std::string alerta = "UPPER FAN INOP|red";
        MPI_Send(alerta.c_str(), alerta.size() + 1, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
    }
    if (filaActualAIR >= AIR_FILA_PACK_R && static_cast<int>(fila[17]) == 0) {
        std::string alerta = "PACK RIGHT INOP|orange";
        MPI_Send(alerta.c_str(), alerta.size() + 1, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
    }

    if (static_cast<int>(fila[10]) != 1) debug << "[FALLA] Fila " << filaActualAIR << " - COMPRESSOR 1 INOP" << std::endl;
    if (static_cast<int>(fila[11]) != 1) debug << "[FALLA] Fila " << filaActualAIR << " - COMPRESSOR 2 INOP" << std::endl;
    if (static_cast<int>(fila[13]) != 1) debug << "[FALLA] Fila " << filaActualAIR << " - COMPRESSOR 4 INOP" << std::endl;
    if (static_cast<int>(fila[16]) != 1) debug << "[FALLA] Fila " << filaActualAIR << " - PACK L OFF" << std::endl;

    if (fila[15] < 36.0f || fila[15] > 42.0f) {
        std::string alerta = "PACK R PRESSURE OUT OF RANGE|orange";
        MPI_Send(alerta.c_str(), alerta.size() + 1, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
    }
    debug.close();
}

void procesarRank3AIR(const std::vector<float>& fila, int filaActualAIR) {
    std::ofstream debug("rank3_log.txt", std::ios::app);
    debug << "[RANK3] Procesando fila: " << filaActualAIR << std::endl;

    if (filaActualAIR >= AIR_FILA_MANIFOLD && fila[20] > 15.0f) {
        std::string alerta = "MANIFOLD PRESSURE HIGH|red";
        MPI_Send(alerta.c_str(), alerta.size() + 1, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
    }
    if (static_cast<int>(fila[19]) != 1) {
        debug << "[FALLA] Fila " << filaActualAIR << " - LOWER FAN INOP" << std::endl;
    }
    debug.close();
}

void procesarAIRSlave(int rankAIR) {
    std::ofstream logFile("log_rank" + std::to_string(rankAIR) + ".txt");
    logFile << "[INFO] Rank " << rankAIR << " inici\xF3 procesamiento." << std::endl;
    logFile.flush();

    std::string lineaAIR;
    int filaGlobalAIR = 0;

    while (true) {
        char buffer[512] = {0};
        MPI_Status status;
        int flag = 0;
        MPI_Iprobe(0, 0, MPI_COMM_WORLD, &flag, &status);
        if (!flag) {
            std::this_thread::sleep_for(std::chrono::milliseconds(2));
            continue;
        }
        MPI_Recv(buffer, sizeof(buffer), MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        if (strcmp(buffer, "FIN") == 0) break;

        std::istringstream iss(buffer);
        std::string valor;
        std::vector<float> fila;
        while (std::getline(iss, valor, ',')) {
            fila.push_back(std::stof(valor));
        }

        if (rankAIR == 1) procesarRank1AIR(fila, filaGlobalAIR);
        if (rankAIR == 2) procesarRank2AIR(fila, filaGlobalAIR);
        if (rankAIR == 3) procesarRank3AIR(fila, filaGlobalAIR);

        filaGlobalAIR++;
    }

    logFile << "[INFO] Rank " << rankAIR << " finaliz\xF3 procesamiento." << std::endl;
    logFile.close();
}
