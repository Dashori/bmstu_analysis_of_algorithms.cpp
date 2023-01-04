from dataclasses import dataclass

from salesman import help_salesman, parameterization
from graph_result import get_graph_result
from time_test import print_time

@dataclass
class Menu:
    """
        Константы необходимые в меню.
    """

    msg = "\nМЕНЮ:\n" + \
          "1. Полный перебор\n" + \
          "2. Муравьиный алгоритм\n" + \
          "3. Оба алгоритма\n" + \
          "4. Построить графики\n" + \
          "5. Замерить время\n" + \
          "6. Параметризация\n" + \
          "0. Выход\n" + \
          "Выбор: "

    exit = 0
    full = 1
    ant = 2
    both = 3
    plot = 4
    measure = 5
    param = 6


def process():

    process = True

    while process:
        command = int(input(Menu.msg))

        if command == Menu.full:
            help_salesman(Menu.full)
        elif command == Menu.ant:
            help_salesman(Menu.ant)
        elif command == Menu.both:
            help_salesman(Menu.both)
        elif command == Menu.plot:
            get_graph_result()
        elif command == Menu.measure:
            print_time()
        elif command == Menu.param:
            parameterization()
        elif command == Menu.exit:
            process = False
        else:
            print("\nВыбран неверный пункт меню.\n")


if __name__ == "__main__":
    process()
