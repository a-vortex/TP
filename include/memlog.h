#pragma once

#include <ctime>
#include <cstdio>

namespace memlog {

struct MemLog {
    FILE* log;
    clockid_t clk_id;
    struct timespec inittime;
    long count;
    int fase;
    int ativo;
};

extern MemLog ml;

// constantes definindo os estados de registro
constexpr int MLATIVO = 1;
constexpr int MLINATIVO = 0;

#define LEMEMLOG(pos, tam, id) \
    ((void)((ml.ativo == MLATIVO) ? leMemLog(pos, tam, id) : 0))

#define ESCREVEMEMLOG(pos, tam, id) \
    ((void)((ml.ativo == MLATIVO) ? escreveMemLog(pos, tam, id) : 0))

int iniciaMemLog(char* nome);
int ativaMemLog();
int desativaMemLog();
int defineFaseMemLog(int f);
int leMemLog(long int pos, long int tam, int id);
int escreveMemLog(long int pos, long int tam, int id);
int finalizaMemLog();

} // namespace memlog