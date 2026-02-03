# Shape Registry

## In this task:
- I implemented the registry pattern to create an instance of the provided shape without having to check one by one using if-else. 
- added an abstract base class (Shape) that all shapes inherit from, enabling polymorphism.
- added registry with static functions for: getting the map, registering a shape, creating shape instances by name
- added examples for Circle, Square, Rect.
- each shape registers itself, using a static variable to invoke the register function (self registeration).

This way, to add a new shape: we add a class that inherits from Shape and registers itself in the registry, and that’s it.

## Running 

### Clone :
```
git clone https://github.com/B-asmala/shape-registry
```

### Build
```
make
```

### Run
```
./describe_object <shape name> <parmeter1> <parameter2> ... 
```

