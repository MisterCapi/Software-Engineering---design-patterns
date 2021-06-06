from abc import abstractmethod
from typing import List


class Place:

    @abstractmethod
    def accept(self, visitor) -> None:
        pass


class ParkingLot(Place):

    def accept(self, visitor) -> None:
        visitor.visit_parking_lot(self)

    def park_the_vehicle(self) -> str:
        return "The vehicle is parked"


class PetrolStation(Place):
    """
    Same here: visitConcreteComponentB => ConcreteComponentB
    """

    def accept(self, visitor) -> None:
        visitor.visit_pertol_station(self)

    def fuel_the_vehicle(self) -> str:
        return "Vehicle is now fueled to the top"


class Visitor:

    @abstractmethod
    def visit_parking_lot(self, element: ParkingLot) -> None:
        pass

    @abstractmethod
    def visit_pertol_station(self, element: PetrolStation) -> None:
        pass


class Car(Visitor):
    def visit_parking_lot(self, element) -> None:
        print(f"{element.park_the_vehicle()} + Car")

    def visit_pertol_station(self, element) -> None:
        print(f"{element.fuel_the_vehicle()} + Car")


class Truck(Visitor):
    def visit_parking_lot(self, element) -> None:
        print(f"{element.park_the_vehicle()} + Truck")

    def visit_pertol_station(self, element) -> None:
        print(f"{element.fuel_the_vehicle()} + Truck")


def visit_all(places: List[Place], visitor: Visitor):
    for place in places:
        place.accept(visitor)


if __name__ == "__main__":
    places = [ParkingLot(), PetrolStation()]

    print("Visitor1: the Car")
    car = Car()
    visit_all(places, car)

    print("Visitor1: the Truck")
    truck = Truck()
    visit_all(places, truck)
