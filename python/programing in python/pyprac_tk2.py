class Vehicle:
    current_fuel: int = 0
    def __init__(self, type: str, capacity_fual_ml: int):
        self.__type = type
        self.FUEL_CAPACITY = capacity_fual_ml
    def refuel(self, fuel_type: type, fuel_ml: int):
        raise NotImplementedError()
    
class Motorcycle(Vehicle):
    def __init__(self, capacity_fual_ml: int):
        super().__init__('Motorcycle', capacity_fual_ml) 
    def refuel(self, fuel_type: str, fuel_ml: int):
        if fuel_type in ['Unleaded-Gasoline-#92', 'Unleaded-Gasoline-#95']:
            return min(self.FUEL_CAPACITY, fuel_ml)
        else:
            return 0
        
print(Motorcycle(int(input())).refuel(input(), int(input())))