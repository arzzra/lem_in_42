**lem_in**
=====================
**О проекте**
-----------------------------------
Дано: Ориентированный граф: ноды - комнаты, связи - проходы между ними; муравьи, находящиеся в стартовой ноде; финишная нода.


В каждой комнате одновременно может находиться 1 муравей (кроме старта и финиша).


Задача: за наименьшее число ходов (за один ход можно переместить любое количество муравьёв,
не нарушая вышесказанного условия) провести всех муравьёв из старта в финиш.


Решение:
Выполняется поиск оптимального количества путей для заданного количества муравьев с помощью алгоритма Белмана-Форда и Джона Суурбале [wiki](https://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%A1%D1%83%D1%83%D1%80%D0%B1%D0%B0%D0%BB%D0%BB%D0%B5) . После нахожденмя нового пути выполняется расчет количества ходов. Время прохождения муравьев от старта к финишу, а также их распределение по путям рассчитывается исходя из того, что по кратчайшему пути должно идти максимальное количество муравьев, притом последний муравей проходит по самой кратчайшей пути.


Итог: Выбранный алгоритм идеально подошёл к задаче: среди критериев оценивания были время и точность.


**Запуск**
-----------------------------------
make


./lem-in [options] < ./generator [options]


(Для просмотра опций самой программы и  генератора используйте --help)
