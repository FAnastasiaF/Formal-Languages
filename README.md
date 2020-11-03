# Практикум №1

### [![Build Status](https://travis-ci.com/FAnastasiaF/Formal-Languages.svg?token=uBX54u6DiMPNbKZv3Hs7&branch=Practical_Work_1)](https://travis-ci.com/FAnastasiaF/Formal-Languages)

#### Задача:
*(18 вариант)*

На ввод подается язык из символов из {a, b, c, 1, ., +, *}. Даны α и буква x. Найти максимальное k, такое что в L есть слова, начинающиеся с x^k.

#### Алгоритм:

У нас есть 7 состояний(typesymbol). И пара(max) состоящая из возможных(максимальных) k для последнего регулярного выражения
 * 0 - Начинается не на x // max = {0,0}
 * 1 - Единица // max = {0,0}
 * 2 - Начинается на x, состоит не только из x // max = {#x до первого не x, #x до первого не x}
 * 3 - Состоит только из x, но не x* // max = {#x, #x}
 * 4 - Начинается x* // max = {0,0} - для удобства 
 * 5 - (1 + 2) // max = {0, #x до первого не x}
 * 6 - (3 + 2) // max = {#x, #x до первого не x}
 
Считываем регулярное выражение и букву x. Проходимся по каждому элементу и запихиваем его состояние в 1 стек и пару из возможных k в 2 стек, 
если этот элемент буква. 
А если это операция, то извлекаем нужное количество элементов из стеков 1 и 2(2 элемента для "+" и "." и 1 для "*"), 
делаем с ними эти операции(результаты операций для различных состояний будут приведены в отдельном файле) 
и возвращаем на оба стека результаты. Данный алгоритм работает за O(длины заданного регулярного выражения).

#### Запуск:

Для того чтобы запустить тесты,
воспользуйтесь командами:

```cmake -DDEBUG=1```

```make```

```./first-practical-work```

Для запуска программы воспользуйтесь командами:

```cmake```

```make```

```./first-practical-work```

