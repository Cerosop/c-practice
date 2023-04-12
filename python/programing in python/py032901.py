class Shape:
    def draw(self) -> None:
        print('Draw shape')
 
### Your code start here ###
class Circle(Shape):
    def draw(self) -> None:
        print('Draw circle')

class Square(Shape):
    def draw(self) -> None:
        print('Draw square')
        
class Triangle(Shape):
    def draw(self) -> None:
        print('Draw triangle')

### End ###
 
SHAPE_MAP = {'Shape': lambda: Shape(), 'Circle': lambda: Circle(), 'Square': lambda: Square(), 'Triangle': lambda: Triangle()}
for s in input().split():
    SHAPE_MAP[s]().draw()