class Vehicle:
    current_fuel: int = 0
    def __init__(self, type: str, capacity_fual_ml: int) -> None:
        self.__type = type
        self.FUEL_CAPACITY = capacity_fual_ml
    def __str__(self) -> str:
        return f'Vehicle Type: {self.__type}\nFuel Capacity: {self.FUEL_CAPACITY}\nCurrent Fuel: {self.current_fuel}'
    def refuel(self, fuel_type: type, fuel_ml: int) -> None:
        raise NotImplementedError()
    
class Motorcycle(Vehicle):
    def __init__(self, capacity_fual_ml: int):
        super().__init__('Motorcycle', capacity_fual_ml) 
    def refuel(self, fuel_type: str, fuel_ml: int):
        if fuel_type in ['Unleaded-Gasoline-#92', 'Unleaded-Gasoline-#95']:
            self.current_fuel = min(self.FUEL_CAPACITY, fuel_ml)

class Bus(Vehicle):
    def __init__(self, capacity_fual_ml: int):
        super().__init__('Bus', capacity_fual_ml) 
    def refuel(self, fuel_type: str, fuel_ml: int):
        if fuel_type in ['Unleaded-Gasoline-#92', 'Premium-Diesel']:
            self.current_fuel = min(self.FUEL_CAPACITY, fuel_ml)
 
class Car(Vehicle):
    def __init__(self, capacity_fual_ml: int):
        super().__init__('Car', capacity_fual_ml) 
    def refuel(self, fuel_type: str, fuel_ml: int):
        if fuel_type in ['Unleaded-Gasoline-#98', 'Unleaded-Gasoline-#95']:
            self.current_fuel = min(self.FUEL_CAPACITY, fuel_ml)
        
def gen_vehicle(s): return {'B': lambda: Bus(int(input())),
                            'C': lambda: Car(int(input())),
                            'M': lambda: Motorcycle(int(input()))}[s]()

for s in ['B', 'C', 'M']:
    v = gen_vehicle(s)
    #print(v)
    v.refuel(input(), int(input()))
    print(v)
        