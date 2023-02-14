c++ -Wall -Wextra -Werror -std=c++98 main.cpp -D NS=ft
valgrind ./a.out # > a
echo "..................................."
echo "..................................."
c++ -Wall -Wextra -Werror -std=c++98 main.cpp -D NS=std
valgrind ./a.out # > b
#diff a b
