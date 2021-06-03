from copy import deepcopy

class Pizza:

    def __init__(self):
        self.components = ""

    def displayPizza(self):
        print(self.components)


class Cook:

    def __init__(self):
        self.pizza = Pizza()

    def addCheese(self):
        self.pizza.components += "-cheese\n"

    def addPepperoni(self):
        self.pizza.components += "-pepperoni\n"

    def addMushrooms(self):
        self.pizza.components += "-mushrooms\n"

    def addHam(self):
        self.pizza.components += "-ham\n"

    def addOlives(self):
        self.pizza.components += "-olives\n"

    def addTomatoes(self):
        self.pizza.components += "-tomatoes\n"

    def getPizza(self):
        ready_pizza = deepcopy(self.pizza)
        self.pizza = Pizza()
        return ready_pizza


if __name__ == '__main__':
    cook = Cook()

    cook.addCheese()
    cook.addPepperoni()
    cook.addMushrooms()
    cook.addOlives()

    pizza1 = cook.getPizza()

    cook.addCheese()
    cook.addTomatoes()
    cook.addMushrooms()
    cook.addHam()

    pizza2 = cook.getPizza()

    cook.addCheese()
    cook.addCheese()
    cook.addCheese()
    cook.addCheese()

    pizza_extra_cheese = cook.getPizza()

    pizza1.displayPizza()
    pizza2.displayPizza()
    pizza_extra_cheese.displayPizza()


