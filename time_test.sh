c++ -Wall -Wextra -Werror -std=c++98 main.cpp -D NS=ft
time ./a.out # > a
echo "..................................."
echo "..................................."
c++ -Wall -Wextra -Werror -std=c++98 main.cpp -D NS=std
time ./a.out # > b
#diff a b
