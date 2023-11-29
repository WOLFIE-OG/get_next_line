./build.sh
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out multiple_nlx5
