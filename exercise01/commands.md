# Filas - Secuencial 1 hilo
valgrind --tool=cachegrind --cachegrind-out-file=cachegrind.row_seq ./exercise01 1

# Filas - Paralelo 2 hilos
OMP_NUM_THREADS=2 valgrind --tool=cachegrind --cachegrind-out-file=cachegrind.row_par_2 ./exercise01 2

# Filas - Paralelo 3 hilos
OMP_NUM_THREADS=3 valgrind --tool=cachegrind --cachegrind-out-file=cachegrind.row_par_3 ./exercise01 2

# Filas - Paralelo 4 hilos
OMP_NUM_THREADS=4 valgrind --tool=cachegrind --cachegrind-out-file=cachegrind.row_par_4 ./exercise01 2

# Columnas - Secuencial 1 hilo
valgrind --tool=cachegrind --cachegrind-out-file=cachegrind.col_seq ./exercise01 3

# Columnas - Paralelo 2 hilos
OMP_NUM_THREADS=2 valgrind --tool=cachegrind --cachegrind-out-file=cachegrind.col_par_2 ./exercise01 4

# Columnas - Paralelo 3 hilos
OMP_NUM_THREADS=3 valgrind --tool=cachegrind --cachegrind-out-file=cachegrind.col_par_3 ./exercise01 4

# Columnas - Paralelo 4 hilos
OMP_NUM_THREADS=4 valgrind --tool=cachegrind --cachegrind-out-file=cachegrind.col_par_4 ./exercise01 4