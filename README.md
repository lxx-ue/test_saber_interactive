# test_saber_interactive
Реализуйте функции сериализации и десериализации двусвязного списка<br><br>
**Примечание:** сериализация подразумевает сохранение и восстановление полной структуры списка, включая взаимное соотношение его элементов между собой — в том числе ссылок на Rand элементы.
<br><br>
Список состоит из пяти элементов:
1. red
2. green
3. blue
4. black
5. white
<br><br>
После выполнения функции Serialize() файл выглядит так:
```
red 3
green 1
blue 3
black 0
white 3
```
<br> А в консоль выводится следующая информация<br>
![serialization](https://github.com/lxx-ue/test_saber_interactive/blob/master/readme_img/serialization.jpg)
<br><br>
Проведя соотвествия между файлом и полями rand и data в консоли, видно, что они совпадают.
<br>
Далее после выполнения функции Deserialize() консоль выглядит так:
![deserialization](https://github.com/lxx-ue/test_saber_interactive/blob/master/readme_img/deserialization.jpg)
Можно заметить, что адреса изменились, а соответствие файлу - нет.
