# Мануал

## САМОЕ УЛЬТРА МЕГА ВАЖНОЕ

Каждый должен работать в своей ветке (желательно называть ветки так, чтобы мы могли понимать у кого чья). За пуш в main минус баллы)

Все задания делаем СТРОГО по порядку и после завершения выполнения КАЖДОГО модуля, сразу закидываем иего в гитхаб!

## Распределение заданий:


Александр Снигерев

N-3, N-8, N-13, Z-4, Z-9, Q-4, P-1, P-6, P-11


## Документирование кода

Каждый модуль предлагаю документировать в Doxygen (https://www.doxygen.nl/download.html). Для тех, кто никогда не использовал Doxygen, прилагаю статью с обзором и инструкцией: https://habr.com/ru/articles/252101/. Документировать необходимо так, чтобы в вашем коде смогли разобраться все участники.

## Язык программирования и все такое

Программируем на C++. Компилятор выбирайте на свой вкус (от себя могу посоветовать Clang++). Писать код мы будем на стандарте C++17. Личная рекомендация (настоятельная :)): Пусть компилятор обрабатывает все предупреждения как ошибки. Так менее вероятно засесть с какой-то ошибкой (переросшей из предупреждения) в будущем. От себя рекомендую следующие флаги для вашего компилятора: 

```
 -g --debug -Wall -Wshadow -Werror -Wextra -Weffc++ -Wconversion -std=c++17
```

Так же прилагаю свой Makefile:

```
CXX = clang++
CXXFLAGS = -g --debug -Wall -Wshadow -Werror -Wextra -Weffc++ -Wconversion -std=c++17

TARGET = main
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
```

Делать GUI мы не будем. По крайней мере до момента, пока мы точно не узнаем, будет ли такая программа считаться альт экзаменом. Поэтому программу реализовываем с CLI. 

### Касаемо код стайла

Я использую свой код стайл, немного отличный от Гугловского. Если кто-то использует clang-format, то обратитесь ко мне, я выдам вам свой пресет. Иначе, следуйте код стайлу от Google (https://google.github.io/styleguide/cppguide.html). Для инициализации переменных предлагаю выбрать инициализацию списком. В конце, когда все будет готово, я могу все отформатировать, используя собственный clang-format, чтобы код выглядел аккуратно и читаемо.

## Тесты и GitHub Actions

Имея небольшой опыт работы с GitHub Actions, я беру на себя ответственность за его реализацию и поддержку (но не обещаю :)). Но для начала нам необходимо написать тесты для каждого модуля.

При каждом пуше, код автоматически будет проверяться в Github Actions, проводя все прописанные тесты. Таким образом, мы будем уверены, что каждый модуль точно исправно работает.
