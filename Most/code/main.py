from abc import abstractmethod


class Transmission:

    @abstractmethod
    def change_gear(self):
        pass


class Manual(Transmission):

    def change_gear(self):
        print("Changing gears with a stick shift")


class Automatic(Transmission):

    def change_gear(self):
        print("CPU is changing gears, you just put the pedal to the metal")


class Car:

    def __init__(self, transmission: Transmission):
        self.__transmission = transmission

    def drive(self):
        self.__transmission.change_gear()
        print("Brum brum!")


class Sedan(Car):
    pass


if __name__ == '__main__':
    auto_t = Automatic()
    sedan_a = Sedan(auto_t)

    manual_t = Manual()
    sedan_m = Sedan(manual_t)

    sedan_m.drive()
    sedan_a.drive()
