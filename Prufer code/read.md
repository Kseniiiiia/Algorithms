# Код Прюфера
Кодирование Прюфера переводит помеченные деревья порядка n в последовательность чисел от 1 до n по алгоритму:

Пока количество вершин больше двух:
- Выбирается лист v с минимальным номером
- В код Прюфера добавляется номер вершины, смежной с v
- Вершина v и инцидентное ей ребро удаляются из дерева.

Полученная последовательность называется кодом Прюфера для заданного дерева