class Car:
    def __init__(self, marka, model, kuzov, year, cost):
        self.marka = marka
        self.model = model
        self.kuzov = kuzov
        self.year = year
        self.cost = cost

    def __str__(self):
        return f"{self.marka} {self.model} ({self.kuzov}, {self.year}, {self.cost}рублей)"

# чтение данных из файла и создание списка объектов
cars_list = []
with open("cars.txt", "r") as file:
    for line in file:
        data = line.strip().split(",")
        marka = data[0]
        model = data[1]
        kuzov = data[2]
        year = int(data[3])
        cost = int(data[4])
        cars_list.append(Car(marka, model, kuzov, year, cost))

# вывод информации обо всех автомобилях
print("Информация обо всех автомобилях:")
for car in cars_list:
    print(car)

# проверка, если год выпуска старшее 2000, то удаляем
cars_list = [car for car in cars_list if (car.year > 2000)]

# вывод информации об автомобилях после удаления(удалится хонда ТК она 1998 года и лада гранта ТК она 1999 года
print("\nИнформация об автомобилях после удаления старых:")
for car in cars_list:
    print(car)
