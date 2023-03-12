c++ -Wall -Wextra -Werror -std=c++98 main.cpp -D NS=ft
./a.out # > a
echo "..................................."
echo "..................................."
c++ -Wall -Wextra -Werror -std=c++98 main.cpp -D NS=std
./a.out # > b
#diff a b
